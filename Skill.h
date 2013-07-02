/*
  Author: Albert
  Date: 20130620
  Description: Skills
*/

class CSkillCB
{
public:
  int IsTarget();
};

class CSkill
{
public:
  int OnProcess();
  int OnResponse();
};

class CWanjianSkill
{
public:
  int m_Start;
};

class CCardSkill: public CSkill
{
};



