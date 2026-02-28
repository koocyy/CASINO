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

int pocet_kol(int *Pkol) {
    *Pkol = rand() % 101 + 50;
    return *Pkol;
}

char* fmtNum(int n, char *buf,int tipr) {
    if (n == 0)
        sprintf(buf, "\033[92m%02d\033[0m", n);
    else if (n == tipr)
        sprintf(buf, "\033[1m\033[94m%02d\033[0m", n);
    else if (n==1||n==3||n==5||n==7||n==9||n==12||n==14||n==16||n==18||n==19||n==21||n==23||n==25||n==27||n==30||n==32||n==34||n==36)
        sprintf(buf, "\033[91m%02d\033[0m", n);
    else
        sprintf(buf, "%02d", n);
    return buf;
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
            printf("\nJACKPOT!!!\n");
            Sleep(1500);
            *penize += sazka * 20;
        } else if (v == a || a == r) {
                printf("\nJACKPOT!!!\n");
                Sleep(1500);
               *penize += sazka * 3;
               }
            else {
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
    int sazka,tipr,hrat=1,hra,barva;

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
            printf("Vyber si cislo od 0 do 35: ");
            scanf("%d", &tipr);
            int a=0,b=1,c=2,d=3,e=4,f=5,g=6,h=7,i2=8,j=9,k=10,l=11,m=12,n=13,o=14,p=15,q=16,r=17,s=18,t=19,u=20,v=21,w=22,x=23,y=24,z=25,a1=26,b1=27,c1=28,d1=29,e1=30,f1=31,g1=32,h1=33,i1=34,j1=35;
            // padlo = rand() % 37;
            int kolo[36] = {
                0, 32, 15, 19, 4, 21, 2, 25, 17,
                34, 6, 27, 13, 11, 30, 8, 23,
                10, 5, 24, 16, 33, 1, 20, 14, 31,
                9, 22, 18, 29, 7, 28, 12, 35, 3, 26
            };
            hideCursor();
            int Pkol = 0;
            pocet_kol(&Pkol);
            char buf1[20],buf2[20],buf3[20],buf4[20],buf5[20],buf6[20],buf7[20],buf8[20],buf9[20],buf10[20],buf11[20],buf12[20],buf13[20],buf14[20],buf15[20],buf16[20],buf17[20],buf18[20],buf19[20],buf20[20],buf21[20],buf22[20],buf23[20],buf24[20],buf25[20],buf26[20],buf27[20],buf28[20],buf29[20],buf30[20];
            for (int i = 0; i < Pkol+1; i++) {
                system("cls");
                printf("                  /^\\\n");
                printf("         |%s|%s|%s|%s|%s|%s|%s|\n",fmtNum(kolo[dalsiCislo(&a)],buf1, tipr),fmtNum(kolo[dalsiCislo(&j1)],buf2, tipr),fmtNum(kolo[dalsiCislo(&i1)],buf3, tipr),fmtNum(kolo[dalsiCislo(&h1)],buf4, tipr),fmtNum(kolo[dalsiCislo(&g1)],buf5, tipr),fmtNum(kolo[dalsiCislo(&f1)],buf6, tipr),fmtNum(kolo[dalsiCislo(&e1)],buf7, tipr));
                printf("      |%s|        \\v/          |%s|\n",fmtNum(kolo[dalsiCislo(&b)],buf8, tipr),fmtNum(kolo[dalsiCislo(&d1)],buf9, tipr));
                printf("   |%s|            |             |%s|\n",fmtNum(kolo[dalsiCislo(&c)],buf10, tipr),fmtNum(kolo[dalsiCislo(&c1)],buf11, tipr));
                printf("|%s|               |                |%s|\n",fmtNum(kolo[dalsiCislo(&d)],buf12, tipr),fmtNum(kolo[dalsiCislo(&b1)],buf13, tipr));
                printf("|%s|               |                |%s|\n",fmtNum(kolo[dalsiCislo(&e)],buf14, tipr),fmtNum(kolo[dalsiCislo(&a1)],buf15, tipr));
                printf("|%s|             [###]              |%s|\n",fmtNum(kolo[dalsiCislo(&f)],buf16, tipr),fmtNum(kolo[dalsiCislo(&z)],buf17, tipr));
                printf("|%s|------------[# 0 #]-------------|%s|\n",fmtNum(kolo[dalsiCislo(&g)],buf18, tipr),fmtNum(kolo[dalsiCislo(&y)],buf19, tipr));
                printf("|%s|             [###]              |%s|\n",fmtNum(kolo[dalsiCislo(&h)],buf20, tipr),fmtNum(kolo[dalsiCislo(&x)],buf21, tipr));
                printf("|%s|               |                |%s|\n",fmtNum(kolo[dalsiCislo(&i2)],buf22, tipr),fmtNum(kolo[dalsiCislo(&w)],buf23, tipr));
                printf("|%s|               |                |%s|\n",fmtNum(kolo[dalsiCislo(&j)],buf24, tipr),fmtNum(kolo[dalsiCislo(&v)],buf25, tipr));
                printf("   |%s|            |             |%s|\n",fmtNum(kolo[dalsiCislo(&k)],buf26, tipr),fmtNum(kolo[dalsiCislo(&u)],buf27, tipr));
                printf("      |%s|         |          |%s|\n",fmtNum(kolo[dalsiCislo(&l)],buf28, tipr),fmtNum(kolo[dalsiCislo(&t)],buf29, tipr));
                printf("         |%s|%s|%s|%s|%s|%s|%s|\n",fmtNum(kolo[dalsiCislo(&m)],buf30, tipr),fmtNum(kolo[dalsiCislo(&n)],buf1, tipr),fmtNum(kolo[dalsiCislo(&o)],buf2, tipr),fmtNum(kolo[dalsiCislo(&p)],buf3, tipr),fmtNum(kolo[dalsiCislo(&q)],buf4, tipr),fmtNum(kolo[dalsiCislo(&r)],buf5, tipr),fmtNum(kolo[dalsiCislo(&s)],buf6, tipr));
                if (i>Pkol-20&&i<Pkol-12) {
                    Sleep(100);
                }
                else if (i>=Pkol-11&&i<Pkol-5){
                    Sleep(170);
                }
                else if (i>=Pkol-5){
                    Sleep(450);
                }
                else {
                    Sleep(10);
                }
            }

            // to co padlo = kolo[i1-1]

            showCursor();
            if (tipr==kolo[i1-1]&&kolo[i1-1]==0) {
                printf("SUPER VYHRA!!!\n");
                Sleep(1500);
                *penize += sazka * 100;
            }
            if (tipr == kolo[i1-1]) {
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
/* funkce pro niga petr */
void blackjack(int *penize) {
    int vzit,hrat=1,sazka,karta,dalsi;

    while (hrat==1){
        int dohromady=0,ddohromady=0;
        system("cls");
        printf("VITEJ V BLACKJACKU\n");
        printf("\nMas %d kreditu\n", *penize);
        printf("Kolik chces vsadit?: ");
        scanf("%d", &sazka);
        if (sazka > *penize||sazka<= 0) {
            system("cls");
            printf("Neplatna sazka!\n");
            Sleep(1500);
            goto exit;
        }
       do {
           karta=rand() % 10+1;
           dohromady+=karta;
           system("cls");
           printf("Dostals %d, dohromady mas: %d\n",karta,dohromady);
           printf("Chces si vzit dalsi kartu? 1-ano 0-ne\n");
           scanf("%d",&dalsi);
       }while (dalsi==1&&dohromady<21);
        if (dohromady>21) {
            goto prohra;
        }
        else {
            do {
                karta=rand() % 10+1;
                ddohromady+=karta;
                system("cls");
                printf("Dealer dostal %d, dohromady ma: %d\n",karta,ddohromady);
                Sleep(1500);
            }while (ddohromady<19);
        }
        if (ddohromady>21||dohromady>ddohromady) {
           printf("VYHRAL JSI");
            Sleep(1500);
            *penize += sazka * 2;
        }
        else
        prohra: printf("Mas moc, PROHRAL JSI\n");
        Sleep(2000);
        *penize -= sazka;
        exit:
        printf("Chces hrat znovu? (1 = ano, 0 = ne): \n");
        scanf("%d", &hrat);
    }
}
/*funkce pro niga kolo*/
/*
void kolostesti(int *penize) {
    int sazka,hrat=1;
    while (hrat == 1) {
        system("cls");
        printf("VITEJ V KOLESTESTI\n");
        printf("\nMas %d kreditu\n", *penize);
        printf("Kolik chces vsadit?: ");
        scanf("%d", &sazka);
        if (sazka > *penize || sazka <= 0) {
            system("cls");
            printf("Neplatna sazka!\n");
            Sleep(1500);
            continue;







      }
}
*/

int main() {
srand(time(NULL));
int gamble,menu,penize=1000;
do{
    system("cls");
    printf("VITEJ V KURIHO A TONDOVEM CASINE!!!\n\n");
    printf("VYBER SI: AUTOMAT-1\n\t  RULETA-2\n\t  BLACKJACK-3\n");
    scanf("%d",&gamble);

switch (gamble){
        case 1:automat(&penize);printf("\nKonec hry. Zbylo ti %d kreditu.\n", penize);system("cls");break;
        case 2:ruleta(&penize);printf("\nKonec hry. Zbylo ti %d kreditu.\n", penize);system("cls");break;
        case 3:blackjack(&penize);printf("\nKonec hry. Zbylo ti %d kreditu.\n", penize);system("cls");break;
        case 4:ruleta(&penize);printf("\nKonec hry. Zbylo ti %d kreditu.\n", penize);system("cls");break;
}
    printf("\nKonec hry. Zbylo ti %d kreditu.\n", penize);
    printf("Chces se vratit do menu? (1 = ano, 0 = ne): \n");
    scanf("%d", &menu);
}while(menu == 1);
return 0;
}
