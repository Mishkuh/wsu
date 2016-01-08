/*
	Programmer: Michael Wiens
	Date: February 25th, 2013
	Class: CPTS 121 Section 6
	Description: A game of chance "craps" using random numbers and loops
*/
#include "Craps.h"

int main(void)
{
	int die1 = 0, die2 = 0, sum_dice = 0, player_point = 0, choice = 0, point_value = 0;
	double bank_bal = 0.0, wager = 0.0;
	srand(time(NULL));
	
	while(choice != 3)
	{
		do
		{
			system("cls");
			printf("1.) Print rules\n2.) Play Game\n3.) Exit game\n");
			scanf("%d", &choice);
		}while(choice < 1 || choice > 3);
		
		if(choice == 1)
		{
			print_game_rules();
			choice = 0;
		}
		else if(choice == 2)
		{
			system("cls");
			bank_bal = get_bank_balance();
			while( bank_bal > 0)
			{
				printf("Current bank balance: $%.2lf\n", bank_bal);
				wager = get_wager_amount();
				check_wager_amount(wager, bank_bal);
				die1 = roll_die();
				die2 = roll_die();
				printf("Die number 1: %d\n", die1);
				printf("Die number 2: %d\n", die2);
				sum_dice = calculate_sum_dice(die1, die2);
				if(is_win_loss_or_point(sum_dice) == 1)
				{
					bank_bal = adjust_bank_balance(bank_bal, wager, 1);
					printf("WINNER!\n");
					pause_clr();
				}
				else if(is_win_loss_or_point(sum_dice) == 0)
				{
					bank_bal = adjust_bank_balance(bank_bal, wager, 0);
					printf("LOSER!\n");
					pause_clr();
				}
				else
				{
					point_value = sum_dice;
					sum_dice = 0;
					while(is_point_loss_or_neither(sum_dice, point_value) == -1)
					{
						system("pause");
						die1 = roll_die();
						die2 = roll_die();
						printf("Die number 1: %d\n", die1);
						printf("Die number 2: %d\n", die2);
						sum_dice = calculate_sum_dice(die1, die2);
						if(is_point_loss_or_neither(sum_dice, point_value) == 1)
						{
							bank_bal = adjust_bank_balance(bank_bal, wager, 1);
							printf("WINNER!\n");
							pause_clr();
						}
						else if(is_point_loss_or_neither(sum_dice, point_value) == 0)
						{
							bank_bal = adjust_bank_balance(bank_bal, wager, 0);
							printf("LOSER!\n");
							pause_clr();
						}
					}
				}
			}
			choice = 0;
		}
		else if(choice == 3)
		{
			system("cls");
			printf("Thank You for playing!\n");
		}
	}
	return 0;
}