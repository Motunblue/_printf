#ifndef _MAIN_H_
#define _MAIN_H_

/* Header files */
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/* Macros */
#define BUFF_SIZE 1024

/* Fuction Prototypes */
int _printf(const char *format, ...);
int print_fmt(char c, va_list list, char);
int print_char(char c);
int print_str(char *s);
int print_S(char *);
int print_int(long n, char flag);
int print_hex(long m, char x, char flag);
int print_ptr(const void *ptr, int);
int print_u(int n, int base);
int print_base(long m, int base, char flag);
int print_fmt2(char c, va_list list, char flag);
char getflag(char c);
int print_r(char *);
int print_R(char *);

#endif
