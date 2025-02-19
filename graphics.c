#include <SDL.h>
#include "simulation.h"

void render_population(SDL_Renderer* renderer, Graph* g) {
    for (int i = 0; i < g->size; i++) {
        Person* p = g->people[i];
        SDL_Color color;
        switch (p->state) {
        case HEALTHY: color = (SDL_Color){ 0, 255, 0, 255 }; break;  // Vert
        case INFECTED: color = (SDL_Color){ 255, 0, 0, 255 }; break; // Rouge
        case RECOVERED: color = (SDL_Color){ 0, 0, 255, 255 }; break;// Bleu
        }
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
        SDL_Rect rect = { i % 40 * 20, i / 40 * 20, 15, 15 }; // Grille visuelle
        SDL_RenderFillRect(renderer, &rect);
    }
}

void initialize_graphics() {
    SDL_Init(SDL_INIT_VIDEO);
}

void close_graphics() {
    SDL_Quit();
}