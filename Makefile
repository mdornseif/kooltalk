# A very simple Makefile for KoolTalk
INSTDIR = /usr/local/bin
MANDIR = /usr/local/man
CC = /usr/bin/gcc -O2 -Wall
STRIP = /usr/bin/strip
CTAGS = /usr/bin/ctags
RM =  /bin/rm
CP = /bin/cp
ALL: tags kooltalk 

kooltalk: kooltalk.o
	$(CC) -o $@ $^
	$(STRIP) $@  
tags: 
	$(CTAGS) kooltalk.c
clean: 
	$(RM) kooltalk tags *.o
install: 
	$(CP) kooltalk $(INSTDIR)
	$(CP) kooltalk.1 $(MANDIR)/man1
