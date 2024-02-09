#include "hpacman.h"

void loading(char map[][85], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == 124 || map[i][j] == -38 || map[i][j] == '-' || map[i][j] == -77 || map[i][j] == '_' || map[i][j] == -64 || map[i][j] == -39 || map[i][j] == -65 || map[i][j] == -63 || map[i][j] == -62)
            {
                sc(136);
                printf("%c", map[i][j]);
            }
            else if (map[i][j] == -83)
            {
                sc(136);
                printf("-");
            }
            else if (map[i][j] == -8)
            {
                sc(14);
                printf("%c", map[i][j]);
            }
            else if (map[i][j+2] == 'G' || map[i][j-2] == 'G')
            {
                sc(7);
                printf("|");
            }
            else if (map[i+1][j-1] == 'G' || map[i+1][j+1] == 'G')
            {
                sc(7);
                printf(".");
            }
            else if (map[i+1][j] == 'G')
            {
                printf("-");
            }
            else if (map[i][j-1] == 'G' || map[i][j+1] == 'G')
            {
                sc(7);
                char aux = 169;
                printf("%c", aux);
            }
            else if (map[i][j] == 'G')
            {
                printf(" ");
            }
            else if (map[i-1][j+2] == 'G' || map[i-1][j-2] == 'G')
            {
                sc(7);
                printf("'");
            }
            else if (map[i-1][j-1] == 'G' || map[i-1][j] == 'G' || map[i-1][j+1] == 'G')
            {
                printf("~");
            }
            else if (map[i][j] == 'P' || map[i+1][j] == 'P')
            {
                sc(4);
                printf("-");
            }
            else if (map[i+1][j+1] == 'P' || map[i+1][j-1] == 'P')
            {
                sc(4);
                printf(".");
            }
            else if (map[i][j-1] == 'P' || map[i][j+1] == 'P')
            {
                sc(4);
                printf("'");
            }
            else if (map[i+1][j-2] == '@' || map[i+1][j+2] == '@' || map[i][j] == '@')
            {
                sc(5);
                printf(".");
            }
            else if (map[i+1][j-1] == '@' || map[i+1][j+1] == '@')
            {
                sc(5);
                printf("^");
            }
            else if (map[i+1][j] == '@' || map[i-1][j-1] == '@' || map[i-1][j] == '@' || map[i-1][j+1] == '@')
            {
                sc(5);
                printf("-");
            }
            else if (map[i][j-2] == '@' || map[i][j+2] == '@')
            {
                sc(5);
                printf("|");
            }
            else if (map[i-1][j-2] == '@' || map[i-1][j+2] == '@')
            {
                sc(5);
                printf("'");
            }
            else if (map[i][j-1] == '@' || map[i][j+1] == '@')
            {
                char aux = 223;
                printf("%c", aux);
            }
            else
            {
                sc(7);
                printf("%c", map[i][j]);
            }
            sc(7);
        }
        printf("\n");
    }
    sc(7);
}

void sc(int color_code)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_code );
}

