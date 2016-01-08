#include "Craps.h"

/*
	Function: void print_game_rules (void)
	Date Created: February 21, 2013
	Date Last Modified: February 26, 2013
	Description: prints the game rules
	Input Parameters: void
	Returns: void 
*/
void print_game_rules (void)
{
	char go = '\0';
	system("cls");
	printf("A player rolls two dice. Each die has six faces. \nThese faces contain 1, 2, 3, 4, 5, and 6 spots. \nAfter the dice have come to rest, the sum of the spots on the two upward faces \nis calculated. \nIf the sum is 7 or 11 on the first throw, the player wins. \nIf the sum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses (i.e. the \"house\" wins). \nIf the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's \"point.\" \nTo win, you must continue rolling the dice until you \"make your point.\" \nThe player loses by rolling a 7 before making the point.\n");
	system("pause");
	system("cls");
}
/*
	Function: double get_bank_balance (void)
	Date Created: February 21, 2013
	Date Last Modified: February 26, 2013
	Description: Gets the users desired bank balance
	Input Parameters: void
	Returns: The bank balance
*/
double get_bank_balance (void)
{
	double bank_balance = 0.0;

	printf("Please enter an initial bank balance: ");
	scanf("%lf", &bank_balance);

	return bank_balance;
}
/*
	Function: double get_wager_amount (void)
	Date Created: February 21, 2013
	Date Last Modified: February 26, 2013
	Description: gets users wager amount
	Input Parameters: void
	Returns: wager amount
*/
double get_wager_amount (void)
{
	double wager_amount = 0.0;

	printf("Please enter a wager amount for this roll: ");
	scanf("%lf", &wager_amount);

	return wager_amount;
}
/*
	Function: int check_wager_amount (double wager, double balance)
	Date Created: February 21, 2013
	Date Last Modified: February 26, 2013
	Description: checks if wager amount is a valid amount
	Input Parameters:wager and balance
	Returns: 1 or 0 if the wager amount is valid or not
*/
int check_wager_amount (double wager, double balance)
{
	int valid = VALIDWAGER;
	char all_in = '\0';

	while(wager > balance)
	{
		printf("You are wagering more than you have.\n Would you like to go \"all in\" \n(enter y (yes) or n (no)):");
		scanf(" %c", &all_in);
		if(all_in == 'y' || all_in == 'Y')
		{
			wager = balance;
			valid = VALIDWAGER;
			break;
		}
		else
		{ 
			printf("Please enter a valid wager amount: ");
			scanf("%lf", &wager);
		}
	}

	return valid;
}
/*
	Function: int roll_die (void)
	Date Created: February 21, 2013
	Date Last Modified: February 26, 2013
	Description: gets a number one through six
	Input Parameters: void
	Returns: Number for die rolled
*/
int roll_die (void)
{
	int die = 0, temp = 0;

	temp = rand();
	die = (temp % 6) + 1;

	return die;
}
/*
	Function: int calculate_sum_dice (int die1_value, int die2_value)
	Date Created: February 21, 2013
	Date Last Modified: February 26, 2013
	Description: adds the two dice together
	Input Parameters: die one and two
	Returns: total of dice added together
*/
int calculate_sum_dice (int die1_value, int die2_value)
{
	int sum = 0;

	sum = die1_value + die2_value;

	return sum;
}
/*
	Function: int is_win_loss_or_point (int sum_dice)
	Date Created: February 21, 2013
	Date Last Modified: February 26, 2013
	Description: checks if sum is winning or losing number
	Input Parameters: sum of dice
	Returns: int showing if win loss or point
*/
int is_win_loss_or_point (int sum_dice)
{
	int result = 0;

	if(sum_dice == 7 || sum_dice == 11) {result = 1;}
	else if(sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {result = 0;}
	else {result = -1;}

	return result;
}
/*
	Function: int is_point_loss_or_neither (int sum_dice, int point_value)
	Date Created: February 21, 2013
	Date Last Modified: February 26, 2013
	Description: checks if win loss or point
	Input Parameters: sum of dice and point value
	Returns: int resembling point loss or neither
*/
int is_point_loss_or_neither (int sum_dice, int point_value)
{
	int result = 0;

	if(sum_dice == point_value) {result = 1;}
	else if(sum_dice == 7) {result = 0;}
	else {result = -1;}

	return result;
}
/*
	Function: double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract)
	Date Created: February 21, 2013
	Date Last Modified: February 26, 2013
	Description: adds or subtracts wager to bank balance
	Input Parameters: bank balance wager and if its added or subtracted
	Returns: adjusted bank balance
*/
double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract)
{
	double balance = 0.0;

	if(add_or_subtract == 1){balance = wager_amount + bank_balance;}
	else if(add_or_subtract == 0){balance = bank_balance - wager_amount;}

	return balance;
}
/*
	Function: void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
	Date Created: February 21, 2013
	Date Last Modified: February 26, 2013
	Description: prints messages
	Input Parameters: number of rolls, win loss neither, initial bank bal, and current bank bal
	Returns: void
*/
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{

}
void pause_clr (void)
{
	system("pause");
	system("cls");
}
