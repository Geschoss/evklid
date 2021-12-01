//
//  date.cpp
//  Chapter03
//
//  Created by Kolomnikov Pavel on 16.06.2021.
//

#include "date.h"
#include <sys/time.h>

unsigned long fgSystemTime(void) {
    struct timeval now;
    gettimeofday( &now, NULL );
    return now.tv_usec/1000 + now.tv_sec*1000;
}

/*
 * Elapsed Time
 */
long fgElapsedTime(unsigned long startTime)
{
    return (long) (fgSystemTime() - startTime);
}
