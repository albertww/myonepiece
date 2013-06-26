/*
  Author: Albert
  Date: 20130417
  Description: Definition of card
*/

#ifndef _CARD_H_
#define _CARD_H_

#include "DataTypes.h"

#define PACKAGE_STANDARD 1
#define PACKAGE_WARFARE 2

//
enum CardSuits
{
  CARD_SUIT_SPADE, //����
  CARD_SUIT_HEART,     //����
  CARD_SUIT_DIAMOND,   //÷��
  CARD_SUIT_CLUB       //����
};

enum CardPoint
{
  CARD_POINT_TWO,
  CARD_POINT_THREE,
  CARD_POINT_FOUR,
  CARD_POINT_FIVE,
  CARD_POINT_SIX,
  CARD_POINT_SEVEN,
  CARD_POINT_EIGHT,
  CARD_POINT_NINE,
  CARD_POINT_TEN,
  CARD_POINT_JACK,
  CARD_POINT_QUENE,
  CARD_POINT_KING,
  CARD_POINT_ONE
};

enum CardType
{
  CARD_TYPE_BEGIN,
  CARD_TYPE_SLASH, // ɱ
  CARD_TYPE_FIRE_SLASH, // ��ɱ
  CARD_TYPE_THUNDER_SLASH, // ��ɱ
  CARD_TYPE_JINK, // ��
  CARD_TYPE_PEACH, // ��
  CARD_TYPE_WINE, // ��
  CARD_TYPE_BASIC, // -------------------- ������
  CARD_TYPE_ARCHERY, // ����뷢
  CARD_TYPE_ALL_PEACH, // ��԰����
  CARD_TYPE_COLLATERAL,  // �赶ɱ��
  CARD_TYPE_GOOD_HARVEST, // ��ȷ��
  CARD_TYPE_LIGHTING, // ����
  CARD_TYPE_FOOD_SHORTAGE, // �������
  CARD_TYPE_DUEL, // ����
  CARD_TYPE_SAVAGE_INVASION, // ��������
  CARD_TYPE_FORGET_HOME, // �ֲ�˼��
  CARD_TYPE_FIRE_ATTACK, // ��
  CARD_TYPE_OUT_OF_NOTHING, // ��������
  CARD_TYPE_STEAL_SHEEP, // ˳��ǣ��
  CARD_TYPE_BURN_BRIDGE, //  ���Ӳ���
  CARD_TYPE_CHAIN, // ��������
  CARD_TYPE_INVULNERABLE, // ��и�ɻ�
  CARD_TYPE_STRATAGEM, // ---------------- ������
  CARD_TYPE_CROSSBOW, // ����
  CARD_TYPE_DOUBLE_SWORD, // ����˫�ɽ�
  CARD_TYPE_ICE_SWORD, // ������
  CARD_TYPE_QINGGANG_SWORD, // ��ֽ�
  CARD_TYPE_GUDING_SWORD, // �Ŷ���
  CARD_TYPE_QINGLONG_SWORD, // �������µ�
  CARD_TYPE_SNAKE_SPEAR, // ��ì
  CARD_TYPE_INTERSECTING_AXES, // ��ʯ��
  CARD_TYPE_FANGTIAN_HALBERD, // ���컭�
  CARD_TYPE_ROSEFINCH_FAN, // ��ȸ����
  CARD_TYPE_KYLIN_BOW, // ���빭
  CARD_TYPE_EIGHT_DIAGRAM, // ������
  CARD_TYPE_BENEVOLENT_SHIELD, // ������
  CARD_TYPE_SILVER_LION, // ����ʨ��
  CARD_TYPE_RATTAN_ARMOR, // �ټ�
  CARD_TYPE_RED_HORSE, // ����
  CARD_TYPE_DAWAN_HORSE, // ������
  CARD_TYPE_ZIXING_HORSE, // ���U��
  CARD_TYPE_DILU_HORSE, // ��¬
  CARD_TYPE_JUEYING_HORSE, // ��Ӱ
  CARD_TYPE_YELLOWTHUNDER_HORSE, // צ�Ʒɵ�
  CARD_TYPE_HUALIU_HORSE, // ����
  CARD_TYPE_EQUIPMENT // --------------------- װ��
};

// The basic card info
struct CardInfo
{
  uchar m_CardType;
  uchar m_CardSuit;
  uchar m_CardPoint;
};

extern const CardInfo StandardCards[];
extern const CardInfo WarfareCards[];

enum CardState
{
  CARD_STATE_IN_HEAP,
  CARD_STATE_IN_PLAYER,
  CARD_STATE_IN_USED
};

// The card object, include basic card info and some other field that will be used in game
class CCard
{
public:
  CCard();

  uchar GetCardSuit() const { return m_CardInfo.m_CardSuit; }
  void SetCardSuit(uchar cardSuit) { m_CardInfo.m_CardSuit = cardSuit; }
  uchar GetCardPoint() const { return m_CardInfo.m_CardPoint; }
  void SetCardPoint(uchar cardPoint) { m_CardInfo.m_CardPoint = cardPoint; }
  uchar GetCardType() const { return m_CardInfo.m_CardType; }
  void SetCardType(uchar cardType) { m_CardInfo.m_CardType = cardType; }
  ushort GetCardSkillID() const { return m_CardInfo.m_SkillID; }
  void SetCardSkillID(ushort skillID) { m_CardInfo.m_SkillID = skillID; }
  CardInfo GetCardInfo() const { return m_CardInfo; }
  void SetCardInfo(CardInfo &cardInfo) { m_CardInfo = cardInfo; }

  CSkill * GetCardSkill() const { return m_CardSkill; }
  void SetCardSkill(CSkill *skill) { m_CardSkill = skill; }

  uchar GetCardState() const { return m_CardState; };
  void SetCardState(uchar cardState) { m_CardState = cardState; }

protected:
  CardInfo m_CardInfo;
  CSkill *m_CardSkill;
  uchar m_CardState;
};

// Card heap contain all cards, 
class CCardHeap
{
public:
  CCardHeap();
  int Init(int packageMask = PACKAGE_STANDARD);
  void DeInit();
  void Shuffle();
  void ShuffleAll();

  CCard * DrawOneCard();
  void PutOneCard(CCard *card);
  int DrawCards(CCard **cards, int num);
  void PutCards(CCard **cards, int num);

protected:
  int m_CardNum;
  CCard *m_AllCards;
  list<CCard *> m_CardInHeap; // not used, can be drawed by player
  list<CCard *> m_CardInUsed; // discard or used by player
  list<CCard *> m_CardInPlayer; // hand card, installed judgement card or equipment card
  uchar m_CardMask;
};

class CCardArray
{
  
};

#endif
