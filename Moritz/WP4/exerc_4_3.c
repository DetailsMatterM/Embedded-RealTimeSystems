#include <time.h>
#include <stdio.h>

void f_delay(int);
unsigned char random_inport(void);
void printport(int);

int main() {
	unsigned char port;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		port = random_inport();
		printport(port);
		f_delay(5);
	}
	return (0);
}

void f_delay(int tenth_sec) {
	clock_t start_t, end_t;
	start_t = clock();
	do {
		for (long int i = 0; i < 10000000; i++) {
			// Do some work until enough time has passed
		};
		end_t = clock();
	} while ((end_t - start_t) < (tenth_sec * CLOCKS_PER_SEC) / 10);
	return;
}

unsigned char random_inport() {
	unsigned char inport = 0;
	inport = rand() % 256;
	return (inport);
}

void printport(int portvalue) {
	int binchar[8], rest, j, i = 0;
	rest = portvalue;
	while (rest != 0) {
		binchar[i++] = rest % 2;
		rest = rest / 2;
	}
	// Fill to 8 bits
	while (i < 8) {
		binchar[i++] = 0;
	}
	// Print bits and at the end corresponding decimal value
	for (j = i - 1; j > -1; j--) {
		printf("  %d", binchar[j]);
	}
	printf(" --------Porten value = %d  \n", portvalue);
	return;
}