////////////////////////////////////////////////////////////////////////////////
// File: Hand.cc
//
// Project: C++ implementation of the Essex Management Code Test
//
// Description: (Refer to header file)
//
// Change Log:
// 2020.06.10   Mike Mayer   Initial Development
////////////////////////////////////////////////////////////////////////////////

#include "Hand.h"
#include "CardComparator.h"

#include <iostream>
#include <sstream>

//------------------------------------------------------------------------------
// Hand constructor #2 - initial cards specified
//------------------------------------------------------------------------------

Hand::Hand(const Cards &cards)
{
  _cards.insert(_cards.end(), cards.begin(), cards.end());
}

//------------------------------------------------------------------------------
// add() - append a card to the end of the hand
//------------------------------------------------------------------------------
void Hand::add(const Card &card)
{
  _cards.push_back(card);
}

//------------------------------------------------------------------------------
// sort(Suit,Suit,Suit) - sorts the hand based on the specified suit order
//   the three specified suits must all be unique
//   if two cards are of same suit, the rank is used (in ascending value)
//------------------------------------------------------------------------------ 

void Hand::sort(Suit suit1, Suit suit2, Suit suit3)
{
  assert( suit1 != suit2);
  assert( suit1 != suit3);
  assert( suit2 != suit3);

  std::sort(_cards.begin(), _cards.end(), CardComparator(suit1,suit2,suit3) );
}

//------------------------------------------------------------------------------
// str() - string representation of the hand showing all cards in order
//------------------------------------------------------------------------------
std::string Hand::str() const
{
  std::stringstream s;

  Cards::const_iterator it = _cards.begin();

  if( it != _cards.end() ) 
  {
    s << *it;
  
    for( ++it; it!=_cards.end(); ++it)
    {
      s << ' ' << *it;
    }
  }

  return s.str();
}

//------------------------------------------------------------------------------
// details() - string representation of the hand showing all cards with points
//------------------------------------------------------------------------------
std::string Hand::details() const
{
  std::stringstream s;

  Cards::const_iterator it = _cards.begin();

  if( it != _cards.end() ) 
  {
    s << *it << "(" << it->pointValue() << ")";
  
    for( ++it; it!=_cards.end(); ++it)
    {
      s << ' ' << *it << "(" << it->pointValue() << ")";
    }
  }

  return s.str();
}

//------------------------------------------------------------------------------
// score() - total points in the hand
//------------------------------------------------------------------------------
int Hand::score() const
{
  int rval = 0;

  for( Cards::const_iterator it = _cards.begin(); it != _cards.end(); ++it )
  {
    rval += it->pointValue();
  }

  return rval;
}


