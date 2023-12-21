#ifndef _HODE_H
#define _HODW_H

int getcmdarg (int idx, int len, char *buf);
__uint64_t getnowns ();
int setrosize (__size_t rosize);
int setstklim (__size_t stklim);
int setttyecho (int fd, bool echo);
int printinstr (bool on);
__uint16_t rdps ();
__uint16_t wrps (__uint16_t ps);
void watchwrite (void *addr);

#endif
