// Card.cpp
#include "../include/Card.h"
#include "../include/Enums.h"
#include <string>
#include <stdexcept>

Card::Card( const Rank rank, const Suit suit, const Enhancement enhancement, const Edition edition, const Seal seal)
    : rank(rank), suit(suit), enhancement(enhancement), edition(edition), seal(seal)
{}

Card::Card( const Rank rank, const Suit suit)
    : rank(rank), suit(suit),
      enhancement(Enhancement::NONE),
      edition(Edition::NONE),
      seal(Seal::NONE)
{}

Rank Card::getRank() const {
    return rank;
}

Suit Card::getSuit() const {
    return suit;
}

Enhancement Card::getEnhancement() const {
    return enhancement;
}

Edition Card::getEdition() const {
    return edition;
}

Seal Card::getSeal() const {
    return seal;
}

void Card::setRank( const Rank r) {
    rank = r;
}

void Card::setSuit( const Suit s) {
    suit = s;
}

void Card::setEnhancement( const Enhancement e) {
    enhancement = e;
}

void Card::setEdition( const Edition ed) {
    edition = ed;
}

void Card::setSeal( const Seal s) {
    seal = s;
}

std::string Card::toString() const {
    char rankChar = 0;
    switch(rank) {
        case Rank::ACE:   rankChar = 'A'; break;
        case Rank::TWO:   rankChar = '2'; break;
        case Rank::THREE: rankChar = '3'; break;
        case Rank::FOUR:  rankChar = '4'; break;
        case Rank::FIVE:  rankChar = '5'; break;
        case Rank::SIX:   rankChar = '6'; break;
        case Rank::SEVEN: rankChar = '7'; break;
        case Rank::EIGHT: rankChar = '8'; break;
        case Rank::NINE:  rankChar = '9'; break;
        case Rank::TEN:   rankChar = 'T'; break;
        case Rank::JACK:  rankChar = 'J'; break;
        case Rank::QUEEN: rankChar = 'Q'; break;
        case Rank::KING:  rankChar = 'K'; break;
    }
    const std::string suitStr = suitToString(suit);
    const char suitChar = suitStr[0];
    return std::string(1, rankChar) + suitChar;
}

bool Card::operator==(const Card &other) const {
    return rank == other.rank && suit == other.suit;
}