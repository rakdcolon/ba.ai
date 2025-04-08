// Player.cpp
#include "../include/Player.h"
#include "../include/Card.h"
#include "../include/CardList.h"
#include "../include/Enums.h"
#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <stdexcept>

Player::Player() : handSize(8) {
    // Build the absolute deck with 52 cards (4 suits x 13 ranks)
    for (int s = 0; s < 4; s++) {
        for (int r = 0; r < 13; r++) {
            // Cast integers to enums (assuming enum order matches)
            Card card(static_cast<Rank>(r), static_cast<Suit>(s));
            absoluteDeck.add(card);
        }
    }
    deck = absoluteDeck.copy();
    hand = deck.drawNCards(handSize);
}

CardList Player::getAbsoluteDeck() const {
    return absoluteDeck;
}

CardList Player::getDeck() const {
    return deck;
}

CardList Player::getHand() const {
    return hand;
}

int Player::getHandSize() const {
    return handSize;
}

void Player::setAbsoluteDeck(const CardList &deck) {
    absoluteDeck = deck;
}

void Player::setDeck(const CardList &deck) {
    this->deck = deck;
}

void Player::setHand(const CardList &hand) {
    this->hand = hand;
}

void Player::setHandSize( const int handSize) {
    this->handSize = handSize;
}

CardList Player::selectCardsToPlay() {
    CardList playedCards;
    std::vector<Card> handCards = hand.getCards();
    std::cout << "Your hand:" << std::endl;
    for (size_t i = 0; i < handCards.size(); i++) {
        std::cout << i << ": " << handCards[i].toString() << std::endl;
    }
    std::cout << "Enter indices of cards to play (space separated, maximum 5):" << std::endl;

    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> tokens;
    int token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    if (tokens.size() > 5) {
        std::cout << "Maximum 5 cards allowed. Only first 5 indices will be used." << std::endl;
        tokens.resize(5);
    }

    // Use a set to avoid duplicates
    std::set<int> indexSet;
    for (int idx : tokens) {
        if (idx < 0 || idx >= static_cast<int>(handCards.size())) {
            std::cout << "Index " << idx << " is out of range. Skipping." << std::endl;
        } else {
            indexSet.insert(idx);
        }
    }

    // Sort indices in descending order so removal doesn't affect remaining indices
    std::vector indices(indexSet.begin(), indexSet.end());
    std::sort(indices.rbegin(), indices.rend());

    for (int idx : indices) {
        if ( std::vector<Card> currentHand = hand.getCards() ; idx < static_cast<int>(currentHand.size())) {
            Card card = currentHand[idx];
            playedCards.add(card);
            hand.removeCardAt(idx);
        }
    }

    // Draw new cards to refill the hand
    if ( int missingCards = handSize - hand.size() ; missingCards > 0) {
        try {
            for ( CardList newCards = deck.drawNCards(missingCards) ; const Card &c : newCards.getCards()) {
                hand.add(c);
            }
        } catch (const std::exception &e) {
            std::cerr << "Error drawing cards: " << e.what() << std::endl;
        }
    }
    return playedCards;
}