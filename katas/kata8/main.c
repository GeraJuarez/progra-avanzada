#include <stdlib.h>
#include <stdio.h>
#include "ies.h"

int main() {
    int flight_lenght = 10;
    int movie_lenghts[] = {1, 2, 4, 5, 4, 3, 2, 1, 9};
    int movieSize = sizeof(movie_lenghts) / sizeof(int);

    int res = iesMoviesForFlight(flight_lenght, movie_lenghts, movieSize);

    if (res)
    {
        printf("Movies available\n");
    }
    else
    {
        printf("No Movies available\n");
    }
    
    return 0;
}
