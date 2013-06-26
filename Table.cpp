
#include "Table.h"

int CTable::Init()
{
  if (m_CardHeap.Init() == 0)
  	return 0;
  return 1;
}

CTable::ShuffleCards()
{
  m_CardHeap.Shuffle();
}

int CTable::PlayerDrawCards(CPlayer *player, int num)
{
  CCard **cards = new CCard*[num];
  m_CardHeap.DrawCards(cards, num);
  player->DrawCard(cards, num);
  delete [] cards;
}

void CTable::PlayerPutCards(CCard **cards, int num)
{
  m_CardHeap.PutCards(cards, num);
}
