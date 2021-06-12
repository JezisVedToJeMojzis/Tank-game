#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int randNumber(int a, int b)	//funkcia na generovanie random cisla
{
	return rand() % (b - a + 1) + a;
}

void printPlayers(char str[], int t1, int t2)	//umiestnenie hracov
{
	while (1)
	{
		if (str[t1] == '.')	//t1 suradnica hraca
		{
			str[t1] = 'H';	//hrac
		}
		if (str[t2] == '.')	//t2 suradnica pocitacu
		{
			str[t2] = 'P';	//pocitac
		}
		break;
		printf("%s", str);
	}
}

int pocet_zivotov_PC = 3;
int pocet_zivotov_HRACA = 3;

int hra(char str[], int t1, int t2)
{
	printf("ZACIATOK HRY\n\n*************************************************\nZivoty hraca : 3\nZivoty pocitaca : 3\n*************************************************\n\n");
	printf("VYSTREL NASLEPO, OTESTUJ SVOJE SCHOPNOSTI PREDATORA\n");
	while (1)
	{
		//HRAC JE NA RADE
		int rychlost, uhol;
		printf("\n\n\nIde hrac\nZadaj rychlost vystrelu: \n");
		scanf("%d", &rychlost);
		printf("Zadaj uhol vystrelu: \n");
		scanf("%d", &uhol);
		int dostrel;
		dostrel =t1+  rychlost + uhol;
		memcpy(str + dostrel, "*", 1);	//zobrazi zasah
		printf("%s", str);
		memcpy(str +  dostrel, ".", 1);	//vrati pole do povodneho stavu
		if (dostrel > 100) // ak je dostrel vacsi ako hracia plocha
		{
			printf("*************************************************\nSTRIELAS MOC DALEKO!\n*************************************************\n\n\n\n");
		}
		if (dostrel == t2)	//ak sme sa trafili tak pocitacu ubudne 1hp... ak ma 0hp konci sa hra
		{
			pocet_zivotov_PC = pocet_zivotov_PC - 1;
			printf("*************************************************\nTrafil si\nPocet zivotov PC : %d\n*************************************************\n\n\n\n", pocet_zivotov_PC);
			memcpy(str +  dostrel, "P", 1);	//znova zobrazi tank pocitaca
			if (pocet_zivotov_PC == 0)
			{
				printf("*************************************************\nVyhral si\n*************************************************\n");
				break;
			}
		}
		
		
		
		//POCITAC JE NA RADE
		printf("\n\n\nIde pocitac\n");
		srand(time(0));
		rychlost = randNumber(1, 20);
		uhol = randNumber(1, 20);
		int x = rychlost + uhol ;
		int dostrel1 = (100 - (100 - t2) - x);
		printf("Pocitac zadal rychlost vystrelu:\n%d", rychlost);
		printf("\nPocitac zadal uhol vystrelu:\n%d\n", uhol);
		memcpy(str + dostrel1, "+", 1);
		printf("%s", str);
		memcpy(str + dostrel1, ".", 1);
		if (dostrel1 < 0)
		{
			printf("*************************************************\nPOCITAC STRELIL MOC DALEKO!\n*************************************************\n\n\n\n");
		}
		if (dostrel1 == t1)
		{
			pocet_zivotov_HRACA = pocet_zivotov_HRACA - 1;
			printf("*************************************************\nPocitac sa trafil\nPocet zivotov HRACA : %d\n*************************************************\n\n\n\n", pocet_zivotov_HRACA);
			memcpy(str + dostrel1, "H", 1);	//znova zobrazi tank hraca
			if (pocet_zivotov_HRACA == 0)
			{
				printf("*************************************************\nVyhral pocitac\n*************************************************\n");
				break;
			}
		}
	}
	return 0;
}

int main()
{
	int t1, t2;
	srand(time(0));
	t1 = randNumber(0, 49);
	t2 = randNumber(50, 100);

	char str[] = ".....................................................................................................\n\n\n\n\n";	//hracia plocha 100 characterov

	printPlayers(str, t1, t2);
	hra(str, t1, t2);
}