/*
 * TimeTools.h
 *
 *  Created on: 2013-3-28
 *      Author: licko
 */

#include "TimeTools.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define     DEL_LEN  5  

int FindMark(char *pszFormat);
int FindNumber(char *pszTimeString);
void TimeFormat(ULONG iTime,char *pszFormat,char *pszTimeString,int iStringLen)
{
	
	time_t tim = (time_t) iTime;
	char *str = pszTimeString;
	char *fmat= pszFormat;
	struct tm *p_tm;
	p_tm = localtime(&tim);
	int last ;//Record the key letter last time 
	int mark = 0;//The time key;
	int slen = 0;//pszTimeString's length
	fmat = fmat + FindMark(fmat) ;
	while((iStringLen - slen) > 0 && (*fmat != '\0'))
	{
		char delimiter[DEL_LEN]= {0};
		last = mark;
		mark = *fmat;
		
		if(mark > 96)//All converted to capital letter
		{
			mark -= 32;
		}
		
		fmat = fmat + 1;
		int next = FindMark(fmat);
		if(next > 0) 
		{
			if(next < DEL_LEN)
			{
				strncpy(delimiter, fmat , next);
			}
			else
			{	return;
			}

		}
		
		if((last == 'H') && (mark == 'M'))
		{
			mark = 'N'; 
		}
		fmat = fmat + next;
		if(strlen(delimiter) + 2 > (iStringLen - slen)) //Promise not to overflow
			return;
				
		switch (mark)
		{
			case 'Y' :
					sprintf(str+slen,"%d%s",p_tm->tm_year + 1900, delimiter);
					break;
			case 'M' :
				if(p_tm->tm_mon <10)
					sprintf(str+slen,"0%d%s",p_tm->tm_mon + 1, delimiter);
				else
					sprintf(str+slen,"%d%s",p_tm->tm_mon + 1, delimiter);
					break;
			case 'D' :
				if(p_tm->tm_mday <10)
					sprintf(str+slen,"0%d%s",p_tm->tm_mday, delimiter);
				else
					sprintf(str+slen,"%d%s",p_tm->tm_mday, delimiter);
					break;
			case 'H' :
				if(p_tm->tm_hour <10)
					sprintf(str+slen,"0%d%s",p_tm->tm_hour, delimiter);
				else
					sprintf(str+slen,"%d%s",p_tm->tm_hour, delimiter);
					break;
			case 'N' :
				if(p_tm->tm_min <10)
					sprintf(str+slen,"0%d%s",p_tm->tm_min, delimiter);
				else					
					sprintf(str+slen,"%d%s",p_tm->tm_min, delimiter);
					break;
			case 'S' :
				if(p_tm->tm_sec <10)
					sprintf(str+slen,"0%d%s",p_tm->tm_sec, delimiter);
				else
					sprintf(str+slen,"%d%s",p_tm->tm_sec, delimiter);
					break;
				
		}
		slen = strlen(str);
		
	}


}
/*Find time key letters in the string*/
int FindMark(char *pszFormat)
{

	char *fmat= pszFormat;
	int place = 0;

	while(*fmat != 'Y' && *fmat != 'y' && *fmat != 'M' && *fmat != 'm' && *fmat != 'D' && *fmat != 'd' && *fmat != 'H' && *fmat != 'h' && *fmat != 'S' && *fmat != 's' && *fmat != '\0')	
	{	
		fmat++;		
		place++;
	}
	return place;
}


int GetYear(ULONG iTime)
{
	time_t tim = (time_t) iTime;
	struct tm *p_tm;
	p_tm = localtime(&tim);
	/*Starting from 1900*/
	return (1900 + p_tm->tm_year);

}

int GetMonth(ULONG iTime)
{
	time_t tim = (time_t) iTime;
	struct tm *p_tm;
	p_tm = localtime(&tim);
	/*The month must be plus 1 month to reality*/
	return (1 + p_tm->tm_mon);

}

int GetDay(ULONG iTime)
{
	time_t tim = (time_t) iTime;
	struct tm *p_tm;
	p_tm = localtime(&tim);
	return p_tm->tm_mday;
}

ULONG GetCurrentTime()
{
	ULONG seconds;
	if( (seconds = time(NULL)) < 0)
	{
		perror("time\n");
	}
	return seconds; 
}
/*将字符串时间转换为整形
 * 参数1：字串串形式的时间，格式不固定，如“2013－06－23，21：05：23”或”20130623210523“，但除年以外不足两位的均会补齐
 * 返回：当前时间的整形表达
 */
ULONG GetTimeByString(char *pszTimeString)
{
	char *tmp = pszTimeString;
	int time[6] ;
	int i = 0;
	int len ;
	int timers = 6;
	while(timers--)
	{
		tmp = tmp + FindNumber(tmp);
		char str[5] = {0}; 
		if(i == 0)
		{
			len = 4;
		}
		else
		{
			len = 2;
		}
		strncpy(str, tmp, len);
		tmp = tmp + len;
		time[i] = atoi(str);	
		i++;
	}
	ULONG timep = GetTimeByYMDHMS(time[0], time[1], time[2], time[3], time[4], time[5]);
	
	return timep;


}
int FindNumber(char *pszTimeString)
{
	char *tmp = pszTimeString;
	int place = 0;	
	while(*tmp < '0' || *tmp > '9') 
	{
		tmp++;
		place++;
	}	
	return place;
}


/*Can't use the variables of tm  structure*/
ULONG GetTimeByYMDHMS(int iYear,int iMonth,int iDay,int iHour,int iMinute,int iSecond)
{
	struct tm p_tm;
	time_t timep;
	p_tm.tm_sec  = iSecond;
	p_tm.tm_min  = iMinute; 
	p_tm.tm_hour = iHour;
	p_tm.tm_mday = iDay ;
	p_tm.tm_mon  = iMonth - 1; //Normal month minus one
	p_tm.tm_year = iYear - 1900;//From 1900
	timep = mktime(&p_tm);
	return ((ULONG) timep);
}




