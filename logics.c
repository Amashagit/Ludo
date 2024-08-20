#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "types.c"

const char* PlayertoColor(int player);
const char* PiecestoPlay(int piece);
void initializeGame();
struct Piece Piece[16];


const char* PlayertoColor(int player){
		
		if(player == 0){
			return "Yellow";
		}else if(player == 1){
			return "Blue";
		}else if(player == 2){
			return "Red";
		}else if(player == 3){
			return "Green";
		}else{
			return "Unknown";
		}
	}
	const char* PiecestoPlay(int piece){
		if(piece == 0){
			return "Y";
		}else if(piece == 1){
			return "B";
		}else if(piece == 2){
			return "R";
		}else if(piece == 3){
			return "G";
		}else{
			return "Unknown";
		}
	}
	// Function to initialize players
void initializePlayers(struct Player players[MAX_PLAYERS]) {
	  for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].player_id = i;
        players[i].pieces_in_base = 4;
        players[i].pieces_in_play = 0;
        players[i].pieces_in_home = 0;
        players[i].rounds_sick = 0;
        players[i].consecutive_sixes = 0;
        for (int j = 0; j < MAX_PIECES; j++) {
            players[i].pieces[j].position = -1;
            players[i].pieces[j].home = 0;
            players[i].pieces[j].captured = 0;
            players[i].pieces[j].block_count = 0;
            players[i].pieces[j].is_energized = 0;
            players[i].pieces[j].is_sick = 0;
            players[i].pieces[j].is_briefing = 0;
            players[i].pieces[j].is_moving_clockwise = 1;
            players[i].pieces[j].is_teleported = 0;
            players[i].pieces[j].original_direction = 1;
        }
    }
}

void initializeBoard(struct Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->cells[i] = 0;
    }
    board->mystery_cell_location = -1;
    board->mystery_cell_rounds_left = 0;
    board->total_rounds = 0;
}

	
	void initializeGame(struct Player players[MAX_PLAYERS], struct Board *board) {
		
	
		
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("The %s player has four (04) pieces named %s1, %s2, %s3, and %s4.\n",
            PlayertoColor(i), PiecestoPlay(i), PiecestoPlay(i), PiecestoPlay(i), PiecestoPlay(i));
    }
    initializePlayers(players);
    initializeBoard(board);
}

  int rollDice(){
  	return ((rand()%6)+1);
  }
  
  int rollToss(){
  	return((rand()%2));
  }
  
 /* void resetPiece(){
  	struct Piece Piece[16];
  	
  	for(int i=0; i<16;i++){
	  
  	Piece[i].position = -1;  // Position on the board or -1 for base
    Piece[i].home = 0;  // 1 if the piece has reached home, else 0
    Piece[i].captured = 0;  // Number of captures by the piece
    Piece[i].block_count = 0; // Part of a block (number of pieces in the block)
    Piece[i].is_energized = 0;  // 1 if energized, 0 if not
    Piece[i].is_sick = 0;  // 1 if sick, 0 if not
    Piece[i].is_briefing = 0;  // 1 if in briefing, 0 if not
    Piece[i].is_moving_clockwise = -1; // 1 if clockwise, 0 if counterclockwise
    Piece[i].is_teleported = 0; // 1 if teleported, 0 if not
    Piece[i].original_direction = -1;
   }
}*/
  
    int SelectFirst() {
    int max = 0;
    int player = 0;  // To track the player with the highest roll
    int max_count = 0;  // To count the number of players with the maximum roll

    for (int i = 0; i < MAX_PLAYERS; i++) {
        int roll = rollDice();
        printf("%s player rolled %d\n", PlayertoColor(i), roll);

        if (roll > max) {
            max = roll;
            player = i;
            max_count = 1;  // Reset count since we have a new max
        } else if (roll == max) {
            max_count++;
        }
    }

    if (max_count >= 2) {
        printf("Multiple players rolled the max number, rolling again.\n");
        return SelectFirst();  // Re-roll for a tie
    } else {
        printf("%s player has the highest roll and will begin the game.\n", PlayertoColor(player));
        printf("The order of a single round is %s, %s, %s and %s.\n",
            PlayertoColor(player),
            PlayertoColor((player + 1) % MAX_PLAYERS),
            PlayertoColor((player + 2) % MAX_PLAYERS),
            PlayertoColor((player + 3) % MAX_PLAYERS));
    }
    return player;
}



		
    	


	


