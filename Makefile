# A very simple Makefile for KoolTalk
INSTDIR = /usr/local/bin
MANDIR = /usr/local/man
CC=gcc

ALL: tags kooltest 

kooltalk: kooltalk.o
	$(CC) -o $@ $^

kooltiz.so: kooltiz.o koolit.o kooltwins.o helper.a
	ld -Bshareable -o kooltiz.so $^

kooltest: koolit.o kooltest.o kooltwins.o helper.a
	$(CC) -o $@ $^

helper.a: helper/alloc.o helper/alloc_re.o helper/byte_copy.o \
helper/stralloc_cat.o helper/stralloc_catb.o helper/stralloc_cats.o \
helper/stralloc_copy.o helper/stralloc_eady.o helper/stralloc_opyb.o \
helper/stralloc_opys.o helper/stralloc_pend.o helper/str_len.o helper/error.o
	ar cr $@ $^
	ranlib $@

tags: 
	ctags kooltalk.c

clean: 
	rm -f kooltalk tags *.o

distclean:
	rm -f *.o *~ */*.o */*~ tags

install: 
	# we should do striping here
	install kooltalk $(INSTDIR)
	install kooltalk.1 $(MANDIR)/man1
