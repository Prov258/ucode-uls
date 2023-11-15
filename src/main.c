#include <uls.h>

int main(int argc, char* argv[]) {
	DIR* dir = opendir(argv[argc - 1]);
	struct dirent *test;

	for (test = readdir(dir); test != NULL; test = readdir(dir)) {
		mx_printstr(test->d_name);
		mx_printstr(" ");
	}
	mx_printstr("\n");

	return 0;
}

