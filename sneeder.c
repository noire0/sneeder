#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void slice(char *destStr, const char *srcStr, size_t start, size_t end)
{
	size_t i;
	size_t j = 0;

	for (i = start; i <= end; i++)
	{
		destStr[j] = srcStr[i];
		j++;
	}
	destStr[j] = '\0';
}

void sneeder(const char *sneed, int n)
{
	if (n < 0)
	{
		puts(sneed);
		goto end;
	}
	
	int i;
	// message to print
	char *message = (char*)
		malloc(strlen(sneed)+strlen("FeedSeed")+sizeof(char));
	// the last three letters of sneed
	char *eed = (char*) malloc(4*sizeof(char));

	slice(eed, sneed, strlen(sneed)-3, strlen(sneed)-1);
	
	for (i = 1; i <= n; i++)
	{
		strcpy(message, "");
		if (i%3 == 0)
			strcpy(message, sneed);
		if (i%5 == 0)
		{
			strcat(message, "F");
			strcat(message, eed);
		}
		if (i%7 == 0)
		{
			strcat(message, "S");
			strcat(message, eed);
		}
		if (strcmp(message, "") == 0)
		{
			sprintf(message, "%d", i);
		}
		puts(message);
	}
	
end:
	return;
}

int main(int argc, char *argv[])
{
	int i;
	// index of the number given to sneeder
	int nIn = -1;
	// index of the sneed given to sneeder
	int sneedIn = -1;
	const char *helpMessage =
"sneeder takes a name and an integer to print a word game like FizzBuzz.";
	const char *defaultMessage =
"sneed";

	// default message
	if (argc == 1)
	{
		puts(defaultMessage);
		exit(0);
	}

	// identify arguments
	for (i = 1; i < argc; i++)
	{
		// help
		if (strcmp(argv[i], "-h") == 0)
	{
			puts(helpMessage);
			exit(0);
		}

		if (atoi(argv[i]) != 0)
		{
			printf("Found number: %s\n", argv[i]);
			nIn = i;
		}
		else
			if (strcmp(argv[i], "0") != 0)
			{
				printf("Found sneed: %s\n", argv[i]);
				sneedIn = i;
			}
		
		if (nIn != -1 && sneedIn != -1)
			break;
	}
	
	if (sneedIn != -1)
		sneeder(argv[sneedIn], atoi(argv[nIn]));
	else
		sneeder("Sneed", atoi(argv[nIn]));

	return 0;
}
