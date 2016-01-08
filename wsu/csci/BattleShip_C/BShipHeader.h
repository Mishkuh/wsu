#ifndef PA6_H
#define PA6_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
typedef struct ship
{
	int ship_length;
	int ship_hits;
	char ship_symbol;
	char *ship_name;

} Ship;
typedef struct stats
{
	int num_misses;
	int num_hits;
	int total_shots;
	double hits_misses_ratio;
} Stats;
typedef struct player
{
	Ship ship_carrier;
	Ship ship_battleship;
	Ship ship_submarine;
	Ship ship_cruiser;
	Ship ship_destroyer;
	Stats player_stats;

} Player;

void welcome_screen(void);
void option_menu(int *choice);
void select_who_goes_first (int *player_start);
void init_board (char board[10][10], int num_rows, int num_cols);
void print_board (char board[10][10], int num_rows, int num_cols);
void generate_direction (int *dir);
void generate_random_start_pt (int direction, int length, int *row, int *col);
void generate_manual_start_pt (Ship *boat, int *row, int *col);
int check_ship_place (char board[10][10], int row_start, int col_start, int dir, int length, char symbol);
void place_ship (char board[10][10], int row_start, int col_start, int dir, int length, char symbol);
void check_shot (char board[10][10], int col, int row, int *hit, Player *player);
void shot_attempt (char board[10][10], Player *player);
void shot_attempt_random (char board[10][10], Player *player2);
void shot_attempt_blind (char board[10][10], char board_blind[10][10], Player *player1);
int check_ship(Player *player);
void randomly_place_ships(char board[10][10], Player *player);
void manually_place_ships(char board[10][10], Ship boat);
void generate_manual_direction (int *direction);
void ship_init(Ship *ship, char type);
void player_init(Player *player);
void write_to_file (Player player);

#endif