#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#define CharLength 100
#define TOTAL_SWITCHES 4

#pragma warning (disable:4996)

int main(int argc, char* argv[])
{
	printf("Total arguments: %d\n\n", argc);
	printf("Argument: %s\n\n", argv[0]);

	for (int i = 0; i < argc; i++)
	{
		printf("Argument %d: %s\n", i + 1, argv[i]);
	}

	printf("\n----------------------------------------------------------\n");

	char switches[][CharLength] = { "-a", "-p", "-s", "-n" };

	// bool flag initialised to all false
	bool flag[4] = {false};

	int index = 0;
	int c = 0;



	// This loop checks if all the switches are present in the command line
	// running through all the command line arguments
	for (int k = 1; k < argc; k++)
	{
		// running through all the switches to make sure everything exists
		for (int i = 0; i < TOTAL_SWITCHES; i++)
		{
			if (strcmp(argv[k], switches[i]) == 0)
			{				
				flag[i] = true;
				i++;
			}
		}
	}


	for (int i = 0; i < 4; i++)
	{
		printf("%d: %s\n", i, flag[i]?"True":"False");
	}



	getch();
	return 0;
}

