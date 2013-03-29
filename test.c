#include "TimeTools.h"
#include <stdio.h>

int main()
{
	time_t timer = GetCurrentTime();
	printf("timer = %ld \n", timer);
	printf("%s", asctime(localtime(&timer)));
	printf("day = %d \n", GetDay(timer));
	printf("month = %d \n", GetMonth(timer));
	printf("year = %d \n", GetYear(timer));
	struct tm *p_tm = localtime(&timer);
	ULONG timm = GetTimeByYMDHMS(p_tm->tm_year + 1900, p_tm->tm_mon + 1,p_tm->tm_mday, 
							p_tm->tm_hour,p_tm->tm_min,p_tm->tm_sec);
		printf("1ptm = %ld\n", timm);
	char tmp[50];
	
	TimeFormat(timer, "Y-*M-D:H-M)S", tmp, 21);
	
	printf("tmp  = %s\n", tmp);
	printf("Getptm = %ld\n", GetTimeByString("2012@03.29.14.23.09"));
	return 0;
}
