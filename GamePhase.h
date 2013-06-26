/*
  Author: Albert
  Date: 20130419
  Description: The GamePhase is a abstract of game procedure. This kind of game have many procedures such as game 
  pre-start, game start, game end, each procedure also contain sub-procedure. The game procedure may changes 
  frequently, likes TCP status switch, so state pattern is considerable.
*/

#ifndef _GAME_PHASE_H_
#define _GAME_PHASE_H_

enum GamePhase
{
  GAME_PHASE_PRESTART = 0,   // 回合开始前，可发动洛神技能，可触发观星技能
  GAME_PHASE_JUDGE,          // 判定阶段，可触发张角司马懿技能
  GAME_PHASE_DRAWCARD,       // 摸牌阶段，可触发突袭技能
  GAME_PHASE_OUTCARD,        // 出牌阶段
  GAME_PHASE_THROWCARD,      // 弃牌阶段，可触发克己技能
  GAME_PHASE_AFTER_THROWCARD, // 弃牌后，可触发闭月技能 
  GAME_PHASE_MAX_GAMEPHASE    
};

class CTable;
class CGameRound;

class CGamePhase
{
public:
  virtual CGamePhase * Processing() = 0;
protected:
  int m_AllPhases;
  CGameRound *m_GameRound;
};

class CPreStartPhase: public CGamePhase
{
public:
  CPreStartPhase(CGameRound *gameround);
  virtual CGamePhase * Processing();
};

class CJudgePhase: public CGamePhase
{
public:
  CJudgePhase(CGameRound *gameround);
  virtual CGamePhase * Processing();
};

class CDrawCardPhase: public CGamePhase
{
public:
  CDrawCardPhase(CGameRound *gameround);
  virtual CGamePhase * Processing();
};

class COutCardPhase: public CGamePhase
{
public:
  COutCardPhase(CGameRound *gameround);
  virtual CGamePhase * Processing();
};

class CThrowCardPhase: public CGamePhase
{
public:
  CThrowCardPhase(CGameRound *gameround);
  virtual CGamePhase * Processing();
};

class CAfterThrowCardPhase: public CGamePhase
{
public:
  CAfterThrowCardPhase(CGameRound *gameround);
  virtual CGamePhase * Processing();
};

class CGameRound
{
public:
  static CGameRound * CreateGameRound(CTable *table);
  
public:
  CGameRound();
  ~CGameRound();
  int Init(CTable *table);
  void DeInit();

  void Reset();
  void Run();
  void SetPhase(CGamePhase *phase);

  CGamePhase * GetPreStartPhase() { return m_AllPhases[GAME_PHASE_PRESTART];}
  CGamePhase * GetJudgePhase() { return m_AllPhases[GAME_PHASE_JUDGE];}
  CGamePhase * GetDrawCardPhase() { return m_AllPhases[GAME_PHASE_DRAWCARD];}
  CGamePhase * GetOutCardPhase() { return m_AllPhases[GAME_PHASE_OUTCARD];}
  CGamePhase * GetThrowCardPhase() { return m_AllPhases[GAME_PHASE_THROWCARD];}
  CGamePhase * GetAfterThrowCardPhase() { return m_AllPhases[GAME_PHASE_AFTER_THROWCARD];}
  
protected:
  CGamePhase *m_AllPhases[GAME_PHASE_MAX_GAMEPHASE];
  CGamePhase *m_CurrentPhase;
  CTable *m_Table;
];

#endif