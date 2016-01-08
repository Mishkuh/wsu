/*
	Programmer: Michael Wiens
	Date: 4/9/14
	Section: 6
	Description: A battleship game versus the computer
*/

#include "BShipHeader.h"

int main (void)
{
	int direction = 0, row_start = 0, col_start = 0, i = 0, choice = -1, game_over1 = 0, game_over2 = 0;

	char game_board[10][10] = {{'\0', '\0'}, {'\0'}};
	char comp_board[10][10] = {{'\0', '\0'}, {'\0'}};
	char game_board_blind[10][10] = {{'\0', '\0'}, {'\0'}};
	char comp_board_blind[10][10] = {{'\0', '\0'}, {'\0'}};

	Player p1, p2;

	player_init(&p1);
	player_init(&p2);

	srand ((unsigned int) time (NULL));

	welcome_screen();
	option_menu(&choice);

	system("cls");

	init_board (game_board, 10, 10);
	init_board (comp_board, 10, 10);
	init_board (game_board_blind, 10, 10);
	init_board (comp_board_blind, 10, 10);

	if(choice == 1)
	{
		manually_place_ships(game_board, p1.ship_carrier);
		manually_place_ships(game_board, p1.ship_battleship);
		manually_place_ships(game_board, p1.ship_submarine);
		manually_place_ships(game_board, p1.ship_cruiser);
		manually_place_ships(game_board, p1.ship_destroyer);

		randomly_place_ships(comp_board, &p1);
	}
	else
	{
		randomly_place_ships(comp_board, &p1);
		randomly_place_ships(game_board, &p2);
	}

	system("cls");

	while(game_over1 == 0 && game_over2 == 0)
	{
		printf("-------PLAYER BOARD-------\n");
		print_board (game_board, 10, 10);
		print_board (comp_board_blind, 10, 10);
		shot_attempt_blind(comp_board, comp_board_blind, &p1);
		game_over1 = check_ship(&p1);
		printf("\n");
		print_board (game_board, 10, 10);
		print_board (comp_board_blind, 10, 10);
		shot_attempt_random (game_board, &p2);
		game_over2 = check_ship(&p2);
		system("cls");
	}

	if(game_over1 == 1)
	{
		printf("CONGRATULATIONS YOU WON!!!");
	}
	else {printf("Sorry, you lost");}

	write_to_file(p1);

	return 0;
}