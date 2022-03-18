#include <iostream>
#include <Windows.h>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

bool hit()
{
	char option{};
	while (true)
	{
		std::cout << "What's your next move:\n"
				  << "Press H - for a new card or S - if you want to stand!\n";
		std::cin >> option;
		if (option == 'h')
			option = 'H';
		if (option == 's')
			option = 'S';
		switch (option)
		{
		case 'H': return true;
		case 'S': return false;
		}
	}
}

bool playerTurn(Deck &theDeck, Player &thePlayer)
{
	while (true) 
	{
		if (thePlayer.isBust())
		{
			std::cout << "You have " << thePlayer.getScore() << " points!\n";
			return true;
		}
		else
		{
			if (hit())
			{
				int playedCard = thePlayer.drawCard(theDeck);
				std::cout << "Now you have " << thePlayer.getScore() << " points!\n";
			}
			else
			{
				std::cout << "The player didn't take risks...\n";
				return false;
			}
		}
	}
	return false;
}

bool dealerTurn(Deck &theDeck, Player &Dealer, Player &thePlayer)
{
	if (thePlayer.getScore() > g_maxScore)
	{
		return false;
	}
	while((Dealer.getScore()< g_minimDealerScore) && (Dealer.getScore()< thePlayer.getScore()))
	{
		std::cout << "The dealer draw a card...\n";
		Sleep(1500);
		Dealer.drawCard(theDeck);
		std::cout << "The dealer has " << Dealer.getScore() << " points!\n";
	}
	while ((Dealer.getScore() < thePlayer.getScore()) && (Dealer.getScore() < g_maxScore))
	{
		std::cout << "The dealer draw a card...\n";
		Sleep(1500);
		Dealer.drawCard(theDeck);
		std::cout << "The dealer has " << Dealer.getScore() << " points!\n";
	}
	if (Dealer.getScore() > g_maxScore)
	{
		std::cout << "The dealer is busted!\n";
		return true;
	}
	std::cout << "You lose!\n";
	return false;
}

void playBlackJack(Deck &theDeck)
{
	Player Dealer{};
	Dealer.drawCard(theDeck);
	std::cout << "The dealer has " << Dealer.getScore() << " points!\n";
	
	Player player{};
	player.drawCard(theDeck);
	player.drawCard(theDeck);
	std::cout << "You have " << player.getScore() << " points!\n";

	if (playerTurn(theDeck, player))
	{
		std::cout << "You lose...\n";
	}
	if (dealerTurn(theDeck, Dealer, player))
	{
		std::cout << "You WIN!\n";
	}
}


int main()
{
	Deck deck{};
	deck.shuffleDeck();
	
	playBlackJack(deck);
	
}