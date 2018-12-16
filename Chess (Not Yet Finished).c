/**
    CHESS IN C : PROGRAM BY MR.S
    Started: 22.9.18 1700

    Partly Finished: 03.12.18 1032
    Finished:

    Main problem:
        > Players can manipulate other player's pieces. [SOLVED]
        > friendly fire is ON.. Player can devour it's own chess piece.  [SOLVED]

        Minor Problem:
            > Checkmate Warning
            > Castling

    Program Components:
        Function I: Main
        Function II: GameOver
        Function III: Delay
        Function IV: game
            Cluster I: Assigning coordinates
            Cluster II: Draw the board
            Cluster III: Gameplay
                Sector I: Player's input & input errors
                Sector II: Pawn's Logic
                Sector III: Rook's Logic
                Sector IV: Knight's Logic
                Sector V: Bishop's Logic
                Sector VI: Queen's Logic
                Sector VII: King's Logic

    Suggestions:
        > method for each piece
        > globalization of the variables
**/
#include <stdio.h>
#include <stdlib.h>

void GameOver(int player);
void game();
void delay(int sec);

void main()
{
    int choice;

    printf("\t\t****** CHESS GAME ******\n");
    printf("\t\t[1] PLAY\t[2] EXIT\n");
    printf("\t\tChoice: ");
    scanf("%d", &choice);

    if(choice == 1){
        system("cls");
        game();
    }else{
        return 0;
    }
}

