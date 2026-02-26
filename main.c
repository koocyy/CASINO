#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
/* KURIHO CASINO (a kocyho) */

void automat(int *penize) {
    int sazka,v,a,r,hrat=1;
    while (hrat == 1) {
        system("cls");
        printf("VITEJ V AUTOMATU\n");
        printf("\nMas %d kreditu\n", *penize);
        printf("Kolik chces vsadit?\n");
        scanf("%d", &sazka);

        if (sazka > *penize || sazka <= 0) {
            printf("Neplatna sazka!\n");
            Sleep(1500);
            continue;
        }
        v = rand() % 9 + 1;
        a = rand() % 9 + 1;
        r = rand() % 9 + 1;
        printf("\n[-%d-][-%d-][-%d-]\n", v, a, r);

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

/* zkouska */


int main() {
srand(time(NULL));
int gamble,menu,penize=1000;
do{
printf("VITEJ V KURIHO A TONDOVEM CASINE!!!\n\n");
printf("VYBER SI: AUTOMAT-1\n\t  RULETA-2\n");
scanf("%d",&gamble);

switch (gamble){
case 1:automat(&penize);printf("\nKonec hry. Zbylo ti %d kreditu.\n", penize);system("cls");break;
case 2:{
    int sazka,padlo,tipr1,hrat,hra,barva,tipr2,cisla,cervena,cerna;

    printf("vitej");

    do {
            printf("\nMas %d kreditu\n", penize);

            printf("Kolik chces vsadit?: ");
            scanf("%d", &sazka);

            if (sazka > penize) {
                printf("Nemas dost penez!\n");
            continue;
            }
            printf("chces barvy-1 nebo cisla-0?\n");
            scanf("%d",&hra);

        if (hra==0)
        {
            printf("Tipni si cislo (0-36): ");
              scanf("%d", &tipr1);
              printf("\n");

               padlo = rand() % 37;

            printf("Padlo cislo: %d\n", padlo);

            if (tipr1 == padlo) {
                printf("VYHRA!!!\n");
                penize = penize + sazka * 50;
            } else {
                printf("Prohral jsi.\n");
               penize = penize - sazka;
           }
        }
        else
        {
                printf("cervenu-1 nebo cernou-2?\n");
                scanf("%d",&tipr2);
                printf("\n");

            barva = rand() % 2+1;
            cervena=1;
            cerna=2;

            if (tipr2 == barva) {
                printf("VYHRA!!!\n");
                penize = penize + sazka * 2;
            } else {
               printf("Prohral jsi.\n");
               penize = penize - sazka;
            }
        }
            printf("\nMas %d kreditu\n", penize);
            printf("Chces hrat znovu? (1 = ano, 0 = ne): \n");
            scanf("%d", &hrat);

    } while (hrat == 1 && penize > 0);

    printf("\nKonec hry. Zbylo ti %d kreditu.\n", penize);
break;}
}
     printf("Chces se vratit do menu? (1 = ano, 0 = ne): \n");
     scanf("%d", &menu);
}while(menu == 1);
return 0;
}
