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
  CARD_SUIT_SPADE, //黑桃
  CARD_SUIT_HEART,     //红桃
  CARD_SUIT_DIAMOND,   //梅花
  CARD_SUIT_CLUB       //方块
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
  CARD_TYPE_SLASH, // 杀
  CARD_TYPE_FIRE_SLASH, // 火杀
  CARD_TYPE_THUNDER_SLASH, // 雷杀
  CARD_TYPE_JINK, // 闪
  CARD_TYPE_PEACH, // 桃
  CARD_TYPE_WINE, // 酒
  CARD_TYPE_BASIC, // -------------------- 基本牌
  CARD_TYPE_ARCHERY, // 万箭齐发
  CARD_TYPE_ALL_PEACH, // 桃园结义
  CARD_TYPE_COLLATERAL,  // 借刀杀人
  CARD_TYPE_GOOD_HARVEST, // 五谷丰登
  CARD_TYPE_LIGHTING, // 闪电
  CARD_TYPE_FOOD_SHORTAGE, // 兵粮寸断
  CARD_TYPE_DUEL, // 决斗
  CARD_TYPE_SAVAGE_INVASION, // 南蛮入侵
  CARD_TYPE_FORGET_HOME, // 乐不思蜀
  CARD_TYPE_FIRE_ATTACK, // 火攻
  CARD_TYPE_OUT_OF_NOTHING, // 无中生有
  CARD_TYPE_STEAL_SHEEP, // 顺手牵羊
  CARD_TYPE_BURN_BRIDGE, //  过河拆桥
  CARD_TYPE_CHAIN, // 铁索连环
  CARD_TYPE_INVULNERABLE, // 无懈可击
  CARD_TYPE_STRATAGEM, // ---------------- 锦囊牌
  CARD_TYPE_CROSSBOW, // 连弩
  CARD_TYPE_DOUBLE_SWORD, // 雌雄双股剑
  CARD_TYPE_ICE_SWORD, // 寒冰剑
  CARD_TYPE_QINGGANG_SWORD, // 青钢剑
  CARD_TYPE_GUDING_SWORD, // 古锭刀
  CARD_TYPE_QINGLONG_SWORD, // 青龙偃月刀
  CARD_TYPE_SNAKE_SPEAR, // 蛇矛
  CARD_TYPE_INTERSECTING_AXES, // 贯石斧
  CARD_TYPE_FANGTIAN_HALBERD, // 方天画戟
  CARD_TYPE_ROSEFINCH_FAN, // 朱雀羽扇
  CARD_TYPE_KYLIN_BOW, // 麒麟弓
  CARD_TYPE_EIGHT_DIAGRAM, // 八卦阵
  CARD_TYPE_BENEVOLENT_SHIELD, // 仁王盾
  CARD_TYPE_SILVER_LION, // 白银狮子
  CARD_TYPE_RATTAN_ARMOR, // 藤甲
  CARD_TYPE_RED_HORSE, // 赤兔
  CARD_TYPE_DAWAN_HORSE, // 大宛马
  CARD_TYPE_ZIXING_HORSE, // 紫骍马
  CARD_TYPE_DILU_HORSE, // 的卢
  CARD_TYPE_JUEYING_HORSE, // 绝影
  CARD_TYPE_YELLOWTHUNDER_HORSE, // 爪黄飞电
  CARD_TYPE_HUALIU_HORSE, // 骅骝
  CARD_TYPE_EQUIPMENT // --------------------- 装备
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
