#include "Player.h"

Player::Player()
{

}

Player::Player(std::string name, int score)
{
	m_name = name;
	m_score = score;
}

int Player::getScore()
{
	return m_score;
}

int Player::drawCard(Deck& deck)
{
	Card card{deck.dealCard()};
	std::cout << "The card is: ";
	card.printCard();
	std::cout << "\n";
	int value = card.getValue();
	m_score += value;
	return value;
}

bool Player::isBust()
{
	return (m_score > g_maxScore);
}

Player::~Player()
{

}


