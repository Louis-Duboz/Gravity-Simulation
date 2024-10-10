#include "pch.h"
#include "framework.h"
#include <iostream>

namespace {
    struct ApplicationState
    {
        /// The window we'll open to show our rendering inside.
        SDL_Window* window{ nullptr };
        /// Count of the number of times the main loop has been run.
        long long iterations{ 0 };
    };
}

extern "C" {

	SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv)
    {
        std::cerr << "SDL_AppInit" << std::endl;

        // Create an object that will be passed back to each callback:
        *appstate = new ApplicationState;
        ApplicationState& state = *static_cast<ApplicationState*>(*appstate);

        int result = SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        if (result < 0)
        {
            std::cerr << "SDL_InitSubSystem failed with code " << result << std::endl;
            goto error_exit;
        }

        state.window = SDL_CreateWindow("Gravity Simulation", 960, 540, /* 0 | */ SDL_WINDOW_VULKAN);
        if (state.window == NULL)
        {
            std::cerr << "SDL_CreateWindow failed" << std::endl;
            goto error_exit;
        }

        return SDL_APP_CONTINUE;

    error_exit:
        std::cerr << "Last SDL error: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    SDL_AppResult SDL_AppIterate(void* appstate)
    {
        ApplicationState& state = *static_cast<ApplicationState*>(appstate);
        ++state.iterations;
        return SDL_APP_CONTINUE;
    }

    SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
    {
        std::cerr << "SDL_AppEvent";
        if (event)
        {
            std::cerr << ": type = " << event->type << ", timestamp = " << event->common.timestamp << std::endl;
        }
        std::cerr << std::endl;
        if (event->type == SDL_EVENT_QUIT)
        {
            std::cerr << "SDL_EVENT_QUIT" << std::endl;
            return SDL_APP_SUCCESS;
        }
        return SDL_APP_CONTINUE;
    }

    void SDL_AppQuit(void* appstate, SDL_AppResult result)
    {
        ApplicationState* state = static_cast<ApplicationState*>(appstate);
        std::cerr << "SDL_AppQuit after " << state->iterations << " iterations of the main loop." << std::endl;
        delete state;
        return;
    }

}