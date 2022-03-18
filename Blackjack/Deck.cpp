#include "Deck.h"

Deck::Deck()
{
	int index{ 0 };
	for (int suit{ 0 }; suit < static_cast<int>(Card::CardSuit::max_suits); ++suit)
	{
		for (int rank{ 0 }; rank < static_cast<int>(Card::CardRank::max_ranks); ++rank)
		{
			m_deck[index] = {static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit)};
			++index;
		}
	}
}

void Deck::printDeck()
{
	for (Card card : m_deck)
	{
		card.printCard();
		std::cout << " ";
	}
	std::cout << "\n";
}

void Deck::shuffleDeck()
{
	std::shuffle(std::begin(m_deck),std::end(m_deck),std::default_random_engine(time(0)));
	m_cardIndex = 0;
}

Card& Deck::dealCard()
{	
	int lenghtOfArray = std::size(m_deck);
	if (m_cardIndex == lenghtOfArray)
	{
		std::cout << "Sory, we're out of cards!\n";
		shuffleDeck();
	};
	return m_deck[m_cardIndex++];

}

Deck::~Deck()
{

}