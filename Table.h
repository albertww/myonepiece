/*
  Author: Albert
  Date: 20130417
  Description: Table
*/

#ifndef _TABLE_H_
#define _TABLE_H_

#include "GamePhase.h"

class CPlayer;

struct ScenePlayer
{
  
};

class CGameScene
{
public:
  
};

class CTable
{
public:
  CTable();
  ~CTable();

  int Init();
  void DeInit();

  void PlayerJoin(CPlayer *player);
  void BeginGame();
  void PlayGame();
  void EndGame();
  
  void ShuffleCards();

  int AskForKill();
  int AskForJink();
  int AskForPeach();

  void PlayerDrawCards(CPlayer *player, int num);
  void PlayerPutCards(CCard **cards, int num);

protected:
  list<CPlayer *> m_Players; // or replace it with playermanager
  CCardHeap *m_CardHeap;
  CGameRound *m_GameRound;
};

#endif

