#include <sys/time.h>
#include <iostream>

#ifndef NSEC_PER_SEC
#define NSEC_PER_SEC 1000000000ULL
#endif

int main() {
	struct timespec tp;
	clock_gettime(CLOCK_MONOTONIC_COARSE, &tp);
	std::cout << tp.tv_sec << " " << tp.tv_nsec << std::endl;
	return 0;
}
