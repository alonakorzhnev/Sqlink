#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw_files.h"

#define SIZE 256

int last(char* fileName, int n)
{
	FILE* fp;
	char str[512];
	int* array;
	char* c;
	int i = 0;
	long int pos = 0;
	
	if((fp = fopen(fileName, "r")) == NULL)
	{
		printf("Cannot open file\n");
		return -1;
	}
	
	array = (int*)malloc(n*sizeof(int));
	
	if(array == NULL)
	{
		return -1;
	}
	
	array[i] = 0;
	
	while(fgets(str, 512, fp) != NULL)
	{		
		i++;
		i = i%n;
		printf("i = %d ", i);
		array[i] = ftell(fp);
		printf("%d\n", array[i]);		
	}
	
	fseek(fp, array[(i+1)%n], SEEK_SET);
	
	while ( fgets(str, 512, fp) != NULL ) {
		printf("%s", str);
	}
	
	if(fclose(fp) != 0)
	{
		return -1;
	}
	
	free(array);
}

int countLetters(char* fileName)
{
	FILE* fp;
	int alefbet[27] = {0};
	int letter;
	
	if((fp = fopen(fileName, "r")) == NULL)
	{
		printf("Cannot open file\n");
		return -1;
	}
	
	while((letter = fgetc(fp)) != EOF)
	{
        if(letter >= 'a' && letter <= 'z')
		{
            letter -= 'a'; 
            alefbet[letter]++;
        }
        else if(letter >= 'A' && letter <= 'Z')
		{
            letter -= 'A';
            alefbet[letter]++;
        }
    }
	
	for(letter = 0; letter < 26; letter++)
	{
		printf("%c: %d\n", letter + 'a', alefbet[letter]);
    }

    fclose(fp);
    return 0;	
}

int countWords(char* fileName)
{
		

}
