#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 50
#define SIGNAL_LENGTH 50
#define SIGNAL_HEIGHT 50

// Función para inicializar SDL y crear una ventana
SDL_Window* initSDL() {
    SDL_Window* window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("Digital Signal Visualization", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
    }

    return window;
}

// Función para dibujar la señal en la ventana
void drawSignal(SDL_Renderer* renderer, int* signal) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Color blanco
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Color negro
    SDL_Point points[SIGNAL_LENGTH];

    for (int i = 0; i < SIGNAL_LENGTH; ++i) {
        points[i].x = i;
        points[i].y = SCREEN_HEIGHT / 2 - signal[i] * SIGNAL_HEIGHT / 2;
    }

    SDL_RenderDrawLines(renderer, points, SIGNAL_LENGTH);

    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Window* window = initSDL();
    if (window == NULL) {
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    int signal[SIGNAL_LENGTH]; // Señal digital

    // Simulación de una señal digital (cambiar esto con la entrada real)
    for (int i = 0; i < SIGNAL_LENGTH; ++i) {
        signal[i] = i % 2; // Alternar entre 0 y 1
    }

    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        drawSignal(renderer, signal);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
