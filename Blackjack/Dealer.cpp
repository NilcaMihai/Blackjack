#include "Dealer.h"

Dealer::Dealer()
{

}

int Dealer::getScore()
{
	return d_score;
}

void Dealer::drawCard(Deck &deck)
{
	system("cls");
	std::cout << "The dealer draw a card!\n";
	Card card{ deck.dealCard() };
	std::cout << "The card is...\n";
	Sleep(1500);
	card.printCard();
	int cardValue = card.getValue();
	d_score += cardValue;
}

Dealer::~Dealer()
{

}