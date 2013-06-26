#include "Card.h"

const CardInfo StandardCards[] = 
{
  
  {TYPE_SLASH, SUIT_CLUB, POINT_SIX},
  {TYPE_SLASH, SUIT_CLUB, POINT_SEVEN},
  {TYPE_SLASH, SUIT_CLUB, POINT_EIGHT},
  {TYPE_SLASH, SUIT_CLUB, POINT_NINE},
  {TYPE_SLASH, SUIT_CLUB, POINT_TEN},
  {TYPE_SLASH, SUIT_CLUB, POINT_KING},
  {TYPE_SLASH, SUIT_SPADE, POINT_SEVEN},
  {TYPE_SLASH, SUIT_SPADE, POINT_EIGHT},
  {TYPE_SLASH, SUIT_SPADE, POINT_EIGHT},
  {TYPE_SLASH, SUIT_SPADE, POINT_NINE},
  {TYPE_SLASH, SUIT_SPADE, POINT_NINE},
  {TYPE_SLASH, SUIT_SPADE, POINT_TEN},
  {TYPE_SLASH, SUIT_SPADE, POINT_TEN},
  {TYPE_SLASH, SUIT_HEART, POINT_TEN},
  {TYPE_SLASH, SUIT_HEART, POINT_TEN},
  {TYPE_SLASH, SUIT_HEART, POINT_JACK},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_TWO},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_THREE},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_FOUR},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_FIVE},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_SIX},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_SEVEN},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_EIGHT},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_EIGHT},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_NINE},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_NINE},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_TEN},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_TEN},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_JACK},
  {TYPE_SLASH, SUIT_DIAMOND, POINT_JACK},
  {TYPE_JINK, SUIT_CLUB, POINT_TWO},
  {TYPE_JINK, SUIT_CLUB, POINT_TWO},
  {TYPE_JINK, SUIT_CLUB, POINT_THREE},
  {TYPE_JINK, SUIT_CLUB, POINT_FOUR},
  {TYPE_JINK, SUIT_CLUB, POINT_FIVE},
  {TYPE_JINK, SUIT_CLUB, POINT_SIX},
  {TYPE_JINK, SUIT_CLUB, POINT_SEVEN},
  {TYPE_JINK, SUIT_CLUB, POINT_EIGHT},
  {TYPE_JINK, SUIT_CLUB, POINT_NINE},
  {TYPE_JINK, SUIT_CLUB, POINT_TEN},
  {TYPE_JINK, SUIT_CLUB, POINT_JACK},
  {TYPE_JINK, SUIT_CLUB, POINT_JACK},
  {TYPE_JINK, SUIT_HEART, POINT_TWO},
  {TYPE_JINK, SUIT_HEART, POINT_TWO},
  {TYPE_JINK, SUIT_HEART, POINT_KING},
  {TYPE_PEACH, SUIT_CLUB, POINT_QUENE},
  {TYPE_PEACH, SUIT_HEART, POINT_THREE},
  {TYPE_PEACH, SUIT_HEART, POINT_FOUR},
  {TYPE_PEACH, SUIT_HEART, POINT_SIX},
  {TYPE_PEACH, SUIT_HEART, POINT_SEVEN},
  {TYPE_PEACH, SUIT_HEART, POINT_EIGHT},
  {TYPE_PEACH, SUIT_HEART, POINT_NINE},
  {TYPE_PEACH, SUIT_HEART, POINT_QUENE},
  {TYPE_ARCHERY, SUIT_HEART, POINT_ONE},
  {TYPE_ALL_PEACH, SUIT_HEART, POINT_ONE},
  {TYPE_COLLATERAL, SUIT_DIAMOND, POINT_QUENE},
  {TYPE_COLLATERAL, SUIT_DIAMOND, POINT_KING},
  {TYPE_GOOD_HARVEST, SUIT_HEART, POINT_THREE},
  {TYPE_GOOD_HARVEST, SUIT_HEART, POINT_FOUR},
  {TYPE_LIGHTING, SUIT_SPADE, POINT_ONE},
  {TYPE_LIGHTING, SUIT_HEART, POINT_QUENE},
  {TYPE_DUEL, SUIT_CLUB, POINT_ONE},
  {TYPE_DUEL, SUIT_SPADE, POINT_ONE},
  {TYPE_DUEL, SUIT_DIAMOND, POINT_ONE},
  {TYPE_SAVAGE_INVASION, SUIT_SPADE, POINT_SEVEN},
  {TYPE_SAVAGE_INVASION, SUIT_SPADE, POINT_KING},
  {TYPE_SAVAGE_INVASION, SUIT_DIAMOND, POINT_SEVEN},
  {TYPE_FORGET_HOME, SUIT_SPADE, POINT_SIX},
  {TYPE_FORGET_HOME, SUIT_HEART, POINT_SIX},
  {TYPE_FORGET_HOME, SUIT_DIAMOND, POINT_SIX},
  {TYPE_OUT_OF_NOTHING, SUIT_HEART, POINT_SEVEN},
  {TYPE_OUT_OF_NOTHING, SUIT_HEART, POINT_EIGHT},
  {TYPE_OUT_OF_NOTHING, SUIT_HEART, POINT_NINE},
  {TYPE_OUT_OF_NOTHING, SUIT_HEART, POINT_JACK},
  {TYPE_STEAL_SHEEP, SUIT_CLUB, POINT_THREE},
  {TYPE_STEAL_SHEEP, SUIT_CLUB, POINT_FOUR},
  {TYPE_STEAL_SHEEP, SUIT_SPADE, POINT_THREE},
  {TYPE_STEAL_SHEEP, SUIT_SPADE, POINT_FOUR},
  {TYPE_STEAL_SHEEP, SUIT_SPADE, POINT_JACK},
  {TYPE_BURN_BRIDGE, SUIT_SPADE, POINT_THREE},
  {TYPE_BURN_BRIDGE, SUIT_SPADE, POINT_FOUR},
  {TYPE_BURN_BRIDGE, SUIT_SPADE, POINT_QUENE},
  {TYPE_BURN_BRIDGE, SUIT_HEART, POINT_QUENE},
  {TYPE_BURN_BRIDGE, SUIT_DIAMOND, POINT_THREE},
  {TYPE_BURN_BRIDGE, SUIT_DIAMOND, POINT_FOUR},
  {TYPE_INVULNERABLE, SUIT_SPADE, POINT_JACK},
  {TYPE_INVULNERABLE, SUIT_DIAMOND, POINT_QUENE},
  {TYPE_INVULNERABLE, SUIT_DIAMOND, POINT_KING},
  {TYPE_INVULNERABLE, SUIT_CLUB, POINT_QUENE},
  {TYPE_CROSSBOW, SUIT_CLUB, POINT_ONE},
  {TYPE_CROSSBOW, SUIT_DIAMOND, POINT_ONE},
  {TYPE_DOUBLE_SWORD, SUIT_SPADE, POINT_TWO},
  {TYPE_ICE_SWORD, SUIT_SPADE, POINT_TWO},
  {TYPE_QINGGANG_SWORD, SUIT_SPADE, POINT_SIX},
  {TYPE_QINGLONG_SWORD, SUIT_SPADE, POINT_FIVE},
  {TYPE_SNAKE_SPEAR, SUIT_SPADE, POINT_QUENE},
  {TYPE_INTERSECTING_AXES, SUIT_CLUB, POINT_FIVE},
  {TYPE_FANGTIAN_HALBERD, SUIT_CLUB, POINT_QUENE},
  {TYPE_KYLIN_BOW, SUIT_HEART, POINT_FIVE},
  {TYPE_EIGHT_DIAGRAM, SUIT_SPADE, POINT_TWO},
  {TYPE_EIGHT_DIAGRAM, SUIT_DIAMOND, POINT_TWO},
  {TYPE_BENEVOLENT_SHIELD, SUIT_DIAMOND, POINT_TWO},
  {TYPE_RED_HORSE, SUIT_HEART, POINT_FIVE},
  {TYPE_DAWAN_HORSE, SUIT_SPADE, POINT_KING},
  {TYPE_ZIXING_HORSE, SUIT_CLUB, POINT_KING},
  {TYPE_DILU_HORSE, SUIT_DIAMOND, POINT_FIVE},
  {TYPE_JUEYING_HORSE, SUIT_SPADE, POINT_KING},
  {TYPE_YELLOWTHUNDER_HORSE, SUIT_HEART, POINT_FIVE}
};

