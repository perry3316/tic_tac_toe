#include "header.h"
int start();      //print game menu on screen
void game();      //call function for game
void g_name();    //print tictactoe on screen
void p_name();    //take player name as input
void design();    //print pattren of game
void input_pos(); //take position as input
int chk_pos();    //check pattern for result
void result();    //check result
void final(int);  //print result
void h_scr();     //hold screen
void g_result();  //check result
int l = 1, i_pos = 0, count = 0;
int g_play = 0, p1_win = 0, p2_win = 0, g_draw = 0;
int pl = 0, m = 0, b[99] = {}, h = 0;
char p1[20], p2[20];
char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char win[50][10], p1_n[50][10], p2_n[50][10];
int main()
{
    while (1)

        
        case 2:
            printf(CRS);
            system("clear||cls");
            exit(0);
         case 3:
            g_result();
            break;
        default:
            printf(B RRED "\n\tInvalid choice" RES);
            h_scr();
        }
        count = 0;
        l = 1;
    {
        printf(CRH);
        system("clear||cls");
        switch (start())
        {
        case 1:
            g_play++;
            game();
            break;
        i_pos = 0;
        for (int i = 0; i < 9; i++)
            a[i] = i + 49;
    }
}
// #include "game.c"
