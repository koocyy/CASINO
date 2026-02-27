#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
/* KURIHO CASINO (a kocyho) */
int dalsiCislo(int *akt_cislo) {
    if (*akt_cislo == 35) {
        *akt_cislo = 0;
        return *akt_cislo;
    }
    else {
        *akt_cislo += 1;
        return *akt_cislo;

    }
}
/* funkce pro zmenu viditelnosti kurzoru v consoli */
void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;  // hide cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
void showCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = TRUE;   // show cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

/* funkce pro nas automat */
void automat(int *penize) {
    int sazka,v,a,r,hrat=1;
    while (hrat == 1) {
        system("cls");
        printf("VITEJ V AUTOMATU\n");
        printf("\nMas %d kreditu\n", *penize);
        printf("Kolik chces vsadit?\n");
        scanf("%d", &sazka);

        if (sazka > *penize || sazka <= 0) {
            system("cls");
            printf("Neplatna sazka!\n");
            Sleep(1500);
            continue;
        }
        v = rand() % 9 + 1;
        a = rand() % 9 + 1;
        r = rand() % 9 + 1;

        /* animace cisel */
        hideCursor();
        for (int i = 0; i < 250; i++) {
            system("cls");
            printf(" -------------");
            printf("\n[-%d-][-%d-][-%d-]\n", rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1);
            printf(" -------------");
        }
        for (int i = 0; i < 250; i++) {
            system("cls");
            printf(" -|-----------");
            printf("\n[-%d-][-%d-][-%d-]\n", v, rand() % 9 + 1, rand() % 9 + 1);
            printf(" -|-----------");
        }
        for (int i = 0; i < 250; i++) {
            system("cls");
            printf(" -|----|------");
            printf("\n[-%d-][-%d-][-%d-]\n", v, a, rand() % 9 + 1);
            printf(" -|----|------");
        }
        system("cls");
        printf(" -|----|----|-");
        printf("\n[-%d-][-%d-][-%d-]\n", v, a, r);
        printf(" -|----|----|-");
        showCursor();


        if (v == a && a == r) {
            printf("\nVYHRA!!!\n");
            Sleep(1500);
            *penize += sazka * 20;
        } else {
            printf("\nProhral jsi.\n");
            Sleep(1500);
            *penize -= sazka;
        }
        if (*penize <= 0) {
            system("cls");
            printf("Dosly ti penize! Restart na 1000 kreditu.\n");
            *penize = 1000;
            Sleep(2000);
        }
        printf("\nMas %d kreditu\n", *penize);
        printf("Chces hrat znovu? (1 = ano, 0 = ne): ");
        scanf("%d", &hrat);
    }
}