const CardInfo WarfareCards[] = 
{
  {TYPE_WINE, SUIT_CLUB, POINT_NINE},
  {TYPE_WINE, SUIT_SPADE, POINT_THREE},
  {TYPE_WINE, SUIT_SPADE, POINT_NINE},
  {TYPE_WINE, SUIT_DIAMOND, POINT_THREE},
  {TYPE_WINE, SUIT_DIAMOND, POINT_NINE},
  {TYPE_FIRE_SLASH, SUIT_CLUB, POINT_FOUR},
  {TYPE_FIRE_SLASH, SUIT_CLUB, POINT_FIVE},
  {TYPE_FIRE_SLASH, SUIT_HEART, POINT_FOUR},
  {TYPE_FIRE_SLASH, SUIT_HEART, POINT_SEVEN},
  {TYPE_FIRE_SLASH, SUIT_HEART, POINT_TEN},
  {TYPE_THUNDER_SLASH, SUIT_SPADE, POINT_FOUR},
  {TYPE_THUNDER_SLASH, SUIT_SPADE, POINT_FIVE},
  {TYPE_THUNDER_SLASH, SUIT_SPADE, POINT_SIX},
  {TYPE_THUNDER_SLASH, SUIT_SPADE, POINT_SEVEN},
  {TYPE_THUNDER_SLASH, SUIT_SPADE, POINT_EIGHT},
  {TYPE_THUNDER_SLASH, SUIT_DIAMOND, POINT_FIVE},
  {TYPE_THUNDER_SLASH, SUIT_DIAMOND, POINT_SIX},
  {TYPE_THUNDER_SLASH, SUIT_DIAMOND, POINT_SEVEN},
  {TYPE_THUNDER_SLASH, SUIT_DIAMOND, POINT_EIGHT},
  {TYPE_JINK, SUIT_CLUB, POINT_SIX},
  {TYPE_JINK, SUIT_CLUB, POINT_SEVEN},
  {TYPE_JINK, SUIT_CLUB, POINT_EIGHT},
  {TYPE_JINK, SUIT_CLUB, POINT_TEN},
  {TYPE_JINK, SUIT_CLUB, POINT_JACK},
  {TYPE_JINK, SUIT_HEART, POINT_EIGHT},
  {TYPE_JINK, SUIT_HEART, POINT_NINE},
  {TYPE_JINK, SUIT_HEART, POINT_JACK},
  {TYPE_JINK, SUIT_HEART, POINT_QUENE},
  {TYPE_PEACH, SUIT_CLUB, POINT_TWO},
  {TYPE_PEACH, SUIT_CLUB, POINT_THREE},
  {TYPE_PEACH, SUIT_HEART, POINT_FIVE},
  {TYPE_PEACH, SUIT_HEART, POINT_SIX},
  {TYPE_FOOD_SHORTAGE, SUIT_SPADE, POINT_TEN},
  {TYPE_FOOD_SHORTAGE, SUIT_DIAMOND, POINT_FOUR},
  {TYPE_FIRE_ATTACK, SUIT_CLUB, POINT_QUENE},
  {TYPE_FIRE_ATTACK, SUIT_HEART, POINT_TWO},
  {TYPE_FIRE_ATTACK, SUIT_HEART, POINT_THREE},
  {TYPE_CHAIN, SUIT_SPADE, POINT_JACK},
  {TYPE_CHAIN, SUIT_SPADE, POINT_QUENE},
  {TYPE_CHAIN, SUIT_DIAMOND, POINT_TEN},
  {TYPE_CHAIN, SUIT_DIAMOND, POINT_JACK},
  {TYPE_CHAIN, SUIT_DIAMOND, POINT_QUENE},
  {TYPE_CHAIN, SUIT_DIAMOND, POINT_KING},
  {TYPE_INVULNERABLE, SUIT_SPADE, POINT_KING},
  {TYPE_INVULNERABLE, SUIT_HEART, POINT_ONE},
  {TYPE_INVULNERABLE, SUIT_HEART, POINT_KING},
  {TYPE_GUDING_SWORD, SUIT_SPADE, POINT_ONE},
  {TYPE_ROSEFINCH_FAN, SUIT_CLUB, POINT_ONE},
  {TYPE_SILVER_LION, SUIT_DIAMOND, POINT_ONE},
  {TYPE_RATTAN_ARMOR, SUIT_SPADE, POINT_TWO},
  {TYPE_RATTAN_ARMOR, SUIT_DIAMOND, POINT_TWO},
  {TYPE_HUALIU_HORSE, SUIT_CLUB, POINT_KING}
};

