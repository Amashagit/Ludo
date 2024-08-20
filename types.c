#include <stdio.h>

#define MAX_PLAYERS 4
#define MAX_PIECES 4
#define BOARD_SIZE 52
#define MYSTERY_CELL_DURATION 4

// Positions for special locations
#define BASE -1
#define HOME 1
#define BHAWANA 9
#define KOTUWA 27
#define PITA_KOTUWA 46

// Define the piece structure
struct Piece {
    int position;  // Position on the board or -1 for base
    int home;  // 1 if the piece has reached home, else 0
    int captured;  // Number of captures by the piece
    int block_count; // Part of a block (number of pieces in the block)
    int is_energized;  // 1 if energized, 0 if not
    int is_sick;  // 1 if sick, 0 if not
    int is_briefing;  // 1 if in briefing, 0 if not
    int is_moving_clockwise; // 1 if clockwise, 0 if counterclockwise
    int is_teleported; // 1 if teleported, 0 if not
    int original_direction; // Original direction after entering from base
};

// Define the player structure
struct Player {
    struct Piece pieces[MAX_PIECES];
    int player_id;
    int pieces_in_base;
    int pieces_in_play;
    int pieces_in_home;
    int rounds_sick; // Number of rounds the player is sick
    int consecutive_sixes; // Number of consecutive sixes rolled
};

// Define the board structure
struct Board {
    int cells[BOARD_SIZE]; // Each cell indicates how many pieces are present
    int mystery_cell_location; // Current mystery cell location
    int mystery_cell_rounds_left; // Rounds left for the mystery cell
    int total_rounds;  // Total rounds played in the game
};


