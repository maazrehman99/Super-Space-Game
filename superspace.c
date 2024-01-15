#include "faizanfunctions.h"	//this header file has all user-defined functions of main program structure and casino
#include "umairfunctions.h"		//this header file has hangman minigame and all the functions of hangman minigame
//the header file of maaz has been called inside the header file of umair so no need to repeat it again
//header file of maaz contains RPS and few more important structure functions (user-defined)

int main(void)
{
    int wallet_balance = 2000, minigame_entry = 200, casino_unlock_fee = 1600;
    char username[35], buy_subscription[6];

    print_with_delay("\nHello! Please enter your name:", 35);
    gets(username);
	
	sleep(1);
	
    printf("\nYou have been given a wallet balance of %d coins\n\n%s, would you like to buy the subscription of 1000 coins for SuperSpace?", wallet_balance, username);
    sleep(3.5);

    while (1)
    {
        print_with_delay("\n\nPlease enter your response in either yes or no:\n\n>>>", 35);
        gets(buy_subscription);
        if (strcmp(buy_subscription, "yes") == 0 || strcmp(buy_subscription, "Yes") == 0 || strcmp(buy_subscription, "YES") == 0)
        {
            wallet_balance -= 1000;
            printf("\n%s, you have successfully subscribed!", username);
            sleep(2);
            printf("\n\nCurrent wallet balance = %d", wallet_balance);
            sleep(3.5);
            system("cls");		//since we cannot use clrscr() for this version of compiler, we use this to clear the screen
            display_loading_screen(0);
            sleep(3);
            system("cls");
			display_menu_list(wallet_balance);
            sleep(3.5);

            while (1)
            {
                int menu_option;
                int special_option_menu;

                print_with_delay("\n\nPlease select any option of your choice from the above menu\n\n>>>", 35);
                scanf("%d", &menu_option);

                if (menu_option == 5)
                { //for exiting superspace
                    printf("\nThank you for spending your time in superspace, %s!", username);
                    sleep(2);
                    display_exiting_screen(5);
                    sleep(2);
                    system("cls");
                    return 1;
                }
                else if(menu_option == 1){
                	//for rock paper scissors
					display_loading_screen(menu_option);
					sleep(3.5);
					system("cls");
					
					wallet_balance -= 200;
	
					srand(time(NULL));
					
				    display_rules();
				
				    int round, user_score = 0, computer_score = 0, ties = 0;
				    int dynamite_available = 1; // Player starts with one dynamite
				
				    for (round = 1; round <= 3; round++) {
				        printf("\nRound %d\n", round);
				
				        int user_choice;
				        print_with_delay("1. Rock\n2. Paper\n3. Scissors\n4. Dynamite (Use it wisely!)\nEnter your choice (1-4): ", 35);
				        if (scanf("%d", &user_choice) != 1 || user_choice < 1 || user_choice > 4) {
				            print_with_delay("Invalid input. Please enter a number between 1 and 4.\n", 35);
				            sleep(2);
				            round--;
				            while (getchar() != '\n'); // Clear input buffer
				            continue;
				        }
				
				        int computer_choice = get_computer_choice();
				
				        print_with_delay("You chose ", 35);
				        switch (user_choice) {
				            case 1:
				                print_with_delay("Rock\n", 35);
				                sleep(2);
				                break;
				            case 2:
				                print_with_delay("Paper\n", 35);
				                sleep(2);
				                break;
				            case 3:
				                print_with_delay("Scissors\n", 35);
				                sleep(2);
				                break;
				            case 4:
				                if (dynamite_available) {
				                    print_with_delay("Dynamite\n", 35);
				                    sleep(2);
				                    dynamite_available = 0; // Use up the dynamite
				                } else {
				                    print_with_delay("Dynamite again! It looks like you've already used Dynamite. Choose another move.\n", 35);
				                    sleep(2);
				                    round--;
				                    continue;
				                }
				                break;
				        }
				
				        print_with_delay("Computer chose ", 35);
				        switch (computer_choice) {
				            case 1:
				                print_with_delay("Rock\n", 35);
				                sleep(2);
				                break;
				            case 2:
				                print_with_delay("Paper\n", 35);
				                sleep(2);
				                break;
				            case 3:
				                print_with_delay("Scissors\n", 35);
				                sleep(2);
				                break;
				        }
				
				        // Update score based on the game result
				        if (user_choice == 4 && computer_choice != 4) {
				            print_with_delay("Boom! You win this round with Dynamite!\n", 35);
				            sleep(2);
				            user_score++;
				        } else if (user_choice == computer_choice) {
				            print_with_delay("It's a tie!\n", 35);
				            sleep(2);
				            ties++;
				        } else if ((user_choice == 1 && computer_choice == 3) ||
				                   (user_choice == 2 && computer_choice == 1) ||
				                   (user_choice == 3 && computer_choice == 2)) {
				            print_with_delay("You win this round!\n", 35);
				            sleep(2);
				            user_score++;
				        } else {
				            print_with_delay("Computer wins this round!\n", 35);
				            sleep(2);
				            computer_score++;
				        }
				
				        // Display the scorecard after each round
				        display_scorecard(user_score, computer_score, ties, round);
				
				        usleep(1000 * 500); // Introduce a delay of 500 milliseconds before starting the next round
				    }
				
				    if (user_score > computer_score) {
				        print_with_delay("Congratulations! You win the game!\n", 35);
				        sleep(2);
				        wallet_balance += 500;
				        sleep(3);
				        printf("\nYour current wallet balance = %d coins.", wallet_balance);
				        sleep(3);
				        display_exiting_screen(menu_option);
				        sleep(3);
				        system("cls");
				        display_menu_list(wallet_balance);
				    } else if (user_score < computer_score) {
				        print_with_delay("Computer wins the game. Better luck next time!\n", 35);
				        wallet_balance -= 150;
				        sleep(3);
				        printf("\nYour current wallet balance = %d coins.", wallet_balance);
				        sleep(3);
				        display_exiting_screen(menu_option);
				        sleep(3);
				        system("cls");
				        display_menu_list(wallet_balance);
				    } else {
				        print_with_delay("The game is a tie!\n", 35);
				        sleep(3);
				        printf("\nYour current wallet balance = %d coins.", wallet_balance);
				        sleep(3);
				        display_exiting_screen(menu_option);
				        sleep(3);
				        system("cls");
				        display_menu_list(wallet_balance);
				    }	
				}
				else if (menu_option == 2) {  // for hangman minigame
				    wallet_balance -= 200;
				    char name[40][50] = {"napoleon", "soup", "michigan"}, ch, continu;
				    int in = 0, length, attempt = 0, counts[26] = {0}, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, j = 0;
				    int k = 0, i = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0;
				    int y = 0, z = 0;
				    int attempt2 = 0, attempt3 = 0;
				    char hints;
				    
				    char rules;
				    display_loading_screen(menu_option);
				    sleep(2.5);
				    system("cls");
				    while (1) {
				        printf("\n\nWelcome to Hangman, %s. Press 'r' to view rules, otherwise press any key...\n", username);
				        scanf(" %c", &rules);
				
				        if (rules == 'r') {
				            display_hangman_rules();
				        }
				
				        printf("\n%s, your current wallet balance = %d coins", username, wallet_balance);
				        sleep(2);
				        system("cls");
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
				
				        if(in == length && attempt == 9) {
				            print_with_delay("\n\t\t\t You have guessed the name 'napoleon' correctly. Congratulations!\n\n", 35);
				            print_with_delay("\nYou have been blessed with 500 coins!", 35);
				            wallet_balance += 500;
				            printf("\nYour current wallet balance = %d coins.", wallet_balance);
				            sleep(2);
				        }
				
				        else if (attempt == 9) {
				            print_with_delay("\nYou have reached your limit!!\n", 35);
				            print_with_delay("\nYou lose...", 100);
				            system("cls");
				            display_exiting_screen(menu_option);
				            sleep(3.5);
				            system("cls");
				            display_menu_list(wallet_balance);
				            break;
				        }
				        else{
				        	print_with_delay("Incorrect try again \n\n", 35);
						}
				
				        print_with_delay("\nIf you want to play level 2, enter 'y', and to exit enter any key\n", 35);
				        scanf(" %c", &continu);
				
				        if (continu == 'y' || continu == 'Y') {
				        	memset(counts, 0, sizeof(counts));	//resets the occurences of characters after each level
				            for (in = 0; in < 2; in++) {
				                if (in == 1) {
				                    length = strlen(name[in]);
				                }
				            }
				            system("cls");
				            print_with_delay("\n-----Let start level 02-----", 35);
				
				            print_with_delay("\nPress h to get a hint, otherwise, press any key...\n", 35);
				            while (getchar() != '\n');
				            scanf(" %c", &hints);
				
				            if (hints == 'h' || hints == 'H') {
				                display_hints_for_second_word();
				            }
				
				            in = 0;
				
				            while (in < length && attempt2 < 9) {
				                print_with_delay("\n\n||||Enter your character:||||\n", 35);
				                scanf(" %c", &ch);
				                attempt2++;
				
				                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
				                    int index = (ch >= 'a' && ch <= 'z') ? ch - 'a' : ch - 'A';
				                    counts[index]++;
				                    printf("You have entered %c %d times\n", ch, counts[index]);
				                } else {
				                    print_with_delay("Invalid input\n", 35);
				                    continue;
				                }
				
				                if (ch == name[1][in]) {
				                    print_with_delay("\nCorrect \n", 35);
				                    in++;
				                }
				            }
				
				            if (in == length && attempt == 9) {
				                print_with_delay("\n\t\t\t You have guessed the word 'soup' correctly. Congratulations!\n\n", 35);
				                print_with_delay("\nYou have been blessed with 500 coins!", 35);
				                wallet_balance += 500;
				                printf("\nYour current wallet balance = %d coins", wallet_balance);
				                sleep(2);
				            } else if (attempt2 == 9) {
				                print_with_delay("\nYou have reached your limit!!\n", 35);
				                print_with_delay("\nYou lose...", 100);
				                system("cls");
				                display_exiting_screen(menu_option);
				                sleep(3.5);
				                system("cls");
				                display_menu_list(wallet_balance);
				                break;
				            }
				            else{
				            	print_with_delay("Incorrect please try again \n\n", 35);
							}
				        } else {
				            system("cls");
				            display_exiting_screen(menu_option);
				            sleep(3.5);
				            system("cls");
				            display_menu_list(wallet_balance);
				            break;
				        }
				
				        print_with_delay("\nIf you want to play level 3 enter 'y' or if you want to exit then enter any key\n", 35);
				        scanf(" %c", &continu);
				
				        if (continu == 'y') {
				        	memset(counts, 0, sizeof(counts));
				            for (in = 0; in < 3; in++) {
				                if (in == 2) {
				                    length = strlen(name[in]);
				                }
				            }
				            system("cls");
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
				                print_with_delay("\nYou have been blessed with 500 coins!", 35);
				                wallet_balance += 500;
				                printf("\nYour current wallet balance = %d coins", wallet_balance);
				                sleep(2.5);
				                system("cls");
				                display_exiting_screen(menu_option);
				                sleep(3);
				                system("cls");
				                display_menu_list(wallet_balance);
				                break;
				            } else if (attempt3 == 9) {
				                print_with_delay("You have reached your limit!!", 35);
				                print_with_delay("\nYou lose...", 35);
				                system("cls");
				                display_exiting_screen(menu_option);
				                sleep(3.5);
				                system("cls");
				                display_menu_list(wallet_balance);
				                break;
				            } else {
				                print_with_delay("Incorrect please try again \n\n", 35);
				            }
				        } else {
				            system("cls");
				            display_exiting_screen(menu_option);
				            sleep(3.5);
				            system("cls");
				            display_menu_list(wallet_balance);
				            break;
				        }
				    }
				}

                else if (menu_option == 3)
                { //for casino minigame
                    display_loading_screen(menu_option);
                    sleep(3.5);
                    
					if (wallet_balance >= casino_unlock_fee)
                    {	
                    	int coins_won_in_casino = 0;
                    	
						wallet_balance -= 200;
						system("cls");
                        print_with_delay("\n\n\t\t\t\t\t\t----------Casino Jackpot----------", 35);
                        sleep(2);
                        print_with_delay("\n\nRules for playing Casino Jackpot:", 35);
                        sleep(2.5);
                        print_with_delay("\n\nEach spin will cost you 250 coins.", 35);
                        print_with_delay("\nMatch any two rows to win 500 coins.\nMatch all three rows to win the jackpot of 2000 coins (very rare).\nMatching no rows results in no reward.\nAny random number will be generated for each row.\n\n", 35);
                        sleep(2.5);
                        
                        printf("\n%s, your current wallet balance = %d coins\n\n", username, wallet_balance);
                        sleep(3);
                        
                        while(1){
	                        char spin_jackpot[7];
	                        
	                        if(wallet_balance < 250){
	                        	printf("\n%s! Unfortunately, it looks like you do not even have the balance required for performing one spin!", username);
								sleep(4);
								printf("\nBalance required for one spin = 250 coins\nYour current balance = %d coins", wallet_balance);
								sleep(3.5);
								printf("\nTry playing the other mingames, or going into Special Options to beg for money!");
								sleep(4);
								system("cls");
								display_exiting_screen(3);
								sleep(3);
								system("cls");
								display_menu_list(wallet_balance);
								break;
	                        }
	                        else{
								print_with_delay("Type 'spin' to spin the wheels, or type 'stop' to cash out and exit from Casino Jackpot. Good Luck !\n\n>>", 35);
	                        	scanf("%s", &spin_jackpot);
	                        	
								if (strcmp (spin_jackpot, "spin") == 0 || strcmp (spin_jackpot, "Spin") == 0 || strcmp (spin_jackpot, "SPIN") == 0)
		                        {
		                        	wallet_balance -= 250;
		                        	int row_1_num = first_jackpot_random_number();
									int row_2_num = second_jackpot_random_number();
									int row_3_num = third_jackpot_random_number();
									int *row_1_num_ptr = &row_1_num;
									int *row_2_num_ptr = &row_2_num;
									int *row_3_num_ptr = &row_3_num;
									int row_1[1][3], row_2[1][3], row_3[1][3];
		                        	
									for(int i = 0; i < 1; i++){
										for(int j = 0; j < 3; j++){
											row_1[i][j] = *row_1_num_ptr;
											row_2[i][j] = *row_2_num_ptr;
											row_3[i][j] = *row_3_num_ptr;
										}
									}
									
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSpinning...\n\n\n");
									sleep(2.5);
									system("cls");
									
									//printing the casino machine display
									
									print_with_delay("\n\n\n\n\n\n\n\t\t\t\t", 35);
									
									for(int i = 0; i < 1; i++){
										for(int j = 0; j < 3; j++){
											printf("%d\t\t\t", row_1[i][j]);
											sleep(1.5);
										}
										sleep(1.5);
										print_with_delay("\n\n\t\t------------------------------------------------------------------------------\r\n\n\t\t\t\t", 5);
										sleep(1.5);
									}
										
									for(int i = 0; i < 1; i++){
										for(int j = 0; j < 3; j++){
											printf("%d\t\t\t", row_2[i][j]);
											sleep(1.5);
										}
										sleep(1.5);
										print_with_delay("\n\n\t\t------------------------------------------------------------------------------\r\n\n\t\t\t\t", 5);
										sleep(1.5);
									}
									
									for(int i = 0; i < 1; i++){
										for(int j = 0; j < 3; j++){
											printf("%d\t\t\t", row_3[i][j]);
											sleep(1.5);
										}
										print_with_delay("\r\n\n\n", 10);
										sleep(2.5);
									}
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tProcessing Results...");
									
									sleep(2.5);
									system("cls");
									
									if(row_1[0][0] == row_2[0][0] && row_1[0][0] == row_3[0][0]){
										wallet_balance += 2000;
										coins_won_in_casino += 2000;
										for(int i = 0; i < 15; i++){
											printf("\n-----------------------------------------------------------------------------------JACKPOT--------------------------------------------------------------------------------------");
											sleep(1);
										}
										system("cls");
										printf("\n%s, you truly are a very very lucky individual!", username);
										sleep(2);
										printf("\nYou have won 2000 coins from the jackpot!\nYour current wallet balance = %d coins.\n\n", wallet_balance);
										sleep(5);
										system("cls");
										print_with_delay("\n\n", 10);	
									}
									
									else if(row_1[0][0] == row_2[0][0] || row_2[0][0] == row_3[0][0] || row_1[0][0] == row_3[0][0]){
										wallet_balance += 500;
										coins_won_in_casino += 500;
										system("cls");
										printf("\n\n%s, you have successfully matched two rows!", username);
										sleep(2);
										printf("\nYou have won 500 coins!\nYour current wallet balance = %d coins", wallet_balance);
										sleep(5);
										system("cls");
										print_with_delay("\n\n", 10);
									}
									
									else{
										system("cls");
										print_with_delay("\nWhoops! It looks like u got a little bit unlucky. You didnt get any matching row :(", 35);
										sleep(2);
										printf("\nYou have won 0 coins\nYour current wallet balance = %d coins", wallet_balance);
										sleep(5);
										print_with_delay("\nKeep in mind that each spin costs 250 coins!!", 35);
										sleep(2);
										system("cls");
									}
								}
								
								else if(strcmp (spin_jackpot, "stop") == 0 || strcmp(spin_jackpot, "Stop") == 0 || strcmp(spin_jackpot, "STOP") == 0){
									printf("\nThankyou for spending your time in Casino, %s!", username);
									sleep(2);
									printf("\nYou won a total of %d coins from the casino\nYour current wallet balance is now %d coins", coins_won_in_casino, wallet_balance);
									sleep(3);
									display_exiting_screen(3);
									sleep(3.5);
									system("cls");
									display_menu_list(wallet_balance);
									break;
								}
		                    	else{
		                    		print_with_delay("\n\nInvalid command entered...\n\n", 35);
		                    		sleep(2);
								}
							}
	                    }
	                }
                    else
                    {
                    	system("cls");
                        print_with_delay("\nOOPS! It looks like you currently do not have sufficient funds to play Casino!", 35);
                        sleep(2);
                        printf("\nCurrent wallet balance = %d coins\tTo access casino everyime, your wallet balance must be = %d coins\nFee for one casino spin = 250 coins\n", wallet_balance, casino_unlock_fee);
                        sleep(7);
                        print_with_delay("\nPlay the other games and earn more coins to unlock the Casino!", 35);
                        sleep(2);
                        system("cls");
                        display_menu_list(wallet_balance);
                    }
                }

                else if (menu_option == 4)
                { //for special options
					display_loading_screen(menu_option);
					sleep(3.5);
					system("cls");
					print_with_delay("\n\t\t\t----------Special Options----------", 35);
                    printf("\n%s, would you like to \n\n1-View current wallet balance\n2-Beg for money\n\n", username);
                    sleep(2.5);
                    print_with_delay("Please select one of the above two options\n>>>", 35);
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
                        if (wallet_balance < 2000)
                        {
                            char beg[6];
                            printf("\nHard times, %s! Type in 'beg' to beg for some money. Good Luck!\n\n>>>", username);
                            scanf("%s", &beg);

                            if (strcmp(beg, "beg") == 0 || strcmp(beg, "Beg") == 0 || strcmp(beg, "BEG") == 0)
                            {
                                int beg_number = beg_luck_generator();
                                if ((beg_number >= 0 && beg_number < 5) || (beg_number >= 8 && beg_number <= 10))
                                {
                                    printf("\n\nToday is your unlucky day, %s! Sadly, you do not get any coins...", username);
                                    sleep(2);
                                    display_exiting_screen(4);
                                    sleep(2);
                                    system("cls");
                                    display_menu_list(wallet_balance);
                                }
                                else if (beg_number == 6 || beg_number == 5)
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
                                print_with_delay("\n\nYou should stay poor...", 35);
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
                        print_with_delay("\n\nInvalid option selection.", 35);
                        sleep(2);
                        display_exiting_screen(5);
                        sleep(2);
                        return 1;
                    }
                }
                else
                { //for invalid selection
                    print_with_delay("\nInvalid menu option selected.\n", 35);
                    sleep(2);
                    display_exiting_screen(5);
                    sleep(2);
                    return 1;
                }
            }
        }
        else if (strcmp(buy_subscription, "no") == 0 || strcmp(buy_subscription, "No") == 0 || strcmp(buy_subscription, "NO") == 0)
        {
            print_with_delay("\nSubscription to superspace cancelled.", 35);
            sleep(2);
            display_exiting_screen(6);
            sleep(2);
            return 1;
        }
        else
        {
            print_with_delay("\nInvalid response entered.", 35);
            sleep(2);
        }
    }
    return 0;
}