#include <iostream>
#include <set>


int siguiente(int n) {
	int suma = 0;
	while (n > 0) {
		int d = n % 10;
		suma += d * d * d;
		n /= 10;
	}
	std::cout << " " << suma;
	return suma;
}

bool happy(int n) {
	std::set<int> c;
	std::cout << n << " -";
	while (n != 1 && c.count(n) == 0) {
		c.insert(n);
		n = siguiente(n); 
		std::cout << " -";
	}
	return n == 1;
}


int main() {
	int n;
	std::cin >> n;
	while (n != 0) { if(happy(n)) std::cout << "> cubifinito.";
	else std::cout << "> no cubifinito.";
	std::cout << '\n';
	std::cin >> n;
	}

	return 0;
}
