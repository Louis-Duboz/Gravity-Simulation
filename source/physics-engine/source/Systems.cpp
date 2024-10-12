#include "pch.h"
#include "Systems.hpp"

#include <iostream>

#include "Components.hpp"

namespace Systems
{
	void IntegrateMotion(const flecs::world& ecs)
	{
		ecs.system<Position, Velocity, const Acceleration>()
			.each([](const flecs::iter& it, size_t&, Position& pos, Velocity& vel, const Acceleration& acc)
			{
				// Symplectic Euler semi-implicit method.
				vel.x += acc.x * it.delta_time() * 0.5;
				vel.y += acc.y * it.delta_time() * 0.5;

				pos.x += vel.x * it.delta_time();
				pos.y += vel.y * it.delta_time();

				vel.x += acc.x * it.delta_time() * 0.5;
				vel.y += acc.y * it.delta_time() * 0.5;
			});
	}

	void ResetAppliedForces(const flecs::world& ecs)
	{
		ecs.system<Acceleration>()
			.each([](Acceleration& acc)
			{
				acc.x = 0;
				acc.y = 0;
			});
	}

	void CalculateGravityForces(const flecs::world& ecs)
	{
		ecs.system<const Mass, const Position, Acceleration>()
			.each([&](const flecs::entity& a, const Mass& mass_a, const Position& pos_a, Acceleration& acc_a)
			{
				ecs.query<const Mass, const Position, Acceleration>()
					.each([&](const flecs::entity& b, const Mass& mass_b, const Position& pos_b, Acceleration& acc_b)
					{
						if (a == b)
							return;

						const double G = 1; // 6.67430e-11;
						double dx = pos_b.x - pos_a.x;
						double dy = pos_b.y - pos_a.y;
						double distanceSquared = dx * dx + dy * dy;
						double distance = sqrt(distanceSquared);

						if (distance > 0.0)
						{
							double force = G * (mass_a.value * mass_b.value) / distanceSquared;
							double force_x = force * (dx / distance);
							double force_y = force * (dy / distance);

							acc_a.x += force_x / mass_a.value;
							acc_a.y += force_y / mass_a.value;

							acc_b.x += -force_x / mass_b.value;
							acc_b.y += -force_y / mass_b.value;
						}
					});
			});
	}
}
