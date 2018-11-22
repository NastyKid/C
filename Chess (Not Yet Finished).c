/**
    CHESS IN C : PROGRAM BY MR.S
    Started: 22.9.18 1700
    Finished:

    Main problem:
        > Players can manipulate other player's pieces. [SOLVED]

        > friendly fire is ON.. Player can devour it's own chess piece.  [SOLVED]


    Program :
        Function I: Main
        Function II: Delay
        Function III: game
            Cluster I: Assigning coordinates
            Cluster II: Draw the board
            Cluster III: Gameplay
                Sector I: Player's input & input errors
                Sector II: Pawn Logics

**/
#include <stdio.h>
#include <stdlib.h>

void delay(int sec);
void game();

int main()
{
    int choice;

    printf("****** CHESS GAME ******\n");
    printf("[1] PLAY\t[2] EXIT\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        system("cls");
        game();
    }else{
        return 0;
    }
    return 0;
}

void game(){
    char chess_board[8][8]; //chess_board[y][x]
    char selected_piece,selected_piece_tracker;
    int pieces_tracker[8][8],piece_tracker;
    int y_len,x_len,count = 0,player = 1,round_counter = 1,promotion;
    int move_x,move_y,sel_x,sel_y,move_y_tracker,move_x_tracker,sel_y_tracker,sel_x_tracker;
    // Cluster I: Assigning coordinates
    // White
    chess_board[0][0] = 'r';
    chess_board[0][1] = 'k';
    chess_board[0][2] = 'b';
    chess_board[0][3] = 'K';
    chess_board[0][4] = 'Q';
    chess_board[0][5] = 'b';
    chess_board[0][6] = 'k';
    chess_board[0][7] = 'r';
    for(int x = 0;x < 8;x++){
        chess_board[1][x] = 'p';
    }
    // Player 1 chess pieces tracker
    for( int y = 0;y < 2; y++){
        for( int x = 0; x < 8; x++){
            pieces_tracker[y][x] = 1;
        }
    }

    for(int y = 2; y < 6; y++){
        for(int x = 0; x < 8; x++){
            chess_board[y][x] = ' ';
            pieces_tracker[y][x] = 0;
        }
    }

    // Black
    chess_board[7][0] = 'r';
    chess_board[7][1] = 'k';
    chess_board[7][2] = 'b';
    chess_board[7][3] = 'K';
    chess_board[7][4] = 'Q';
    chess_board[7][5] = 'b';
    chess_board[7][6] = 'k';
    chess_board[7][7] = 'r';
    for(int x = 0;x < 8;x++){
        chess_board[6][x] = 'p';
    }
    // Player 2 chess pieces tracker
    for( int y = 6;y < 8; y++){
        for( int x = 0; x < 8; x++){
            pieces_tracker[y][x] = 2;
        }
    }

board:

    // Cluster II: Draw the board
    printf("\t     PLAYER ONE\n");
    printf("  x 1");
    for(int x = 0,x_count = 2; x < 30; x++){
        if(count == 3){
                printf("%d",x_count);
                count = 0;
                x_count++;
            }else{
                printf(" ");
                count++;
            }
    }
    count = 0;
    printf("\ny +");
    for(int dash = 0; dash < 32; dash++){
            if(count == 3){
                printf("+");
                count = 0;
            }else{
                printf("-");
                count++;
            }
        }
    for( y_len = 0; y_len < 8; y_len++){
        count = 0;
        printf("\n");

        printf("%d |",y_len+1);
        for( x_len = 0; x_len < 8 ; x_len++){
            printf(" %c |", chess_board[y_len][x_len]);

        }

        printf("\n");
        printf("  +");
        for(int dash = 0; dash < 32; dash++){
            if(count == 3){
                printf("+");
                count = 0;
            }else{
                printf("-");
                count++;
            }
        }
    }
        printf("\n\t     PLAYER TWO\n");

    // Cluster III: Gameplay
        // Sector I: Player's input & input errors
        // Selecting
        printf("\nPlayer %d Turn",player);
        printf("\nEnter the coordinate of the piece to move: ");
        printf("\nY: ");
        scanf("%d",&sel_y);
        printf("X: ");
        scanf("%d",&sel_x);
        // Moving to
        printf("Move to? ");
        printf("\nY: ");
        scanf("%d",&move_y);
        printf("X: ");
        scanf("%d",&move_x);

        if(move_y > 8 || move_x > 8 || sel_y > 8 || sel_x > 8){
            system("cls");
            printf("ERROR: INVALID COORDINATE!\n");
            goto board;
        }

        // Get the chess piece in that coordinate and validate either it is his/her piece.
        if(player == 1 && pieces_tracker[sel_y-1][sel_x-1] == 1){
            selected_piece = chess_board[sel_y-1][sel_x-1];
            piece_tracker = pieces_tracker[sel_y-1][sel_x-1];
        }else if(player == 2 && pieces_tracker[sel_y-1][sel_x-1] == 2){
            selected_piece = chess_board[sel_y-1][sel_x-1];
            piece_tracker = pieces_tracker[sel_y-1][sel_x-1];
        }else{
            system("cls");
            printf("ERROR: IT IS NOT YOUR CHESS PIECE OR NO PIECE IN THAT LOCATION!\n");
            goto board;
        }

        // Sector II: Pawn Logic
        // 1st Pawn Move:
        if(selected_piece == 'p'){
                if(player == 1 && ((sel_y == 2 || sel_y == 7) && (sel_x <= 8)) && ((move_y - sel_y) > 2 )) {
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
                if(player == 2 && ((sel_y == 2 || sel_y == 7) && (sel_x <= 8)) && ((move_y - sel_y) * -1 > 2 )) {
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
        }
        if(selected_piece == 'p'){
                // En passant Move
                if(player == 1 && selected_piece_tracker == 'p' && sel_y_tracker == 7 && move_y_tracker == 5 && move_x == move_x_tracker && move_y == 6){
                    chess_board[move_y_tracker-1][move_x_tracker-1] = ' ';
                    goto move;
                }
                if(player == 2 && selected_piece_tracker == 'p' && sel_y_tracker == 2 && move_y_tracker == 4 && move_x == move_x_tracker && move_y == 3){
                    chess_board[move_y_tracker-1][move_x_tracker-1] = ' ';
                    goto move;
                }
                // Preventing the pawn to move sideward except if the coordinate (y+1,x+1) or (y+1,x-1) have food
                if(chess_board[move_y-1][move_x-1] == ' ' && move_x != sel_x){
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
                // Preventing the player's pawn to move backward
                if(player == 1 && move_y <= sel_y){
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
                if(player == 2 && move_y >= sel_y){
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
                // Preventing the player's pawn to move twice/more blocks after it leave it's post.
                if(player == 1 && chess_board[1][sel_x-1] != 'p' && ((move_y - sel_y) > 1)){
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
                if(player == 2 && chess_board[6][sel_x-1] != 'p' && ((move_y - sel_y) * -1 > 1)) {
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
                // Preventing to devour the piece in front of the pawn
                if(move_x == sel_x && chess_board[move_y-1][move_x-1] != ' '){
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
                // Promotion
                if((player == 1 && move_y == 8) || (player == 2 && move_y == 1)){
                    system("cls");
                    printf("PROMOTION!!!");
                    delay(3);
                    system("cls");
                    printf("PROMOTE INTO?\n1 - Rook\n2 - Knight\n3 - Bishop\n4 - Queen\nPromote : ");
                    scanf("%d",&promotion);
                    switch(promotion){
                    case 1:
                        selected_piece = 'r';
                        printf("Promoting pawn to rook!");
                        delay(2);
                        system("cls");
                        goto move;
                        break;
                    case 2:
                        selected_piece = 'k';
                        printf("Promoting pawn to knight!");
                        delay(2);
                        system("cls");
                        goto move;
                        break;
                    case 3:
                        selected_piece = 'b';
                        printf("Promoting pawn to bishop!");
                        delay(2);
                        system("cls");
                        goto move;
                        break;
                    case 4:
                        selected_piece = 'Q';
                        printf("Promoting pawn to Queen!");
                        delay(2);
                        system("cls");
                        goto move;
                        break;
                    default:
                        break;
                    }
                }
        }
        // Sector III: Rook Logic
        if(selected_piece == 'r'){
            // Preventing the rook to move other direction except straight line
            if(move_y != sel_y && move_x != sel_x){
                system("cls");
                printf("ERROR: INVALID MOVE!\n");
                goto board;
            }

            // Preventing the rook to jump over a chess piece
            // vertical
            if(sel_y < move_y){
                // down
                 for(int y = sel_y; y <= move_y-1;y++){
                    if(chess_board[y][sel_x-1] != ' '){
                        system("cls");
                        printf("ERROR_v1: INVALID MOVE!\n");
                        goto board;
                    }
                 }
            }else if(sel_y > move_y){
                // up
                for(int y = sel_y-2; y > move_y-1;y--){
                    if(chess_board[y][sel_x-1] != ' '){
                        system("cls");
                        printf("ERROR_v2: INVALID MOVE!\n");
                        goto board;
                    }
                }
            }
            // horizontal
            if(sel_x < move_x){
                // right
                 for(int x = sel_x; x <= move_x-1;x++){
                    if(chess_board[sel_y-1][x] != ' '){
                        system("cls");
                        printf("ERROR: INVALID MOVE!\n");
                        goto board;
                    }
                 }
            }else if(sel_x > move_x){
                // left
                for(int x = sel_x-2; x >= move_x-1;x--){
                    if(chess_board[sel_y-1][x] != ' '){
                        system("cls");
                        printf("ERROR: INVALID MOVE!\n");
                        goto board;
                    }
                 }
            }
        }
        // Friendly Fire : OFF
        if(pieces_tracker[move_y-1][move_x-1] == player ){
                system("cls");
                printf("ERROR: YOUR TRYING TO EAT IS YOUR OWN PIECE!\n");
                goto board;
        }
move:
        //Move the piece
        chess_board[sel_y-1][sel_x-1] = ' ';
        chess_board[move_y-1][move_x-1] = selected_piece;
        pieces_tracker[sel_y-1][sel_x-1] = 0;
        pieces_tracker[move_y-1][move_x-1] = piece_tracker;

        // Save the previous move
        move_y_tracker = move_y;
        move_x_tracker = move_x;
        sel_y_tracker = sel_y;
        sel_x_tracker = sel_x;
        selected_piece_tracker = selected_piece;

        player++;
        if(player == 3){
            round_counter++;
            player = 1;
        }
        system("cls");
        goto board;
}


void delay(int sec){
    int c,d;
    sec = sec * 10000;
    for(c = 1;c <= sec; c++){
        for(d = 1; d <= sec; d++){

        }
    }

}
