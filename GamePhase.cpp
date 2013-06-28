
#include "gamephase.h"

CPreStartPhase::CPreStartPhase(CGameRound *gameround): m_AllPhases(GAME_PHASE_PRESTART), m_GameRound(gameround)
{
}

CGamePhase *  CPreStartPhase::Processing()
{
  return m_GameRound->SetPhase(m_GameRound->GetJudgePhase());
}

// ---------------------------------------------------


CJudgePhase::CJudgePhase(CGameRound *gameround): m_AllPhases(GAME_PHASE_JUDGE), m_GameRound(gameround)
{
}

CGamePhase * CJudgePhase::Processing()
{
  return m_GameRound->SetPhase(m_GameRound->GetDrawCardPhase());
}

// ---------------------------------------------------


CDrawCardPhase::CDrawCardPhase(CGameRound *gameround): m_AllPhases(GAME_PHASE_DRAWCARD), m_GameRound(gameround)
{
}

CGamePhase * CDrawCardPhase::Processing()
{
  return m_GameRound->SetPhase(m_GameRound->GetOutCardPhase());
}

// ---------------------------------------------------


COutCardPhase::COutCardPhase(CGameRound *gameround): m_AllPhases(GAME_PHASE_OUTCARD), m_GameRound(gameround)
{
}

CGamePhase * COutCardPhase::Processing()
{
  return m_GameRound->SetPhase(m_GameRound->GetThrowCardPhase());
}

// ---------------------------------------------------


CThrowCardPhase::CThrowCardPhase(CGameRound *gameround): m_AllPhases(GAME_PHASE_THROWCARD), m_GameRound(gameround)
{
}

CGamePhase * CThrowCardPhase::Processing()
{
  return m_GameRound->SetPhase(m_GameRound->GetAfterThrowCardPhase());
}

// ---------------------------------------------------

CAfterThrowCardPhase::CAfterThrowCardPhase(CGameRound *gameround): m_AllPhases(GAME_PHASE_AFTER_THROWCARD), m_GameRound(gameround)
{
}

CGamePhase * CAfterThrowCardPhase::Processing()
{
  return NULL;
}


// ---------------------------------------------------

CGameRound * CGameRound::CreateGameRound(CTable *table)
{
  CGameRound *gameRound = new CGameRound();
  if (gameRound != NULL)
  {
    if (gameRound->Init(table))
    {
      return gameRound;
    }
  }
  return NULL;
}


CGameRound::CGameRound(): m_CurrentPhase(NULL), m_Table(NULL)
{

}

CGameRound::~CGameRound()
{
  DeInit();
}

int CGameRound::Init(CTable *table)
{
  if (table == NULL)
  	return 0;

  DeInit();
  
  m_Table = table;
  
  m_AllPhases[GAME_PHASE_PRESTART] = new CPreStartPhase(this);
  if (m_AllPhases[GAME_PHASE_PRESTART] == NULL)
  	return 0;
  m_AllPhases[GAME_PHASE_JUDGE] = new CJudgePhase(this);
  if (m_AllPhases[GAME_PHASE_JUDGE] == NULL)
  	return 0;
  m_AllPhases[GAME_PHASE_DRAWCARD] = new CDrawCardPhase(this);
  if (m_AllPhases[GAME_PHASE_DRAWCARD] == NULL)
  	return 0;
  m_AllPhases[GAME_PHASE_OUTCARD] = new COutCardPhase(this);
  if (m_AllPhases[GAME_PHASE_OUTCARD] == NULL)
  	return 0;
  m_AllPhases[GAME_PHASE_THROWCARD] = new CThrowCardPhase(this);
  if (m_AllPhases[GAME_PHASE_THROWCARD] == NULL)
  	return 0;
  m_AllPhases[GAME_PHASE_AFTER_THROWCARD] = new CAfterThrowCardPhase(this);
  if (m_AllPhases[GAME_PHASE_AFTER_THROWCARD] == NULL)
  	return 0;
  m_CurrentPhase = m_AllPhases[GAME_PHASE_PRESTART];

  return 1;
}

void CGameRound::DeInit()
{
  m_CurrentPhase = NULL;
  m_Table = NULL;
  
  if (m_AllPhases[GAME_PHASE_PRESTART] != NULL)
  {
    delete m_AllPhases[GAME_PHASE_PRESTART];
  }
  
  if (m_AllPhases[GAME_PHASE_JUDGE] == NULL)
  {
    delete m_AllPhases[GAME_PHASE_JUDGE];
  }
  
  if (m_AllPhases[GAME_PHASE_DRAWCARD] == NULL)
  {
    delete m_AllPhases[GAME_PHASE_DRAWCARD];
  }
  
  if (m_AllPhases[GAME_PHASE_OUTCARD] == NULL)
  {
    delete m_AllPhases[GAME_PHASE_OUTCARD];
  }
  
  if (m_AllPhases[GAME_PHASE_THROWCARD] == NULL)
  {
    delete m_AllPhases[GAME_PHASE_THROWCARD];
  }
  
  if (m_AllPhases[GAME_PHASE_AFTER_THROWCARD] == NULL)
  {
    delete m_AllPhases[GAME_PHASE_AFTER_THROWCARD];
  }

  memset(m_AllPhases, 0, sizeof(m_AllPhases));
}

void CGameRound::Reset()
{
  //m_CurrentPhase = m_AllPhases[GAME_PHASE_PRESTART];
  SetPhase(GAME_PHASE_PRESTART);
}

void CGameRound::Run()
{
  while (m_CurrentPhase != NULL)
  {
    m_CurrentPhase->Processing();
  }
}

void CGameRound::SetPhase(CGamePhase *phase)
{
  m_CurrentPhase = phase;
}


