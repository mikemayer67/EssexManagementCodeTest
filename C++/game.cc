////////////////////////////////////////////////////////////////////////////////
// File: game.cc
//
// Project: C++ implementation of the Essex Management Code Test
//
// Description:
// 
//   This is the main body for playing the game.
//
//   Two players alternate drawing a card from a random deck for a total
//     of three cards each. 
//
//   The players add the point values of their cards (defined as 3*rank
//     for red cards, 2*rank for yellow cards, and the rank itself for green
//     cards).
//
//   The player with the higher score wins.
//
// Change Log:
// 2020.06.10   Mike Mayer   Initial Development
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Deck.h"


int main(int argc,char **argv)
{
  Hand player1;
  Hand player2;

  Deck deck;

  // Each player draws 3 cards, alternating turns

  for(int i=0; i<3; ++i)
  {
    player1.add(deck.deal());
    player2.add(deck.deal());
  }

  // Show what each player drew
  
  std::cout 
    << std::endl
    << "Player 1 drew: " << player1.str() << std::endl
    << "Player 2 drew: " << player2.str() << std::endl
    << std::endl;

  // Show what each player's hand after they have sorted it to their likine
  
  player1.sort(RED,GREEN,YELLOW);
  player2.sort(YELLOW,GREEN,RED);

  std::cout
    << "Player 1 sorted their hand RGY: " << player1.details() << std::endl
    << "Player 2 sorted their hand YGR: " << player2.details() << std::endl
    << std::endl;

  // Evaluate each player's score

  int score1 = player1.score();
  int score2 = player2.score();

  // And announce the winner

  if     ( score1 > score2 ) { std::cout << "Player 1 won " << score1 << " to " << score2 << std::endl; }
  else if( score2 > score1 ) { std::cout << "Player 2 won " << score2 << " to " << score1 << std::endl; }
  else                       { std::cout << "TIE at " << score1 << " points each" << std::endl; }
  std::cout << std::endl;
}

