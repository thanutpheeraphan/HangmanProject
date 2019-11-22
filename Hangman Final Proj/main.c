#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h> 


char word[1000][100];

char get_Char()
{
	char ans, wrong = 0;
	do
	{
		ans = getchar();
	} while (ans == '\n' || ans == '\t' || ans == ' ');
	while (getchar() != '\n')
	{
		wrong = 1;
	}

	if (wrong)
		return 0;
	else
		return ans;
}


void arrayofwords() {
	int count = 0;

	FILE* inFile;
	inFile = fopen("hangmanwords.txt", "r");
	if (inFile == NULL) {
		printf("null\n");
		system("pause");
	}
	char words[1000];
	while (fscanf(inFile, "%s ", words) != EOF) {
		//printf("pass count: %d\n", count);
		strcpy(word[count], words);
		//printf("%s\n", word[count]);
		if (count == 994) {
			break;
		}
		count += 1;
	}
	fclose(inFile);
	/*
	for (int i = 0; i <= count; i++) {
		printf("%s\n", word[i]);
	}
	*/
}

void loadingscreen() {
	system("cls");
	printf(" \n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\tLOADING . ");
	Sleep(350);
	system("cls");
	printf(" \n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\tLOADING .. ");
	Sleep(350);
	system("cls");
	printf(" \n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\tLOADING ... ");
	Sleep(350);

}

void youwin() {
	printf("  \t\t\t\t\t __   __            _    _ _       _ \n");
	printf("  \t\t\t\t\t \\ \\ / /           | |  | (_)     | |\n");
	printf("  \t\t\t\t\t  \\ V /___  _   _  | |  | |_ _ __ | |\n");
	printf("  \t\t\t\t\t   \\ // _ \\| | | | | |/\\| | | '_ \\| |\n");
	printf("  \t\t\t\t\t   | | (_) | |_| | \\  /\\  / | | | |_|\n");
	printf("  \t\t\t\t\t   \\_/\\___/ \\__,_|  \\/  \\/|_|_| |_(_)\n");

}


