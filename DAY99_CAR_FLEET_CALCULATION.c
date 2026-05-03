/*
Problem: Given a target distance and cars’ positions & speeds, compute number of car fleets reaching destination.

A car fleet is formed when faster cars catch up to slower ones and move together.

Approach:
1. Compute time for each car to reach target.
2. Sort cars by position in descending order (closest to target first).
3. Traverse and count fleets using a stack-like logic (or max time tracking).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;
    return c2->position - c1->position; // descending order
}

int main() {
    int n, target;
    printf("Enter number of cars: ");
    scanf("%d", &n);

    printf("Enter target distance: ");
    scanf("%d", &target);

    Car *cars = (Car *)malloc(n * sizeof(Car));
    double *time = (double *)malloc(n * sizeof(double));

    printf("Enter position and speed for each car:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cars[i].position, &cars[i].speed);
        time[i] = (double)(target - cars[i].position) / cars[i].speed;
    }

    qsort(cars, n, sizeof(Car), compare);

    // reorder time array according to sorted cars
    double *sortedTime = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        sortedTime[i] = (double)(target - cars[i].position) / cars[i].speed;
    }

    int fleets = 0;
    double currMaxTime = 0;

    for (int i = 0; i < n; i++) {
        if (sortedTime[i] > currMaxTime) {
            fleets++;
            currMaxTime = sortedTime[i];
        }
    }

    printf("Number of car fleets = %d\n", fleets);

    free(cars);
    free(time);
    free(sortedTime);

    return 0;
}