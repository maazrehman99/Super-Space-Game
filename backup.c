#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int beg_luck_generator(void);	//user-defined function for generating begging luck

void display_menu_list(int balance);	//user-defined function which prevents repitition for displaying menu list

void display_loading_screen(void);		//user-defined function for displaying the loading screen nicely

void display_exiting_screen(int menu);	//user-defined function for displaying the exiting screen nicely.

int first_jackpot_random_number(void);
int second_jackpot_random_number(void);		//three user-defined functions for generating three random numbers for the casino minigame
int third_jackpot_random_number(void);

int main(void)
{
    int wallet_balance = 3000, minigame_entry = 200, casino_unlock_fee = 1600;
    char username[35], buy_subscription[6];

    printf("\nHello! Please enter your name:");
    gets(username);
	
	sleep(1);
	
    printf("\nYou have been given a wallet balance of %d coins\n\n%s, would you like to buy the subscription of 1000 coins for SuperSpace?", wallet_balance, username);
    sleep(3.5);

    while (1)
    {
        printf("\n\nPlease enter your response in either yes or no:\n\n>>>");
        gets(buy_subscription);
        if (strcmp(buy_subscription, "yes") == 0 || strcmp(buy_subscription, "Yes") == 0 || strcmp(buy_subscription, "YES") == 0)
        {
            wallet_balance -= 1000;
            printf("\n%s, you have successfully subscribed!", username);
            sleep(2);
            printf("\n\nCurrent wallet balance = %d", wallet_balance);
            sleep(2);
            system("cls");		//since we cannot use clrscr() for this version of compiler, we use this to clear the screen
            display_menu_list(wallet_balance);
            sleep(3.5);

            while (1)
            {
                int menu_option;
                int special_option_menu;

                printf("\n\nPlease select any option of your choice from the above menu\n\n>>>");
                scanf("%d", &menu_option);

                if (menu_option == 5)
                { //for exiting superspace
                    printf("\nThank you for spending your time in superspace, %s!", username);
                    sleep(2);
                    display_exiting_screen(5);
                    sleep(2);
                    return 1;
                }
                else if (menu_option == 3)
                { //for casino minigame
                    display_loading_screen();
                    sleep(3.5);
                    
					if (wallet_balance >= casino_unlock_fee)
                    {	
                    	wallet_balance -= 200;
						system("cls");
                        printf("\n\n\t\t\t\t\t\t----------Casino Jackpot----------");
                        sleep(2);
                        printf("\n\nRules for playing Casino Jackpot:");
                        sleep(2.5);
                        printf("\n\nEach spin will cost you 250 coins.");
                        printf("\nMatch any two rows to win 500 coins.\nMatch all three rows to win the jackpot of 2000 coins (very rare).\nMatching no rows results in no reward.\nAny random number will be generated for each row.\n\n");
                        sleep(8);
                        
                        printf("\n%s, your current wallet balance = %d coins\n\n", username, wallet_balance);
                        
                        while(1){
	                        char spin_jackpot[7];
	                        int coins_won_in_casino = 0;
	                        
							printf("Type 'spin' to spin the wheels, or type 'stop' to cash out and exit from Casino Jackpot. Good Luck !\n\n>>");
                        	scanf("%s", &spin_jackpot);
                        	
							if (strcmp (spin_jackpot, "spin") == 0 || strcmp (spin_jackpot, "Spin") == 0 || strcmp (spin_jackpot, "SPIN") == 0)
	                        {
	                        	wallet_balance -= 250;
	                        	int row_1_num = first_jackpot_random_number();
								int row_2_num = second_jackpot_random_number();
								int row_3_num = third_jackpot_random_number();
								
								int row_1[1][3], row_2[1][3], row_3[1][3];
	                        	
								for(int i = 0; i < 1; i++){
									for(int j = 0; j < 3; j++){
										row_1[i][j] = row_1_num;
										row_2[i][j] = row_2_num;
										row_3[i][j] = row_3_num;
									}
								}
								
								system("cls");
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSpinning...\n\n\n");
								sleep(2.5);
								system("cls");
								
								//printing the casino machine display
								
								printf("\n\n\n\n\n\n\n\t\t\t\t");
								
								for(int i = 0; i < 1; i++){
									for(int j = 0; j < 3; j++){
										printf("%d\t\t\t", row_1[i][j]);
										sleep(1.5);
									}
									sleep(1.5);
									printf("\n\n\t\t------------------------------------------------------------------------------\r\n\n\t\t\t\t");
									sleep(1.5);
								}
									
								for(int i = 0; i < 1; i++){
									for(int j = 0; j < 3; j++){
										printf("%d\t\t\t", row_2[i][j]);
										sleep(1.5);
									}
									sleep(1.5);
									printf("\n\n\t\t----------------------------------------------------------------------------\r\n\n\t\t\t\t");
									sleep(1.5);
								}
								
								for(int i = 0; i < 1; i++){
									for(int j = 0; j < 3; j++){
										printf("%d\t\t\t", row_3[i][j]);
										sleep(1.5);
									}
									printf("\r\n\n\n");
									sleep(2.5);
								}
								system("cls");
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tProcessing Results...");
								
								sleep(2.5);
								
								if(row_1[0][0] == row_2[0][0] && row_1[0][0] == row_3[0][0]){
									wallet_balance += 2000;
									coins_won_in_casino += 2000;
									for(int i = 0; i < 200; i++){
										system("cls");
										printf("\n-----------------------------------------------------------------------------------JACKPOT--------------------------------------------------------------------------------------");
										sleep(0.5);
									}
									system("cls");
									printf("\n%s, you truly are a very very lucky individual!", username);
									sleep(2);
									printf("\nYou have won 2000 coins from the jackpot!\nYour previous wallet balance = %d coins\nYour current wallet balance = %d coins.\n\n", wallet_balance - 2000, wallet_balance);
									sleep(2);
									system("cls");	
								}
								
								else if(row_1[0][0] == row_2[0][0] || row_2[0][0] == row_3[0][0] || row_1[0][0] == row_3[0][0]){
									wallet_balance += 500;
									coins_won_in_casino += 500;
									system("cls");
									printf("\n\n%s, you have successfully matched two rows!", username);
									sleep(2);
									printf("\nYou have won 500 coins!\nYour previous wallet balance = %d coins\nYour current wallet balance = %d coins", wallet_balance-500, wallet_balance);
									sleep(2);
									system("cls");
								}
								
								else{
									system("cls");
									printf("\nWhoops! It looks like u got a little bit unlucky. You didnt get any matching row :(");
									sleep(2);
									printf("\nYou have won 0 coins\nYour previous wallet balance = %d coins\nYour current wallet balance = %d coins", wallet_balance, wallet_balance);
									sleep(2);
									printf("\nKeep in mind that each spin costs 250 coins!!");
									sleep(2);
									system("cls");
								}
							}
							
							else if(strcmp (spin_jackpot, "stop") == 0 || strcmp(spin_jackpot, "Stop") == 0 || strcmp(spin_jackpot, "STOP") == 0){
								printf("\nThankyou for spending your time in Casino, %s!");
								sleep(2);
								printf("\nYou won a total of %d coins from the casino\nYour current wallet balance is now %d coins", coins_won_in_casino, wallet_balance);
								sleep(3);
								display_exiting_screen(3);
								sleep(2);
								system("cls");
								display_menu_list(wallet_balance);
								break;
							}
	                    	else{
	                    		printf("\n\nInvalid command entered...\n\n");
	                    		sleep(2);
							}
	                    }
	                }
                    else
                    {
                        printf("\nOOPS! It looks like you currently do not have sufficient funds to play Casino!");
                        sleep(2);
                        printf("\nCurrent wallet balance = %d coins\tCasino unlock fee = %d coins", wallet_balance, casino_unlock_fee);
                        sleep(2);
                        printf("\nPlay the other games and earn more coins to unlock the Casino!");
                        sleep(2);
                        system("cls");
                        display_menu_list(wallet_balance);
                    }
                }

                else if (menu_option == 4)
                { //for special options
					display_loading_screen();
					sleep(3.5);
					system("cls");
					printf("\n\t\t\t----------Special Options----------");
                    printf("\n%s, would you like to \n\n1-View current wallet balance\n2-Beg for money\n\n", username);
                    sleep(2.5);
                    printf("Please select one of the above two options\n>>>");
                    scanf("%d", &special_option_menu);

                    if (special_option_menu == 1)
                    {
                        printf("\n%s, your current wallet balance = %d coins", username, wallet_balance);
                        sleep(2);
                        display_exiting_screen(4);
                        sleep(2);
                        system("cls");
                        display_menu_list(wallet_balance);
                    }

                    else if (special_option_menu == 2)
                    { //ask the user to beg
                        if (wallet_balance <= 500)
                        {
                            char beg[6];
                            printf("\nHard times, %s! Type in 'beg' to beg for some money. Good Luck!\n\n>>>", username);
                            scanf("%s", &beg);

                            if (strcmp(beg, "beg") == 0 || strcmp(beg, "Beg") == 0 || strcmp(beg, "BEG") == 0)
                            {
                                int beg_number = beg_luck_generator();
                                if ((beg_number >= 0 && beg_number < 6) || (beg_number >= 8 && beg_number <= 10))
                                {
                                    printf("\n\nToday is your unlucky day, %s! Sadly, you do not get any coins...", username);
                                    sleep(2);
                                    display_exiting_screen(4);
                                    sleep(2);
                                    system("cls");
                                    display_menu_list(wallet_balance);
                                }
                                else if (beg_number == 6)
                                {
                                    printf("\n\nKeep your head up, %s. You have been donated 200 coins...", username);
                                    wallet_balance += 200;
                                    sleep(2.5);
                                    display_exiting_screen(4);
                                    sleep(2);
                                    system("cls");
                                    display_menu_list(wallet_balance);
                                }
                                else
                                {
                                    printf("\n\nYou have been blessed by a miracle, %s! Some businessman found you on the road and donated 500 coins!", username);
                                    wallet_balance += 500;
                                    sleep(3);
                                    display_exiting_screen(4);
                                    sleep(2);
                                    system("cls");
                                    display_menu_list(wallet_balance);
                                }
                            }
                            else
                            {
                                printf("\n\nYou should stay poor...");
                                sleep(2);
                                display_exiting_screen(4);
                                sleep(2);
                                system("cls");
                                display_menu_list(wallet_balance);
                            }
                        }

                        else
                        {
                            printf("\n\n%s, your current wallet balance = %d coins, I think you look good right now without any begging...", username, wallet_balance);
                            sleep(3);
                            display_exiting_screen(4);
                            sleep(2);
                            system("cls");
                            display_menu_list(wallet_balance);
                        }
                    }
                    else
                    {
                        printf("\n\nInvalid option selection.");
                        sleep(2);
                        display_exiting_screen(5);
                        sleep(2);
                        return 1;
                    }
                }
                else
                { //for invalid selection
                    printf("\nInvalid menu option selected.\n");
                    sleep(2);
                    display_exiting_screen(5);
                    sleep(2);
                    return 1;
                }
            }
        }
        else if (strcmp(buy_subscription, "no") == 0 || strcmp(buy_subscription, "No") == 0 || strcmp(buy_subscription, "NO") == 0)
        {
            printf("\nSubscription to superspace cancelled.");
            sleep(2);
            display_exiting_screen(5);
            sleep(2);
            return 1;
        }
        else
        {
            printf("\nInvalid response entered.");
            sleep(2);
        }
    }
    return 0;
}

//end of the main program



//bodies of the user-defined functions

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

void display_loading_screen(void){
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLoading...");
}

void display_exiting_screen(int menu){
	system("cls");
	if(menu == 1){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tExiting from Hangman...");	
	}
	else if(menu == 2){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tExiting from RPS...");
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
//these functions create such random numbers that even i have randomly created them and have no particular idea but they work eventually so I let it go with the flow
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