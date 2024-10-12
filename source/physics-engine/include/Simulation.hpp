#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "pch.h"

/**
 * @namespace Simulation contains functions related to manage the simulation.
 */
namespace Simulation
{
	/**
	 * Initialise the simulation.
	 *
	 * @param ecs 
	 */
	void initialise(const flecs::world& ecs);

	/**
	 * Update the simulation.
	 *
	 * @param ecs 
	 * @param deltaTime 
	 */
	void update(const flecs::world& ecs, const float& deltaTime);
}

#endif // SIMULATION_HPP