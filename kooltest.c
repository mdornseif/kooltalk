/* $Id: kooltest.c,v 1.1 2000/04/15 03:50:12 drt Exp $
 *
 * testing kooltalk
 * 
 * $Log: kooltest.c,v $
 * Revision 1.1  2000/04/15 03:50:12  drt
 * ERstmals is kooltalk mit kooltiz in der LAge, als LS_PRELOAD zu laufen.
 * Diese fünktionalität braucht allerdings noch polish.
 * */

#include <stdio.h>   
#include "kooltalk.h"

int main()
{
  puts("Dies ist ein test text - hoffentlich kool.");
  printf("Dies ist ein %s - hoffentlich kool (%d).", "test Text", 23);
  kool_puts("Dies ist ein test text - hoffentlich kool.");
  kool_printf("Dies ist ein %s - hoffentlich kool (%d).", "test Text", 23);
  
  return 0;
}
