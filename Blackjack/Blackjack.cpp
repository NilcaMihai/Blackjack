#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

bool playerTurn(Deck &theDeck, Player &player)
{
	while (true) 
	{
		if (player.isBust())
		{
			return true;
		}
		else
		{
			if (player.hit())
			{
				player.drawCard(theDeck);
				std::cout << "Now you have " << player.getScore() << " points!\n";
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

bool dealerTurn(Deck &theDeck, Dealer &dealer, Player &player)
{
	if (player.getScore() > g_maxScore)
	{
		return false;
	}
	while((dealer.getScore() < g_minimDealerScore) && (dealer.getScore() < player.getScore()))
	{
		Sleep(1500);
		dealer.drawCard(theDeck);
		std::cout << "The dealer has " << dealer.getScore() << " points!\n";
	}
	while ((dealer.getScore() < player.getScore()) && (dealer.getScore() < g_maxScore))
	{
		Sleep(1500);
		dealer.drawCard(theDeck);
		std::cout << "The dealer has " << dealer.getScore() << " points!\n";
	}
	if (dealer.getScore() > g_maxScore)
	{
		std::cout << "The dealer is busted!\n";
		std::cout << "You WIN!!!\n";
		player.paidBet();
		return true;
	}
	if (dealer.getScore() > 10 && dealer.getScore() == player.getScore())
	{
		std::cout << "It is a DRAW!\n";
		player.paidDraw();
		return true;
	}
	std::cout << "You LOSE...\n";
	return false;
}

void playBlackJack(Deck &theDeck, Player &player)
{
	system("cls");
	if (player.getSold() >= 1.0)
	{
		player.bet();

		Dealer dealer{};
		dealer.drawCard(theDeck);
		std::cout << "The dealer has " << dealer.getScore() << " points!\n";

		player.drawCard(theDeck);
		player.drawCard(theDeck);
		std::cout << "You have " << player.getScore() << " points!\n";
		if (player.getScore() == 21)
		{
			std::cout << "You have got a Blackjack!!!\n"
				<< "You WIN!\n";
			player.paidBlackjack();
			return;
		}

		if (playerTurn(theDeck, player))
		{	
			std::cout << "You have " << player.getScore() << " points and the dealer has "
				<< dealer.getScore() << " points!\n";
			std::cout << "You LOSE...\n";
		}
		if (dealerTurn(theDeck, dealer, player))
		{
			std::cout << "Do you dare for another round?\n";
		}
	}
	else
		std::cout << "You don't have money...You must make a deposit!\n";
}

int main()
{
	std::cout << "Welcome to our little Blackjack casino!!!\n";
	std::cout << "What is your name?\n";
	std::string userName;
	std::getline(std::cin, userName);
	Player playerOne{ userName};

	Deck deck{};
	deck.shuffleDeck();

	bool optionPlay{ true };
	while (optionPlay)
	{
		int key;
		std::cout << "Press the key for your desiered option:\n"
			<< "1 - Play a new game!\n"
			<< "2 - Add some money in your cont!\n"
			<< "3 - Check your info!\n"
			<< "9 - End game!\n";
		std::cin >> key;
		switch (key)
		{
		case 1: playBlackJack(deck, playerOne);		break;
		case 2: playerOne.updateSold();				break;
		case 3: playerOne.getInfo();				break;
		default: optionPlay = false; 
			system("cls");
			std::cout << "Thank you for playing!\n";
			break;
		}
	}
}