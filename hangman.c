#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "umairfunctions.h"

int main() {
    char name[40][50] = {"napoleon", "soup", "michigan"}, ch, continu;
    int in = 0, length, attempt = 0, counts[26] = {0}, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, j = 0;
    int k = 0, i = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0;
    int y = 0, z = 0; 
	int attempt2 = 0, attempt3 = 0;
    char hints;

    char rules;
    printf("\n\nWelcome to Hangman, %s. Press 'r' to view rules, otherwise press any key...\n");
    scanf(" %c", &rules);

    if (rules == 'r') {
		display_hangman_rules();
    }

    print_with_delay("\n-----Let's start level 01-----", 35);

    for (in = 0; in < 2; in++) {
        if (in == 0) {
            length = strlen(name[in]);
        }
    }

    print_with_delay("\nPress h to get a hint, otherwise, press any key...\t", 35);
    scanf(" %c", &hints);

    if (hints == 'h' || hints == 'H') {
		display_hints_for_first_word();
    }

    in = 0;

    while (in < length && attempt < 9) {
        print_with_delay("\n\n||||||Enter your character:|||||||\n", 35);
        scanf(" %c", &ch);
        attempt++;

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            int index = (ch >= 'a' && ch <= 'z') ? ch - 'a' : ch - 'A';
            counts[index]++;
            printf("You have entered %c %d times\n", ch, counts[index]);
        } else {
            print_with_delay("Invalid input\n", 35);
        }

        if (ch == name[0][in]) {
            print_with_delay("\nCorrect \n", 35);
            in++;
        }
    }

    if (in == length) {
        print_with_delay("\n\t\t\t You have guessed the name 'napoleon' correctly. Congratulations!\n\n", 35);
    }

    if (attempt == 9) {
        print_with_delay("\nYou have reached your limit!!\n", 35);
        return 0;
    }

    print_with_delay("\n\tIf you want to play level 2, enter 'y', and to exit enter any key\n", 35);
    scanf(" %c", &continu);

    if (continu == 'y' || continu == 'Y') {
        for (in = 0; in < 2; in++) {
            if (in == 1) {
                length = strlen(name[in]);
            }
        }

        print_with_delay("\n-----Let start level 02-----", 35);

        print_with_delay("\nPress h to get a hint, otherwise, press any key...\n", 35);
        while (getchar() != '\n');
        scanf(" %c", &hints);

        if (hints == 'h' || hints == 'H') {
			display_hints_for_second_word();
        }

        in = 1;

        while (in < 9 && attempt2 < 9) {
            print_with_delay("\n\n||||Enter your character:||||\n", 35);
            scanf(" %c", &ch);
            attempt2++;

            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                int index = (ch >= 'a' && ch <= 'z') ? ch - 'a' : ch - 'A';
                counts[index]++;
                printf("You have entered %c %d times\n", ch, counts[index]);
            } else {
                print_with_delay("Invalid input\n", 35);
            }

            if (ch == name[1][in]) {
                print_with_delay("\nCorrect \n", 35);
                in++;
            }

            if (in == length) {
                print_with_delay("\n\t\t\t You have guessed the word 'soup' correctly. Congratulations!\n\n", 35);
            }

            if (attempt2 == 9) {
                print_with_delay("\nYou have reached your limit!!\n", 35);
                return 0;
            }
        }
    }

    print_with_delay("If you want to play level 3 enter 'y' or if you want to exit then enter any key of the keyboard\n", 35);
    scanf(" %c", &continu);

    if (continu == 'y') {
        for (in = 0; in < 3; in++) {
            if (in == 2) {
                length = strlen(name[in]);
            }
        }

        print_with_delay("\n-----Let start level 03-----", 35);

        print_with_delay("Press h to get a hint, otherwise, press any key...\n", 35);
        while (getchar() != '\n');
        scanf("%c", &hints);

        if (hints == 'h' || hints == 'H') {
			display_hints_for_third_word();
        }

        in = 0;

        while (in < 9 && attempt3 < 9) {
            print_with_delay("\n\n|||||Enter your character:|||||\n\n", 35);
            scanf(" %c", &ch);
            attempt3++;

            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        		int index = (ch >= 'a' && ch <= 'z') ? ch - 'a' : ch - 'A';
        		counts[index]++;
        		printf("You have entered %c %d times\n", ch, counts[index]);
    		} else {
        		printf("Invalid input\n", 35);
        		continue;
    		}

    		if (ch == name[2][in]) {
        		print_with_delay("\nCorrect \n", 35);
        		in++;
    		}
		}

        if (attempt3 == 9 && in == length) {
            print_with_delay("You have guessed the name 'Michigan' correctly congrats\n\n", 35);
            return 0;
        } else if (attempt3 == 9) {
            print_with_delay("You have reached your limit!!", 35);
        } else {
            print_with_delay("Incorrect please try again \n\n", 35);
        }
    }

    return 0;
}
