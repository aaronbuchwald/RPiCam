#include <unistd.h>
#include <iostream>

int main() {
	int M = 1000000;
	usleep(3 * M);
	std::cout << "done" << std::endl;
}
