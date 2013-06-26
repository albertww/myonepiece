/*
  Author: Albert
  Date: 20130417
  Description: Definition of card
*/

#ifndef _HERO_H_
#define _HERO_H_

#include <list>
#include "datatypes.h"
using std::list;

class CHero
{
public:
  CHero();
  

protected:
  uchar m_HP;
  list<CCard *> m_HandCard;
  list<CSkill *> m_Skills;
  
  // cards
  // skills
};

#endif
