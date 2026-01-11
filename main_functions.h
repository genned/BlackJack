#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H

#include <iostream>

#include "Card.h"
#include "Player.h"

using namespace std;

inline int num_of_players = 0;
inline int num_of_decks = 0;
inline Player* players;
inline int num_of_chips = 100;
inline int round_counter = 1;
inline bool players_in_play = true;

void setAndGetNumPlayers();
Card* setAndGetNumDecks();
int getNumDecks();
void setPlayerNames();
void gameSetUp(Deck &deck);
void roundOfPlay(Deck &deck);
void dealer();
void setBets();
void playerCards();
void onePlayerCards(int player_number);
void checkChips();
int setRoundSentinel();



#endif //MAIN_FUNCTIONS_H
