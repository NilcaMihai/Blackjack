#include "Player.h"

Player::Player()
{

}

Player::Player(std::string name, float sold, int score)
{
	m_name = name;
	m_sold = sold;
	m_score = score;
}

int Player::getScore()
{
	return m_score;
}

void Player::resetScore()
{
	m_score = 0;
}

float Player::getSold()
{
	return m_sold;
}

int Player::getNumberOfGamesPlayed()
{
	return m_numberOfGamesPlayed;
}

int Player::getNumberOfVictories()
{
	return m_numberOfVictories;
}

void Player::updateSold()
{
	system("cls");
	bool askedOption{ true };
	float addMoney{ 0 };
	while (askedOption)
	{
		std::cout << "How much money do you want to add to your cont?\n";
		std::cin >> addMoney;
		if (addMoney > 0.0)
			askedOption = false;
	}
	m_sold += addMoney;
}

void Player::getInfo()
{
	system("cls");
	std::cout << "Hello " << m_name << "!\n";
	std::cout << "Your cont balance is " << m_sold << "$.\n";
	if (getNumberOfGamesPlayed() == 0)
	{
		std::cout << "You didn't played any game!\n";
	}
	else if (getNumberOfGamesPlayed() == 1)
	{
		if (getNumberOfVictories() == 1)
			std::cout << "You played 1 round and you won it!\n";
		else
			std::cout << "You played 1 round but you lost!\n";

	}
	else
	{
		std::cout << "You played " << getNumberOfGamesPlayed() << " rounds and you won "
			<< getNumberOfVictories() << " of them!\n";
	}
}

void Player::drawCard(Deck &deck)
{
	std::cout << "You get a card...\n";
	Card card{deck.dealCard()};
	std::cout << "The card is: ";
	Sleep(1500);
	card.printCard();
	int value = card.getValue();
	m_score += value;
}

bool Player::hit()
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

bool Player::isBust()
{
	return (m_score > g_maxScore);
}

void Player::bet()
{
	system("cls");
	resetScore();
	bool betOK = false;
	while (!betOK)
	{
		std::cout << "How much do you want to bet?\n";
		std::cin >> m_betMoney;
		if (m_betMoney <= m_sold)
		{
			if (m_betMoney >= 1.0)
			{
				betOK = true;
				std::cout << "The bet is made!\n";
			}
			else
				std::cout << "The minimum bet is 1$.\n";
		}
		else
			std::cout << "Sorry! You don't have so much money...\n"
			<< "Your cont balance is " << m_sold << "$\n";
	}
	m_sold -= m_betMoney;
	++m_numberOfGamesPlayed;
	Sleep(1000);
}

void Player::paidBet()
{
	m_betMoney *= 2;
	m_sold += m_betMoney;
	++m_numberOfVictories;
}

void Player::paidBlackjack()
{
	m_betMoney *= 2.5;
	m_sold += m_betMoney;
	++m_numberOfVictories;
}

void Player::paidDraw()
{
	m_sold += m_betMoney;
}

Player::~Player()
{

}