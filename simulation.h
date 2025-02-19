#ifndef SIMULATION_H
#define SIMULATION_H

#define MAX_POPULATION 1000
#define INFECTION_PROB 0.3
#define RECOVERY_PROB 0.1

typedef enum { HEALTHY, INFECTED, RECOVERED } State;

typedef struct Person {
    int id;
    State state;
    int days_infected;
    struct Person** contacts;
    int contact_count;
} Person;

typedef struct Graph {
    Person* people[MAX_POPULATION];
    int size;
} Graph;

// Fonctions
Graph* create_graph(int population_size);
void simulate_day(Graph* g);
void free_graph(Graph* g);

#endif