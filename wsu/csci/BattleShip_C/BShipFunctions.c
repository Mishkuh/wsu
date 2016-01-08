#include "BShipHeader.h"

void welcome_screen(void)
{
	printf("***** Welcome to Battleship! *****\n");
	printf("Rules of the Game:\n");
	printf("1. This is a two player game.\n");
	printf("2. Player1 is you and Player2 is the computer.\n");
	printf("3. You go one by one firing at coordinates.\n");
	printf("4. You win if you destroy all the ships.\n");
	printf("5. You lose if all your ships get destroyed.\n");
	printf("Hit enter to start the game!\n");
	system("pause");
	system("cls");
}
void option_menu(int *choice)
{
	do
	{
		printf("_--Choose an option for placing your ships--_\n");
		printf("---------------------------------------------\n");
		printf("1.) Manual ship placement\n");
		printf("2.) Automatic ship placement\n");
		printf("Choice:");
		scanf("%d", choice);
	}while (choice < 0);
}
void select_who_goes_first (int *player_start)
{
	*player_start = rand () % 2;
}
void init_board (char board[10][10], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < num_rows; row_index++)
	{
		for (col_index = 0; col_index < num_cols; col_index++)
		{
			board[row_index][col_index] = '~';
		}
	}
}
void print_board (char board[10][10], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	printf ("  0 1 2 3 4 5 6 7 8 9\n");

	for (row_index = 0; row_index < num_rows; row_index++)
	{
		printf ("%d ", row_index);
		for (col_index = 0; col_index < num_cols; col_index++)
		{
			printf ("%c ", board[row_index][col_index]);
		}
		putchar ('\n');
	}
}
void generate_direction (int *dir)
{
	*dir = rand () % 2;
}
void generate_random_start_pt (int direction, int length, int *row, int *col)
{
	if (direction) //vertical
	{
		*row = (rand () % (10 - length + 1));
		*col = rand () % 10;
	}
	else // horizontal
	{
		*row = rand () % 10;
		*col = (rand () % (10 - length + 1));
	}
}
void generate_manual_start_pt (Ship *boat, int *row, int *col)
{
	do
	{
		printf("Time to add your %s!\n", boat->ship_name);
		printf("Please choose an x and y coordinate seperated by a space for your ships starting position: ");
		scanf("%d %d", row, col);
	}while (*row < 0 || *col < 0 || *row > 9 || *col > 9);
}
int check_ship_place (char board[10][10], int row_start, int col_start, int dir, int length, char symbol)
{
	int index = 0, valid = 1;

	for (index = 0; index < length; index++)
	{
		switch (dir)
		{
		case 0:	 if(board[col_start + index][row_start] != '~'){valid = 0;} //vertical 
				 break;

		case 1:  if(board[col_start][row_start + index] != '~'){valid = 0;} //horizontal
			     break;
		}
	}
	return valid;
}
void place_ship (char board[10][10], int row_start, int col_start, int dir, int length, char symbol)
{
	int index = 0;

	for (index = 0; index < length; index++)
	{
		switch (dir)
		{
		case 0:	 board[col_start + index][row_start] = symbol; //vertical 
				 break;

		case 1:  board[col_start][row_start + index] = symbol; //horizontal
			     break;
		}
	}
}	
void check_shot (char board[10][10], int col, int row, int *hit, Player *player)
{
	if(col > 9 || row > 9 || col < 0 || row < 0)
	{
		printf("Try a point on the game board\n");
	}
	else if(board[row][col] < 'z' && board[row][col] > 'Z')
	{
		if(board[row][col] == 'c')
		{player->ship_carrier.ship_hits++;}
		else if(board[row][col] == 'b')
		{player->ship_battleship.ship_hits++;}
		else if(board[row][col] == 's')
		{player->ship_submarine.ship_hits++;}
		else if(board[row][col] == 'r')
		{player->ship_cruiser.ship_hits++;}
		else if(board[row][col] == 'd')
		{player->ship_destroyer.ship_hits++;}
		board[row][col] = 'X';
		printf("\n*****DIRECT HIT!*****\n\n");
		*hit = 1;
		player->player_stats.num_hits++;
	}
	else if(board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'O';
		printf("\n_____shot missed_____\n\n");
		*hit = 0;
	}
	else if(board[row][col] == 'X' || board[row][col] == 'O')
	{
		printf("That spot was already tried\n");
	}
	else
	{
		printf("Sorry, that entry is invalid\n");
	}
	system("pause");
}
void shot_attempt (char board[10][10], Player *player)
{
	int row = 0, col = 0, hit = -1;

	while(hit < 0)
	{
		printf("\nx and y coordinate to shoot: ");
		scanf("%d %d", &row, &col);
		check_shot(board, row, col, &hit, player);
	}

	if (hit > 0){ player->player_stats.num_hits++; }
	else if (hit == 0){ player->player_stats.num_misses++; }
}
void shot_attempt_random (char board[10][10], Player *player2)
{
	int row = 0, col = 0, hit = -1;

	while(hit < 0)
	{
		row = rand() % 10;
		col = rand() % 10;
		printf("\nComputer fires at: %d, %d\n", row, col);
		check_shot(board, row, col, &hit, player2);
	}

	if (hit > 0){ player2->player_stats.num_hits++; }
	else if (hit == 0){ player2->player_stats.num_misses++; }
}
void shot_attempt_blind (char board[10][10], char board_blind[10][10], Player *player1)
{
	int row = 0, col = 0, hit = -1;

	while(hit < 0)
	{
		printf("\nx and y coordinate to shoot: ");
		scanf("%d %d", &row, &col);
		check_shot(board, row, col, &hit, player1);
	}
	if (hit == 1)
	{
		board_blind[col][row] = 'X';
	}
	else
	{
		board_blind[col][row] = 'O';
	}
}
int check_ship(Player *player)
{
	int game_over = 0, destroyed = 0;

	if(player->ship_carrier.ship_hits == player->ship_carrier.ship_length)
	{ printf("Carrier was destroyed!\n");
	destroyed++;}
	if(player->ship_battleship.ship_hits == player->ship_battleship.ship_length)
	{ printf("Battleship was destroyed!\n"); 
	destroyed++;}
	if(player->ship_submarine.ship_hits == player->ship_submarine.ship_length)
	{ printf("Submarine was destroyed!\n"); 
	destroyed++;}
	if(player->ship_cruiser.ship_hits == player->ship_cruiser.ship_length)
	{ printf("Cruiser was destroyed!\n"); 
	destroyed++;}
	if(player->ship_destroyer.ship_hits == player->ship_destroyer.ship_length)
	{ printf("Destroyer was destroyed!\n"); 
	destroyed++;}
	if(destroyed == 5)
	{game_over = 1;}

	system("pause");
}
void randomly_place_ships(char board[10][10], Player *player)
{
	int direction = 0, row_start = 0, col_start = 0;
	
	while(check_ship_place (board, row_start, col_start, direction, 5, 'c') == 0)
	{
		generate_direction (&direction);
		generate_random_start_pt (direction, 5, &row_start, &col_start);
	}
	place_ship (board, row_start, col_start, direction, 5, 'c');
	while(check_ship_place (board, row_start, col_start, direction, 4, 'b') == 0)
	{
		generate_direction (&direction);
		generate_random_start_pt (direction, 4, &row_start, &col_start);
	}
	place_ship (board, row_start, col_start, direction, 4, 'b');
	while(check_ship_place (board, row_start, col_start, direction, 3, 's') == 0)
	{
		generate_direction (&direction);
		generate_random_start_pt (direction, 3, &row_start, &col_start);
	}
	place_ship (board, row_start, col_start, direction, 3, 's');
	while(check_ship_place (board, row_start, col_start, direction, 3, 'r') == 0)
	{
		generate_direction (&direction);
		generate_random_start_pt (direction, 3, &row_start, &col_start);
	}
	place_ship (board, row_start, col_start, direction, 3, 'r');
	while(check_ship_place (board, row_start, col_start, direction, 2, 'd') == 0)
	{
		generate_direction (&direction);
		generate_random_start_pt (direction, 2, &row_start, &col_start);
	}
	place_ship (board, row_start, col_start, direction, 2, 'd');
}
void manually_place_ships(char board[10][10], Ship boat)
{
	int direction = 0, row_start = 0, col_start = 0, valid = -1;

	system("cls");
	print_board(board, 10, 10);
	while(valid != 1)
	{
		if(valid == 0)
		{
			printf("Please place in a valid spot\n");
			valid = -1;
		}
		generate_manual_start_pt (&boat, &row_start, &col_start);
		generate_manual_direction (&direction);
		if((direction == 1) && ((boat.ship_length + row_start) > 10))
		{
			valid = 0;
		}
		else if((direction == 0) && ((boat.ship_length + col_start) > 10))
		{
			valid = 0;
		}
		else if(check_ship_place(board, row_start, col_start, direction, boat.ship_length, boat.ship_symbol) == 0)
		{ 
			valid = 0;
		}
		else{ valid = 1; }
	}
	place_ship (board, row_start, col_start, direction, boat.ship_length, boat.ship_symbol);
}
void generate_manual_direction (int *direction)
{
	char entry = '\0';

	do
	{
		printf("\nWhich direction would you like your ship?\n");
		printf("Press h for horizontal or v for vertical:");
		scanf(" %c", &entry);
		if(entry == 'h' || entry == 'H')
		{
			*direction = 1;
		}
		else if(entry == 'v' || entry == 'V')
		{
			*direction = 0;
		}
	}while (entry == '\0');
}
void ship_init(Ship *ship, char type)
{
	ship->ship_hits = 0;
	ship->ship_symbol = type;

	switch(type)
	{
	case 'c':
		ship->ship_length = 5;
		ship->ship_name = "Carrier";
		break;
	case 'b':
		ship->ship_length = 4;
		ship->ship_name = "Battleship";
		break;
	case 's':
		ship->ship_length = 3;
		ship->ship_name = "Submarine";
		break;
	case 'r':
		ship->ship_length = 3;
		ship->ship_name = "Cruiser";
		break;
	case 'd':
		ship->ship_length = 2;
		ship->ship_name = "Destroyer";
		break;
	}
}
void player_init(Player *player)
{
	ship_init(&(player->ship_carrier),'c');
	ship_init(&(player->ship_battleship),'b');
	ship_init(&(player->ship_submarine),'s');
	ship_init(&(player->ship_cruiser),'r');
	ship_init(&(player->ship_destroyer),'d');
}
void write_to_file (Player player)
{
	FILE *input = NULL;
	input = fopen("battleship.log", "w");

	fprintf(input, "Hits: %d\nMisses: %d\nHits/Miss ratio: %.2lf\nTotal Shots: %d\n", 
		player.player_stats.num_hits,
		player.player_stats.num_misses, 
		player.player_stats.num_hits / player.player_stats.num_misses, 
		player.player_stats.num_hits + player.player_stats.num_misses);

	fclose(input);
}