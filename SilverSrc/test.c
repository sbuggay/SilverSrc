#include "cmd.h"

#include "test.h"

void test_print() {
	printf("test_print()\n");
}

void test_echo(char* string) {
	printf("%s\n", string);
}

void test_init() {
	cmd_addcommand("test", test_print);
	cmd_addcommand("echo", test_echo);
}