// --------------------------------------------------------------------------

CCardHeap::CCardHeap(): m_CardMask(PACKAGE_STANDARD), m_AllCards(NULL), m_CardNum(0)
{
}

int CCardHeap::Init(int packageMask)
{
  DeInit();
  int standardNum = sizeof(StandardCards) / sizeof(StandardCards[0]);
  int warfareNum = sizeof(WarfareCards) / sizeof(WarfareCards[0]);

  if (m_CardMask & PACKAGE_STANDARD)
  {
    m_CardNum += standardNum;
  }
  else
  {
    return 0;
  }

  if (m_CardMask & PACKAGE_WARFARE)
  {
    m_CardNum += warfareNum;
  }

  m_AllCards = new CCard[m_CardNum];
  if (m_AllCards == NULL)
  {
    return 0;
  }

  for (int i = 0; i < m_CardNum; ++i)
  {
    if (i <= standardNum)
    {
      m_AllCards[i].SetCardInfo(StandardCards[i]);
    }
    else
    {
      m_AllCards[i].SetCardInfo(WarfareCards[i - standardNum]);
    }
  }
  
  return 1;
}

void CCardHeap::DeInit()
{
  m_CardNum = 0;
  m_CardMask = PACKAGE_STANDARD;
  if (m_AllCards != NULL)
    delete [] m_AllCards;
  m_AllCards = NULL;
}

