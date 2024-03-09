#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROUNDS 10

typedef enum { PAPER, ROCK, SCISSORS } Choice;

void print_scores(Choice user_choices[], Choice computer_choices[], int round);

const char* choice_to_string(Choice choice) {
    switch (choice) {
        case PAPER:
            return "paper";
        case ROCK:
            return "rock";
        case SCISSORS:
            return "scissors";
    }
}

int main() {
    Choice user_choices[MAX_ROUNDS];
    Choice computer_choices[MAX_ROUNDS];
    int round = 0;

    srand(time(NULL));

    printf("Welcome to the Rock, Paper, Scissors game!\n");

    while (round < MAX_ROUNDS) {
        printf("\nRound %d\n", round + 1);

        int user_choice;
        printf("Choose your move (0 - paper, 1 - rock, 2 - scissors): ");
        scanf("%d", &user_choice);

        if (user_choice < 0 || user_choice > 2) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        user_choices[round] = (Choice)user_choice;
        computer_choices[round] = (Choice)(rand() % 3);

        printf("Your choice: %s\n", choice_to_string(user_choices[round]));
        printf("Computer's choice: %s\n", choice_to_string(computer_choices[round]));

        // Check who wins
        if (user_choices[round] == computer_choices[round]) {
            printf("It's a tie!\n");
        } else if ((user_choices[round] == PAPER && computer_choices[round] == ROCK) ||
                   (user_choices[round] == ROCK && computer_choices[round] == SCISSORS) ||
                   (user_choices[round] == SCISSORS && computer_choices[round] == PAPER)) {
            printf("You win!\n");
        } else {
            printf("Computer wins!\n");
        }

        round++;

        char command[10];
        printf("\nEnter a command (scores - display results, q - quit game): ");
        scanf("%s", command);

        if (!strcmp(command, "scores")) {
            print_scores(user_choices, computer_choices, round);
        } else if (!strcmp(command, "q")) {
            break;
        }
    }

    printf("Thank you for playing!\n");

    return 0;
}

void print_scores(Choice user_choices[], Choice computer_choices[], int round) {
    printf("\nRound results:\n");
    for (int i = 0; i < round; i++) {
        const char *winner;
        if (user_choices[i] == computer_choices[i]) {
            winner = "Tie";
        } else if ((user_choices[i] == PAPER && computer_choices[i] == ROCK) ||
                   (user_choices[i] == ROCK && computer_choices[i] == SCISSORS) ||
                   (user_choices[i] == SCISSORS && computer_choices[i] == PAPER)) {
            winner = "You";
        } else {
            winner = "Computer";
        }
        printf("Round %d - You: %s, Computer: %s, Winner: %s\n", i + 1, choice_to_string(user_choices[i]), choice_to_string(computer_choices[i]), winner);
    }
}
