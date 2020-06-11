////////////////////////////////////////////////////////////////////////////////
// File: Card.cc
//
// Project: C++ implementation of the Essex Management Code Test
//
// Description: (Refer to header file)
//
// Change Log:
// 2020.06.10   Mike Mayer   Initial Development
////////////////////////////////////////////////////////////////////////////////

#include "Card.h"

#include <iostream>
#include <sstream>

//------------------------------------------------------------------------------
// Card constructor
//   verify that the rank is in range
//   use of enum for suit should suffice (we're assuming no attempt at subterfuge)
//   evalute card's point value
//------------------------------------------------------------------------------

Card::Card(Suit suit, Rank rank) : _suit(suit), _rank(rank)
{
  // validate that the rank is in range... owtherwise throw the bad rank
  //   (yes, this is rather simplistic, buf this exercise that should be sufficient)

  if(rank < 0 || rank > 9) throw rank;

  // assing point value based on suit and rank
  switch( suit )
  {
    case RED:    _pointValue = 3 * rank; break;
    case YELLOW: _pointValue = 2 * rank; break;
    case GREEN:  _pointValue =     rank; break;
  }
}

//------------------------------------------------------------------------------
// str() - string representation of the card (rank/suit)
//------------------------------------------------------------------------------
std::string Card::str() const
{
  std::stringstream s;
  s << _rank << _suit;
  return s.str();
}
