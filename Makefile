# A very simple Makefile for KoolTalk
INSTDIR = /usr/local/bin
MANDIR = /usr/local/man
CC = /usr/bin/gcc -O2 -Wall
STRIP = /usr/bin/strip
CTAGS = /usr/bin/ctags
RM =  /bin/rm
CP = /bin/cp
ALL: tags kooltalk 
kooltalk: 
	$(CC) -o kooltalk kooltalk.c
	$(STRIP) kooltalk
tags: 
	$(CTAGS) kooltalk.c
clean: 
	$(RM) kooltalk tags
install: 
	$(CP) kooltalk $(INSTDIR)
	$(CP) kooltalk.1 $(MANDIR)/man1
