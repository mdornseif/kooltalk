/* $Id: kooltalk.h,v 1.1 2000/04/15 03:50:11 drt Exp $
 * 
 * Headerfiles for libkool/kooltalk
 *
 * $Log: kooltalk.h,v $
 * Revision 1.1  2000/04/15 03:50:11  drt
 * ERstmals is kooltalk mit kooltiz in der LAge, als LS_PRELOAD zu laufen.
 * Diese fünktionalität braucht allerdings noch polish.
 *
 */

#include "helper/stralloc.h"

/* koolit.c */
int kool_down_cat(stralloc *out, stralloc *in);
int kool_down_catb(stralloc *out, char *in, int l);
int kool_down_cats(stralloc *out, char *in);
int kool_down(stralloc *out, stralloc *in);
int kool_downb(stralloc *out, char *in, int l);
int kool_downs(stralloc *out, char *in);
int kool_this_down_cat(char *out, int n, stralloc *in);
int kool_this_down_catb(char *out, int n, char *in, int l);
int kool_this_down_cats(char *out, int n, char *in);
int kool_this_down(char *out, int n, stralloc *in);
int kool_this_downb(char *out, int n, char *in, int l);
int kool_this_downs(char *out, int n, char *in);
