#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void f_delay(int);
unsigned char random_inport(void);
void printport(int);
unsigned char toHex(unsigned char port);


int main() {
	unsigned char port;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		port = random_inport();
		if ((port >> 7) == 1) {
			printf("%c \n", toHex(port & 0x0F));
		}
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

unsigned char toHex(unsigned char port) {
	switch (port) {
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	case 15:
		return 'F';
	default:
		return '?';
	}
}