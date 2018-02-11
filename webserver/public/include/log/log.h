#ifndef __LOG_H__
#define __LOG_H__

#include <libgen.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <string>

extern int __log_level__;


#define log_bare(lvl, fmt, args...)	 	 _write_log_(lvl, NULL, NULL, 0 , fmt, ##args)
#define log_generic(lvl, fmt, args...)	 _write_log_(lvl, __FILE__, __FUNCTION__, __LINE__ , fmt, ##args)
#define log_emerg(fmt, args...)		log_generic(0, fmt, ##args)
#define log_alert(fmt, args...)		log_generic(1, fmt, ##args)
#define log_crit(fmt, args...)		log_generic(2, fmt, ##args)
#define log_error(fmt, args...)		log_generic(3, fmt, ##args)
#define log_warning(fmt, args...)	do{ if(__log_level__>=4)log_generic(4, fmt, ##args); } while(0)
#define log_notice(fmt, args...)	do{ if(__log_level__>=5)log_generic(5, fmt, ##args); } while(0)
#define log_info(fmt, args...)		do{ if(__log_level__>=6)log_generic(6, fmt, ##args); } while(0)
#define log_debug(fmt, args...)		do{ if(__log_level__>=7)log_generic(7, fmt, ##args); } while(0)


void _init_log_(const std::string &app, const std::string &dir);
void _set_log_level_(int l);
void _write_log_(int, const char*, const char *, int, const char *, ...) __attribute__((format(printf, 5, 6)));
void _write_stderr_(const char *fmt, ...);


#endif // __LOG_H__