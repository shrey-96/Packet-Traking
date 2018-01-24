#include "headers.h"

void Client(char adr[], char port[], char blocksize[], char totalblocks[], char protocol[])
{
	printf("I'm a client with following attributes: \n");
	printf("\n\tAddress: %s\n\tPort: %s\n\tBlocksize: %s\n\tTotal Blocks: %s\n\tProtocol: %s",
		adr, port, blocksize, totalblocks, protocol);
}