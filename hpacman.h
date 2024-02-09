#ifndef Hpacman
#define Hpacman

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <direct.h>
#include <string.h>
#include <unistd.h>

typedef struct user
{
    char name[100];
    char ID[100];
    int level;
    int LastPlay;
    int Isvalid;
    int SaveFile;
}user;

void loading(char map[][85], int , int); //printf map A & B
void load_2(char map[][90], int , int); // printf map C
void sc(int color_code); // change color of the therminal
int filesize(); // send the count of the players in txt file
void fileper(user **per, int count); // por kardan (user *per) with the information of the txt file
void clrscr(); // clear screan
char **restore(char *, int *, int *); // bazyabi bazi ghabli
void SaveLastPlay(char map[][85], int, char *, int); // save kardan akharin bazi map A & B
void SaveLastPlay_2(char map[][90], int, char *, int); // hamun function bala baraye map C
void SavePlayer(user *per, int); // save kardan afrad dar file txt
void moveghost(char);


#endif