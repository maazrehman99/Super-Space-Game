#include "maazfunctions.h"

void display_hangman_rules(void);
void display_hints_for_first_word(void);
void display_hints_for_second_word(void);
void display_hints_for_third_word(void);

void display_hangman_rules(void){
	print_with_delay("1: The word must be guessed in a sequence i.e. letters should be guessed chronologically\n", 35);
    print_with_delay("2: It is a case-sensitive game; you should not use capital letters. \n", 35);
    print_with_delay("3. This game includes 3 levels, and in each level, there are 3 different words.\n", 35);
    print_with_delay("4. Guess one word correctly to win 500 coins!\n", 35);
    print_with_delay("5. Each word will progressively get harder!", 35);
    print_with_delay("\n\n\nThanyou for reading the rules.\n\n", 35);
}

void display_hints_for_first_word(void){
    print_with_delay("HINT1: Famous ruler of France...\n", 35);
    print_with_delay("HINT2: Waterloo\n", 35);
    print_with_delay("HINT3: First letter is n and last letter is also n\n", 35);
}

void display_hints_for_second_word(void){
    print_with_delay("\nHINT1: Very famous appetizer\n", 35);
    print_with_delay("HINT2: First letter starts with s\n", 35);
    print_with_delay("HINT3: There are total four letters in the word youre guessing...\n", 35);
}

void display_hints_for_third_word(void){
    print_with_delay("HINT1: Part of America\n", 35);
    print_with_delay("\nThe first letter of the word starts with m and it ends with n\n", 35);
    print_with_delay("HINT2: There are 8 letters in the word youre guessing...\n", 35);
}
