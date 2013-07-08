
#ifndef _PACKET_H_
#define _PACKET_H_

#define MAX_PACKET_LEN 64000

#pragma pack(1)

struct PacketHeader
{
  int m_PacketLen;
  int m_Command;
  int m_Reserved;
};

#pragma pack()

class CPacketQueue
{
public:
  CPacketQueue();
  int PushbackQ(void *data);
  int PushfrontQ(void *data);
  int PopfrontQ(void **data);

protected:
  list<void *> m_Data;
};

class CPullThread: public COPThread
{
public:
  CPullThread(CPacketQueue *queue);
  virtual int Run();

protected:
  CPacketQueue *m_Queue;
};

#endif
