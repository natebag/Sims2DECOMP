// main_pc.cpp — PC port entry point for The Sims 2
// Replaces the GameCube __start → main() boot sequence with a PC-native entry point.

#include "types.h"

#ifdef SIMS2_HAS_SDL2
#include <SDL2/SDL.h>
#endif

#include <cstdio>
#include <cstdlib>

// Forward declaration of the game's main init (from global_chunk_3.cpp / original main())
// extern void MainInit(void);
// extern void StartMainThread(void);

int main(int argc, char* argv[]) {
    printf("=== The Sims 2 — PC Port ===\n");
    printf("Based on GameCube decompilation (G4ZE69)\n");
    printf("Build: F.09.12.0 (Gold Master)\n");
    printf("\n");

#ifdef SIMS2_HAS_SDL2
    printf("[SDL2] Initializing...\n");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) < 0) {
        fprintf(stderr, "[SDL2] Failed to initialize: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "The Sims 2 (PC Port)",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
#ifdef SIMS2_HAS_OPENGL
        | SDL_WINDOW_OPENGL
#endif
    );

    if (!window) {
        fprintf(stderr, "[SDL2] Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

#ifdef SIMS2_HAS_OPENGL
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        fprintf(stderr, "[OpenGL] Failed to create context: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    printf("[OpenGL] Context created\n");
#endif

    printf("[SDL2] Window created (1280x720)\n");
    printf("\n");

    // TODO: Call game initialization
    // MainInit();
    // StartMainThread();

    // Temporary: event loop so the window stays open
    printf("PC port scaffold running. Game init not yet wired up.\n");
    printf("Press ESC or close window to exit.\n");

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }

        // TODO: Call game update/render loop
        // EEngine::Update();
        // EEngine::Render();

#ifdef SIMS2_HAS_OPENGL
        SDL_GL_SwapWindow(window);
#endif

        SDL_Delay(16); // ~60fps cap
    }

#ifdef SIMS2_HAS_OPENGL
    SDL_GL_DeleteContext(glContext);
#endif
    SDL_DestroyWindow(window);
    SDL_Quit();

#else
    // No SDL2 — just print status and exit
    printf("SDL2 not available. Install SDL2 and rebuild to get a window.\n");
    printf("For now, this confirms the decomp code compiles on x86.\n");
#endif

    printf("\nClean exit.\n");
    return 0;
}
