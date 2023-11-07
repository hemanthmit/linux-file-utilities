#include <stdio.h>

int main() {
	const char* src = "w.txt";
	const char* dest = "ww.txt";
	if (rename(src, dest) == 0) {
		printf("file moved succesfully");
	} else {
		printf("Error");
	}
}
