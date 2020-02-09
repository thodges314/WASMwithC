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
	printf("int test=%d\n", num);
}

void float_test(float num)
{
	printf("float test=%f\n", num);
}

void string_test(char *str)
{
	printf("string test = %s\n", str);
}
/*
emcc shell.c -o shell-test.html --shell-file new_shell.html -s NO_EXIT_RUNTIME=1 -s EXPORTED_FUNCTIONS="['_test', '_string_test', '_int_test', '_float_test', '_main']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap', 'ccall']"
emrun --browser firefox shell-test.html
*/