#ifndef SYSTEMS_HPP
#define SYSTEMS_HPP

/**
 * @namespace Systems contains all the systems applied to the physics engine.
 */
namespace Systems
{
    /**
     * Integrates the position and velocity of entities.
     *
     * @param ecs
     */
    void IntegrateMotion(const flecs::world& ecs);

    /**
     * Resets the forces (acceleration) applied to entities.
     *
     * @param ecs
     */
    void ResetAppliedForces(const flecs::world& ecs);

    /**
     * Calculates gravitational forces between entities and updates acceleration.
     *
     * @param ecs
     */
    void CalculateGravityForces(const flecs::world& ecs);
}

#endif // SYSTEMS_HPP