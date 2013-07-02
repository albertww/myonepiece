/*
  Author: Albert
  Date: 20130419
  Description: The GamePhase is a abstract of game procedure. This kind of game have many procedures such as game 
  pre-start, game start, game end, each procedure also contain sub-procedure. The game procedure may changes 
  frequently, likes TCP status switch, so state pattern is considerable.
*/

#ifndef _GAME_PHASE_H_
#define _GAME_PHASE_H_

enum GameRoundPhase
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
  CGamePhase(CGameRound *gameround);
  virtual ~CGamePhase();
  virtual int Init();
  virtual CGamePhase * OnProc() = 0;
  virtual CGamePhase * OnResp() = 0;
  
  // On Process
  virtual int OnProc();
  // On Response
  virtual int OnResp();
  
  void NextTo(CGamePhase *next);
  void PrevTo(CGamePhase *prev);
  CGamePhase * GetNextPhase();
  CGamePhase * GetPrevPhase();
protected:
  int m_PhaseID;
  CGameRound *m_GameRound;
  CGamePhase *m_NextPhase;
  CGamePhase *m_PrevPhase;
};

class CPhaseStack
{
public:
  CPhaseStack();
  int OnProc();
  int OnResp();
  int Push(CGamePhase *phase);
  CGamePhase * Pop();
  int IsEmpty();
protected:
  CGamePhase *m_CurrentPhase;
};

class CPreStartPhase: public CGamePhase
{
public:
  CPreStartPhase(CGameRound *gameround);
  virtual CGamePhase * OnProc();
};

class CJudgePhase: public CGamePhase
{
public:
  CJudgePhase(CGameRound *gameround);
  virtual CGamePhase * OnProc();
};

class CDrawCardPhase: public CGamePhase
{
public:
  CDrawCardPhase(CGameRound *gameround);
  virtual CGamePhase * OnProc();
};

class COutCardPhase: public CGamePhase
{
public:
  COutCardPhase(CGameRound *gameround);
  virtual CGamePhase * OnProc();
};

class CThrowCardPhase: public CGamePhase
{
public:
  CThrowCardPhase(CGameRound *gameround);
  virtual CGamePhase * OnProc();
};

class CAfterThrowCardPhase: public CGamePhase
{
public:
  CAfterThrowCardPhase(CGameRound *gameround);
  virtual CGamePhase * OnProc();
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

// Query player's action when outcard phase
// He can outcard or use a skill
class CQueryPlayerOutCardPhase: public CGamePhase
{
public:
  CQueryPlayerOutCardPhase();
  virtual ~CQueryPlayerOutCardPhase();
  /*
    send outcard message to player and set timer, if the response from player or timer is coming
    call OnResp to process it
  */
  virtual int OnProc();
  /*
    There are 3 type of player action returned
    1 The player giveup, so go to the next gamephase
    2 Player outcard
    3 Player use an active skill
  */
  virtual int OnResp(void *data, int len);

};

class CSlashPhase: public CGamePhase
{
public:
  CSlashPhase();
  virtual ~CSlashPhase();
  
  virtual int OnProc();
  virtual int OnResp(void *data, int len);
};

#endif