/**
 * @file
 * Definitions of user variables, sort methods and commands
 *
 * @authors
 * Copyright (C) 1996-2002,2007,2010,2012-2013,2016 Michael R. Elkins <me@mutt.org>
 * Copyright (C) 2004 g10 Code GmbH
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MUTT_INIT_H
#define _MUTT_INIT_H

#ifdef _MAKEDOC
#include "config.h"
#include "doc/makedoc_defs.h"
#else
#include <stddef.h>
#include "mutt.h"
#include "buffy.h"
#include "globals.h"
#include "group.h"
#include "mutt_commands.h"
#include "mutt_options.h"
#include "mutt_regex.h"
#include "mx.h"
#include "options.h"
#include "protos.h"
#include "sort.h"
#ifdef USE_LUA
#include "mutt_lua.h"
#endif
#endif

struct Buffer;

#ifndef _MAKEDOC
/* flags to parse_set() */
#define MUTT_SET_INV   (1 << 0) /**< default is to invert all vars */
#define MUTT_SET_UNSET (1 << 1) /**< default is to unset all vars */
#define MUTT_SET_RESET (1 << 2) /**< default is to reset all vars to default */

/* forced redraw/resort types + other flags */
#define R_NONE        0
#define R_INDEX       (1 << 0) /**< redraw the index menu (MENU_MAIN) */
#define R_PAGER       (1 << 1) /**< redraw the pager menu */
#define R_PAGER_FLOW  (1 << 2) /**< reflow line_info and redraw the pager menu */
#define R_RESORT      (1 << 3) /**< resort the mailbox */
#define R_RESORT_SUB  (1 << 4) /**< resort subthreads */
#define R_RESORT_INIT (1 << 5) /**< resort from scratch */
#define R_TREE        (1 << 6) /**< redraw the thread tree */
#define R_REFLOW      (1 << 7) /**< reflow window layout and full redraw */
#define R_SIDEBAR     (1 << 8) /**< redraw the sidebar */
#define R_MENU        (1 << 9) /**< redraw all menus */
#define R_BOTH        (R_INDEX | R_PAGER)
#define R_RESORT_BOTH (R_RESORT | R_RESORT_SUB)

/* general flags, to be OR'd with the R_ flags above (so keep shifting..) */
#define F_SENSITIVE   (1 << 9)

#define IS_SENSITIVE(x) (((x).flags & F_SENSITIVE) == F_SENSITIVE)

#define UL (unsigned long)
#endif /* _MAKEDOC */

#ifndef ISPELL
#define ISPELL "ispell"
#endif

struct Option MuttVars[] = {
  /*++*/

