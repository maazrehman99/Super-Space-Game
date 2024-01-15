#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For the sleep function

int get_computer_choice() {
    return rand() % 3 + 1;
}

void print_with_delay(const char *str, int delay_time) {
    while (*str) {
        putchar(*str++);
        fflush(stdout);
        usleep(delay_time * 1000); // Sleep for delay_time milliseconds
    }
}

void display_rules() {
    const char *rules = "\nWelcome to Rock, Paper, Scissors with a twist!\n"
                        "Rules:\n"
                        "- You can choose from Rock, Paper, Scissors, or Dynamite.\n"
                        "- Dynamite can only be used once per game.\n"
                        "- Rock beats Scissors, Scissors beats Paper, Paper beats Rock.\n"
                        "- Dynamite beats everything, but you have only one!\n"
                        "- Win this best-of-three to win 500 coins!\n"
                        "- However, you do lose 150 coins on losing to a machine!\n"
                        "Get ready for an exciting game!\n\n";
    
    print_with_delay(rules, 35);
}

void display_scorecard(int user_score, int computer_score, int ties, int round) {
    printf("\nScorecard:\n");
    printf("+--------------------------+\n");
    printf("|   User  | Computer | Ties |\n");
    printf("|   %2d   |    %2d   |  %2d |\n", user_score, computer_score, ties);
    printf("+-------------------------+\n");
    printf("|        Round %2d        |\n", round);
    printf("+-------------------------+\n");
}