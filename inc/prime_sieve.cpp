#include "prime_sieve.h"
#define SIEVE_MAX 90000

namespace prime {
	int intSqrt(int num) {
		int a = 0, b = num, c;

		while (b - a > 1) {
			c = (a + b) / 2;
			if ((c * c) > num) b = c; else a = c;
		}

		return a;
	}

	bool sieve[SIEVE_MAX] = {};

	int sieved = 1, checked = 2;

	void sieveNum(int num) {
		for (int i = 2 * num; i <= SIEVE_MAX; i += num)
			sieve[i - 2] = true;
	}

	void sieveNext() {
		do {
			sieved++;
		} while (sieve[sieved - 2]);

		sieveNum(sieved);
	}

	void sieveUntil(int num) {
		int root = intSqrt(num);
		while (sieved < root) sieveNext();
		checked = sieved * sieved;
	}

	bool isPrime(int number) {
		if (number < 2) return false;
		if (number > SIEVE_MAX) throw invalid_argument("Received too big a number");
		if (number > checked) sieveUntil(number);
		return !sieve[number - 2];
	}
}