
#ifndef _PLAYER_H_
#define _PLAYER_H_

#define JUDGEMENT_CARD_TYPE 3 // lighting, no food, sleep
#define EQUIPMENT_CARD_TYPE 4

class CPlayer
{
public:
  CPlayer(CTable *table);
  virtual ~CPlayer();

  void DrawCard(CCard **cards, int num);
  int DisCard();

protected:
  list<CCard *> m_HandCard;
  //CCard *m_JudgementCard[JUDGEMENT_CARD_TYPE];
  list<CCard *> m_JudgementCard;
  CCard *m_EquipmentCard[EQUIPMENT_CARD_TYPE];
  CTable *m_Table;
};

#endif
