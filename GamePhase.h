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
  GAME_PHASE_PRESTART = 0,   // �غϿ�ʼǰ���ɷ��������ܣ��ɴ������Ǽ���
  GAME_PHASE_JUDGE,          // �ж��׶Σ��ɴ����Ž�˾��ܲ����
  GAME_PHASE_DRAWCARD,       // ���ƽ׶Σ��ɴ���ͻϮ����
  GAME_PHASE_OUTCARD,        // ���ƽ׶�
  GAME_PHASE_THROWCARD,      // ���ƽ׶Σ��ɴ����˼�����
  GAME_PHASE_AFTER_THROWCARD, // ���ƺ󣬿ɴ������¼��� 
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