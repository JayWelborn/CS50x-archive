/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to dim x dim).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be dim x dim,
 * where dim must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define BLANK 0

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int dim;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    dim = atoi(argv[1]);
    if (dim < DIM_MIN || dim > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < dim - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\x1b[31m \nIllegal move.\x1b[0m\n");
            usleep(1000000);
        }

        // sleep thread for animation's sake
        usleep(1000000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through dim*dim - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // Fill array with integers
    int count = 1;
    for (int y = 0; y < DIM_MAX; y++)
    {
        for (int x = 0; x < DIM_MAX; x++)
        {
            if (x < dim && y < dim)
            {
                board[y][x] = dim * dim - count;
                count += 1;
            }
            else
            {
                board[y][x] = 99;
            }
        }
        
    }
    if (dim % 2 == 0)
    {
        board[dim - 1][dim - 2] = 2;
        board[dim - 1][dim - 3] = 1;
    }
    
    board[dim - 1][dim - 1] = BLANK;
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int y = 0, x = 0;
    for (y = 0; y < dim; y++)
    {
        printf("\n");
        for (x = 0; x < dim; x++)
        {
            int current = board[y][x];
            if (current > 0 && current != BLANK)
            {
                printf("\x1b[33m %d  \x1b[0m", current);
            }
            else if (current == BLANK)
            {
                printf("\x1b[36m ◼  \x1b[0m");
            }
            
            if (board[y][x] < 10 || board[y][x] == BLANK)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // Loop searches for tile value in array
    int x, y, alpha, beta;
    bool stop = false;
    for (y = 0; y < dim && stop == false; y++)
    {
        for (x = 0; x < dim; x++)
        {
            if (tile == board[y][x])
            {
                stop = true;
                alpha = x;
                beta = y;
                break;
            }
        }
    }
    
    // Tests adjacent positions and swaps with blank
    if (board[beta][alpha + 1] == BLANK)
    {
        board[beta][alpha] = BLANK;
        board[beta][alpha + 1] = tile;
        return true;
    }
    
    else if (board[beta + 1][alpha] == BLANK)
    {
        board[beta][alpha] = BLANK;
        board[beta + 1][alpha] = tile;
        return true;
    }
    
    else if (board[beta - 1][alpha] == BLANK && beta - 1 >= 0)
    {
        board[beta][alpha] = BLANK;
        board[beta - 1][alpha] = tile;
        return true;
    }
    
    else if (board[beta][alpha - 1] == BLANK && alpha - 1 >= 0)
    {
        board[beta][alpha] = BLANK;
        board[beta][alpha - 1] = tile;
        return true;
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // Makes 1-d array for checking purposes
    int x, y, count, array[dim * dim], size;
    count = 0;
    size = dim * dim;
    
    for (y = 0; y < dim; y++)
    {
        for(x = 0; x < dim; x++)
        {
            array[count] = board[y][x];
            count += 1;
        }
    }
    
    // Checks to see if array is sorted
    count = 0;
    for (x = 0; x < size - 2; x++)
    {
        if (array[x] < array[x + 1] && array[0] != 0)
        {
            count += 1;
            if (count == size - 2)
            {
                return true;
            }
        }
    }
    return false;
}