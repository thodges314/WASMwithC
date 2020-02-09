#include <emscripten.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("hello, world!\n");
	EM_ASM(InitWrappers());
	printf("Initialisation complete.\n");
}

void test()
{
	printf("button test\n");
}

void int_test(int num)
{
	printf("int test=%f\n", num);
}

void float_test(float num)
{
	printf("float test=%f\n", num);
}

void string_test(char *str)
{
	printf("string test = %s\n", str);
}
