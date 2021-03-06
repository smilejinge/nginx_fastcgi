#ifndef __POLL_POOL_H__
#define __POLL_POOL_H__


#include <stdint.h>

#include <sys/epoll.h>

#include <map>


namespace Network
{
	class CPollUnit;
	
	
	class CPollPool
	{
	public:
		CPollPool(uint64_t epoll_size = 4096);
		virtual ~CPollPool();

	public:
		int32_t Init();
		void UnInit();
		int32_t AttachUnit(CPollUnit *unit);
		int32_t DetachUnit(CPollUnit *unit);
		int32_t EpollCtl(int32_t op, int32_t fd, epoll_event *ep_event);
		int32_t EpollCtl(int32_t op, CPollUnit *unit);
		int32_t EpollCtl(int32_t op, CPollUnit *unit, epoll_event *ep_event);
		int32_t EpollCtl(int32_t op, CPollUnit *unit, uint32_t events);
		int32_t ModifyEvent(CPollUnit *unit);
		int32_t DoOtherSomething();
		int32_t EpollProcess(int32_t timeout = 3000);

	private:
		typedef std::list<CPollUnit *> POLLUNIT_LIST;
		typedef std::map<int32_t, CPollUnit *> POLLUNIT_MAP;
		
	private:
		int32_t m_epoll_fd;
		uint64_t m_epoll_size;
		epoll_event *m_epoll_events;
		POLLUNIT_LIST m_poll_pres;
		POLLUNIT_MAP m_poll_units;
	};
};


#endif
