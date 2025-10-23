# Non Blocking waiting #

> Checking the value of `errno` to adjust the server behaviour is strictly forbidden after performing a read or write operation.
> > So it's acceptable if used for initialisation of the polling functions ?

## poll ##

```C
#include <poll.h>
int poll(struct pollfd fds[], nfds_t nfds, int timeout);
```

## select ##

```C
#include <sys/select.h>

int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds,
    fd_set *restrict errorfds, struct timeval *restrict timeout);
```

## epoll ##

### epoll_create ###

```C
#include <sys/epoll.h>
```

```C
/**
 * @brief Create a new epoll instance
 * 
 * @param[in] size number of expected fd, but anything higher than 0 is OK
 * as it's dynamically changed anyways
 * @return a valid fd, -1 if error and errno set
 */
int epoll_create(int size);
```

ERRORS :

* EINVAL size is not positive.
* EMFILE The  per-user  limit  on the number of epoll instances imposed by /proc/sys/fs/epoll/max_user_instances was encountered.  See epoll(7) for further details.
* EMFILE The per-process limit on the number of open file descriptors has been reached.
* ENFILE The system-wide limit on the total number of open files has been reached.
* ENOMEM There was insufficient memory to create the kernel object.

### epoll_ctl ###

```C
/**
 * @brief Add, modify or remove entrieds in interest list
 * 
 * @param[in] epfd file descriptor of epoll instance
 * @param[in] op
 * @param[in] fd
 * @param[in, out] event
 * @return a valid fd, -1 if error and errno set
 */
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
```

### epoll_wait ###

int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);

```C
/**
 * @brief Waits for events on the epoll instance 
 * 
 * @param[in] epfd file descriptor of epoll instance
 * @param[in, out] event
 * @param[in] maxevents maximum number of events returned (>0)
 * @param[in] timeout number of milliseconds before epoll_wait() unblocks itself
 * @return number of fd ready for I/O, 0 if timeout, -1 if error and errno set
 */
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
```

## kqueue / kevent ##

```C
#include <sys/event.h>
```

### kqueue ###

```C
/**
 * @brief Creates a new kernel event queue and returns a descriptor
 * 
 * @return descriptor, -1 if error and errno set 
 */
int kqueue(void);
```

### kevent ###

```C
struct kevent {
    uintptr_t ident;   /* identifier for this event */
    short filter;      /* filter for event */
    u_short flags;     /* action flags for kqueue */
    u_int fflags;      /* filter flag value */
    int64_t ata;       /* filter data value */
    void *udata;       /* opaque user data identifier */
    uint64_t ext[4];   /* extensions */
};

struct timespec {
    time_t tv_sec;      // nombre de secondes
    long tv_nsec;       // nombre de nanosecondes
};

/**
 * @brief Register events with the queue and 
 * 
 * @param[in] kq descriptor of kqueue instance
 * @param[in, out] changelist list of events that we WANT to change
 * @param[in] nchanges size of changelist
 * @param[in, out] eventlist list of events that are ready
 * @param[in] nevents size of eventlist
 * @param[in] timeout timespect, if NULL, waits indefinitely
 * @return number of events placed in eventlist, 0 if timeout, -1 if error and errno set 
 */
int kevent(int kq, const struct    kevent *changelist,     int nchanges,
struct kevent *eventlist, int nevents, const struct    timespec *timeout);
```
