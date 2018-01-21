#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#define CharLength 100
#define TOTAL_SWITCHES 4

#pragma warning (disable:4996)

// prototypes
void Server(int port);
void Client(char adr[], char port[], char blocksize[], char totalblocks[], char protocol[]);
bool ValidateField(char* argv[], int FieldIndex, int ValidationIndex);



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
	bool flag[6] = {false};

	int index = 0;
	int c = 0;

	 
	
	

	// This loop checks if all the switches are present in the command line
	// running through all the command line arguments
	for (int k = 1; k < argc; k++)
	{
		// running through all the switches to make sure everything exists
		for (int i = 0; i < TOTAL_SWITCHES; i++)
		{
			if (stricmp(argv[k], switches[i]) == 0)
			{					
				if (ValidateField(argv, k, i))
				{
					flag[i] = true;
				}
				i++;
			}
		}

		if (stricmp(argv[k], "-TCP") == 0)
		{
			// 5th index (for tcp)
			flag[4] = true;
		}
		else
			if (stricmp(argv[k], "-UDP") == 0)
			{
				// 6th index (for udp)
				flag[5] = true;
			}
	}

	

	//		0: -a address
	//		1: -p port
	//		2: -s block size
	//		3: -n number of blocks
	//		4: -TCP
	//		5: -UDP

	for (int i = 0; i < 6; i++)
	{
		printf("%d: %s\n", i, flag[i]?"True":"False");
	}

	// if server, call server
	if (flag[1] == true && flag[0] == false && flag[2] == false &&
		flag[3] == false && flag[4] == false && flag[5] == false)
	{		
		Server(100);
	}
	else
		// call client if sufficient arguments are there
		if (flag[1] == true && flag[0] == true && flag[2] == true &&
			flag[3] == true && (flag[4] == true || flag[5] == true))
		{
			Client("something", "", "", "", "");
		}
		// print error if not sufficient arguments are there
		else
			printf("Invalid arguments!!");





	getch();
	return 0;
}

// validates the command line arguments, returns bool flag based on valid/invalid data
bool ValidateField(char* argv[], int FieldIndex, int ValidationIndex)
{
	bool flag = true;

	switch (ValidationIndex)
	{
	case 0: 
		printf("Validating address\n");
		flag = ValidateAddress(argv[FieldIndex + 1]);
		break;
	case 1:
		printf("Validating port\n");
		flag = ValidatePort(argv[FieldIndex + 1]);
		break;
	case 2:
		printf("Validating block size\n");
		break;
	case 3:
		printf("Validating number of blocks\n");
		break;
	case 4:
		printf("Validating tcp\n");
		break;
	case 5: 
		printf("Validating udp\n");
		break;

	default:
		flag = false;
		break;
	}
	
	return flag;
}






