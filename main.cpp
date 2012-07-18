#include <stdio.h>
#include <stdlib.h>

#include "TCPState.h"
#include "TCPConnection.h"

int main(int argc, char* argv[])
{
	struct MyStruct mst;

	mst.ch = 0x67;

	printf("sizeof mystruct=%d\r\n", sizeof(struct MyStruct));

	printf("mst.ch1=%d\r\n", mst.ch1);
	printf("mst.ch2=%d\r\n", mst.ch2);

	TCPConnection *t = new TCPConnection();

	t->PassiveOpen();

	system("pause");

	return 0;
}