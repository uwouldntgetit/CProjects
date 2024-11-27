// making a tic tac toe game using terminal
// the idea is that of creating a gird using printf and then make the user input the coordinates of where it wants to place its sign on the grid
// the grid concept will be made on a matrix
// the game will run on a while loop, with a function to display the updated grid at the start of every new turn, 
// the while loop will be rerun using the continue statement
// the event checker for the win condition will check every possible combination
//
// TO DO:
// - add rematch option: do a function that skips the "return false" of is_draw and is_won
// 
// - add an exit option
//
// - make the grid look better
//
#include <stdio.h>
#include <stdbool.h>

#define GRID_LENGTH 3
#define NAME_LENGTH 30

bool is_won(char[][GRID_LENGTH], char[], char[]);
bool is_draw(char[][GRID_LENGTH]);
// both are event checkers 
void print_grid(char [][GRID_LENGTH]);
// prints the updated grid

void sign_in_grid(int, int, char, char[][GRID_LENGTH]);
void take_position_input(int, int*, char*); // used in sign_in_grid
bool check_if_occupied(char[][GRID_LENGTH], int, int);

int check_columns(char[][GRID_LENGTH]);
int check_rows(char[][GRID_LENGTH]);
int check_diagonal(char[][GRID_LENGTH]);
//they all check if a certain player has won, all three used is_won

void print_chosen_player(int, char[], char[]); // used in is_won
void display_string(char[]); // used in print_chosen_player
// functions to handle strings

void refresh(char[][GRID_LENGTH]);
// fills the grid with '-'

/**********************************************************************************
 -------------------------END OF FUNCTION INTIALIZATION----------------------------
 *********************************************************************************/

int main(void){    
    char grid[GRID_LENGTH][GRID_LENGTH];
    // in this matrix i will put the character to keep the score
    refresh(grid);
    // it fills the matrix with '-'

    char name_player_1[NAME_LENGTH];
    char name_player_2[NAME_LENGTH];
   
    int turn_counter = 1;
    int row_chosen;
    char column_chosen;
    // set of variable used to poosition a sign on the grid
    
    bool win_checker = true;

    printf("Player 1, choose your name: ");
    scanf(" %30[^\n]", name_player_1);
    printf("Player 2, choose your name: ");
    scanf(" %30[^\n]", name_player_2);


    while(win_checker){
        print_grid(grid);
        // printf("print_grid done\n");
        take_position_input(turn_counter,&row_chosen, &column_chosen);
        // printf("take_position_input done\n");
        sign_in_grid(turn_counter, row_chosen, column_chosen, grid);
        // printf("sign_in_grid done\n");
        // print_grid(grid);

        win_checker = is_won(grid, name_player_1, name_player_2);
        // printf("is_won done\n");
        win_checker = is_draw(grid);
        //printf("is_draw done\n");
        
        turn_counter++;
    }
    return 0;
}

/**********************************************************************************
 -------------------------START OF FUNCTION DECLARATION----------------------------
 *********************************************************************************/

// function that is used to put the sign on the chosen position on the grid
void sign_in_grid(int turn_counter, int row_chosen, char column_chosen, char grid[][GRID_LENGTH]){
    char character_to_put;
    if((turn_counter % 2) == 0)
    {
        character_to_put = 'O';
    }
    else
    {
        character_to_put = 'X';
    }
    // if the turn is even, then the character to put in the grid must be 'O', otherwise
    // it must be 'X'

    int final_row_result = row_chosen - 1;
    int final_column_result;
    // used to store the final result of rows and columns

    int n = 0;
    // variable used as the while loop expression to check
    while(n == 0)
    {
        switch(column_chosen)
        {
            case 'a':
                final_column_result = 0;
                break;
            case 'b':
                final_column_result = 1;
                break;
            case 'c':
                final_column_result = 2;
                break;
            default:
                // the input character is illegal
                printf("Illegal position inserted!\n");
                take_position_input(turn_counter, &row_chosen, &column_chosen);
        }
        
        if(check_if_occupied(grid, final_row_result, final_column_result) == true)
        {
            grid[final_row_result][final_column_result] = character_to_put;
            n = 1;
        }else
        {
            printf("The position is already occupied, choose another one\n");
            take_position_input(turn_counter, &row_chosen, &column_chosen);
        }
    }
}

