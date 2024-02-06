#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int vowel, consonant, i;

char s[100];

void enterString()
{
	printf("Enter a string\n");
	fgets(s, sizeof(s), stdin);
}

void menu()
{
	printf("A)\t Count the number of vowels in the string\n");
	printf("B)\t Count the number of consonants in the string\n");
	printf("C)\t Convert the string to uppercase\n");
	printf("D)\t Convert the string to lowercase\n");
	printf("E)\t Display the current string\n");
	printf("F)\t Enter another string\n\n");
	printf("X)\t Exit the program\n\n");
}

int countVowel()
{
	int count = 0;

	for (i = 0; i <= strlen(s); i++)
	{
		if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' ||
			s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
			count++;
		
	} 
	return count;
}

int countConsonant()
{
	int count = 0;

	for(i = 0; i <= strlen(s); i++)
	{
		//Ensures that it only counts the actual letters
		if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) 
		{
			//will count any non-vowel letter as a consonant
			if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
				|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'))
				count++;
		}
	}
	return count;
}

void toLowerCase()
{
	for (i = 0; i <= strlen(s); i++)
	{
		//ascii values for all lower case letters
		if (s[i] >= 65 && s[i] <= 90) 
			//all lower case chars have an ascii value 32 higher than their upper case counterparts
			s[i] = s[i] + 32; 
	}
}

void toUpperCase()
{
	for (i = 0; i <= strlen(s); i++)
	{
		//ascii values for all upper case letters
		if (s[i] >= 97 && s[i] <= 122) 
		
			//All upper case chars have an ascii value 32 lower than their lower case counterparts
			s[i] = s[i] - 32; 
		
	}
}

//Wipes the buffer after the first menu option is selected (allows multiple selections)
void clean_stdin(void)
{
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

void main()
{
	char input;

	enterString();

//Will return here after every menu selection except exit
prompt: 

	menu();

	scanf_s("%c", &input);
	clean_stdin();

	//Menu Options
	switch (toupper(input)) //Makes the menu options case insensitive
	{
	case 'A': //Counts the number of Vowels
		vowel = countVowel();;
		printf("Number of vowels: %d\n\n", vowel);
		goto prompt;
	
	case 'B': //Counts the number of consonants
		consonant = countConsonant();
		printf("Number of consonants: %d\n\n", consonant);
		goto prompt;

	case 'C': //Converts the string to uppercase
		toUpperCase();
		printf("%s\n\n", s);
		goto prompt;

	case 'D': //Converts the string to lowercase
		toLowerCase();
		printf("%s\n\n", s);
		goto prompt;
		
	case 'E': //Displays the string
		printf("%s\n\n", s); 
		goto prompt;

	case 'F': //Enter another string
		enterString();
		goto prompt;

	case 'X': //Exits the program
		printf("Goodbye\n\n");
		break;
	}
}
