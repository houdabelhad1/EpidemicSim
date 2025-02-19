#include <stdlib.h>
#include "simulation.h"

void infect_person(Person* p) {
    if (p->state == HEALTHY) {
        p->state = INFECTED;
    }
}

void simulate_day(Graph* g) {
    for (int i = 0; i < g->size; i++) {
        Person* p = g->people[i];
        if (p->state == INFECTED) {
            for (int j = 0; j < p->contact_count; j++) {
                if ((double)rand() / RAND_MAX < INFECTION_PROB) {
                    infect_person(p->contacts[j]);
                }
            }
            if ((double)rand() / RAND_MAX < RECOVERY_PROB) {
                p->state = RECOVERED;
            }
        }
    }
}