  { "abort_noattach", DT_QUAD, R_NONE, OPT_ABORT_NOATTACH, MUTT_NO },
  /*
  ** .pp
  ** If set to \fIyes\fP, when composing messages containing the regular expression
  ** specified by $attach_keyword and no attachments ** are given, composition
  ** will be aborted. If set to \fIno\fP, composing ** messages as such will never
  ** be aborted.
  ** .pp
  ** Example:
  ** .ts
  ** set attach_keyword = "\\<attach(|ed|ments?)\\>"
  ** .te
  */
  { "abort_nosubject",  DT_QUAD, R_NONE, OPT_ABORT_NOSUBJECT, MUTT_ASKYES },
  /*
  ** .pp
  ** If set to \fIyes\fP, when composing messages and no subject is given
  ** at the subject prompt, composition will be aborted.  If set to
  ** \fIno\fP, composing messages with no subject given at the subject
  ** prompt will never be aborted.
  */
  { "abort_unmodified", DT_QUAD, R_NONE, OPT_ABORT_UNMODIFIED, MUTT_YES },
  /*
  ** .pp
  ** If set to \fIyes\fP, composition will automatically abort after
  ** editing the message body if no changes are made to the file (this
  ** check only happens after the \fIfirst\fP edit of the file).  When set
  ** to \fIno\fP, composition will never be aborted.
  */
  { "alias_file",       DT_PATH, R_NONE, UL &AliasFile, UL "~/.neomuttrc" },
  /*
  ** .pp
  ** The default file in which to save aliases created by the
  ** \fC$<create-alias>\fP function. Entries added to this file are
  ** encoded in the character set specified by $$config_charset if it
  ** is \fIset\fP or the current character set otherwise.
  ** .pp
  ** \fBNote:\fP NeoMutt will not automatically source this file; you must
  ** explicitly use the ``$source'' command for it to be executed in case
  ** this option points to a dedicated alias file.
  ** .pp
  ** The default for this option is the currently used neomuttrc file, or
  ** ``~/.neomuttrc'' if no user neomuttrc was found.
  */
  { "alias_format",     DT_STRING,  R_NONE, UL &AliasFormat, UL "%4n %2f %t %-10a   %r" },
  /*
  ** .pp
  ** Specifies the format of the data displayed for the ``$alias'' menu.  The
  ** following \fCprintf(3)\fP-style sequences are available:
  ** .dl
  ** .dt %a .dd alias name
  ** .dt %f .dd flags - currently, a ``d'' for an alias marked for deletion
  ** .dt %n .dd index number
  ** .dt %r .dd address which alias expands to
  ** .dt %t .dd character which indicates if the alias is tagged for inclusion
  ** .de
  */
  { "allow_8bit",       DT_BOOL, R_NONE, OPT_ALLOW_8BIT, 1 },
  /*
  ** .pp
  ** Controls whether 8-bit data is converted to 7-bit using either Quoted-
  ** Printable or Base64 encoding when sending mail.
  */
  { "allow_ansi",      DT_BOOL, R_NONE, OPT_ALLOW_ANSI, 0 },
  /*
  ** .pp
  ** Controls whether ANSI color codes in messages (and color tags in
  ** rich text messages) are to be interpreted.
  ** Messages containing these codes are rare, but if this option is \fIset\fP,
  ** their text will be colored accordingly. Note that this may override
  ** your color choices, and even present a security problem, since a
  ** message could include a line like
  ** .ts
  ** [-- PGP output follows ...
  ** .te
  ** .pp
  ** and give it the same color as your attachment color (see also
  ** $$crypt_timestamp).
  */
  { "arrow_cursor",     DT_BOOL, R_MENU, OPT_ARROW_CURSOR, 0 },
  /*
  ** .pp
  ** When \fIset\fP, an arrow (``->'') will be used to indicate the current entry
  ** in menus instead of highlighting the whole line.  On slow network or modem
  ** links this will make response faster because there is less that has to
  ** be redrawn on the screen when moving to the next or previous entries
  ** in the menu.
  */
  { "ascii_chars",      DT_BOOL, R_BOTH, OPT_ASCII_CHARS, 0 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will use plain ASCII characters when displaying thread
  ** and attachment trees, instead of the default \fIACS\fP characters.
  */
  { "askbcc",           DT_BOOL, R_NONE, OPT_ASKBCC, 0 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will prompt you for blind-carbon-copy (Bcc) recipients
  ** before editing an outgoing message.
  */
  { "askcc",            DT_BOOL, R_NONE, OPT_ASKCC, 0 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will prompt you for carbon-copy (Cc) recipients before
  ** editing the body of an outgoing message.
  */
#ifdef USE_NNTP
  { "ask_follow_up",    DT_BOOL, R_NONE, OPT_ASK_FOLLOW_UP, 0 },
  /*
  ** .pp
  ** If set, NeoMutt will prompt you for follow-up groups before editing
  ** the body of an outgoing message.
  */
  { "ask_x_comment_to", DT_BOOL, R_NONE, OPT_ASK_X_COMMENT_TO, 0 },
  /*
  ** .pp
  ** If set, NeoMutt will prompt you for x-comment-to field before editing
  ** the body of an outgoing message.
  */
#endif
  { "assumed_charset", DT_STRING, R_NONE, UL &AssumedCharset, UL 0 },
  /*
  ** .pp
  ** This variable is a colon-separated list of character encoding
  ** schemes for messages without character encoding indication.
  ** Header field values and message body content without character encoding
  ** indication would be assumed that they are written in one of this list.
  ** By default, all the header fields and message body without any charset
  ** indication are assumed to be in ``us-ascii''.
  ** .pp
  ** For example, Japanese users might prefer this:
  ** .ts
  ** set assumed_charset="iso-2022-jp:euc-jp:shift_jis:utf-8"
  ** .te
  ** .pp
  ** However, only the first content is valid for the message body.
  */
  { "attach_charset",    DT_STRING,  R_NONE, UL &AttachCharset, UL 0 },
  /*
  ** .pp
  ** This variable is a colon-separated list of character encoding
  ** schemes for text file attachments. NeoMutt uses this setting to guess
  ** which encoding files being attached are encoded in to convert them to
  ** a proper character set given in $$send_charset.
  ** .pp
  ** If \fIunset\fP, the value of $$charset will be used instead.
  ** For example, the following configuration would work for Japanese
  ** text handling:
  ** .ts
  ** set attach_charset="iso-2022-jp:euc-jp:shift_jis:utf-8"
  ** .te
  ** .pp
  ** Note: for Japanese users, ``iso-2022-*'' must be put at the head
  ** of the value as shown above if included.
  */
  { "attach_format",    DT_STRING,  R_NONE, UL &AttachFormat, UL "%u%D%I %t%4n %T%.40d%> [%.7m/%.10M, %.6e%?C?, %C?, %s] " },
  /*
  ** .pp
  ** This variable describes the format of the ``attachment'' menu.  The
  ** following \fCprintf(3)\fP-style sequences are understood:
  ** .dl
  ** .dt %C  .dd charset
  ** .dt %c  .dd requires charset conversion (``n'' or ``c'')
  ** .dt %D  .dd deleted flag
  ** .dt %d  .dd description (if none, falls back to %F)
  ** .dt %e  .dd MIME content-transfer-encoding
  ** .dt %F  .dd filename in content-disposition header (if none, falls back to %f)
  ** .dt %f  .dd filename
  ** .dt %I  .dd disposition (``I'' for inline, ``A'' for attachment)
  ** .dt %m  .dd major MIME type
  ** .dt %M  .dd MIME subtype
  ** .dt %n  .dd attachment number
  ** .dt %Q  .dd ``Q'', if MIME part qualifies for attachment counting
  ** .dt %s  .dd size
  ** .dt %t  .dd tagged flag
  ** .dt %T  .dd graphic tree characters
  ** .dt %u  .dd unlink (=to delete) flag
  ** .dt %X  .dd number of qualifying MIME parts in this part and its children
  **             (please see the ``$attachments'' section for possible speed effects)
  ** .dt %>X .dd right justify the rest of the string and pad with character ``X''
  ** .dt %|X .dd pad to the end of the line with character ``X''
  ** .dt %*X .dd soft-fill with character ``X'' as pad
  ** .de
  ** .pp
  ** For an explanation of ``soft-fill'', see the $$index_format documentation.
  */
  { "attach_keyword",  DT_REGEX,  R_NONE, UL &AttachKeyword, UL "\\<(attach|attached|attachments?)\\>" },
  /*
  ** .pp
  ** If $abort_noattach is not set to no, then the body of the message
  ** will be scanned for this regular expression, and if found, you will
  ** be prompted if there are no attachments.
  */
  { "attach_sep",       DT_STRING,  R_NONE, UL &AttachSep, UL "\n" },
  /*
  ** .pp
  ** The separator to add between attachments when operating (saving,
  ** printing, piping, etc) on a list of tagged attachments.
  */
  { "attach_split",     DT_BOOL, R_NONE, OPT_ATTACH_SPLIT, 1 },
  /*
  ** .pp
  ** If this variable is \fIunset\fP, when operating (saving, printing, piping,
  ** etc) on a list of tagged attachments, NeoMutt will concatenate the
  ** attachments and will operate on them as a single attachment. The
  ** $$attach_sep separator is added after each attachment. When \fIset\fP,
  ** NeoMutt will operate on the attachments one by one.
  */
  { "attribution",      DT_STRING,  R_NONE, UL &Attribution, UL "On %d, %n wrote:" },
  /*
  ** .pp
  ** This is the string that will precede a message which has been included
  ** in a reply.  For a full listing of defined \fCprintf(3)\fP-like sequences see
  ** the section on $$index_format.
  */
  { "attribution_locale", DT_STRING, R_NONE, UL &AttributionLocale, UL "" },
  /*
  ** .pp
  ** The locale used by \fCstrftime(3)\fP to format dates in the
  ** $attribution string.  Legal values are the strings your system
  ** accepts for the locale environment variable \fC$$$LC_TIME\fP.
  ** .pp
  ** This variable is to allow the attribution date format to be
  ** customized by recipient or folder using hooks.  By default, NeoMutt
  ** will use your locale environment, so there is no need to set
  ** this except to override that default.
  */
  { "auto_tag",         DT_BOOL, R_NONE, OPT_AUTO_TAG, 0 },
  /*
  ** .pp
  ** When \fIset\fP, functions in the \fIindex\fP menu which affect a message
  ** will be applied to all tagged messages (if there are any).  When
  ** unset, you must first use the \fC<tag-prefix>\fP function (bound to ``;''
  ** by default) to make the next function apply to all tagged messages.
  */
  { "autoedit",         DT_BOOL, R_NONE, OPT_AUTOEDIT, 0 },
  /*
  ** .pp
  ** When \fIset\fP along with $$edit_headers, NeoMutt will skip the initial
  ** send-menu (prompting for subject and recipients) and allow you to
  ** immediately begin editing the body of your
  ** message.  The send-menu may still be accessed once you have finished
  ** editing the body of your message.
  ** .pp
  ** \fBNote:\fP when this option is \fIset\fP, you cannot use send-hooks that depend
  ** on the recipients when composing a new (non-reply) message, as the initial
  ** list of recipients is empty.
  ** .pp
  ** Also see $$fast_reply.
  */
  { "beep",             DT_BOOL, R_NONE, OPT_BEEP, 1 },
  /*
  ** .pp
  ** When this variable is \fIset\fP, NeoMutt will beep when an error occurs.
  */
  { "beep_new",         DT_BOOL, R_NONE, OPT_BEEP_NEW, 0 },
  /*
  ** .pp
  ** When this variable is \fIset\fP, NeoMutt will beep whenever it prints a message
  ** notifying you of new mail.  This is independent of the setting of the
  ** $$beep variable.
  */
  { "bounce",   DT_QUAD, R_NONE, OPT_BOUNCE, MUTT_ASKYES },
  /*
  ** .pp
  ** Controls whether you will be asked to confirm bouncing messages.
  ** If set to \fIyes\fP you don't get asked if you want to bounce a
  ** message. Setting this variable to \fIno\fP is not generally useful,
  ** and thus not recommended, because you are unable to bounce messages.
  */
  { "bounce_delivered", DT_BOOL, R_NONE, OPT_BOUNCE_DELIVERED, 1 },
  /*
  ** .pp
  ** When this variable is \fIset\fP, NeoMutt will include Delivered-To headers when
  ** bouncing messages.  Postfix users may wish to \fIunset\fP this variable.
  */
  { "braille_friendly", DT_BOOL, R_NONE, OPT_BRAILLE_FRIENDLY, 0 },
  /*
  ** .pp
  ** When this variable is \fIset\fP, NeoMutt will place the cursor at the beginning
  ** of the current line in menus, even when the $$arrow_cursor variable
  ** is \fIunset\fP, making it easier for blind persons using Braille displays to
  ** follow these menus.  The option is \fIunset\fP by default because many
  ** visual terminals don't permit making the cursor invisible.
  */
#ifdef USE_NNTP
  { "catchup_newsgroup", DT_QUAD, R_NONE, OPT_CATCHUP_NEWSGROUP, MUTT_ASKYES },
  /*
  ** .pp
  ** If this variable is \fIset\fP, NeoMutt will mark all articles in newsgroup
  ** as read when you quit the newsgroup (catchup newsgroup).
  */
#endif
#ifdef USE_SSL
  { "certificate_file", DT_PATH, R_NONE, UL &CertificateFile, UL "~/.mutt_certificates" },
  /*
  ** .pp
  ** This variable specifies the file where the certificates you trust
  ** are saved. When an unknown certificate is encountered, you are asked
  ** if you accept it or not. If you accept it, the certificate can also
  ** be saved in this file and further connections are automatically
  ** accepted.
  ** .pp
  ** You can also manually add CA certificates in this file. Any server
  ** certificate that is signed with one of these CA certificates is
  ** also automatically accepted.
  ** .pp
  ** Example:
  ** .ts
  ** set certificate_file=~/.neomutt/certificates
  ** .te
  **
  */
#endif
  { "charset",          DT_STRING,  R_NONE, UL &Charset, UL 0 },
  /*
  ** .pp
  ** Character set your terminal uses to display and enter textual data.
  ** It is also the fallback for $$send_charset.
  ** .pp
  ** Upon startup NeoMutt tries to derive this value from environment variables
  ** such as \fC$$$LC_CTYPE\fP or \fC$$$LANG\fP.
  ** .pp
  ** \fBNote:\fP It should only be set in case NeoMutt isn't able to determine the
  ** character set used correctly.
  */
  { "check_mbox_size",  DT_BOOL, R_NONE, OPT_CHECK_MBOX_SIZE, 0 },
  /*
  ** .pp
  ** When this variable is \fIset\fP, NeoMutt will use file size attribute instead of
  ** access time when checking for new mail in mbox and mmdf folders.
  ** .pp
  ** This variable is \fIunset\fP by default and should only be enabled when
  ** new mail detection for these folder types is unreliable or doesn't work.
  ** .pp
  ** Note that enabling this variable should happen before any ``$mailboxes''
  ** directives occur in configuration files regarding mbox or mmdf folders
  ** because NeoMutt needs to determine the initial new mail status of such a
  ** mailbox by performing a fast mailbox scan when it is defined.
  ** Afterwards the new mail status is tracked by file size changes.
  */
  { "check_new",        DT_BOOL, R_NONE, OPT_CHECK_NEW, 1 },
  /*
  ** .pp
  ** \fBNote:\fP this option only affects \fImaildir\fP and \fIMH\fP style
  ** mailboxes.
  ** .pp
  ** When \fIset\fP, NeoMutt will check for new mail delivered while the
  ** mailbox is open.  Especially with MH mailboxes, this operation can
  ** take quite some time since it involves scanning the directory and
  ** checking each file to see if it has already been looked at.  If
  ** this variable is \fIunset\fP, no check for new mail is performed
  ** while the mailbox is open.
  */
  { "collapse_unread",  DT_BOOL, R_NONE, OPT_COLLAPSE_UNREAD, 1 },
  /*
  ** .pp
  ** When \fIunset\fP, NeoMutt will not collapse a thread if it contains any
  ** unread messages.
  */
  { "collapse_flagged", DT_BOOL, R_NONE, OPT_COLLAPSE_FLAGGED, 1 },
  /*
  ** .pp
  ** When \fIunset\fP, NeoMutt will not collapse a thread if it contains any
  ** flagged messages.
  */
  { "compose_format",   DT_STRING,  R_MENU, UL &ComposeFormat, UL "-- NeoMutt: Compose  [Approx. msg size: %l   Atts: %a]%>-" },
  /*
  ** .pp
  ** Controls the format of the status line displayed in the ``compose''
  ** menu.  This string is similar to $$status_format, but has its own
  ** set of \fCprintf(3)\fP-like sequences:
  ** .dl
  ** .dt %a .dd total number of attachments
  ** .dt %h .dd local hostname
  ** .dt %l .dd approximate size (in bytes) of the current message
  ** .dt %v .dd NeoMutt version string
  ** .de
  ** .pp
  ** See the text describing the $$status_format option for more
  ** information on how to set $$compose_format.
  */
  { "config_charset",   DT_STRING,  R_NONE, UL &ConfigCharset, UL 0 },
  /*
  ** .pp
  ** When defined, NeoMutt will recode commands in rc files from this
  ** encoding to the current character set as specified by $$charset
  ** and aliases written to $$alias_file from the current character set.
  ** .pp
  ** Please note that if setting $$charset it must be done before
  ** setting $$config_charset.
  ** .pp
  ** Recoding should be avoided as it may render unconvertable
  ** characters as question marks which can lead to undesired
  ** side effects (for example in regular expressions).
  */
  { "confirmappend",    DT_BOOL, R_NONE, OPT_CONFIRMAPPEND, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will prompt for confirmation when appending messages to
  ** an existing mailbox.
  */
  { "confirmcreate",    DT_BOOL, R_NONE, OPT_CONFIRMCREATE, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will prompt for confirmation when saving messages to a
  ** mailbox which does not yet exist before creating it.
  */
  { "connect_timeout",  DT_NUMBER, R_NONE, UL &ConnectTimeout, 30 },
  /*
  ** .pp
  ** Causes NeoMutt to timeout a network connection (for IMAP, POP or SMTP) after this
  ** many seconds if the connection is not able to be established.  A negative
  ** value causes NeoMutt to wait indefinitely for the connection attempt to succeed.
  */
  { "content_type",     DT_STRING, R_NONE, UL &ContentType, UL "text/plain" },
  /*
  ** .pp
  ** Sets the default Content-Type for the body of newly composed messages.
  */
  { "copy",             DT_QUAD, R_NONE, OPT_COPY, MUTT_YES },
  /*
  ** .pp
  ** This variable controls whether or not copies of your outgoing messages
  ** will be saved for later references.  Also see $$record,
  ** $$save_name, $$force_name and ``$fcc-hook''.
  */
  { "pgp_autoencrypt",          DT_SYNONYM,  R_NONE, UL "crypt_autoencrypt", 0 },
  { "crypt_autoencrypt",        DT_BOOL, R_NONE, OPT_CRYPT_AUTOENCRYPT, 0 },
  /*
  ** .pp
  ** Setting this variable will cause NeoMutt to always attempt to PGP
  ** encrypt outgoing messages.  This is probably only useful in
  ** connection to the ``$send-hook'' command.  It can be overridden
  ** by use of the pgp menu, when encryption is not required or
  ** signing is requested as well.  If $$smime_is_default is \fIset\fP,
  ** then OpenSSL is used instead to create S/MIME messages and
  ** settings can be overridden by use of the smime menu instead.
  ** (Crypto only)
  */
  { "crypt_autopgp",    DT_BOOL, R_NONE, OPT_CRYPT_AUTOPGP, 1 },
  /*
  ** .pp
  ** This variable controls whether or not NeoMutt may automatically enable
  ** PGP encryption/signing for messages.  See also $$crypt_autoencrypt,
  ** $$crypt_replyencrypt,
  ** $$crypt_autosign, $$crypt_replysign and $$smime_is_default.
  */
  { "pgp_autosign",     DT_SYNONYM,  R_NONE, UL "crypt_autosign", 0 },
  { "crypt_autosign",   DT_BOOL, R_NONE, OPT_CRYPT_AUTOSIGN, 0 },
  /*
  ** .pp
  ** Setting this variable will cause NeoMutt to always attempt to
  ** cryptographically sign outgoing messages.  This can be overridden
  ** by use of the pgp menu, when signing is not required or
  ** encryption is requested as well. If $$smime_is_default is \fIset\fP,
  ** then OpenSSL is used instead to create S/MIME messages and settings can
  ** be overridden by use of the smime menu instead of the pgp menu.
  ** (Crypto only)
  */
  { "crypt_autosmime",  DT_BOOL, R_NONE, OPT_CRYPT_AUTOSMIME, 1 },
  /*
  ** .pp
  ** This variable controls whether or not NeoMutt may automatically enable
  ** S/MIME encryption/signing for messages. See also $$crypt_autoencrypt,
  ** $$crypt_replyencrypt,
  ** $$crypt_autosign, $$crypt_replysign and $$smime_is_default.
  */
  { "crypt_confirmhook",        DT_BOOL, R_NONE, OPT_CRYPT_CONFIRMHOOK, 1 },
  /*
  ** .pp
  ** If set, then you will be prompted for confirmation of keys when using
  ** the \fIcrypt-hook\fP command.  If unset, no such confirmation prompt will
  ** be presented.  This is generally considered unsafe, especially where
  ** typos are concerned.
  */
  { "crypt_opportunistic_encrypt", DT_BOOL, R_NONE, OPT_CRYPT_OPPORTUNISTIC_ENCRYPT, 0 },
  /*
  ** .pp
  ** Setting this variable will cause NeoMutt to automatically enable and
  ** disable encryption, based on whether all message recipient keys
  ** can be located by NeoMutt.
  ** .pp
  ** When this option is enabled, NeoMutt will enable/disable encryption
  ** each time the TO, CC, and BCC lists are edited.  If
  ** $$edit_headers is set, NeoMutt will also do so each time the message
  ** is edited.
  ** .pp
  ** While this is set, encryption can't be manually enabled/disabled.
  ** The pgp or smime menus provide a selection to temporarily disable
  ** this option for the current message.
  ** .pp
  ** If $$crypt_autoencrypt or $$crypt_replyencrypt enable encryption for
  ** a message, this option will be disabled for that message.  It can
  ** be manually re-enabled in the pgp or smime menus.
  ** (Crypto only)
   */
  { "pgp_replyencrypt",         DT_SYNONYM,  R_NONE, UL "crypt_replyencrypt", 1  },
  { "crypt_replyencrypt",       DT_BOOL, R_NONE, OPT_CRYPT_REPLYENCRYPT, 1 },
  /*
  ** .pp
  ** If \fIset\fP, automatically PGP or OpenSSL encrypt replies to messages which are
  ** encrypted.
  ** (Crypto only)
  */
  { "pgp_replysign",    DT_SYNONYM, R_NONE, UL "crypt_replysign", 0 },
  { "crypt_replysign",  DT_BOOL, R_NONE, OPT_CRYPT_REPLYSIGN, 0 },
  /*
  ** .pp
  ** If \fIset\fP, automatically PGP or OpenSSL sign replies to messages which are
  ** signed.
  ** .pp
  ** \fBNote:\fP this does not work on messages that are encrypted
  ** \fIand\fP signed!
  ** (Crypto only)
  */
  { "pgp_replysignencrypted",   DT_SYNONYM,  R_NONE, UL "crypt_replysignencrypted", 0 },
  { "crypt_replysignencrypted", DT_BOOL, R_NONE, OPT_CRYPT_REPLYSIGNENCRYPTED, 0 },
  /*
  ** .pp
  ** If \fIset\fP, automatically PGP or OpenSSL sign replies to messages
  ** which are encrypted. This makes sense in combination with
  ** $$crypt_replyencrypt, because it allows you to sign all
  ** messages which are automatically encrypted.  This works around
  ** the problem noted in $$crypt_replysign, that NeoMutt is not able
  ** to find out whether an encrypted message is also signed.
  ** (Crypto only)
  */
  { "crypt_timestamp", DT_BOOL, R_NONE, OPT_CRYPT_TIMESTAMP, 1 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will include a time stamp in the lines surrounding
  ** PGP or S/MIME output, so spoofing such lines is more difficult.
  ** If you are using colors to mark these lines, and rely on these,
  ** you may \fIunset\fP this setting.
  ** (Crypto only)
  */
  { "crypt_use_gpgme",  DT_BOOL, R_NONE, OPT_CRYPT_USE_GPGME, 0 },
  /*
  ** .pp
  ** This variable controls the use of the GPGME-enabled crypto backends.
  ** If it is \fIset\fP and NeoMutt was built with gpgme support, the gpgme code for
  ** S/MIME and PGP will be used instead of the classic code.  Note that
  ** you need to set this option in .neomuttrc; it won't have any effect when
  ** used interactively.
  ** .pp
  ** Note that the GPGME backend does not support creating old-style inline
  ** (traditional) PGP encrypted or signed messages (see $$pgp_autoinline).
  */
  { "crypt_use_pka", DT_BOOL, R_NONE, OPT_CRYPT_USE_PKA, 0 },
  /*
  ** .pp
  ** Controls whether NeoMutt uses PKA
  ** (see http://www.g10code.de/docs/pka-intro.de.pdf) during signature
  ** verification (only supported by the GPGME backend).
  */
  { "pgp_verify_sig",   DT_SYNONYM,  R_NONE, UL "crypt_verify_sig", 0 },
  { "crypt_verify_sig", DT_QUAD, R_NONE, OPT_CRYPT_VERIFY_SIG, MUTT_YES },
  /*
  ** .pp
  ** If \fI``yes''\fP, always attempt to verify PGP or S/MIME signatures.
  ** If \fI``ask-*''\fP, ask whether or not to verify the signature.
  ** If \fI``no''\fP, never attempt to verify cryptographic signatures.
  ** (Crypto only)
  */
  { "date_format",      DT_STRING,  R_MENU, UL &DateFormat, UL "!%a, %b %d, %Y at %I:%M:%S%p %Z" },
  /*
  ** .pp
  ** This variable controls the format of the date printed by the ``%d''
  ** sequence in $$index_format.  This is passed to the \fCstrftime(3)\fP
  ** function to process the date, see the man page for the proper syntax.
  ** .pp
  ** Unless the first character in the string is a bang (``!''), the month
  ** and week day names are expanded according to the locale.
  ** If the first character in the string is a
  ** bang, the bang is discarded, and the month and week day names in the
  ** rest of the string are expanded in the \fIC\fP locale (that is in US
  ** English).
  */
#ifdef DEBUG
  { "debug_level", DT_NUMBER, R_NONE, UL &DebugLevel, 0 },
  /*
  ** .pp
  ** The debug level. Note: to debug the early startup process (before the
  ** configuration is loaded), ``-d'' neomutt argument must be used.
  ** debug_level/debug_file are ignored until it's read from the configuration
  ** file.
  */
  { "debug_file", DT_PATH, R_NONE, UL &DebugFile, UL "~/.muttdebug" },
  /*
  ** .pp
  ** The location prefix of the debug file, 0 is append to the debug file
  ** Old debug files are renamed with the prefix 1, 2, 3 and 4.
  ** See ``debug_level'' for more detail.
  */
#endif
  { "default_hook",     DT_STRING,  R_NONE, UL &DefaultHook, UL "~f %s !~P | (~P ~C %s)" },
  /*
  ** .pp
  ** This variable controls how ``$message-hook'', ``$reply-hook'', ``$send-hook'',
  ** ``$send2-hook'', ``$save-hook'', and ``$fcc-hook'' will
  ** be interpreted if they are specified with only a simple regex,
  ** instead of a matching pattern.  The hooks are expanded when they are
  ** declared, so a hook will be interpreted according to the value of this
  ** variable at the time the hook is declared.
  ** .pp
  ** The default value matches
  ** if the message is either from a user matching the regular expression
  ** given, or if it is from you (if the from address matches
  ** ``$alternates'') and is to or cc'ed to a user matching the given
  ** regular expression.
  */
  { "delete",           DT_QUAD, R_NONE, OPT_DELETE, MUTT_ASKYES },
  /*
  ** .pp
  ** Controls whether or not messages are really deleted when closing or
  ** synchronizing a mailbox.  If set to \fIyes\fP, messages marked for
  ** deleting will automatically be purged without prompting.  If set to
  ** \fIno\fP, messages marked for deletion will be kept in the mailbox.
  */
  { "delete_untag",     DT_BOOL, R_NONE, OPT_DELETE_UNTAG, 1 },
  /*
  ** .pp
  ** If this option is \fIset\fP, NeoMutt will untag messages when marking them
  ** for deletion.  This applies when you either explicitly delete a message,
  ** or when you save it to another folder.
  */
  { "digest_collapse",  DT_BOOL, R_NONE, OPT_DIGEST_COLLAPSE, 1 },
  /*
  ** .pp
  ** If this option is \fIset\fP, NeoMutt's received-attachments menu will not show the subparts of
  ** individual messages in a multipart/digest.  To see these subparts, press ``v'' on that menu.
  */
  { "display_filter",   DT_PATH, R_PAGER, UL &DisplayFilter, UL "" },
  /*
  ** .pp
  ** When set, specifies a command used to filter messages.  When a message
  ** is viewed it is passed as standard input to $$display_filter, and the
  ** filtered message is read from the standard output.
  */
  { "dsn_notify",       DT_STRING,  R_NONE, UL &DsnNotify, UL "" },
  /*
  ** .pp
  ** This variable sets the request for when notification is returned.  The
  ** string consists of a comma separated list (no spaces!) of one or more
  ** of the following: \fInever\fP, to never request notification,
  ** \fIfailure\fP, to request notification on transmission failure,
  ** \fIdelay\fP, to be notified of message delays, \fIsuccess\fP, to be
  ** notified of successful transmission.
  ** .pp
  ** Example:
  ** .ts
  ** set dsn_notify="failure,delay"
  ** .te
  ** .pp
  ** \fBNote:\fP when using $$sendmail for delivery, you should not enable
  ** this unless you are either using Sendmail 8.8.x or greater or a MTA
  ** providing a \fCsendmail(1)\fP-compatible interface supporting the \fC-N\fP option
  ** for DSN. For SMTP delivery, DSN support is auto-detected so that it
  ** depends on the server whether DSN will be used or not.
  */
  { "dsn_return",       DT_STRING,  R_NONE, UL &DsnReturn, UL "" },
  /*
  ** .pp
  ** This variable controls how much of your message is returned in DSN
  ** messages.  It may be set to either \fIhdrs\fP to return just the
  ** message header, or \fIfull\fP to return the full message.
  ** .pp
  ** Example:
  ** .ts
  ** set dsn_return=hdrs
  ** .te
  ** .pp
  ** \fBNote:\fP when using $$sendmail for delivery, you should not enable
  ** this unless you are either using Sendmail 8.8.x or greater or a MTA
  ** providing a \fCsendmail(1)\fP-compatible interface supporting the \fC-R\fP option
  ** for DSN. For SMTP delivery, DSN support is auto-detected so that it
  ** depends on the server whether DSN will be used or not.
  */
  { "duplicate_threads",        DT_BOOL, R_RESORT|R_RESORT_INIT|R_INDEX, OPT_DUPLICATE_THREADS, 1 },
  /*
  ** .pp
  ** This variable controls whether NeoMutt, when $$sort is set to \fIthreads\fP, threads
  ** messages with the same Message-Id together.  If it is \fIset\fP, it will indicate
  ** that it thinks they are duplicates of each other with an equals sign
  ** in the thread tree.
  */
  { "edit_headers",     DT_BOOL, R_NONE, OPT_EDIT_HEADERS, 0 },
  /*
  ** .pp
  ** This option allows you to edit the header of your outgoing messages
  ** along with the body of your message.
  ** .pp
  ** Although the compose menu may have localized header labels, the
  ** labels passed to your editor will be standard RFC2822 headers,
  ** (e.g. To:, Cc:, Subject:).  Headers added in your editor must
  ** also be RFC2822 headers, or one of the pseudo headers listed in
  ** ``$edit-header''.  NeoMutt will not understand localized header
  ** labels, just as it would not when parsing an actual email.
  ** .pp
  ** \fBNote\fP that changes made to the References: and Date: headers are
  ** ignored for interoperability reasons.
  */
  { "edit_hdrs",        DT_SYNONYM,  R_NONE, UL "edit_headers", 0 },
  /*
  */
  { "editor",           DT_PATH, R_NONE, UL &Editor, 0 },
  /*
  ** .pp
  ** This variable specifies which editor is used by NeoMutt.
  ** It defaults to the value of the \fC$$$VISUAL\fP, or \fC$$$EDITOR\fP, environment
  ** variable, or to the string ``vi'' if neither of those are set.
  ** .pp
  ** The \fC$$editor\fP string may contain a \fI%s\fP escape, which will be replaced by the name
  ** of the file to be edited.  If the \fI%s\fP escape does not appear in \fC$$editor\fP, a
  ** space and the name to be edited are appended.
  ** .pp
  ** The resulting string is then executed by running
  ** .ts
  ** sh -c 'string'
  ** .te
  ** .pp
  ** where \fIstring\fP is the expansion of \fC$$editor\fP described above.
  */
  { "empty_subject",    DT_STRING, R_NONE, UL &EmptySubject, UL "Re: your mail" },
  /*
  ** .pp
  ** This variable specifies the subject to be used when replying to an email
  ** with an empty subject.  It defaults to "Re: your mail".
  */
  { "encode_from",      DT_BOOL, R_NONE, OPT_ENCODE_FROM, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will quoted-printable encode messages when
  ** they contain the string ``From '' (note the trailing space) in the beginning of a line.
  ** This is useful to avoid the tampering certain mail delivery and transport
  ** agents tend to do with messages (in order to prevent tools from
  ** misinterpreting the line as a mbox message separator).
  */
#ifdef USE_SSL_OPENSSL
  { "entropy_file",     DT_PATH, R_NONE, UL &EntropyFile, 0 },
  /*
  ** .pp
  ** The file which includes random data that is used to initialize SSL
  ** library functions.
  */
#endif
  { "envelope_from_address", DT_ADDRESS, R_NONE, UL &EnvelopeFromAddress, 0 },
  /*
  ** .pp
  ** Manually sets the \fIenvelope\fP sender for outgoing messages.
  ** This value is ignored if $$use_envelope_from is \fIunset\fP.
  */
  { "escape",           DT_STRING,  R_NONE, UL &Escape, UL "~" },
  /*
  ** .pp
  ** Escape character to use for functions in the built-in editor.
  */
  { "fast_reply",       DT_BOOL, R_NONE, OPT_FAST_REPLY, 0 },
  /*
  ** .pp
  ** When \fIset\fP, the initial prompt for recipients and subject are skipped
  ** when replying to messages, and the initial prompt for subject is
  ** skipped when forwarding messages.
  ** .pp
  ** \fBNote:\fP this variable has no effect when the $$autoedit
  ** variable is \fIset\fP.
  */
  { "fcc_attach",       DT_QUAD, R_NONE, OPT_FCC_ATTACH, MUTT_YES },
  /*
  ** .pp
  ** This variable controls whether or not attachments on outgoing messages
  ** are saved along with the main body of your message.
  */
  { "fcc_clear",        DT_BOOL, R_NONE, OPT_FCC_CLEAR, 0 },
  /*
  ** .pp
  ** When this variable is \fIset\fP, FCCs will be stored unencrypted and
  ** unsigned, even when the actual message is encrypted and/or
  ** signed.
  ** (PGP only)
  */
  { "flag_safe", DT_BOOL, R_NONE, OPT_FLAG_SAFE, 0 },
  /*
  ** .pp
  ** If set, flagged messages cannot be deleted.
  */
  { "folder",           DT_PATH, R_NONE, UL &Folder, UL "~/Mail" },
  /*
  ** .pp
  ** Specifies the default location of your mailboxes.  A ``+'' or ``='' at the
  ** beginning of a pathname will be expanded to the value of this
  ** variable.  Note that if you change this variable (from the default)
  ** value you need to make sure that the assignment occurs \fIbefore\fP
  ** you use ``+'' or ``='' for any other variables since expansion takes place
  ** when handling the ``$mailboxes'' command.
  */
  { "folder_format",    DT_STRING,  R_MENU, UL &FolderFormat, UL "%2C %t %N %F %2l %-8.8u %-8.8g %8s %d %f" },
  /*
  ** .pp
  ** This variable allows you to customize the file browser display to your
  ** personal taste.  This string is similar to $$index_format, but has
  ** its own set of \fCprintf(3)\fP-like sequences:
  ** .dl
  ** .dt %C  .dd current file number
  ** .dt %d  .dd date/time folder was last modified
  ** .dt %D  .dd date/time folder was last modified using $$date_format.
  ** .dt %f  .dd filename (``/'' is appended to directory names,
  **             ``@'' to symbolic links and ``*'' to executable
  **             files)
  ** .dt %F  .dd file permissions
  ** .dt %g  .dd group name (or numeric gid, if missing)
  ** .dt %l  .dd number of hard links
  ** .dt %m  .dd number of messages in the mailbox *
  ** .dt %n  .dd number of unread messages in the mailbox *
  ** .dt %N  .dd N if mailbox has new mail, blank otherwise
  ** .dt %s  .dd size in bytes
  ** .dt %t  .dd ``*'' if the file is tagged, blank otherwise
  ** .dt %u  .dd owner name (or numeric uid, if missing)
  ** .dt %>X .dd right justify the rest of the string and pad with character ``X''
  ** .dt %|X .dd pad to the end of the line with character ``X''
  ** .dt %*X .dd soft-fill with character ``X'' as pad
  ** .de
  ** .pp
  ** For an explanation of ``soft-fill'', see the $$index_format documentation.
  ** .pp
  ** * = can be optionally printed if nonzero
  ** .pp
  ** %m, %n, and %N only work for monitored mailboxes.
  ** %m requires $$mail_check_stats to be set.
  ** %n requires $$mail_check_stats to be set (except for IMAP mailboxes).
  */
  { "followup_to",      DT_BOOL, R_NONE, OPT_FOLLOWUP_TO, 1 },
  /*
  ** .pp
  ** Controls whether or not the ``Mail-Followup-To:'' header field is
  ** generated when sending mail.  When \fIset\fP, NeoMutt will generate this
  ** field when you are replying to a known mailing list, specified with
  ** the ``$subscribe'' or ``$lists'' commands.
  ** .pp
  ** This field has two purposes.  First, preventing you from
  ** receiving duplicate copies of replies to messages which you send
  ** to mailing lists, and second, ensuring that you do get a reply
  ** separately for any messages sent to known lists to which you are
  ** not subscribed.
  ** .pp
  ** The header will contain only the list's address
  ** for subscribed lists, and both the list address and your own
  ** email address for unsubscribed lists.  Without this header, a
  ** group reply to your message sent to a subscribed list will be
  ** sent to both the list and your address, resulting in two copies
  ** of the same email for you.
  */
#ifdef USE_NNTP
  { "followup_to_poster", DT_QUAD, R_NONE, OPT_FOLLOWUP_TO_POSTER, MUTT_ASKYES },
  /*
  ** .pp
  ** If this variable is \fIset\fP and the keyword "poster" is present in
  ** \fIFollowup-To\fP header, follow-up to newsgroup function is not
  ** permitted.  The message will be mailed to the submitter of the
  ** message via mail.
  */
#endif
  { "force_name",       DT_BOOL, R_NONE, OPT_FORCE_NAME, 0 },
  /*
  ** .pp
  ** This variable is similar to $$save_name, except that NeoMutt will
  ** store a copy of your outgoing message by the username of the address
  ** you are sending to even if that mailbox does not exist.
  ** .pp
  ** Also see the $$record variable.
  */
  { "forward_attribution_intro", DT_STRING, R_NONE, UL &ForwardAttributionIntro, UL "----- Forwarded message from %f -----" },
  /*
  ** .pp
  ** This is the string that will precede a message which has been forwarded
  ** in the main body of a message (when $$mime_forward is unset).
  ** For a full listing of defined \fCprintf(3)\fP-like sequences see
  ** the section on $$index_format.  See also $$attribution_locale.
  */
  { "forward_attribution_trailer", DT_STRING, R_NONE, UL &ForwardAttributionTrailer, UL "----- End forwarded message -----" },
  /*
  ** .pp
  ** This is the string that will follow a message which has been forwarded
  ** in the main body of a message (when $$mime_forward is unset).
  ** For a full listing of defined \fCprintf(3)\fP-like sequences see
  ** the section on $$index_format.  See also $$attribution_locale.
  */
  { "forward_decode",   DT_BOOL, R_NONE, OPT_FORWARD_DECODE, 1 },
  /*
  ** .pp
  ** Controls the decoding of complex MIME messages into \fCtext/plain\fP when
  ** forwarding a message.  The message header is also RFC2047 decoded.
  ** This variable is only used, if $$mime_forward is \fIunset\fP,
  ** otherwise $$mime_forward_decode is used instead.
  */
  { "forw_decode",      DT_SYNONYM,  R_NONE, UL "forward_decode", 0 },
  /*
  */
  { "forward_decrypt",  DT_BOOL, R_NONE, OPT_FORWARD_DECRYPT, 1 },
  /*
  ** .pp
  ** Controls the handling of encrypted messages when forwarding a message.
  ** When \fIset\fP, the outer layer of encryption is stripped off.  This
  ** variable is only used if $$mime_forward is \fIset\fP and
  ** $$mime_forward_decode is \fIunset\fP.
  ** (PGP only)
  */
  { "forw_decrypt",     DT_SYNONYM,  R_NONE, UL "forward_decrypt", 0 },
  /*
  */
  { "forward_edit",     DT_QUAD, R_NONE, OPT_FORWARD_EDIT, MUTT_YES },
  /*
  ** .pp
  ** This quadoption controls whether or not the user is automatically
  ** placed in the editor when forwarding messages.  For those who always want
  ** to forward with no modification, use a setting of ``no''.
  */
  { "forward_format",   DT_STRING,  R_NONE, UL &ForwardFormat, UL "[%a: %s]" },
  /*
  ** .pp
  ** This variable controls the default subject when forwarding a message.
  ** It uses the same format sequences as the $$index_format variable.
  */
  { "forw_format",      DT_SYNONYM,  R_NONE, UL "forward_format", 0 },
  /*
  */
  { "forward_quote",    DT_BOOL, R_NONE, OPT_FORWARD_QUOTE, 0 },
  /*
  ** .pp
  ** When \fIset\fP, forwarded messages included in the main body of the
  ** message (when $$mime_forward is \fIunset\fP) will be quoted using
  ** $$indent_string.
  */
  { "forw_quote",       DT_SYNONYM,  R_NONE, UL "forward_quote", 0 },
  /*
  */
  { "forward_references", DT_BOOL, R_NONE, OPT_FORWARD_REFERENCES, 0 },
  /*
  ** .pp
  ** When \fIset\fP, forwarded messages set the ``In-Reply-To:'' and
  ** ``References:'' headers in the same way as normal replies would. Hence the
  ** forwarded message becomes part of the original thread instead of starting
  ** a new one.
  */
  { "from",             DT_ADDRESS, R_NONE, UL &From, UL 0 },
  /*
  ** .pp
  ** When \fIset\fP, this variable contains a default from address.  It
  ** can be overridden using ``$my_hdr'' (including from a ``$send-hook'') and
  ** $$reverse_name.  This variable is ignored if $$use_from is \fIunset\fP.
  ** .pp
  ** This setting defaults to the contents of the environment variable \fC$$$EMAIL\fP.
  */
  { "from_chars",               DT_MBTABLE,    R_BOTH, UL &FromChars, 0 },
  /*
  ** .pp
  ** Controls the character used to prefix the %F and %L fields in the
  ** index.
  ** .dl
  ** .dt \fBCharacter\fP .dd \fBDescription\fP
  ** .dt 1 .dd Mail is written by you and has a To address, or has a known mailing list in the To address.
  ** .dt 2 .dd Mail is written by you and has a Cc address, or has a known mailing list in the Cc address.
  ** .dt 3 .dd Mail is written by you and has a Bcc address.
  ** .dt 4 .dd All remaining cases.
  ** .de
  ** .pp
  ** If this is empty or unset (default), the traditional long "To ",
  ** "Cc " and "Bcc " prefixes are used.  If set but too short to
  ** include a character for a particular case, a single space will be
  ** prepended to the field.  To prevent any prefix at all from being
  ** added in a particular case, use the special value CR (aka ^M)
  ** for the corresponding character.
  ** .pp
  ** This slightly odd interface is necessitated by NeoMutt's handling of
  ** string variables; one cannot tell a variable that is unset from one
  ** that is set to the empty string.
  */
  { "gecos_mask",       DT_REGEX,   R_NONE, UL &GecosMask, UL "^[^,]*" },
  /*
  ** .pp
  ** A regular expression used by NeoMutt to parse the GECOS field of a password
  ** entry when expanding the alias.  The default value
  ** will return the string up to the first ``,'' encountered.
  ** If the GECOS field contains a string like ``lastname, firstname'' then you
  ** should set it to ``\fC.*\fP''.
  ** .pp
  ** This can be useful if you see the following behavior: you address an e-mail
  ** to user ID ``stevef'' whose full name is ``Steve Franklin''.  If NeoMutt expands
  ** ``stevef'' to ``"Franklin" stevef@foo.bar'' then you should set the $$gecos_mask to
  ** a regular expression that will match the whole name so NeoMutt will expand
  ** ``Franklin'' to ``Franklin, Steve''.
  */
#ifdef USE_NNTP
  { "group_index_format", DT_STRING, R_BOTH, UL &GroupIndexFormat, UL "%4C %M%N %5s  %-45.45f %d" },
  /*
  ** .pp
  ** This variable allows you to customize the newsgroup browser display to
  ** your personal taste.  This string is similar to ``$index_format'', but
  ** has its own set of printf()-like sequences:
  ** .dl
  ** .dt %C  .dd current newsgroup number
  ** .dt %d  .dd description of newsgroup (becomes from server)
  ** .dt %f  .dd newsgroup name
  ** .dt %M  .dd - if newsgroup not allowed for direct post (moderated for example)
  ** .dt %N  .dd N if newsgroup is new, u if unsubscribed, blank otherwise
  ** .dt %n  .dd number of new articles in newsgroup
  ** .dt %s  .dd number of unread articles in newsgroup
  ** .dt %>X .dd right justify the rest of the string and pad with character "X"
  ** .dt %|X .dd pad to the end of the line with character "X"
  ** .de
  */
#endif
  { "hdr_format",       DT_SYNONYM,  R_NONE, UL "index_format", 0 },
  /*
  */
  { "hdrs",             DT_BOOL, R_NONE, OPT_HDRS, 1 },
  /*
  ** .pp
  ** When \fIunset\fP, the header fields normally added by the ``$my_hdr''
  ** command are not created.  This variable \fImust\fP be unset before
  ** composing a new message or replying in order to take effect.  If \fIset\fP,
  ** the user defined header fields are added to every new message.
  */
  { "header",           DT_BOOL, R_NONE, OPT_HEADER, 0 },
  /*
  ** .pp
  ** When \fIset\fP, this variable causes NeoMutt to include the header
  ** of the message you are replying to into the edit buffer.
  ** The $$weed setting applies.
  */
#ifdef USE_HCACHE
  { "header_cache", DT_PATH, R_NONE, UL &HeaderCache, 0 },
  /*
  ** .pp
  ** This variable points to the header cache database.
  ** If pointing to a directory NeoMutt will contain a header cache
  ** database file per folder, if pointing to a file that file will
  ** be a single global header cache. By default it is \fIunset\fP so no header
  ** caching will be used.
  ** .pp
  ** Header caching can greatly improve speed when opening POP, IMAP
  ** MH or Maildir folders, see ``$caching'' for details.
  */
  { "header_cache_backend", DT_HCACHE, R_NONE, UL &HeaderCacheBackend, UL 0 },
  /*
  ** .pp
  ** This variable specifies the header cache backend.
  */
#if defined(HAVE_QDBM) || defined(HAVE_TC) || defined(HAVE_KC)
  { "header_cache_compress", DT_BOOL, R_NONE, OPT_HEADER_CACHE_COMPRESS, 1 },
  /*
  ** .pp
  ** When NeoMutt is compiled with qdbm, tokyocabinet or kyotocabinet
  ** as header cache backend, this option determines whether the
  ** database will be compressed. Compression results in database
  ** files roughly being one fifth of the usual diskspace, but the
  ** decompression can result in a slower opening of cached folder(s)
  ** which in general is still much faster than opening non header
  ** cached folders.
  */
#endif /* HAVE_QDBM */
#if defined(HAVE_GDBM) || defined(HAVE_BDB)
  { "header_cache_pagesize", DT_STRING, R_NONE, UL &HeaderCachePageSize, UL "16384" },
  /*
  ** .pp
  ** When NeoMutt is compiled with either gdbm or bdb4 as the header cache backend,
  ** this option changes the database page size.  Too large or too small
  ** values can waste space, memory, or CPU time. The default should be more
  ** or less optimal for most use cases.
  */
#endif /* HAVE_GDBM || HAVE_BDB */
#endif /* USE_HCACHE */
  { "header_color_partial", DT_BOOL, R_PAGER_FLOW, OPT_HEADER_COLOR_PARTIAL, 0 },
  /*
  ** .pp
  ** When \fIset\fP, color header regexes behave like color body regexes:
  ** color is applied to the exact text matched by the regex.  When
  ** \fIunset\fP, color is applied to the entire header.
  ** .pp
  ** One use of this option might be to apply color to just the header labels.
  ** .pp
  ** See ``$color'' for more details.
  */
  { "help",             DT_BOOL, R_REFLOW, OPT_HELP, 1 },
  /*
  ** .pp
  ** When \fIset\fP, help lines describing the bindings for the major functions
  ** provided by each menu are displayed on the first line of the screen.
  ** .pp
  ** \fBNote:\fP The binding will not be displayed correctly if the
  ** function is bound to a sequence rather than a single keystroke.  Also,
  ** the help line may not be updated if a binding is changed while NeoMutt is
  ** running.  Since this variable is primarily aimed at new users, neither
  ** of these should present a major problem.
  */
  { "hidden_host",      DT_BOOL, R_NONE, OPT_HIDDEN_HOST, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will skip the host name part of $$hostname variable
  ** when adding the domain part to addresses.  This variable does not
  ** affect the generation of Message-IDs, and it will not lead to the
  ** cut-off of first-level domains.
  */
  { "hide_limited",     DT_BOOL, R_TREE|R_INDEX, OPT_HIDE_LIMITED, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will not show the presence of messages that are hidden
  ** by limiting, in the thread tree.
  */
  { "hide_missing",     DT_BOOL, R_TREE|R_INDEX, OPT_HIDE_MISSING, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will not show the presence of missing messages in the
  ** thread tree.
  */
  { "hide_thread_subject", DT_BOOL, R_TREE|R_INDEX, OPT_HIDE_THREAD_SUBJECT, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will not show the subject of messages in the thread
  ** tree that have the same subject as their parent or closest previously
  ** displayed sibling.
  */
  { "hide_top_limited", DT_BOOL, R_TREE|R_INDEX, OPT_HIDE_TOP_LIMITED, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will not show the presence of messages that are hidden
  ** by limiting, at the top of threads in the thread tree.  Note that when
  ** $$hide_limited is \fIset\fP, this option will have no effect.
  */
  { "hide_top_missing", DT_BOOL, R_TREE|R_INDEX, OPT_HIDE_TOP_MISSING, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will not show the presence of missing messages at the
  ** top of threads in the thread tree.  Note that when $$hide_missing is
  ** \fIset\fP, this option will have no effect.
  */
  { "history",          DT_NUMBER,  R_NONE, UL &History, 10 },
  /*
  ** .pp
  ** This variable controls the size (in number of strings remembered) of
  ** the string history buffer per category. The buffer is cleared each time the
  ** variable is set.
  */
  { "history_file",     DT_PATH, R_NONE, UL &HistoryFile, UL "~/.mutthistory" },
  /*
  ** .pp
  ** The file in which NeoMutt will save its history.
  ** .pp
  ** Also see $$save_history.
  */
  { "history_remove_dups", DT_BOOL, R_NONE, OPT_HISTORY_REMOVE_DUPS, 0 },
  /*
  ** .pp
  ** When \fIset\fP, all of the string history will be scanned for duplicates
  ** when a new entry is added.  Duplicate entries in the $$history_file will
  ** also be removed when it is periodically compacted.
  */
  { "honor_disposition", DT_BOOL, R_NONE, OPT_HONOR_DISPOSITION, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will not display attachments with a
  ** disposition of ``attachment'' inline even if it could
  ** render the part to plain text. These MIME parts can only
  ** be viewed from the attachment menu.
  ** .pp
  ** If \fIunset\fP, NeoMutt will render all MIME parts it can
  ** properly transform to plain text.
  */
  { "honor_followup_to", DT_QUAD, R_NONE, OPT_HONOR_FOLLOWUP_TO, MUTT_YES },
  /*
  ** .pp
  ** This variable controls whether or not a Mail-Followup-To header is
  ** honored when group-replying to a message.
  */
  { "hostname",         DT_STRING,  R_NONE, UL &Hostname, 0 },
  /*
  ** .pp
  ** Specifies the fully-qualified hostname of the system NeoMutt is running on
  ** containing the host's name and the DNS domain it belongs to. It is used
  ** as the domain part (after ``@'') for local email addresses as well as
  ** Message-Id headers.
  ** .pp
  ** Its value is determined at startup as follows: the node's
  ** hostname is first determined by the \fCuname(3)\fP function.  The
  ** domain is then looked up using the \fCgethostname(2)\fP and
  ** \fCgetaddrinfo(3)\fP functions.  If those calls are unable to
  ** determine the domain, the full value returned by uname is used.
  ** Optionally, NeoMutt can be compiled with a fixed domain name in
  ** which case a detected one is not used.
  ** .pp
  ** Also see $$use_domain and $$hidden_host.
  */
#ifdef HAVE_LIBIDN
  { "idn_decode",       DT_BOOL, R_MENU, OPT_IDN_DECODE, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will show you international domain names decoded.
  ** Note: You can use IDNs for addresses even if this is \fIunset\fP.
  ** This variable only affects decoding. (IDN only)
  */
  { "idn_encode",       DT_BOOL, R_MENU, OPT_IDN_ENCODE, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will encode international domain names using
  ** IDN.  Unset this if your SMTP server can handle newer (RFC6531)
  ** UTF-8 encoded domains. (IDN only)
  */
#endif /* HAVE_LIBIDN */
  { "ignore_linear_white_space",    DT_BOOL, R_NONE, OPT_IGNORE_LINEAR_WHITE_SPACE, 0 },
  /*
  ** .pp
  ** This option replaces linear-white-space between encoded-word
  ** and text to a single space to prevent the display of MIME-encoded
  ** ``Subject:'' field from being divided into multiple lines.
  */
  { "ignore_list_reply_to", DT_BOOL, R_NONE, OPT_IGNORE_LIST_REPLY_TO, 0 },
  /*
  ** .pp
  ** Affects the behavior of the \fC<reply>\fP function when replying to
  ** messages from mailing lists (as defined by the ``$subscribe'' or
  ** ``$lists'' commands).  When \fIset\fP, if the ``Reply-To:'' field is
  ** set to the same value as the ``To:'' field, NeoMutt assumes that the
  ** ``Reply-To:'' field was set by the mailing list to automate responses
  ** to the list, and will ignore this field.  To direct a response to the
  ** mailing list when this option is \fIset\fP, use the \fC$<list-reply>\fP
  ** function; \fC<group-reply>\fP will reply to both the sender and the
  ** list.
  */
  { "show_multipart_alternative", DT_STRING, R_NONE, UL &ShowMultipartAlternative, 0 },
  /*
  ** .pp
  ** When \fIset\fP to \fCinfo\fP, the multipart/alternative information is shown.
  ** When \fIset\fP to \fCinline\fP, all of the alternatives are displayed.
  ** When not set, the default behavior is to show only the chosen alternative.
  ** .pp
  */
#ifdef USE_IMAP
  { "imap_authenticators", DT_STRING, R_NONE, UL &ImapAuthenticators, UL 0 },
  /*
  ** .pp
  ** This is a colon-delimited list of authentication methods NeoMutt may
  ** attempt to use to log in to an IMAP server, in the order NeoMutt should
  ** try them.  Authentication methods are either ``login'' or the right
  ** side of an IMAP ``AUTH=xxx'' capability string, e.g. ``digest-md5'', ``gssapi''
  ** or ``cram-md5''. This option is case-insensitive. If it's
  ** \fIunset\fP (the default) NeoMutt will try all available methods,
  ** in order from most-secure to least-secure.
  ** .pp
  ** Example:
  ** .ts
  ** set imap_authenticators="gssapi:cram-md5:login"
  ** .te
  ** .pp
  ** \fBNote:\fP NeoMutt will only fall back to other authentication methods if
  ** the previous methods are unavailable. If a method is available but
  ** authentication fails, NeoMutt will not connect to the IMAP server.
  */
  { "imap_check_subscribed",  DT_BOOL, R_NONE, OPT_IMAP_CHECK_SUBSCRIBED, 0 },
  /*
   ** .pp
   ** When \fIset\fP, NeoMutt will fetch the set of subscribed folders from
   ** your server on connection, and add them to the set of mailboxes
   ** it polls for new mail just as if you had issued individual ``$mailboxes''
   ** commands.
   */
  { "imap_delim_chars",         DT_STRING, R_NONE, UL &ImapDelimChars, UL "/." },
  /*
  ** .pp
  ** This contains the list of characters which you would like to treat
  ** as folder separators for displaying IMAP paths. In particular it
  ** helps in using the ``='' shortcut for your \fIfolder\fP variable.
  */
  { "imap_headers",     DT_STRING, R_INDEX, UL &ImapHeaders, UL 0 },
  /*
  ** .pp
  ** NeoMutt requests these header fields in addition to the default headers
  ** (``Date:'', ``From:'', ``Subject:'', ``To:'', ``Cc:'', ``Message-Id:'',
  ** ``References:'', ``Content-Type:'', ``Content-Description:'', ``In-Reply-To:'',
  ** ``Reply-To:'', ``Lines:'', ``List-Post:'', ``X-Label:'') from IMAP
  ** servers before displaying the index menu. You may want to add more
  ** headers for spam detection.
  ** .pp
  ** \fBNote:\fP This is a space separated list, items should be uppercase
  ** and not contain the colon, e.g. ``X-BOGOSITY X-SPAM-STATUS'' for the
  ** ``X-Bogosity:'' and ``X-Spam-Status:'' header fields.
  */
  { "imap_idle",                DT_BOOL, R_NONE, OPT_IMAP_IDLE, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will attempt to use the IMAP IDLE extension
  ** to check for new mail in the current mailbox. Some servers
  ** (dovecot was the inspiration for this option) react badly
  ** to NeoMutt's implementation. If your connection seems to freeze
  ** up periodically, try unsetting this.
  */
  { "imap_keepalive",           DT_NUMBER,  R_NONE, UL &ImapKeepalive, 300 },
  /*
  ** .pp
  ** This variable specifies the maximum amount of time in seconds that NeoMutt
  ** will wait before polling open IMAP connections, to prevent the server
  ** from closing them before NeoMutt has finished with them. The default is
  ** well within the RFC-specified minimum amount of time (30 minutes) before
  ** a server is allowed to do this, but in practice the RFC does get
  ** violated every now and then. Reduce this number if you find yourself
  ** getting disconnected from your IMAP server due to inactivity.
  */
  { "imap_list_subscribed",     DT_BOOL, R_NONE, OPT_IMAP_LIST_SUBSCRIBED, 0 },
  /*
  ** .pp
  ** This variable configures whether IMAP folder browsing will look for
  ** only subscribed folders or all folders.  This can be toggled in the
  ** IMAP browser with the \fC<toggle-subscribed>\fP function.
  */
  { "imap_login",       DT_STRING,  R_NONE|F_SENSITIVE, UL &ImapLogin, UL 0 },
  /*
  ** .pp
  ** Your login name on the IMAP server.
  ** .pp
  ** This variable defaults to the value of $$imap_user.
  */
  { "imap_pass",        DT_STRING,  R_NONE|F_SENSITIVE, UL &ImapPass, UL 0 },
  /*
  ** .pp
  ** Specifies the password for your IMAP account.  If \fIunset\fP, NeoMutt will
  ** prompt you for your password when you invoke the \fC<imap-fetch-mail>\fP function
  ** or try to open an IMAP folder.
  ** .pp
  ** \fBWarning\fP: you should only use this option when you are on a
  ** fairly secure machine, because the superuser can read your neomuttrc even
  ** if you are the only one who can read the file.
  */
  { "imap_passive",             DT_BOOL, R_NONE, OPT_IMAP_PASSIVE, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will not open new IMAP connections to check for new
  ** mail.  NeoMutt will only check for new mail over existing IMAP
  ** connections.  This is useful if you don't want to be prompted to
  ** user/password pairs on NeoMutt invocation, or if opening the connection
  ** is slow.
  */
  { "imap_peek", DT_BOOL, R_NONE, OPT_IMAP_PEEK, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will avoid implicitly marking your mail as read whenever
  ** you fetch a message from the server. This is generally a good thing,
  ** but can make closing an IMAP folder somewhat slower. This option
  ** exists to appease speed freaks.
  */
  { "imap_pipeline_depth", DT_NUMBER,  R_NONE, UL &ImapPipelineDepth, 15 },
  /*
  ** .pp
  ** Controls the number of IMAP commands that may be queued up before they
  ** are sent to the server. A deeper pipeline reduces the amount of time
  ** NeoMutt must wait for the server, and can make IMAP servers feel much
  ** more responsive. But not all servers correctly handle pipelined commands,
  ** so if you have problems you might want to try setting this variable to 0.
  ** .pp
  ** \fBNote:\fP Changes to this variable have no effect on open connections.
  */
  { "imap_poll_timeout", DT_NUMBER,  R_NONE, UL &ImapPollTimeout, 15 },
  /*
  ** .pp
  ** This variable specifies the maximum amount of time in seconds
  ** that NeoMutt will wait for a response when polling IMAP connections
  ** for new mail, before timing out and closing the connection.  Set
  ** to 0 to disable timing out.
  */
  { "imap_servernoise",         DT_BOOL, R_NONE, OPT_IMAP_SERVERNOISE, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will display warning messages from the IMAP
  ** server as error messages. Since these messages are often
  ** harmless, or generated due to configuration problems on the
  ** server which are out of the users' hands, you may wish to suppress
  ** them at some point.
  */
  { "imap_user",        DT_STRING,  R_NONE|F_SENSITIVE, UL &ImapUser, UL 0 },
  /*
  ** .pp
  ** The name of the user whose mail you intend to access on the IMAP
  ** server.
  ** .pp
  ** This variable defaults to your user name on the local machine.
  */
#endif
  { "implicit_autoview", DT_BOOL,R_NONE, OPT_IMPLICIT_AUTOVIEW, 0 },
  /*
  ** .pp
  ** If set to ``yes'', NeoMutt will look for a mailcap entry with the
  ** ``\fCcopiousoutput\fP'' flag set for \fIevery\fP MIME attachment it doesn't have
  ** an internal viewer defined for.  If such an entry is found, NeoMutt will
  ** use the viewer defined in that entry to convert the body part to text
  ** form.
  */
  { "include",          DT_QUAD, R_NONE, OPT_INCLUDE, MUTT_ASKYES },
  /*
  ** .pp
  ** Controls whether or not a copy of the message(s) you are replying to
  ** is included in your reply.
  */
  { "include_onlyfirst",        DT_BOOL, R_NONE, OPT_INCLUDE_ONLYFIRST, 0 },
  /*
  ** .pp
  ** Controls whether or not NeoMutt includes only the first attachment
  ** of the message you are replying.
  */
  { "indent_string",    DT_STRING,  R_NONE, UL &IndentString, UL "> " },
  /*
  ** .pp
  ** Specifies the string to prepend to each line of text quoted in a
  ** message to which you are replying.  You are strongly encouraged not to
  ** change this value, as it tends to agitate the more fanatical netizens.
  ** .pp
  ** The value of this option is ignored if $$text_flowed is set, because
  ** the quoting mechanism is strictly defined for format=flowed.
  ** .pp
  ** This option is a format string, please see the description of
  ** $$index_format for supported \fCprintf(3)\fP-style sequences.
  */
  { "indent_str",       DT_SYNONYM,  R_NONE, UL "indent_string", 0 },
  /*
  */
  { "index_format",     DT_STRING,  R_BOTH, UL &IndexFormat, UL "%4C %Z %{%b %d} %-15.15L (%?l?%4l&%4c?) %s" },
  /*
  ** .pp
  ** This variable allows you to customize the message index display to
  ** your personal taste.
  ** .pp
  ** ``Format strings'' are similar to the strings used in the C
  ** function \fCprintf(3)\fP to format output (see the man page for more details).
  ** For an explanation of the %? construct, see the $status_format description.
  ** The following sequences are defined in NeoMutt:
  ** .dl
  ** .dt %a .dd address of the author
  ** .dt %A .dd reply-to address (if present; otherwise: address of author)
  ** .dt %b .dd filename of the original message folder (think mailbox)
  ** .dt %B .dd the list to which the letter was sent, or else the folder name (%b).
  ** .dt %c .dd number of characters (bytes) in the message
  ** .dt %C .dd current message number
  ** .dt %d .dd date and time of the message in the format specified by
  **            $$date_format converted to sender's time zone
  ** .dt %D .dd date and time of the message in the format specified by
  **            $$date_format converted to the local time zone
  ** .dt %e .dd current message number in thread
  ** .dt %E .dd number of messages in current thread
  ** .dt %f .dd sender (address + real name), either From: or Return-Path:
  ** .dt %F .dd author name, or recipient name if the message is from you
  ** .dt %g .dd newsgroup name (if compiled with NNTP support)
  ** .dt %g .dd message labels (e.g. notmuch tags)
  ** .dt %H .dd spam attribute(s) of this message
  ** .dt %I .dd initials of author
  ** .dt %i .dd message-id of the current message
  ** .dt %K .dd the list to which the letter was sent (if any; otherwise: empty).
  ** .dt %l .dd number of lines in the message (does not work with maildir,
  **            mh, and possibly IMAP folders)
  ** .dt %L .dd If an address in the ``To:'' or ``Cc:'' header field matches an address
  **            defined by the users ``$subscribe'' command, this displays
  **            "To <list-name>", otherwise the same as %F.
  ** .dt %m .dd total number of message in the mailbox
  ** .dt %M .dd number of hidden messages if the thread is collapsed.
  ** .dt %N .dd message score
  ** .dt %n .dd author's real name (or address if missing)
  ** .dt %O .dd original save folder where NeoMutt would formerly have
  **            stashed the message: list name or recipient name
  **            if not sent to a list
  ** .dt %P .dd progress indicator for the built-in pager (how much of the file has been displayed)
  ** .dt %q .dd newsgroup name (if compiled with NNTP support)
  ** .dt %r .dd comma separated list of ``To:'' recipients
  ** .dt %R .dd comma separated list of ``Cc:'' recipients
  ** .dt %s .dd subject of the message
  ** .dt %S .dd single character status of the message (``N''/``O''/``D''/``d''/``!''/``r''/``\(as'')
  ** .dt %t .dd ``To:'' field (recipients)
  ** .dt %T .dd the appropriate character from the $$to_chars string
  ** .dt %u .dd user (login) name of the author
  ** .dt %v .dd first name of the author, or the recipient if the message is from you
  ** .dt %W .dd name of organization of author (``Organization:'' field)
  ** .dt %x .dd ``X-Comment-To:'' field (if present and compiled with NNTP support)
  ** .dt %X .dd number of attachments
  **            (please see the ``$attachments'' section for possible speed effects)
  ** .dt %y .dd ``X-Label:'' field, if present
  ** .dt %Y .dd ``X-Label:'' field, if present, and \fI(1)\fP not at part of a thread tree,
  **            \fI(2)\fP at the top of a thread, or \fI(3)\fP ``X-Label:'' is different from
  **            preceding message's ``X-Label:''.
  ** .dt %Z .dd a three character set of message status flags.
  **            the first character is new/read/replied flags (``n''/``o''/``r''/``O''/``N'').
  **            the second is deleted or encryption flags (``D''/``d''/``S''/``P''/``s''/``K'').
  **            the third is either tagged/flagged (``\(as''/``!''), or one of the characters
  **            listed in $$to_chars.
  ** .dt %zs .dd message status flags
  ** .dt %zc .dd message crypto flags
  ** .dt %zt .dd message tag flags
  ** .dt %{fmt} .dd the date and time of the message is converted to sender's
  **                time zone, and ``fmt'' is expanded by the library function
  **                \fCstrftime(3)\fP; a leading bang disables locales
  ** .dt %[fmt] .dd the date and time of the message is converted to the local
  **                time zone, and ``fmt'' is expanded by the library function
  **                \fCstrftime(3)\fP; a leading bang disables locales
  ** .dt %(fmt) .dd the local date and time when the message was received.
  **                ``fmt'' is expanded by the library function \fCstrftime(3)\fP;
  **                a leading bang disables locales
  ** .dt %>X    .dd right justify the rest of the string and pad with character ``X''
  ** .dt %|X    .dd pad to the end of the line with character ``X''
  ** .dt %*X    .dd soft-fill with character ``X'' as pad
  ** .de
  ** .pp
  ** Date format expressions can be constructed based on relative dates. Using
  ** the date formatting operators along with nested conditionals, the date
  ** format can be modified based on how old a message is.  See the section on
  ** ``Conditional Dates'' for an explanation and examples
  ** ``Soft-fill'' deserves some explanation: Normal right-justification
  ** will print everything to the left of the ``%>'', displaying padding and
  ** whatever lies to the right only if there's room. By contrast,
  ** soft-fill gives priority to the right-hand side, guaranteeing space
  ** to display it and showing padding only if there's still room. If
  ** necessary, soft-fill will eat text leftwards to make room for
  ** rightward text.
  ** .pp
  ** Note that these expandos are supported in
  ** ``$save-hook'', ``$fcc-hook'' and ``$fcc-save-hook'', too.
  */
#ifdef USE_NNTP
  { "inews",            DT_PATH, R_NONE, UL &Inews, UL "" },
  /*
  ** .pp
  ** If set, specifies the program and arguments used to deliver news posted
  ** by NeoMutt.  Otherwise, NeoMutt posts article using current connection to
  ** news server.  The following printf-style sequence is understood:
  ** .dl
  ** .dt %a .dd account url
  ** .dt %p .dd port
  ** .dt %P .dd port if specified
  ** .dt %s .dd news server name
  ** .dt %S .dd url schema
  ** .dt %u .dd username
  ** .de
  ** .pp
  ** Example:
  ** .ts
  ** set inews="/usr/local/bin/inews -hS"
  ** .te
  */
#endif
  { "ispell",           DT_PATH, R_NONE, UL &Ispell, UL ISPELL },
  /*
  ** .pp
  ** How to invoke ispell (GNU's spell-checking software).
  */
  { "keep_flagged", DT_BOOL, R_NONE, OPT_KEEP_FLAGGED, 0 },
  /*
  ** .pp
  ** If \fIset\fP, read messages marked as flagged will not be moved
  ** from your spool mailbox to your $$mbox mailbox, or as a result of
  ** a ``$mbox-hook'' command.
  */
  { "keywords_legacy", DT_BOOL, R_NONE, OPT_KEYWORDS_LEGACY, 1 },
  /*
  ** .pp
  ** If \fIset\fP, keywords/labels/tags will be written to whatever
  ** legacy, nonstandard headers (X-Label, X-Keywords, X-Mozilla-Keys)
  ** they were sourced from.
  ** .pp
  ** If both ``$$keywords_legacy'' and
  ** ``$$keywords_standard'' are \fCfalse\fP, NeoMutt will save keywords
  ** to legacy headers to ensure that it does not lose your labels.
  */
  { "keywords_standard", DT_BOOL, R_NONE, OPT_KEYWORDS_STANDARD, 0 },
  /*
  ** .pp
  ** If \fIset\fP, keywords/labels/tags will be written to the
  ** RFC2822-standard Keywords: header; this may imply a conversion from
  ** legacy headers.
  ** .pp
  ** If both ``$$keywords_legacy'' and
  ** ``$$keywords_standard'' are \fCfalse\fP, NeoMutt will save keywords
  ** to legacy headers to ensure that it does not lose your labels.
  */
  { "mail_check",       DT_NUMBER,  R_NONE, UL &MailCheck, 5 },
  /*
  ** .pp
  ** This variable configures how often (in seconds) NeoMutt should look for
  ** new mail. Also see the $$timeout variable.
  */
  { "mail_check_recent",DT_BOOL, R_NONE, OPT_MAIL_CHECK_RECENT, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will only notify you about new mail that has been received
  ** since the last time you opened the mailbox.  When \fIunset\fP, NeoMutt will notify you
  ** if any new mail exists in the mailbox, regardless of whether you have visited it
  ** recently.
  ** .pp
  ** When \fI$$mark_old\fP is set, NeoMutt does not consider the mailbox to contain new
  ** mail if only old messages exist.
  */
  { "mail_check_stats", DT_BOOL, R_NONE, OPT_MAIL_CHECK_STATS, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will periodically calculate message
  ** statistics of a mailbox while polling for new mail.  It will
  ** check for unread, flagged, and total message counts.  Because
  ** this operation is more performance intensive, it defaults to
  ** \fIunset\fP, and has a separate option, $$mail_check_stats_interval, to
  ** control how often to update these counts.
  */
  { "mail_check_stats_interval", DT_NUMBER, R_NONE, UL &MailCheckStatsInterval, 60 },
  /*
  ** .pp
  ** When $$mail_check_stats is \fIset\fP, this variable configures
  ** how often (in seconds) NeoMutt will update message counts.
  */
  { "mailcap_path",     DT_STRING,  R_NONE, UL &MailcapPath, 0 },
  /*
  ** .pp
  ** This variable specifies which files to consult when attempting to
  ** display MIME bodies not directly supported by NeoMutt.
  */
  { "mailcap_sanitize", DT_BOOL, R_NONE, OPT_MAILCAP_SANITIZE, 1 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will restrict possible characters in mailcap % expandos
  ** to a well-defined set of safe characters.  This is the safe setting,
  ** but we are not sure it doesn't break some more advanced MIME stuff.
  ** .pp
  ** \fBDON'T CHANGE THIS SETTING UNLESS YOU ARE REALLY SURE WHAT YOU ARE
  ** DOING!\fP
  */
#ifdef USE_HCACHE
  { "maildir_header_cache_verify", DT_BOOL, R_NONE, OPT_MAILDIR_HEADER_CACHE_VERIFY, 1 },
  /*
  ** .pp
  ** Check for Maildir unaware programs other than NeoMutt having modified maildir
  ** files when the header cache is in use.  This incurs one \fCstat(2)\fP per
  ** message every time the folder is opened (which can be very slow for NFS
  ** folders).
  */
#endif
  { "maildir_trash", DT_BOOL, R_NONE, OPT_MAILDIR_TRASH, 0 },
  /*
  ** .pp
  ** If \fIset\fP, messages marked as deleted will be saved with the maildir
  ** trashed flag instead of unlinked.  \fBNote:\fP this only applies
  ** to maildir-style mailboxes.  Setting it will have no effect on other
  ** mailbox types.
  */
  { "maildir_check_cur", DT_BOOL, R_NONE, OPT_MAILDIR_CHECK_CUR, 0 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will poll both the new and cur directories of
  ** a maildir folder for new messages.  This might be useful if other
  ** programs interacting with the folder (e.g. dovecot) are moving new
  ** messages to the cur directory.  Note that setting this option may
  ** slow down polling for new messages in large folders, since NeoMutt has
  ** to scan all cur messages.
  */
  { "mark_macro_prefix",DT_STRING, R_NONE, UL &MarkMacroPrefix, UL "'" },
  /*
  ** .pp
  ** Prefix for macros created using mark-message.  A new macro
  ** automatically generated with \fI<mark-message>a\fP will be composed
  ** from this prefix and the letter \fIa\fP.
  */
  { "mark_old",         DT_BOOL, R_BOTH, OPT_MARK_OLD, 1 },
  /*
  ** .pp
  ** Controls whether or not NeoMutt marks \fInew\fP \fBunread\fP
  ** messages as \fIold\fP if you exit a mailbox without reading them.
  ** With this option \fIset\fP, the next time you start NeoMutt, the messages
  ** will show up with an ``O'' next to them in the index menu,
  ** indicating that they are old.
  */
  { "markers",          DT_BOOL, R_PAGER_FLOW, OPT_MARKERS, 1 },
  /*
  ** .pp
  ** Controls the display of wrapped lines in the internal pager. If set, a
  ** ``+'' marker is displayed at the beginning of wrapped lines.
  ** .pp
  ** Also see the $$smart_wrap variable.
  */
  { "mask",             DT_REGEX,   R_NONE, UL &Mask, UL "!^\\.[^.]" },
  /*
  ** .pp
  ** A regular expression used in the file browser, optionally preceded by
  ** the \fInot\fP operator ``!''.  Only files whose names match this mask
  ** will be shown. The match is always case-sensitive.
  */
  { "mbox",             DT_PATH, R_BOTH, UL &Mbox, UL "~/mbox" },
  /*
  ** .pp
  ** This specifies the folder into which read mail in your $$spoolfile
  ** folder will be appended.
  ** .pp
  ** Also see the $$move variable.
  */
  { "mbox_type",        DT_MAGIC,R_NONE, UL &MboxType, MUTT_MBOX },
  /*
  ** .pp
  ** The default mailbox type used when creating new folders. May be any of
  ** ``mbox'', ``MMDF'', ``MH'' and ``Maildir''. This is overridden by the
  ** \fC-m\fP command-line option.
  */
  { "menu_context",     DT_NUMBER,  R_NONE, UL &MenuContext, 0 },
  /*
  ** .pp
  ** This variable controls the number of lines of context that are given
  ** when scrolling through menus. (Similar to $$pager_context.)
  */
  { "menu_move_off",    DT_BOOL, R_NONE, OPT_MENU_MOVE_OFF, 1 },
  /*
  ** .pp
  ** When \fIunset\fP, the bottom entry of menus will never scroll up past
  ** the bottom of the screen, unless there are less entries than lines.
  ** When \fIset\fP, the bottom entry may move off the bottom.
  */
  { "menu_scroll",      DT_BOOL, R_NONE, OPT_MENU_SCROLL, 0 },
  /*
  ** .pp
  ** When \fIset\fP, menus will be scrolled up or down one line when you
  ** attempt to move across a screen boundary.  If \fIunset\fP, the screen
  ** is cleared and the next or previous page of the menu is displayed
  ** (useful for slow links to avoid many redraws).
  */
#if defined(USE_IMAP) || defined(USE_POP)
  { "message_cache_clean", DT_BOOL, R_NONE, OPT_MESSAGE_CACHE_CLEAN, 0 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will clean out obsolete entries from the message cache when
  ** the mailbox is synchronized. You probably only want to set it
  ** every once in a while, since it can be a little slow
  ** (especially for large folders).
  */
  { "message_cachedir", DT_PATH,        R_NONE, UL &MessageCachedir, 0 },
  /*
  ** .pp
  ** Set this to a directory and NeoMutt will cache copies of messages from
  ** your IMAP and POP servers here. You are free to remove entries at any
  ** time.
  ** .pp
  ** When setting this variable to a directory, NeoMutt needs to fetch every
  ** remote message only once and can perform regular expression searches
  ** as fast as for local folders.
  ** .pp
  ** Also see the $$message_cache_clean variable.
  */
#endif
  { "message_format",   DT_STRING,  R_NONE, UL &MessageFormat, UL "%s" },
  /*
  ** .pp
  ** This is the string displayed in the ``attachment'' menu for
  ** attachments of type \fCmessage/rfc822\fP.  For a full listing of defined
  ** \fCprintf(3)\fP-like sequences see the section on $$index_format.
  */
  { "msg_format",       DT_SYNONYM,  R_NONE, UL "message_format", 0 },
  /*
  */
  { "meta_key",         DT_BOOL, R_NONE, OPT_META_KEY, 0 },
  /*
  ** .pp
  ** If \fIset\fP, forces NeoMutt to interpret keystrokes with the high bit (bit 8)
  ** set as if the user had pressed the Esc key and whatever key remains
  ** after having the high bit removed.  For example, if the key pressed
  ** has an ASCII value of \fC0xf8\fP, then this is treated as if the user had
  ** pressed Esc then ``x''.  This is because the result of removing the
  ** high bit from \fC0xf8\fP is \fC0x78\fP, which is the ASCII character
  ** ``x''.
  */
  { "metoo",            DT_BOOL, R_NONE, OPT_METOO, 0 },
  /*
  ** .pp
  ** If \fIunset\fP, NeoMutt will remove your address (see the ``$alternates''
  ** command) from the list of recipients when replying to a message.
  */
  { "mh_purge",         DT_BOOL, R_NONE, OPT_MH_PURGE, 0 },
  /*
  ** .pp
  ** When \fIunset\fP, NeoMutt will mimic mh's behavior and rename deleted messages
  ** to \fI,<old file name>\fP in mh folders instead of really deleting
  ** them. This leaves the message on disk but makes programs reading the folder
  ** ignore it. If the variable is \fIset\fP, the message files will simply be
  ** deleted.
  ** .pp
  ** This option is similar to $$maildir_trash for Maildir folders.
  */
  { "mh_seq_flagged",   DT_STRING, R_NONE, UL &MhSeqFlagged, UL "flagged" },
  /*
  ** .pp
  ** The name of the MH sequence used for flagged messages.
  */
  { "mh_seq_replied",   DT_STRING, R_NONE, UL &MhSeqReplied, UL "replied" },
  /*
  ** .pp
  ** The name of the MH sequence used to tag replied messages.
  */
  { "mh_seq_unseen",    DT_STRING, R_NONE, UL &MhSeqUnseen, UL "unseen" },
  /*
  ** .pp
  ** The name of the MH sequence used for unseen messages.
  */
  { "mime_forward",     DT_QUAD, R_NONE, OPT_MIME_FORWARD, MUTT_NO },
  /*
  ** .pp
  ** When \fIset\fP, the message you are forwarding will be attached as a
  ** separate \fCmessage/rfc822\fP MIME part instead of included in the main body of the
  ** message.  This is useful for forwarding MIME messages so the receiver
  ** can properly view the message as it was delivered to you. If you like
  ** to switch between MIME and not MIME from mail to mail, set this
  ** variable to ``ask-no'' or ``ask-yes''.
  ** .pp
  ** Also see $$forward_decode and $$mime_forward_decode.
  */
  { "mime_forward_decode", DT_BOOL, R_NONE, OPT_MIME_FORWARD_DECODE, 0 },
  /*
  ** .pp
  ** Controls the decoding of complex MIME messages into \fCtext/plain\fP when
  ** forwarding a message while $$mime_forward is \fIset\fP. Otherwise
  ** $$forward_decode is used instead.
  */
  { "mime_fwd",         DT_SYNONYM,  R_NONE, UL "mime_forward", 0 },
  /*
  */
  { "mime_forward_rest", DT_QUAD, R_NONE, OPT_MIME_FORWARD_REST, MUTT_YES },
  /*
  ** .pp
  ** When forwarding multiple attachments of a MIME message from the attachment
  ** menu, attachments which cannot be decoded in a reasonable manner will
  ** be attached to the newly composed message if this option is \fIset\fP.
  */
#ifdef USE_NNTP
  { "mime_subject",     DT_BOOL, R_NONE, OPT_MIME_SUBJECT, 1 },
  /*
  ** .pp
  ** If \fIunset\fP, 8-bit ``subject:'' line in article header will not be
  ** encoded according to RFC2047 to base64.  This is useful when message
  ** is Usenet article, because MIME for news is nonstandard feature.
  */
#endif
  { "mime_type_query_command", DT_STRING, R_NONE, UL &MimeTypeQueryCommand, UL "" },
  /*
  ** .pp
  ** This specifies a command to run, to determine the mime type of a
  ** new attachment when composing a message.  Unless
  ** $$mime_type_query_first is set, this will only be run if the
  ** attachment's extension is not found in the mime.types file.
  ** .pp
  ** The string may contain a ``%s'', which will be substituted with the
  ** attachment filename.  NeoMutt will add quotes around the string substituted
  ** for ``%s'' automatically according to shell quoting rules, so you should
  ** avoid adding your own.  If no ``%s'' is found in the string, NeoMutt will
  ** append the attachment filename to the end of the string.
  ** .pp
  ** The command should output a single line containing the
  ** attachment's mime type.
  ** .pp
  ** Suggested values are ``xdg-mime query filetype'' or
  ** ``file -bi''.
  */
  { "mime_type_query_first", DT_BOOL, R_NONE, OPT_MIME_TYPE_QUERY_FIRST, 0 },
  /*
  ** .pp
  ** When \fIset\fP, the $$mime_type_query_command will be run before the
  ** mime.types lookup.
  */
#ifdef MIXMASTER
  { "mix_entry_format", DT_STRING,  R_NONE, UL &MixEntryFormat, UL "%4n %c %-16s %a" },
  /*
  ** .pp
  ** This variable describes the format of a remailer line on the mixmaster
  ** chain selection screen.  The following \fCprintf(3)\fP-like sequences are
  ** supported:
  ** .dl
  ** .dt %n .dd The running number on the menu.
  ** .dt %c .dd Remailer capabilities.
  ** .dt %s .dd The remailer's short name.
  ** .dt %a .dd The remailer's e-mail address.
  ** .de
  */
  { "mixmaster",        DT_PATH, R_NONE, UL &Mixmaster, UL MIXMASTER },
  /*
  ** .pp
  ** This variable contains the path to the Mixmaster binary on your
  ** system.  It is used with various sets of parameters to gather the
  ** list of known remailers, and to finally send a message through the
  ** mixmaster chain.
  */
#endif
  { "move",             DT_QUAD, R_NONE, OPT_MOVE, MUTT_NO },
  /*
  ** .pp
  ** Controls whether or not NeoMutt will move read messages
  ** from your spool mailbox to your $$mbox mailbox, or as a result of
  ** a ``$mbox-hook'' command.
  */
  { "narrow_tree",      DT_BOOL, R_TREE|R_INDEX, OPT_NARROW_TREE, 0 },
  /*
  ** .pp
  ** This variable, when \fIset\fP, makes the thread tree narrower, allowing
  ** deeper threads to fit on the screen.
  */
#ifdef USE_SOCKET
  { "net_inc",  DT_NUMBER,  R_NONE, UL &NetInc, 10 },
  /*
   ** .pp
   ** Operations that expect to transfer a large amount of data over the
   ** network will update their progress every $$net_inc kilobytes.
   ** If set to 0, no progress messages will be displayed.
   ** .pp
   ** See also $$read_inc, $$write_inc and $$net_inc.
   */
#endif
  { "new_mail_command", DT_PATH, R_NONE, UL &NewMailCommand, UL NULL },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will call this command after a new message is received.
  ** See the $$status_format documentation for the values that can be formatted
  ** into this command.
  */
#ifdef USE_NNTP
  { "news_cache_dir",   DT_PATH, R_NONE, UL &NewsCacheDir, UL "~/.neomutt" },
  /*
  ** .pp
  ** This variable pointing to directory where NeoMutt will save cached news
  ** articles and headers in. If \fIunset\fP, articles and headers will not be
  ** saved at all and will be reloaded from the server each time.
  */
  { "news_server",      DT_STRING, R_NONE, UL &NewsServer, 0 },
  /*
  ** .pp
  ** This variable specifies domain name or address of NNTP server. It
  ** defaults to the news server specified in the environment variable
  ** $$$NNTPSERVER or contained in the file /etc/nntpserver.  You can also
  ** specify username and an alternative port for each news server, ie:
  ** .pp
  ** [[s]news://][username[:password]@]server[:port]
  */
  { "newsgroups_charset", DT_STRING, R_NONE, UL &NewsgroupsCharset, UL "utf-8" },
  /*
  ** .pp
  ** Character set of newsgroups descriptions.
  */
  { "newsrc",           DT_PATH, R_NONE, UL &NewsRc, UL "~/.newsrc" },
  /*
  ** .pp
  ** The file, containing info about subscribed newsgroups - names and
  ** indexes of read articles.  The following printf-style sequence
  ** is understood:
  ** .dl
  ** .dt %a .dd account url
  ** .dt %p .dd port
  ** .dt %P .dd port if specified
  ** .dt %s .dd news server name
  ** .dt %S .dd url schema
  ** .dt %u .dd username
  ** .de
  */
  { "nntp_authenticators", DT_STRING, R_NONE, UL &NntpAuthenticators, UL 0 },
  /*
  ** .pp
  ** This is a colon-delimited list of authentication methods NeoMutt may
  ** attempt to use to log in to a news server, in the order NeoMutt should
  ** try them.  Authentication methods are either ``user'' or any
  ** SASL mechanism, e.g. ``digest-md5'', ``gssapi'' or ``cram-md5''.
  ** This option is case-insensitive.  If it's \fIunset\fP (the default)
  ** NeoMutt will try all available methods, in order from most-secure to
  ** least-secure.
  ** .pp
  ** Example:
  ** .ts
  ** set nntp_authenticators="digest-md5:user"
  ** .te
  ** .pp
  ** \fBNote:\fP NeoMutt will only fall back to other authentication methods if
  ** the previous methods are unavailable. If a method is available but
  ** authentication fails, NeoMutt will not connect to the IMAP server.
  */
  { "nntp_context",     DT_NUMBER, R_NONE, UL &NntpContext, 1000 },
  /*
  ** .pp
  ** This variable defines number of articles which will be in index when
  ** newsgroup entered.  If active newsgroup have more articles than this
  ** number, oldest articles will be ignored.  Also controls how many
  ** articles headers will be saved in cache when you quit newsgroup.
  */
  { "nntp_listgroup",   DT_BOOL, R_NONE, OPT_NNTP_LISTGROUP, 1 },
  /*
  ** .pp
  ** This variable controls whether or not existence of each article is
  ** checked when newsgroup is entered.
  */
  { "nntp_load_description", DT_BOOL, R_NONE, OPT_NNTP_LOAD_DESCRIPTION, 1 },
  /*
  ** .pp
  ** This variable controls whether or not descriptions for each newsgroup
  ** must be loaded when newsgroup is added to list (first time list
  ** loading or new newsgroup adding).
  */
  { "nntp_user",        DT_STRING, R_NONE|F_SENSITIVE, UL &NntpUser, UL "" },
  /*
  ** .pp
  ** Your login name on the NNTP server.  If \fIunset\fP and NNTP server requires
  ** authentication, NeoMutt will prompt you for your account name when you
  ** connect to news server.
  */
  { "nntp_pass",        DT_STRING, R_NONE|F_SENSITIVE, UL &NntpPass, UL "" },
  /*
  ** .pp
  ** Your password for NNTP account.
  */
  { "nntp_poll",        DT_NUMBER, R_NONE, UL &NntpPoll, 60 },
  /*
  ** .pp
  ** The time in seconds until any operations on newsgroup except post new
  ** article will cause recheck for new news.  If set to 0, NeoMutt will
  ** recheck newsgroup on each operation in index (stepping, read article,
  ** etc.).
  */
#endif
#ifdef USE_NOTMUCH
  { "nm_open_timeout", DT_NUMBER, R_NONE, UL &NmOpenTimeout, 5 },
  /*
   ** .pp
   ** This variable specifies the timeout for database open in seconds.
   */
  { "nm_default_uri", DT_STRING, R_NONE, UL &NmDefaultUri, 0 },
  /*
   ** .pp
   ** This variable specifies the default Notmuch database in format
   ** notmuch://<absolute path>.
   */
  { "nm_hidden_tags", DT_STRING, R_NONE, UL &NmHiddenTags, UL "unread,draft,flagged,passed,replied,attachment,signed,encrypted" },
  /*
   ** .pp
   ** This variable specifies private notmuch tags which should not be printed
   ** on screen.
   */
  { "nm_exclude_tags", DT_STRING,  R_NONE, UL &NmExcludeTags, 0 },
  /*
   ** .pp
   ** The messages tagged with these tags are excluded and not loaded
   ** from notmuch DB to NeoMutt unless specified explicitly.
   */
  { "nm_unread_tag", DT_STRING, R_NONE, UL &NmUnreadTag, UL "unread" },
  /*
   ** .pp
   ** This variable specifies notmuch tag which is used for unread messages. The
   ** variable is used to count unread messages in DB only. All other NeoMutt commands
   ** use standard (e.g. maildir) flags.
   */
  { "nm_db_limit", DT_NUMBER, R_NONE, UL &NmDbLimit, 0 },
  /*
   ** .pp
   ** This variable specifies the default limit used in notmuch queries.
   */
  { "nm_query_type", DT_STRING, R_NONE, UL &NmQueryType, UL "messages" },
  /*
   ** .pp
   ** This variable specifies the default query type (threads or messages) used in notmuch queries.
   */
  { "nm_record", DT_BOOL, R_NONE, OPT_NM_RECORD, 0 },
  /*
   ** .pp
   ** This variable specifies if the NeoMutt record should indexed by notmuch.
   */
  { "nm_record_tags", DT_STRING, R_NONE, UL &NmRecordTags, 0 },
  /*
   ** .pp
   ** This variable specifies the default tags applied to messages stored to the NeoMutt record.
   ** When set to 0 this variable disable the window feature.
   */
  { "nm_query_window_duration", DT_NUMBER, R_NONE, UL &NmQueryWindowDuration, 0 },
  /*
   ** .pp
   ** This variable sets the time base of a windowed notmuch query.
   ** Accepted values are 'minute', 'hour', 'day', 'week', 'month', 'year'
   */
  { "nm_query_window_timebase", DT_STRING, R_NONE, UL &NmQueryWindowTimebase, UL "week" },
  /*
   ** .pp
   ** This variable sets the time duration of a windowed notmuch query.
   ** Accepted values all non negative integers. A value of 0 disables the feature.
   */
  { "nm_query_window_current_search", DT_STRING, R_NONE, UL &NmQueryWindowCurrentSearch, UL "" },
  /*
   ** .pp
   ** This variable sets the time duration of a windowed notmuch query.
   ** Accepted values all non negative integers. A value of 0 disables the feature.
   */
  { "nm_query_window_current_position", DT_NUMBER, R_NONE, UL &NmQueryWindowCurrentPosition, 0 },
  /*
   ** .pp
   ** This variable contains the currently setup notmuch search for window based vfolder.
   */
#endif
  { "pager",            DT_PATH, R_NONE, UL &Pager, UL "builtin" },
  /*
  ** .pp
  ** This variable specifies which pager you would like to use to view
  ** messages. The value ``builtin'' means to use the built-in pager, otherwise this
  ** variable should specify the pathname of the external pager you would
  ** like to use.
  ** .pp
  ** Using an external pager may have some disadvantages: Additional
  ** keystrokes are necessary because you can't call NeoMutt functions
  ** directly from the pager, and screen resizes cause lines longer than
  ** the screen width to be badly formatted in the help menu.
  */
  { "pager_context",    DT_NUMBER,  R_NONE, UL &PagerContext, 0 },
  /*
  ** .pp
  ** This variable controls the number of lines of context that are given
  ** when displaying the next or previous page in the internal pager.  By
  ** default, NeoMutt will display the line after the last one on the screen
  ** at the top of the next page (0 lines of context).
  ** .pp
  ** This variable also specifies the amount of context given for search
  ** results. If positive, this many lines will be given before a match,
  ** if 0, the match will be top-aligned.
  */
  { "pager_format",     DT_STRING,  R_PAGER, UL &PagerFormat, UL "-%Z- %C/%m: %-20.20n   %s%*  -- (%P)" },
  /*
  ** .pp
  ** This variable controls the format of the one-line message ``status''
  ** displayed before each message in either the internal or an external
  ** pager.  The valid sequences are listed in the $$index_format
  ** section.
  */
  { "pager_index_lines",DT_NUMBER,  R_PAGER, UL &PagerIndexLines, 0 },
  /*
  ** .pp
  ** Determines the number of lines of a mini-index which is shown when in
  ** the pager.  The current message, unless near the top or bottom of the
  ** folder, will be roughly one third of the way down this mini-index,
  ** giving the reader the context of a few messages before and after the
  ** message.  This is useful, for example, to determine how many messages
  ** remain to be read in the current thread.  One of the lines is reserved
  ** for the status bar from the index, so a setting of 6
  ** will only show 5 lines of the actual index.  A value of 0 results in
  ** no index being shown.  If the number of messages in the current folder
  ** is less than $$pager_index_lines, then the index will only use as
  ** many lines as it needs.
  */
  { "pager_stop",       DT_BOOL, R_NONE, OPT_PAGER_STOP, 0 },
  /*
  ** .pp
  ** When \fIset\fP, the internal-pager will \fBnot\fP move to the next message
  ** when you are at the end of a message and invoke the \fC<next-page>\fP
  ** function.
  */
  { "pgp_auto_decode", DT_BOOL, R_NONE, OPT_PGP_AUTO_DECODE, 0 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will automatically attempt to decrypt traditional PGP
  ** messages whenever the user performs an operation which ordinarily would
  ** result in the contents of the message being operated on.  For example,
  ** if the user displays a pgp-traditional message which has not been manually
  ** checked with the \fC$<check-traditional-pgp>\fP function, NeoMutt will automatically
  ** check the message for traditional pgp.
  */
  { "pgp_create_traditional",   DT_SYNONYM, R_NONE, UL "pgp_autoinline", 0 },
  { "pgp_autoinline",           DT_BOOL, R_NONE, OPT_PGP_AUTOINLINE, 0 },
  /*
  ** .pp
  ** This option controls whether NeoMutt generates old-style inline
  ** (traditional) PGP encrypted or signed messages under certain
  ** circumstances.  This can be overridden by use of the pgp menu,
  ** when inline is not required.  The GPGME backend does not support
  ** this option.
  ** .pp
  ** Note that NeoMutt might automatically use PGP/MIME for messages
  ** which consist of more than a single MIME part.  NeoMutt can be
  ** configured to ask before sending PGP/MIME messages when inline
  ** (traditional) would not work.
  ** .pp
  ** Also see the $$pgp_mime_auto variable.
  ** .pp
  ** Also note that using the old-style PGP message format is \fBstrongly\fP
  ** \fBdeprecated\fP.
  ** (PGP only)
  */
  { "pgp_check_exit",   DT_BOOL, R_NONE, OPT_PGP_CHECK_EXIT, 1 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will check the exit code of the PGP subprocess when
  ** signing or encrypting.  A non-zero exit code means that the
  ** subprocess failed.
  ** (PGP only)
  */
  { "pgp_clearsign_command",    DT_STRING, R_NONE, UL &PgpClearSignCommand, 0 },
  /*
  ** .pp
  ** This format is used to create an old-style ``clearsigned'' PGP
  ** message.  Note that the use of this format is \fBstrongly\fP
  ** \fBdeprecated\fP.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pgp_decode_command",       DT_STRING, R_NONE, UL &PgpDecodeCommand, 0 },
  /*
  ** .pp
  ** This format strings specifies a command which is used to decode
  ** application/pgp attachments.
  ** .pp
  ** The PGP command formats have their own set of \fCprintf(3)\fP-like sequences:
  ** .dl
  ** .dt %p .dd Expands to PGPPASSFD=0 when a pass phrase is needed, to an empty
  **            string otherwise. Note: This may be used with a %? construct.
  ** .dt %f .dd Expands to the name of a file containing a message.
  ** .dt %s .dd Expands to the name of a file containing the signature part
  ** .          of a \fCmultipart/signed\fP attachment when verifying it.
  ** .dt %a .dd The value of $$pgp_sign_as.
  ** .dt %r .dd One or more key IDs (or fingerprints if available).
  ** .de
  ** .pp
  ** For examples on how to configure these formats for the various versions
  ** of PGP which are floating around, see the pgp and gpg sample configuration files in
  ** the \fCsamples/\fP subdirectory which has been installed on your system
  ** alongside the documentation.
  ** (PGP only)
  */
  { "pgp_decrypt_command",      DT_STRING, R_NONE, UL &PgpDecryptCommand, 0 },
  /*
  ** .pp
  ** This command is used to decrypt a PGP encrypted message.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pgp_decryption_okay",      DT_REGEX,  R_NONE, UL &PgpDecryptionOkay, 0 },
  /*
  ** .pp
  ** If you assign text to this variable, then an encrypted PGP
  ** message is only considered successfully decrypted if the output
  ** from $$pgp_decrypt_command contains the text.  This is used to
  ** protect against a spoofed encrypted message, with multipart/encrypted
  ** headers but containing a block that is not actually encrypted.
  ** (e.g. simply signed and ascii armored text).
  ** (PGP only)
  */
  { "pgp_encrypt_only_command", DT_STRING, R_NONE, UL &PgpEncryptOnlyCommand, 0 },
  /*
  ** .pp
  ** This command is used to encrypt a body part without signing it.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pgp_encrypt_sign_command", DT_STRING, R_NONE, UL &PgpEncryptSignCommand, 0 },
  /*
  ** .pp
  ** This command is used to both sign and encrypt a body part.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pgp_entry_format", DT_STRING,  R_NONE, UL &PgpEntryFormat, UL "%4n %t%f %4l/0x%k %-4a %2c %u" },
  /*
  ** .pp
  ** This variable allows you to customize the PGP key selection menu to
  ** your personal taste. This string is similar to $$index_format, but
  ** has its own set of \fCprintf(3)\fP-like sequences:
  ** .dl
  ** .dt %n     .dd number
  ** .dt %k     .dd key id
  ** .dt %u     .dd user id
  ** .dt %a     .dd algorithm
  ** .dt %l     .dd key length
  ** .dt %p     .dd protocol
  ** .dt %f     .dd flags
  ** .dt %c     .dd capabilities
  ** .dt %t     .dd trust/validity of the key-uid association
  ** .dt %[<s>] .dd date of the key where <s> is an \fCstrftime(3)\fP expression
  ** .de
  ** .pp
  ** (PGP only)
  */
  { "pgp_export_command",       DT_STRING, R_NONE, UL &PgpExportCommand, 0 },
  /*
  ** .pp
  ** This command is used to export a public key from the user's
  ** key ring.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pgp_getkeys_command",      DT_STRING, R_NONE, UL &PgpGetkeysCommand, 0 },
  /*
  ** .pp
  ** This command is invoked whenever NeoMutt needs to fetch the public key associated with
  ** an email address.  Of the sequences supported by $$pgp_decode_command, %r is
  ** the only \fCprintf(3)\fP-like sequence used with this format.  Note that
  ** in this case, %r expands to the email address, not the public key ID (the key ID is
  ** unknown, which is why NeoMutt is invoking this command).
  ** (PGP only)
  */
  { "pgp_good_sign",    DT_REGEX,  R_NONE, UL &PgpGoodSign, 0 },
  /*
  ** .pp
  ** If you assign a text to this variable, then a PGP signature is only
  ** considered verified if the output from $$pgp_verify_command contains
  ** the text. Use this variable if the exit code from the command is 0
  ** even for bad signatures.
  ** (PGP only)
  */
  { "pgp_ignore_subkeys", DT_BOOL, R_NONE, OPT_PGP_IGNORE_SUBKEYS, 1 },
  /*
  ** .pp
  ** Setting this variable will cause NeoMutt to ignore OpenPGP subkeys. Instead,
  ** the principal key will inherit the subkeys' capabilities.  \fIUnset\fP this
  ** if you want to play interesting key selection games.
  ** (PGP only)
  */
  { "pgp_import_command",       DT_STRING, R_NONE, UL &PgpImportCommand, 0 },
  /*
  ** .pp
  ** This command is used to import a key from a message into
  ** the user's public key ring.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pgp_list_pubring_command", DT_STRING, R_NONE, UL &PgpListPubringCommand, 0 },
  /*
  ** .pp
  ** This command is used to list the public key ring's contents.  The
  ** output format must be analogous to the one used by
  ** .ts
  ** gpg --list-keys --with-colons --with-fingerprint
  ** .te
  ** .pp
  ** This format is also generated by the \fCpgpring\fP utility which comes
  ** with NeoMutt.
  ** .pp
  ** Note: gpg's \fCfixed-list-mode\fP option should not be used.  It
  ** produces a different date format which may result in NeoMutt showing
  ** incorrect key generation dates.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pgp_list_secring_command", DT_STRING, R_NONE, UL &PgpListSecringCommand, 0 },
  /*
  ** .pp
  ** This command is used to list the secret key ring's contents.  The
  ** output format must be analogous to the one used by:
  ** .ts
  ** gpg --list-keys --with-colons --with-fingerprint
  ** .te
  ** .pp
  ** This format is also generated by the \fCpgpring\fP utility which comes
  ** with NeoMutt.
  ** .pp
  ** Note: gpg's \fCfixed-list-mode\fP option should not be used.  It
  ** produces a different date format which may result in NeoMutt showing
  ** incorrect key generation dates.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pgp_long_ids",     DT_BOOL, R_NONE, OPT_PGP_LONG_IDS, 1 },
  /*
  ** .pp
  ** If \fIset\fP, use 64 bit PGP key IDs, if \fIunset\fP use the normal 32 bit key IDs.
  ** NOTE: Internally, NeoMutt has transitioned to using fingerprints (or long key IDs
  ** as a fallback).  This option now only controls the display of key IDs
  ** in the key selection menu and a few other places.
  ** (PGP only)
  */
  { "pgp_mime_auto", DT_QUAD, R_NONE, OPT_PGP_MIME_AUTO, MUTT_ASKYES },
  /*
  ** .pp
  ** This option controls whether NeoMutt will prompt you for
  ** automatically sending a (signed/encrypted) message using
  ** PGP/MIME when inline (traditional) fails (for any reason).
  ** .pp
  ** Also note that using the old-style PGP message format is \fBstrongly\fP
  ** \fBdeprecated\fP.
  ** (PGP only)
  */
  { "pgp_auto_traditional",     DT_SYNONYM, R_NONE, UL "pgp_replyinline", 0 },
  { "pgp_replyinline",          DT_BOOL, R_NONE, OPT_PGP_REPLYINLINE, 0 },
  /*
  ** .pp
  ** Setting this variable will cause NeoMutt to always attempt to
  ** create an inline (traditional) message when replying to a
  ** message which is PGP encrypted/signed inline.  This can be
  ** overridden by use of the pgp menu, when inline is not
  ** required.  This option does not automatically detect if the
  ** (replied-to) message is inline; instead it relies on NeoMutt
  ** internals for previously checked/flagged messages.
  ** .pp
  ** Note that NeoMutt might automatically use PGP/MIME for messages
  ** which consist of more than a single MIME part.  NeoMutt can be
  ** configured to ask before sending PGP/MIME messages when inline
  ** (traditional) would not work.
  ** .pp
  ** Also see the $$pgp_mime_auto variable.
  ** .pp
  ** Also note that using the old-style PGP message format is \fBstrongly\fP
  ** \fBdeprecated\fP.
  ** (PGP only)
  **
  */
  { "pgp_retainable_sigs", DT_BOOL, R_NONE, OPT_PGP_RETAINABLE_SIGS, 0 },
  /*
  ** .pp
  ** If \fIset\fP, signed and encrypted messages will consist of nested
  ** \fCmultipart/signed\fP and \fCmultipart/encrypted\fP body parts.
  ** .pp
  ** This is useful for applications like encrypted and signed mailing
  ** lists, where the outer layer (\fCmultipart/encrypted\fP) can be easily
  ** removed, while the inner \fCmultipart/signed\fP part is retained.
  ** (PGP only)
  */
  { "pgp_self_encrypt",    DT_BOOL, R_NONE, OPT_PGP_SELF_ENCRYPT, 0 },
  /*
  ** .pp
  ** When \fIset\fP, PGP encrypted messages will also be encrypted
  ** using the key in $$pgp_self_encrypt_as.
  ** (PGP only)
  */
  { "pgp_self_encrypt_as", DT_STRING,  R_NONE, UL &PgpSelfEncryptAs, 0 },
  /*
  ** .pp
  ** This is an additional key used to encrypt messages when $$pgp_self_encrypt
  ** is \fIset\fP.  It is also used to specify the key for $$postpone_encrypt.
  ** It should be in keyid or fingerprint form (e.g. 0x00112233).
  ** (PGP only)
  */
  { "pgp_show_unusable", DT_BOOL, R_NONE, OPT_PGP_SHOW_UNUSABLE, 1 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will display non-usable keys on the PGP key selection
  ** menu.  This includes keys which have been revoked, have expired, or
  ** have been marked as ``disabled'' by the user.
  ** (PGP only)
  */
  { "pgp_sign_as",      DT_STRING,  R_NONE, UL &PgpSignAs, 0 },
  /*
  ** .pp
  ** If you have more than one key pair, this option allows you to specify
  ** which of your private keys to use.  It is recommended that you use the
  ** keyid form to specify your key (e.g. \fC0x00112233\fP).
  ** (PGP only)
  */
  { "pgp_sign_command",         DT_STRING, R_NONE, UL &PgpSignCommand, 0 },
  /*
  ** .pp
  ** This command is used to create the detached PGP signature for a
  ** \fCmultipart/signed\fP PGP/MIME body part.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pgp_sort_keys",    DT_SORT|DT_SORT_KEYS, R_NONE, UL &PgpSortKeys, SORT_ADDRESS },
  /*
  ** .pp
  ** Specifies how the entries in the pgp menu are sorted. The
  ** following are legal values:
  ** .dl
  ** .dt address .dd sort alphabetically by user id
  ** .dt keyid   .dd sort alphabetically by key id
  ** .dt date    .dd sort by key creation date
  ** .dt trust   .dd sort by the trust of the key
  ** .de
  ** .pp
  ** If you prefer reverse order of the above values, prefix it with
  ** ``reverse-''.
  ** (PGP only)
  */
  { "pgp_strict_enc",   DT_BOOL, R_NONE, OPT_PGP_STRICT_ENC, 1 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will automatically encode PGP/MIME signed messages as
  ** quoted-printable.  Please note that unsetting this variable may
  ** lead to problems with non-verifyable PGP signatures, so only change
  ** this if you know what you are doing.
  ** (PGP only)
  */
  { "pgp_timeout",      DT_NUMBER,  R_NONE, UL &PgpTimeout, 300 },
  /*
  ** .pp
  ** The number of seconds after which a cached passphrase will expire if
  ** not used.
  ** (PGP only)
  */
  { "pgp_use_gpg_agent", DT_BOOL, R_NONE, OPT_PGP_USE_GPG_AGENT, 0 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will use a possibly-running \fCgpg-agent(1)\fP process.
  ** Note that as of version 2.1, GnuPG no longer exports GPG_AGENT_INFO, so
  ** NeoMutt no longer verifies if the agent is running.
  ** (PGP only)
  */
  { "pgp_verify_command",       DT_STRING, R_NONE, UL &PgpVerifyCommand, 0 },
  /*
  ** .pp
  ** This command is used to verify PGP signatures.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pgp_verify_key_command",   DT_STRING, R_NONE, UL &PgpVerifyKeyCommand, 0 },
  /*
  ** .pp
  ** This command is used to verify key information from the key selection
  ** menu.
  ** .pp
  ** This is a format string, see the $$pgp_decode_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (PGP only)
  */
  { "pipe_decode",      DT_BOOL, R_NONE, OPT_PIPE_DECODE, 0 },
  /*
  ** .pp
  ** Used in connection with the \fC<pipe-message>\fP command.  When \fIunset\fP,
  ** NeoMutt will pipe the messages without any preprocessing. When \fIset\fP, NeoMutt
  ** will weed headers and will attempt to decode the messages
  ** first.
  */
  { "pipe_sep",         DT_STRING,  R_NONE, UL &PipeSep, UL "\n" },
  /*
  ** .pp
  ** The separator to add between messages when piping a list of tagged
  ** messages to an external Unix command.
  */
  { "pipe_split",       DT_BOOL, R_NONE, OPT_PIPE_SPLIT, 0 },
  /*
  ** .pp
  ** Used in connection with the \fC<pipe-message>\fP function following
  ** \fC<tag-prefix>\fP.  If this variable is \fIunset\fP, when piping a list of
  ** tagged messages NeoMutt will concatenate the messages and will pipe them
  ** all concatenated.  When \fIset\fP, NeoMutt will pipe the messages one by one.
  ** In both cases the messages are piped in the current sorted order,
  ** and the $$pipe_sep separator is added after each message.
  */
#ifdef USE_POP
  { "pop_auth_try_all", DT_BOOL, R_NONE, OPT_POP_AUTH_TRY_ALL, 1 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will try all available authentication methods.
  ** When \fIunset\fP, NeoMutt will only fall back to other authentication
  ** methods if the previous methods are unavailable. If a method is
  ** available but authentication fails, NeoMutt will not connect to the POP server.
  */
  { "pop_authenticators", DT_STRING, R_NONE, UL &PopAuthenticators, UL 0 },
  /*
  ** .pp
  ** This is a colon-delimited list of authentication methods NeoMutt may
  ** attempt to use to log in to an POP server, in the order NeoMutt should
  ** try them.  Authentication methods are either ``user'', ``apop'' or any
  ** SASL mechanism, e.g. ``digest-md5'', ``gssapi'' or ``cram-md5''.
  ** This option is case-insensitive. If this option is \fIunset\fP
  ** (the default) NeoMutt will try all available methods, in order from
  ** most-secure to least-secure.
  ** .pp
  ** Example:
  ** .ts
  ** set pop_authenticators="digest-md5:apop:user"
  ** .te
  */
  { "pop_checkinterval", DT_NUMBER, R_NONE, UL &PopCheckinterval, 60 },
  /*
  ** .pp
  ** This variable configures how often (in seconds) NeoMutt should look for
  ** new mail in the currently selected mailbox if it is a POP mailbox.
  */
  { "pop_delete",       DT_QUAD, R_NONE, OPT_POP_DELETE, MUTT_ASKNO },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will delete successfully downloaded messages from the POP
  ** server when using the \fC$<fetch-mail>\fP function.  When \fIunset\fP, NeoMutt will
  ** download messages but also leave them on the POP server.
  */
  { "pop_host",         DT_STRING,  R_NONE, UL &PopHost, UL "" },
  /*
  ** .pp
  ** The name of your POP server for the \fC$<fetch-mail>\fP function.  You
  ** can also specify an alternative port, username and password, i.e.:
  ** .ts
  ** [pop[s]://][username[:password]@]popserver[:port]
  ** .te
  ** .pp
  ** where ``[...]'' denotes an optional part.
  */
  { "pop_last",         DT_BOOL, R_NONE, OPT_POP_LAST, 0 },
  /*
  ** .pp
  ** If this variable is \fIset\fP, NeoMutt will try to use the ``\fCLAST\fP'' POP command
  ** for retrieving only unread messages from the POP server when using
  ** the \fC$<fetch-mail>\fP function.
  */
  { "pop_pass",         DT_STRING,  R_NONE|F_SENSITIVE, UL &PopPass, UL "" },
  /*
  ** .pp
  ** Specifies the password for your POP account.  If \fIunset\fP, NeoMutt will
  ** prompt you for your password when you open a POP mailbox.
  ** .pp
  ** \fBWarning\fP: you should only use this option when you are on a
  ** fairly secure machine, because the superuser can read your neomuttrc
  ** even if you are the only one who can read the file.
  */
  { "pop_reconnect",    DT_QUAD, R_NONE, OPT_POP_RECONNECT, MUTT_ASKYES },
  /*
  ** .pp
  ** Controls whether or not NeoMutt will try to reconnect to the POP server if
  ** the connection is lost.
  */
  { "pop_user",         DT_STRING,  R_NONE|F_SENSITIVE, UL &PopUser, 0 },
  /*
  ** .pp
  ** Your login name on the POP server.
  ** .pp
  ** This variable defaults to your user name on the local machine.
  */
#endif /* USE_POP */
  { "post_indent_string",DT_STRING, R_NONE, UL &PostIndentString, UL "" },
  /*
  ** .pp
  ** Similar to the $$attribution variable, NeoMutt will append this
  ** string after the inclusion of a message which is being replied to.
  */
  { "post_indent_str",  DT_SYNONYM,  R_NONE, UL "post_indent_string", 0 },
  /*
  */
#ifdef USE_NNTP
  { "post_moderated",   DT_QUAD, R_NONE, OPT_POST_MODERATED, MUTT_ASKYES },
  /*
  ** .pp
  ** If set to \fIyes\fP, NeoMutt will post article to newsgroup that have
  ** not permissions to posting (e.g. moderated).  \fBNote:\fP if news server
  ** does not support posting to that newsgroup or totally read-only, that
  ** posting will not have an effect.
  */
#endif
  { "postpone",         DT_QUAD, R_NONE, OPT_POSTPONE, MUTT_ASKYES },
  /*
  ** .pp
  ** Controls whether or not messages are saved in the $$postponed
  ** mailbox when you elect not to send immediately.
  ** .pp
  ** Also see the $$recall variable.
  */
  { "postponed",        DT_PATH, R_INDEX, UL &Postponed, UL "~/postponed" },
  /*
  ** .pp
  ** NeoMutt allows you to indefinitely ``$postpone sending a message'' which
  ** you are editing.  When you choose to postpone a message, NeoMutt saves it
  ** in the mailbox specified by this variable.
  ** .pp
  ** Also see the $$postpone variable.
  */
  { "postpone_encrypt",    DT_BOOL, R_NONE, OPT_POSTPONE_ENCRYPT, 0 },
  /*
  ** .pp
  ** When \fIset\fP, postponed messages that are marked for encryption will be
  ** self-encrypted.  NeoMutt will first try to encrypt using the value specified
  ** in $$pgp_self_encrypt_as or $$smime_self_encrypt_as.  If those are not
  ** set, it will try the deprecated $$postpone_encrypt_as.
  ** (Crypto only)
  */
  { "postpone_encrypt_as", DT_STRING,  R_NONE, UL &PostponeEncryptAs, 0 },
  /*
  ** .pp
  ** This is a deprecated fall-back variable for $$postpone_encrypt.
  ** Please use $$pgp_self_encrypt_as or $$smime_self_encrypt_as.
  ** (Crypto only)
  */
#ifdef USE_SOCKET
  { "preconnect",       DT_STRING, R_NONE, UL &Preconnect, UL 0 },
  /*
  ** .pp
  ** If \fIset\fP, a shell command to be executed if NeoMutt fails to establish
  ** a connection to the server. This is useful for setting up secure
  ** connections, e.g. with \fCssh(1)\fP. If the command returns a  nonzero
  ** status, NeoMutt gives up opening the server. Example:
  ** .ts
  ** set preconnect="ssh -f -q -L 1234:mailhost.net:143 mailhost.net \(rs
  ** sleep 20 < /dev/null > /dev/null"
  ** .te
  ** .pp
  ** Mailbox ``foo'' on ``mailhost.net'' can now be reached
  ** as ``{localhost:1234}foo''.
  ** .pp
  ** Note: For this example to work, you must be able to log in to the
  ** remote machine without having to enter a password.
  */
#endif /* USE_SOCKET */
  { "print",            DT_QUAD, R_NONE, OPT_PRINT, MUTT_ASKNO },
  /*
  ** .pp
  ** Controls whether or not NeoMutt really prints messages.
  ** This is set to ``ask-no'' by default, because some people
  ** accidentally hit ``p'' often.
  */
  { "print_command",    DT_PATH, R_NONE, UL &PrintCommand, UL "lpr" },
  /*
  ** .pp
  ** This specifies the command pipe that should be used to print messages.
  */
  { "print_cmd",        DT_SYNONYM,  R_NONE, UL "print_command", 0 },
  /*
  */
  { "print_decode",     DT_BOOL, R_NONE, OPT_PRINT_DECODE, 1 },
  /*
  ** .pp
  ** Used in connection with the \fC<print-message>\fP command.  If this
  ** option is \fIset\fP, the message is decoded before it is passed to the
  ** external command specified by $$print_command.  If this option
  ** is \fIunset\fP, no processing will be applied to the message when
  ** printing it.  The latter setting may be useful if you are using
  ** some advanced printer filter which is able to properly format
  ** e-mail messages for printing.
  */
  { "print_split",      DT_BOOL, R_NONE, OPT_PRINT_SPLIT,  0 },
  /*
  ** .pp
  ** Used in connection with the \fC<print-message>\fP command.  If this option
  ** is \fIset\fP, the command specified by $$print_command is executed once for
  ** each message which is to be printed.  If this option is \fIunset\fP,
  ** the command specified by $$print_command is executed only once, and
  ** all the messages are concatenated, with a form feed as the message
  ** separator.
  ** .pp
  ** Those who use the \fCenscript\fP(1) program's mail-printing mode will
  ** most likely want to \fIset\fP this option.
  */
  { "prompt_after",     DT_BOOL, R_NONE, OPT_PROMPT_AFTER, 1 },
  /*
  ** .pp
  ** If you use an \fIexternal\fP $$pager, setting this variable will
  ** cause NeoMutt to prompt you for a command when the pager exits rather
  ** than returning to the index menu.  If \fIunset\fP, NeoMutt will return to the
  ** index menu when the external pager exits.
  */
  { "query_command",    DT_PATH, R_NONE, UL &QueryCommand, UL "" },
  /*
  ** .pp
  ** This specifies the command NeoMutt will use to make external address
  ** queries.  The string may contain a ``%s'', which will be substituted
  ** with the query string the user types.  NeoMutt will add quotes around the
  ** string substituted for ``%s'' automatically according to shell quoting
  ** rules, so you should avoid adding your own.  If no ``%s'' is found in
  ** the string, NeoMutt will append the user's query to the end of the string.
  ** See ``$query'' for more information.
  */
  { "query_format",     DT_STRING, R_NONE, UL &QueryFormat, UL "%4c %t %-25.25a %-25.25n %?e?(%e)?" },
  /*
  ** .pp
  ** This variable describes the format of the ``query'' menu. The
  ** following \fCprintf(3)\fP-style sequences are understood:
  ** .dl
  ** .dt %a  .dd destination address
  ** .dt %c  .dd current entry number
  ** .dt %e  .dd extra information *
  ** .dt %n  .dd destination name
  ** .dt %t  .dd ``*'' if current entry is tagged, a space otherwise
  ** .dt %>X .dd right justify the rest of the string and pad with ``X''
  ** .dt %|X .dd pad to the end of the line with ``X''
  ** .dt %*X .dd soft-fill with character ``X'' as pad
  ** .de
  ** .pp
  ** For an explanation of ``soft-fill'', see the $$index_format documentation.
  ** .pp
  ** * = can be optionally printed if nonzero, see the $$status_format documentation.
  */
  { "quit",             DT_QUAD, R_NONE, OPT_QUIT, MUTT_YES },
  /*
  ** .pp
  ** This variable controls whether ``quit'' and ``exit'' actually quit
  ** from NeoMutt.  If this option is \fIset\fP, they do quit, if it is \fIunset\fP, they
  ** have no effect, and if it is set to \fIask-yes\fP or \fIask-no\fP, you are
  ** prompted for confirmation when you try to quit.
  */
  { "quote_regexp",     DT_REGEX,   R_PAGER, UL &QuoteRegexp, UL "^([ \t]*[|>:}#])+" },
  /*
  ** .pp
  ** A regular expression used in the internal pager to determine quoted
  ** sections of text in the body of a message. Quoted text may be filtered
  ** out using the \fC<toggle-quoted>\fP command, or colored according to the
  ** ``color quoted'' family of directives.
  ** .pp
  ** Higher levels of quoting may be colored differently (``color quoted1'',
  ** ``color quoted2'', etc.). The quoting level is determined by removing
  ** the last character from the matched text and recursively reapplying
  ** the regular expression until it fails to produce a match.
  ** .pp
  ** Match detection may be overridden by the $$smileys regular expression.
  */
  { "read_inc",         DT_NUMBER,  R_NONE, UL &ReadInc, 10 },
  /*
  ** .pp
  ** If set to a value greater than 0, NeoMutt will display which message it
  ** is currently on when reading a mailbox or when performing search actions
  ** such as search and limit. The message is printed after
  ** this many messages have been read or searched (e.g., if set to 25, NeoMutt will
  ** print a message when it is at message 25, and then again when it gets
  ** to message 50).  This variable is meant to indicate progress when
  ** reading or searching large mailboxes which may take some time.
  ** When set to 0, only a single message will appear before the reading
  ** the mailbox.
  ** .pp
  ** Also see the $$write_inc, $$net_inc and $$time_inc variables and the
  ** ``$tuning'' section of the manual for performance considerations.
  */
  { "read_only",        DT_BOOL, R_NONE, OPT_READ_ONLY, 0 },
  /*
  ** .pp
  ** If \fIset\fP, all folders are opened in read-only mode.
  */
  { "realname",         DT_STRING,  R_BOTH, UL &RealName, 0 },
  /*
  ** .pp
  ** This variable specifies what ``real'' or ``personal'' name should be used
  ** when sending messages.
  ** .pp
  ** By default, this is the GECOS field from \fC/etc/passwd\fP.  Note that this
  ** variable will \fInot\fP be used when the user has set a real name
  ** in the $$from variable.
  */
  { "recall",           DT_QUAD, R_NONE, OPT_RECALL, MUTT_ASKYES },
  /*
  ** .pp
  ** Controls whether or not NeoMutt recalls postponed messages
  ** when composing a new message.
  ** .pp
  ** Setting this variable to \fIyes\fP is not generally useful, and thus not
  ** recommended.  Note that the \fC<recall-message>\fP function can be used
  ** to manually recall postponed messages.
  ** .pp
  ** Also see $$postponed variable.
  */
  { "record",           DT_PATH, R_NONE, UL &Record, UL "~/sent" },
  /*
  ** .pp
  ** This specifies the file into which your outgoing messages should be
  ** appended.  (This is meant as the primary method for saving a copy of
  ** your messages, but another way to do this is using the ``$my_hdr''
  ** command to create a ``Bcc:'' field with your email address in it.)
  ** .pp
  ** The value of \fI$$record\fP is overridden by the $$force_name and
  ** $$save_name variables, and the ``$fcc-hook'' command.
  */
  { "reflow_space_quotes",      DT_BOOL, R_NONE, OPT_REFLOW_SPACE_QUOTES, 1 },
  /*
  ** .pp
  ** This option controls how quotes from format=flowed messages are displayed
  ** in the pager and when replying (with $$text_flowed \fIunset\fP).
  ** When set, this option adds spaces after each level of quote marks, turning
  ** ">>>foo" into "> > > foo".
  ** .pp
  ** \fBNote:\fP If $$reflow_text is \fIunset\fP, this option has no effect.
  ** Also, this option does not affect replies when $$text_flowed is \fIset\fP.
  */
  { "reflow_text",      DT_BOOL, R_NONE, OPT_REFLOW_TEXT, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will reformat paragraphs in text/plain
  ** parts marked format=flowed.  If \fIunset\fP, NeoMutt will display paragraphs
  ** unaltered from how they appear in the message body.  See RFC3676 for
  ** details on the \fIformat=flowed\fP format.
  ** .pp
  ** Also see $$reflow_wrap, and $$wrap.
  */
  { "reflow_wrap",      DT_NUMBER, R_NONE, UL &ReflowWrap, 78 },
  /*
  ** .pp
  ** This variable controls the maximum paragraph width when reformatting text/plain
  ** parts when $$reflow_text is \fIset\fP.  When the value is 0, paragraphs will
  ** be wrapped at the terminal's right margin.  A positive value sets the
  ** paragraph width relative to the left margin.  A negative value set the
  ** paragraph width relative to the right margin.
  ** .pp
  ** Also see $$wrap.
  */
  { "reply_regexp",     DT_REGEX,   R_INDEX|R_RESORT, UL &ReplyRegexp, UL "^(re([\\[0-9\\]+])*|aw):[ \t]*" },
  /*
  ** .pp
  ** A regular expression used to recognize reply messages when threading
  ** and replying. The default value corresponds to the English "Re:" and
  ** the German "Aw:".
  */
  { "reply_self",       DT_BOOL, R_NONE, OPT_REPLY_SELF, 0 },
  /*
  ** .pp
  ** If \fIunset\fP and you are replying to a message sent by you, NeoMutt will
  ** assume that you want to reply to the recipients of that message rather
  ** than to yourself.
  ** .pp
  ** Also see the ``$alternates'' command.
  */
  { "reply_to",         DT_QUAD, R_NONE, OPT_REPLY_TO, MUTT_ASKYES },
  /*
  ** .pp
  ** If \fIset\fP, when replying to a message, NeoMutt will use the address listed
  ** in the Reply-to: header as the recipient of the reply.  If \fIunset\fP,
  ** it will use the address in the From: header field instead.  This
  ** option is useful for reading a mailing list that sets the Reply-To:
  ** header field to the list address and you want to send a private
  ** message to the author of a message.
  */
  { "reply_with_xorig", DT_BOOL, R_NONE, OPT_REPLY_WITH_XORIG, 0 },
  /*
  ** .pp
  ** This variable provides a toggle. When active, the From: header will be
  ** extracted from the current mail's `X-Original-To:' header. This setting
  ** does not have precedence over ``$reverse_realname''.
  ** .pp
  ** Assuming `fast_reply' is disabled, this option will prompt the user with a
  ** prefilled From: header.
  */
  { "resolve",          DT_BOOL, R_NONE, OPT_RESOLVE, 1 },
  /*
  ** .pp
  ** When \fIset\fP, the cursor will be automatically advanced to the next
  ** (possibly undeleted) message whenever a command that modifies the
  ** current message is executed.
  */
  { "resume_draft_files", DT_BOOL, R_NONE, OPT_RESUME_DRAFT_FILES, 0 },
  /*
  ** .pp
  ** If \fIset\fP, draft files (specified by \fC-H\fP on the command
  ** line) are processed similarly to when resuming a postponed
  ** message.  Recipients are not prompted for; send-hooks are not
  ** evaluated; no alias expansion takes place; user-defined headers
  ** and signatures are not added to the message.
  */
  { "resume_edited_draft_files", DT_BOOL, R_NONE, OPT_RESUME_EDITED_DRAFT_FILES, 1 },
  /*
  ** .pp
  ** If \fIset\fP, draft files previously edited (via \fC-E -H\fP on
  ** the command line) will have $$resume_draft_files automatically
  ** set when they are used as a draft file again.
  ** .pp
  ** The first time a draft file is saved, NeoMutt will add a header,
  ** X-Mutt-Resume-Draft to the saved file.  The next time the draft
  ** file is read in, if NeoMutt sees the header, it will set
  ** $$resume_draft_files.
  ** .pp
  ** This option is designed to prevent multiple signatures,
  ** user-defined headers, and other processing effects from being
  ** made multiple times to the draft file.
  */
  { "reverse_alias",    DT_BOOL, R_BOTH, OPT_REVERSE_ALIAS, 0 },
  /*
  ** .pp
  ** This variable controls whether or not NeoMutt will display the ``personal''
  ** name from your aliases in the index menu if it finds an alias that
  ** matches the message's sender.  For example, if you have the following
  ** alias:
  ** .ts
  ** alias juser abd30425@somewhere.net (Joe User)
  ** .te
  ** .pp
  ** and then you receive mail which contains the following header:
  ** .ts
  ** From: abd30425@somewhere.net
  ** .te
  ** .pp
  ** It would be displayed in the index menu as ``Joe User'' instead of
  ** ``abd30425@somewhere.net.''  This is useful when the person's e-mail
  ** address is not human friendly.
  */
  { "reverse_name",     DT_BOOL, R_BOTH, OPT_REVERSE_NAME, 0 },
  /*
  ** .pp
  ** It may sometimes arrive that you receive mail to a certain machine,
  ** move the messages to another machine, and reply to some the messages
  ** from there.  If this variable is \fIset\fP, the default \fIFrom:\fP line of
  ** the reply messages is built using the address where you received the
  ** messages you are replying to \fBif\fP that address matches your
  ** ``$alternates''.  If the variable is \fIunset\fP, or the address that would be
  ** used doesn't match your ``$alternates'', the \fIFrom:\fP line will use
  ** your address on the current machine.
  ** .pp
  ** Also see the ``$alternates'' command.
  */
  { "reverse_realname", DT_BOOL, R_BOTH, OPT_REVERSE_REALNAME, 1 },
  /*
  ** .pp
  ** This variable fine-tunes the behavior of the $$reverse_name feature.
  ** When it is \fIset\fP, NeoMutt will use the address from incoming messages as-is,
  ** possibly including eventual real names.  When it is \fIunset\fP, NeoMutt will
  ** override any such real names with the setting of the $$realname variable.
  */
  { "rfc2047_parameters", DT_BOOL, R_NONE, OPT_RFC2047_PARAMETERS, 0 },
  /*
  ** .pp
  ** When this variable is \fIset\fP, NeoMutt will decode RFC2047-encoded MIME
  ** parameters. You want to set this variable when NeoMutt suggests you
  ** to save attachments to files named like:
  ** .ts
  ** =?iso-8859-1?Q?file=5F=E4=5F991116=2Ezip?=
  ** .te
  ** .pp
  ** When this variable is \fIset\fP interactively, the change won't be
  ** active until you change folders.
  ** .pp
  ** Note that this use of RFC2047's encoding is explicitly
  ** prohibited by the standard, but nevertheless encountered in the
  ** wild.
  ** .pp
  ** Also note that setting this parameter will \fInot\fP have the effect
  ** that NeoMutt \fIgenerates\fP this kind of encoding.  Instead, NeoMutt will
  ** unconditionally use the encoding specified in RFC2231.
  */
  { "save_address",     DT_BOOL, R_NONE, OPT_SAVE_ADDRESS, 0 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will take the sender's full address when choosing a
  ** default folder for saving a mail. If $$save_name or $$force_name
  ** is \fIset\fP too, the selection of the Fcc folder will be changed as well.
  */
  { "save_empty",       DT_BOOL, R_NONE, OPT_SAVE_EMPTY, 1 },
  /*
  ** .pp
  ** When \fIunset\fP, mailboxes which contain no saved messages will be removed
  ** when closed (the exception is $$spoolfile which is never removed).
  ** If \fIset\fP, mailboxes are never removed.
  ** .pp
  ** \fBNote:\fP This only applies to mbox and MMDF folders, NeoMutt does not
  ** delete MH and Maildir directories.
  */
  { "save_history",     DT_NUMBER,  R_NONE, UL &SaveHistory, 0 },
  /*
  ** .pp
  ** This variable controls the size of the history (per category) saved in the
  ** $$history_file file.
  */
  { "save_name",        DT_BOOL, R_NONE, OPT_SAVE_NAME, 0 },
  /*
  ** .pp
  ** This variable controls how copies of outgoing messages are saved.
  ** When \fIset\fP, a check is made to see if a mailbox specified by the
  ** recipient address exists (this is done by searching for a mailbox in
  ** the $$folder directory with the \fIusername\fP part of the
  ** recipient address).  If the mailbox exists, the outgoing message will
  ** be saved to that mailbox, otherwise the message is saved to the
  ** $$record mailbox.
  ** .pp
  ** Also see the $$force_name variable.
  */
  { "score",            DT_BOOL, R_NONE, OPT_SCORE, 1 },
  /*
  ** .pp
  ** When this variable is \fIunset\fP, scoring is turned off.  This can
  ** be useful to selectively disable scoring for certain folders when the
  ** $$score_threshold_delete variable and related are used.
  **
  */
  { "score_threshold_delete", DT_NUMBER, R_NONE, UL &ScoreThresholdDelete, UL -1 },
  /*
  ** .pp
  ** Messages which have been assigned a score equal to or lower than the value
  ** of this variable are automatically marked for deletion by NeoMutt.  Since
  ** NeoMutt scores are always greater than or equal to zero, the default setting
  ** of this variable will never mark a message for deletion.
  */
  { "score_threshold_flag", DT_NUMBER, R_NONE, UL &ScoreThresholdFlag, 9999 },
  /*
  ** .pp
  ** Messages which have been assigned a score greater than or equal to this
  ** variable's value are automatically marked "flagged".
  */
  { "score_threshold_read", DT_NUMBER, R_NONE, UL &ScoreThresholdRead, UL -1 },
  /*
  ** .pp
  ** Messages which have been assigned a score equal to or lower than the value
  ** of this variable are automatically marked as read by NeoMutt.  Since
  ** NeoMutt scores are always greater than or equal to zero, the default setting
  ** of this variable will never mark a message read.
  */
  { "search_context",   DT_NUMBER,  R_NONE, UL &SearchContext, UL 0 },
  /*
  ** .pp
  ** For the pager, this variable specifies the number of lines shown
  ** before search results. By default, search results will be top-aligned.
  */
  { "send_charset",     DT_STRING,  R_NONE, UL &SendCharset, UL "us-ascii:iso-8859-1:utf-8" },
  /*
  ** .pp
  ** A colon-delimited list of character sets for outgoing messages. NeoMutt will use the
  ** first character set into which the text can be converted exactly.
  ** If your $$charset is not ``iso-8859-1'' and recipients may not
  ** understand ``UTF-8'', it is advisable to include in the list an
  ** appropriate widely used standard character set (such as
  ** ``iso-8859-2'', ``koi8-r'' or ``iso-2022-jp'') either instead of or after
  ** ``iso-8859-1''.
  ** .pp
  ** In case the text cannot be converted into one of these exactly,
  ** NeoMutt uses $$charset as a fallback.
  */
  { "sendmail",         DT_PATH, R_NONE, UL &Sendmail, UL SENDMAIL " -oem -oi" },
  /*
  ** .pp
  ** Specifies the program and arguments used to deliver mail sent by NeoMutt.
  ** NeoMutt expects that the specified program interprets additional
  ** arguments as recipient addresses.  NeoMutt appends all recipients after
  ** adding a \fC--\fP delimiter (if not already present).  Additional
  ** flags, such as for $$use_8bitmime, $$use_envelope_from,
  ** $$dsn_notify, or $$dsn_return will be added before the delimiter.
  */
  { "sendmail_wait",    DT_NUMBER,  R_NONE, UL &SendmailWait, 0 },
  /*
  ** .pp
  ** Specifies the number of seconds to wait for the $$sendmail process
  ** to finish before giving up and putting delivery in the background.
  ** .pp
  ** NeoMutt interprets the value of this variable as follows:
  ** .dl
  ** .dt >0 .dd number of seconds to wait for sendmail to finish before continuing
  ** .dt 0  .dd wait forever for sendmail to finish
  ** .dt <0 .dd always put sendmail in the background without waiting
  ** .de
  ** .pp
  ** Note that if you specify a value other than 0, the output of the child
  ** process will be put in a temporary file.  If there is some error, you
  ** will be informed as to where to find the output.
  */
  { "shell",            DT_PATH, R_NONE, UL &Shell, 0 },
  /*
  ** .pp
  ** Command to use when spawning a subshell.  By default, the user's login
  ** shell from \fC/etc/passwd\fP is used.
  */
#ifdef USE_NNTP
  { "save_unsubscribed", DT_BOOL, R_NONE, OPT_SAVE_UNSUBSCRIBED, 0 },
  /*
  ** .pp
  ** When \fIset\fP, info about unsubscribed newsgroups will be saved into
  ** ``newsrc'' file and into cache.
  */
  { "show_new_news",    DT_BOOL, R_NONE, OPT_SHOW_NEW_NEWS, 1 },
  /*
  ** .pp
  ** If \fIset\fP, news server will be asked for new newsgroups on entering
  ** the browser.  Otherwise, it will be done only once for a news server.
  ** Also controls whether or not number of new articles of subscribed
  ** newsgroups will be then checked.
  */
  { "show_only_unread", DT_BOOL, R_NONE, OPT_SHOW_ONLY_UNREAD, 0 },
  /*
  ** .pp
  ** If \fIset\fP, only subscribed newsgroups that contain unread articles
  ** will be displayed in browser.
  */
#endif
#ifdef USE_SIDEBAR
  { "sidebar_delim_chars", DT_STRING, R_SIDEBAR, UL &SidebarDelimChars, UL "/." },
  /*
  ** .pp
  ** This contains the list of characters which you would like to treat
  ** as folder separators for displaying paths in the sidebar.
  ** .pp
  ** Local mail is often arranged in directories: `dir1/dir2/mailbox'.
  ** .ts
  ** set sidebar_delim_chars='/'
  ** .te
  ** .pp
  ** IMAP mailboxes are often named: `folder1.folder2.mailbox'.
  ** .ts
  ** set sidebar_delim_chars='.'
  ** .te
  ** .pp
  ** \fBSee also:\fP $$sidebar_short_path, $$sidebar_folder_indent, $$sidebar_indent_string.
  */
  { "sidebar_divider_char", DT_STRING, R_SIDEBAR, UL &SidebarDividerChar, 0 },
  /*
  ** .pp
  ** This specifies the characters to be drawn between the sidebar (when
  ** visible) and the other NeoMutt panels. ASCII and Unicode line-drawing
  ** characters are supported.
  */
  { "sidebar_folder_indent", DT_BOOL, R_SIDEBAR, OPT_SIDEBAR_FOLDER_INDENT, 0 },
  /*
  ** .pp
  ** Set this to indent mailboxes in the sidebar.
  ** .pp
  ** \fBSee also:\fP $$sidebar_short_path, $$sidebar_indent_string, $$sidebar_delim_chars.
  */
  { "sidebar_format", DT_STRING, R_SIDEBAR, UL &SidebarFormat, UL "%B%*  %n" },
  /*
  ** .pp
  ** This variable allows you to customize the sidebar display. This string is
  ** similar to $$index_format, but has its own set of \fCprintf(3)\fP-like
  ** sequences:
  ** .dl
  ** .dt %B  .dd Name of the mailbox
  ** .dt %S  .dd * Size of mailbox (total number of messages)
  ** .dt %N  .dd * Number of unread messages in the mailbox
  ** .dt %n  .dd N if mailbox has new mail, blank otherwise
  ** .dt %F  .dd * Number of Flagged messages in the mailbox
  ** .dt %!  .dd ``!'' : one flagged message;
  **             ``!!'' : two flagged messages;
  **             ``n!'' : n flagged messages (for n > 2).
  **             Otherwise prints nothing.
  ** .dt %d  .dd * @ Number of deleted messages
  ** .dt %L  .dd * @ Number of messages after limiting
  ** .dt %t  .dd * @ Number of tagged messages
  ** .dt %>X .dd right justify the rest of the string and pad with ``X''
  ** .dt %|X .dd pad to the end of the line with ``X''
  ** .dt %*X .dd soft-fill with character ``X'' as pad
  ** .de
  ** .pp
  ** * = Can be optionally printed if nonzero
  ** @ = Only applicable to the current folder
  ** .pp
  ** In order to use %S, %N, %F, and %!, $$mail_check_stats must
  ** be \fIset\fP.  When thus set, a suggested value for this option is
  ** "%B%?F? [%F]?%* %?N?%N/?%S".
  */
  { "sidebar_indent_string", DT_STRING, R_SIDEBAR, UL &SidebarIndentString, UL "  " },
  /*
  ** .pp
  ** This specifies the string that is used to indent mailboxes in the sidebar.
  ** It defaults to two spaces.
  ** .pp
  ** \fBSee also:\fP $$sidebar_short_path, $$sidebar_folder_indent, $$sidebar_delim_chars.
  */
  { "sidebar_new_mail_only", DT_BOOL, R_SIDEBAR, OPT_SIDEBAR_NEW_MAIL_ONLY, 0 },
  /*
  ** .pp
  ** When set, the sidebar will only display mailboxes containing new, or
  ** flagged, mail.
  ** .pp
  ** \fBSee also:\fP $sidebar_whitelist.
  */
  { "sidebar_next_new_wrap", DT_BOOL, R_NONE, OPT_SIDEBAR_NEXT_NEW_WRAP, 0 },
  /*
  ** .pp
  ** When set, the \fC<sidebar-next-new>\fP command will not stop and the end of
  ** the list of mailboxes, but wrap around to the beginning. The
  ** \fC<sidebar-prev-new>\fP command is similarly affected, wrapping around to
  ** the end of the list.
  */
  { "sidebar_on_right", DT_BOOL, R_BOTH|R_REFLOW, OPT_SIDEBAR_ON_RIGHT, 0 },
  /*
  ** .pp
  ** When set, the sidebar will appear on the right-hand side of the screen.
  */
  { "sidebar_short_path", DT_BOOL, R_SIDEBAR, OPT_SIDEBAR_SHORT_PATH, 0 },
  /*
  ** .pp
  ** By default the sidebar will show the mailbox's path, relative to the
  ** $$folder variable. Setting \fCsidebar_shortpath=yes\fP will shorten the
  ** names relative to the previous name. Here's an example:
  ** .dl
  ** .dt \fBshortpath=no\fP .dd \fBshortpath=yes\fP .dd \fBshortpath=yes, folderindent=yes, indentstr=".."\fP
  ** .dt \fCfruit\fP        .dd \fCfruit\fP         .dd \fCfruit\fP
  ** .dt \fCfruit.apple\fP  .dd \fCapple\fP         .dd \fC..apple\fP
  ** .dt \fCfruit.banana\fP .dd \fCbanana\fP        .dd \fC..banana\fP
  ** .dt \fCfruit.cherry\fP .dd \fCcherry\fP        .dd \fC..cherry\fP
  ** .de
  ** .pp
  ** \fBSee also:\fP $$sidebar_delim_chars, $$sidebar_folder_indent, $$sidebar_indent_string.
  */
  { "sidebar_sort_method", DT_SORT|DT_SORT_SIDEBAR, R_SIDEBAR, UL &SidebarSortMethod, SORT_ORDER },
  /*
  ** .pp
  ** Specifies how to sort entries in the file browser.  By default, the
  ** entries are sorted alphabetically.  Valid values:
  ** .il
  ** .dd alpha (alphabetically)
  ** .dd count (all message count)
  ** .dd flagged (flagged message count)
  ** .dd name (alphabetically)
  ** .dd new (unread message count)
  ** .dd path (alphabetically)
  ** .dd unread (unread message count)
  ** .dd unsorted
  ** .ie
  ** .pp
  ** You may optionally use the ``reverse-'' prefix to specify reverse sorting
  ** order (example: ``\fCset sort_browser=reverse-date\fP'').
  */
  { "sidebar_visible", DT_BOOL, R_REFLOW, OPT_SIDEBAR_VISIBLE, 0 },
  /*
  ** .pp
  ** This specifies whether or not to show sidebar. The sidebar shows a list of
  ** all your mailboxes.
  ** .pp
  ** \fBSee also:\fP $$sidebar_format, $$sidebar_width
  */
  { "sidebar_width", DT_NUMBER, R_REFLOW, UL &SidebarWidth, 30 },
  /*
  ** .pp
  ** This controls the width of the sidebar.  It is measured in screen columns.
  ** For example: sidebar_width=20 could display 20 ASCII characters, or 10
  ** Chinese characters.
  */
#endif
  { "sig_dashes",       DT_BOOL, R_NONE, OPT_SIG_DASHES, 1 },
  /*
  ** .pp
  ** If \fIset\fP, a line containing ``-- '' (note the trailing space) will be inserted before your
  ** $$signature.  It is \fBstrongly\fP recommended that you not \fIunset\fP
  ** this variable unless your signature contains just your name.  The
  ** reason for this is because many software packages use ``-- \n'' to
  ** detect your signature.  For example, NeoMutt has the ability to highlight
  ** the signature in a different color in the built-in pager.
  */
  { "sig_on_top",       DT_BOOL, R_NONE, OPT_SIG_ON_TOP, 0 },
  /*
  ** .pp
  ** If \fIset\fP, the signature will be included before any quoted or forwarded
  ** text.  It is \fBstrongly\fP recommended that you do not set this variable
  ** unless you really know what you are doing, and are prepared to take
  ** some heat from netiquette guardians.
  */
  { "signature",        DT_PATH, R_NONE, UL &Signature, UL "~/.signature" },
  /*
  ** .pp
  ** Specifies the filename of your signature, which is appended to all
  ** outgoing messages.   If the filename ends with a pipe (``|''), it is
  ** assumed that filename is a shell command and input should be read from
  ** its standard output.
  */
  { "simple_search",    DT_STRING,  R_NONE, UL &SimpleSearch, UL "~f %s | ~s %s" },
  /*
  ** .pp
  ** Specifies how NeoMutt should expand a simple search into a real search
  ** pattern.  A simple search is one that does not contain any of the ``~'' pattern
  ** operators.  See ``$patterns'' for more information on search patterns.
  ** .pp
  ** For example, if you simply type ``joe'' at a search or limit prompt, NeoMutt
  ** will automatically expand it to the value specified by this variable by
  ** replacing ``%s'' with the supplied string.
  ** For the default value, ``joe'' would be expanded to: ``~f joe | ~s joe''.
  */
  { "skip_quoted_offset", DT_NUMBER, R_NONE, UL &SkipQuotedOffset, 0 },
  /*
  ** .pp
  ** Lines of quoted text that are displayed before the unquoted text after
  ** ``skip to quoted'' command (S)
  */
  { "sleep_time",       DT_NUMBER, R_NONE, UL &SleepTime, 1 },
  /*
  ** .pp
  ** Specifies time, in seconds, to pause while displaying certain informational
  ** messages, while moving from folder to folder and after expunging
  ** messages from the current folder.  The default is to pause one second, so
  ** a value of zero for this option suppresses the pause.
  */
  { "smart_wrap",       DT_BOOL, R_PAGER_FLOW, OPT_SMART_WRAP, 1 },
  /*
  ** .pp
  ** Controls the display of lines longer than the screen width in the
  ** internal pager. If \fIset\fP, long lines are wrapped at a word boundary.  If
  ** \fIunset\fP, lines are simply wrapped at the screen edge. Also see the
  ** $$markers variable.
  */
  { "smileys",          DT_REGEX,   R_PAGER, UL &Smileys, UL "(>From )|(:[-^]?[][)(><}{|/DP])" },
  /*
  ** .pp
  ** The \fIpager\fP uses this variable to catch some common false
  ** positives of $$quote_regexp, most notably smileys and not consider
  ** a line quoted text if it also matches $$smileys. This mostly
  ** happens at the beginning of a line.
  */
  { "smime_ask_cert_label",     DT_BOOL, R_NONE, OPT_SMIME_ASK_CERT_LABEL, 1 },
  /*
  ** .pp
  ** This flag controls whether you want to be asked to enter a label
  ** for a certificate about to be added to the database or not. It is
  ** \fIset\fP by default.
  ** (S/MIME only)
  */
  { "smime_ca_location",        DT_PATH, R_NONE, UL &SmimeCALocation, 0 },
  /*
  ** .pp
  ** This variable contains the name of either a directory, or a file which
  ** contains trusted certificates for use with OpenSSL.
  ** (S/MIME only)
  */
  { "smime_certificates",       DT_PATH, R_NONE, UL &SmimeCertificates, 0 },
  /*
  ** .pp
  ** Since for S/MIME there is no pubring/secring as with PGP, NeoMutt has to handle
  ** storage and retrieval of keys by itself. This is very basic right
  ** now, and keys and certificates are stored in two different
  ** directories, both named as the hash-value retrieved from
  ** OpenSSL. There is an index file which contains mailbox-address
  ** keyid pairs, and which can be manually edited. This option points to
  ** the location of the certificates.
  ** (S/MIME only)
  */
  { "smime_decrypt_command",    DT_STRING, R_NONE, UL &SmimeDecryptCommand, 0 },
  /*
  ** .pp
  ** This format string specifies a command which is used to decrypt
  ** \fCapplication/x-pkcs7-mime\fP attachments.
  ** .pp
  ** The OpenSSL command formats have their own set of \fCprintf(3)\fP-like sequences
  ** similar to PGP's:
  ** .dl
  ** .dt %f .dd Expands to the name of a file containing a message.
  ** .dt %s .dd Expands to the name of a file containing the signature part
  ** .          of a \fCmultipart/signed\fP attachment when verifying it.
  ** .dt %k .dd The key-pair specified with $$smime_default_key
  ** .dt %i .dd Intermediate certificates
  ** .dt %c .dd One or more certificate IDs.
  ** .dt %a .dd The algorithm used for encryption.
  ** .dt %d .dd The message digest algorithm specified with $$smime_sign_digest_alg.
  ** .dt %C .dd CA location:  Depending on whether $$smime_ca_location
  ** .          points to a directory or file, this expands to
  ** .          ``-CApath $$smime_ca_location'' or ``-CAfile $$smime_ca_location''.
  ** .de
  ** .pp
  ** For examples on how to configure these formats, see the \fCsmime.rc\fP in
  ** the \fCsamples/\fP subdirectory which has been installed on your system
  ** alongside the documentation.
  ** (S/MIME only)
  */
  { "smime_decrypt_use_default_key",    DT_BOOL, R_NONE, OPT_SMIME_DECRYPT_USE_DEFAULT_KEY, 1 },
  /*
  ** .pp
  ** If \fIset\fP (default) this tells NeoMutt to use the default key for decryption. Otherwise,
  ** if managing multiple certificate-key-pairs, NeoMutt will try to use the mailbox-address
  ** to determine the key to use. It will ask you to supply a key, if it can't find one.
  ** (S/MIME only)
  */
  { "smime_sign_as",                    DT_SYNONYM,  R_NONE, UL "smime_default_key", 0 },
  { "smime_default_key",                DT_STRING,  R_NONE, UL &SmimeDefaultKey, 0 },
  /*
  ** .pp
  ** This is the default key-pair to use for signing. This must be set to the
  ** keyid (the hash-value that OpenSSL generates) to work properly
  ** (S/MIME only)
  */
  { "smime_encrypt_command",    DT_STRING, R_NONE, UL &SmimeEncryptCommand, 0 },
  /*
  ** .pp
  ** This command is used to create encrypted S/MIME messages.
  ** .pp
  ** This is a format string, see the $$smime_decrypt_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (S/MIME only)
  */
  /*
  ** .pp
  ** Encrypt the message to $$smime_default_key too.
  ** (S/MIME only)
  */
  { "smime_encrypt_with",       DT_STRING,  R_NONE, UL &SmimeEncryptWith, UL "aes256" },
  /*
  ** .pp
  ** This sets the algorithm that should be used for encryption.
  ** Valid choices are ``aes128'', ``aes192'', ``aes256'', ``des'', ``des3'', ``rc2-40'', ``rc2-64'', ``rc2-128''.
  ** (S/MIME only)
  */
  { "smime_get_cert_command",   DT_STRING, R_NONE, UL &SmimeGetCertCommand, 0 },
  /*
  ** .pp
  ** This command is used to extract X509 certificates from a PKCS7 structure.
  ** .pp
  ** This is a format string, see the $$smime_decrypt_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (S/MIME only)
  */
  { "smime_get_cert_email_command",     DT_STRING, R_NONE, UL &SmimeGetCertEmailCommand, 0 },
  /*
  ** .pp
  ** This command is used to extract the mail address(es) used for storing
  ** X509 certificates, and for verification purposes (to check whether the
  ** certificate was issued for the sender's mailbox).
  ** .pp
  ** This is a format string, see the $$smime_decrypt_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (S/MIME only)
  */
  { "smime_get_signer_cert_command",    DT_STRING, R_NONE, UL &SmimeGetSignerCertCommand, 0 },
  /*
  ** .pp
  ** This command is used to extract only the signers X509 certificate from a S/MIME
  ** signature, so that the certificate's owner may get compared to the
  ** email's ``From:'' field.
  ** .pp
  ** This is a format string, see the $$smime_decrypt_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (S/MIME only)
  */
  { "smime_import_cert_command",        DT_STRING, R_NONE, UL &SmimeImportCertCommand, 0 },
  /*
  ** .pp
  ** This command is used to import a certificate via smime_keys.
  ** .pp
  ** This is a format string, see the $$smime_decrypt_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (S/MIME only)
  */
  { "smime_is_default", DT_BOOL,  R_NONE, OPT_SMIME_IS_DEFAULT, 0 },
  /*
  ** .pp
  ** The default behavior of NeoMutt is to use PGP on all auto-sign/encryption
  ** operations. To override and to use OpenSSL instead this must be \fIset\fP.
  ** However, this has no effect while replying, since NeoMutt will automatically
  ** select the same application that was used to sign/encrypt the original
  ** message.  (Note that this variable can be overridden by unsetting $$crypt_autosmime.)
  ** (S/MIME only)
  */
  { "smime_keys",               DT_PATH, R_NONE, UL &SmimeKeys, 0 },
  /*
  ** .pp
  ** Since for S/MIME there is no pubring/secring as with PGP, NeoMutt has to handle
  ** storage and retrieval of keys/certs by itself. This is very basic right now,
  ** and stores keys and certificates in two different directories, both
  ** named as the hash-value retrieved from OpenSSL. There is an index file
  ** which contains mailbox-address keyid pair, and which can be manually
  ** edited. This option points to the location of the private keys.
  ** (S/MIME only)
  */
  { "smime_pk7out_command",     DT_STRING, R_NONE, UL &SmimePk7outCommand, 0 },
  /*
  ** .pp
  ** This command is used to extract PKCS7 structures of S/MIME signatures,
  ** in order to extract the public X509 certificate(s).
  ** .pp
  ** This is a format string, see the $$smime_decrypt_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (S/MIME only)
  */
  { "smime_self_encrypt",    DT_BOOL, R_NONE, OPT_SMIME_SELF_ENCRYPT, 0 },
  /*
  ** .pp
  ** When \fIset\fP, S/MIME encrypted messages will also be encrypted
  ** using the certificate in $$smime_self_encrypt_as.
  ** (S/MIME only)
  */
  { "smime_self_encrypt_as", DT_STRING,  R_NONE, UL &SmimeSelfEncryptAs, 0 },
  /*
  ** .pp
  ** This is an additional certificate used to encrypt messages when
  ** $$smime_self_encrypt is \fIset\fP.  It is also used to specify the
  ** certificate for $$postpone_encrypt.  It should be the hash-value that
  ** OpenSSL generates.
  ** (S/MIME only)
  */
  { "smime_sign_command",       DT_STRING, R_NONE, UL &SmimeSignCommand, 0 },
  /*
  ** .pp
  ** This command is used to created S/MIME signatures of type
  ** \fCmultipart/signed\fP, which can be read by all mail clients.
  ** .pp
  ** This is a format string, see the $$smime_decrypt_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (S/MIME only)
  */
  { "smime_sign_digest_alg",    DT_STRING,  R_NONE, UL &SmimeSignDigestAlg, UL "sha256" },
  /*
  ** .pp
  ** This sets the algorithm that should be used for the signature message digest.
  ** Valid choices are ``md5'', ``sha1'', ``sha224'', ``sha256'', ``sha384'', ``sha512''.
  ** (S/MIME only)
  */
  { "smime_timeout",            DT_NUMBER,  R_NONE, UL &SmimeTimeout, 300 },
  /*
  ** .pp
  ** The number of seconds after which a cached passphrase will expire if
  ** not used.
  ** (S/MIME only)
  */
  { "smime_verify_command",     DT_STRING, R_NONE, UL &SmimeVerifyCommand, 0 },
  /*
  ** .pp
  ** This command is used to verify S/MIME signatures of type \fCmultipart/signed\fP.
  ** .pp
  ** This is a format string, see the $$smime_decrypt_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (S/MIME only)
  */
  { "smime_verify_opaque_command",      DT_STRING, R_NONE, UL &SmimeVerifyOpaqueCommand, 0 },
  /*
  ** .pp
  ** This command is used to verify S/MIME signatures of type
  ** \fCapplication/x-pkcs7-mime\fP.
  ** .pp
  ** This is a format string, see the $$smime_decrypt_command command for
  ** possible \fCprintf(3)\fP-like sequences.
  ** (S/MIME only)
  */
#ifdef USE_SMTP
  { "smtp_authenticators", DT_STRING, R_NONE, UL &SmtpAuthenticators, UL 0 },
  /*
  ** .pp
  ** This is a colon-delimited list of authentication methods NeoMutt may
  ** attempt to use to log in to an SMTP server, in the order NeoMutt should
  ** try them.  Authentication methods are any SASL mechanism, e.g. ``plain'',
  ** ``digest-md5'', ``gssapi'' or ``cram-md5''.
  ** This option is case-insensitive. If it is ``unset''
  ** (the default) NeoMutt will try all available methods, in order from
  ** most-secure to least-secure. Support for the ``plain'' mechanism is
  ** bundled; other mechanisms are provided by an external SASL library (look
  ** for +USE_SASL in the output of neomutt -v).
  ** .pp
  ** Example:
  ** .ts
  ** set smtp_authenticators="digest-md5:cram-md5"
  ** .te
  */
  { "smtp_pass",        DT_STRING,  R_NONE|F_SENSITIVE, UL &SmtpPass, UL 0 },
  /*
  ** .pp
  ** Specifies the password for your SMTP account.  If \fIunset\fP, NeoMutt will
  ** prompt you for your password when you first send mail via SMTP.
  ** See $$smtp_url to configure NeoMutt to send mail via SMTP.
  ** .pp
  ** \fBWarning\fP: you should only use this option when you are on a
  ** fairly secure machine, because the superuser can read your neomuttrc even
  ** if you are the only one who can read the file.
  */
  { "smtp_url",         DT_STRING, R_NONE|F_SENSITIVE, UL &SmtpUrl, UL 0 },
  /*
  ** .pp
  ** Defines the SMTP smarthost where sent messages should relayed for
  ** delivery. This should take the form of an SMTP URL, e.g.:
  ** .ts
  ** smtp[s]://[user[:pass]@]host[:port]
  ** .te
  ** .pp
  ** where ``[...]'' denotes an optional part.
  ** Setting this variable overrides the value of the $$sendmail
  ** variable.
  */
#endif /* USE_SMTP */
  { "sort",             DT_SORT, R_INDEX|R_RESORT, UL &Sort, SORT_DATE },
  /*
  ** .pp
  ** Specifies how to sort messages in the ``index'' menu.  Valid values
  ** are:
  ** .il
  ** .dd date or date-sent
  ** .dd date-received
  ** .dd from
  ** .dd mailbox-order (unsorted)
  ** .dd score
  ** .dd size
  ** .dd spam
  ** .dd subject
  ** .dd threads
  ** .dd to
  ** .ie
  ** .pp
  ** You may optionally use the ``reverse-'' prefix to specify reverse sorting
  ** order.
  ** .pp
  ** Example:
  ** .ts
  ** set sort=reverse-date-sent
  ** .te
  */
  { "sort_alias",       DT_SORT|DT_SORT_ALIAS,  R_NONE, UL &SortAlias, SORT_ALIAS },
  /*
  ** .pp
  ** Specifies how the entries in the ``alias'' menu are sorted.  The
  ** following are legal values:
  ** .il
  ** .dd address (sort alphabetically by email address)
  ** .dd alias (sort alphabetically by alias name)
  ** .dd unsorted (leave in order specified in .neomuttrc)
  ** .ie
  */
  { "sort_aux",         DT_SORT|DT_SORT_AUX, R_INDEX|R_RESORT_BOTH, UL &SortAux, SORT_DATE },
  /*
  ** .pp
  ** When sorting by threads, this variable controls how threads are sorted
  ** in relation to other threads, and how the branches of the thread trees
  ** are sorted.  This can be set to any value that $$sort can, except
  ** ``threads'' (in that case, NeoMutt will just use ``date-sent'').  You can also
  ** specify the ``last-'' prefix in addition to the ``reverse-'' prefix, but ``last-''
  ** must come after ``reverse-''.  The ``last-'' prefix causes messages to be
  ** sorted against its siblings by which has the last descendant, using
  ** the rest of $$sort_aux as an ordering.  For instance,
  ** .ts
  ** set sort_aux=last-date-received
  ** .te
  ** .pp
  ** would mean that if a new message is received in a
  ** thread, that thread becomes the last one displayed (or the first, if
  ** you have ``\fCset sort=reverse-threads\fP''.)
  ** .pp
  ** Note: For reversed $$sort
  ** order $$sort_aux is reversed again (which is not the right thing to do,
  ** but kept to not break any existing configuration setting).
  */
  { "sort_browser",     DT_SORT|DT_SORT_BROWSER, R_NONE, UL &SortBrowser, SORT_ALPHA },
  /*
  ** .pp
  ** Specifies how to sort entries in the file browser.  By default, the
  ** entries are sorted alphabetically.  Valid values:
  ** .il
  ** .dd alpha (alphabetically)
  ** .dd count (all message count)
  ** .dd date
  ** .dd desc (description)
  ** .dd new (new message count)
  ** .dd size
  ** .dd unsorted
  ** .ie
  ** .pp
  ** You may optionally use the ``reverse-'' prefix to specify reverse sorting
  ** order (example: ``\fCset sort_browser=reverse-date\fP'').
  */
  { "sort_re",          DT_BOOL, R_INDEX|R_RESORT|R_RESORT_INIT, OPT_SORT_RE, 1 },
  /*
  ** .pp
  ** This variable is only useful when sorting by mailboxes in sidebar. By default,
  ** entries are unsorted.  Valid values:
  ** .il
  ** .dd count (all message count)
  ** .dd desc  (virtual mailbox description)
  ** .dd new (new message count)
  ** .dd path
  ** .dd unsorted
  ** .ie
  */
  { "spam_separator",   DT_STRING, R_NONE, UL &SpamSeparator, UL "," },
  /*
  ** .pp
  ** This variable controls what happens when multiple spam headers
  ** are matched: if \fIunset\fP, each successive header will overwrite any
  ** previous matches value for the spam label. If \fIset\fP, each successive
  ** match will append to the previous, using this variable's value as a
  ** separator.
  */
  { "spoolfile",        DT_PATH, R_NONE, UL &SpoolFile, 0 },
  /*
  ** .pp
  ** If your spool mailbox is in a non-default place where NeoMutt cannot find
  ** it, you can specify its location with this variable.  NeoMutt will
  ** initially set this variable to the value of the environment
  ** variable \fC$$$MAIL\fP or \fC$$$MAILDIR\fP if either is defined.
  */
#ifdef USE_SSL
#ifdef USE_SSL_GNUTLS
  { "ssl_ca_certificates_file", DT_PATH, R_NONE, UL &SslCaCertificatesFile, 0 },
  /*
  ** .pp
  ** This variable specifies a file containing trusted CA certificates.
  ** Any server certificate that is signed with one of these CA
  ** certificates is also automatically accepted.
  ** .pp
  ** Example:
  ** .ts
  ** set ssl_ca_certificates_file=/etc/ssl/certs/ca-certificates.crt
  ** .te
  */
#endif /* USE_SSL_GNUTLS */
  { "ssl_client_cert", DT_PATH, R_NONE, UL &SslClientCert, 0 },
  /*
  ** .pp
  ** The file containing a client certificate and its associated private
  ** key.
  */
  { "ssl_force_tls",            DT_BOOL, R_NONE, OPT_SSL_FORCE_TLS, 0 },
  /*
   ** .pp
   ** If this variable is \fIset\fP, NeoMutt will require that all connections
   ** to remote servers be encrypted. Furthermore it will attempt to
   ** negotiate TLS even if the server does not advertise the capability,
   ** since it would otherwise have to abort the connection anyway. This
   ** option supersedes $$ssl_starttls.
   */
#ifdef USE_SSL_GNUTLS
  { "ssl_min_dh_prime_bits", DT_NUMBER, R_NONE, UL &SslMinDhPrimeBits, 0 },
  /*
  ** .pp
  ** This variable specifies the minimum acceptable prime size (in bits)
  ** for use in any Diffie-Hellman key exchange. A value of 0 will use
  ** the default from the GNUTLS library.
  */
#endif /* USE_SSL_GNUTLS */
  { "ssl_starttls", DT_QUAD, R_NONE, OPT_SSL_STARTTLS, MUTT_YES },
  /*
  ** .pp
  ** If \fIset\fP (the default), NeoMutt will attempt to use \fCSTARTTLS\fP on servers
  ** advertising the capability. When \fIunset\fP, NeoMutt will not attempt to
  ** use \fCSTARTTLS\fP regardless of the server's capabilities.
  */
#ifdef USE_SSL_OPENSSL
  { "ssl_use_sslv2", DT_BOOL, R_NONE, OPT_SSL_USE_SSLV2, 0 },
  /*
  ** .pp
  ** This variable specifies whether to attempt to use SSLv2 in the
  ** SSL authentication process. Note that SSLv2 and SSLv3 are now
  ** considered fundamentally insecure and are no longer recommended.
  */
#endif /* defined USE_SSL_OPENSSL */
  { "ssl_use_sslv3", DT_BOOL, R_NONE, OPT_SSL_USE_SSLV3, 0 },
  /*
  ** .pp
  ** This variable specifies whether to attempt to use SSLv3 in the
  ** SSL authentication process. Note that SSLv2 and SSLv3 are now
  ** considered fundamentally insecure and are no longer recommended.
  */
  { "ssl_use_tlsv1", DT_BOOL, R_NONE, OPT_SSL_USE_TLSV1, 1 },
  /*
  ** .pp
  ** This variable specifies whether to attempt to use TLSv1.0 in the
  ** SSL authentication process.
  */
  { "ssl_use_tlsv1_1", DT_BOOL, R_NONE, OPT_SSL_USE_TLSV1_1, 1 },
  /*
  ** .pp
  ** This variable specifies whether to attempt to use TLSv1.1 in the
  ** SSL authentication process.
  */
  { "ssl_use_tlsv1_2", DT_BOOL, R_NONE, OPT_SSL_USE_TLSV1_2, 1 },
  /*
  ** .pp
  ** This variable specifies whether to attempt to use TLSv1.2 in the
  ** SSL authentication process.
  */
#ifdef USE_SSL_OPENSSL
  { "ssl_usesystemcerts", DT_BOOL, R_NONE, OPT_SSL_USESYSTEMCERTS, 1 },
  /*
  ** .pp
  ** If set to \fIyes\fP, NeoMutt will use CA certificates in the
  ** system-wide certificate store when checking if a server certificate
  ** is signed by a trusted CA.
  */
#endif
  { "ssl_verify_dates", DT_BOOL, R_NONE, OPT_SSL_VERIFY_DATES, 1 },
  /*
  ** .pp
  ** If \fIset\fP (the default), NeoMutt will not automatically accept a server
  ** certificate that is either not yet valid or already expired. You should
  ** only unset this for particular known hosts, using the
  ** \fC$<account-hook>\fP function.
  */
  { "ssl_verify_host", DT_BOOL, R_NONE, OPT_SSL_VERIFY_HOST, 1 },
  /*
  ** .pp
  ** If \fIset\fP (the default), NeoMutt will not automatically accept a server
  ** certificate whose host name does not match the host used in your folder
  ** URL. You should only unset this for particular known hosts, using
  ** the \fC$<account-hook>\fP function.
  */
#ifdef USE_SSL_OPENSSL
#ifdef HAVE_SSL_PARTIAL_CHAIN
  { "ssl_verify_partial_chains", DT_BOOL, R_NONE, OPT_SSL_VERIFY_PARTIAL_CHAINS, 0 },
  /*
  ** .pp
  ** This option should not be changed from the default unless you understand
  ** what you are doing.
  ** .pp
  ** Setting this variable to \fIyes\fP will permit verifying partial
  ** certification chains, i. e. a certificate chain where not the root,
  ** but an intermediate certificate CA, or the host certificate, are
  ** marked trusted (in $$certificate_file), without marking the root
  ** signing CA as trusted.
  ** .pp
  ** (OpenSSL 1.0.2b and newer only).
  */
#endif /* defined HAVE_SSL_PARTIAL_CHAIN */
#endif /* defined USE_SSL_OPENSSL */
  { "ssl_ciphers", DT_STRING, R_NONE, UL &SslCiphers, UL 0 },
  /*
  ** .pp
  ** Contains a colon-seperated list of ciphers to use when using SSL.
  ** For OpenSSL, see ciphers(1) for the syntax of the string.
  ** .pp
  ** For GnuTLS, this option will be used in place of "NORMAL" at the
  ** start of the priority string.  See gnutls_priority_init(3) for the
  ** syntax and more details. (Note: GnuTLS version 2.1.7 or higher is
  ** required.)
  */
#endif /* defined(USE_SSL) */
  { "status_chars",     DT_MBTABLE, R_BOTH, UL &StatusChars, UL "-*%A" },
  /*
  ** .pp
  ** Controls the characters used by the ``%r'' indicator in $$status_format.
  ** .dl
  ** .dt \fBCharacter\fP .dd \fBDefault\fP .dd \fBDescription\fP
  ** .dt 1 .dd - .dd Mailbox is unchanged
  ** .dt 2 .dd * .dd Mailbox has been changed and needs to be resynchronized
  ** .dt 3 .dd % .dd Mailbox is read-only, or will not be written when exiting.
  **                 (You can toggle whether to write changes to a mailbox
  **                 with the \fC<toggle-write>\fP operation, bound by default
  **                 to ``%'')
  ** .dt 4 .dd A .dd Folder opened in attach-message mode.
  **                 (Certain operations like composing a new mail, replying,
  **                 forwarding, etc. are not permitted in this mode)
  ** .de
  */
  { "status_format",    DT_STRING,  R_BOTH, UL &StatusFormat, UL "-%r-NeoMutt: %f [Msgs:%?M?%M/?%m%?n? New:%n?%?o? Old:%o?%?d? Del:%d?%?F? Flag:%F?%?t? Tag:%t?%?p? Post:%p?%?b? Inc:%b?%?l? %l?]---(%s/%S)-%>-(%P)---" },
  /*
  ** .pp
  ** Controls the format of the status line displayed in the ``index''
  ** menu.  This string is similar to $$index_format, but has its own
  ** set of \fCprintf(3)\fP-like sequences:
  ** .dl
  ** .dt %b  .dd number of mailboxes with new mail *
  ** .dt %d  .dd number of deleted messages *
  ** .dt %f  .dd the full pathname of the current mailbox
  ** .dt %F  .dd number of flagged messages *
  ** .dt %h  .dd local hostname
  ** .dt %l  .dd size (in bytes) of the current mailbox *
  ** .dt %L  .dd size (in bytes) of the messages shown
  **             (i.e., which match the current limit) *
  ** .dt %m  .dd the number of messages in the mailbox *
  ** .dt %M  .dd the number of messages shown (i.e., which match the current limit) *
  ** .dt %n  .dd number of new messages in the mailbox *
  ** .dt %o  .dd number of old unread messages *
  ** .dt %p  .dd number of postponed messages *
  ** .dt %P  .dd percentage of the way through the index
  ** .dt %r  .dd modified/read-only/won't-write/attach-message indicator,
  **             according to $$status_chars
  ** .dt %s  .dd current sorting mode ($$sort)
  ** .dt %S  .dd current aux sorting method ($$sort_aux)
  ** .dt %t  .dd number of tagged messages *
  ** .dt %u  .dd number of unread messages *
  ** .dt %v  .dd NeoMutt version string
  ** .dt %V  .dd currently active limit pattern, if any *
  ** .dt %>X .dd right justify the rest of the string and pad with ``X''
  ** .dt %|X .dd pad to the end of the line with ``X''
  ** .dt %*X .dd soft-fill with character ``X'' as pad
  ** .de
  ** .pp
  ** For an explanation of ``soft-fill'', see the $$index_format documentation.
  ** .pp
  ** * = can be optionally printed if nonzero
  ** .pp
  ** Some of the above sequences can be used to optionally print a string
  ** if their value is nonzero.  For example, you may only want to see the
  ** number of flagged messages if such messages exist, since zero is not
  ** particularly meaningful.  To optionally print a string based upon one
  ** of the above sequences, the following construct is used:
  ** .pp
  **  \fC%?<sequence_char>?<optional_string>?\fP
  ** .pp
  ** where \fIsequence_char\fP is a character from the table above, and
  ** \fIoptional_string\fP is the string you would like printed if
  ** \fIsequence_char\fP is nonzero.  \fIoptional_string\fP \fBmay\fP contain
  ** other sequences as well as normal text, but you may \fBnot\fP nest
  ** optional strings.
  ** .pp
  ** Here is an example illustrating how to optionally print the number of
  ** new messages in a mailbox:
  ** .pp
  ** \fC%?n?%n new messages.?\fP
  ** .pp
  ** You can also switch between two strings using the following construct:
  ** .pp
  ** \fC%?<sequence_char>?<if_string>&<else_string>?\fP
  ** .pp
  ** If the value of \fIsequence_char\fP is non-zero, \fIif_string\fP will
  ** be expanded, otherwise \fIelse_string\fP will be expanded.
  ** .pp
  ** You can force the result of any \fCprintf(3)\fP-like sequence to be lowercase
  ** by prefixing the sequence character with an underscore (``_'') sign.
  ** For example, if you want to display the local hostname in lowercase,
  ** you would use: ``\fC%_h\fP''.
  ** .pp
  ** If you prefix the sequence character with a colon (``:'') character, NeoMutt
  ** will replace any dots in the expansion by underscores. This might be helpful
  ** with IMAP folders that don't like dots in folder names.
  */
  { "status_on_top",    DT_BOOL, R_REFLOW, OPT_STATUS_ON_TOP, 0 },
  /*
  ** .pp
  ** Setting this variable causes the ``status bar'' to be displayed on
  ** the first line of the screen rather than near the bottom. If $$help
  ** is \fIset\fP, too it'll be placed at the bottom.
  */
  { "strict_threads",   DT_BOOL, R_RESORT|R_RESORT_INIT|R_INDEX, OPT_STRICT_THREADS, 0 },
  /*
  ** .pp
  ** If \fIset\fP, threading will only make use of the ``In-Reply-To'' and
  ** ``References:'' fields when you $$sort by message threads.  By
  ** default, messages with the same subject are grouped together in
  ** ``pseudo threads.''. This may not always be desirable, such as in a
  ** personal mailbox where you might have several unrelated messages with
  ** the subjects like ``hi'' which will get grouped together. See also
  ** $$sort_re for a less drastic way of controlling this
  ** behavior.
  */
  { "suspend",          DT_BOOL, R_NONE, OPT_SUSPEND, 1 },
  /*
  ** .pp
  ** When \fIunset\fP, NeoMutt won't stop when the user presses the terminal's
  ** \fIsusp\fP key, usually ``^Z''. This is useful if you run NeoMutt
  ** inside an xterm using a command like ``\fCxterm -e neomutt\fP''.
  */
  { "text_flowed",      DT_BOOL, R_NONE, OPT_TEXT_FLOWED,  0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will generate ``format=flowed'' bodies with a content type
  ** of ``\fCtext/plain; format=flowed\fP''.
  ** This format is easier to handle for some mailing software, and generally
  ** just looks like ordinary text.  To actually make use of this format's
  ** features, you'll need support in your editor.
  ** .pp
  ** Note that $$indent_string is ignored when this option is \fIset\fP.
  */
  { "thorough_search",  DT_BOOL, R_NONE, OPT_THOROUGH_SEARCH, 1 },
  /*
  ** .pp
  ** Affects the \fC~b\fP and \fC~h\fP search operations described in
  ** section ``$patterns''.  If \fIset\fP, the headers and body/attachments of
  ** messages to be searched are decoded before searching. If \fIunset\fP,
  ** messages are searched as they appear in the folder.
  ** .pp
  ** Users searching attachments or for non-ASCII characters should \fIset\fP
  ** this value because decoding also includes MIME parsing/decoding and possible
  ** character set conversions. Otherwise NeoMutt will attempt to match against the
  ** raw message received (for example quoted-printable encoded or with encoded
  ** headers) which may lead to incorrect search results.
  */
  { "thread_received",  DT_BOOL, R_RESORT|R_RESORT_INIT|R_INDEX, OPT_THREAD_RECEIVED, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt uses the date received rather than the date sent
  ** to thread messages by subject.
  */
  { "tilde",            DT_BOOL, R_PAGER, OPT_TILDE, 0 },
  /*
  ** .pp
  ** When \fIset\fP, the internal-pager will pad blank lines to the bottom of the
  ** screen with a tilde (``~'').
  */
  { "time_inc",         DT_NUMBER,  R_NONE, UL &TimeInc, 0 },
  /*
  ** .pp
  ** Along with $$read_inc, $$write_inc, and $$net_inc, this
  ** variable controls the frequency with which progress updates are
  ** displayed. It suppresses updates less than $$time_inc milliseconds
  ** apart. This can improve throughput on systems with slow terminals,
  ** or when running NeoMutt on a remote system.
  ** .pp
  ** Also see the ``$tuning'' section of the manual for performance considerations.
  */
  { "timeout",          DT_NUMBER,  R_NONE, UL &Timeout, 600 },
  /*
  ** .pp
  ** When NeoMutt is waiting for user input either idling in menus or
  ** in an interactive prompt, NeoMutt would block until input is
  ** present. Depending on the context, this would prevent certain
  ** operations from working, like checking for new mail or keeping
  ** an IMAP connection alive.
  ** .pp
  ** This variable controls how many seconds NeoMutt will at most wait
  ** until it aborts waiting for input, performs these operations and
  ** continues to wait for input.
  ** .pp
  ** A value of zero or less will cause NeoMutt to never time out.
  */
  { "tmpdir",           DT_PATH, R_NONE, UL &Tmpdir, 0 },
  /*
  ** .pp
  ** This variable allows you to specify where NeoMutt will place its
  ** temporary files needed for displaying and composing messages.  If
  ** this variable is not set, the environment variable \fC$$$TMPDIR\fP is
  ** used.  If \fC$$$TMPDIR\fP is not set then ``\fC/tmp\fP'' is used.
  */
  { "to_chars",         DT_MBTABLE, R_BOTH, UL &ToChars, UL " +TCFL" },
  /*
  ** .pp
  ** Controls the character used to indicate mail addressed to you.
  ** .dl
  ** .dt \fBCharacter\fP .dd \fBDefault\fP .dd \fBDescription\fP
  ** .dt 1 .dd <space> .dd The mail is \fInot\fP addressed to your address.
  ** .dt 2 .dd + .dd You are the only recipient of the message.
  ** .dt 3 .dd T .dd Your address appears in the ``To:'' header field, but you are not the only recipient of the message.
  ** .dt 4 .dd C .dd Your address is specified in the ``Cc:'' header field, but you are not the only recipient.
  ** .dt 5 .dd F .dd Indicates the mail that was sent by \fIyou\fP.
  ** .dt 6 .dd L .dd Indicates the mail was sent to a mailing-list you subscribe to.
  ** .de
  */
  { "flag_chars",       DT_MBTABLE,    R_BOTH, UL &FlagChars, UL "*!DdrONon- " },
  /*
   ** .pp
   ** Controls the characters used in several flags.
   ** .dl
   ** .dt \fBCharacter\fP .dd \fBDefault\fP .dd \fBDescription\fP
   ** .dt 1 .dd * .dd The mail is tagged.
   ** .dt 2 .dd ! .dd The mail is flagged as important.
   ** .dt 3 .dd D .dd The mail is marked for deletion.
   ** .dt 4 .dd d .dd The mail has attachments marked for deletion.
   ** .dt 5 .dd r .dd The mail has been replied to.
   ** .dt 6 .dd O .dd The mail is Old (Unread but seen).
   ** .dt 7 .dd N .dd The mail is New (Unread but not seen).
   ** .dt 8 .dd o .dd The mail thread is Old (Unread but seen).
   ** .dt 9 .dd n .dd The mail thread is New (Unread but not seen).
   ** .dt 10 .dd - .dd The mail is read - %S expando.
   ** .dt 11 .dd <space> .dd The mail is read - %Z expando.
   ** .de
   */
  { "trash",            DT_PATH, R_NONE, UL &Trash, 0 },
  /*
  ** .pp
  ** If set, this variable specifies the path of the trash folder where the
  ** mails marked for deletion will be moved, instead of being irremediably
  ** purged.
  ** .pp
  ** NOTE: When you delete a message in the trash folder, it is really
  ** deleted, so that you have a way to clean the trash.
  */
  { "ts_icon_format",    DT_STRING,  R_BOTH, UL &TSIconFormat, UL "M%?n?AIL&ail?" },
  /*
  ** .pp
  ** Controls the format of the icon title, as long as ``$$ts_enabled'' is set.
  ** This string is identical in formatting to the one used by
  ** ``$$status_format''.
  */
  { "ts_enabled",        DT_BOOL,  R_BOTH, OPT_TS_ENABLED, 0 },
  /* The default must be off to force in the validity checking. */
  /*
  ** .pp
  ** Controls whether NeoMutt tries to set the terminal status line and icon name.
  ** Most terminal emulators emulate the status line in the window title.
  */
  { "ts_status_format",  DT_STRING,   R_BOTH, UL &TSStatusFormat, UL "NeoMutt with %?m?%m messages&no messages?%?n? [%n NEW]?" },
  /*
  ** .pp
  ** Controls the format of the terminal status line (or window title),
  ** provided that ``$$ts_enabled'' has been set. This string is identical in
  ** formatting to the one used by ``$$status_format''.
  */
#ifdef USE_SOCKET
  { "tunnel",            DT_STRING, R_NONE, UL &Tunnel, UL 0 },
  /*
  ** .pp
  ** Setting this variable will cause NeoMutt to open a pipe to a command
  ** instead of a raw socket. You may be able to use this to set up
  ** preauthenticated connections to your IMAP/POP3/SMTP server. Example:
  ** .ts
  ** set tunnel="ssh -q mailhost.net /usr/local/libexec/imapd"
  ** .te
  ** .pp
  ** Note: For this example to work you must be able to log in to the remote
  ** machine without having to enter a password.
  ** .pp
  ** When set, NeoMutt uses the tunnel for all remote connections.
  ** Please see ``$account-hook'' in the manual for how to use different
  ** tunnel commands per connection.
  */
#endif
  { "uncollapse_jump",  DT_BOOL, R_NONE, OPT_UNCOLLAPSE_JUMP, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will jump to the next unread message, if any,
  ** when the current thread is \fIun\fPcollapsed.
  */
  { "uncollapse_new",   DT_BOOL, R_NONE, OPT_UNCOLLAPSE_NEW, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will automatically uncollapse any collapsed thread
  ** that receives a new message. When \fIunset\fP, collapsed threads will
  ** remain collapsed. the presence of the new message will still affect
  ** index sorting, though.
  */
  { "use_8bitmime",     DT_BOOL, R_NONE, OPT_USE_8BITMIME, 0 },
  /*
  ** .pp
  ** \fBWarning:\fP do not set this variable unless you are using a version
  ** of sendmail which supports the \fC-B8BITMIME\fP flag (such as sendmail
  ** 8.8.x) or you may not be able to send mail.
  ** .pp
  ** When \fIset\fP, NeoMutt will invoke $$sendmail with the \fC-B8BITMIME\fP
  ** flag when sending 8-bit messages to enable ESMTP negotiation.
  */
  { "use_domain",       DT_BOOL, R_NONE, OPT_USE_DOMAIN, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will qualify all local addresses (ones without the
  ** ``@host'' portion) with the value of $$hostname.  If \fIunset\fP, no
  ** addresses will be qualified.
  */
  { "use_envelope_from",        DT_BOOL, R_NONE, OPT_USE_ENVELOPE_FROM, 0 },
  /*
   ** .pp
   ** When \fIset\fP, NeoMutt will set the \fIenvelope\fP sender of the message.
   ** If $$envelope_from_address is \fIset\fP, it will be used as the sender
   ** address. If \fIunset\fP, NeoMutt will attempt to derive the sender from the
   ** ``From:'' header.
   ** .pp
   ** Note that this information is passed to sendmail command using the
   ** \fC-f\fP command line switch. Therefore setting this option is not useful
   ** if the $$sendmail variable already contains \fC-f\fP or if the
   ** executable pointed to by $$sendmail doesn't support the \fC-f\fP switch.
   */
  { "envelope_from",    DT_SYNONYM,  R_NONE, UL "use_envelope_from", 0 },
  /*
  */
  { "use_from",         DT_BOOL, R_NONE, OPT_USE_FROM, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will generate the ``From:'' header field when
  ** sending messages.  If \fIunset\fP, no ``From:'' header field will be
  ** generated unless the user explicitly sets one using the ``$my_hdr''
  ** command.
  */
#ifdef HAVE_GETADDRINFO
  { "use_ipv6",         DT_BOOL, R_NONE, OPT_USE_IPV6, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will look for IPv6 addresses of hosts it tries to
  ** contact.  If this option is \fIunset\fP, NeoMutt will restrict itself to IPv4 addresses.
  ** Normally, the default should work.
  */
#endif /* HAVE_GETADDRINFO */
  { "user_agent",       DT_BOOL, R_NONE, OPT_USER_AGENT, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will add a ``User-Agent:'' header to outgoing
  ** messages, indicating which version of NeoMutt was used for composing
  ** them.
  */
  { "visual",           DT_PATH, R_NONE, UL &Visual, 0 },
  /*
  ** .pp
  ** Specifies the visual editor to invoke when the ``\fC~v\fP'' command is
  ** given in the built-in editor.
  */
#ifdef USE_NOTMUCH
  { "vfolder_format",   DT_STRING,  R_INDEX, UL &VfolderFormat, UL "%2C %?n?%4n/&     ?%4m %f" },
  /*
  ** .pp
  ** This variable allows you to customize the file browser display for virtual
  ** folders to your personal taste.  This string uses many of the same
  ** expandos as $$folder_format.
  */
  { "virtual_spoolfile", DT_BOOL, R_NONE, OPT_VIRTUAL_SPOOLFILE, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will use the first defined virtual mailbox (see
  ** virtual-mailboxes) as a spool file.
  */
#endif
  { "wait_key",         DT_BOOL, R_NONE, OPT_WAIT_KEY, 1 },
  /*
  ** .pp
  ** Controls whether NeoMutt will ask you to press a key after an external command
  ** has been invoked by these functions: \fC<shell-escape>\fP,
  ** \fC<pipe-message>\fP, \fC<pipe-entry>\fP, \fC<print-message>\fP,
  ** and \fC<print-entry>\fP commands.
  ** .pp
  ** It is also used when viewing attachments with ``$auto_view'', provided
  ** that the corresponding mailcap entry has a \fIneedsterminal\fP flag,
  ** and the external program is interactive.
  ** .pp
  ** When \fIset\fP, NeoMutt will always ask for a key. When \fIunset\fP, NeoMutt will wait
  ** for a key only if the external command returned a non-zero status.
  */
  { "weed",             DT_BOOL, R_NONE, OPT_WEED, 1 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will weed headers when displaying, forwarding,
  ** printing, or replying to messages.
  */
  { "wrap",             DT_NUMBER,  R_PAGER, UL &Wrap, 0 },
  /*
  ** .pp
  ** When set to a positive value, NeoMutt will wrap text at $$wrap characters.
  ** When set to a negative value, NeoMutt will wrap text so that there are $$wrap
  ** characters of empty space on the right side of the terminal. Setting it
  ** to zero makes NeoMutt wrap at the terminal width.
  ** .pp
  ** Also see $$reflow_wrap.
  */
  { "wrap_headers",     DT_NUMBER,  R_PAGER, UL &WrapHeaders, 78 },
  /*
  ** .pp
  ** This option specifies the number of characters to use for wrapping
  ** an outgoing message's headers. Allowed values are between 78 and 998
  ** inclusive.
  ** .pp
  ** \fBNote:\fP This option usually shouldn't be changed. RFC5233
  ** recommends a line length of 78 (the default), so \fBplease only change
  ** this setting when you know what you're doing\fP.
  */
  { "wrap_search",      DT_BOOL, R_NONE, OPT_WRAP_SEARCH, 1 },
  /*
  ** .pp
  ** Controls whether searches wrap around the end.
  ** .pp
  ** When \fIset\fP, searches will wrap around the first (or last) item. When
  ** \fIunset\fP, incremental searches will not wrap.
  */
  { "wrapmargin",       DT_NUMBER,  R_PAGER, UL &Wrap, 0 },
  /*
  ** .pp
  ** (DEPRECATED) Equivalent to setting $$wrap with a negative value.
  */
  { "write_bcc",        DT_BOOL, R_NONE, OPT_WRITE_BCC, 1 },
  /*
  ** .pp
  ** Controls whether NeoMutt writes out the ``Bcc:'' header when preparing
  ** messages to be sent.  Exim users may wish to unset this. If NeoMutt
  ** is set to deliver directly via SMTP (see $$smtp_url), this
  ** option does nothing: NeoMutt will never write out the ``Bcc:'' header
  ** in this case.
  */
  { "write_inc",        DT_NUMBER,  R_NONE, UL &WriteInc, 10 },
  /*
  ** .pp
  ** When writing a mailbox, a message will be printed every
  ** $$write_inc messages to indicate progress.  If set to 0, only a
  ** single message will be displayed before writing a mailbox.
  ** .pp
  ** Also see the $$read_inc, $$net_inc and $$time_inc variables and the
  ** ``$tuning'' section of the manual for performance considerations.
  */
  { "xterm_icon",        DT_SYNONYM,  R_NONE, UL "ts_icon_format", 0 },
  /*
  */
  { "xterm_title",       DT_SYNONYM,  R_NONE, UL "ts_status_format", 0 },
  /*
  */
  { "xterm_set_titles",  DT_SYNONYM,  R_NONE, UL "ts_enabled", 0 },
  /*
  */
  { "xlabel_delimiter", DT_STRING, R_NONE, UL &XlabelDelimiter, UL "" },
  /*
  ** .pp
  ** The character used to delimit distinct keywords in X-Label headers.
  ** X-Label is primarily a NeoMutt artifact, and the semantics of the field
  ** were never defined: it is free-form text.  However interaction with
  ** X-Keywords:, X-Mozilla-Keys:, and Keywords: requires that we adopt
  ** some means of identifying separate keywords within the field.  Set
  ** this to your personal convention.
  ** .pp
  ** This affect both parsing existing X-Label headers and writing new
  ** X-Label headers.  You can modify this variable in runtime to accomplish
  ** various kinds of conversion.
  */
#ifdef USE_NNTP
  { "x_comment_to",     DT_BOOL, R_NONE, OPT_X_COMMENT_TO, 0 },
  /*
  ** .pp
  ** If \fIset\fP, NeoMutt will add ``X-Comment-To:'' field (that contains full
  ** name of original article author) to article that followuped to newsgroup.
  */
#endif
  { "collapse_all",     DT_BOOL, R_NONE, OPT_COLLAPSE_ALL, 0 },
  /*
  ** .pp
  ** When \fIset\fP, NeoMutt will collapse all threads when entering a folder.
  */
  /*--*/
  { "pgp_encrypt_self",   DT_QUAD, R_NONE, OPT_PGP_ENCRYPT_SELF,   MUTT_NO },
  { "smime_encrypt_self", DT_QUAD, R_NONE, OPT_SMIME_ENCRYPT_SELF, MUTT_NO },
  { NULL, 0, 0, 0, 0 },
};

const struct Mapping SortMethods[] = {
  { "date",             SORT_DATE },
  { "date-sent",        SORT_DATE },
  { "date-received",    SORT_RECEIVED },
  { "mailbox-order",    SORT_ORDER },
  { "subject",          SORT_SUBJECT },
  { "from",             SORT_FROM },
  { "size",             SORT_SIZE },
  { "threads",          SORT_THREADS },
  { "to",               SORT_TO },
  { "score",            SORT_SCORE },
  { "spam",             SORT_SPAM },
  { "label",            SORT_LABEL },
  { NULL,               0 },
};

/* same as SortMethods, but with "threads" replaced by "date" */

const struct Mapping SortAuxMethods[] = {
  { "date",             SORT_DATE },
  { "date-sent",        SORT_DATE },
  { "date-received",    SORT_RECEIVED },
  { "mailbox-order",    SORT_ORDER },
  { "subject",          SORT_SUBJECT },
  { "from",             SORT_FROM },
  { "size",             SORT_SIZE },
  { "threads",          SORT_DATE },    /* note: sort_aux == threads
                                         * isn't possible.
                                         */
  { "to",               SORT_TO },
  { "score",            SORT_SCORE },
  { "spam",             SORT_SPAM },
  { "label",            SORT_LABEL },
  { NULL,               0 },
};

const struct Mapping SortBrowserMethods[] = {
  { "alpha",    SORT_SUBJECT },
  { "count",    SORT_COUNT },
  { "date",     SORT_DATE },
  { "desc",     SORT_DESC },
  { "new",      SORT_UNREAD },
  { "size",     SORT_SIZE },
  { "unsorted", SORT_ORDER },
  { NULL,       0 },
};

const struct Mapping SortAliasMethods[] = {
  { "alias",    SORT_ALIAS },
  { "address",  SORT_ADDRESS },
  { "unsorted", SORT_ORDER },
  { NULL,       0 },
};

const struct Mapping SortKeyMethods[] = {
  { "address",  SORT_ADDRESS },
  { "date",     SORT_DATE },
  { "keyid",    SORT_KEYID },
  { "trust",    SORT_TRUST },
  { NULL,       0 },
};

const struct Mapping SortSidebarMethods[] = {
  { "alpha",            SORT_PATH },
  { "count",            SORT_COUNT },
  { "desc",             SORT_DESC },
  { "flagged",          SORT_FLAGGED },
  { "mailbox-order",    SORT_ORDER },
  { "name",             SORT_PATH },
  { "new",              SORT_UNREAD },  /* kept for compatibility */
  { "path",             SORT_PATH },
  { "unread",           SORT_UNREAD },
  { "unsorted",         SORT_ORDER },
  { NULL,               0 },
};

/* functions used to parse commands in a rc file */

static int parse_stailq(struct Buffer *buf, struct Buffer *s, unsigned long data,
                      struct Buffer *err);
static int parse_spam_list(struct Buffer *buf, struct Buffer *s,
                           unsigned long data, struct Buffer *err);
static int parse_unstailq(struct Buffer *buf, struct Buffer *s,
                        unsigned long data, struct Buffer *err);
#ifdef USE_SIDEBAR
static int parse_path_list(struct Buffer *buf, struct Buffer *s,
                           unsigned long data, struct Buffer *err);
static int parse_path_unlist(struct Buffer *buf, struct Buffer *s,
                             unsigned long data, struct Buffer *err);
#endif

static int parse_group(struct Buffer *buf, struct Buffer *s, unsigned long data,
                       struct Buffer *err);

static int parse_lists(struct Buffer *buf, struct Buffer *s, unsigned long data,
                       struct Buffer *err);
static int parse_unlists(struct Buffer *buf, struct Buffer *s,
                         unsigned long data, struct Buffer *err);
static int parse_alias(struct Buffer *buf, struct Buffer *s, unsigned long data,
                       struct Buffer *err);
static int parse_unalias(struct Buffer *buf, struct Buffer *s,
                         unsigned long data, struct Buffer *err);
static int finish_source(struct Buffer *buf, struct Buffer *s,
                         unsigned long data, struct Buffer *err);
static int parse_ifdef(struct Buffer *buf, struct Buffer *s, unsigned long data,
                       struct Buffer *err);
static int parse_ignore(struct Buffer *buf, struct Buffer *s,
                        unsigned long data, struct Buffer *err);
static int parse_unignore(struct Buffer *buf, struct Buffer *s,
                          unsigned long data, struct Buffer *err);
static int parse_source(struct Buffer *buf, struct Buffer *token,
                        unsigned long data, struct Buffer *err);
static int parse_set(struct Buffer *buf, struct Buffer *s, unsigned long data,
                     struct Buffer *err);
static int parse_setenv(struct Buffer *buf, struct Buffer *s,
                        unsigned long data, struct Buffer *err);
static int parse_my_hdr(struct Buffer *buf, struct Buffer *s,
                        unsigned long data, struct Buffer *err);
static int parse_unmy_hdr(struct Buffer *buf, struct Buffer *s,
                          unsigned long data, struct Buffer *err);
static int parse_subscribe(struct Buffer *buf, struct Buffer *s,
                           unsigned long data, struct Buffer *err);
static int parse_unsubscribe(struct Buffer *buf, struct Buffer *s,
                             unsigned long data, struct Buffer *err);
static int parse_attachments(struct Buffer *buf, struct Buffer *s,
                             unsigned long data, struct Buffer *err);
static int parse_unattachments(struct Buffer *buf, struct Buffer *s,
                               unsigned long data, struct Buffer *err);

static int parse_replace_list(struct Buffer *buf, struct Buffer *s,
                              unsigned long data, struct Buffer *err);
static int parse_unreplace_list(struct Buffer *buf, struct Buffer *s,
                                unsigned long data, struct Buffer *err);
static int parse_subjectrx_list(struct Buffer *buf, struct Buffer *s,
                                unsigned long data, struct Buffer *err);
static int parse_unsubjectrx_list(struct Buffer *buf, struct Buffer *s,
                                  unsigned long data, struct Buffer *err);
static int parse_alternates(struct Buffer *buf, struct Buffer *s, unsigned long data,

                            struct Buffer *err);
static int parse_unalternates(struct Buffer *buf, struct Buffer *s,
                              unsigned long data, struct Buffer *err);

/* Parse -group arguments */
static int parse_group_context(struct GroupContext **ctx, struct Buffer *buf,
                               struct Buffer *s, unsigned long data, struct Buffer *err);

#ifdef USE_NOTMUCH
static int parse_tag_transforms(struct Buffer *buf, struct Buffer *s,
                                unsigned long data, struct Buffer *err);
static int parse_tag_formats(struct Buffer *buf, struct Buffer *s,
                             unsigned long data, struct Buffer *err);
#endif

#ifdef USE_IMAP
static int parse_subscribe_to(struct Buffer *buf, struct Buffer *s,
                                unsigned long data, struct Buffer *err);
static int parse_unsubscribe_from(struct Buffer *buf, struct Buffer *s,
                                unsigned long data, struct Buffer *err);
#endif

const struct Command Commands[] = {
#ifdef USE_SOCKET
  { "account-hook",        mutt_parse_hook,        MUTT_ACCOUNTHOOK },
#endif
  { "alias",               parse_alias,            0 },
  { "alternates",          parse_alternates,       0 },
  { "alternative_order",   parse_stailq,           UL &AlternativeOrderList },
#ifdef USE_COMPRESSED
  { "append-hook",         mutt_parse_hook,        MUTT_APPENDHOOK },
#endif
  { "attachments",         parse_attachments,      0 },
  { "auto_view",           parse_stailq,           UL &AutoViewList },
  { "bind",                mutt_parse_bind,        0 },
  { "charset-hook",        mutt_parse_hook,        MUTT_CHARSETHOOK },
#ifdef USE_COMPRESSED
  { "close-hook",          mutt_parse_hook,        MUTT_CLOSEHOOK },
#endif
#ifdef HAVE_COLOR
  { "color",               mutt_parse_color,       0 },
#endif
  { "crypt-hook",          mutt_parse_hook,        MUTT_CRYPTHOOK },
  { "exec",                mutt_parse_exec,        0 },
  { "fcc-hook",            mutt_parse_hook,        MUTT_FCCHOOK },
  { "fcc-save-hook",       mutt_parse_hook,        MUTT_FCCHOOK | MUTT_SAVEHOOK },
  { "finish",              finish_source,          0 },
  { "folder-hook",         mutt_parse_hook,        MUTT_FOLDERHOOK },
  { "group",               parse_group,            MUTT_GROUP },
  { "hdr_order",           parse_stailq,           UL &HeaderOrderList },
  { "iconv-hook",          mutt_parse_hook,        MUTT_ICONVHOOK },
  { "ifdef",               parse_ifdef,            0 },
  { "ifndef",              parse_ifdef,            1 },
  { "ignore",              parse_ignore,           0 },
  { "lists",               parse_lists,            0 },
#ifdef USE_LUA
  { "lua",                 mutt_lua_parse,         0 },
  { "lua-source",          mutt_lua_source_file,   0 },
#endif
  { "macro",               mutt_parse_macro,       0 },
  { "mailboxes",           mutt_parse_mailboxes,   0 },
  { "mailto_allow",        parse_stailq,           UL &MailToAllow },
  { "mbox-hook",           mutt_parse_hook,        MUTT_MBOXHOOK },
  { "message-hook",        mutt_parse_hook,        MUTT_MESSAGEHOOK },
  { "mime_lookup",         parse_stailq,           UL &MimeLookupList },
  { "mono",                mutt_parse_mono,        0 },
  { "my_hdr",              parse_my_hdr,           0 },
  { "nospam",              parse_spam_list,        MUTT_NOSPAM },
#ifdef USE_COMPRESSED
  { "open-hook",           mutt_parse_hook,        MUTT_OPENHOOK },
#endif
  { "pgp-hook",            mutt_parse_hook,        MUTT_CRYPTHOOK },
  { "push",                mutt_parse_push,        0 },
  { "reply-hook",          mutt_parse_hook,        MUTT_REPLYHOOK },
  { "reset",               parse_set,              MUTT_SET_RESET },
  { "save-hook",           mutt_parse_hook,        MUTT_SAVEHOOK },
  { "score",               mutt_parse_score,       0 },
  { "send-hook",           mutt_parse_hook,        MUTT_SENDHOOK },
  { "send2-hook",          mutt_parse_hook,        MUTT_SEND2HOOK },
  { "set",                 parse_set,              0 },
  { "setenv",              parse_setenv,           0 },
  { "shutdown-hook",       mutt_parse_hook,        MUTT_SHUTDOWNHOOK | MUTT_GLOBALHOOK },
#ifdef USE_SIDEBAR
  { "sidebar_whitelist",   parse_path_list,        UL &SidebarWhitelist },
#endif
  { "source",              parse_source,           0 },
  { "spam",                parse_spam_list,        MUTT_SPAM },
  { "startup-hook",        mutt_parse_hook,        MUTT_STARTUPHOOK | MUTT_GLOBALHOOK },
  { "subjectrx",           parse_subjectrx_list,   UL &SubjectRegexList },
  { "subscribe",           parse_subscribe,        0 },
#ifdef USE_IMAP
  { "subscribe-to",        parse_subscribe_to,     0 },
#endif
#ifdef USE_NOTMUCH
  { "tag-formats",         parse_tag_formats,      0 },
  { "tag-transforms",      parse_tag_transforms,   0 },
#endif
  { "timeout-hook",        mutt_parse_hook,        MUTT_TIMEOUTHOOK | MUTT_GLOBALHOOK },
  { "toggle",              parse_set,              MUTT_SET_INV },
  { "unalias",             parse_unalias,          0 },
  { "unalternates",        parse_unalternates,     0 },
  { "unalternative_order", parse_unstailq,         UL &AlternativeOrderList },
  { "unattachments",       parse_unattachments,    0 },
  { "unauto_view",         parse_unstailq,         UL &AutoViewList },
#ifdef HAVE_COLOR
  { "uncolor",             mutt_parse_uncolor,     0 },
#endif
  { "ungroup",             parse_group,            MUTT_UNGROUP },
  { "unhdr_order",         parse_unstailq,         UL &HeaderOrderList },
  { "unhook",              mutt_parse_unhook,      0 },
  { "unignore",            parse_unignore,         0 },
  { "unlists",             parse_unlists,          0 },
  { "unmailboxes",         mutt_parse_unmailboxes, 0 },
  { "unmailto_allow",      parse_unstailq,         UL &MailToAllow },
  { "unmime_lookup",       parse_unstailq,         UL &MimeLookupList },
  { "unmono",              mutt_parse_unmono,      0 },
  { "unmy_hdr",            parse_unmy_hdr,         0 },
  { "unscore",             mutt_parse_unscore,     0 },
  { "unset",               parse_set,              MUTT_SET_UNSET },
  { "unsetenv",            parse_setenv,           MUTT_SET_UNSET },
#ifdef USE_SIDEBAR
  { "unsidebar_whitelist", parse_path_unlist,      UL &SidebarWhitelist },
#endif
  { "unsubjectrx",         parse_unsubjectrx_list, UL &SubjectRegexList },
  { "unsubscribe",         parse_unsubscribe,      0 },
#ifdef USE_IMAP
  { "unsubscribe-from",    parse_unsubscribe_from, 0 },
#endif
#ifdef USE_NOTMUCH
  { "unvirtual-mailboxes", mutt_parse_unmailboxes, MUTT_VIRTUAL },
  { "virtual-mailboxes",   mutt_parse_mailboxes,   MUTT_VIRTUAL | MUTT_NAMED },
#endif
  { NULL,                  NULL,                   0 },
};

#endif /* _MUTT_INIT_H */
