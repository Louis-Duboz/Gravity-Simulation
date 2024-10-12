#include "Simulation.hpp"
#include "Systems.hpp"

namespace Simulation
{
    void initialise(const flecs::world& ecs)
    {
        Systems::IntegrateMotion(ecs);
        Systems::ResetAppliedForces(ecs);
        Systems::CalculateGravityForces(ecs);
    }

    void update(const flecs::world& ecs, const float& deltaTime)
    {
        ecs.progress(deltaTime);
    }
}