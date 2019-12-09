#include "stdio.h"
#include "string.h"
#include "stdint.h"

char buf[255] = {0};

int main()
{
  char test = 0xe2;
  printf("%02x\n", (uint8_t)test);
	strcat(buf, "abc");
	printf("buf: %s", buf);
}
