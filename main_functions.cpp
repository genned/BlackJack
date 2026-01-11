#include <iostream>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "main_functions.h"

using namespace std;

void setAndGetNumPlayers() {
  cout << "Enter the number of players playing: ";
  cin >> num_of_players;
  num_of_players = num_of_players + 1;
  players = new Player[num_of_players];
  for (int count = 0; count < num_of_players; count++) {
    if (count == 0) {
      players[count].setChips(999);
    }
    else {
      players[count].setChips(num_of_chips);
    }
  }
}

Card* setAndGetNumDecks() {
  cout << "Enter the number of decks that will be used: ";
  cin >> num_of_decks;
  Card* true_size_ptr = new Card[52 * num_of_decks];
  return true_size_ptr;
}

int getNumDecks() {
  return num_of_decks;
}

void setPlayerNames() {
  string temp_player_name;
  for (int count = 0; count < num_of_players; count++) {
    if (count == 0) {
    players[count].setPlayerName("Dealer");
    }
    else {
      cout << "Enter the name of player " << count << ": " << endl;
      cin >> temp_player_name;
      players[count].setPlayerName(temp_player_name);
    }
  }
}

void playerCards() {
  for (int count_outer = 1; count_outer < num_of_players; count_outer++) {
    	if (players[count_outer].hasChips()) {
        	cout << players[count_outer].getPlayerName() << " has a ";
            for (int count_inner = 0; count_inner < players[count_outer].getHand().size(); count_inner++) {
                 cout << players[count_outer].getCard(count_inner).card_info() << ", ";
                 if (count_inner == players[count_outer].getHand().size() - 2) {
                   cout << "and a ";
                 }
            }
          	cout << endl;
    	}
  }
}

void onePlayerCards(int player_number) {
  cout << players[player_number].getPlayerName() << " has a ";
  for (int count_inner = 0; count_inner < players[player_number].getHand().size(); count_inner++) {
  	cout << players[player_number].getCard(count_inner).card_info() << ", ";
    if (count_inner == players[player_number].getHand().size() - 2) {
    	cout << "and a ";
   	}
  }
  cout << endl;
}

void gameSetUp(Deck &deck){
    //hops to Player Class then Deck class
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;
    cout << "Let's start round " << round_counter << endl;
    for (int count = 0; count < num_of_players; count++) {
    	players[count].clearHand();
	}
	for (int count = 0; count < num_of_players; count++) {
          if (players[count].hasChips()) {
          	players[count].drawCard(deck);
            players[count].drawCard(deck);
            players[count].setHandValue();
          }
          else if (!players[count].hasChips()) {
            cout << players[count].getPlayerName() << " is out of chips." << endl;
          }
	}
    cout << "The dealer is showing a " << players[0].getCard(0).card_info() << endl;
	playerCards();
    round_counter++;
}

void roundOfPlay(Deck &deck) {
  int player_choice = 0;
	for (int count = 1; count < num_of_players; count++) {
        if (players[count].hasChips()) {
			cout << "It's " << players[count].getPlayerName() << "'s turn" << endl;
            while (players[count].getHandValue() < 22) {
        		cout << "1) Hit  2) Stand  3) Hand" << endl;
        		cin >> player_choice;
        		if (player_choice == 1) {
          			players[count].drawCard(deck);
          			onePlayerCards(count);
                    players[count].setHandValue();
        		}
            	else if (player_choice == 2) {
              		break;
            	}
            	else if (player_choice == 3) {
                  onePlayerCards(count);
                  cout << players[count].getPlayerName() << "'s hand value is " << players[count].getHandValue() << endl;
            	}
            }
        	if (players[count].getHandValue() > 21) {
                  cout << players[count].getPlayerName() << " busted!" << endl;
        	}
        }
	}
    onePlayerCards(0);
    while (players[0].getHandValue() < 17) {
    	players[0].drawCard(deck);
    	onePlayerCards(0);
        players[0].setHandValue();
    }
    if (players[0].getHandValue() > 21) {
      cout << players[0].getPlayerName() << " busted!" << endl;
      for (int count = 1; count < num_of_players; count++) {
        if (players[count].hasChips()) {
          if (players[count].getHandValue() < 22) {
            cout << players[count].getPlayerName() << " beat the dealer and gets " << players[count].getRoundBet()<< endl;
            players[count].setChips(players[count].getChips() + (players[count].getRoundBet() * 2));
          }
          else {
            cout << players[count].getPlayerName() << " pushes" << endl;
            players[count].setChips(players[count].getChips() + (players[count].getRoundBet()));
          }
        }
      }
    }
	else {
      for (int count = 1; count < num_of_players; count++) {
        if (players[count].hasChips()) {
          if (players[count].getHandValue() > players[0].getHandValue() && players[count].getHandValue() < 22) {
            cout << players[count].getPlayerName() << " beat the Dealer and gets " << players[count].getRoundBet()<< endl;
            players[count].setChips(players[count].getChips() + (players[count].getRoundBet() * 2));
          }
          else if (players[count].getHandValue() == players[0].getHandValue()) {
            cout << players[count].getPlayerName() << " pushes" << endl;
            players[count].setChips(players[count].getChips() + (players[count].getRoundBet()));
          }
          else if (players[count].getHandValue() < players[0].getHandValue()) {
            cout << players[count].getPlayerName() << " loses to the Dealer" << endl;
          }
        }
      }
	}
}

void setBets() {
  for (int count = 1; count < num_of_players; count++) {
    if (players[count].hasChips()) {
      cout << players[count].getPlayerName() << " has " <<players[count].getChips() << " chips" << endl;
      cout << "How much does " << players[count].getPlayerName() << " wish to bet?" << endl;
      int temp_bet;
      cin >> temp_bet;
      players[count].setRoundBet(temp_bet);
    }
  }
}

int setRoundSentinel() {
  int temp_sent = 0;
  cout << "1) Play Another round  2) Reset  3) Exit" << endl;
  cin >> temp_sent;
  return temp_sent;
}

void checkChips() {
  int chip_total = 0;
  for (int count = 1; count < num_of_players; count++) {
    if (players[count].hasChips()) {
      chip_total = chip_total + players[count].getChips();
    }
  }
  if (chip_total == 0) {
    players_in_play = false;
  }
}