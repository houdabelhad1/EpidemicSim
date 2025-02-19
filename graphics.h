#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include "simulation.h"

void initialize_graphics();
void render_population(SDL_Renderer* renderer, Graph* g);
void close_graphics();

#endif