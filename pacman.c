#include "hpacman.h"




int main(){

    char map_type, name[100], ID[100];
    int indexOfPer, Sighn, count;
    user *per;

    //map A
    char map_A[25][85], dash = '_', corner_A = 218, corner_B = 191, corner_C = 192, corner_D = 217, deg = 248, wall = 173, space = ' ', roof = '-';
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 80; ++j)
            map_A[i][j] = space;
    for (int i = 1; i < 79; ++i)
    {
        map_A[0][i] = roof;
        map_A[19][i] = roof;
    }
    for (int i = 1; i < 19; ++i)
    {
        map_A[i][0] = wall;
        map_A[i][79] = wall;
    }
    //corners
    map_A[0][0] = corner_A;
    map_A[0][79] = corner_B;
    map_A[19][0] = corner_C;
    map_A[19][79] = corner_D;
    //points
    for (int i = 4; i < 20; i += 5)
        for (int j = 8; j < 79; j += 9)
            if (i != 19)
                map_A[i][j] = deg;
    //end corners
    map_A[0][37] = 194;
    for (int i = 1; i < 10; ++i)
        map_A[i][37] = 179;
    //end of wall miani
    //kafe map
    for (int j = 58; j < 68; ++j)
    {
        map_A[4][j] = dash;
        map_A[14][j] = dash;
    }
    //roads
    for (int j = 25; j < 37; ++j)
        map_A[9][j] = dash;
    map_A[4][62] = dash;
    map_A[4][35] = space;
    map_A[9][62] = 'P';
    map_A[9][53] = '@';
    map_A[14][17] = 'G';
    //end of map A
        //map c start
    char map_C[45][90];
    for (int i = 0; i < 40; ++i)
        for (int j = 0; j < 88; ++j)
            map_C[i][j] = space;
    for (int i = 1; i < 39; ++i)
        map_C[i][0] = map_C[i][87] = wall;
    for (int j = 1; j < 87; ++j)
        map_C[0][j] = map_C[39][j] = roof;
    map_C[0][0] = corner_A;
    map_C[0][87] = corner_B;
    map_C[39][0] = corner_C;
    map_C[39][87] = corner_D;
    //emtiaz
    for (int i = 2; i < 39; i += 5)
        for (int j = 8; j < 87; j += 9)
            map_C[i][j] = deg;
    //divar ha
    for (int i = 35; i < 39; ++i)
        map_C[i][35] = '|';
    map_C[39][35] = 193;
    for (int i = 1; i < 8; ++i)
        map_C[i][35] = '|';
    map_C[0][35] = 194;
    for (int j = 23; j < 35; ++j)
        map_C[7][j] = dash;
    for (int i = 5; i < 13; ++i)
        map_C[i][53] = '|';
    for (int j = 23; j < 31; ++j)
        map_C[12][j] = dash;
    for (int i = 13; i < 19; ++i)
        map_C[i][26] = '|';
    for (int j = 54; j < 65; ++j)
        map_C[12][j] = dash;
    for (int j = 59; j < 66; ++j)
        map_C[2][j] = dash;
    for (int j = 72; j < 87; ++j)
        map_C[22][j] = dash;
    for (int i = 23; i < 30; ++i)
        map_C[i][71] = '|';
    map_C[22][71] = space;
    map_C[2][8] = map_C[32][53] = 'G';
    map_C[32][8] = '@';
    map_C[2][44] = map_C[7][62] = map_C[27][80] = 'P';
    //endof map C
    //map b
    char map_B[35][85];

    for (int i = 1; i < 31; ++i)
        for (int j = 1; j < 79; ++j)
            map_B[i][j] = space;
    for (int j = 1; j < 79; ++ j)
    {
        map_B[0][j] = roof;
        map_B[31][j] = roof;
    }
    for (int i = 1; i < 31; ++i)
    {
        map_B[i][0] = wall;
        map_B[i][79]= wall;
    }
    map_B[0][0] = corner_A;
    map_B[0][79] = corner_B;
    map_B[31][0] = corner_C;
    map_B[31][79] = corner_D;
    //main map
    //start of line haye vasat

    
    for (int i = 4; i < 31; i += 5)
        for (int j = 8; j < 79; j += 9)
            map_B[i][j] = deg;
    for (int i = 1; i < 10; ++i)
        map_B[i][35] = 179;
    for (int j = 36; j < 47; ++j)
        map_B[9][j] = dash;
    for (int j = 1; j < 15; ++j)
        map_B[19][j] = dash;
    for (int j = 58; j < 67; ++j)
        map_B[23][j] = dash;
    for (int i = 28; i < 31; ++i)
        map_B[i][35] = 179;
    map_B[0][35] = 194;
    map_B[31][35] = 193;
    map_B[24][62] = space;
    map_B[24][35] = '@';
    map_B[4][44] = map_B[29][8] = 'P';
    map_B[14][8] = map_B[14][62] = 'G';
    //end of map b

    //start of get information
    while (1)
    {
        char smile = 1;
        count = filesize(); // count of players in list
        if (!count)
            per = (user *) calloc (10, sizeof(user));
        else
        {
            per = (user *) calloc ((count + 2), sizeof(user)); // get the players of the list and their information
            fileper(&per, count);
        }
        printf("Wellcome %c!\nWanna play? Press 2 to sighn up!\nAlready have an account? Press 1 to log in\nEnter -1 to exit\n", smile);
        scanf(" \n%d", &Sighn);
        if (Sighn == -1)
            break;
        if (Sighn == 2)
        {
            indexOfPer = count;
            printf("Enter your name: ");
            scanf("%s", name);
            strcpy(per[indexOfPer].name, name);
            while(1)
            {
                int flag = 0;
                printf("Enter your ID: ");
                scanf("%s", ID);
                for (int i = 0; i < indexOfPer; ++i)
                    if (per[i].Isvalid && !(strcmp(ID, per[i].ID)))
                    {
                        printf("Your ID is unavailable!\n"); // age ghabla in ID vojod dashte bayad eror bede
                        flag = 1;
                    }
                if (!flag)
                    break;
            }
            ++count;
            strcpy(per[indexOfPer].ID, ID);
            per[indexOfPer].SaveFile = 0;
            per[indexOfPer].Isvalid = 1;
            sleep(5);
            clrscr();
            printf("\nLogged in sccessfully!!");
            sleep(5);
            clrscr();
            printf("Loading");
            sleep(3);
            printf(" .");
            sleep(3);
            printf(" .");
            sleep(3);
            printf(" .");
            sleep(5);
        }
        if (Sighn == 1)
        {
            int flag = 0;
            while(1)
            {
                printf("Enter your name and ID: ");
                scanf("%s", name);
                scanf(" \n%s", ID);
                for (int i = 0; i < count; ++i)
                    if (!(strcmp(name, per[i].name)) && !(strcmp(ID, per[i].ID)) && per[i].Isvalid)// bayad check kone ID & name hamkhani dashte bashan
                    {
                        flag = 1;
                        indexOfPer = i;
                        clrscr();
                        printf("\nLogged in sccessfully!!");
                        sleep(5);
                        clrscr();
                        printf("Loading");
                        sleep(3);
                        printf(" .");
                        sleep(3);
                        printf(" .");
                        sleep(3);
                        printf(" .");
                        sleep(5);
                        break;
                    }
                if (flag)
                    break;
                printf("Your name or ID is not correct!\nTry again.\n");
            }
        }
        //end of get information


        

        int i, j, i_1, i_2, j_1, j_2, score=0, ip, jp;
        char map_Aaux[25][85], map_Baux[35][85], map_Caux[45][90]; // map haye komaki ke azashon estefade mishe
        while (1)
        {
            int Sighn_2;
            clrscr();
            printf("Hi %s %c\t%s %d\n", name, smile, ID, per[indexOfPer].level);
            printf("Enter 1 to play.\nEnter 2 to log out.\nEnter 3 to delete your account.\n");
            scanf(" \n%d", &Sighn_2);
            if (Sighn_2 == 2)
            {
                SavePlayer(per, count);
                clrscr();
                break;
            }
            if (Sighn_2 == 3)
            {
                per[indexOfPer].Isvalid = 0;
                SavePlayer(per, count);
                clrscr();
                break;
            }
            char YesNo;
            int flag = 0, flagWin = 0;

            if (per[indexOfPer].SaveFile) // age ghabla bazi natamom dashte miad inja
            {
                per[indexOfPer].SaveFile = 0;
                int type;
                char **mapaux = restore(ID, &type, &score);
                if (type == 1)
                {
                    map_type = 'A';
                    for (int n = 0; n < 20; ++n)
                        for (int m = 0; m < 80; ++m)
                        {
                            map_Aaux[n][m] = mapaux[n][m];//gharar dadan naghshe file dar map haye komaki
                            if (map_Aaux[n][m] == 'G') //mokhtasate ghost
                            {
                                i = n;
                                j = m;
                            }
                            if (map_Aaux[n][m] == '@')//mokhtasate pacman
                            {
                                ip = n;
                                jp = m;
                            }
                        }
                }
                else if (type == 2)
                {
                    int con = 0;
                    map_type = 'B';
                    for (int n = 0; n < 32; ++n)
                        for (int m = 0; m < 80; ++m)
                        {
                            map_Baux[n][m] = mapaux[n][m];
                            if (map_Baux[n][m] == 'G' && !con)//mokhtasate ghoste 1
                            {
                                ++con;
                                i_1 = n;
                                j_1 = m;
                            }
                            if (map_Baux[n][m] == 'G')//mokhtasate ghoste 2
                            {
                                i_2 = n;
                                j_2 = m;
                            }
                            if (map_Baux[n][m] == '@')
                            {
                                ip = n;
                                jp = m;
                            }
                        }
                }
                else
                {
                    int con = 0;
                    map_type = 'C';
                    for (int n = 0; n < 40; ++n)
                        for (int m = 0; m < 88; ++m)
                        {
                            map_Caux[n][m] = mapaux[n][m];
                            if (map_Caux[n][m] == 'G' && !con)
                            {
                                ++con;
                                i_1 = n;
                                j_1 = m;
                            }
                            if (map_Caux[n][m] == 'G')
                            {
                                i_2 = n;
                                j_2 = m;
                            }
                            if (map_Caux[n][m] == '@')
                            {
                                ip = n;
                                jp = m;
                            }
                        }
                }
                flag = 1;
            }
                while(1)
                {
                    if (!flag)
                    {
                        score = 0;
                        flagWin = 0;
                        printf("Please enter:\nA. Easy\nB. Medium\nC. Hard\n\n");
                        scanf(" \n\n%c", &map_type);
                        if (map_type == 'A')
                        {
                            clrscr();
                            printf("Loading . . .");
                            sleep(4);
                            clrscr();
                            for(int k = 0; k < 20; ++k)
                                for (int z = 0; z < 80; ++z)
                                    map_Aaux[k][z] = map_A[k][z];
                            i = 14;
                            j = 17;
                            ip = 9;
                            jp = 53;
                        }
                        else if (map_type == 'B')
                        {
                            clrscr();
                            printf("Loading . . .");
                            sleep(4);
                            clrscr();
                            for(int k = 0; k < 32; ++k)
                                for (int z = 0; z < 80; ++z)
                                    map_Baux[k][z] = map_B[k][z];
                            i_1 = 14;
                            i_2 = 14;
                            j_1 = 8;
                            j_2 = 62;
                            ip = 24;
                            jp = 35;
                        }
                        else if (map_type == 'C')
                        {
                            clrscr();
                            printf("Loading . . .");
                            sleep(4);
                            clrscr();
                            for(int k = 0; k < 40; ++k)
                                for (int z = 0; z < 88; ++z)
                                    map_Caux[k][z] = map_C[k][z];
                            i_1 = 2;
                            j_1 = 8;
                            i_2 = 32;
                            j_2 = 53;
                            ip = 32;
                            jp = 8;
                        }
                        flag = 1;
                    }
                    clrscr();
                    printf("%s\n", per[indexOfPer].name);
                    printf("Score : %d\n", score);
                    if (map_type == 'A')
                        loading(map_Aaux, 20, 80);
                    else if (map_type == 'B')
                        loading(map_Baux, 32, 80);
                    else if (map_type == 'C')
                        load_2(map_Caux, 40, 88);
                    sc(7);
                    printf("(u, d, r, l)\nPress <Esc> to exit!");
                    char key = getch();
                    if (key == 27)
                    {
                        printf("\nAre you sure you wanna leave? (Y/N)\n");
                        scanf(" \n%c", &YesNo);
                        per[indexOfPer].LastPlay = 1;
                        sleep(2);
                        clrscr();
                        if (YesNo == 'Y')
                            break;
                        else
                            continue;
                    }
                    else if (key == 117) // up arrow
                    {
                        if (map_type == 'A')
                            if (ip != 4)
                            {
                                if (map_Aaux[ip-5][jp] == -8)//age khalie harekat kone
                                {
                                    char temp = map_Aaux[ip][jp];
                                    map_Aaux[ip][jp] = map_Aaux[ip-5][jp];
                                    map_Aaux[ip-5][jp] = temp;
                                    ip -= 5;
                                }
                                else if (map_Aaux[ip-5][jp] == 'P')//age mive bebare
                                {
                                    ++score;
                                    flagWin = 1;
                                    per[indexOfPer].level += 3;
                                    sleep(2);
                                    clrscr();
                                    printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    if (YesNo == 'Y')
                                        break;
                                    flag = 0;
                                    continue;
                                }
                                else if (map_Aaux[ip-5][jp] == 'G')//age ghost bebaze
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 20; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Aaux[k][z] = map_A[k][z];
                                        i = 14;
                                        j = 17;
                                        ip = 9;
                                        jp = 53;
                                        continue;
                                    }
                                }   
                            }
                        if (map_type == 'B')
                            if (ip != 4)
                            {
                                if (map_Baux[ip-5][jp] == -8)
                                {
                                    char temp = map_Baux[ip][jp];
                                    map_Baux[ip][jp] = map_Baux[ip-5][jp];
                                    map_Baux[ip-5][jp] = temp;
                                    ip -= 5;
                                }
                                else if (map_Baux[ip-5][jp] == 'P')
                                {
                                    ++score;
                                    if (score == 1)
                                    {
                                        map_Baux[ip-5][jp] = map_Baux[ip][jp];
                                        map_Baux[ip][jp] = deg;
                                        ip -= 5;
                                    }
                                    if (score == 2)
                                    {
                                        flagWin = 1;
                                        per[indexOfPer].level += 3;
                                        sleep(2);
                                        clrscr();
                                        printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                        scanf(" \n%c", &YesNo);
                                        if (YesNo == 'Y')
                                            break;
                                        flag = 0;
                                        continue;
                                    }
                                }
                                else if (map_Baux[ip-5][jp] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'C')
                            if (ip != 2)
                            {
                                if (map_Caux[ip-5][jp] == -8)
                                {
                                    char temp = map_Caux[ip][jp];
                                    map_Caux[ip][jp] = map_Caux[ip-5][jp];
                                    map_Caux[ip-5][jp] = temp;
                                    ip -= 5;
                                }
                                else if (map_Caux[ip-5][jp] == 'P')
                                {
                                    ++score;
                                    if (score == 1 || score == 2)
                                    {
                                        map_Caux[ip-5][jp] = map_Caux[ip][jp];
                                        map_Caux[ip][jp] = deg;
                                        ip -= 5;
                                    }
                                    if (score == 3)
                                    {
                                        flagWin = 1;
                                        per[indexOfPer].level += 3;
                                        sleep(2);
                                        clrscr();
                                        printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                        scanf(" \n%c", &YesNo);
                                        if (YesNo == 'Y')
                                            break;
                                        flag = 0;
                                        continue;
                                    }
                                }
                                else if (map_Caux[ip-5][jp] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }                
                    }
                    else if (key == 100) // down arrow
                    {
                        if (map_type == 'A')
                            if (ip != 14)
                            {
                                if (map_Aaux[ip+5][jp] == -8)
                                {
                                    char temp = map_Aaux[ip][jp];
                                    map_Aaux[ip][jp] = map_Aaux[ip+5][jp];
                                    map_Aaux[ip+5][jp] = temp;
                                    ip += 5;
                                }
                                else if (map_Aaux[ip+5][jp] == 'P')
                                {
                                    ++score;
                                    flagWin = 1;
                                    per[indexOfPer].level += 3;
                                    sleep(2);
                                    clrscr();
                                    printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    if (YesNo == 'Y')
                                        break;
                                    flag = 0;
                                    continue;
                                }
                                else if (map_Aaux[ip+5][jp] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 20; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Aaux[k][z] = map_A[k][z];
                                        i = 14;
                                        j = 17;
                                        ip = 9;
                                        jp = 53;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'B')
                            if (ip != 29)
                            {
                                if (map_Baux[ip+5][jp] == -8)
                                {
                                    char temp = map_Baux[ip][jp];
                                    map_Baux[ip][jp] = map_Baux[ip+5][jp];
                                    map_Baux[ip+5][jp] = temp;
                                    ip += 5;
                                }
                                else if (map_Baux[ip+5][jp] == 'P')
                                {
                                    ++score;
                                    if (score == 1)
                                    {
                                        map_Baux[ip+5][jp] = map_Baux[ip][jp];
                                        map_Baux[ip][jp] = deg;
                                        ip += 5;
                                    }
                                    if (score == 2)
                                    {
                                        flagWin = 1;
                                        per[indexOfPer].level += 3;
                                        sleep(2);
                                        clrscr();
                                        printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                        scanf(" \n%c", &YesNo);
                                        if (YesNo == 'Y')
                                            break;
                                        flag = 0;
                                        continue;
                                    }
                                }
                                else if (map_Baux[ip+5][jp] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'C')
                            if (ip != 37)
                            {
                                if (map_Caux[ip+5][jp] == -8)
                                {
                                    char temp = map_Caux[ip][jp];
                                    map_Caux[ip][jp] = map_Caux[ip+5][jp];
                                    map_Caux[ip+5][jp] = temp;
                                    ip += 5;
                                }
                                else if (map_Caux[ip+5][jp] == 'P')
                                {
                                    ++score;
                                    if (score == 1 || score == 2)
                                    {
                                        map_Caux[ip+5][jp] = map_Caux[ip][jp];
                                        map_Caux[ip][jp] = deg;
                                        ip += 5;
                                    }
                                    if (score == 3)
                                    {
                                        flagWin = 1;
                                        per[indexOfPer].level += 3;
                                        sleep(2);
                                        clrscr();
                                        printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                        scanf(" \n%c", &YesNo);
                                        if (YesNo == 'Y')
                                            break;
                                        flag = 0;
                                        continue;
                                    }
                                }
                                else if (map_Caux[ip+5][jp] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }
                    }
                    else if (key == 108) // left arrow
                    {
                        if (map_type == 'A')
                            if (jp != 8)
                            {
                                if(map_Aaux[ip][jp-9] == -8)
                                {
                                    char temp = map_Aaux[ip][jp];
                                    map_Aaux[ip][jp] = map_Aaux[ip][jp-9];
                                    map_Aaux[ip][jp-9] = temp;
                                    jp -= 9;
                                }
                                else if (map_Aaux[ip][jp-9] == 'P')
                                {
                                    ++score;
                                    flagWin = 1;
                                    per[indexOfPer].level += 3;
                                    sleep(2);
                                    clrscr();
                                    printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    if (YesNo == 'Y')
                                        break;
                                    flag = 0;
                                    continue;
                                }
                                else if (map_Aaux[ip][jp-9] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 20; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Aaux[k][z] = map_A[k][z];
                                        i = 14;
                                        j = 17;
                                        ip = 9;
                                        jp = 53;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'B')
                            if (jp != 8)
                            {
                                if(map_Baux[ip][jp-9] == -8)
                                {
                                    char temp = map_Baux[ip][jp];
                                    map_Baux[ip][jp] = map_Baux[ip][jp-9];
                                    map_Baux[ip][jp-9] = temp;
                                    jp -= 9;
                                }
                                else if (map_Baux[ip][jp-9] == 'P')
                                {
                                    ++score;
                                    if (score == 1)
                                    {
                                        map_Baux[ip][jp-9] = map_Baux[ip][jp];
                                        map_Baux[ip][jp] = deg;
                                        jp -= 9;
                                    }
                                    if (score == 2)
                                    {
                                        flagWin = 1;
                                        per[indexOfPer].level += 3;
                                        sleep(2);
                                        clrscr();
                                        printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                        scanf(" \n%c", &YesNo);
                                        if (YesNo == 'Y')
                                            break;
                                        flag = 0;
                                        continue;
                                    }
                                }
                                else if (map_Baux[ip][jp-9] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'C')
                            if (jp != 8)
                            {
                                if(map_Caux[ip][jp-9] == -8)
                                {
                                    char temp = map_Caux[ip][jp];
                                    map_Caux[ip][jp] = map_Caux[ip][jp-9];
                                    map_Caux[ip][jp-9] = temp;
                                    jp -= 9;
                                }
                                else if (map_Caux[ip][jp-9] == 'P')
                                {
                                    ++score;
                                    if (score == 1 || score == 2)
                                    {
                                        map_Caux[ip][jp-9] = map_Caux[ip][jp];
                                        map_Caux[ip][jp] = deg;
                                        jp -= 9;
                                    }
                                    if (score == 3)
                                    {
                                        flagWin = 1;
                                        per[indexOfPer].level += 3;
                                        sleep(2);
                                        clrscr();
                                        printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                        scanf(" \n%c", &YesNo);
                                        if (YesNo == 'Y')
                                            break;
                                        flag = 0;
                                        continue;
                                    }
                                }
                                else if (map_Caux[ip][jp-9] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }
                    }
                    else if (key == 114) // right arrow
                    {
                        if (map_type == 'A')
                            if (jp != 71)
                            {
                                if(map_Aaux[ip][jp+9] == -8)
                                {
                                    char temp = map_Aaux[ip][jp];
                                    map_Aaux[ip][jp] = map_Aaux[ip][jp+9];
                                    map_Aaux[ip][jp+9] = temp;
                                    jp += 9;
                                }
                                else if (map_Aaux[ip][jp+9] == 'P')
                                {
                                    ++score;
                                    flagWin = 1;
                                    per[indexOfPer].level += 3;
                                    sleep(2);
                                    clrscr();
                                    printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    if (YesNo == 'Y')
                                        break;
                                    flag = 0;
                                    continue;
                                }
                                else if (map_Aaux[ip][jp+9] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 20; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Aaux[k][z] = map_A[k][z];
                                        i = 14;
                                        j = 17;
                                        ip = 9;
                                        jp = 53;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'B')
                            if (jp != 71)
                            {
                                if(map_Baux[ip][jp+9] == -8)
                                {
                                    char temp = map_Baux[ip][jp];
                                    map_Baux[ip][jp] = map_Baux[ip][jp+9];
                                    map_Baux[ip][jp+9] = temp;
                                    jp += 9;
                                }
                                else if (map_Baux[ip][jp+9] == 'P')
                                {
                                    ++score;
                                    if (score == 1)
                                    {
                                        map_Baux[ip][jp+9] = map_Baux[ip][jp];
                                        map_Baux[ip][jp] = deg;
                                        jp += 9;
                                    }
                                    if (score == 2)
                                    {
                                        flagWin = 1;
                                        per[indexOfPer].level += 3;
                                        sleep(2);
                                        clrscr();
                                        printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                        scanf(" \n%c", &YesNo);
                                        if (YesNo == 'Y')
                                            break;
                                        flag = 0;
                                        continue;
                                    }
                                }
                                else if (map_Baux[ip][jp+9] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'C')
                            if (jp != 80)
                            {
                                if(map_Caux[ip][jp+9] == -8)
                                {
                                    char temp = map_Caux[ip][jp];
                                    map_Caux[ip][jp] = map_Caux[ip][jp+9];
                                    map_Caux[ip][jp+9] = temp;
                                    jp += 9;
                                }
                                else if (map_Caux[ip][jp+9] == 'P')
                                {
                                    ++score;
                                    if (score == 1 || score == 2)
                                    {
                                        map_Caux[ip][jp+9] = map_Baux[ip][jp];
                                        map_Caux[ip][jp] = deg;
                                        jp += 9;
                                    }
                                    if (score == 3)
                                    {
                                        flagWin = 1;
                                        per[indexOfPer].level += 3;
                                        sleep(2);
                                        clrscr();
                                        printf("\nYou Won !!!\nWanna leave? (Y/N)\n");
                                        scanf(" \n%c", &YesNo);
                                        if (YesNo == 'Y')
                                            break;
                                        flag = 0;
                                        continue;
                                    }
                                }
                                else if (map_Caux[ip][jp+9] == 'G')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }
                    }
                    int random;
                    srand(time(0));
                    random = rand() % 4 + 1;
                    if (random == 1) // means ghost wants to move up
                    {
                        if (map_type == 'A')
                            if (i != 4) // be carefull! balaye saresh saghf nabashe
                            {
                                if (map_Aaux[i-5][j] == -8)
                                {
                                    char temp = map_Aaux[i][j];
                                    map_Aaux[i][j] = map_Aaux[i-5][j];
                                    map_Aaux[i-5][j] = temp;
                                    i -= 5;
                                }
                                else if (map_Aaux[i-5][j] == '@') // age be pacman barkhord kard bebaze
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 20; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Aaux[k][z] = map_A[k][z];
                                        i = 14;
                                        j = 17;
                                        ip = 9;
                                        jp = 53;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'B')
                        {
                            if (i_1 != 4) // in baraye ghost avale
                            {
                                if (map_Baux[i_1-5][j_1] == -8)
                                {
                                    char temp = map_Baux[i_1][j_1];
                                    map_Baux[i_1][j_1] = map_Baux[i_1-5][j_1];
                                    map_Baux[i_1-5][j_1] = temp;
                                    i_1 -= 5;
                                }
                                else if (map_Baux[i_1-5][j_1] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                            if (i_2 != 4) // in baraye ghost dovom
                            {
                                if (map_Baux[i_2-5][j_2] == -8)
                                {
                                    char temp = map_Baux[i_2][j_2];
                                    map_Baux[i_2][j_2] = map_Baux[i_2-5][j_2];
                                    map_Baux[i_2-5][j_2] = temp;
                                    i_2 -= 5;
                                }
                                else if (map_Baux[i_2-5][j_2] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                        }
                        if (map_type == 'C')
                        {
                            if (i_1 != 2)
                            {
                                if (map_Caux[i_1-5][j_1] == -8)
                                {
                                    char temp = map_Caux[i_1][j_1];
                                    map_Caux[i_1][j_1] = map_Caux[i_1-5][j_1];
                                    map_Caux[i_1-5][j_1] = temp;
                                    i_1 -= 5;
                                }
                                else if (map_Caux[i_1-5][j_1] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }
                            if (i_2 != 2)
                            {
                                if (map_Caux[i_2-5][j_2] == -8)
                                {
                                    char temp = map_Caux[i_2][j_2];
                                    map_Caux[i_2][j_2] = map_Caux[i_2-5][j_2];
                                    map_Caux[i_2-5][j_2] = temp;
                                    i_2 -= 5;
                                }
                                else if (map_Caux[i_2-5][j_2] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }

                            }
                        }
                    }
                    else if (random == 2) // means ghost wants to move right
                    {
                        if (map_type == 'A')
                            if (j != 71) // rast divar nabashe
                            {
                                if(map_Aaux[i][j+9] == -8)
                                {
                                    char temp = map_Aaux[i][j];
                                    map_Aaux[i][j] = map_Aaux[i][j+9];
                                    map_Aaux[i][j+9] = temp;
                                    j += 9;
                                }
                                else if (map_Aaux[i][j+9] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 20; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Aaux[k][z] = map_A[k][z];
                                        i = 14;
                                        j = 17;
                                        ip = 9;
                                        jp = 53;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'B')
                        {
                            if (j_1 != 71)
                            {
                                if (map_Baux[i_1][j_1+9] == -8)
                                    {
                                        char temp = map_Baux[i_1][j_1];
                                        map_Baux[i_1][j_1] = map_Baux[i_1][j_1+9];
                                        map_Baux[i_1][j_1+9] = temp;
                                        j_1 += 9;
                                    }
                                else if (map_Baux[i_1][j_1+9] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                            if (j_2 != 71)
                            {
                                if (map_Baux[i_2][j_2+9] == -8)
                                    {
                                        char temp = map_Baux[i_2][j_2];
                                        map_Baux[i_2][j_2] = map_Baux[i_2][j_2+9];
                                        map_Baux[i_2][j_2+9] = temp;
                                        j_2 += 9;
                                    }
                                else if (map_Baux[i_2][j_2+9] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                            
                        }
                        if (map_type == 'C')
                        {
                            if (j_1 != 80)
                            {
                                if (map_Caux[i_1][j_1+9] == -8)
                                {
                                    char temp = map_Caux[i_1][j_1];
                                    map_Caux[i_1][j_1] = map_Caux[i_1][j_1+9];
                                    map_Caux[i_1][j_1+9] = temp;
                                    j_1 += 9;
                                }
                                else if (map_Caux[i_1][j_1+9] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }
                            if (j_2 != 80)
                            {
                                if (map_Caux[i_2][j_2+9] == -8)
                                {
                                    char temp = map_Caux[i_2][j_2];
                                    map_Caux[i_2][j_2] = map_Caux[i_2][j_2+9];
                                    map_Caux[i_2][j_2+9] = temp;
                                    j_2 += 9;
                                }
                                else if (map_Caux[i_2][j_2+9] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    else if (random == 3) // means ghost wants to move down
                    {
                        if (map_type == 'A')
                            if (i != 14) // samte paiienesh divar nabashe
                            {
                                if (map_Aaux[i+5][j] == -8)
                                {
                                    char temp = map_Aaux[i][j];
                                    map_Aaux[i][j] = map_Aaux[i+5][j];
                                    map_Aaux[i+5][j] = temp;
                                    i += 5;
                                }
                                else if (map_Aaux[i+5][j] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 20; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Aaux[k][z] = map_A[k][z];
                                        i = 14;
                                        j = 17;
                                        ip = 9;
                                        jp = 53;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'B')
                        {
                            if (i_1 != 29)
                            {
                                if (map_Baux[i_1+5][j_1] == -8)
                                {
                                    char temp = map_Baux[i_1][j_1];
                                    map_Baux[i_1][j_1] = map_Baux[i_1+5][j_1];
                                    map_Baux[i_1+5][j_1] = temp;
                                    i_1 += 5;
                                }
                                else if (map_Baux[i_1+5][j_1] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                            if (i_2 != 29)
                            {
                                if (map_Baux[i_2+5][j_2] == -8)
                                {
                                    char temp = map_Baux[i_2][j_2];
                                    map_Baux[i_2][j_2] = map_Baux[i_2+5][j_2];
                                    map_Baux[i_2+5][j_2] = temp;
                                    i_2 += 5;
                                }
                                else if (map_Baux[i_2+5][j_2] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                        }
                        if (map_type == 'C')
                        {
                            if (i_1 != 37)
                            {
                                if (map_Caux[i_1+5][j_1] == -8)
                                {
                                    char temp = map_Caux[i_1][j_1];
                                    map_Caux[i_1][j_1] = map_Caux[i_1+5][j_1];
                                    map_Caux[i_1+5][j_1] = temp;
                                    i_1 += 5;
                                }
                                else if (map_Caux[i_1+5][j_1] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }
                            if (i_2 != 37)
                            {
                                if (map_Caux[i_2+5][j_2] == -8)
                                {
                                    char temp = map_Caux[i_2][j_2];
                                    map_Caux[i_2][j_2] = map_Caux[i_2+5][j_2];
                                    map_Caux[i_2+5][j_2] = temp;
                                    i_2 += 5;
                                }
                                else if (map_Caux[i_2+5][j_2] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    else if (random == 4) // means ghost wants to move left
                    {
                        if (map_type == 'A')
                            if (j != 8) // samte chapesh divar nabashe
                            {
                                if(map_Aaux[i][j-9] == -8)
                                {
                                    char temp = map_Aaux[i][j];
                                    map_Aaux[i][j] = map_Aaux[i][j-9];
                                    map_Aaux[i][j-9] = temp;
                                    j -= 9;
                                }
                                else if (map_Aaux[i][j-9] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 20; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Aaux[k][z] = map_A[k][z];
                                        i = 14;
                                        j = 17;
                                        ip = 9;
                                        jp = 53;
                                        continue;
                                    }
                                }
                            }
                        if (map_type == 'B')
                        {
                            if (j_1 != 8)
                            {
                                if (map_Baux[i_1][j_1-9] == -8)
                                {
                                    char temp = map_Baux[i_1][j_1];
                                    map_Baux[i_1][j_1] = map_Baux[i_1][j_1-9];
                                    map_Baux[i_1][j_1-9] = temp;
                                    j_1 -= 9;
                                }
                                else if (map_Baux[i_1][j_1-9] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                            if (j_2 != 8)
                            {
                                if (map_Baux[i_2][j_2-9] == -8)
                                {
                                    char temp = map_Baux[i_2][j_2];
                                    map_Baux[i_2][j_2] = map_Baux[i_2][j_2-9];
                                    map_Baux[i_2][j_2-9] = temp;
                                    j_2 -= 9;
                                }
                                else if (map_Baux[i_2][j_2-9] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 32; ++k)
                                            for (int z = 0; z < 80; ++z)
                                                map_Baux[k][z] = map_B[k][z];
                                        i_1 = 14;
                                        i_2 = 14;
                                        j_1 = 8;
                                        j_2 = 62;
                                        ip = 24;
                                        jp = 35;
                                        continue;
                                    }
                                }
                            }
                        }
                        if (map_type == 'C')
                        {
                            if (j_1 != 8)
                            {
                                if (map_Caux[i_1][j_1-9] == -8)
                                {
                                    char temp = map_Caux[i_1][j_1];
                                    map_Caux[i_1][j_1] = map_Caux[i_1][j_1-9];
                                    map_Caux[i_1][j_1-9] = temp;
                                    j_1 -= 9;
                                }
                                else if (map_Caux[i_1][j_1-9] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }
                            if (j_2 != 8)
                            {
                                if (map_Caux[i_2][j_2-9] == -8)
                                {
                                    char temp = map_Caux[i_2][j_2];
                                    map_Caux[i_2][j_2] = map_Caux[i_2][j_2-9];
                                    map_Caux[i_2][j_2-9] = temp;
                                    j_2 -= 9;
                                }
                                else if (map_Caux[i_2][j_2-9] == '@')
                                {
                                    score = 0;
                                    per[indexOfPer].level -= 1;
                                    printf("\nGame Over !!!\nWanna play again? (Y/N)\n");
                                    scanf(" \n%c", &YesNo);
                                    sleep(3);
                                    if (YesNo == 'N')
                                    {
                                        clrscr();
                                        flag = 0;
                                        continue;
                                    }
                                    else
                                    {
                                        for(int k = 0; k < 40; ++k)
                                            for (int z = 0; z < 88; ++z)
                                                map_Caux[k][z] = map_C[k][z];
                                        i_1 = 2;
                                        j_1 = 8;
                                        i_2 = 32;
                                        j_2 = 53;
                                        ip = 32;
                                        jp = 8;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }
            sleep(5);
            clrscr();
            if (!flagWin) // age player bazi ro borde nabayed bazi save beshe
            {
                printf("Wanna save your last play? (Y/N)\n");
                scanf(" \n%c", &YesNo);
                if (YesNo == 'Y')
                {
                    if (map_type == 'A')
                        SaveLastPlay(map_Aaux, 20, ID, score);
                    else if (map_type == 'B')
                        SaveLastPlay(map_Baux, 32, ID, score);
                    else 
                        SaveLastPlay_2(map_Caux, 40, ID, score);
                    per[indexOfPer].SaveFile = 1;
                    printf("Save successfully!!!");
                    sleep(2);
                }
            }
        }    
    }


    return 0;
}