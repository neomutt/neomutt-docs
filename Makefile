VERSION=20170912
DESTDIR =
PREFIX = /usr/local
ifeq ($(PREFIX),/usr)
	ETC_DIR = /etc
else
	ETC_DIR = $(PREFIX)/etc
endif
DOC_DIR = $(PREFIX)/share/doc/neomutt
MAN_DIR = $(PREFIX)/share/man

INSTALL = install
MKDIR = mkdir -p
RM = rm -fr

SRC_DIR = ~/neomutt
SRC_DOCS = ChangeLog.md CODE_OF_CONDUCT.md COPYRIGHT INSTALL LICENSE.md README.md README.SSL
SRC_SOURCE = functions.h init.h opcodes.h

CFLAGS	= -Wall -std=c99

BUILD	= index.html makedoc guide.html guide.txt guide.xml neomutt.1 neomuttrc neomuttrc.5
CHUNKED_DOCFILES = advancedusage.html configuration.html gettingstarted.html \
	intro.html mimesupport.html miscellany.html optionalfeatures.html \
	reference.html security.html tuning.html

EDIT = sed \
	-e 's,@VERSION@,$(VERSION),g' \
	-e 's,@SYSCONFDIR@,$(ETC_DIR),g' \
	-e 's,@DOCDIR@,$(DOC_DIR),g' \
	-e 's,\<ISPELL\>,/usr/bin/ispell,g' \
	-e 's,\<SENDMAIL\>,/usr/sbin/sendmail,g' \
	-e 's,\<MIXMASTER\>,mixmaster,g'

all: $(BUILD)

makedoc:	makedoc.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(BUILD) $(CHUNKED_DOCFILES)

distclean: clean

neomuttrc.5:	man/neomuttrc.man.head man/neomuttrc.man.tail makedoc src/init.h
	( \
		cat man/neomuttrc.man.head; \
		$(EDIT) src/init.h | ./makedoc -m; \
		cat man/neomuttrc.man.tail; \
	) > $@

neomuttrc: neomuttrc.head makedoc src/init.h
	( \
		$(EDIT) neomuttrc.head; \
		$(EDIT) src/init.h | ./makedoc -c; \
	) > $@

guide.xml:	src/functions.h src/init.h guide/guide.xml.head guide/guide.xml.tail guide/gen-map-doc makedoc
	( \
		$(EDIT) guide/guide.xml.head; \
		$(EDIT) src/init.h | ./makedoc -s; \
		$(EDIT) src/functions.h | perl guide/gen-map-doc guide/guide.xml.tail src/opcodes.h; \
	) > $@

guide.html: guide.xml guide/html.xsl guide/neomutt.xsl guide/neomutt.css
	-xsltproc --nonet -o $@ guide/html.xsl guide.xml

$(CHUNKED_DOCFILES): index.html

index.html: guide/chunk.xsl guide/neomutt.xsl guide.xml guide/neomutt.css
	-xsltproc --nonet guide/chunk.xsl guide.xml > /dev/null 2>&1

guide.txt: guide.html
	-LC_ALL=C w3m -dump -O UTF8 guide.html > $@ || \
	LC_ALL=C lynx -dump -nolist -with_backspaces -display_charset=us-ascii guide.html > $@ || \
	LC_ALL=C elinks -dump -no-numbering -no-references guide.html | sed -e 's,\\001, ,g' > $@

spellcheck:
	-aspell -d american --mode=sgml  --encoding=utf-8 -p neomutt.pwl check guide/guide.xml.head
	-aspell -d american --mode=nroff --encoding=utf-8 -p neomutt.pwl check man/neomuttrc.man.head
	-aspell -d american --mode=ccpp  --encoding=utf-8 -p neomutt.pwl check src/init.h

validate: guide.xml
	xmllint --noout --noblanks --postvalid $<

neomutt.1: man/neomutt.man
	$(EDIT) man/neomutt.man > $@

install:	all
	$(MKDIR) $(DESTDIR)$(MAN_DIR)/man1
	for i in pgpewrap pgpring smime_keys; do \
		$(INSTALL) -m 644 man/$$i.1 $(DESTDIR)$(MAN_DIR)/man1/$${i}_neomutt.1; \
	done
	$(INSTALL) -m 644 neomutt.1 $(DESTDIR)$(MAN_DIR)/man1

	$(MKDIR) $(DESTDIR)$(MAN_DIR)/man5
	for i in mbox mmdf; do \
		$(INSTALL) -m 644 man/$$i.5 $(DESTDIR)$(MAN_DIR)/man5/$${i}_neomutt.5; \
	done
	$(INSTALL) -m 644 neomuttrc.5 $(DESTDIR)$(MAN_DIR)/man5
	$(MKDIR) $(DESTDIR)$(DOC_DIR)/logo
	for i in neomutt-32.png neomutt-64.png neomutt-128.png neomutt-256.png neomutt.svg; do \
		$(INSTALL) -m 644 logo/$$i $(DESTDIR)$(DOC_DIR)/logo; \
	done
	$(MKDIR) $(DESTDIR)$(DOC_DIR)
	for i in guide.html index.html $(CHUNKED_DOCFILES); do \
		$(INSTALL) -m 644 $$i $(DESTDIR)$(DOC_DIR); \
	done
	for i in guide.txt neomutt-syntax.vim neomuttrc PGP-Notes.txt smime-notes.txt; do \
		$(INSTALL) -m 644 $$i $(DESTDIR)$(DOC_DIR); \
	done
	for i in $(SRC_DOCS); do \
		$(INSTALL) -m 644 src/$$i $(DESTDIR)$(DOC_DIR); \
	done

uninstall:
	for i in pgpewrap pgpring smime_keys; do \
		$(RM) $(DESTDIR)$(MAN_DIR)/man1/$${i}_neomutt.1; \
	done
	$(RM) $(DESTDIR)$(MAN_DIR)/man1/neomutt.1
	for i in mbox mmdf; do \
		$(RM) $(DESTDIR)$(MAN_DIR)/man5/$${i}_neomutt.5; \
	done
	$(RM) $(DESTDIR)$(MAN_DIR)/man5/neomuttrc.5
	for i in neomutt-32.png neomutt-64.png neomutt-128.png neomutt-256.png neomutt.svg; do \
		$(RM) $(DESTDIR)$(DOC_DIR)/logo; \
	done
	for i in guide.html index.html $(CHUNKED_DOCFILES); do \
		$(RM) $(DESTDIR)$(DOC_DIR)/$$i; \
	done
	for i in guide.txt neomutt-syntax.vim neomuttrc PGP-Notes.txt smime-notes.txt; do \
		$(RM) $(DESTDIR)$(DOC_DIR)/$$i; \
	done
	for i in $(SRC_DOCS); do \
		$(RM) $(DESTDIR)$(DOC_DIR)/$$i; \
	done

update-source:
	for i in $(SRC_DOCS) $(SRC_SOURCE); do \
		$(INSTALL) -m 644 $(SRC_DIR)/$$i src; \
	done

