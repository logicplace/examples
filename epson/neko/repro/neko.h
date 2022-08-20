#ifndef __NEKO_H__
#define __NEKO_H__

#define ICON_WIDTH       32
#define ICON_PAGE_HEIGHT 4

extern _near unsigned char neko[][128];
enum STATUS { sleep1, sleep2, awake, mati, jare, kaki1, kaki2, akubi };

void rtclock1Hz (void);
void rtclock2Hz (void);
void inputport (void);

#endif // __NEKO_H__
