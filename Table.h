/*
  Author: Albert
  Date: 20130417
  Description: Table
*/

#ifndef _TABLE_H_
#define _TABLE_H_

class CPlayer;

class CTable
{
public:

  int Init();

  void PlayerJoin(CPlayer *player);
  void StartGame();
  void EndGame();
  
  void ShuffleCards();

  int AskForKill();
  int AskForJink();
  int AskForPeach();

  void PlayerDrawCards(CPlayer *player, int num);
  void PlayerPutCards(CCard **cards, int num);

protected:
  list<CPlayer *> m_Players; // or replace it with playermanager
  CCardHeap m_CardHeap;
};

#endif

