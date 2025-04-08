#ifndef ENUMS_H
#define ENUMS_H

#include <string>
#include <algorithm>

// Rank enum and inline helper functions
enum class Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

inline std::string rankToString( const Rank r) {
    switch(r) {
        case Rank::TWO:   return "TWO";
        case Rank::THREE: return "THREE";
        case Rank::FOUR:  return "FOUR";
        case Rank::FIVE:  return "FIVE";
        case Rank::SIX:   return "SIX";
        case Rank::SEVEN: return "SEVEN";
        case Rank::EIGHT: return "EIGHT";
        case Rank::NINE:  return "NINE";
        case Rank::TEN:   return "TEN";
        case Rank::JACK:  return "JACK";
        case Rank::QUEEN: return "QUEEN";
        case Rank::KING:  return "KING";
        case Rank::ACE:   return "ACE";
    }
    return "";
}

inline int getRankValue( const Rank r) {
    switch(r) {
        case Rank::TWO:   return 2;
        case Rank::THREE: return 3;
        case Rank::FOUR:  return 4;
        case Rank::FIVE:  return 5;
        case Rank::SIX:   return 6;
        case Rank::SEVEN: return 7;
        case Rank::EIGHT: return 8;
        case Rank::NINE:  return 9;
        case Rank::TEN:   return 10;
        case Rank::JACK:  return 11;
        case Rank::QUEEN: return 12;
        case Rank::KING:  return 13;
        case Rank::ACE:   return 14;
    }
    return 0;
}

inline int getRankChips( const Rank r) {
    const int value = getRankValue(r);
    return value == 14 ? 11 : std::min(value, 10);
}

// Suit enum and inline helper functions
enum class Suit { HEARTS, CLUBS, DIAMONDS, SPADES };

inline std::string suitToString( const Suit s) {
    switch(s) {
        case Suit::HEARTS:   return "HEARTS";
        case Suit::CLUBS:    return "CLUBS";
        case Suit::DIAMONDS: return "DIAMONDS";
        case Suit::SPADES:   return "SPADES";
    }
    return "";
}

// Enhancement enum and inline helper functions
enum class Enhancement { NONE, BONUS, MULT, WILD, GLASS, STEEL, STONE, GOLD, LUCKY };

inline std::string enhancementToString( const Enhancement e) {
    switch(e) {
        case Enhancement::NONE:   return "NONE";
        case Enhancement::BONUS:  return "BONUS";
        case Enhancement::MULT:   return "MULT";
        case Enhancement::WILD:   return "WILD";
        case Enhancement::GLASS:  return "GLASS";
        case Enhancement::STEEL:  return "STEEL";
        case Enhancement::STONE:  return "STONE";
        case Enhancement::GOLD:   return "GOLD";
        case Enhancement::LUCKY:  return "LUCKY";
    }
    return "";
}

// Edition enum and inline helper functions
enum class Edition { NONE, FOIL, HOLOGRAPHIC, POLYCHROME, NEGATIVE };

inline std::string editionToString( const Edition ed) {
    switch(ed) {
        case Edition::NONE:         return "NONE";
        case Edition::FOIL:         return "FOIL";
        case Edition::HOLOGRAPHIC:  return "HOLOGRAPHIC";
        case Edition::POLYCHROME:   return "POLYCHROME";
        case Edition::NEGATIVE:     return "NEGATIVE";
    }
    return "";
}

// Seal enum and inline helper functions
enum class Seal { NONE, GOLD, RED, BLUE, PURPLE };

inline std::string sealToString( const Seal s) {
    switch(s) {
        case Seal::NONE:   return "NONE";
        case Seal::GOLD:   return "GOLD";
        case Seal::RED:    return "RED";
        case Seal::BLUE:   return "BLUE";
        case Seal::PURPLE: return "PURPLE";
    }
    return "";
}

#endif // ENUMS_H