void load_2(char map[][90], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
                        if (map[i][j] == 124 || map[i][j] == -38 || map[i][j] == '-' || map[i][j] == -77 || map[i][j] == '_' || map[i][j] == -64 || map[i][j] == -39 || map[i][j] == -65 || map[i][j] == -63 || map[i][j] == -62)
            {
                sc(136);
                printf("%c", map[i][j]);
            }
            else if (map[i][j] == -83)
            {
                sc(136);
                printf("-");
            }
            else if (map[i][j] == -8)
            {
                sc(14);
                printf("%c", map[i][j]);
            }
            else if (map[i][j+2] == 'G' || map[i][j-2] == 'G')
            {
                sc(7);
                printf("|");
            }
            else if (map[i+1][j-1] == 'G' || map[i+1][j+1] == 'G')
            {
                sc(7);
                printf(".");
            }
            else if (map[i+1][j] == 'G')
            {
                printf("-");
            }
            else if (map[i][j-1] == 'G' || map[i][j+1] == 'G')
            {
                sc(7);
                char aux = 169;
                printf("%c", aux);
            }
            else if (map[i][j] == 'G')
            {
                printf(" ");
            }
            else if (map[i-1][j+2] == 'G' || map[i-1][j-2] == 'G')
            {
                sc(7);
                printf("'");
            }
            else if (map[i-1][j-1] == 'G' || map[i-1][j] == 'G' || map[i-1][j+1] == 'G')
            {
                printf("~");
            }
            else if (map[i][j] == 'P' || map[i+1][j] == 'P')
            {
                sc(4);
                printf("-");
            }
            else if (map[i+1][j+1] == 'P' || map[i+1][j-1] == 'P')
            {
                sc(4);
                printf(".");
            }
            else if (map[i][j-1] == 'P' || map[i][j+1] == 'P')
            {
                sc(4);
                printf("'");
            }
            else if (map[i+1][j-2] == '@' || map[i+1][j+2] == '@' || map[i][j] == '@')
            {
                sc(5);
                printf(".");
            }
            else if (map[i+1][j-1] == '@' || map[i+1][j+1] == '@')
            {
                sc(5);
                printf("^");
            }
            else if (map[i+1][j] == '@' || map[i-1][j-1] == '@' || map[i-1][j] == '@' || map[i-1][j+1] == '@')
            {
                sc(5);
                printf("-");
            }
            else if (map[i][j-2] == '@' || map[i][j+2] == '@')
            {
                sc(5);
                printf("|");
            }
            else if (map[i-1][j-2] == '@' || map[i-1][j+2] == '@')
            {
                sc(5);
                printf("'");
            }
            else if (map[i][j-1] == '@' || map[i][j+1] == '@')
            {
                char aux = 223;
                printf("%c", aux);
            }
            else
            {
                sc(7);
                printf("%c", map[i][j]);
            }
            sc(7);
        }
        printf("\n");
    }
    sc(7);
}

int filesize ()
{
    int count = 0;
    FILE *fp = fopen("C:\\pacman\\pacman.txt", "rb");
    if (fp == NULL)
    {
        fclose(fp);
        return 0;
    }
    fscanf(fp, "%d", &count);
    fclose (fp);
    return count;
}

void fileper(user **per, int count)
{
    char name[100], ID[100];
    FILE *fp = fopen("C:\\pacman\\pacman.txt", "r");
    fseek(fp, 2, SEEK_SET);
    for (int i = 0; i < count; ++i)
    {
        fscanf(fp, "%s", name);
        strcpy((*per)[i].name, name);
        fscanf(fp, "%s", ID);
        strcpy((*per)[i].ID, ID);
        fscanf(fp, "%d", &(*per)[i].level);
        fscanf(fp, "%d", &(*per)[i].LastPlay);
        fscanf(fp, "%d", &(*per)[i].Isvalid);
        fscanf(fp, "%d", &(*per)[i].SaveFile);
    }
    fclose(fp);
}

void clrscr()
{
    system("@cls||clear");
}

