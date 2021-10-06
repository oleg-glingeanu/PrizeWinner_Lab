#include <iostream>
#include <list>
#include <random>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

inline int task1() {
	int finalists = 25;
	int prizes[26];
	int prize_pool[5];
	srand(99922);
	for (int finalist = 0; finalist < finalists; finalist++){
		default_random_engine deEngine(time(0));
		uniform_int_distribution<int> intDistro(0, 25);
		prizes[finalist] = intDistro(deEngine);
	}
	for (int i = 0; i <4; i++){
		int pick = (rand() % 24) + 1;
		prize_pool[i] = prizes[pick];
		for (int j = 0; j < i; j++) {
			if (prize_pool[j] == prize_pool[i]) {
				for (int v : prize_pool) {
					cout << v << ", ";
					if (v == sizeof(prize_pool)) {
						cout << v;
					}
				}
				cout << "WONT WORK ! ";
				for (int k = 0; k < 4; k++) {
					int pick = (rand() % 24) + 1;
					prize_pool[k] = prizes[pick];
				}
			}
		}
	}
	for (int v : prize_pool) {
		cout << v << ", ";
		if (v == sizeof(prize_pool)) {
			cout << v;
		}
	}
	cout << "WILL WORK ! ";

	return 0;
}