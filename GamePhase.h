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
  GAME_PHASE_MAX_GAMEPROC    
};

class CGameRound;

class CGamePhase
{
public:
  virtual CGamePhase * Perform() = 0;
protected:
  int m_Phase;
  CGameRound *m_GameRound;
};

class CPreStartPhase: public CGamePhase
{
public:
  CPreStartPhase(CGameRound *gameround);
  virtual CGamePhase * Perform();
};

class CJudgePhase: public CGamePhase
{
public:
  CJudgePhase(CGameRound *gameround);
  virtual CGamePhase * Perform();
};

class CDrawCardPhase: public CGamePhase
{
public:
  CDrawCardPhase(CGameRound *gameround);
  virtual CGamePhase *  Perform();
};

class COutCardPhase: public CGamePhase
{
public:
  COutCardPhase(CGameRound *gameround);
  virtual CGamePhase *  Perform();
};

class CThrowCardPhase: public CGamePhase
{
public:
  CThrowCardPhase(CGameRound *gameround);
  virtual CGamePhase *  Perform();
};

class CAfterThrowCardPhase: public CGamePhase
{
public:
  CAfterThrowCardPhase(CGameRound *gameround);
  virtual CGamePhase *  Perform();
};

class CGameRound
{
public:

  int Init();
  void Run();
  void SetPhase(CGamePhase *phase);

  CGamePhase * GetPreStartPhase() { return m_Phase[GAME_PHASE_PRESTART];}
  CGamePhase * GetJudgePhase() { return m_Phase[GAME_PHASE_JUDGE];}
  CGamePhase * GetDrawCardPhase() { return m_Phase[GAME_PHASE_DRAWCARD];}
  CGamePhase * GetOutCardPhase() { return m_Phase[GAME_PHASE_OUTCARD];}
  CGamePhase * GetThrowCardPhase() { return m_Phase[GAME_PHASE_THROWCARD];}
  CGamePhase * GetAfterThrowCardPhase() { return m_Phase[GAME_PHASE_AFTER_THROWCARD];}
  
protected:
  CGamePhase *m_Phase[MAX_GAMEPROC];
  CGamePhase *m_CurrentPhase;
];

#endif