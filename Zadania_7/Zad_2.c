#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_GAMES 100
#define MAX_LINE_LENGTH 1024

typedef struct {
    int min_red;
    int max_red;
    int min_green;
    int max_green;
    int min_blue;
    int max_blue;
} DiceCounts;

void parse_observation(char *observation, DiceCounts *counts) {
    int red = 0, green = 0, blue = 0;
    char *token = strtok(observation, ",;");
    
    while (token != NULL) {
        if (strstr(token, "red") != NULL) {
            sscanf(token, "%d red", &red);
        } else if (strstr(token, "green") != NULL) {
            sscanf(token, "%d green", &green);
        } else if (strstr(token, "blue") != NULL) {
            sscanf(token, "%d blue", &blue);
        }
        token = strtok(NULL, ",;");
    }

    if (red < counts->min_red) counts->min_red = red;
    if (red > counts->max_red) counts->max_red = red;
    if (green < counts->min_green) counts->min_green = green;
    if (green > counts->max_green) counts->max_green = green;
    if (blue < counts->min_blue) counts->min_blue = blue;
    if (blue > counts->max_blue) counts->max_blue = blue;
}

int main() {
    FILE *file = fopen("input_2.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    DiceCounts game_counts[MAX_GAMES];
    int game_count = 0;

    while (fgets(line, sizeof(line), file)) {
        char *game_id = strtok(line, ":");
        char *observations = strtok(NULL, ":");
        
        if (game_id && observations) {
            game_counts[game_count].min_red = INT_MAX;
            game_counts[game_count].max_red = 0;
            game_counts[game_count].min_green = INT_MAX;
            game_counts[game_count].max_green = 0;
            game_counts[game_count].min_blue = INT_MAX;
            game_counts[game_count].max_blue = 0;

            char *observation = strtok(observations, ";");
            while (observation) {
                parse_observation(observation, &game_counts[game_count]);
                observation = strtok(NULL, ";");
            }

            game_count++;
        }
    }

    fclose(file);

    for (int i = 0; i < game_count; i++) {
        printf("Game %d: Red (%d-%d), Green (%d-%d), Blue (%d-%d)\n",
               i + 1,
               game_counts[i].min_red, game_counts[i].max_red,
               game_counts[i].min_green, game_counts[i].max_green,
               game_counts[i].min_blue, game_counts[i].max_blue);
    }

    return 0;
}
