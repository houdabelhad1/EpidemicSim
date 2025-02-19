#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simulation.h"
#include "graphics.h"

int main() {
    srand((unsigned int)time(NULL));
    // Initialisation du graphe avec 100 personnes
    Graph* graph = create_graph(600);
    initialize_graphics();

    // Création de la fenêtre SDL
    SDL_Window* window = SDL_CreateWindow("Epidemic Simulation",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Infecter une personne au hasard
    graph->people[rand() % graph->size]->state = INFECTED;

    // Boucle principale
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
        }

        // Simulation et rendu
        simulate_day(graph);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        render_population(renderer, graph);
        SDL_RenderPresent(renderer);

        SDL_Delay(500); // Pause de 100ms
    }

    // Nettoyage
    free_graph(graph);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}