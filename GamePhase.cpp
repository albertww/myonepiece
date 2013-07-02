
#include "gamephase.h"

// --------------------------------------------------

CGamePhase::CGamePhase(CGameRound *gameround): m_GameRound(gameround), m_NextPhase(NULL), m_PrevPhase(NULL)
{
}

void CGamePhase::NextTo(CGamePhase *next)
{
  m_NextPhase = next;
}

void CGamePhase::PrevTo(CGamePhase *prev)
{
  m_PrevPhase = prev;
}

CGamePhase * CGamePhase::GetNextPhase()
{
  return m_NextPhase;
}

CGamePhase * CGamePhase::GetPrevPhase()
{
  return m_PrevPhase;
}

// --------------------------------------------------

CPhaseStack::CPhaseStack(): m_CurrentPhase(NULL)
{
}


int CPhaseStack::OnProc()
{
  if (m_CurrentPhase)
  	return m_CurrentPhase->OnProc();
  return 0;
}

int CPhaseStack::OnResp()
{
  if (m_CurrentPhase)
  	return m_CurrentPhase->OnResp();
  return 0;
}

int CPhaseStack::Push(CGamePhase *phase)
{
  if (m_CurrentPhase == NULL)
  {
    m_CurrentPhase = phase;
	m_CurrentPhase->NextTo(NULL);
	m_CurrentPhase->PrevTo(NULL);
	return 1;
  }
  m_CurrentPhase->NextTo(phase);
  phase->PrevTo(m_CurrentPhase);
  phase->NextTo(NULL);
  m_CurrentPhase = phase;
  return 1;
}

CGamePhase * CPhaseStack::Pop()
{
  if (m_CurrentPhase == NULL)
  {
    return NULL;
  }
  else
  {
    CGamePhase *phase = m_CurrentPhase;
    m_CurrentPhase = m_CurrentPhase->GetPrevPhase();
	if (m_CurrentPhase)
	  m_CurrentPhase->NextTo(NULL);
	phase->NextTo(NULL);
	phase->PrevTo(NULL);
	return phase;
  }
}

int CPhaseStack::IsEmpty()
{
  if (m_CurrentPhase == NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

// --------------------------------------------------

CPreStartPhase::CPreStartPhase(CGameRound *gameround): m_PhaseID(GAME_PHASE_PRESTART), m_GameRound(gameround)
{
}

CGamePhase *  CPreStartPhase::OnProc()
{
  return m_GameRound->SetPhase(m_GameRound->GetJudgePhase());
}

// ---------------------------------------------------


CJudgePhase::CJudgePhase(CGameRound *gameround): m_PhaseID(GAME_PHASE_JUDGE), m_GameRound(gameround)
{
}

CGamePhase * CJudgePhase::OnProc()
{
  return m_GameRound->SetPhase(m_GameRound->GetDrawCardPhase());
}

// ---------------------------------------------------


CDrawCardPhase::CDrawCardPhase(CGameRound *gameround): m_PhaseID(GAME_PHASE_DRAWCARD), m_GameRound(gameround)
{
}

CGamePhase * CDrawCardPhase::OnProc()
{
  return m_GameRound->SetPhase(m_GameRound->GetOutCardPhase());
}

// ---------------------------------------------------


COutCardPhase::COutCardPhase(CGameRound *gameround): m_PhaseID(GAME_PHASE_OUTCARD), m_GameRound(gameround)
{
}

CGamePhase * COutCardPhase::OnProc()
{
  return m_GameRound->SetPhase(m_GameRound->GetThrowCardPhase());
}

// ---------------------------------------------------


CThrowCardPhase::CThrowCardPhase(CGameRound *gameround): m_PhaseID(GAME_PHASE_THROWCARD), m_GameRound(gameround)
{
}

CGamePhase * CThrowCardPhase::OnProc()
{
  return m_GameRound->SetPhase(m_GameRound->GetAfterThrowCardPhase());
}

// ---------------------------------------------------

CAfterThrowCardPhase::CAfterThrowCardPhase(CGameRound *gameround): m_PhaseID(GAME_PHASE_AFTER_THROWCARD), m_GameRound(gameround)
{
}

CGamePhase * CAfterThrowCardPhase::OnProc()
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
    m_CurrentPhase->OnProc();
  }
}

void CGameRound::SetPhase(CGamePhase *phase)
{
  m_CurrentPhase = phase;
}

// ---------------------------------------------------

CQueryPlayerOutCardPhase::CQueryPlayerOutCardPhase()
{
}

int CQueryPlayerOutCardPhase::OnProc()
{
  CTable *table;
  CPlayer *player = table->GetCurrentActivePlayer();
  player->OnOutCard();
}

int CQueryPlayerOutCardPhase::OnResp(void *data, int len)
{
  // PseudoCode switch slash
  CPhaseStack *stack;
  CSlashPhase *nextPhase = new CSlashPhase();
  stack->Push(nextPhase);
  stack->OnProc();
  // ----------------
}

// ---------------------------------------------------

int CSlashPhase::OnProc()
{
  // PseudoCode
  // ask target player for jink
}

int CSlashPhase::OnResp(void *data, int len)
{
  // PseudoCode
  if (nojink)
  {
    player->OnDamage();
  }
  else
  {
    stack->Pop();
	// player have jink the slash is counteract, so back to prev phase ask active player out another card 
	stack->OnProc(); 
  }
  // ------------
}


