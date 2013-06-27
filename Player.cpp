
#include "Player.h"

CPlayer::CPlayer(): m_HealthPoint(0), m_Table(NULL)
{
  memset(m_EquipmentCard, 0, sizeof(m_EquipmentCard));
}

CPlayer::~CPlayer()
{
}

void CPlayer::JoinTable(CTable *table)
{
  m_Table = table;
}

void CPlayer::DrawCard(CCard **cards, int num)
{
  if (cards == NULL || num <= 0)
  	return;
  for (int i = 0; i < num; ++i)
  {
    m_HandCard.push_back(cards[i]);
  }
  return OnDrawCard(cards, num);
}

int CPlayer::DisCard(int num, CCard **cards)
{
  return OnDisCard(num, cards);
}

int CPlayer::DiscardTo(int num, CCard **cards)
{
  return OnDiscardTo(num, cards);
}

