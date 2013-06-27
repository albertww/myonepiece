
#include "Table.h"

CTable::CTable(): m_CardHeap(NULL), m_GameRound(NULL)
{
}

CTable::~CTable()
{
  DeInit();
}


int CTable::Init()
{
  m_CardHeap = CCardHeap::CreateCardHeap(PACKAGE_STANDARD | PACKAGE_WARFARE);
  if (m_CardHeap == NULL)
  	return 0;
  m_GameRound = CGameRound::CreateGameRound(this);
  if (m_GameRound == NULL)
  	return 0;
  return 1;
}

void CTable::DeInit()
{
  if (m_CardHeap != NULL)
  {
	delete m_CardHeap;
	m_CardHeap = NULL;
  }
  if (m_GameRound != NULL)
  {
    delete m_GameRound;
	m_GameRound = NULL;
  }
}

void CTable::PlayerJoin(CPlayer *player)
{
}

void CTable::BeginGame()
{
}

void CTable::PlayGame()
{
  m_GameRound->Run();
}

void CTable::EndGame()
{
}

CTable::ShuffleCards()
{
  m_CardHeap->Shuffle();
}

int CTable::PlayerDrawCards(CPlayer *player, int num)
{
  CCard **cards = new CCard*[num];
  m_CardHeap->DrawCards(cards, num);
  player->DrawCard(cards, num);
  delete [] cards;
}

void CTable::PlayerPutCards(CCard **cards, int num)
{
  m_CardHeap->PutCards(cards, num);
}
