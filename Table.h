/*
  Author: Albert
  Date: 20130417
  Description: Table
*/

#ifndef _TABLE_H_
#define _TABLE_H_

class CPlayer;

class CTable
{
public:

  int AskForKill();
  int AskForJink();
  int AskForPeach();

protected:
  list<CPlayer *> m_Players;
};

#endif

