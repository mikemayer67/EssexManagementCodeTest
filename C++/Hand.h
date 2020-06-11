////////////////////////////////////////////////////////////////////////////////
// File: Hand.h
//
// Project: C++ implementation of the Essex Management Code Test
//
// Description:
// 
//   This class defines a collection of 0 or more Card instances.
//
//   Note: there is no assumption that each card in the hand must be unique.
//     It is up to the "game" to determine the rules by which a hand will be
//     constructed.
//
//   The sort method is provided to rearrange the cards in the hand into
//     a sorted order.  The sort order of the suits must be specified.
//     For cards of equal suit, the rank (in ascening value is used to 
//     determine sort order
//
// Change Log:
// 2020.06.10   Mike Mayer   Initial Development
////////////////////////////////////////////////////////////////////////////////

#ifndef _HAND_H_
#define _HAND_H_

#include <vector>

#include "Card.h"

//------------------------------------------------
// define Cards type for improved readability

typedef std::vector<Card> Cards;

//------------------------------------------------

class Hand
{
  public:

    // Constructor #1 - Empty hand
    Hand() {}

    // Constructor #2 - Initial cards specified
    Hand(const Cards &cards);

    // add - appends the card to the hand
    //   new card will be added to the end of the hand
    void add(const Card &card);

    // sort - sorts the cards using the specified suit order
    void sort(Suit suit1, Suit suit2, Suit suit3);

    // string representation of the cards in the hand (in order)
    std::string str() const;

    // string representation of the cards in the hand with point values
    std::string details() const;

    // score - total value of the hand (sum of points)
    int score() const;


  protected:   // we're going to subclass Deck as a specialized type of Hand

    Cards _cards;
};

#endif // _HAND_H_
