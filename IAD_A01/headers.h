#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// prototypes

// validations
bool ValidateDigits(char digits[]);
bool ValidateAddress(char adr[]);

// Main
void Server(int port);
void Client(char adr[], char port[], char blocksize[], char totalblocks[], char protocol[]);
bool ValidateField(char* argv[], int FieldIndex, int ValidationIndex);
void converttolowercase(char* temp);


