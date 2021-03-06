/*
 * TimeTools.h
 *
 *  Created on: 2013-3-28
 *      Author: root
 */

#ifndef TIMETOOLS_H_
#define TIMETOOLS_H_
#include <time.h>

#ifdef OP_SUCCESS
#else
#define OP_SUCCESS 0
#define OP_FAILED -1
#endif
typedef  unsigned long ULONG;

/*根据格式化描述获取指定整形时间的字符串
 * 参数1：传入整型时间
 * 参数2：格式化字符串如“Y-M-D” 输出 “年－月－日”形式，“Y_M_D,H：M：S“输出“年_月_日,时:分:秒”形式，注意，分割符是自定义的
 * 参数3：输出的时间字符串
 * 参数4：参数3的长度
 * 返回：无
 */
void TimeFormat(ULONG iTime,char *pszFormat,char *pszTimeString,int iStringLen);
/*获取时间的年数值
 * 参数1：时间
 * 返回：年的整形表达
 */
int GetYear(ULONG iTime);
/*获取时间的月数值
 * 参数1：时间
 * 返回：月的整形表达
 */
int GetMonth(ULONG iTime);
/*获取时间的天数值
 * 参数1：时间
 * 返回：天的整形表达
 */
int GetDay(ULONG iTime);
/*获取当前时间
 * 参数1：无
 * 返回：当前时间的整形表达
 */
ULONG GetCurrentTime();
/*将字符串时间转换为整形
 * 参数1：字串串形式的时间，格式不固定，如“2013－06－23，21：05：23”或”20130623210523“，但除年以外不足两位的均会补齐
 * 返回：当前时间的整形表达
 */
ULONG GetTimeByString(char *pszTimeString);
/*将拆分的时间转换为整形
 * 参数1－6，代表时间的年月日时分秒
 * 返回：当前时间的整形表达
 */
ULONG GetTimeByYMDHMS(int iYear,int iMonth,int iDay,int iHour,int iMinute,int iSecond);



#endif /* TIMETOOLS_H_ */