void game(){
    char chess_board[8][8]; //chess_board[y][x]
    char selected_piece,selected_piece_tracker;
    int pos_k[8][2], pos_b[8][2];
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
    // +-----+
    // |     |
    // |  p  |
    // |     |
    // +-----+
    // Cluster II: Draw the board
    printf("\t\t      PLAYER ONE\n");
    printf("   X  1");
    for(int x = 0,x_count = 2; x < 48; x++){
        if(count == 5 && x_count < 9){
                printf("%d",x_count);
                count = 0;
                x_count++;
            }else{
                printf(" ");
                count++;
            }
    }

    count = 0;
    printf("\n Y +");
    for(int dash = 0; dash < 48; dash++){
            if(count == 5){
                printf("+");
                count = 0;
            }else{
                printf("-");
                count++;
            }
        }
    int count_2;
    for( y_len = 0; y_len < 8; y_len++){
        count = 0;
        printf("\n");
        // top
        printf("   |");
        for(int i = 0 ; i < 8 ; i++){
            printf("     |");
        }
        // mid
        printf("\n %d |",y_len+1);
        for( x_len = 0; x_len < 8 ; x_len++){
            printf("  %c  |", chess_board[y_len][x_len]);

        }
        // bot
        printf("\n   |");
        for(int i = 0 ; i < 8 ; i++){
            printf("     |");
        }
        printf("\n");
        printf("   +");
        for(int dash = 0; dash < 48; dash++){
            if(count == 5){
                printf("+");
                count = 0;
            }else{
                printf("-");
                count++;
            }
        }
    }
        printf("\n\t\t      PLAYER TWO\n");
        printf("LEGEND:");
        printf("\n\tp = pawn\tr = rook\tk = knight\n\tb = bishop\tQ = Queen\tK = King\n");
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

        // Sector II: Pawn's Logic
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
        // Sector III: Rook's Logic
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
                if(pieces_tracker[move_y-1][move_x-1] != player){
                    for(int y = sel_y; y <= move_y-1;y++){
                        if(y == move_y-1 && chess_board[y][sel_x-1] != ' '){
                            goto move;
                        }
                        if(chess_board[y][sel_x-1] != ' '){
                            system("cls");
                            printf("ERROR: INVALID MOVE!\n");
                            goto board;
                        }
                    }
                }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
            }else if(sel_y > move_y){
                // up
                if(pieces_tracker[move_y-1][move_x-1] != player){
                    for(int y = sel_y-2; y > move_y-1;y--){
                        if(y == move_y-1 && chess_board[y][sel_x-1] != ' '){
                            goto move;
                        }
                        if(chess_board[y][sel_x-1] != ' '){
                            system("cls");
                            printf("ERROR: INVALID MOVE!\n");
                            goto board;
                        }
                    }
                }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
            }
            // horizontal
            if(sel_x < move_x){
                // right
                if(pieces_tracker[move_y-1][move_x-1] != player){
                    for(int x = sel_x; x <= move_x-1;x++){
                        if(x == move_x-1 && chess_board[sel_y-1][x] != ' '){
                            goto move;
                        }
                        if(chess_board[sel_y-1][x] != ' '){
                            system("cls");
                            printf("ERROR: INVALID MOVE!\n");
                            goto board;
                        }
                    }
                 }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                 }
            }else if(sel_x > move_x){
                // left
                if(pieces_tracker[move_y-1][move_x-1] != player){
                    for(int x = sel_x-2; x >= move_x-1;x--){
                        if(x == move_x-1 && chess_board[sel_y-1][x] != ' '){
                            goto move;
                        }
                        if(chess_board[sel_y-1][x] != ' '){
                            system("cls");
                            printf("ERROR: INVALID MOVE!\n");
                            goto board;
                        }
                    }
                }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                 }
            }
        }
        // Sector IV: Knight's Logic
        if(selected_piece == 'k'){
            pos_k[0][0] = sel_y + 2;
            pos_k[0][1] = sel_x + 1;

            pos_k[1][0] = sel_y + 1;
            pos_k[1][1] = sel_x + 2;

            pos_k[2][0] = sel_y + 2;
            pos_k[2][1] = sel_x - 1;

            pos_k[3][0] = sel_y + 1;
            pos_k[3][1] = sel_x - 2;

            pos_k[4][0] = sel_y - 1;
            pos_k[4][1] = sel_x - 2;

            pos_k[5][0] = sel_y - 2;
            pos_k[5][1] = sel_x - 1;

            pos_k[6][0] = sel_y - 2;
            pos_k[6][1] = sel_x + 1;

            pos_k[7][0] = sel_y - 1;
            pos_k[7][1] = sel_x + 2;
            if((move_x != pos_k[0][1] || move_y != pos_k[0][0]) && (move_x != pos_k[1][1] || move_y != pos_k[1][0]) && (move_x != pos_k[2][1] || move_y != pos_k[2][0]) && (move_x != pos_k[3][1] || move_y != pos_k[3][0]) && (move_x != pos_k[4][1] || move_y != pos_k[4][0]) && (move_x != pos_k[5][1] || move_y != pos_k[5][0]) && (move_x != pos_k[6][1] || move_y != pos_k[6][0]) && (move_x != pos_k[7][1] || move_y != pos_k[7][0])){
                system("cls");
                printf("ERROR: Invalid Move!\n");
                goto board;
            }
        }
        // Sector V: Bishop's Logic
        if(selected_piece == 'b'){
            int count = 0;
            // Preventing the bishop to move other direction except sideway
            if(sel_y == move_y || sel_x == move_x){
                system("cls");
                printf("ERROR: INVALID MOVE!\n");
                goto board;
            }
            // Down-Right
           if(sel_y < move_y && sel_x < move_x){
            // down-right
            if(pieces_tracker[move_y-1][move_x-1] != player){
                for(int y = sel_y+1, x = sel_x+1, move = 0; y <= 8 && x <= 8; y++,x++,move++){
                    // setting bishop track
                    pos_b[move][0] = y;
                    pos_b[move][1] = x;
                }
                for(int y = sel_y, x = sel_x; y <= move_y-1 ; y++,x++){
                    if(y == move_y-1 && chess_board[y][move_x-1] != ' '){
                        goto move;
                    }
                    // No Jumping over to the pieces
                    if(chess_board[y][x] != ' '){
                        system("cls");
                        printf("ERROR: Invalid Move!\n");
                        goto board;
                    }
                }
                for(int i = 0; i < 8; i++){
                    // verifying the player's move
                    if(pos_b[i][0] >= 0){
                        if(pos_b[i][0] == move_y && pos_b[i][1] == move_x){
                            count++;
                        }
                    }
                }
                if(count == 0){
                    system("cls");
                    printf("ERROR: Invalid Move!\n");
                    goto board;
                }
            }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
            }
           }
            // Down-Left
           if(sel_y < move_y && sel_x > move_x){
            // down-left
            if(pieces_tracker[move_y-1][move_x-1] != player){
                for(int y = sel_y+1, x = sel_x-1, move = 0; y <= 8 && x >= 0; y++,x--,move++){
                    // setting bishop track
                    pos_b[move][0] = y;
                    pos_b[move][1] = x;
                }
                for(int y = sel_y, x = sel_x-2; y <= move_y-1 ; y++,x--){
                    if(y == move_y-1 && chess_board[y][move_x-1] != ' '){
                        goto move;
                    }
                    // No Jumping over to the pieces
                    if(chess_board[y][x] != ' '){
                        system("cls");
                        printf("ERROR: Invalid Move!\n");
                        goto board;
                    }
                }
                for(int i = 0; i < 8; i++){
                    // verifying the player's move
                    if(pos_b[i][0] >= 0){
                        if(pos_b[i][0] == move_y && pos_b[i][1] == move_x){
                            count++;
                        }
                    }
                }
                if(count == 0){
                    system("cls");
                    printf("ERROR: Invalid Move!\n");
                    goto board;
                }
            }else{
                    system("cls");
                    printf("ERROR: YOUR TRYING TO EAT IS YOUR OWN PIECE!\n");
                    goto board;
            }
           }
            // Up-Right
           if(sel_y > move_y && sel_x < move_x){
            // up-right
            if(pieces_tracker[move_y-1][move_x-1] != player){
                for(int y = sel_y-1, x = sel_x+1, move = 0; y >= 0 && x <= 8 ; y--,x++,move++){
                    // setting bishop track
                    pos_b[move][0] = y;
                    pos_b[move][1] = x;
                }
                for(int y = sel_y-2, x = sel_x; y >= move_y-1 ; y--,x++){
                    if(y == move_y-1 && chess_board[y][move_x-1] != ' '){
                        goto move;
                    }
                    // No Jumping over to the pieces
                    if(chess_board[y][x] != ' '){
                        system("cls");
                        printf("ERROR: Invalid Move!\n");
                        goto board;
                    }
                }
                for(int i = 0; i < 8; i++){
                    // verifying the player's move
                    if(pos_b[i][0] >= 0){
                        if(pos_b[i][0] == move_y && pos_b[i][1] == move_x){
                            count++;
                        }
                    }
                }
                if(count == 0){
                    system("cls");
                    printf("ERROR: Invalid Move!\n");
                    goto board;
                }
            }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
            }
           }
            // Up-Left
           if(sel_y > move_y && sel_x > move_x){
            // up-left
            if(pieces_tracker[move_y-1][move_x-1] != player){
                for(int y = sel_y-1, x = sel_x-1, move = 0; y >= 0 && x >= 0 ; y--,x--,move++){
                    // setting bishop track
                    pos_b[move][0] = y;
                    pos_b[move][1] = x;
                }
                for(int y = sel_y-2, x = sel_x-2; y >= move_y-1 ; y--,x--){
                    if(y == move_y-1 && chess_board[y][move_x-1] != ' '){
                        goto move;
                    }
                    // No Jumping over to the pieces
                    if(chess_board[y][x] != ' '){
                        system("cls");
                        printf("ERROR: Invalid Move!\n");
                        goto board;
                    }
                }
                for(int i = 0; i < 8; i++){
                    // verifying the player's move
                    if(pos_b[i][0] >= 0){
                        if(pos_b[i][0] == move_y && pos_b[i][1] == move_x){
                            count++;
                        }
                    }
                }
                if(count == 0){
                    system("cls");
                    printf("ERROR: Invalid Move!\n");
                    goto board;
                }
            }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
            }
           }
        }
        // Sector VI: Queen's Logic
        if(selected_piece == 'Q'){
            // straight and side line only
            int count = 0;
            // vertical
            if(sel_y < move_y && sel_x == move_x){
                // down
                if(pieces_tracker[move_y-1][move_x-1] != player){
                    for(int y = sel_y; y <= move_y-1;y++){
                        if(y == move_y-1 && chess_board[y][sel_x-1] != ' '){
                            goto move;
                        }
                        if(chess_board[y][sel_x-1] != ' '){
                            system("cls");
                            printf("ERROR: INVALID MOVE!\n");
                            goto board;
                        }
                    }
                }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
            }else if(sel_y > move_y && sel_x == move_x){
                // up
                if(pieces_tracker[move_y-1][move_x-1] != player){
                    for(int y = sel_y-2; y > move_y-1;y--){
                        if(y == move_y-1 && chess_board[y][sel_x-1] != ' '){
                            goto move;
                        }
                        if(chess_board[y][sel_x-1] != ' '){
                            system("cls");
                            printf("ERROR: INVALID MOVE! vu1\n");
                            goto board;
                        }
                    }
                }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE!\n");
                    goto board;
                }
            }
            // horizontal
            if(sel_x < move_x && sel_y == move_y){
                // right
                if(pieces_tracker[move_y-1][move_x-1] != player){
                    for(int x = sel_x; x <= move_x-1;x++){
                        if(x == move_x-1 && chess_board[sel_y-1][x] != ' '){
                            goto move;
                        }
                        if(chess_board[sel_y-1][x] != ' '){
                            system("cls");
                            printf("ERROR: INVALID MOVE!\n");
                            goto board;
                        }
                    }
                 }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE! hr2\n");
                    goto board;
                 }
            }else if(sel_x > move_x && sel_y == move_y){
                // left
                if(pieces_tracker[move_y-1][move_x-1] != player){
                    for(int x = sel_x-2; x >= move_x-1;x--){
                        if(x == move_x-1 && chess_board[sel_y-1][x] != ' '){
                            goto move;
                        }
                        if(chess_board[sel_y-1][x] != ' '){
                            system("cls");
                            printf("ERROR: INVALID MOVE! hl1\n");
                            goto board;
                        }
                    }
                }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE! hl2\n");
                    goto board;
                 }
            }
            // Down-Right
           if(sel_y < move_y && sel_x < move_x){
            // down-right
            if(pieces_tracker[move_y-1][move_x-1] != player){
                for(int y = sel_y+1, x = sel_x+1, move = 0; y <= 8 && x <= 8; y++,x++,move++){
                    // setting bishop track
                    pos_b[move][0] = y;
                    pos_b[move][1] = x;
                }
                for(int y = sel_y, x = sel_x; y <= move_y-1 ; y++,x++){
                    if(y == move_y-1 && chess_board[y][move_x-1] != ' '){
                        goto move;
                    }
                    // No Jumping over to the pieces
                    if(chess_board[y][x] != ' '){
                        system("cls");
                        printf("ERROR: Invalid Move! drx1\n");
                        goto board;
                    }
                }
                for(int i = 0; i < 8; i++){
                    // verifying the player's move
                    if(pos_b[i][0] >= 0){
                        if(pos_b[i][0] == move_y && pos_b[i][1] == move_x){
                            count++;
                        }
                    }
                }
                if(count == 0){
                    system("cls");
                    printf("ERROR: Invalid Move! drx2\n");
                    goto board;
                }
            }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE! drx3\n");
                    goto board;
            }
           }
            // Down-Left
           if(sel_y < move_y && sel_x > move_x){
            // down-left
            if(pieces_tracker[move_y-1][move_x-1] != player){
                for(int y = sel_y+1, x = sel_x-1, move = 0; y <= 8 && x >= 0; y++,x--,move++){
                    // setting bishop track
                    pos_b[move][0] = y;
                    pos_b[move][1] = x;
                }
                for(int y = sel_y, x = sel_x-2; y <= move_y-1 ; y++,x--){
                    if(y == move_y-1 && chess_board[y][move_x-1] != ' '){
                        goto move;
                    }
                    // No Jumping over to the pieces
                    if(chess_board[y][x] != ' '){
                        system("cls");
                        printf("ERROR: Invalid Move! dlx1\n");
                        goto board;
                    }
                }
                for(int i = 0; i < 8; i++){
                    // verifying the player's move
                    if(pos_b[i][0] >= 0){
                        if(pos_b[i][0] == move_y && pos_b[i][1] == move_x){
                            count++;
                        }
                    }
                }
                if(count == 0){
                    system("cls");
                    printf("ERROR: Invalid Move! dlx2\n");
                    goto board;
                }
            }else{
                    system("cls");
                    printf("ERROR: YOUR TRYING TO EAT IS YOUR OWN PIECE!\n");
                    goto board;
            }
           }
            // Up-Right
           if(sel_y > move_y && sel_x < move_x){
            // up-right
            if(pieces_tracker[move_y-1][move_x-1] != player){
                for(int y = sel_y-1, x = sel_x+1, move = 0; y >= 0 && x <= 8 ; y--,x++,move++){
                    // setting bishop track
                    pos_b[move][0] = y;
                    pos_b[move][1] = x;
                }
                for(int y = sel_y-2, x = sel_x; y >= move_y-1 ; y--,x++){
                    if(y == move_y-1 && chess_board[y][move_x-1] != ' '){
                        goto move;
                    }
                    // No Jumping over to the pieces
                    if(chess_board[y][x] != ' '){
                        system("cls");
                        printf("ERROR: Invalid Move! urx1\n");
                        goto board;
                    }
                }
                for(int i = 0; i < 8; i++){
                    // verifying the player's move
                    if(pos_b[i][0] >= 0){
                        if(pos_b[i][0] == move_y && pos_b[i][1] == move_x){
                            count++;
                        }
                    }
                }
                if(count == 0){
                    system("cls");
                    printf("ERROR: Invalid Move! urx2\n");
                    goto board;
                }
            }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE! urx3\n");
                    goto board;
            }
           }
            // Up-Left
           if(sel_y > move_y && sel_x > move_x){
            // up-left
            if(pieces_tracker[move_y-1][move_x-1] != player){
                for(int y = sel_y-1, x = sel_x-1, move = 0; y >= 0 && x >= 0 ; y--,x--,move++){
                    // setting bishop track
                    pos_b[move][0] = y;
                    pos_b[move][1] = x;
                }
                for(int y = sel_y-2, x = sel_x-2; y >= move_y-1 ; y--,x--){
                    if(y == move_y-1 && chess_board[y][move_x-1] != ' '){
                        goto move;
                    }
                    // No Jumping over to the pieces
                    if(chess_board[y][x] != ' '){
                        system("cls");
                        printf("ERROR: Invalid Move! ulx1\n");
                        goto board;
                    }
                }
                for(int i = 0; i < 8; i++){
                    // verifying the player's move
                    if(pos_b[i][0] >= 0){
                        if(pos_b[i][0] == move_y && pos_b[i][1] == move_x){
                            count++;
                        }
                    }
                }
                if(count == 0){
                    system("cls");
                    printf("ERROR: Invalid Move! ulx2\n");
                    goto board;
                }
            }else{
                    system("cls");
                    printf("ERROR: INVALID MOVE! ulx3\n");
                    goto board;
            }
           }
        }
        // Sector VII: King's Logic
        if(selected_piece == 'K'){
            if(move_x > sel_x+1 && move_y == sel_y){
            // Right
                system("cls");
                printf("ERROR: Invalid Move! r\n");
                goto board;
            }
            if(move_x < sel_x-1 && move_y == sel_y){
            // Left
                system("cls");
                printf("ERROR: Invalid Move! l\n");
                goto board;
            }
            if(move_y > sel_y+1 && move_x == sel_x){
            // Down
                system("cls");
                printf("ERROR: Invalid Move! d\n");
                goto board;
            }
            if(move_y < sel_y-1 && move_x == sel_x){
            // Up
                system("cls");
                printf("ERROR: Invalid Move! u\n");
                goto board;
            }
            if(move_x > sel_x+1 && move_y > sel_y+1){
            // Down-Right
                system("cls");
                printf("ERROR: Invalid Move! dr1\n");
                goto board;
            }
            if(move_x > sel_x+1 && move_y < sel_y-1){
            // Up-Right
                system("cls");
                printf("ERROR: Invalid Move! ur\n");
                goto board;
            }
            if(move_x < sel_x-1 && move_y > sel_y+1){
            // Down-Left
                system("cls");
                printf("ERROR: Invalid Move! dl\n");
                goto board;
            }
            if(move_x < sel_x-1 && move_y < sel_y-1){
            // Up-Left
                system("cls");
                printf("ERROR: Invalid Move! ul\n");
                goto board;
            }
            if(chess_board[move_y-1][move_x-1] != ' ' && pieces_tracker[move_y-1][move_x-1] == player){
                system("cls");
                printf("ERROR: Invalid Move!\n");
                goto board;
            }
        }
