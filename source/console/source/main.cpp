#include "pch.h"
#include "framework.h"
#include "main.h"

#include <thread>

#include "Simulation.hpp"
#include "Components.hpp"

#ifdef _WIN32
	#define CLEAR_SCREEN "cls"
#else
	#define CLEAR_SCREEN "clear"
#endif

int main(int, char* []) {
    flecs::world ecs;
    Simulation::initialise(ecs);

    /*
    flecs::entity sun = ecs.entity("Sun")
        .set(Position{ 0, 0 })
        .set(Velocity{ 0, 0 })
        .set(Acceleration{ 0, 0 })
        .set(Mass{ 1.989e30 });

    flecs::entity planet = ecs.entity("Earth")
        .set(Position{ 149597870000, 0 })
        .set(Velocity{ 0, 29800 })
        .set(Acceleration{ 0, 0 })
        .set(Mass{ 5.972e24 });
    */

    flecs::entity A = ecs.entity("A")
        .set(Position{ -10, 0 })
        .set(Velocity{ 0, -2 })
        .set(Acceleration{ 0, 0 })
        .set(Mass{ 100 });

    flecs::entity B = ecs.entity("B")
        .set(Position{ 10, 0 })
        .set(Velocity{ 0, 2 })
        .set(Acceleration{ 0, 0 })
        .set(Mass{ 100 });

    bool isRunning = true;
    constexpr int TICK_MAXIMUM = 2000;
    int i = 0;

    while (isRunning)
    {
        std::system(CLEAR_SCREEN);
        std::cout << "\nIteration : " << i++ << "\n";
        Simulation::update(ecs, 0.04f);

    	ecs.each([&](const flecs::entity entity, const Position& pos, const Velocity& vel, const Acceleration& acc, const Mass& mass) {
            std::cout << entity.name()
                << ": [pos: { " << pos.x << ", " << pos.y << " }"
                <<   " vel: { " << vel.x << ", " << vel.y << " }"
                <<   " acc: { " << acc.x << ", " << acc.y << " }"
                <<   " mass: { " << mass.value << " }]\n";
        });

        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        if (i >= TICK_MAXIMUM)
            isRunning = false;
    }
}