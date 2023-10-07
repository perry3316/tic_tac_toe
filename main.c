#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define ANSI escape sequences for text formatting
#include "ANSI.h"

// Global variables
int l = 1, i_pos = 0, count = 0;
int g_play = 0, p1_win = 0, p2_win = 0, g_draw = 0;
int pl = 0, m = 0, b[99] = {}, h = 0;
char p1[20], p2[20];
char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char win[99][20], p1_n[99][20], p2_n[99][20];

// Function prototypes
int start();          // Print the game menu on the screen and get user choice
void game();          // Start the game
void g_name();        // Print "TicTacToe" on the screen
void p_name();        // Take player names as input
void design();        // Print the game board pattern
void input_pos();     // Take player position as input
int chk_pos();        // Check the game board for a result
void result();        // Check and display the game result
void final(int);      // Display the final result of the game
void h_scr();         // Hold the screen for user interaction
void g_result();      // Display game statistics and results

int main()
{
    while (1)
    {
        // Clear the screen and set text formatting
        printf(CRH);
        system("clear||cls");

        // Show the game menu and get user choice
        switch (start())
        {
        case 1:
            g_play++;
            game();
            break;
        case 2:
            g_result();
            break;
        case 3:
            printf(CRS);
            system("clear||cls");
            exit(0);
        default:
            printf(B RRED "\n\tInvalid choice" RES);
            h_scr();
        }

        // Reset game variables for a new game
        count = 0;
        l = 1;
        i_pos = 0;
        for (int i = 0; i < 9; i++)
            a[i] = i + 49; // Reset game board
    }
}

int start()
{
    int ch;
    printf(B RGRN "\n\t1. Play TicTacToe");
    printf(RBLU "\n\t2. Game Result");
    printf(RRED "\n\t3. Exit");
    printf(RCYN "\n\tEnter your choice: ");
    scanf("%d", &ch);
    printf(RES);
    return (ch);
}

void game()
{
    char m;
    system("clear||cls");
    g_name();
    p_name();
    system("clear||cls");
    while (l) // Loop will continue until l==1
    {
        g_name();
        design();
        input_pos();
        system("clear||cls");
        g_name();
        design();
        result();
        system("clear||cls");
    }
}

void g_name()
{
    printf("\n\n\t\t\t  " B DU BGRN "TicTacToe" RES "\n");
}

void p_name()
{
    printf(B RBLU "\tEnter Player1 name: ");
    while (getchar() != '\n')
        ; // Clear input buffer
    scanf("%[^\n]", p1);
    strcpy(p1_n[pl], p1); // Copy player1 name
    printf(RMAG "\tEnter Player2 name: ");
    while (getchar() != '\n')
        ;
    scanf("%[^\n]", p2);
    strcpy(p2_n[pl], p2); // Copy player2 name
    pl++;
    printf(RES);
}

void design()
{
    printf("\n");
    puts(B RBBLU RYLO "\t\t\t|---|---|---|");
    printf("\t\t\t| " YLO "%c" RES B RBBLU RYLO " | " YLO "%c" RES B RBBLU RYLO " | " YLO "%c" RES B RBBLU RYLO " |\n", a[0], a[1], a[2]);
    puts("\t\t\t|---|---|---|");
    printf("\t\t\t| " YLO "%c" RES B RBBLU RYLO " | " YLO "%c" RES B RBBLU RYLO " | " YLO "%c" RES B RBBLU RYLO " |\n", a[3], a[4], a[5]);
    puts("\t\t\t|---|---|---|");
    printf("\t\t\t| " YLO "%c" RES B RBBLU RYLO " | " YLO "%c" RES B RBBLU RYLO " | " YLO "%c" RES B RBBLU RYLO " |\n", a[6], a[7], a[8]);
    puts("\t\t\t|---|---|---|" RES);
}

