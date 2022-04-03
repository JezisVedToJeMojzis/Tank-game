#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int randNumber(int a, int b)	//generate random number
{
	return rand() % (b - a + 1) + a;
}

void printPlayers(char str[], int t1, int t2)	//place players
{
	while (1)
	{
		if (str[t1] == '.')	//t1 coord of player
		{
			str[t1] = 'H';	//player
		}
		if (str[t2] == '.')	//t2 coord of PC
		{
			str[t2] = 'P';	//PC
		}
		break;
		printf("%s", str);
	}
}

int pocet_zivotov_PC = 3;
int pocet_zivotov_HRACA = 3;

int hra(char str[], int t1, int t2)
{
	printf("GAME BEGINS\n\n*************************************************\nPlayer's HP : 3\nPC's HP : 3\n*************************************************\n\n");
	printf("TRY BLIND SHOT, TEST YOUR SKILLs OF PREDATOR\n");
	while (1)
	{
		//Players turn
		int rychlost, uhol;
		printf("\n\n\nPlayer's turn\nEnter speed of shot: \n");
		scanf("%d", &rychlost);
		printf("Enter angle of shot: \n");
		scanf("%d", &uhol);
		int dostrel;
		dostrel =t1+  rychlost + uhol;
		memcpy(str + dostrel, "*", 1);	//shows hit
		printf("%s", str);
		memcpy(str +  dostrel, ".", 1);	//initial state of array
		if (dostrel > 100) // if the shot hit too far
		{
			printf("*************************************************\nYOU ARE SHOOTING TOO FAR!\n*************************************************\n\n\n\n");
		}
		if (dostrel == t2)	//if PC is hit 1hp... if PC has 0hp game ends
		{
			pocet_zivotov_PC = pocet_zivotov_PC - 1;
			printf("*************************************************\nYou hit\nPC's HP : %d\n*************************************************\n\n\n\n", pocet_zivotov_PC);
			memcpy(str +  dostrel, "P", 1);	//show tank of PC again
			if (pocet_zivotov_PC == 0)
			{
				printf("*************************************************\nYou won\n*************************************************\n");
				break;
			}
		}
		
		
		
		//PCs turn
		printf("\n\n\nPC's turn\n");
		srand(time(0));
		rychlost = randNumber(1, 20);
		uhol = randNumber(1, 20);
		int x = rychlost + uhol ;
		int dostrel1 = (100 - (100 - t2) - x);
		printf("PC entered speed of shot:\n%d", rychlost);
		printf("\nPC entered angle of shot:\n%d\n", uhol);
		memcpy(str + dostrel1, "+", 1);
		printf("%s", str);
		memcpy(str + dostrel1, ".", 1);
		if (dostrel1 < 0)
		{
			printf("*************************************************\nPC IS SHOOTING TOO FAR!\n*************************************************\n\n\n\n");
		}
		if (dostrel1 == t1)
		{
			pocet_zivotov_HRACA = pocet_zivotov_HRACA - 1;
			printf("*************************************************\nPC hit you\nPlayer's HP : %d\n*************************************************\n\n\n\n", pocet_zivotov_HRACA);
			memcpy(str + dostrel1, "H", 1);	//show players tank again
			if (pocet_zivotov_HRACA == 0)
			{
				printf("*************************************************\nPC won\n*************************************************\n");
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

	char str[] = ".....................................................................................................\n\n\n\n\n";	//game field (100 characters)

	printPlayers(str, t1, t2);
	hra(str, t1, t2);
}
