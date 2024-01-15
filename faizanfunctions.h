#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int beg_luck_generator(void);			//user-defined function for generating begging luck

void display_menu_list(int balance);	//user-defined function which prevents repitition for displaying menu list

void display_loading_screen(int menu);		//user-defined function for displaying the loading screen nicely

void display_exiting_screen(int menu);	//user-defined function for displaying the exiting screen nicely.

int first_jackpot_random_number(void);
int second_jackpot_random_number(void);		//three user-defined functions for generating three random numbers for the casino minigame
int third_jackpot_random_number(void);


int beg_luck_generator(void)
{
    srand(time(0));
    return 1 + (rand() % 10);
}

void display_menu_list(int balance){
	int minigame_entry = 200, casino_unlock_fee = 1600;
	if(balance < 1600){
		printf("\n\n\t\t\t\t\t----------Welcome to SuperSpace----------\n\n1-Rock Paper Scissors\t(entry = %d coins)\n2-Hangman\t(entry = %d coins)\n3-Casino\t(LOCKED, opens on %d coins)\t(entry = %d coins)\n4-Special Options\n5-Exit SuperSpace", minigame_entry, minigame_entry, casino_unlock_fee, minigame_entry);
	}
	else{
		printf("\n\n\t\t\t\t\t----------Welcome to SuperSpace----------\n\n1-Rock Paper Scissors\t(entry = %d coins)\n2-Hangman\t(entry = %d coins)\n3-Casino\t(UNLOCKED)\t(entry = %d coins)\n4-Special Options\n5-Exit SuperSpace", minigame_entry, minigame_entry, minigame_entry);
	}
}

void display_loading_screen(int menu){
	system("cls");
	if(menu == 1){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLoading RPS...");
	}
	else if(menu == 2){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Hangman...");	
	}
	else if(menu == 3){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Casino Jackpot...");
	}
	else if(menu == 4){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Special Options...");
	}
	else{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading SuperSpace...");
	}
}

void display_exiting_screen(int menu){
	system("cls");
	if(menu == 1){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tExiting from RPS...");	
	}
	else if(menu == 2){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tExiting from Hangman...");
	}
	else if(menu == 3){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tExiting from Casino Jackpot...");
	}
	else if(menu == 4){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tExiting from Special Options...");
	}
	else if(menu == 5){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tExiting Superspace...");
	}
	else{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tExiting the program...");
	}
}

int first_jackpot_random_number(void){
	srand(time(NULL));
	return 1 + (rand() % 10);	
}
int second_jackpot_random_number(void){
	srand(time(NULL));
	return (rand() % 2) + (rand() % 10);	
}
int third_jackpot_random_number(void){
	srand(time(NULL));
	return (rand() % 3) + (rand() % 10);	
}
