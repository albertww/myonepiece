
#ifndef _PLAYER_H_
#define _PLAYER_H_

#define JUDGEMENT_CARD_TYPE 3 // lighting, no food, sleep
#define EQUIPMENT_CARD_TYPE 4

class CPlayer
{
public:
  CPlayer();
  virtual ~CPlayer();

  void JoinTable(CTable *table);
  void StartGame();
  void OnStartGame();
  void DrawCard(CCard **cards, int num);
  virtual void OnDrawCard(CCard **cards, int num);
  /* 
    user discard hand card
    @param num, number of cards to discard
    @param cards, input&output, pointer to cards that user discard
    @return, number of cards discard
  */
  int DisCard(int num, CCard **cards);
  virtual int OnDisCard(int num, CCard **cards);
  /* 
    user should only keep num cards in hand, discard redundant
    @param num, number of cards to remain in hand
    @param cards, input&output, pointer to cards that user discard
    @return, number of cards discard
  */
  int DiscardTo(int num, CCard **cards);
  virtual int OnDiscardTo(int num, CCard **cards);

  virtual void OnOutCard();

  int AttackDistance();
  int Distance();

protected:
  list<CCard *> m_HandCard;
  //CCard *m_JudgementCard[JUDGEMENT_CARD_TYPE];
  list<CCard *> m_JudgementCard;
  CCard *m_EquipmentCard[EQUIPMENT_CARD_TYPE];
  CTable *m_Table;
  map<int, CSkill *> m_Skills;
  uchar m_HealthPoint;
  
};

class CClientPlayer: public CPlayer
{
  
};

#endif
