
#include "gamephase.h"

CPreStartPhase::CPreStartPhase(CGameRound *gameround): m_Phase(GAME_PHASE_PRESTART), m_GameRound(gameround)
{
}

CGamePhase *  CPreStartPhase::Perform()
{
  return m_GameRound->GetJudgePhase();
}

// ---------------------------------------------------


CJudgePhase::CJudgePhase(CGameRound *gameround): m_Phase(GAME_PHASE_JUDGE), m_GameRound(gameround)
{
}

CGamePhase * CJudgePhase::Perform()
{
  return m_GameRound->GetDrawCardPhase();
}

// ---------------------------------------------------


CDrawCardPhase::CDrawCardPhase(CGameRound *gameround): m_Phase(GAME_PHASE_DRAWCARD), m_GameRound(gameround)
{
}

CGamePhase * CDrawCardPhase::Perform()
{
  return m_GameRound->GetOutCardPhase();
}

// ---------------------------------------------------


COutCardPhase::COutCardPhase(CGameRound *gameround): m_Phase(GAME_PHASE_OUTCARD), m_GameRound(gameround)
{
}

CGamePhase * COutCardPhase::Perform()
{
  return m_GameRound->GetThrowCardPhase();
}

// ---------------------------------------------------


CThrowCardPhase::CThrowCardPhase(CGameRound *gameround): m_Phase(GAME_PHASE_THROWCARD), m_GameRound(gameround)
{
}

CGamePhase * CThrowCardPhase::Perform()
{
  return m_GameRound->SetPhase(m_GameRound->GetAfterThrowCardPhase());
}

// ---------------------------------------------------

CAfterThrowCardPhase::CAfterThrowCardPhase(CGameRound *gameround): m_Phase(GAME_PHASE_AFTER_THROWCARD), m_GameRound(gameround)
{
}

CGamePhase * CAfterThrowCardPhase::Perform()
{
  return NULL;
}


// ---------------------------------------------------

CGameRound::CGameRound(): m_CurrentPhase(NULL)
{
  memset(m_Phase, 0, sizeof(m_Phase));
}

int CGameRound::Init()
{
  m_Phase[GAME_PHASE_PRESTART] = new CPreStartPhase(this);
  if (m_Phase[GAME_PHASE_PRESTART] == NULL)
  	return 0;
  m_Phase[GAME_PHASE_JUDGE] = new CJudgePhase(this);
  if (m_Phase[GAME_PHASE_JUDGE] == NULL)
  	return 0;
  m_Phase[GAME_PHASE_DRAWCARD] = new CDrawCardPhase(this);
  if (m_Phase[GAME_PHASE_DRAWCARD] == NULL)
  	return 0;
  m_Phase[GAME_PHASE_OUTCARD] = new COutCardPhase(this);
  if (m_Phase[GAME_PHASE_OUTCARD] == NULL)
  	return 0;
  m_Phase[GAME_PHASE_THROWCARD] = new CThrowCardPhase(this);
  if (m_Phase[GAME_PHASE_THROWCARD] == NULL)
  	return 0;
  m_Phase[GAME_PHASE_AFTER_THROWCARD] = new CAfterThrowCardPhase(this);
  if (m_Phase[GAME_PHASE_AFTER_THROWCARD] == NULL)
  	return 0;
  m_CurrentPhase = m_Phase[GAME_PHASE_PRESTART];

  return 1;
}

void CGameRound::Run()
{
}

void CGameRound::SetPhase(CGamePhase *phase)
{
  m_CurrentPhase = phase;
}