// takes in input the player's next move
void take_position_input(int turn_counter, int *row_chosen, char *column_chosen)
{
    int player = (turn_counter % 2) == 0? 2 : 1;
    // if turn is even, then player ==2 else player == 1
    printf("Player %d, insert the position of your chosen placement: \n", player);
    printf("Row: ");
    scanf("%1d", row_chosen);
    printf("Column: ");
    scanf(" %1[^\n]", column_chosen);

}

// function that checks if a player won or not
bool is_won(char grid[][GRID_LENGTH], char name_player_1[], char name_player_2[]){
    // the first argument of print_chosen_player is the result of the
    // event checker funcitons, that determine wich player has won
    if(check_rows(grid) != 0)
    {
        print_chosen_player(check_rows(grid), name_player_1, name_player_2);
        // the first argument is the return of the function that indicates which
        // player has won
        return false;
    }
    else if(check_columns(grid) != 0)
    {
        print_chosen_player(check_rows(grid), name_player_1, name_player_2); 
        return false;
    }
    else if(check_diagonal(grid) != 0)
    {
        print_chosen_player(check_rows(grid), name_player_1, name_player_2); 
        return false;
    }
    return true;

}

// function that checks if the game was a draw
bool is_draw(char grid[][GRID_LENGTH])
{
    int draw_counter = 0;
    for(int i = 0; i < GRID_LENGTH; i++){
        for(int j = 0; j < GRID_LENGTH; j++){
            if(grid[i][j] == 'X' || grid[i][j] == 'O'){
                draw_counter++;
            }
        }
    }
    if(draw_counter == 9){
        printf("It's a draw!\n");
        return false;
    }
    return true;
}

// checks if a column is occupied by only one character
int check_columns(char grid[][GRID_LENGTH])
{
    for(int i = 0; i < GRID_LENGTH; i++)
    {
        if(grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
        {
            if(grid[0][i] == 'X')
                return 1;
            if(grid[0][i] == 'O')
                return 2;
        }
    }
    return 0;
}

// checks if a row is occpuied by only one character
int check_rows(char grid[][GRID_LENGTH])
{
    for(int i = 0; i < GRID_LENGTH; i++)
    {
        if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
        {
            if(grid[i][0] == 'X')
                return 1;
            if(grid[i][0] == 'O')
                return 2;
        } 
    }
    return 0;
}

// it check if a diagonal is occupied by only one character
int check_diagonal(char grid[][GRID_LENGTH])
{
    if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2])
    {
        if(grid[0][0] == 'X')
            return 1;
        if(grid[0][0] == 'O')
            return 2;
    }
    return 0;
}

// it prints the grid 
void print_grid(char grid[][GRID_LENGTH])
{
    int x = 1;
    // sign variable 
    printf("\n\n  a   b   c  \n");
    for(int i = 0; i < GRID_LENGTH; i++)
    {
        printf("\n   |   |     %d\n", x);
        // to make the grid look better
        for(int j = 0; j < GRID_LENGTH; j++)
        {
            if(j == 2)
            {
                // if it's the last one to the right, it will only print the character without the | at its right
                printf(" %c ", grid[i][j]);
            }else
            {
            printf(" %c |", grid[i][j]);
            }
        }
        if(i == 2)
            break;
        printf("\n___________");
        x++;
    }
    printf("\n\n");
}


// it prints the chosen player
void print_chosen_player(int player_to_choose, char name_player_1[], char name_player_2[])
{
    switch(player_to_choose)
    {
        case 1:
            display_string(name_player_1);
            break;
        case 2:
            display_string(name_player_2);
            break;
    }
}

// it prints a string on the display
void display_string(char player_name[])
{
    int i = 0;
    while(player_name[i] != '\0')
    {
        printf("%c", player_name[i]);
        i++;
    }
}

// it refreshes the matrix to the starting point
void refresh(char grid[][GRID_LENGTH]){
    for(int i = 0; i < GRID_LENGTH; i++)
    {
        for(int j = 0; j < GRID_LENGTH; j++)
        {
            grid[i][j] = '-';
        }
    }
}

// used to check if the chosen position in the grid is occupied
bool check_if_occupied(char grid[][GRID_LENGTH], int row, int column){
    if(grid[row][column] == 'X' || grid[row][column] == 'O'){
        return false;
    }
    return true;
}