/* funkce pro ruletu */
void ruleta(int *penize) {
    int sazka,padlo,tipr,hrat=1,hra,barva;

    while (hrat == 1) {
        system("cls");
        printf("VITEJ V RULETE\n");
        printf("\nMas %d kreditu\n", *penize);
        printf("Kolik chces vsadit?: ");
        scanf("%d", &sazka);
        if (sazka > *penize || sazka <= 0) {
            system("cls");
            printf("Neplatna sazka!\n");
            Sleep(1500);
            continue;
        }
        system("cls");
        printf("Chces si vsadit na barvu (1) nebo cislo (0)?\n");
        scanf("%d",&hra);

        if (hra==0) {
            system("cls");
            printf("Vyber si cislo od 0 do 36: ");
            scanf("%d", &tipr);
            int a=0,b=1,c=2,d=3,e=4,f=5,g=6,h=7,i2=8,j=9,k=10,l=11,m=12,n=13,o=14,p=15,q=16,r=17,s=18,t=19,u=20,v=21,w=22,x=23,y=24,z=25,a1=26,b1=27,c1=28,d1=29,e1=30,f1=31,g1=32,h1=33,i1=34,j1=35;
            padlo = rand() % 37;
            int kolo[36] = {
                0, 32, 15, 19, 4, 21, 2, 25, 17,
                34, 6, 27, 13, 11, 30, 8, 23,
                10, 5, 24, 16, 33, 1, 20, 14, 31,
                9, 22, 18, 29, 7, 28, 12, 35, 3, 26
            };
            hideCursor();
            for (int i = 0; i < 37; i++) {
                system("cls");
                printf("                   v\n");
                printf("         |%02d|%02d|%02d|%02d|%02d|%02d|%02d|\n",kolo[dalsiCislo(&a)],kolo[dalsiCislo(&j1)],kolo[dalsiCislo(&i1)],kolo[dalsiCislo(&h1)],kolo[dalsiCislo(&g1)],kolo[dalsiCislo(&f1)],kolo[dalsiCislo(&e1)]);
                printf("      |%02d|         ^          |%02d|\n",kolo[dalsiCislo(&b)],kolo[dalsiCislo(&d1)]);
                printf("   |%02d|                          |%02d|\n",kolo[dalsiCislo(&c)],kolo[dalsiCislo(&c1)]);
                printf("|%02d|                                |%02d|\n",kolo[dalsiCislo(&d)],kolo[dalsiCislo(&b1)]);
                printf("|%02d|                                |%02d|\n",kolo[dalsiCislo(&e)],kolo[dalsiCislo(&a1)]);
                printf("|%02d|             [###]              |%02d|\n",kolo[dalsiCislo(&f)],kolo[dalsiCislo(&z)]);
                printf("|%02d|            [# 0 #]             |%02d|\n",kolo[dalsiCislo(&g)],kolo[dalsiCislo(&y)]);
                printf("|%02d|             [###]              |%02d|\n",kolo[dalsiCislo(&h)],kolo[dalsiCislo(&x)]);
                printf("|%02d|                                |%02d|\n",kolo[dalsiCislo(&i2)],kolo[dalsiCislo(&w)]);
                printf("|%02d|                                |%02d|\n",kolo[dalsiCislo(&j)],kolo[dalsiCislo(&v)]);
                printf("   |%02d|                          |%02d|\n",kolo[dalsiCislo(&k)],kolo[dalsiCislo(&u)]);
                printf("      |%02d|                    |%02d|\n",kolo[dalsiCislo(&l)],kolo[dalsiCislo(&t)]);
                printf("         |%02d|%02d|%02d|%02d|%02d|%02d|%02d|\n",kolo[dalsiCislo(&m)],kolo[dalsiCislo(&n)],kolo[dalsiCislo(&o)],kolo[dalsiCislo(&p)],kolo[dalsiCislo(&q)],kolo[dalsiCislo(&r)],kolo[dalsiCislo(&s)]);
                Sleep(1000);
            }
            showCursor();
            if (tipr == padlo) {
                printf("VYHRA!!!\n");
                Sleep(1500);
                *penize += sazka * 50;
            } else {
                printf("Prohral jsi.\n");
                Sleep(1500);
                *penize -= sazka;
            }
        }
        else if (hra == 1) {
            system("cls");
            printf("Sazis na cervenou (1) nebo cernou (2)?\n");
            scanf("%d",&tipr);
            printf("\n");
            barva = rand() % 2+1;

            if (tipr == barva) {
                printf("VYHRA!!!\n");
                Sleep(1500);
                *penize += sazka * 2;
            } else {
               printf("Prohral jsi.\n");
                Sleep(1500);
               *penize -= sazka;
            }
        }
        else {
            system("cls");
            printf("Neplatny vyber.\n");
            Sleep(1500);
            continue;
        }
        if (*penize <= 0) {
            system("cls");
            printf("Dosly ti penize! Restart na 1000 kreditu.\n");
            *penize = 1000;
            Sleep(2000);
        }
        printf("\nMas %d kreditu\n", *penize);
        printf("Chces hrat znovu? (1 = ano, 0 = ne): \n");
        scanf("%d", &hrat);
    };
}


int main() {
srand(time(NULL));
int gamble,menu,penize=1000;
do{
printf("VITEJ V KURIHO A TONDOVEM CASINE!!!\n\n");
printf("VYBER SI: AUTOMAT-1\n\t  RULETA-2\n");
scanf("%d",&gamble);

switch (gamble){
case 1:automat(&penize);printf("\nKonec hry. Zbylo ti %d kreditu.\n", penize);system("cls");break;
case 2:ruleta(&penize);printf("\nKonec hry. Zbylo ti %d kreditu.\n", penize);system("cls");break;
}
    printf("\nKonec hry. Zbylo ti %d kreditu.\n", penize);
    printf("Chces se vratit do menu? (1 = ano, 0 = ne): \n");
    scanf("%d", &menu);
}while(menu == 1);
return 0;
}
