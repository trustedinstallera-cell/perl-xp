#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#ifndef SHUT_RD
#  define SHUT_RD 0
#endif
#ifndef SHUT_WR
#  define SHUT_WR 1
#endif
#ifndef SHUT_RDWR
#  define SHUT_RDWR 2
#endif

#ifndef MSG_WAITALL
#  define MSG_WAITALL 0x08
#endif
#ifndef MSG_NOSIGNAL
#  define MSG_NOSIGNAL 0
#endif

#ifndef AI_NUMERICSERV
#  define AI_NUMERICSERV 0x0400
#endif
#ifndef AI_V4MAPPED
#  define AI_V4MAPPED 0x0800
#endif
#ifndef AI_ALL
#  define AI_ALL 0x0100
#endif
#ifndef AI_ADDRCONFIG
#  define AI_ADDRCONFIG 0x0020
#endif

static void
constant_bootstrap(pTHX_ CV *cv)
{
    HV *stash = gv_stashpvs("Socket", GV_ADD);
    (void)cv;

    newCONSTSUB(stash, "AF_INET", newSViv(AF_INET));
    newCONSTSUB(stash, "AF_INET6", newSViv(AF_INET6));
    newCONSTSUB(stash, "AF_UNIX", newSViv(AF_UNIX));
    newCONSTSUB(stash, "SOCK_STREAM", newSViv(SOCK_STREAM));
    newCONSTSUB(stash, "SOCK_DGRAM", newSViv(SOCK_DGRAM));
    newCONSTSUB(stash, "SOCK_RAW", newSViv(SOCK_RAW));
    newCONSTSUB(stash, "IPPROTO_TCP", newSViv(IPPROTO_TCP));
    newCONSTSUB(stash, "IPPROTO_UDP", newSViv(IPPROTO_UDP));
    newCONSTSUB(stash, "IPPROTO_ICMP", newSViv(IPPROTO_ICMP));
    newCONSTSUB(stash, "SOL_SOCKET", newSViv(SOL_SOCKET));
    newCONSTSUB(stash, "SO_REUSEADDR", newSViv(SO_REUSEADDR));
    newCONSTSUB(stash, "SO_BROADCAST", newSViv(SO_BROADCAST));
    newCONSTSUB(stash, "SO_KEEPALIVE", newSViv(SO_KEEPALIVE));
    newCONSTSUB(stash, "SO_LINGER", newSViv(SO_LINGER));
    newCONSTSUB(stash, "SO_RCVBUF", newSViv(SO_RCVBUF));
    newCONSTSUB(stash, "SO_SNDBUF", newSViv(SO_SNDBUF));
    newCONSTSUB(stash, "SO_TYPE", newSViv(SO_TYPE));
    newCONSTSUB(stash, "SO_ERROR", newSViv(SO_ERROR));
    newCONSTSUB(stash, "SHUT_RD", newSViv(SHUT_RD));
    newCONSTSUB(stash, "SHUT_WR", newSViv(SHUT_WR));
    newCONSTSUB(stash, "SHUT_RDWR", newSViv(SHUT_RDWR));
    newCONSTSUB(stash, "INADDR_ANY", newSVuv(INADDR_ANY));
    newCONSTSUB(stash, "INADDR_LOOPBACK", newSVuv(INADDR_LOOPBACK));
    newCONSTSUB(stash, "INADDR_BROADCAST", newSVuv(INADDR_BROADCAST));
    newCONSTSUB(stash, "INADDR_NONE", newSVuv(INADDR_NONE));
    newCONSTSUB(stash, "SOMAXCONN", newSViv(SOMAXCONN));
    newCONSTSUB(stash, "MSG_OOB", newSViv(MSG_OOB));
    newCONSTSUB(stash, "MSG_PEEK", newSViv(MSG_PEEK));
    newCONSTSUB(stash, "MSG_DONTROUTE", newSViv(MSG_DONTROUTE));
    newCONSTSUB(stash, "MSG_WAITALL", newSViv(MSG_WAITALL));
    newCONSTSUB(stash, "MSG_NOSIGNAL", newSViv(MSG_NOSIGNAL));
    newCONSTSUB(stash, "TCP_NODELAY", newSViv(TCP_NODELAY));
    newCONSTSUB(stash, "AI_PASSIVE", newSViv(AI_PASSIVE));
    newCONSTSUB(stash, "AI_CANONNAME", newSViv(AI_CANONNAME));
    newCONSTSUB(stash, "AI_NUMERICHOST", newSViv(AI_NUMERICHOST));
    newCONSTSUB(stash, "AI_NUMERICSERV", newSViv(AI_NUMERICSERV));
    newCONSTSUB(stash, "AI_V4MAPPED", newSViv(AI_V4MAPPED));
    newCONSTSUB(stash, "AI_ALL", newSViv(AI_ALL));
    newCONSTSUB(stash, "AI_ADDRCONFIG", newSViv(AI_ADDRCONFIG));
    newCONSTSUB(stash, "EAGAIN", newSViv(EAGAIN));
    newCONSTSUB(stash, "EINPROGRESS", newSViv(EINPROGRESS));
    newCONSTSUB(stash, "EWOULDBLOCK", newSViv(EWOULDBLOCK));
    newCONSTSUB(stash, "ECONNREFUSED", newSViv(ECONNREFUSED));
    newCONSTSUB(stash, "ECONNRESET", newSViv(ECONNRESET));
    newCONSTSUB(stash, "ETIMEDOUT", newSViv(ETIMEDOUT));
    newCONSTSUB(stash, "EHOSTUNREACH", newSViv(EHOSTUNREACH));
    newCONSTSUB(stash, "ENETUNREACH", newSViv(ENETUNREACH));
    newCONSTSUB(stash, "EADDRINUSE", newSViv(EADDRINUSE));
    newCONSTSUB(stash, "EADDRNOTAVAIL", newSViv(EADDRNOTAVAIL));
}
