/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
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

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// null position
int nul_p[2]

// prototypes
void clear(void);
void greet(void);
void init(int d);
void draw(int int_to_display, bool nl);
bool move(int tile);
bool won(int sequence[], int max_num);
int abs(int n);

int main(int argc, string argv[])
{
    int ntd;

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    int brd[d][d];
    int const max_num = d * d - 1;
    int count = max_num;
    int temp;
    int nul_p[2] = {d - 1, d - 1};
    int position[d * d];
    int won_count = 0;

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board

    for (int x = 0; x < d; ++x) {
      for (int y = 0; y < d; ++y) {

          brd[x][y] = count;
          --count;
      }
    }

    //swap 1 and 2 for even
    if ((d % 2) == 0)
    {
      temp = brd[d-1][d-2];
      brd[d-1][d-2] = brd[d-1][d-3];
      brd[d-1][d-3] = temp;
    }
    init(d);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        for (int x = 0; x < d; ++x) {

          bool nl = true;

          for (int y = 0; y < d; ++y) {

            ntd = brd[x][y];
            draw(ntd, nl);
            nl = false;

          }
        }

        printf("\n\n");

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        for (int x = 0; x < d; ++x)
          for (int y = 0; y < d; ++y, ++won_count)
            position[won_count] = brd[x][y];

        if (won(position, max_num))
        {
            printf("ftw!\n");
            break;
        }

        won_count = 0;

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // // quit if user inputs 0 (for testing)
        // if (tile == 0)
        // {
        //     break;
        // }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(100000);
        }
        else
        {
          bool found = false;
          for (int x = 0; x < d && !found; ++x)
            for (int y = 0; y < d && !found; ++y)
              {
                if (brd[x][y] == tile)
                {
                  found = true;
                  if ( ( x == nul_p[0] && abs( y - nul_p[1] ) == 1 ) ||
                    ( y == nul_p[1] && abs( x - nul_p[0] ) == 1 ) )
                  {
                    brd[nul_p[0]][nul_p[1]] = brd[x][y];
                    brd[x][y] = 0;
                    nul_p[0] = x;
                    nul_p[1] = y;
                    usleep(100000);
                  }
                  else
                  {
                    printf("\nIllegal move.\n");
                    usleep(100000);
                  }
                  break;
                }
            }
        }


        // sleep thread for animation's sake
        usleep(100000);
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
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(int d)
{

}

/**
 * Prints the board in its current state.
 // */
void draw(int int_to_display, bool nl)
{

  if (nl)
    printf("\n");

  if (int_to_display == 0)
    printf(" _ ");
  else
    printf("%2.i ", int_to_display);
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    if (tile > d * d - 1 || tile < 1)
      return false;

    return true;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(int sequence[], int max_num)
{
    for (int i = 1; i <= max_num; ++i)
      if (i != sequence[i - 1])
        return false;

    return true;
}

int abs(n)
{
  if (n < 0)
    n *= -1;
  return n;
}
