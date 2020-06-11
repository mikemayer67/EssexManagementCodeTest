////////////////////////////////////////////////////////////////////////////////
// File: Card.h
//
// Project: C++ implementation of the Essex Management Code Test
//
// Description:
// 
//   This class defines a single playing card to be used in the game.
//   It consists of a suit (color) and rank (non-negative integer).
//
//   Each card has an implicit value defined as:
//         red cards: 3 x rank
//      yellow cards: 2 x rank
//       green cards: 1 x rank
//
// Change Log:
// 2020.06.10   Mike Mayer   Initial Development
////////////////////////////////////////////////////////////////////////////////

#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>

//------------------------------------------------------------------------------
// Card Suit
//------------------------------------------------------------------------------

enum Suit { RED, YELLOW, GREEN };

inline std::ostream &operator<<(std::ostream &s, Suit suit)
{
  s << (suit==RED    ? "R" : 
        suit==YELLOW ? "Y" : 
        suit==GREEN  ? "G" : "?");
  return s;
}

//------------------------------------------------------------------------------
// Card class
//------------------------------------------------------------------------------

class Card
{
  public:
    typedef short int                   Rank;

    // Constructor requires specifying suit and rank
    // 
    // Specifying a rank outside the range 0-9 will result in a 
    //     thrown integer equal to invalid rank

    Card(Suit, Rank);

    // Copy constructor (needed for STL containers)

    Card(const Card &ref) 
      : _suit(ref._suit), _rank(ref._rank), _pointValue(ref._pointValue)
    {}

    // equality operator 
    //   return true if both suit/rank match referenced card
    //   return false otherwise
    bool operator==(const Card &other)
    {
      return ( _suit == other._suit ) && ( _rank == other._rank );
    }

    // getter methods for the cards suit and rank
    Suit suit(void) const { return _suit; }
    Rank rank(void) const { return _rank; }
    
    // card's implicit value (computed during construction)
    int pointValue() const { return _pointValue; }

    // string representation of the rank/suit of the card (e.g. 5R, 3G, 2Y)
    std::string str() const;

  private:
    Suit _suit;
    Rank _rank;

    int  _pointValue;
};

inline std::ostream &operator<<(std::ostream &s, const Card &card) { s << card.str(); return s; }

#endif // _CARD_H_