char **restore(char *name, int *type, int *score)
{
    char **map, *name_2;
    int len, n, m;
    len = strlen(name);
    name_2 = (char *) calloc((len + 16), sizeof(char));
    strcpy(name_2, "C:\\pacman\\");
    for (int i = 0; i < len; ++i)
        name_2[10 + i] = name[i];
    name_2[10 + len] = '.';
    name_2[11+len] = 't';
    name_2[12 + len] = 'x';
    name_2[13 + len] = 't';
    FILE *fp = fopen(name_2, "r");
    fseek(fp, 0, SEEK_END);
    int count = ftell(fp);// andaze file ro migirim type ro moshakhas konim
    if (count < 2560)
    {
        n = 20;
        m = 80;
        *type = 1;
    }
    else if (count < 3520)
    {
        n = 32;
        m = 80;
        *type = 2;
    }
    else
    {
        n = 40;
        m = 88;
        *type = 3;
    }
    fseek(fp, 0, SEEK_SET);
    map = (char **) calloc (n, sizeof(char *));
        for (int i = 0; i < n; ++i)
            map[i] = (char *) calloc (m, 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            fscanf(fp, "%c", &map[i][j]);//age ghabla manfi boode bashe bayad + beshe
            if (map[i][j] == 38 || map[i][j] == 39 || map[i][j] == 77 || map[i][j] == 63 || map[i][j] == 65 || map[i][j] == 62 || map[i][j] == 83 || map[i][j] == 8)
                map[i][j] = -map[i][j];
            if (map[i][j] == '@' && i == (n-1))//-64 vaghti + mishe barabar 64 mishe ke hamoon @ hast pas bayad halat bandi beshe
                map[i][j] = -map[i][j];
        }
    fscanf(fp, "%d", &(*score));
    fclose(fp);
    free(name_2);

    return map;
}

void SaveLastPlay(char map[][85], int n, char *name, int score)
{
    char *name_2;
    int len;
    len = strlen(name);
    name_2 = (char *) calloc((len + 18), sizeof(char));
    strcpy(name_2, "C:\\pacman\\");
    for (int i = 0; i < len; ++i)
        name_2[10 + i] = name[i];
    name_2[10 + len] = '.';
    name_2[11+len] = 't';
    name_2[12 + len] = 'x';
    name_2[13 + len] = 't';
    FILE *fp = fopen (name_2, "wb");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 80; ++j)
        {//age manfi bashe bayad + save beshe
            if (map[i][j] == -38 || map[i][j] == -39 || map[i][j] == -77 || map[i][j] == -64 || map[i][j] == -63 || map[i][j] == -65 || map[i][j] == -62 || map[i][j] == -83 || map[i][j] == -8)
                map[i][j] = -map[i][j];
            fprintf(fp, "%c", map[i][j]);
        }
    fprintf(fp, "%d", score);
    fclose(fp);
    free(name_2);
}

void SaveLastPlay_2(char map[][90], int n, char *name, int score)
{
    char *name_2;
    int len;
    len = strlen(name);
    name_2 = (char *) calloc((len + 18), sizeof(char));
    strcpy(name_2, "C:\\pacman\\");
    for (int i = 0; i < len; ++i)
        name_2[10 + i] = name[i];
    name_2[10 + len] = '.';
    name_2[11+len] = 't';
    name_2[12 + len] = 'x';
    name_2[13 + len] = 't';
    FILE *fp = fopen (name_2, "wb");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 88; ++j)
        {//age manfi bashe bayad + save beshae
            if (map[i][j] == -38 || map[i][j] == -39 || map[i][j] == -77 || map[i][j] == -64 || map[i][j] == -63 || map[i][j] == -65 || map[i][j] == -62 || map[i][j] == -83 || map[i][j] == -8)
                map[i][j] = -map[i][j];
            fprintf(fp, "%c", map[i][j]);
        }
    fprintf(fp, "%d", score);
    fclose(fp);
    free(name_2);
}

void SavePlayer(user *per, int count)
{
    int count2 = 0;
    for (int i = 0; i < count; ++i)
        if (per[i].Isvalid)//tedad kasayi ke delete nakardan
            ++count2;
    FILE *fp = fopen("C:\\pacman\\pacman.txt", "w");
    fprintf(fp, "%d\n", count2);
    for (int i = 0; i < count; ++i)
    {
        if (per[i].Isvalid)//age delete nashode print kone
        {
            fprintf(fp, "%s\n", per[i].name);
            fprintf(fp, "%s\n", per[i].ID);
            fprintf(fp, "%d\n", per[i].level);
            fprintf(fp, "%d\n", per[i].LastPlay);
            fprintf(fp, "%d\n", per[i].Isvalid);
            fprintf(fp, "%d\n", per[i].SaveFile);
        }
    }
    fclose(fp);
}
