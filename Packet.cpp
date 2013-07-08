#include "Packet.h"


CPacketQueue::CPacketQueue()
{
}

int CPacketQueue::PushbackQ(void *data)
{
  // lock
  int succ = 0;
  do
  {
    if (data)
    {
      PacketHeader *header = data;
	  if (header->m_PacketLen > MAX_PACKET_LEN || header->m_PacketLen <= sizeof(*header))
	  {
	    break;
	  }
	  char *pData = new char[header->m_PacketLen];
	  memcpy(pData, data, header->m_PacketLen];
      m_Data.push_back(pData);
	  succ = 1;
    }
  } while(0)
  
  // unlock
  return succ;
}

int CPacketQueue::PushfrontQ(void *data)
{
  // lock
  int succ = 0;
  do
  {
    if (data)
    {
      PacketHeader *header = data;
	  if (header->m_PacketLen > MAX_PACKET_LEN || header->m_PacketLen <= sizeof(*header))
	  {
	    break;
	  }
	  char *pData = new char[header->m_PacketLen];
	  memcpy(pData, data, header->m_PacketLen];
      m_Data.push_front(pData);
	  succ = 1;
    }
  } while(0)
  
  // unlock
  return succ;
}

int CPacketQueue::PopfrontQ(void **data)
{
  // lock
  int succ = 0;
  do
  {
    if (data)
    {
      list<void *>::iterator it = m_Data.begin();
	  if (it == m_Data.end())
	  {
	    *data = NULL;
	    break;
	  }
      *data = *it;
	  succ = 1;
    }
  } while(0)
  // unlock
  return succ;
}

CPullThread::CPullThread(CPacketQueue *queue): m_Queue(queue);
{

}

int CPullThread::Run()
{
  while (!StopThread())
  {
    void **data;
    m_Queue->PopQ(data);
	// table->Proc(*data);
  }
}