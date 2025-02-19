#include <stdio.h>
#include <stdlib.h>
#include "simulation.h"

Person* create_person(int id) {
    Person* p = (Person*)malloc(sizeof(Person));
    p->id = id;
    p->state = HEALTHY;
    p->days_infected = 0;
    p->contacts = (Person**)malloc(5 * sizeof(Person*));
    p->contact_count = 0;
    return p;
}

void connect_people_randomly(Graph* g, int avg_contacts) {
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < avg_contacts; j++) {
            int random_index = rand() % g->size;
            g->people[i]->contacts[j] = g->people[random_index];
            g->people[i]->contact_count++;
        }
    }
}

Graph* create_graph(int population_size) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->size = population_size;

    for (int i = 0; i < population_size; i++) {
        g->people[i] = create_person(i);
    }

    connect_people_randomly(g, 5);
    return g;
}

void free_graph(Graph* g) {
    for (int i = 0; i < g->size; i++) {
        free(g->people[i]->contacts);
        free(g->people[i]);
    }
    free(g);
}