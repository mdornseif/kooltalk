/* $Id: kooltiz.c,v 1.1 2000/04/15 03:50:12 drt Exp $
 *
 * This are functions to overwrite the regular glibc functions
 * 
 * $Log: kooltiz.c,v $
 * Revision 1.1  2000/04/15 03:50:12  drt
 * ERstmals is kooltalk mit kooltiz in der LAge, als LS_PRELOAD zu laufen.
 * Diese fünktionalität braucht allerdings noch polish.
 * */

#include <stdio.h>   
#include <stdarg.h>
#include <dlfcn.h>      // dlsym
#include "kooltalk.h"


/* Pointers to the original libc functions. Initialized in _init() */

static int (*org_puts)(const char *s);
static int (*org_printf)(const char *fmt, ...);


/* Setup everything, or exit() if an error occurs */
//int _init( void )
//{
  /* find the address of the original libc function */

  /* find the address of the original libc function */
//  org_printf = dlsym( RTLD_NEXT, "printf" );
//  if ( !org_printf )
//    {
      //      fatalerr( "Original 'printf()' not found.\n" );
//      _exit(1);
//    }
  
//  return 0;
//}

int puts(const char *s)
{
   int x;
  stralloc sa = { 0 };

  org_puts = dlsym( RTLD_NEXT, "puts" );
  if ( !org_puts )
    {
      //      fatalerr( "Original 'puts()' not found.\n" );
      _exit(1);
    }

  kool_downs(&sa, s);
  stralloc_0(&sa);
  x = org_puts(sa.s);
  if(x > 0) 
    {
      return sa.len;
    }
  else
    {
      return x;
    }
}

int printf(const char *fmt, ...)
{
  int len;
  va_list ap;

  va_start(ap, fmt);
  len = kool_vprintf(fmt, ap);
  va_end(ap);

  return len;
}




// which other functions people use?
// e.g.:
//kool_fprintf
//kool_snprintf


