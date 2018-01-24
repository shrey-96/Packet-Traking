//#include <stdio.h>
//#include <stdbool.h>
//#include <ctype.h>
//#include <string.h>

#include "headers.h"



// validate port
bool ValidateDigits(char digits[])
{
	bool flag = true;

	// check if each character of string is a digit
	for (unsigned int i = 0; i < strlen(digits); i++)
	{
		if (!isdigit(digits[i]))
		{
			flag = false;
		}
	}

	return flag;
}



// makes sure that address consists of 3 periods and digits
bool ValidateAddress(char adr[])
{
	// sample addreses
	// 127.0.0.1
	// 255.255.255.0
	
	int CountPeriod = 0;


	bool PeriodFlag = true;
	bool CharFlag = true;
	bool Valid = false;

	// run through each character of address and validate it
	for (unsigned int i = 0; i < strlen(adr); i++)
	{
		// check is char is either a digit or a period
		if (!isdigit(adr[i]) && adr[i] != '.')
		{
			CharFlag = false;
		}

		// increment after every period
		if (adr[i] == '.')
			CountPeriod++;
	}

	// change flag state to false if total periods are not 3
	if (CountPeriod != 3)
	{
		PeriodFlag = false;
	}

	// change valid flag to true if both the flags are true
	if (CharFlag && CountPeriod)
		Valid = true;

	if (strlen(adr) >= 14)
		Valid = false;

	return Valid;

}
