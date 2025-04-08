// main.cpp
#include <iostream>
#include "Player.h"

int main() {
	// Create a Player; the constructor handles deck creation and initial hand draw.
	Player player;

	std::cout << "Initial hand: " << player.getHand().toString() << std::endl;

	// Let the player select cards to play.
	try {
		const CardList played = player.selectCardsToPlay();
		std::cout << "You played: " << played.toString() << std::endl;
		std::cout << "New hand: " << player.getHand().toString() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}

	return 0;
}