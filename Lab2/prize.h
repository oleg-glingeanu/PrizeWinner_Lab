#include <iostream>
#include <random>
#include <ctime>

using namespace std;

inline int prize_task() {


	const int NUM_PARTICIPANTS = 25;
	const int FINALISTS = 4;
	int participants[NUM_PARTICIPANTS];
	int winners[FINALISTS];

	default_random_engine defEngine(time(0));
	uniform_int_distribution<int> intDistro(1, 25);
	uniform_int_distribution<int> intDistroo(1, 24);

	// Array to asign a random number to each 25 participants
	for (int participant = 0; participant < NUM_PARTICIPANTS; participant++) {
		int rand_number = intDistro(defEngine);
		participants[participant] = rand_number;
	}

	for (auto v : participants) {
		cout << v << ", ";
	}
	cout << " Participants |   ";

	// Selecting Random winner from Participants
	for (int i = 0; i < FINALISTS; i++) {
		int pick = intDistroo(defEngine);
		winners[i] = participants[pick];

		for (int y = 0; y < 3; y++) {

			for (int j = 0; j < 1; j++) {

				if (winners[j] == winners[i]) {
					int pick = intDistroo(defEngine);
					winners[j] = participants[pick];
				}
			}
		}
	}

	for (auto v : winners) {
		cout << v << ", ";
	}
	cout << " Winners!   ";








	
	return 0;
}
