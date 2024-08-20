#include <stdio.h>

#include "logics.c"


int main(){
	struct Player players[MAX_PLAYERS];
    struct Board board;
    
	
	srand(time(NULL));
	
	initializeGame(players, &board);
	//SelectFirst();
	int first_play = SelectFirst();
	
	
	while(1){
		return 0;
	}
	
	
	
	
	return 0;
}