move:
        // Friendly Fire : OFF
        if(pieces_tracker[move_y-1][move_x-1] == player ){
                system("cls");
                printf("ERROR: YOUR TRYING TO EAT IS YOUR OWN PIECE!\n");
                goto board;
        }
        if(chess_board[move_y-1][move_x-1] == 'K'){
            GameOver(player);
        }
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

void GameOver(int player){
    char choice;

    system("cls");
    printf("\t\t*******************\n");
    printf("\t\t* G A M E O V E R *\n");
    printf("\t\t*******************\n");
    printf("\t\t   PLAYER %d WINS\n\n",player);
repeat:
    printf("\t\tPlay again? [Y/N] > ");
    scanf("%s", &choice);
    if((choice != 'N' && choice != 'n') && (choice != 'Y' && choice != 'y')){
        printf("\t\tError: Invalid Character!\n");
        goto repeat;
    }
    if(choice == 'Y' || choice == 'y'){
        system("cls");
        main();
    }else{
        system("cls");
        printf("\t\t***********************\n");
        printf("\t\t* THANK YOU! GOODBYE! *\n");
        printf("\t\t***********************\n");
        return 0;
    }
}

void delay(int sec){
    for (int c = 1; c <= (sec * 10000); c++)
       for (int d = 1; d <= (sec * 10000); d++)
       {}
}

