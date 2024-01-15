#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For the sleep function
#include "maazfunctions.h"

int main() {
	wallet_balance -= 200;
	
	srand(time(NULL));
	
    display_rules();

    int round, user_score = 0, computer_score = 0, ties = 0;
    int dynamite_available = 1; // Player starts with one dynamite

    for (round = 1; round <= 3; round++) {
        printf("\nRound %d\n", round);

        int user_choice;
        printf("1. Rock\n2. Paper\n3. Scissors\n4. Dynamite (Use it wisely!)\nEnter your choice (1-4): ");
        if (scanf("%d", &user_choice) != 1 || user_choice < 1 || user_choice > 4) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            round--;
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        int computer_choice = get_computer_choice();

        printf("You chose ");
        switch (user_choice) {
            case 1:
                print_with_delay("Rock\n", 50);
                break;
            case 2:
                print_with_delay("Paper\n", 50);
                break;
            case 3:
                print_with_delay("Scissors\n", 50);
                break;
            case 4:
                if (dynamite_available) {
                    print_with_delay("Dynamite\n", 50);
                    dynamite_available = 0; // Use up the dynamite
                } else {
                    print_with_delay("Dynamite again! It looks like you've already used Dynamite. Choose another move.\n", 50);
                    round--;
                    continue;
                }
                break;
        }

        printf("Computer chose ");
        switch (computer_choice) {
            case 1:
                print_with_delay("Rock\n", 50);
                break;
            case 2:
                print_with_delay("Paper\n", 50);
                break;
            case 3:
                print_with_delay("Scissors\n", 50);
                break;
        }

        // Update score based on the game result
        if (user_choice == 4 && computer_choice != 4) {
            printf("Boom! You win this round with Dynamite!\n");
            user_score++;
        } else if (user_choice == computer_choice) {
            printf("It's a tie!\n");
            ties++;
        } else if ((user_choice == 1 && computer_choice == 3) ||
                   (user_choice == 2 && computer_choice == 1) ||
                   (user_choice == 3 && computer_choice == 2)) {
            printf("You win this round!\n");
            user_score++;
        } else {
            printf("Computer wins this round!\n");
            computer_score++;
        }

        // Display the scorecard after each round
        display_scorecard(user_score, computer_score, ties, round);

        usleep(1000 * 500); // Introduce a delay of 500 milliseconds before starting the next round
    }

    // Display the final scorecard with a delay
    display_scorecard(user_score, computer_score, ties, round);
    usleep(1000 * 500); // Introduce a delay of 500 milliseconds before displaying the final result

    if (user_score > computer_score) {
        print_with_delay("Congratulations, %s! You win the game!\n",username, 50);
        wallet_balance += 500;
        sleep(3);
        printf("\nYour current wallet balance = %d coins.", wallet_balance);
        sleep(3);
    } else if (user_score < computer_score) {
        print_with_delay("Computer wins the game. Better luck next time, %s!\n",username, 50);
        wallet_balance -= 150;
        sleep(3);
        printf("\nYour current wallet balance = %d coins.", wallet_balance);
        sleep(3);
    } else {
        print_with_delay("The game is a tie!\n", 50);
        sleep(3);
        printf("\nYour current wallet balance = %d coins.", wallet_balance);
        sleep(3);
    }

    return 0;
}