int main() {
	int count = 0;
	int i;
	int j = 0;
	char choice, user_input;
	char name[50];
	int running = 1;
	int playing = 1;
	int blacklives = 0;
	int length;
	srand(time(NULL));
	int randomIndex = rand() % 40; //Random the word in the file
	char *blanks;
	int health=0;
	



	char menuText[] = "  \t\t\t\t  _    _\n"
		"  \t\t\t\t | |  | |\n"
		"  \t\t\t\t | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __ \n"
		"  \t\t\t\t |  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n"
		"  \t\t\t\t | |  | | (_| | | | | (_| | | | | | | (_| | | | |\n"
		"  \t\t\t\t |_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n"
		"  \t\t\t\t                     __/ |                      \n"
		"  \t\t\t\t                    |___/                       \n";



	//printf(" \n\n\n\n\n\n\n\n\n\n\t\t\t\t\t");
	printf("%s\n", menuText);
	//printf("  \t\t\t\tPlease enter your name to start playing.. ");
	printf("\n\n\n\t\t\t\t\t =======INSTRUCTIONS======= ");
	printf("\n\n\t\t\t   1: HANGMAN IS THE GAME WHERE YOU HAVE TO GUESS THE WORD.");
	printf("\n\t\t\t   2: YOU WILL HAVE TO GUESS UNTILL YOU FIND THE WORD TO WIN.");
	printf("\n\t\t\t   3: YOU HAVE 6 CHOICES TO FIND THE  WORD\n\n\n");
	//printf(" \n\t\t\t\t\t");
	printf("\n  \t\t\t\tEnter your name: ");
	scanf("%s", name);
	loadingscreen();
	system("cls");
	printf(" \n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");

	printf("Welcome to Hangman %s\n", name);
	printf(" \n");
	printf("\t\t\t\t\t\tType p to start playing\n ");
	printf("\t\t\t\t\t\tType q to quit\n ");
	printf("\t\t\t\t\t\tYour choice? ");
	
	//was here
	

	//scanf("\n%c", &choice);
	//choice = readChar();
	while (running) {

		choice = get_Char();
		//if (health = 0) 
			//return 0;
		
		if (choice == 'p' || choice == 'P') {
			playing = 1;
			blacklives = 7;
			randomIndex = rand() % 40;
			system("cls");
			//printf("List of words \n");
			arrayofwords();
			length = strlen(word[randomIndex]);
			blanks = (char*)malloc(length * sizeof(char)); //Create memory space for blank
			for (int x = 0; x < strlen(word[randomIndex]); x++) {
				blanks[x] = '_';
				//printf("chk: %c\n", blanks[x]);

			}

			//printf("This is word[randomIndex] %d \n", word[randomIndex]);
			while (playing && blacklives>0) {
				printf("\nGuess the letter: ");
				//getchar();
				//scanf("%c%c", &user_input,&buff);
				user_input = get_Char();
				user_input = tolower(user_input);
				//getchar();
				j++;


				for (i = 0; i < strlen(word[randomIndex]); i++) {
					if (user_input == word[randomIndex][i]) {
						printf("This char is correct! %c \n", user_input);
						blanks[i] = word[randomIndex][i];
						//printf("%s\n", word[randomIndex]);
						//printf("%c",buff);


					}
				}
				if (!strchr(blanks, '_')) { //If no blanks left in blanks then you win and go back to loading screen 
					printf("\t\t\t\t\t\tThe word is %s \n\n\n", word[randomIndex]);
					//printf("You Win! \n");
					youwin();
					printf("\t\t\t\t  You will be redirected back to the first page ");
					Sleep(4000);
					loadingscreen();
					playing = 0;
				}
				if (!strchr(word[randomIndex],user_input)) { //If user_input is not in the word, subtract blacklives by 1
					blacklives -= 1;
					printf("%d choices left ", blacklives);
					if (blacklives == 6) {
						printf("\n  _______\n");
						printf("  |\n");
						printf("  |\n");
						printf("  |\n");
						printf("  |\n");
						printf("  |\n");
						printf("__|_________\n\n");
					}
					if (blacklives == 5) {
						printf("\n  _______\n");
						printf("  |/   | \n");
						printf("  |    O \n");
						printf("  |\n");
						printf("  |\n");
						printf("  |\n");
						printf("__|_________\n\n");
					}
					if (blacklives == 4) {
						printf("\n  _______\n");
						printf("  |/   | \n");
						printf("  |    O \n");
						printf("  |   \\|\n");
						printf("  |    |\n");
						printf("  |\n");
						printf("__|_________\n\n");
					}
					if (blacklives == 3) {
						printf("\n  _______\n");
						printf("  |/   | \n");
						printf("  |    O \n");
						printf("  |   \\|/\n");
						printf("  |    | \n");
						printf("  |   \n");
						printf("__|_________\n\n");
					}
					if (blacklives == 2) {
						printf("\n  _______\n");
						printf("  |/   | \n");
						printf("  |    O \n");
						printf("  |   \\|/\n");
						printf("  |    | \n");
						printf("  |   / \n");
						printf("__|_________\n\n");

					}
					if (blacklives == 1) {
						printf("\n  _______\n");
						printf("  |/   | \n");
						printf("  |    O \n");
						printf("  |   \\|/\n");
						printf("  |    | \n");
						printf("  |   / \\\n");
						printf("__|_________\n\n");
					}
					if (blacklives == 0) {
						printf("\n  _______\n");
						printf("  |/   | \n");
						printf("  |    X \n");
						printf("  |   \\|/\n");
						printf("  |    | \n");
						printf("  |   / \\\n");
						printf("__|_________\n\n");

					}
			
				}

				printf("\n");
				printf("\t\t\t\t\t\t");
				for (int j = 0; j < strlen(word[randomIndex]); j++) {

					printf("%c ", blanks[j]);

				}
				//system("pause");

			}
			if (blacklives == 0) {
				//Sleep(2000);
				printf("\n\n\n\t\t\t\t\t\t You Lose!! \n");
				printf("\t\t\t\t You will be redirected back to the first page ");
				Sleep(2000);
				loadingscreen();
				//Sleep(4000);

			}
		}
		if (choice == 'q' || choice == 'Q') {
			//system("pause");
			//free(blanks);
			return 0;
			//running = 0;
		}
		if (choice != 'q' || choice != 'Q' || choice != 'p' || choice != 'P') {
			system("cls");
			printf(" \n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
			printf("Welcome to Hangman %s\n", name);
			printf(" \n");
			printf("\t\t\t\t\t\tType p to start playing\n ");
			printf("\t\t\t\t\t\tType q to quit\n ");
			printf("\t\t\t\t\t\tYour choice? ");
			
		}
		//free(blanks);
	}
	free(blanks);
	//system("cls");

	system("pause");

	return 0;
	

}