void input_pos()
{
    char ch;
    int pos, i, flag1 = 0;
    printf(B);
    if (i_pos == 0)
    {
        do
        {
            if (flag1 == 1)
                printf(RRED "\n\tWrong Input!");

            printf(RBLU "\n\t%s Enter your position: ", p1); // Take position input from player 1
            scanf("%d", &pos);
            ch = 48 + (char)pos;
            if (ch == '0' || ch == 'x')
                flag1 = 1;
            else
            {
                flag1 = 1;
                for (i = 0; i < 9; i++)
                {
                    if (a[i] == ch)
                    {
                        a[i] = 'x';
                        flag1 = 0;
                        break;
                    }
                }
            }
        } while (flag1 != 0);
        i_pos = 1;
    }
    else
    {
        do
        {
            if (flag1 == 1)
                printf(RRED "\n\tWrong Input!");
            printf(RMAG "\n\t%s Enter your position: ", p2); // Take position input from player 2
            scanf("%d", &pos);
            ch = 48 + (char)pos;
            if (ch == '0' || ch == 'x')
                flag1 = 1;
            else
            {
                flag1 = 1;
                for (i = 0; i < 9; i++)
                {
                    if (a[i] == ch)
                    {
                        a[i] = '0';
                        flag1 = 0;
                        break;
                    }
                }
            }
        } while (flag1 != 0);
        i_pos = 0;
    }
    count++;
    printf(RES);
}

int chk_pos()
{
    if ((a[0] == 'x' && a[1] == 'x' && a[2] == 'x') || (a[0] == 'x' && a[3] == 'x' && a[6] == 'x') || (a[0] == 'x' && a[4] == 'x' && a[8] == 'x'))
        return (0);
    else if ((a[0] == '0' && a[1] == '0' && a[2] == '0') || (a[0] == '0' && a[3] == '0' && a[6] == '0') || (a[0] == '0' && a[4] == '0' && a[8] == '0'))
        return (1);
    else if (a[1] == 'x' && a[4] == 'x' && a[7] == 'x')
        return (0);
    else if (a[1] == '0' && a[4] == '0' && a[7] == '0')
        return (1);
    else if ((a[2] == 'x' && a[5] == 'x' && a[8] == 'x') || (a[2] == 'x' && a[4] == 'x' && a[6] == 'x'))
        return (0);
    else if ((a[2] == '0' && a[5] == '0' && a[8] == '0') || (a[2] == '0' && a[4] == '0' && a[6] == '0'))
        return (1);
    else if (a[3] == 'x' && a[4] == 'x' && a[5] == 'x')
        return (0);
    else if (a[3] == '0' && a[4] == '0' && a[5] == '0')
        return (1);
    else if (a[6] == 'x' && a[7] == 'x' && a[8] == 'x')
        return (0);
    else if (a[6] == '0' && a[7] == '0' && a[8] == '0')
        return (1);
    else
        return (2);
}

void result()
{
    int r = chk_pos();
    if (count < 9)
    {
        if (r == 2)
            ; // Continue the game
        else
            final(r); // Display the game result
    }
    else
        final(r);
}

void final(int r)
{
    if (r == 0)
    {
        printf(B RBLU "\n\t%s Win\n" RES, p1);
        strcpy(win[m], p1); // Copy the winner's name
        p1_win++;
    }
    else if (r == 1)
    {
        printf(B RMAG "\n\t%s Win\n" RES, p2);
        strcpy(win[m], p2);
        p2_win++;
    }
    else
    {
        printf(B RRED "\n\tGame Draw\n");
        g_draw++;
    }
    if (r == 1 || r == 0)
        b[m] = 1;
    else
        b[m] = 0;
    m++;
    h_scr();
}

void h_scr()
{
    l = 0;
    printf(B BL YLO "\n\tPress Enter to continue..." RES);
    while (getchar() != '\n')
        ;
    getchar();
}

void g_result()
{
    system("clear||cls");
    printf(DU B RV RCYN "\n\t\t\tResult Sheet" RES);
    printf(I B U GRN "\n\tGame played: %d" RES, g_play);
    printf(B RBLU "\n\tx Win: %d" RES B RMAG "\t 0 Win: %d" RES B RRED "\t Game Draw: %d\n" RES, p1_win, p2_win, g_draw);
    for (int i = 0; i < g_play; i++)
    {
        printf(B "\n\tGame %d", i + 1);
        printf(RBLU "\n\tPlayer1: %s\t" RMAG " Player2: %s", p1_n[i], p2_n[i]);
        if (b[i] == 1)
            printf(RYLO "\n\tWinner: %s\n", win[i]);
        else
            printf(B RRED "\n\tGame Draw\n");
        printf(RES);
    }
    h_scr();
}
