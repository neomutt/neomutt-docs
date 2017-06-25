---
author:
- 'Michael Elkins <me@cs.hmc.edu>'
release: 'version 20170609 (1.8.3)'
title: 'The Mutt E-Mail Client'
---

Introduction {#intro}
============

**Mutt** is a small but very powerful text-based MIME mail client. Mutt
is highly configurable, and is well suited to the mail power user with
advanced features like key bindings, keyboard macros, mail threading,
regular expression searches and a powerful pattern matching language for
selecting groups of messages.

NeoMutt Home Page {#homepage}
-----------------

The homepage can be found at <https://www.neomutt.org/>.

Mailing Lists {#mailinglists}
-------------

-   <neomutt-users@neomutt.org> — help, bug reports and
    feature requests. To subscribe to this list, please send a mail to
    <neomutt-users-request@neomutt.org> with the subject "subscribe".

-   <neomutt-devel@neomutt.org> — development mailing list. To subscribe
    to this list, please send a mail to
    <neomutt-devel-request@neomutt.org> with the subject "subscribe".

NeoMutt Online Resources {#irc}
------------------------

Issue Tracking System

:   Bugs may be reported on the devel mailing list, or on GitHub:
    <https://github.com/neomutt/neomutt/issues>

IRC

:   For the IRC user community, visit channel *\#neomutt* on
    [irc.freenode.net](https://webchat.freenode.net).

Contributing to Mutt {#contrib}
--------------------

There are various ways to contribute to the Mutt project.

Especially for new users it may be helpful to meet other new and
experienced users to chat about Mutt, talk about problems and share
tricks.

Since translations of Mutt into other languages are highly appreciated,
the Mutt developers always look for skilled translators that help
improve and continue to maintain stale translations.

For contributing code patches for new features and bug fixes, please
refer to the developer pages at <https://www.neomutt.org/dev.html> for
more details.

Typographical Conventions {#typo}
-------------------------

This section lists typographical conventions followed throughout this
manual. See table [table\_title](#tab-typo)for typographical conventions
for special terms.

  Item               Refers to...
  ------------------ -------------------------------------------
  `printf(3)`        UNIX manual pages, execute `man 3 printf`
  `<PageUp>`         named keys
  `<create-alias>`   named Mutt function
  `^G`               Control+G key combination
  \$mail\_check      Mutt configuration option
  `$HOME`            environment variable

  : Typographical conventions for special terms

Examples are presented as:

    mutt -v

Within command synopsis, curly brackets ( “{}”) denote a set of options
of which one is mandatory, square brackets ( “\[\]”) denote optional
arguments, three dots denote that the argument may be repeated arbitrary
times.

Copyright
---------

Mutt is Copyright © 1996-2016 Michael R. Elkins <me@mutt.org> and
others.

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2 of the License, or (at your
option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

Getting Started {#gettingstarted}
===============

This section is intended as a brief overview of how to use Mutt. There
are many other features which are described elsewhere in the manual.
There is even more information available in the Mutt FAQ and various web
pages. See the [Mutt homepage](http://www.mutt.org/) for more details.

The keybindings described in this section are the defaults as
distributed. Your local system administrator may have altered the
defaults for your site. You can always type “?”in any menu to display
the current bindings.

The first thing you need to do is invoke Mutt, simply by typing `mutt`
at the command line. There are various command-line options, see either
the Mutt man page or the [reference](#commandline).

Core Concepts
-------------

Mutt is a text-based application which interacts with users through
different menus which are mostly line-/entry-based or page-based. A
line-based menu is the so-called “index” menu (listing all messages of
the currently opened folder) or the “alias” menu (allowing you to select
recipients from a list). Examples for page-based menus are the
“pager”(showing one message at a time) or the “help” menu listing all
available key bindings.

The user interface consists of a context sensitive help line at the top,
the menu's contents followed by a context sensitive status line and
finally the command line. The command line is used to display
informational and error messages as well as for prompts and for entering
interactive commands.

Mutt is configured through variables which, if the user wants to
permanently use a non-default value, are written to configuration files.
Mutt supports a rich config file syntax to make even complex
configuration files readable and commentable.

Because Mutt allows for customizing almost all key bindings, there are
so-called “functions” which can be executed manually (using the command
line) or in macros. Macros allow the user to bind a sequence of commands
to a single key or a short key sequence instead of repeating a sequence
of actions over and over.

Many commands (such as saving or copying a message to another folder)
can be applied to a single message or a set of messages (so-called
“tagged” messages). To help selecting messages, Mutt provides a rich set
of message patterns (such as recipients, sender, body contents, date
sent/received, etc.) which can be combined into complex expressions
using the boolean *and* and *or* operations as well as negating. These
patterns can also be used to (for example) search for messages or to
limit the index to show only matching messages.

Mutt supports a “hook” concept which allows the user to execute
arbitrary configuration commands and functions in certain situations
such as entering a folder, starting a new message or replying to an
existing one. These hooks can be used to highly customize Mutt's
behavior including managing multiple identities, customizing the display
for a folder or even implementing auto-archiving based on a per-folder
basis and much more.

Besides an interactive mode, Mutt can also be used as a command-line
tool only send messages. It also supports a `mailx(1)`-compatible
interface, see [table\_title](#tab-commandline-options)for a complete
list of command-line options.

Screens and Menus {#concept-screens-and-menus}
-----------------

### Index {#intro-index}

The index is the screen that you usually see first when you start Mutt.
It gives an overview over your emails in the currently opened mailbox.
By default, this is your system mailbox. The information you see in the
index is a list of emails, each with its number on the left, its flags
(new email, important email, email that has been forwarded or replied
to, tagged email, ...), the date when email was sent, its sender, the
email size, and the subject. Additionally, the index also shows thread
hierarchies: when you reply to an email, and the other person replies
back, you can see the other person's email in a "sub-tree" below. This
is especially useful for personal email between a group of people or
when you've subscribed to mailing lists.

### Pager {#intro-pager}

The pager is responsible for showing the email content. On the top of
the pager you have an overview over the most important email headers
like the sender, the recipient, the subject, and much more information.
How much information you actually see depends on your configuration,
which we'll describe below.

Below the headers, you see the email body which usually contains the
message. If the email contains any attachments, you will see more
information about them below the email body, or, if the attachments are
text files, you can view them directly in the pager.

To give the user a good overview, it is possible to configure Mutt to
show different things in the pager with different colors. Virtually
everything that can be described with a regular expression can be
colored, e.g. URLs, email addresses or smileys.

### File Browser {#intro-browser}

The file browser is the interface to the local or remote file system.
When selecting a mailbox to open, the browser allows custom sorting of
items, limiting the items shown by a regular expression and a freely
adjustable format of what to display in which way. It also allows for
easy navigation through the file system when selecting file(s) to attach
to a message, select multiple files to attach and many more.

### Sidebar {#intro-sidebar}

The Sidebar shows a list of all your mailboxes. The list can be turned
on and off, it can be themed and the list style can be configured.

This part of the manual is suitable for beginners. If you already know
Mutt you could skip ahead to the main [Sidebar guide](#sidebar). If you
just want to get started, you could use the sample [Sidebar
muttrc](#sidebar-muttrc).

To check if Mutt supports “Sidebar”, look for the string `+sidebar` in
the mutt version.

    mutt -v

**Let's turn on the Sidebar:**

    set sidebar_visible
    set sidebar_format = "%B%?F? [%F]?%* %?N?%N/?%S"
    set mail_check_stats

You will see something like this. A list of mailboxes on the left. A
list of emails, from the selected mailbox, on the right.

    Fruit [1]     3/8|  1    + Jan 24  Rhys Lee         (192)  Yew
    Animals [1]   2/6|  2    + Feb 11  Grace Hall       (167)  Ilama
    Cars            4|  3      Feb 23  Aimee Scott      (450)  Nectarine
    Seas          1/7|  4    ! Feb 28  Summer Jackson   (264)  Lemon
                     |  5      Mar 07  Callum Harrison  (464)  Raspberry
                     |  6 N  + Mar 24  Samuel Harris    (353)  Tangerine          
                     |  7 N  + Sep 05  Sofia Graham     (335)  Cherry
                     |  8 N    Sep 16  Ewan Brown       (105)  Ugli
                     |
                     |

This user has four mailboxes: “Fruit”, “Cars”, “Animals” and “Seas”.

The current, open, mailbox is “Fruit”. We can also see information about
the other mailboxes. For example: The “Animals” mailbox contains, 1
flagged email, 2 new emails out of a total of 6 emails.

#### Navigation {#intro-sidebar-navigation}

The Sidebar adds some new [functions](#sidebar-functions) to Mutt.

The user pressed the “c” key to `<change-folder>`to the “Animals”
mailbox. The Sidebar automatically updated the indicator to match.

    Fruit [1]     3/8|  1      Jan 03  Tia Gibson       (362)  Caiman
    Animals [1]   2/6|  2    + Jan 22  Rhys Lee         ( 48)  Dolphin
    Cars            4|  3    ! Aug 16  Ewan Brown       (333)  Hummingbird
    Seas          1/7|  4      Sep 25  Grace Hall       ( 27)  Capybara
                     |  5 N  + Nov 12  Evelyn Rogers    (453)  Tapir              
                     |  6 N  + Nov 16  Callum Harrison  (498)  Hedgehog
                     |
                     |
                     |
                     |

Let's map some functions:

    bind index,pager \CP sidebar-prev       # Ctrl-Shift-P - Previous Mailbox
    bind index,pager \CN sidebar-next       # Ctrl-Shift-N - Next Mailbox
    bind index,pager \CO sidebar-open       # Ctrl-Shift-O - Open Highlighted Mailbox

Press “Ctrl-Shift-N”(Next mailbox) twice will move the Sidebar
**highlight** to down to the “Seas” mailbox.

    Fruit [1]     3/8|  1      Jan 03  Tia Gibson       (362)  Caiman
    Animals [1]   2/6|  2    + Jan 22  Rhys Lee         ( 48)  Dolphin
    Cars            4|  3    ! Aug 16  Ewan Brown       (333)  Hummingbird
    Seas          1/7|  4      Sep 25  Grace Hall       ( 27)  Capybara
                     |  5 N  + Nov 12  Evelyn Rogers    (453)  Tapir              
                     |  6 N  + Nov 16  Callum Harrison  (498)  Hedgehog
                     |
                     |
                     |
                     |

> **Note**
>
> Functions `<sidebar-next>`and `<sidebar-prev>`move the Sidebar
> **highlight**. They **do not** change the open mailbox.

Press “Ctrl-Shift-O”( `<sidebar-open>`) to open the highlighted mailbox.

    Fruit [1]     3/8|  1    ! Mar 07  Finley Jones     (139)  Molucca Sea
    Animals [1]   2/6|  2    + Mar 24  Summer Jackson   ( 25)  Arafura Sea
    Cars            4|  3    + Feb 28  Imogen Baker     (193)  Pechora Sea
    Seas          1/7|  4 N  + Feb 23  Isla Hussain     (348)  Balearic Sea       
                     |
                     |
                     |
                     |
                     |
                     |

#### Features {#intro-sidebar-features}

The Sidebar shows a list of mailboxes in a panel.

Everything about the Sidebar can be configured.

-   Visibility

-   Width

<!-- -->

-   Display all

-   Limit to mailboxes with new mail

-   Whitelist mailboxes to display always

<!-- -->

-   Unsorted (order of mailboxes commands)

-   Sorted alphabetically

-   Sorted by number of new mails

<!-- -->

-   Sidebar indicators and divider

-   Mailboxes depending on their type

-   Mailboxes depending on their contents

<!-- -->

-   Hide/Unhide the Sidebar

-   Select previous/next mailbox

-   Select previous/next mailbox with new mail

-   Page up/down through a list of mailboxes

<!-- -->

-   [Formatting string for mailbox](#intro-sidebar-format)

-   [Wraparound searching](#sidebar-next-new-wrap)

-   [Flexible mailbox abbreviations](#intro-sidebar-abbrev)

-   Support for Unicode mailbox names (utf-8)

#### Display {#intro-sidebar-display}

Everything about the Sidebar can be configured.

-   [Sidebar variables to set](#sidebar-variables)

-   [Sidebar colors to apply](#sidebar-colors)

-   [Sidebar sort methods](#sidebar-sort)

##### Sidebar Basics {#intro-sidebar-basics}

The most important variable is `$sidebar_visible`. You can set this in
your “muttrc”, or bind a key to the function `<sidebar-toggle-visible>`.

    set sidebar_visible                         # Make the Sidebar visible by default
    bind index,pager B sidebar-toggle-visible   # Use 'B' to switch the Sidebar on and off

Next, decide how wide you want the Sidebar to be. 25 characters might be
enough for the mailbox name and some numbers. Remember, you can
hide/show the Sidebar at the press of button.

Finally, you might want to change the divider character. By default,
Sidebar draws an ASCII line between it and the Index panel If your
terminal supports it, you can use a Unicode line-drawing character.

    set sidebar_width = 25                  # Plenty of space
    set sidebar_divider_char = '│'          # Pretty line-drawing character

##### Sidebar Format String {#intro-sidebar-format}

`$sidebar_format` allows you to customize the Sidebar display. For an
introduction, read [format strings](#index-format) including the section
about [conditionals](#formatstrings-conditionals).

The default value is: `%B%* %n`

A more detailed value is: `%B%?F? [%F]?%* %?N?%N/?%S`

-   `%B`- Mailbox name

-   `%?F? [%F]?`- If flagged emails `[%F]`, otherwise nothing

-   `%*`- Pad with spaces

-   `%?N?%N/?`- If new emails `%N/`, otherwise nothing

-   `%S`- Total number of emails

  Format   Notes   Description
  -------- ------- --------------------------------------------------------------------------------------------------------------------------
  %B               Name of the mailbox
  %S       \* †    Size of mailbox (total number of messages)
  %F       \* †    Number of Flagged messages in the mailbox
  %N       \* †    Number of New messages in the mailbox
  %n       \*      If there's new mail, display “N”, otherwise nothing
  %!               “!”: one flagged message; “!!”: two flagged messages; “n!”: n flagged messages (for n &gt; 2). Otherwise prints nothing.
  %d       \* ‡    Number of deleted messages
  %L       \* ‡    Number of messages after limiting
  %t       \* ‡    Number of tagged messages
  %&gt;X           Right justify the rest of the string and pad with “X”
  %|X              Pad to the end of the line with “X”
  %\*X             Soft-fill with character “X” as pad

  : sidebar\_format

\* = Can be optionally printed if nonzero

† = To use this expandos, you must first:

    set mail_check_stats

‡ = Only applicable to the current folder

Here are some examples. They show the number of (F)lagged, (N)ew and
(S)ize.

  Format                        Example
  ----------------------------- --------------------------------
  `%B%?F? [%F]?%* %?N?%N/?%S`       mailbox [F]            N/S
  `%B%* %F:%N:%S`                   mailbox              F:N:S
  `%B %?N?(%N)?%* %S`               mailbox (N)              S
  `%B%* ?F?%F/?%N`                  mailbox                F/S

  : sidebar\_format

##### Abbreviating Mailbox Names {#intro-sidebar-abbrev}

`$sidebar_delim_chars` tells Sidebar how to split up mailbox paths. For
local directories use “/”; for IMAP folders use “.”

###### Example 1 {#intro-sidebar-abbrev-ex1}

This example works well if your mailboxes have unique names after the
last separator.

Add some mailboxes of different depths.

    set folder="~/mail"
    mailboxes =fruit/apple          =fruit/banana          =fruit/cherry
    mailboxes =water/sea/sicily     =water/sea/archipelago =water/sea/sibuyan
    mailboxes =water/ocean/atlantic =water/ocean/pacific   =water/ocean/arctic

Shorten the names:

    set sidebar_short_path                  # Shorten mailbox names
    set sidebar_delim_chars="/"             # Delete everything up to the last / character

The screenshot below shows what the Sidebar would look like before and
after shortening.

    |fruit/apple                            |apple
    |fruit/banana                           |banana
    |fruit/cherry                           |cherry
    |water/sea/sicily                       |sicily
    |water/sea/archipelago                  |archipelago
    |water/sea/sibuyan                      |sibuyan
    |water/ocean/atlantic                   |atlantic
    |water/ocean/pacific                    |pacific
    |water/ocean/arctic                     |arctic

###### Example 2 {#intro-sidebar-abbrev-ex2}

This example works well if you have lots of mailboxes which are arranged
in a tree.

Add some mailboxes of different depths.

    set folder="~/mail"
    mailboxes =fruit
    mailboxes =fruit/apple =fruit/banana =fruit/cherry
    mailboxes =water
    mailboxes =water/sea
    mailboxes =water/sea/sicily =water/sea/archipelago =water/sea/sibuyan
    mailboxes =water/ocean
    mailboxes =water/ocean/atlantic =water/ocean/pacific =water/ocean/arctic

Shorten the names:

    set sidebar_short_path                  # Shorten mailbox names
    set sidebar_delim_chars="/"             # Delete everything up to the last / character
    set sidebar_folder_indent               # Indent folders whose names we've shortened
    set sidebar_indent_string="  "          # Indent with two spaces

The screenshot below shows what the Sidebar would look like before and
after shortening.

    |fruit                                  |fruit
    |fruit/apple                            |  apple
    |fruit/banana                           |  banana
    |fruit/cherry                           |  cherry
    |water                                  |water
    |water/sea                              |  sea
    |water/sea/sicily                       |    sicily
    |water/sea/archipelago                  |    archipelago
    |water/sea/sibuyan                      |    sibuyan
    |water/ocean                            |  ocean
    |water/ocean/atlantic                   |    atlantic
    |water/ocean/pacific                    |    pacific
    |water/ocean/arctic                     |    arctic

Sometimes, it will be necessary to add mailboxes, that you don't use, to
fill in part of the tree. This will trade vertical space for horizontal
space (but it looks good).

##### Limiting the Number of Mailboxes {#intro-sidebar-limit}

If you have a lot of mailboxes, sometimes it can be useful to hide the
ones you aren't using. `$sidebar_new_mail_only` tells Sidebar to only
show mailboxes that contain new, or flagged, email.

If you want some mailboxes to be always visible, then use the
`sidebar_whitelist` command. It takes a list of mailboxes as parameters.

    set sidebar_new_mail_only               # Only mailboxes with new/flagged email
    sidebar_whitelist fruit fruit/apple     # Always display these two mailboxes

#### Colors {#intro-sidebar-colors}

Here is a sample color scheme:

    color sidebar_indicator default color17         # Dark blue background
    color sidebar_highlight white   color238        # Grey background
    color sidebar_spoolfile yellow  default         # Yellow
    color sidebar_new       green   default         # Green
    color sidebar_ordinary  default default         # Default colors
    color sidebar_flagged   red     default         # Red
    color sidebar_divider   color8  default
              # Dark grey

There is a priority order when coloring Sidebar mailboxes. e.g. If a
mailbox has new mail it will have the `sidebar_new` color, even if it
also contains flagged mails.

  Priority   Color                 Description
  ---------- --------------------- ---------------------------------------------------
  Highest    `sidebar_indicator`   Mailbox is open
             `sidebar_highlight`   Mailbox is highlighted
             `sidebar_spoolfile`   Mailbox is the spoolfile (receives incoming mail)
             `sidebar_new`         Mailbox contains new mail
             `sidebar_flagged`     Mailbox contains flagged mail
  Lowest     `sidebar_ordinary`    Mailbox does not match above

  : Sidebar Color Priority

#### Config Changes {#intro-sidebar-config-changes}

If you haven't used Sidebar before, you can ignore this section.

Some of the Sidebar config has been changed to make its meaning clearer.
These changes have been made since the previous Sidebar release:
2015-11-11.

  Old Name                  New Name
  ------------------------- --------------------------
  `$sidebar_delim`          `$sidebar_divider_char`
  `$sidebar_folderindent`   `$sidebar_folder_indent`
  `$sidebar_indentstr`      `$sidebar_indent_string`
  `$sidebar_newmail_only`   `$sidebar_new_mail_only`
  `$sidebar_shortpath`      `$sidebar_short_path`
  `$sidebar_sort`           `$sidebar_sort_method`
  `<sidebar-scroll-down>`   `<sidebar-page-down>`
  `<sidebar-scroll-up>`     `<sidebar-page-up>`

  : Config Changes

### Help {#intro-help}

The help screen is meant to offer a quick help to the user. It lists the
current configuration of key bindings and their associated commands
including a short description, and currently unbound functions that
still need to be associated with a key binding (or alternatively, they
can be called via the Mutt command prompt).

### Compose Menu {#intro-compose}

The compose menu features a split screen containing the information
which really matter before actually sending a message by mail: who gets
the message as what (recipients and who gets what kind of copy).
Additionally, users may set security options like deciding whether to
sign, encrypt or sign and encrypt a message with/for what keys. Also,
it's used to attach messages, to re-edit any attachment including the
message itself.

### Alias Menu {#intro-alias}

The alias menu is used to help users finding the recipients of messages.
For users who need to contact many people, there's no need to remember
addresses or names completely because it allows for searching, too. The
alias mechanism and thus the alias menu also features grouping several
addresses by a shorter nickname, the actual alias, so that users don't
have to select each single recipient manually.

### Attachment Menu {#intro-attach}

As will be later discussed in detail, Mutt features a good and stable
MIME implementation, that is, it supports sending and receiving messages
of arbitrary MIME types. The attachment menu displays a message's
structure in detail: what content parts are attached to which parent
part (which gives a true tree structure), which type is of what type and
what size. Single parts may saved, deleted or modified to offer great
and easy access to message's internals.

Moving Around in Menus {#menus}
----------------------

The most important navigation keys common to line- or entry-based menus
are shown in [table\_title](#tab-keys-nav-line)and in
[table\_title](#tab-keys-nav-page)for page-based menus.

  Key                   Function             Description
  --------------------- -------------------- -------------------------------------------
  j or &lt;Down&gt;     `<next-entry>`       move to the next entry
  k or &lt;Up&gt;       `<previous-entry>`   move to the previous entry
  z or &lt;PageDn&gt;   `<page-down>`        go to the next page
  Z or &lt;PageUp&gt;   `<page-up>`          go to the previous page
  = or &lt;Home&gt;     `<first-entry>`      jump to the first entry
  \* or &lt;End&gt;     `<last-entry>`       jump to the last entry
  q                     `<quit>`             exit the current menu
  ?                     `<help>`             list all keybindings for the current menu

  : Most common navigation keys in entry-based menus

  Key                                  Function            Description
  ------------------------------------ ------------------- ------------------------
  J or &lt;Return&gt;                  `<next-line>`       scroll down one line
  &lt;Backspace&gt;                    `<previous-line>`   scroll up one line
  K, &lt;Space&gt; or &lt;PageDn&gt;   `<next-page>`       move to the next page
  - or &lt;PageUp&gt;                  `<previous-page>`   move the previous page
  &lt;Home&gt;                         `<top>`             move to the top
  &lt;End&gt;                          `<bottom>`          move to the bottom

  : Most common navigation keys in page-based menus

Editing Input Fields {#editing}
--------------------

### Introduction {#editing-intro}

Mutt has a built-in line editor for inputting text, e.g. email addresses
or filenames. The keys used to manipulate text input are very similar to
those of Emacs. See [table\_title](#tab-keys-editor)for a full reference
of available functions, their default key bindings, and short
descriptions.

  Key                     Function              Description
  ----------------------- --------------------- --------------------------------------
  \^A or &lt;Home&gt;     `<bol>`               move to the start of the line
  \^B or &lt;Left&gt;     `<backward-char>`     move back one char
  Esc B                   `<backward-word>`     move back one word
  \^D or &lt;Delete&gt;   `<delete-char>`       delete the char under the cursor
  \^E or &lt;End&gt;      `<eol>`               move to the end of the line
  \^F or &lt;Right&gt;    `<forward-char>`      move forward one char
  Esc F                   `<forward-word>`      move forward one word
  &lt;Tab&gt;             `<complete>`          complete filename, alias, or label
  \^T                     `<complete-query>`    complete address with query
  \^K                     `<kill-eol>`          delete to the end of the line
  Esc d                   `<kill-eow>`          delete to the end of the word
  \^W                     `<kill-word>`         kill the word in front of the cursor
  \^U                     `<kill-line>`         delete entire line
  \^V                     `<quote-char>`        quote the next typed key
  &lt;Up&gt;              `<history-up>`        recall previous string from history
  &lt;Down&gt;            `<history-down>`      recall next string from history
  &lt;BackSpace&gt;       `<backspace>`         kill the char in front of the cursor
  Esc u                   `<upcase-word>`       convert word to upper case
  Esc l                   `<downcase-word>`     convert word to lower case
  Esc c                   `<capitalize-word>`   capitalize the word
  \^G                     n/a                   abort
  &lt;Return&gt;          n/a                   finish editing

  : Most common line editor keys

You can remap the *editor* functions using the [`bind`](#bind)command.
For example, to make the &lt;Delete&gt; key delete the character in
front of the cursor rather than under, you could use:

    bind editor <delete> backspace

### History {#editing-history}

Mutt maintains a history for the built-in editor. The number of items is
controlled by the [\$history](#history) variable and can be made
persistent using an external file specified using
[\$history\_file](#history-file) and [\$save\_history](#save-history).
You may cycle through them at an editor prompt by using the
`<history-up>`and/or `<history-down>`commands. Mutt will remember the
currently entered text as you cycle through history, and will wrap
around to the initial entry line.

Mutt maintains several distinct history lists, one for each of the
following categories:

-   `.muttrc` commands

-   addresses and aliases

-   shell commands

-   filenames

-   patterns

-   everything else

Mutt automatically filters out consecutively repeated items from the
history. If [\$history\_remove\_dups](#history-remove-dups) is set, all
repeated items are removed from the history. It also mimics the behavior
of some shells by ignoring items starting with a space. The latter
feature can be useful in macros to not clobber the history's valuable
entries with unwanted entries.

Reading Mail {#reading}
------------

Similar to many other mail clients, there are two modes in which mail is
read in Mutt. The first is a list of messages in the mailbox, which is
called the “index” menu in Mutt. The second mode is the display of the
message contents. This is called the “pager.”

The next few sections describe the functions provided in each of these
modes.

### The Message Index {#index-menu}

Common keys used to navigate through and manage messages in the index
are shown in [table\_title](#tab-key-index). How messages are presented
in the index menu can be customized using the
[\$index\_format](#index-format) variable.

  Key              Description
  ---------------- ---------------------------------------------
  c                change to a different mailbox
  Esc c            change to a folder in read-only mode
  C                copy the current message to another mailbox
  Esc C            decode a message and copy it to a folder
  Esc s            decode a message and save it to a folder
  D                delete messages matching a pattern
  d                delete the current message
  F                mark as important
  l                show messages matching a pattern
  N                mark message as new
  o                change the current sort method
  O                reverse sort the mailbox
  q                save changes and exit
  s                save-message
  T                tag messages matching a pattern
  t                toggle the tag on a message
  Esc t            toggle tag on entire message thread
  U                undelete messages matching a pattern
  u                undelete-message
  v                view-attachments
  x                abort changes and exit
  &lt;Return&gt;   display-message
  &lt;Tab&gt;      jump to the next new or unread message
  @                show the author's full e-mail address
  \$               save changes to mailbox
  /                search
  Esc /            search-reverse
  \^L              clear and redraw the screen
  \^T              untag messages matching a pattern

  : Most common message index keys

In addition to who sent the message and the subject, a short summary of
the disposition of each message is printed beside the message number.
Zero or more of the “flags” in [table\_title](#tab-msg-status-flags)may
appear, some of which can be turned on or off using these functions:
`<set-flag>`and `<clear-flag>`bound by default to “w” and “W”
respectively.

Furthermore, the flags in [table\_title](#tab-msg-recip-flags)reflect
who the message is addressed to. They can be customized with the
[\$to\_chars](#to-chars) variable.

  Flag   Description
  ------ ---------------------------------------------------------------
  D      message is deleted (is marked for deletion)
  d      message has attachments marked for deletion
  K      contains a PGP public key
  N      message is new
  O      message is old
  P      message is PGP encrypted
  r      message has been replied to
  S      message is signed, and the signature is successfully verified
  s      message is signed
  !      message is flagged
  \*     message is tagged
  n      thread contains new messages (only if collapsed)
  o      thread contains old messages (only if collapsed)

  : Message status flags

  Flag   Description
  ------ ---------------------------------------------------
  +      message is to you and you only
  T      message is to you, but also to or CC'ed to others
  C      message is CC'ed to you
  F      message is from you
  L      message is sent to a subscribed mailing list

  : Message recipient flags

### The Pager {#pager-menu}

By default, Mutt uses its built-in pager to display the contents of
messages (an external pager such as `less(1)`can be configured, see
[\$pager](#pager) variable). The pager is very similar to the Unix
program `less(1)`though not nearly as featureful.

  Key              Description
  ---------------- --------------------------------------------------------------------
  &lt;Return&gt;   go down one line
  &lt;Space&gt;    display the next page (or next message if at the end of a message)
  -                go back to the previous page
  n                search for next match
  S                skip beyond quoted text
  T                toggle display of quoted text
  ?                show keybindings
  /                regular expression search
  Esc /            backward regular expression search
  \\               toggle highlighting of search matches
  \^               jump to the top of the message

  : Most common pager keys

In addition to key bindings in [table\_title](#tab-key-pager), many of
the functions from the index menu are also available in the pager, such
as `<delete-message>`or `<copy-message>`(this is one advantage over
using an external pager to view messages).

Also, the internal pager supports a couple other advanced features. For
one, it will accept and translate the “standard” nroff sequences for
bold and underline. These sequences are a series of either the letter,
backspace ( “\^H”), the letter again for bold or the letter, backspace,
“\_” for denoting underline. Mutt will attempt to display these in bold
and underline respectively if your terminal supports them. If not, you
can use the bold and underline [color](#color) objects to specify a
`color` or mono attribute for them.

Additionally, the internal pager supports the ANSI escape sequences for
character attributes. Mutt translates them into the correct color and
character settings. The sequences Mutt supports are:

    \e[
            Ps;
            Ps;..
            Ps;m

where *Ps* can be one of the codes shown in
[table\_title](#tab-ansi-esc).

  Escape code         Description
  ------------------- ---------------------------------------------------------------------
  0                   All attributes off
  1                   Bold on
  4                   Underline on
  5                   Blink on
  7                   Reverse video on
  3 *&lt;color&gt;*   Foreground color is *&lt;color&gt;*(see [table\_title](#tab-color))
  4 *&lt;color&gt;*   Background color is *&lt;color&gt;*(see [table\_title](#tab-color))

  : ANSI escape sequences

  Color code   Color
  ------------ ---------
  0            Black
  1            Red
  2            Green
  3            Yellow
  4            Blue
  5            Magenta
  6            Cyan
  7            White

  : Color sequences

Mutt uses these attributes for handling `text/enriched` messages, and
they can also be used by an external [autoview](#auto-view) script for
highlighting purposes.

> **Note**
>
> If you change the colors for your display, for example by changing the
> color associated with color2 for your xterm, then that color will be
> used instead of green.

> **Note**
>
> Note that the search commands in the pager take regular expressions,
> which are not quite the same as the more complex [patterns](#patterns)
> used by the search command in the index. This is because patterns are
> used to select messages by criteria whereas the pager already displays
> a selected message.

### Threaded Mode {#threads}

So-called “threads” provide a hierarchy of messages where replies are
linked to their parent message(s). This organizational form is extremely
useful in mailing lists where different parts of the discussion diverge.
Mutt displays threads as a tree structure.

In Mutt, when a mailbox is [sorted](#sort) by *threads*, there are a few
additional functions available in the *index* and *pager* modes as shown
in [table\_title](#tab-key-threads).

  Key     Function                 Description
  ------- ------------------------ ------------------------------------------------
  \^D     `<delete-thread>`        delete all messages in the current thread
  \^U     `<undelete-thread>`      undelete all messages in the current thread
  \^N     `<next-thread>`          jump to the start of the next thread
  \^P     `<previous-thread>`      jump to the start of the previous thread
  \^R     `<read-thread>`          mark the current thread as read
  Esc d   `<delete-subthread>`     delete all messages in the current subthread
  Esc u   `<undelete-subthread>`   undelete all messages in the current subthread
  Esc n   `<next-subthread>`       jump to the start of the next subthread
  Esc p   `<previous-subthread>`   jump to the start of the previous subthread
  Esc r   `<read-subthread>`       mark the current subthread as read
  Esc t   `<tag-thread>`           toggle the tag on the current thread
  Esc v   `<collapse-thread>`      toggle collapse for the current thread
  Esc V   `<collapse-all>`         toggle collapse for all threads
  P       `<parent-message>`       jump to parent message in thread

  : Most common thread mode keys

Collapsing a thread displays only the first message in the thread and
hides the others. This is useful when threads contain so many messages
that you can only see a handful of threads on the screen. See %M in
[\$index\_format](#index-format). For example, you could use
“%?M?(\#%03M)&(%4l)?”in [\$index\_format](#index-format) to optionally
display the number of hidden messages if the thread is collapsed. The `
        %?<char>?<if-part>&<else-part>?`syntax is explained in detail in
[format string conditionals](#formatstrings-conditionals).

Technically, every reply should contain a list of its parent messages in
the thread tree, but not all do. In these cases, Mutt groups them by
subject which can be controlled using the
[\$strict\_threads](#strict-threads) variable.

### Miscellaneous Functions {#reading-misc}

In addition, the *index* and *pager* menus have these interesting
functions:

`<create-alias>` (default: a)

:   Creates a new alias based upon the current message (or prompts for a
    new one). Once editing is complete, an [`alias`](#alias)command is
    added to the file specified by the [\$alias\_file](#alias-file)
    variable for future use

    > **Note**
    >
    > Mutt does not read the [\$alias\_file](#alias-file) upon startup
    > so you must explicitly [`source`](#source)the file.

`<check-traditional-pgp>` (default: Esc P)

:   This function will search the current message for content signed or
    encrypted with PGP the “traditional” way, that is, without proper
    MIME tagging. Technically, this function will temporarily change the
    MIME content types of the body parts containing PGP data; this is
    similar to the [`<edit-type>`](#edit-type)function's effect.

`<edit>` (default: e)

:   This command (available in the index and pager) allows you to edit
    the raw current message as it's present in the mail folder. After
    you have finished editing, the changed message will be appended to
    the current folder, and the original message will be marked for
    deletion; if the message is unchanged it won't be replaced.

`<edit-type>` (default: \^E on the attachment menu, and in the pager and index menus; \^T on the compose menu)

:   This command is used to temporarily edit an attachment's content
    type to fix, for instance, bogus character set parameters. When
    invoked from the index or from the pager, you'll have the
    opportunity to edit the top-level attachment's content type. On the
    [attachment menu](#attach-menu), you can change any attachment's
    content type. These changes are not persistent, and get lost upon
    changing folders.

    Note that this command is also available on the [compose
    menu](#compose-menu). There, it's used to fine-tune the properties
    of attachments you are going to send.

`<enter-command>` (default: “:”)

:   This command is used to execute any command you would normally put
    in a configuration file. A common use is to check the settings of
    variables, or in conjunction with [macros](#macro) to change
    settings on the fly.

`<extract-keys>` (default: \^K)

:   This command extracts PGP public keys from the current or
    tagged message(s) and adds them to your PGP public key ring.

`<forget-passphrase>` (default: \^F)

:   This command wipes the passphrase(s) from memory. It is useful, if
    you misspelled the passphrase.

`<list-reply>` (default: L)

:   Reply to the current or tagged message(s) by extracting any
    addresses which match the regular expressions given by the [`lists`
    or `subscribe`](#lists)commands, but also honor any
    `Mail-Followup-To` header(s) if the
    [\$honor\_followup\_to](#honor-followup-to) configuration variable
    is set. In addition, the `List-Post` header field is examined for
    `mailto:`URLs specifying a mailing list address. Using this when
    replying to messages posted to mailing lists helps avoid duplicate
    copies being sent to the author of the message you are replying to.

`<pipe-message>` (default: |)

:   Asks for an external Unix command and pipes the current or
    tagged message(s) to it. The variables
    [\$pipe\_decode](#pipe-decode), [\$pipe\_split](#pipe-split),
    [\$pipe\_sep](#pipe-sep) and [\$wait\_key](#wait-key) control the
    exact behavior of this function.

`<resend-message>` (default: Esc e)

:   Mutt takes the current message as a template for a new message. This
    function is best described as "recall from arbitrary folders". It
    can conveniently be used to forward MIME messages while preserving
    the original mail structure. Note that the amount of headers
    included here depends on the value of the [\$weed](#weed) variable.

    This function is also available from the attachment menu. You can
    use this to easily resend a message which was included with a bounce
    message as a `message/rfc822` body part.

`<shell-escape>` (default: !)

:   Asks for an external Unix command and executes it. The
    [\$wait\_key](#wait-key) can be used to control whether Mutt will
    wait for a key to be pressed when the command returns (presumably to
    let the user read the output of the command), based on the return
    status of the named command. If no command is given, an interactive
    shell is executed.

`<toggle-quoted>` (default: T)

:   The pager uses the [\$quote\_regexp](#quote-regexp) variable to
    detect quoted text when displaying the body of the message. This
    function toggles the display of the quoted material in the message.
    It is particularly useful when being interested in just the response
    and there is a large amount of quoted text in the way.

`<skip-quoted>` (default: S)

:   This function will go to the next line of non-quoted text which
    comes after a line of quoted text in the internal pager.

Sending Mail {#sending}
------------

### Introduction {#sending-intro}

The bindings shown in [table\_title](#tab-key-send)are available in the
*index* and *pager* to start a new message.

  Key     Function          Description
  ------- ----------------- ----------------------------------
  m       `<compose>`       compose a new message
  r       `<reply>`         reply to sender
  g       `<group-reply>`   reply to all recipients
  L       `<list-reply>`    reply to mailing list address
  f       `<forward>`       forward message
  b       `<bounce>`        bounce (remail) message
  Esc k   `<mail-key>`      mail a PGP public key to someone

  : Most common mail sending keys

*Bouncing* a message sends the message as-is to the recipient you
specify. *Forwarding* a message allows you to add comments or modify the
message you are forwarding. These items are discussed in greater detail
in the next section “[Forwarding and Bouncing Mail](#forwarding-mail).”

Mutt will then enter the *compose* menu and prompt you for the
recipients to place on the “To:”header field when you hit `m` to start a
new message. Next, it will ask you for the “Subject:”field for the
message, providing a default if you are replying to or forwarding a
message. You again have the chance to adjust recipients, subject, and
security settings right before actually sending the message. See also
[\$askcc](#askcc), [\$askbcc](#askbcc), [\$autoedit](#autoedit),
[\$bounce](#bounce), [\$fast\_reply](#fast-reply), and
[\$include](#include) for changing how and if Mutt asks these questions.

When replying, Mutt fills these fields with proper values depending on
the reply type. The types of replying supported are:

Simple reply

:   Reply to the author directly.

Group reply

:   Reply to the author as well to all recipients except you; this
    consults [`alternates`](#alternates).

List reply

:   Reply to all mailing list addresses found, either specified via
    configuration or auto-detected. See
    [Mailing Lists](#lists)for details.

After getting recipients for new messages, forwards or replies, Mutt
will then automatically start your [\$editor](#editor) on the message
body. If the [\$edit\_headers](#edit-headers) variable is set, the
headers will be at the top of the message in your editor; the message
body should start on a new line after the existing blank line at the end
of headers. Any messages you are replying to will be added in sort order
to the message, with appropriate [\$attribution](#attribution),
[\$indent\_string](#indent-string) and
[\$post\_indent\_string](#post-indent-string). When forwarding a
message, if the [\$mime\_forward](#mime-forward) variable is unset, a
copy of the forwarded message will be included. If you have specified a
[\$signature](#signature), it will be appended to the message.

Once you have finished editing the body of your mail message, you are
returned to the *compose* menu providing the functions shown in
[table\_title](#tab-func-compose)to modify, send or postpone the
message.

  Key     Function                Description
  ------- ----------------------- ----------------------------------------------
  a       `<attach-file>`         attach a file
  A       `<attach-message>`      attach message(s) to the message
  Esc k   `<attach-key>`          attach a PGP public key
  d       `<edit-description>`    edit description on attachment
  D       `<detach-file>`         detach a file
  t       `<edit-to>`             edit the To field
  Esc f   `<edit-from>`           edit the From field
  r       `<edit-reply-to>`       edit the Reply-To field
  c       `<edit-cc>`             edit the Cc field
  b       `<edit-bcc>`            edit the Bcc field
  y       `<send-message>`        send the message
  s       `<edit-subject>`        edit the Subject
  S       `<smime-menu>`          select S/MIME options
  f       `<edit-fcc>`            specify an “Fcc” mailbox
  p       `<pgp-menu>`            select PGP options
  P       `<postpone-message>`    postpone this message until later
  q       `<quit>`                quit (abort) sending the message
  w       `<write-fcc>`           write the message to a folder
  i       `<ispell>`              check spelling (if available on your system)
  \^F     `<forget-passphrase>`   wipe passphrase(s) from memory

  : Most common compose menu keys

The compose menu is also used to edit the attachments for a message
which can be either files or other messages. The
`<attach-message>`function to will prompt you for a folder to attach
messages from. You can now tag messages in that folder and they will be
attached to the message you are sending.

> **Note**
>
> Note that certain operations like composing a new mail, replying,
> forwarding, etc. are not permitted when you are in that folder. The %r
> in [\$status\_format](#status-format) will change to a “A” to indicate
> that you are in attach-message mode.

### Editing the Message Header {#edit-header}

When editing the header because of [\$edit\_headers](#edit-headers)
being set, there are a several pseudo headers available which will not
be included in sent messages but trigger special Mutt behavior.

#### Fcc: Pseudo Header {#fcc-header}

If you specify

`Fcc:` *filename*

as a header, Mutt will pick up *filename* just as if you had used the
`<edit-fcc>`function in the *compose* menu. It can later be changed from
the compose menu.

#### Attach: Pseudo Header {#attach-header}

You can also attach files to your message by specifying

`Attach:` *filename*\[ *description*\]

where *filename* is the file to attach and *description* is an optional
string to use as the description of the attached file. Spaces in
filenames have to be escaped using backslash ( “\\”). The file can be
removed as well as more added from the compose menu.

#### Pgp: Pseudo Header {#pgp-header}

If you want to use PGP, you can specify

`Pgp:`\[ `E`| `S`| `S` *&lt;id&gt;*\]

“E” selects encryption, “S” selects signing and “S&lt;id&gt;”selects
signing with the given key, setting [\$pgp\_sign\_as](#pgp-sign-as)
permanently. The selection can later be changed in the compose menu.

#### In-Reply-To: Header

When replying to messages, the *In-Reply-To:*header contains the
Message-Id of the message(s) you reply to. If you remove or modify its
value, Mutt will not generate a *References:*field, which allows you to
create a new message thread, for example to create a new message to a
mailing list without having to enter the mailing list's address.

If you intend to start a new thread by replying, please make really sure
you remove the *In-Reply-To:*header in your editor. Otherwise, though
you'll produce a technically valid reply, some netiquette guardians will
be annoyed by this so-called “thread hijacking”.

### Sending Cryptographically Signed/Encrypted Messages {#sending-crypto}

If you have told Mutt to PGP or S/MIME encrypt a message, it will guide
you through a key selection process when you try to send the message.
Mutt will not ask you any questions about keys which have a certified
user ID matching one of the message recipients' mail addresses. However,
there may be situations in which there are several keys, weakly
certified user ID fields, or where no matching keys can be found.

In these cases, you are dropped into a menu with a list of keys from
which you can select one. When you quit this menu, or Mutt can't find
any matching keys, you are prompted for a user ID. You can, as usually,
abort this prompt using `^G`. When you do so, Mutt will return to the
compose screen.

Once you have successfully finished the key selection, the message will
be encrypted using the selected public keys when sent out.

Most fields of the entries in the key selection menu (see also
[\$pgp\_entry\_format](#pgp-entry-format)) have obvious meanings. But
some explanations on the capabilities, flags, and validity fields are in
order.

The flags sequence ( “%f”) will expand to one of the flags in
[table\_title](#tab-pgp-menuflags).

  Flag   Description
  ------ ----------------------------------------------------
  R      The key has been revoked and can't be used.
  X      The key is expired and can't be used.
  d      You have marked the key as disabled.
  c      There are unknown critical self-signature packets.

  : PGP key menu flags

The capabilities field ( “%c”) expands to a two-character sequence
representing a key's capabilities. The first character gives the key's
encryption capabilities: A minus sign ( “-”) means that the key cannot
be used for encryption. A dot ( “.”) means that it's marked as a
signature key in one of the user IDs, but may also be used for
encryption. The letter “e” indicates that this key can be used for
encryption.

The second character indicates the key's signing capabilities. Once
again, a “-”implies “not for signing”, “.”implies that the key is marked
as an encryption key in one of the user-ids, and “s” denotes a key which
can be used for signing.

Finally, the validity field ( “%t”) indicates how well-certified a
user-id is. A question mark ( “?”) indicates undefined validity, a minus
character ( “-”) marks an untrusted association, a space character means
a partially trusted association, and a plus character ( “+”) indicates
complete validity.

### Sending Format=Flowed Messages {#ff}

#### Concept {#ff-concept}

`format=flowed`-style messages (or `f=f` for short) are `text/plain`
messages that consist of paragraphs which a receiver's mail client may
reformat to its own needs which mostly means to customize line lengths
regardless of what the sender sent. Technically this is achieved by
letting lines of a “flowable” paragraph end in spaces except for the
last line.

While for text-mode clients like Mutt it's the best way to assume only a
standard 80x25 character cell terminal, it may be desired to let the
receiver decide completely how to view a message.

#### Mutt Support {#ff-support}

Mutt only supports setting the required `format=flowed` MIME parameter
on outgoing messages if the [\$text\_flowed](#text-flowed) variable is
set, specifically it does not add the trailing spaces.

After editing the initial message text and before entering the compose
menu, Mutt properly space-stuffs the message. *Space-stuffing* is
required by RfC3676 defining `format=flowed` and means to prepend a
space to:

-   all lines starting with a space

-   lines starting with the word “`From`”followed by space

-   all lines starting with “`>`”which is not intended to be a quote
    character

> **Note**
>
> Mutt only supports space-stuffing for the first two types of lines but
> not for the third: It is impossible to safely detect whether a leading
> `>`character starts a quote or not. Furthermore, Mutt only applies
> space-stuffing *once* after the initial edit is finished.

All leading spaces are to be removed by receiving clients to restore the
original message prior to further processing.

#### Editor Considerations {#ff-editor}

As Mutt provides no additional features to compose `f=f` messages, it's
completely up to the user and his editor to produce proper messages.
Please consider your editor's documentation if you intend to send `f=f`
messages.

Please note that when editing messages from the compose menu several
times before really sending a mail, it's up to the user to ensure that
the message is properly space-stuffed.

For example, *vim* provides the `w` flag for its `formatoptions` setting
to assist in creating `f=f` messages, see `:help fo-table` for details.

#### Reformatting {#ff-pager}

Mutt has some support for reformatting when viewing and replying to
`format=flowed` messages. In order to take advantage of these,
[\$reflow\_text](#reflow-text) must be set.

-   Paragraphs are automatically reflowed and wrapped at a width
    specified by [\$reflow\_wrap](#reflow-wrap).

-   In its original format, the quoting style of `format=flowed`
    messages can be difficult to read, and doesn't intermix well with
    non-flowed replies. Setting
    [\$reflow\_space\_quotes](#reflow-space-quotes) adds spaces after
    each level of quoting when in the pager and replying in a non-flowed
    format (i.e. with [\$text\_flowed](#text-flowed) unset).

-   If [\$reflow\_space\_quotes](#reflow-space-quotes) is unset, mutt
    will still add one trailing space after all the quotes in the pager
    (but not when replying).

Forwarding and Bouncing Mail {#forwarding-mail}
----------------------------

Bouncing and forwarding let you send an existing message to recipients
that you specify. Bouncing a message sends a verbatim copy of a message
to alternative addresses as if they were the message's original
recipients specified in the Bcc header. Forwarding a message, on the
other hand, allows you to modify the message before it is resent (for
example, by adding your own comments). Bouncing is done using the
`<bounce>`function and forwarding using the `<forward>`function bound to
“b” and “f” respectively.

Forwarding can be done by including the original message in the new
message's body (surrounded by indicating lines) or including it as a
MIME attachment, depending on the value of the
[\$mime\_forward](#mime-forward) variable. Decoding of attachments, like
in the pager, can be controlled by the
[\$forward\_decode](#forward-decode) and
[\$mime\_forward\_decode](#mime-forward-decode) variables, respectively.
The desired forwarding format may depend on the content, therefore
[\$mime\_forward](#mime-forward) is a quadoption which, for example, can
be set to “ask-no”.

The inclusion of headers is controlled by the current setting of the
[\$weed](#weed) variable, unless [\$mime\_forward](#mime-forward) is
set.

By default a forwarded message does not reference the messages it
contains. When [\$forward\_references](#forward-references) is set, a
forwarded message includes the “In-Reply-To:”and “References:”headers,
just like a reply would. Hence the forwarded message becomes part of the
original thread instead of starting a new one.

Editing the message to forward follows the same procedure as sending or
replying to a message does.

Postponing Mail
---------------

At times it is desirable to delay sending a message that you have
already begun to compose. When the `<postpone-message>`function is used
in the *compose* menu, the body of your message and attachments are
stored in the mailbox specified by the [\$postponed](#postponed)
variable. This means that you can recall the message even if you exit
Mutt and then restart it at a later time.

Once a message is postponed, there are several ways to resume it. From
the command line you can use the “-p” option, or if you compose a new
message from the *index* or *pager* you will be prompted if postponed
messages exist. If multiple messages are currently postponed, the
*postponed* menu will pop up and you can select which message you would
like to resume.

> **Note**
>
> If you postpone a reply to a message, the reply setting of the message
> is only updated when you actually finish the message and send it.
> Also, you must be in the same folder with the message you replied to
> for the status of the message to be updated.

See also the [\$postpone](#postpone) quad-option.

Configuration
=============

Location of Initialization Files {#configuration-files}
--------------------------------

When Mutt starts up it looks for two configuration files -- one “system”
file and one “user” file.

Mutt searches for several different file names when looking for config.
It looks for NeoMutt config files before Mutt config files and versioned
config before plain config. For example:

  --------------------
  neomuttrc-20170609
  neomuttrc
  muttrc-1.8.3
  muttrc
  --------------------

  : Mutt config file search order

This allows the user to create separate Mutt and NeoMutt config files on
the same system.

### Location of system config files {#muttrc-system}

Mutt will search for a system config file in a `mutt` directory in
several places. First it searches the locations specified in the
`XDG_CONFIG_DIRS` environment variable, which defaults to `/etc/xdg`.
Next, it looks in `/etc`. Finally, it tries `/usr/share`.

The system config file will not be read if the “-n” option is used on
the [command line](#commandline).

Mutt will read just one file, the first file it finds, from the list
below.

  File Location                        Notes
  ------------------------------------ -----------------------------------------------------
  /etc/xdg/mutt/neomuttrc-20170609     NeoMutt release version
  /etc/xdg/mutt/neomuttrc
  /etc/xdg/mutt/Muttrc-1.8.3           Mutt release version, Note the case of the filename
  /etc/xdg/mutt/Muttrc                 Note the case of the filename
  /etc/mutt/neomuttrc-20170609         NeoMutt release version
  /etc/mutt/neomuttrc
  /etc/mutt/Muttrc-1.8.3               Mutt release version, Note the case of the filename
  /etc/mutt/Muttrc                     Note the case of the filename
  /usr/share/mutt/neomuttrc-20170609   NeoMutt release version
  /usr/share/mutt/neomuttrc
  /usr/share/mutt/Muttrc-1.8.3         Mutt release version, Note the case of the filename
  /usr/share/mutt/Muttrc               Note the case of the filename

  : Mutt system config file locations

### Location of user config files {#muttrc-user}

Mutt will search for a user config file in several places. First it
looks in the directory specified in the `XDG_CONFIG_HOME` environment
variable, which defaults to `~/.config/mutt`. Next, it looks in `~`(your
home directory). Finally, it tries `~/.mutt`.

You may specify your own location for the user config file using the
“-F” option on the [command line](#commandline).

Mutt will read just one file, the first file it finds, from the list
below.

  File Location                        Notes
  ------------------------------------ -------------------------
  \~/.config/mutt/neomuttrc-20170609   NeoMutt release version
  \~/.config/mutt/neomuttrc
  \~/.config/mutt/muttrc-1.8.3         Mutt release version
  \~/.config/mutt/muttrc
  \~/.neomuttrc-20170609               NeoMutt release version
  \~/.neomuttrc
  \~/.muttrc-1.8.3                     Mutt release version
  \~/.muttrc
  \~/.mutt/neomuttrc-20170609          NeoMutt release version
  \~/.mutt/neomuttrc
  \~/.mutt/muttrc-1.8.3                Mutt release version
  \~/.mutt/muttrc

  : Mutt user config file locations

Syntax of Initialization Files {#muttrc-syntax}
------------------------------

An initialization file consists of a series of [commands](#commands).
Each line of the file may contain one or more commands. When multiple
commands are used, they must be separated by a semicolon ( “;”).

    set realname='Mutt user' ; ignore x-

The hash mark, or pound sign ( “\#”), is used as a “comment” character.
You can use it to annotate your initialization file. All text after the
comment character to the end of the line is ignored.

    my_hdr X-Disclaimer: Why are you listening to me?
            # This is a comment

Single quotes ( “'”) and double quotes ( “"”) can be used to quote
strings which contain spaces or other special characters. The difference
between the two types of quotes is similar to that of many popular shell
programs, namely that a single quote is used to specify a literal string
(one that is not interpreted for shell variables or quoting with a
backslash \[see next paragraph\]), while double quotes indicate a string
for which should be evaluated. For example, backticks are evaluated
inside of double quotes, but *not* for single quotes.

“\\”quotes the next character, just as in shells such as bash and zsh.
For example, if want to put quotes “"”inside of a string, you can use
“\\”to force the next character to be a literal instead of interpreted
character.

    set realname="Michael \"MuttDude\" Elkins"

“\\\\”means to insert a literal “\\”into the line. “\\n” and “\\r” have
their usual C meanings of linefeed and carriage-return, respectively.

A “\\”at the end of a line can be used to split commands over multiple
lines as it “escapes” the line end, provided that the split points don't
appear in the middle of command names. Lines are first concatenated
before interpretation so that a multi-line can be commented by
commenting out the first line only.

    set status_format="some very \
    long value split \
    over several lines"

It is also possible to substitute the output of a Unix command in an
initialization file. This is accomplished by enclosing the command in
backticks (\`\`). In [example\_title](#ex-rc-backtick), the output of
the Unix command “uname -a” will be substituted before the line is
parsed. Since initialization files are line oriented, only the first
line of output from the Unix command will be substituted.

    my_hdr X-Operating-System: `uname -a`

Both environment variables and Mutt variables can be accessed by
prepending “\$”to the name of the variable. For example,

    set record=+sent_on_$HOSTNAME

will cause Mutt to save outgoing messages to a folder named
“sent\_on\_kremvax” if the environment variable `$HOSTNAME` is set to
“kremvax.”(See [\$record](#record) for details.)

Mutt expands the variable when it is assigned, not when it is used. If
the value of a variable on the right-hand side of an assignment changes
after the assignment, the variable on the left-hand side will not be
affected.

The commands understood by Mutt are explained in the next paragraphs.
For a complete list, see the [command reference](#commands).

All configuration files are expected to be in the current locale as
specified by the [\$charset](#charset) variable which doesn't have a
default value since it's determined by Mutt at startup. If a
configuration file is not encoded in the same character set the
[\$config\_charset](#config-charset) variable should be used: all lines
starting with the next are recoded from
[\$config\_charset](#config-charset) to [\$charset](#charset).

This mechanism should be avoided if possible as it has the following
implications:

-   These variables should be set early in a configuration file with
    [\$charset](#charset) preceding [\$config\_charset](#config-charset)
    so Mutt knows what character set to convert to.

-   If [\$config\_charset](#config-charset) is set, it should be set in
    each configuration file because the value is global and *not* per
    configuration file.

-   Because Mutt first recodes a line before it attempts to parse it, a
    conversion introducing question marks or other characters as part of
    errors (unconvertable characters, transliteration) may introduce
    syntax errors or silently change the meaning of certain tokens (e.g.
    inserting question marks into regular expressions).

Address Groups {#addrgroup}
--------------

Usage:

group
-group
name
-rx
expr
-addr
expr
ungroup
-group
name
\*
-rx
expr
-addr
expr
Mutt supports grouping addresses logically into named groups. An address
or address pattern can appear in several groups at the same time. These
groups can be used in [patterns](#patterns)(for searching, limiting and
tagging) and in hooks by using group patterns. This can be useful to
classify mail and take certain actions depending on in what groups the
message is. For example, the mutt user's mailing list would fit into the
categories “mailing list” and “mutt-related”. Using
[`send-hook`](#send-hook), the sender can be set to a dedicated one for
writing mailing list messages, and the signature could be set to a
mutt-related one for writing to a mutt list — for other lists, the list
sender setting still applies but a different signature can be selected.
Or, given a group only containing recipients known to accept encrypted
mail, “auto-encryption” can be achieved easily.

The `group` command is used to directly add either addresses or regular
expressions to the specified group or groups. The different categories
of arguments to the `group` command can be in any order. The flags `-rx`
and `-addr` specify what the following strings (that cannot begin with a
hyphen) should be interpreted as: either a regular expression or an
email address, respectively.

These address groups can also be created implicitly by the
[`alias`](#alias), [`lists`](#lists), [`subscribe`](#lists)and
[`alternates`](#alternates)commands by specifying the optional `-group`
option. For example,

    alternates -group me address1 address2
    alternates -group me -group work address3

would create a group named “me” which contains all your addresses and a
group named “work” which contains only your work address *address3*.
Besides many other possibilities, this could be used to automatically
mark your own messages in a mailing list folder as read or use a special
signature for work-related messages.

The `ungroup` command is used to remove addresses or regular expressions
from the specified group or groups. The syntax is similar to the `group`
command, however the special character `*`can be used to empty a group
of all of its contents. As soon as a group gets empty because all
addresses and regular expressions have been removed, it'll internally be
removed, too (i.e. there cannot be an empty group). When removing
regular expressions from a group, the pattern must be specified exactly
as given to the `group` command or `-group` argument.

Defining/Using Aliases {#alias}
----------------------

Usage:

alias
-group
name
key
address
address
unalias
-group
name
\*
key
It's usually very cumbersome to remember or type out the address of
someone you are communicating with. Mutt allows you to create “aliases”
which map a short string to a full address.

> **Note**
>
> If you want to create an alias for more than one address, you *must*
> separate the addresses with a comma ( “,”).

The optional `-group` argument to `alias` causes the aliased address(es)
to be added to the named *group*.

To remove an alias or aliases ( “\*”means all aliases):

    alias muttdude me@cs.hmc.edu (Michael Elkins)
    alias theguys manny, moe, jack

Unlike other mailers, Mutt doesn't require aliases to be defined in a
special file. The `alias` command can appear anywhere in a configuration
file, as long as this file is [`source`d](#source). Consequently, you
can have multiple alias files, or you can have all aliases defined in
your `.muttrc`.

On the other hand, the [`<create-alias>`](#create-alias)function can use
only one file, the one pointed to by the [\$alias\_file](#alias-file)
variable (which is `~/.muttrc` by default). This file is not special
either, in the sense that Mutt will happily append aliases to any file,
but in order for the new aliases to take effect you need to explicitly
[`source`](#source)this file too.

    source /usr/local/share/Mutt.aliases
    source ~/.mail_aliases
    set alias_file=~/.mail_aliases

To use aliases, you merely use the alias at any place in Mutt where Mutt
prompts for addresses, such as the *To:*or *Cc:*prompt. You can also
enter aliases in your editor at the appropriate headers if you have the
[\$edit\_headers](#edit-headers) variable set.

In addition, at the various address prompts, you can use the tab
character to expand a partial alias to the full alias. If there are
multiple matches, Mutt will bring up a menu with the matching aliases.
In order to be presented with the full list of aliases, you must hit tab
without a partial alias, such as at the beginning of the prompt or after
a comma denoting multiple addresses.

In the alias menu, you can select as many aliases as you want with the
`select-entry` key (default: &lt;Return&gt;), and use the *exit* key
(default: q) to return to the address prompt.

Changing the Default Key Bindings {#bind}
---------------------------------

Usage:

bind
map
key
function
This command allows you to change the default key bindings (operation
invoked when pressing a key).

*map* specifies in which menu the binding belongs. Multiple maps may be
specified by separating them with commas (no additional whitespace is
allowed). The currently defined maps are:

generic

:   This is not a real menu, but is used as a fallback for all of the
    other menus except for the pager and editor modes. If a key is not
    defined in another menu, Mutt will look for a binding to use in
    this menu. This allows you to bind a key to a certain function in
    multiple menus instead of having multiple `bind` statements to
    accomplish the same task.

alias

:   The alias menu is the list of your personal aliases as defined in
    your `.muttrc`. It is the mapping from a short alias name to the
    full email address(es) of the recipient(s).

attach

:   The attachment menu is used to access the attachments on
    received messages.

browser

:   The browser is used for both browsing the local directory structure,
    and for listing all of your incoming mailboxes.

editor

:   The editor is used to allow the user to enter a single line of text,
    such as the *To* or *Subject* prompts in the `compose` menu.

index

:   The index is the list of messages contained in a mailbox.

compose

:   The compose menu is the screen used when sending a new message.

pager

:   The pager is the mode used to display message/attachment data, and
    help listings.

pgp

:   The pgp menu is used to select the OpenPGP keys used to encrypt
    outgoing messages.

smime

:   The smime menu is used to select the OpenSSL certificates used to
    encrypt outgoing messages.

postpone

:   The postpone menu is similar to the index menu, except is used when
    recalling a message the user was composing, but saved until later.

query

:   The query menu is the browser for results returned by
    [\$query\_command](#query-command).

mix

:   The mixmaster screen is used to select remailer options for outgoing
    messages (if Mutt is compiled with Mixmaster support).

*key* is the key (or key sequence) you wish to bind. To specify a
control character, use the sequence *\\Cx*, where *x* is the letter of
the control character (for example, to specify control-A use “\\Ca”).
Note that the case of *x* as well as *\\C* is ignored, so that *\\CA*,
*\\Ca*, *\\cA* and *\\ca* are all equivalent. An alternative form is to
specify the key as a three digit octal number prefixed with a “\\”(for
example *\\177* is equivalent to *\\c?*). In addition, *key* may be a
symbolic name as shown in [table\_title](#tab-key-names).

  Symbolic name       Meaning
  ------------------- ---------------------
  \\t                 tab
  &lt;tab&gt;         tab
  &lt;backtab&gt;     backtab / shift-tab
  \\r                 carriage return
  \\n                 newline
  \\e                 escape/alt
  &lt;esc&gt;         escape/alt
  &lt;up&gt;          up arrow
  &lt;down&gt;        down arrow
  &lt;left&gt;        left arrow
  &lt;right&gt;       right arrow
  &lt;pageup&gt;      Page Up
  &lt;pagedown&gt;    Page Down
  &lt;backspace&gt;   Backspace
  &lt;delete&gt;      Delete
  &lt;insert&gt;      Insert
  &lt;enter&gt;       Enter
  &lt;return&gt;      Return
  &lt;home&gt;        Home
  &lt;end&gt;         End
  &lt;space&gt;       Space bar
  &lt;f1&gt;          function key 1
  &lt;f10&gt;         function key 10

  : Symbolic key names

The `<what-key>`function can be used to explore keycode and symbolic
names for other keys on your keyboard. Executing this function will
display information about each key pressed, until terminated by `^G`.

*key* does not need to be enclosed in quotes unless it contains a space
( “ ”) or semi-colon ( “;”).

*function* specifies which action to take when *key* is pressed. For a
complete list of functions, see the [reference](#functions). Note that
the `bind` expects *function* to be specified without angle brackets.

The special function `<noop>`unbinds the specified key sequence.

### Warnings about Duplicated Bindings {#bind-warnings}

Due to a limitation of Mutt, creating key bindings, or macros, will
overwrite existing mappings with similar, shorter, names.

    bind index g  group-reply
    bind index gg first-entry

In this example, the `g` binding will be overwritten and cannot be used.
Newer versions of Mutt will warn the user about this.

To avoid warnings on startup, first set the shorter binding to `noop`
(no operation).

    bind index g  noop
    bind index gg first-entry

Defining Aliases for Character Sets {#charset-hook}
-----------------------------------

Usage:

charset-hook
alias
charset
iconv-hook
charset
local-charset
The `charset-hook` command defines an alias for a character set. This is
useful to properly display messages which are tagged with a character
set name not known to Mutt.

The `iconv-hook` command defines a system-specific name for a character
set. This is helpful when your systems character conversion library
insists on using strange, system-specific names for character sets.

Setting Variables Based Upon Mailbox {#folder-hook}
------------------------------------

Usage:

folder-hook
\[!\]regexp
command
It is often desirable to change settings based on which mailbox you are
reading. The `folder-hook` command provides a method by which you can
execute any configuration command. *regexp* is a regular expression
specifying in which mailboxes to execute *command* before loading. If a
mailbox matches multiple `folder-hook`s, they are executed in the order
given in the `.muttrc`.

The regexp parameter has [mailbox shortcut](#shortcuts) expansion
performed on the first character. See
[Mailbox Matching in Hooks](#mailbox-hook)for more details.

> **Note**
>
> If you use the “!”shortcut for [\$spoolfile](#spoolfile) at the
> beginning of the pattern, you must place it inside of double or single
> quotes in order to distinguish it from the logical *not* operator for
> the expression.

> **Note**
>
> Settings are *not* restored when you leave the mailbox. For example, a
> command action to perform is to change the sorting method based upon
> the mailbox being read:
>
>     folder-hook mutt "set sort=threads"
>
> However, the sorting method is not restored to its previous value when
> reading a different mailbox. To specify a *default* command, use the
> pattern “.”before other `folder-hook`s adjusting a value on a
> per-folder basis because `folder-hook`s are evaluated in the order
> given in the configuration file.

> **Note**
>
> The keyboard buffer will not be processed until after all hooks are
> run; multiple [push](#push) or [exec](#exec) commands will end up
> being processed in reverse order.

The following example will set the [sort](#sort) variable to `date-sent`
for all folders but to `threads` for all folders containing “mutt” in
their name.

    folder-hook . "set sort=date-sent"
    folder-hook mutt "set sort=threads"

Keyboard Macros {#macro}
---------------

Usage:

macro
menu
key
sequence
description
Macros are useful when you would like a single key to perform a series
of actions. When you press *key* in menu *menu*, Mutt will behave as if
you had typed *sequence*. So if you have a common sequence of commands
you type, you can create a macro to execute those commands with a single
key or fewer keys.

*menu* is the [map](#maps) which the macro will be bound in. Multiple
maps may be specified by separating multiple menu arguments by commas.
Whitespace may not be used in between the menu arguments and the commas
separating them.

*key* and *sequence* are expanded by the same rules as the [key
bindings](#bind) with some additions. The first is that control
characters in *sequence* can also be specified as *\^x*. In order to get
a caret ( “\^”) you need to use *\^\^*. Secondly, to specify a certain
key such as *up* or to invoke a function directly, you can use the
format *&lt;key name&gt;*and *&lt;function name&gt;*. For a listing of
key names see the section on [key bindings](#bind). Functions are listed
in the [reference](#functions).

The advantage with using function names directly is that the macros will
work regardless of the current key bindings, so they are not dependent
on the user having particular key definitions. This makes them more
robust and portable, and also facilitates defining of macros in files
used by more than one user (e.g., the system Muttrc).

Optionally you can specify a descriptive text after *sequence*, which is
shown in the help screens if they contain a description.

> **Note**
>
> Macro definitions (if any) listed in the help screen(s), are silently
> truncated at the screen width, and are not wrapped.

Using Color and Mono Video Attributes {#color}
-------------------------------------

Usage:

color
object
foreground
background
color
header
body
foreground
background
regexp
color
index-object
foreground
background
pattern
color
compose
composeobject
foreground
background
uncolor
index-object
header
body
\*
pattern
If your terminal supports color, you can spice up Mutt by creating your
own color scheme. To define the color of an object (type of
information), you must specify both a foreground color *and* a
background color (it is not possible to only specify one or the other).

*header* and *body* match *regexp* in the header/body of a message,
*index-object* can match *pattern*(see
[Patterns: Searching, Limiting and Tagging](#patterns)) in the message
index. Note that IMAP server-side searches (=b, =B, =h) are not
supported for color index patterns.

When [\$header\_color\_partial](#header-color-partial) is unset (the
default), a *header* matched by *regexp* will have color applied to the
entire header. When set, color is applied only to the exact text matched
by *regexp*.

*object* can be one of:

-   attachment

-   bold (highlighting bold patterns in the body of messages)

-   error (error messages printed by Mutt)

-   hdrdefault (default color of the message header in the pager)

-   index\_author (color of the author name in the index, uses
    *pattern*)

-   index\_collapsed (the number of messages in a collapsed thread in
    the index)

-   index\_date (color of the date field in the index)

-   index\_flags (color of the message flags in the index)

-   index\_label (color of the message label in the index)

-   index\_number (color of the message number in the index)

-   index\_size (color of the message size and line number in the index)

-   index\_subject (color of the subject in the index, uses *pattern*)

-   indicator (arrow or bar used to indicate the current item in a menu)

-   markers (the “+”markers at the beginning of wrapped lines in
    the pager)

-   message (informational messages)

-   normal

-   [progress](#progress)(visual progress bar)

-   prompt

-   quoted (text matching [\$quote\_regexp](#quote-regexp) in the body
    of a message)

-   quoted1, quoted2, ..., quoted *N*(higher levels of quoting)

-   search (highlighting of words in the pager)

-   signature

-   status (mode lines used to display info about the mailbox
    or message)

-   tilde (the “\~”used to pad blank lines in the pager)

-   tree (thread tree drawn in the message index and attachment menu)

-   underline (highlighting underlined patterns in the body of messages)

*composeobject* can be one of:

-   header

-   security\_encrypt

-   security\_sign

-   security\_both

-   security\_none

*index-object* can be one of the following:

-   index (default highlighting of the entire index line, uses
    *pattern*)

-   index\_date (the date field)

-   index\_flags (the message flags, %S %Z, uses *pattern*)

-   index\_number (the message number, %C)

-   index\_collapsed (the number of messages in a collapsed thread, %M)

-   index\_author (the author name, %A %a %F %L %n, uses *pattern*)

-   index\_subject (the subject, %s, uses *pattern*)

-   index\_size (the message size, %c %l)

-   index\_label (the message label, %y %Y)

-   index\_tags (the transformed message tags, %g)

-   index\_tag (an individual message tag, %G, uses *pattern / tag
    name*)

*foreground* and *background* can be one of the following:

-   white

-   black

-   green

-   magenta

-   blue

-   cyan

-   yellow

-   red

-   default

-   color *x*

*foreground* can optionally be prefixed with the keyword `bright` to
make the foreground color boldfaced (e.g., `brightred`).

If your terminal supports it, the special keyword *default* can be used
as a transparent color. The value *brightdefault* is also valid. If Mutt
is linked against the *S-Lang* library, you also need to set the
`$COLORFGBG` environment variable to the default colors of your terminal
for this to work; for example (for Bourne-like shells):

    set COLORFGBG="green;black"
    export COLORFGBG

> **Note**
>
> The *S-Lang* library requires you to use the *lightgray* and *brown*
> keywords instead of *white* and *yellow* when setting this variable.

> **Note**
>
> The `uncolor` command can be applied to the index, header and body
> objects only. It removes entries from the list. You *must* specify the
> same pattern specified in the `color` command for it to be removed.
> The pattern “\*”is a special token which means to clear the color list
> of all entries.

Mutt also recognizes the keywords *color0*, *color1*, ..., *color*
*N-1*( *N* being the number of colors supported by your terminal). This
is useful when you remap the colors for your display (for example by
changing the color associated with *color2* for your xterm), since color
names may then lose their normal meaning.

If your terminal does not support color, it is still possible change the
video attributes through the use of the “mono” command. Usage:

mono
object
attribute
mono
header
body
attribute
regexp
mono
index
attribute
pattern
unmono
index-object
header
body
\*
pattern
For *object*, see the `color` command. *attribute* can be one of the
following:

-   none

-   bold

-   underline

-   reverse

-   standout

Message Header Display {#msg-hdr-display}
----------------------

### Header Display {#hdr-folding}

When displaying a message in the pager, Mutt folds long header lines at
[\$wrap](#wrap) columns. Though there're precise rules about where to
break and how, Mutt always folds headers using a tab for readability.
(Note that the sending side is not affected by this, Mutt tries to
implement standards compliant folding.)

### Selecting Headers {#ignore}

Usage:

ignore
pattern
pattern
unignore
\*
pattern
Messages often have many header fields added by automatic processing
systems, or which may not seem useful to display on the screen. This
command allows you to specify header fields which you don't normally
want to see in the pager.

You do not need to specify the full header field name. For example,
“ignore content-”will ignore all header fields that begin with the
pattern “content-”. “ignore \*”will ignore all headers.

To remove a previously added token from the list, use the “unignore”
command. The “unignore” command will make Mutt display headers with the
given pattern. For example, if you do “ignore x-”it is possible to
“unignore x-mailer”.

“unignore \*”will remove all tokens from the ignore list.

    # Sven's draconian header weeding
    ignore *
    unignore from date subject to cc
    unignore organization organisation x-mailer: x-newsreader: x-mailing-list:
    unignore posted-to:

### Ordering Displayed Headers {#hdr-order}

Usage:

hdr\_order
header
header
unhdr\_order
\*
header
With the `hdr_order` command you can specify an order in which Mutt will
attempt to present these headers to you when viewing messages.

“`unhdr_order`\*”will clear all previous headers from the order list,
thus removing the header order effects set by the system-wide startup
file.

    hdr_order From Date: From: To: Cc: Subject:

Alternative Addresses {#alternates}
---------------------

Usage:

alternates
-group
name
regexp
regexp
unalternates
-group
name
\*
regexp
With various functions, Mutt will treat messages differently, depending
on whether you sent them or whether you received them from someone else.
For instance, when replying to a message that you sent to a different
party, Mutt will automatically suggest to send the response to the
original message's recipients — responding to yourself won't make much
sense in many cases. (See [\$reply\_to](#reply-to).)

Many users receive e-mail under a number of different addresses. To
fully use Mutt's features here, the program must be able to recognize
what e-mail addresses you receive mail under. That's the purpose of the
`alternates` command: It takes a list of regular expressions, each of
which can identify an address under which you receive e-mail.

As addresses are matched using regular expressions and not exact strict
comparisons, you should make sure you specify your addresses as precise
as possible to avoid mismatches. For example, if you specify:

    alternates user@example

Mutt will consider “`some-user@example`”as being your address, too which
may not be desired. As a solution, in such cases addresses should be
specified as:

    alternates '^user@example$'

The `-group` flag causes all of the subsequent regular expressions to be
added to the named group.

The `unalternates` command can be used to write exceptions to
`alternates` patterns. If an address matches something in an
`alternates` command, but you nonetheless do not think it is from you,
you can list a more precise pattern under an `unalternates` command.

To remove a regular expression from the `alternates` list, use the
`unalternates` command with exactly the same *regexp*. Likewise, if the
*regexp* for an `alternates` command matches an entry on the
`unalternates` list, that `unalternates` entry will be removed. If the
*regexp* for `unalternates` is “\*”, *all entries* on `alternates` will
be removed.

Mailing Lists {#lists}
-------------

Usage:

lists
-group
name
regexp
regexp
unlists
\*
regexp
subscribe
-group
name
regexp
regexp
unsubscribe
\*
regexp
Mutt has a few nice features for [handling mailing lists](#using-lists).
In order to take advantage of them, you must specify which addresses
belong to mailing lists, and which mailing lists you are subscribed to.
Mutt also has limited support for auto-detecting mailing lists: it
supports parsing `mailto:`links in the common `List-Post:`header which
has the same effect as specifying the list address via the `lists`
command (except the group feature). Once you have done this, the
[`<list-reply>`](#list-reply)function will work for all known lists.
Additionally, when you send a message to a subscribed list, Mutt will
add a Mail-Followup-To header to tell other users' mail user agents not
to send copies of replies to your personal address.

> **Note**
>
> The Mail-Followup-To header is a non-standard extension which is not
> supported by all mail user agents. Adding it is not bullet-proof
> against receiving personal CCs of list messages. Also note that the
> generation of the Mail-Followup-To header is controlled by the
> [\$followup\_to](#followup-to) configuration variable since it's
> common practice on some mailing lists to send Cc upon replies (which
> is more a group- than a list-reply).

More precisely, Mutt maintains lists of patterns for the addresses of
known and subscribed mailing lists. Every subscribed mailing list is
known. To mark a mailing list as known, use the `list` command. To mark
it as subscribed, use `subscribe`.

You can use regular expressions with both commands. To mark all messages
sent to a specific bug report's address on Debian's bug tracking system
as list mail, for instance, you could say

    subscribe [0-9]+.*@bugs.debian.org

as it's often sufficient to just give a portion of the list's e-mail
address.

Specify as much of the address as you need to to remove ambiguity. For
example, if you've subscribed to the Mutt mailing list, you will receive
mail addressed to `mutt-users@mutt.org`. So, to tell Mutt that this is a
mailing list, you could add `lists mutt-users@`to your initialization
file. To tell Mutt that you are subscribed to it, add `
      subscribe mutt-users` to your initialization file instead. If you
also happen to get mail from someone whose address is
`mutt-users@example.com`, you could use `
      lists^mutt-users@mutt\\.org$`or `
      subscribe^mutt-users@mutt\\.org$`to match only mail from the
actual list.

The `-group` flag adds all of the subsequent regular expressions to the
named [address group](#addrgroup) in addition to adding to the specified
address list.

The “unlists” command is used to remove a token from the list of known
and subscribed mailing-lists. Use “unlists \*”to remove all tokens.

To remove a mailing list from the list of subscribed mailing lists, but
keep it on the list of known mailing lists, use `unsubscribe`.

Using Multiple Spool Mailboxes {#mbox-hook}
------------------------------

Usage:

mbox-hook
\[!\]regexp
mailbox
This command is used to move read messages from a specified mailbox to a
different mailbox automatically when you quit or change folders.
*regexp* is a regular expression specifying the mailbox to treat as a
“spool” mailbox and *mailbox* specifies where mail should be saved when
read.

The regexp parameter has [mailbox shortcut](#shortcuts) expansion
performed on the first character. See
[Mailbox Matching in Hooks](#mailbox-hook)for more details.

Note that execution of mbox-hooks is dependent on the [\$move](#move)
configuration variable. If set to “no”(the default), mbox-hooks will not
be executed.

Unlike some of the other *hook* commands, only the *first* matching
regexp is used (it is not possible to save read mail in more than a
single mailbox).

Monitoring Incoming Mail {#mailboxes}
------------------------

Usage:

mailboxes
mailbox
mailbox
unmailboxes
\*
mailbox
This command specifies folders which can receive mail and which will be
checked for new messages periodically.

*folder* can either be a local file or directory (Mbox/Mmdf or
Maildir/Mh). If Mutt was built with POP and/or IMAP support, *folder*
can also be a POP/IMAP folder URL. The URL syntax is described in
[URL Syntax](#url-syntax), POP and IMAP are described in
[POP3 Support](#pop)and [IMAP Support](#imap)respectively.

Mutt provides a number of advanced features for handling (possibly many)
folders and new mail within them, please refer to
[New Mail Detection](#new-mail)for details (including in what situations
and how often Mutt checks for new mail).

The “unmailboxes” command is used to remove a token from the list of
folders which receive mail. Use “unmailboxes \*”to remove all tokens.

> **Note**
>
> The folders in the `mailboxes` command are resolved when the command
> is executed, so if these names contain [shortcut
> characters](#shortcuts)(such as “=”and “!”), any variable definition
> that affects these characters (like [\$folder](#folder) and
> [\$spoolfile](#spoolfile)) should be set before the `mailboxes`
> command. If none of these shortcuts are used, a local path should be
> absolute as otherwise Mutt tries to find it relative to the directory
> from where Mutt was started which may not always be desired.

User-Defined Headers {#my-hdr}
--------------------

Usage:

my\_hdr
string
unmy\_hdr
\*
field
The `my_hdr` command allows you to create your own header fields which
will be added to every message you send and appear in the editor if
[\$edit\_headers](#edit-headers) is set.

For example, if you would like to add an “Organization:”header field to
all of your outgoing messages, you can put the command something like
shown in [example\_title](#ex-my-hdr)in your `.muttrc`.

    my_hdr Organization: A Really Big Company, Anytown, USA

> **Note**
>
> Space characters are *not* allowed between the keyword and the colon (
> “:”). The standard for electronic mail (RFC2822) says that space is
> illegal there, so Mutt enforces the rule.

If you would like to add a header field to a single message, you should
either set the [\$edit\_headers](#edit-headers) variable, or use the
`<edit-headers>`function (default: “E”) in the compose menu so that you
can edit the header of your message along with the body.

To remove user defined header fields, use the `unmy_hdr` command. You
may specify an asterisk ( “\*”) to remove all header fields, or the
fields to remove. For example, to remove all “To” and “Cc” header
fields, you could use:

    unmy_hdr to cc

Specify Default Save Mailbox {#save-hook}
----------------------------

Usage:

save-hook
\[!\]pattern
mailbox
This command is used to override the default mailbox used when saving
messages. *mailbox* will be used as the default if the message matches
*pattern*, see [Message Matching in Hooks](#pattern-hook)for information
on the exact format.

To provide more flexibility and good defaults, Mutt applies the expandos
of [\$index\_format](#index-format) to *mailbox* after it was expanded.

    # default: save all to ~/Mail/<author name>
    save-hook . ~/Mail/%F
    # save from me@turing.cs.hmc.edu and me@cs.hmc.edu to $folder/elkins
    save-hook me@(turing\\.)?cs\\.hmc\\.edu$ +elkins
    # save from aol.com to $folder/spam
    save-hook aol\\.com$ +spam

Also see the [`fcc-save-hook`](#fcc-save-hook)command.

Specify Default Fcc: Mailbox When Composing {#fcc-hook}
-------------------------------------------

Usage:

fcc-hook
\[!\]pattern
mailbox
This command is used to save outgoing mail in a mailbox other than
[\$record](#record). Mutt searches the initial list of message
recipients for the first matching *pattern* and uses *mailbox* as the
default Fcc: mailbox. If no match is found the message will be saved to
[\$record](#record) mailbox.

To provide more flexibility and good defaults, Mutt applies the expandos
of [\$index\_format](#index-format) to *mailbox* after it was expanded.

See [Message Matching in Hooks](#pattern-hook)for information on the
exact format of *pattern*.

    fcc-hook [@.]aol\\.com$ +spammers

...will save a copy of all messages going to the aol.com domain to the
\`+spammers' mailbox by default. Also see the
[`fcc-save-hook`](#fcc-save-hook)command.

Specify Default Save Filename and Default Fcc: Mailbox at Once {#fcc-save-hook}
--------------------------------------------------------------

Usage:

fcc-save-hook
\[!\]pattern
mailbox
This command is a shortcut, equivalent to doing both a
[`fcc-hook`](#fcc-hook)and a [`save-hook`](#save-hook)with its
arguments, including %-expansion on *mailbox* according to
[\$index\_format](#index-format).

Change Settings Based Upon Message Recipients {#send-hook}
---------------------------------------------

Usage:

reply-hook
\[!\]pattern
command
send-hook
\[!\]pattern
command
send2-hook
\[!\]pattern
command
These commands can be used to execute arbitrary configuration commands
based upon recipients of the message. *pattern* is used to match the
message, see [Message Matching in Hooks](#pattern-hook)for details.
*command* is executed when *pattern* matches.

`reply-hook` is matched against the message you are *replying to*,
instead of the message you are *sending*. `send-hook` is matched against
all messages, both *new* and *replies*.

> **Note**
>
> `reply-hook`s are matched *before* the `send-hook`, *regardless* of
> the order specified in the user's configuration file. However, you can
> inhibit `send-hook` in the reply case by using the pattern `'! ~Q'`(
> *not replied*, see [Message Matching in Hooks](#pattern-hook)) in the
> `send-hook` to tell when `reply-hook` have been executed.

`send2-hook` is matched every time a message is changed, either by
editing it, or by using the compose menu to change its recipients or
subject. `send2-hook` is executed after `send-hook`, and can, e.g., be
used to set parameters such as the [\$sendmail](#sendmail) variable
depending on the message's sender address.

For each type of `send-hook` or `reply-hook`, when multiple matches
occur, commands are executed in the order they are specified in the
`.muttrc`(for that type of hook).

Example: `
      send-hook mutt "
      set mime_forward signature=''"`

Another typical use for this command is to change the values of the
[\$attribution](#attribution),
[\$attribution\_locale](#attribution-locale), and
[\$signature](#signature) variables in order to change the language of
the attributions and signatures based upon the recipients.

> **Note**
>
> `send-hook`'s are only executed once after getting the initial list of
> recipients. Adding a recipient after replying or editing the message
> will not cause any `send-hook` to be executed, similarly if
> [\$autoedit](#autoedit) is set (as then the initial list of recipients
> is empty). Also note that [`my_hdr`](#my-hdr)commands which modify
> recipient headers, or the message's subject, don't have any effect on
> the current message when executed from a `send-hook`.

Change Settings Before Formatting a Message {#message-hook}
-------------------------------------------

Usage:

message-hook
\[!\]pattern
command
This command can be used to execute arbitrary configuration commands
before viewing or formatting a message based upon information about the
message. *command* is executed if the *pattern* matches the message to
be displayed. When multiple matches occur, commands are executed in the
order they are specified in the `.muttrc`.

See [Message Matching in Hooks](#pattern-hook)for information on the
exact format of *pattern*.

Example:

    message-hook ~A 'set pager=builtin'
    message-hook '~f freshmeat-news' 'set pager="less \"+/^  subject: .*\""'

Choosing the Cryptographic Key of the Recipient {#crypt-hook}
-----------------------------------------------

Usage:

crypt-hook
regexp
keyid
When encrypting messages with PGP/GnuPG or OpenSSL, you may want to
associate a certain key with a given e-mail address automatically,
either because the recipient's public key can't be deduced from the
destination address, or because, for some reasons, you need to override
the key Mutt would normally use. The `crypt-hook` command provides a
method by which you can specify the ID of the public key to be used when
encrypting messages to a certain recipient. You may use multiple
crypt-hooks with the same regexp; multiple matching crypt-hooks result
in the use of multiple keyids for a recipient. During key selection,
Mutt will confirm whether each crypt-hook is to be used (unless the
[\$crypt\_confirmhook](#crypt-confirmhook) option is unset). If all
crypt-hooks for a recipient are declined, Mutt will use the original
recipient address for key selection instead.

The meaning of *keyid* is to be taken broadly in this context: You can
either put a numerical key ID or fingerprint here, an e-mail address, or
even just a real name.

Adding Key Sequences to the Keyboard Buffer {#push}
-------------------------------------------

Usage:

push
string
This command adds the named string to the beginning of the keyboard
buffer. The string may contain control characters, key names and
function names like the sequence string in the [macro](#macro) command.
You may use it to automatically run a sequence of commands at startup,
or when entering certain folders. For example,
[example\_title](#ex-folder-hook-push)shows how to automatically
collapse all threads when entering a folder.

    folder-hook . 'push <collapse-all>'

For using functions like shown in the example, it's important to use
angle brackets ( “&lt;”and “&gt;”) to make Mutt recognize the input as a
function name. Otherwise it will simulate individual just keystrokes,
i.e. “`push collapse-all`”would be interpreted as if you had typed “c”,
followed by “o”, followed by “l”, ..., which is not desired and may lead
to very unexpected behavior.

Keystrokes can be used, too, but are less portable because of
potentially changed key bindings. With default bindings, this is
equivalent to the above example:

    folder-hook . 'push \eV'

because it simulates that Esc+V was pressed (which is the default
binding of `<collapse-all>`).

Executing Functions {#exec}
-------------------

Usage:

exec
function
function
This command can be used to execute any function. Functions are listed
in the [function reference](#functions). “`exec` `function`”is
equivalent to “`push <function>`”.

Message Scoring {#score-command}
---------------

Usage:

score
pattern
value
unscore
\*
pattern
The `score` commands adds *value* to a message's score if *pattern*
matches it. *pattern* is a string in the format described in the
[patterns](#patterns) section (note: For efficiency reasons, patterns
which scan information not available in the index, such as `~b`, `~B`,
`~h`, or `~X` may not be used). *value* is a positive or negative
integer. A message's final score is the sum total of all matching
`score` entries. However, you may optionally prefix *value* with an
equal sign ( “=”) to cause evaluation to stop at a particular entry if
there is a match. Negative final scores are rounded up to 0.

The `unscore` command removes score entries from the list. You *must*
specify the same pattern specified in the `score` command for it to be
removed. The pattern “\*”is a special token which means to clear the
list of all score entries.

Scoring occurs as the messages are read in, before the mailbox is
sorted. Because of this, patterns which depend on threading, such as
*\~=*, *\~\$*, and *\~()*, will not work by default. A workaround is to
push the scoring command in a folder hook. This will cause the mailbox
to be rescored after it is opened and input starts being processed:

    folder-hook . 'push "<enter-command>score ~= 10<enter>"'

Spam Detection {#spam}
--------------

Usage:

spam
pattern
format
nospam
\*
pattern
Mutt has generalized support for external spam-scoring filters. By
defining your spam patterns with the `spam` and `nospam` commands, you
can *limit*, *search*, and *sort* your mail based on its spam
attributes, as determined by the external filter. You also can display
the spam attributes in your index display using the `%H` selector in the
[\$index\_format](#index-format) variable. (Tip: try `%?H?[%H] ?`to
display spam tags only when they are defined for a given message.)

Your first step is to define your external filter's spam patterns using
the `spam` command. *pattern* should be a regular expression that
matches a header in a mail message. If any message in the mailbox
matches this regular expression, it will receive a “spam tag” or “spam
attribute”(unless it also matches a `nospam` pattern — see below.) The
appearance of this attribute is entirely up to you, and is governed by
the *format* parameter. *format* can be any static text, but it also can
include back-references from the *pattern* expression. (A regular
expression “back-reference” refers to a sub-expression contained within
parentheses.) `%1` is replaced with the first back-reference in the
regex, `%2` with the second, etc.

To match spam tags, mutt needs the corresponding header information
which is always the case for local and POP folders but not for IMAP in
the default configuration. Depending on the spam header to be analyzed,
[\$imap\_headers](#imap-headers) may need to be adjusted.

If you're using multiple spam filters, a message can have more than one
spam-related header. You can define `spam` patterns for each filter you
use. If a message matches two or more of these patterns, and the
[\$spam\_separator](#spam-separator) variable is set to a string, then
the message's spam tag will consist of all the *format* strings joined
together, with the value of [\$spam\_separator](#spam-separator)
separating them.

For example, suppose one uses DCC, SpamAssassin, and PureMessage, then
the configuration might look like in [example\_title](#ex-spam).

    spam "X-DCC-.*-Metrics:.*(....)=many"         "90+/DCC-%1"
    spam "X-Spam-Status: Yes"                     "90+/SA"
    spam "X-PerlMX-Spam: .*Probability=([0-9]+)%" "%1/PM"
    set spam_separator=", "

If then a message is received that DCC registered with “many” hits under
the “Fuz2” checksum, and that PureMessage registered with a 97%
probability of being spam, that message's spam tag would read
`90+/DCC-Fuz2, 97/PM`. (The four characters before “=many” in a DCC
report indicate the checksum used — in this case, “Fuz2”.)

If the [\$spam\_separator](#spam-separator) variable is unset, then each
spam pattern match supersedes the previous one. Instead of getting
joined *format* strings, you'll get only the last one to match.

The spam tag is what will be displayed in the index when you use `%H` in
the [\$index\_format](#index-format) variable. It's also the string that
the `~H` pattern-matching expression matches against for `<search>`and
`<limit>`functions. And it's what sorting by spam attribute will use as
a sort key.

That's a pretty complicated example, and most people's actual
environments will have only one spam filter. The simpler your
configuration, the more effective Mutt can be, especially when it comes
to sorting.

Generally, when you sort by spam tag, Mutt will sort *lexically*— that
is, by ordering strings alphanumerically. However, if a spam tag begins
with a number, Mutt will sort numerically first, and lexically only when
two numbers are equal in value. (This is like UNIX's `sort -n`.) A
message with no spam attributes at all — that is, one that didn't match
*any* of your `spam` patterns — is sorted at lowest priority. Numbers
are sorted next, beginning with 0 and ranging upward. Finally,
non-numeric strings are sorted, with “a” taking lower priority than “z”.
Clearly, in general, sorting by spam tags is most effective when you can
coerce your filter to give you a raw number. But in case you can't, Mutt
can still do something useful.

The `nospam` command can be used to write exceptions to `spam` patterns.
If a header pattern matches something in a `spam` command, but you
nonetheless do not want it to receive a spam tag, you can list a more
precise pattern under a `nospam` command.

If the *pattern* given to `nospam` is exactly the same as the *pattern*
on an existing `spam` list entry, the effect will be to remove the entry
from the spam list, instead of adding an exception. Likewise, if the
*pattern* for a `spam` command matches an entry on the `nospam` list,
that nospam entry will be removed. If the *pattern* for `nospam` is
“\*”, *all entries on both lists* will be removed. This might be the
default action if you use `spam` and `nospam` in conjunction with a
`folder-hook`.

You can have as many `spam` or `nospam` commands as you like. You can
even do your own primitive `spam` detection within Mutt — for example,
if you consider all mail from `MAILER-DAEMON` to be spam, you can use a
`spam` command like this:

    spam "^From: .*MAILER-DAEMON"       "999"

Setting and Querying Variables {#set}
------------------------------

### Variable Types {#var-types}

Mutt supports these types of configuration variables:

boolean

:   A boolean expression, either “yes” or “no”.

number

:   A signed integer number in the range -32768 to 32767.

string

:   Arbitrary text.

path

:   A specialized string for representing paths including support for
    mailbox shortcuts (see [Mailbox Shortcuts](#shortcuts)) as well as
    tilde ( “\~”) for a user's home directory and more.

quadoption

:   Like a boolean but triggers a prompt when set to “ask-yes” or
    “ask-no” with “yes” and “no” preselected respectively.

sort order

:   A specialized string allowing only particular words as values
    depending on the variable.

regular expression

:   A regular expression, see [Regular Expressions](#regexp)for
    an introduction.

folder magic

:   Specifies the type of folder to use: *mbox*, *mmdf*, *mh* or
    *maildir*. Currently only used to determine the type for newly
    created folders.

e-mail address

:   An e-mail address either with or without realname. The older
    “`user@example.org (Joe User)`”form is supported but
    strongly deprecated.

user-defined

:   Arbitrary text, see [User-Defined Variables](#set-myvar)for details.

### Commands {#set-commands}

The following commands are available to manipulate and query variables:

Usage:

set
no
inv
variable
variable=value
toggle
variable
variable
unset
variable
variable
reset
variable
variable
This command is used to set (and unset) [configuration
variables](#variables). There are four basic types of variables:
boolean, number, string and quadoption. *boolean* variables can be
*set*(true) or *unset*(false). *number* variables can be assigned a
positive integer value. *string* variables consist of any number of
printable characters and must be enclosed in quotes if they contain
spaces or tabs. You may also use the escape sequences “\\n” and “\\t”
for newline and tab, respectively. *quadoption* variables are used to
control whether or not to be prompted for certain actions, or to specify
a default action. A value of *yes* will cause the action to be carried
out automatically as if you had answered yes to the question. Similarly,
a value of *no* will cause the action to be carried out as if you had
answered “no.”A value of *ask-yes* will cause a prompt with a default
answer of “yes” and *ask-no* will provide a default answer of “no.”

Prefixing a variable with “no” will unset it. Example: `
        set noaskbcc`.

For *boolean* variables, you may optionally prefix the variable name
with `inv` to toggle the value (on or off). This is useful when writing
macros. Example: `
        set invsmart_wrap`.

The `toggle` command automatically prepends the `inv` prefix to all
specified variables.

The `unset` command automatically prepends the `no` prefix to all
specified variables.

Using the `<enter-command>`function in the *index* menu, you can query
the value of a variable by prefixing the name of the variable with a
question mark:

    set ?allow_8bit

The question mark is actually only required for boolean and quadoption
variables.

The `reset` command resets all given variables to the compile time
defaults (hopefully mentioned in this manual). If you use the command
`set` and prefix the variable with “&”this has the same behavior as the
`reset` command.

With the `reset` command there exists the special variable “all”, which
allows you to reset all variables to their system defaults.

### User-Defined Variables {#set-myvar}

#### Introduction {#set-myvar-intro}

Along with the variables listed in the [Configuration
variables](#variables) section, Mutt supports user-defined variables
with names starting with `my_` as in, for example, `my_cfgdir`.

The `set` command either creates a custom `my_` variable or changes its
value if it does exist already. The `unset` and `reset` commands remove
the variable entirely.

Since user-defined variables are expanded in the same way that
environment variables are (except for the [shell-escape](#shell-escape)
command and backtick expansion), this feature can be used to make
configuration files more readable.

#### Examples {#set-myvar-examples}

The following example defines and uses the variable `my_cfgdir` to
abbreviate the calls of the [`source`](#source)command:

    set my_cfgdir = $HOME/mutt/config
    source $my_cfgdir/hooks $my_cfgdir/macros
    # more source commands...

A custom variable can also be used in macros to backup the current value
of another variable. In the following example, the value of the
[\$delete](#delete) is changed temporarily while its original value is
saved as `my_delete`. After the macro has executed all commands, the
original value of [\$delete](#delete) is restored.

    macro pager ,x '\
    <enter-command>set my_delete=$delete<enter>\
    <enter-command>set delete=yes<enter>\
    ...\
    <enter-command>set delete=$my_delete<enter>'

Since Mutt expands such values already when parsing the configuration
file(s), the value of `$my_delete` in the last example would be the
value of [\$delete](#delete) exactly as it was at that point during
parsing the configuration file. If another statement would change the
value for [\$delete](#delete) later in the same or another file, it
would have no effect on `$my_delete`. However, the expansion can be
deferred to runtime, as shown in the next example, when escaping the
dollar sign.

    macro pager <PageDown> "\
    <enter-command> set my_old_pager_stop=\$pager_stop pager_stop<Enter>\
    <next-page>\
    <enter-command> set pager_stop=\$my_old_pager_stop<Enter>\
    <enter-command> unset my_old_pager_stop<Enter>"

Note that there is a space between `<enter-command>`and the `set`
configuration command, preventing Mutt from recording the `macro`'s
commands into its history.

### Type Conversions {#set-conversions}

Variables are always assigned string values which Mutt parses into its
internal representation according to the type of the variable, for
example an integer number for numeric types. For all queries (including
\$-expansion) the value is converted from its internal type back into
string. As a result, any variable can be assigned any value given that
its content is valid for the target. This also counts for custom
variables which are of type string. In case of parsing errors, Mutt will
print error messages. [example\_title](#ex-myvar4)demonstrates type
conversions.

    set my_lines = "5"                # value is string "5"
    set pager_index_lines = $my_lines # value is integer 5
    set my_sort = "date-received"     # value is string "date-received"
    set sort = "last-$my_sort"        # value is sort last-date-received
    set my_inc = $read_inc            # value is string "10" (default of $read_inc)
    set my_foo = $my_inc
              # value is string "10"

These assignments are all valid. If, however, the value of `$my_lines`
would have been “five”(or something else that cannot be parsed into a
number), the assignment to `$pager_index_lines` would have produced an
error message.

Type conversion applies to all configuration commands which take
arguments. But please note that every expanded value of a variable is
considered just a single token. A working example is:

    set my_pattern = "~A"
    set my_number = "10"
    # same as: score ~A +10
    score $my_pattern +$my_number

What does *not* work is:

    set my_mx = "+mailbox1 +mailbox2"
    mailboxes $my_mx +mailbox3

because the value of `$my_mx` is interpreted as a single mailbox named
“+mailbox1 +mailbox2” and not two distinct mailboxes.

Reading Initialization Commands From Another File {#source}
-------------------------------------------------

Usage:

source
file
This command allows the inclusion of initialization commands from other
files. For example, I place all of my aliases in `~/.mail_aliases` so
that I can make my `~/.muttrc` readable and keep my aliases private.

If the filename begins with a tilde ( “\~”), it will be expanded to the
path of your home directory.

If the filename ends with a vertical bar ( “|”), then *filename* is
considered to be an executable program from which to read input (e.g. `
      source~/bin/myscript|`).

Removing Hooks {#unhook}
--------------

Usage:

unhook
\*
hook-type
This command permits you to flush hooks you have previously defined. You
can either remove all hooks by giving the “\*”character as an argument,
or you can remove all hooks of a specific type by saying something like
`
      unhook send-hook`.

Format Strings {#formatstrings}
--------------

### Basic usage {#formatstrings-basics}

Format strings are a general concept you'll find in several locations
through the Mutt configuration, especially in the
[\$index\_format](#index-format), [\$pager\_format](#pager-format),
[\$status\_format](#status-format), and other related variables. These
can be very straightforward, and it's quite possible you already know
how to use them.

The most basic format string element is a percent symbol followed by
another character. For example, `%s` represents a message's Subject:
header in the [\$index\_format](#index-format) variable. The “expandos”
available are documented with each format variable, but there are
general modifiers available with all formatting expandos, too. Those are
our concern here.

Some of the modifiers are borrowed right out of C (though you might know
them from Perl, Python, shell, or another language). These are the
`[-]m.n` modifiers, as in `%-12.12s`. As with such programming
languages, these modifiers allow you to specify the minimum and maximum
size of the resulting string, as well as its justification. If the
“-”sign follows the percent, the string will be left-justified instead
of right-justified. If there's a number immediately following that, it's
the minimum amount of space the formatted string will occupy — if it's
naturally smaller than that, it will be padded out with spaces. If a
decimal point and another number follow, that's the maximum space
allowable — the string will not be permitted to exceed that width, no
matter its natural size. Each of these three elements is optional, so
that all these are legal format strings: `%-12s`, `%4c`, `%.15F` and
`%-12.15L`.

Mutt adds some other modifiers to format strings. If you use an equals
symbol ( `=`) as a numeric prefix (like the minus above), it will force
the string to be centered within its minimum space range. For example,
`%=14y` will reserve 14 characters for the %y expansion — that's the set
of message keywords (formerly X-Label). If the expansion results in a
string less than 14 characters, it will be centered in a 14-character
space. If the X-Label for a message were “test”, that expansion would
look like “     test     ”.

There are two very little-known modifiers that affect the way that an
expando is replaced. If there is an underline ( “\_”) character between
any format modifiers (as above) and the expando letter, it will expands
in all lower case. And if you use a colon ( “:”), it will replace all
decimal points with underlines.

### Conditionals {#formatstrings-conditionals}

Depending on the format string variable, some of its sequences can be
used to optionally print a string if their value is nonzero. For
example, you may only want to see the number of flagged messages if such
messages exist, since zero is not particularly meaningful. To optionally
print a string based upon one of the above sequences, the following
construct is used:

    %?<sequence_char>?<optional_string>?

where *sequence\_char* is an expando, and *optional\_string* is the
string you would like printed if *sequence\_char* is nonzero.
*optional\_string* may contain other sequences as well as normal text,
but you may not nest optional strings.

Here is an example illustrating how to optionally print the number of
new messages in a mailbox in [\$status\_format](#status-format):

    %?n?%n new messages.?

You can also switch between two strings using the following construct:

    %?<sequence_char>?<if_string>&<else_string>?

If the value of *sequence\_char* is non-zero, *if\_string* will be
expanded, otherwise *else\_string* will be expanded.

The conditional sequences can also be nested by using the %&lt; and &gt;
operators. The %? notation can still be used but requires quoting. For
example:

    %<x?true&false>
    %<x?%<y?%<z?xyz&xy>&x>&none>

For more examples, see [Nested If Feature](#nested-if)

### Filters {#formatstrings-filters}

Any format string ending in a vertical bar ( “|”) will be expanded and
piped through the first word in the string, using spaces as separator.
The string returned will be used for display. If the returned string
ends in %, it will be passed through the formatter a second time. This
allows the filter to generate a replacement format string including %
expandos.

All % expandos in a format string are expanded before the script is
called so that:

    set status_format="script.sh '%r %f (%L)'|"

will make Mutt expand `%r`, `%f` and `%L` before calling the script. The
example also shows that arguments can be quoted: the script will receive
the expanded string between the single quotes as the only argument.

A practical example is the `mutt_xtitle` script installed in the
`samples` subdirectory of the Mutt documentation: it can be used as
filter for [\$status\_format](#status-format) to set the current
terminal's title, if supported.

### Padding {#formatstrings-padding}

In most format strings, Mutt supports different types of padding using
special %-expandos:

`%|X`

:   When this occurs, Mutt will fill the rest of the line with the
    character `X`. For example, filling the rest of the line with dashes
    is done by setting:

        set status_format = "%v on %h: %B: %?n?%n&no? new messages %|-"

`%>X`

:   Since the previous expando stops at the end of line, there must be a
    way to fill the gap between two items via the `%>X` expando: it puts
    as many characters `X` in between two items so that the rest of the
    line will be right-justified. For example, to not put the version
    string and hostname the above example on the left but on the right
    and fill the gap with spaces, one might use (note the space after
    `%>`):

        set status_format = "%B: %?n?%n&no? new messages %> (%v on %h)"

`%*X`

:   Normal right-justification will print everything to the left of the
    `%>`, displaying padding and whatever lies to the right only if
    there's room. By contrast, “soft-fill” gives priority to the
    right-hand side, guaranteeing space to display it and showing
    padding only if there's still room. If necessary, soft-fill will eat
    text leftwards to make room for rightward text. For example, to
    right-justify the subject making sure as much as possible of it fits
    on screen, one might use (note two spaces after `%*`: the second
    ensures there's a space between the truncated right-hand side and
    the subject):

        set index_format="%4C %Z %{%b %d} %-15.15L (%?l?%4l&%4c?)%*  %s"

### Conditional Dates {#formatstrings-conditional-dates}

This feature allows the format of dates in the index to vary based on
how recent the message is. This is especially useful in combination with
the [nested-if feature](#nested-if).

For example, using `
        %<[y?%<[d?%[%H:%M]&%[%m/%d]>&%[%y.%m]>`for the date in the
`$index_format` will produce a display like:

       1   + 14.12 Grace Hall      (   13) Gulliver's Travels
       2   + 10/02 Callum Harrison (   48) Huckleberry Finn
       3     12:17 Rhys Lee        (   42) The Lord Of The Rings

Control allowed header fields in a mailto: URL {#mailto-allow}
----------------------------------------------

Usage:

mailto\_allow
\*
header-field
unmailto\_allow
\*
header-field
As a security measure, Mutt will only add user-approved header fields
from a `mailto:`URL. This is necessary since Mutt will handle certain
header fields, such as `Attach:`, in a special way. The `mailto_allow`
and `unmailto_allow` commands allow the user to modify the list of
approved headers.

Mutt initializes the default list to contain only the `Subject` and
`Body` header fields, which are the only requirement specified by the
`mailto:`specification in RFC2368.

Advanced Usage {#advancedusage}
==============

Character Set Handling {#charset-handling}
----------------------

A “character set” is basically a mapping between bytes and glyphs and
implies a certain character encoding scheme. For example, for the ISO
8859 family of character sets, an encoding of 8bit per character is
used. For the Unicode character set, different character encodings may
be used, UTF-8 being the most popular. In UTF-8, a character is
represented using a variable number of bytes ranging from 1 to 4.

Since Mutt is a command-line tool run from a shell, and delegates
certain tasks to external tools (such as an editor for composing/editing
messages), all of these tools need to agree on a character set and
encoding. There exists no way to reliably deduce the character set a
plain text file has. Interoperability is gained by the use of
well-defined environment variables. The full set can be printed by
issuing `locale` on the command line.

Upon startup, Mutt determines the character set on its own using
routines that inspect locale-specific environment variables. Therefore,
it is generally not necessary to set the `$charset` variable in Mutt. It
may even be counter-productive as Mutt uses system and library functions
that derive the character set themselves and on which Mutt has no
influence. It's safest to let Mutt work out the locale setup itself.

If you happen to work with several character sets on a regular basis,
it's highly advisable to use Unicode and an UTF-8 locale. Unicode can
represent nearly all characters in a message at the same time. When not
using a Unicode locale, it may happen that you receive messages with
characters not representable in your locale. When displaying such a
message, or replying to or forwarding it, information may get lost
possibly rendering the message unusable (not only for you but also for
the recipient, this breakage is not reversible as lost information
cannot be guessed).

A Unicode locale makes all conversions superfluous which eliminates the
risk of conversion errors. It also eliminates potentially wrong
expectations about the character set between Mutt and external programs.

The terminal emulator used also must be properly configured for the
current locale. Terminal emulators usually do *not* derive the locale
from environment variables, they need to be configured separately. If
the terminal is incorrectly configured, Mutt may display random and
unexpected characters (question marks, octal codes, or just random
glyphs), format strings may not work as expected, you may not be abled
to enter non-ascii characters, and possible more. Data is always
represented using bytes and so a correct setup is very important as to
the machine, all character sets “look” the same.

Warning: A mismatch between what system and library functions think the
locale is and what Mutt was told what the locale is may make it behave
badly with non-ascii input: it will fail at seemingly random places.
This warning is to be taken seriously since not only local mail handling
may suffer: sent messages may carry wrong character set information the
*receiver* has too deal with. The need to set `$charset` directly in
most cases points at terminal and environment variable setup problems,
not Mutt problems.

A list of officially assigned and known character sets can be found at
[IANA](http://www.iana.org/assignments/character-sets), a list of
locally supported locales can be obtained by running `locale -a`.

Regular Expressions {#regexp}
-------------------

All string patterns in Mutt including those in more complex
[patterns](#patterns) must be specified using regular expressions
(regexp) in the “POSIX extended” syntax (which is more or less the
syntax used by egrep and GNU awk). For your convenience, we have
included below a brief description of this syntax.

The search is case sensitive if the pattern contains at least one upper
case letter, and case insensitive otherwise.

> **Note**
>
> “\\”must be quoted if used for a regular expression in an
> initialization command: “\\\\”.

A regular expression is a pattern that describes a set of strings.
Regular expressions are constructed analogously to arithmetic
expressions, by using various operators to combine smaller expressions.

> **Note**
>
> The regular expression can be enclosed/delimited by either " or '
> which is useful if the regular expression includes a white-space
> character. See [Syntax of Initialization Files](#muttrc-syntax)for
> more information on " and ' delimiter processing. To match a literal "
> or ' you must preface it with \\ (backslash).

The fundamental building blocks are the regular expressions that match a
single character. Most characters, including all letters and digits, are
regular expressions that match themselves. Any metacharacter with
special meaning may be quoted by preceding it with a backslash.

The period “.”matches any single character. The caret “\^”and the dollar
sign “\$”are metacharacters that respectively match the empty string at
the beginning and end of a line.

A list of characters enclosed by “\[”and “\]”matches any single
character in that list; if the first character of the list is a caret
“\^”then it matches any character *not* in the list. For example, the
regular expression *\[0123456789\]*matches any single digit. A range of
ASCII characters may be specified by giving the first and last
characters, separated by a hyphen “-”. Most metacharacters lose their
special meaning inside lists. To include a literal “\]”place it first in
the list. Similarly, to include a literal “\^”place it anywhere but
first. Finally, to include a literal hyphen “-”place it last.

Certain named classes of characters are predefined. Character classes
consist of “\[:”, a keyword denoting the class, and “:\]”. The following
classes are defined by the POSIX standard in
[table\_title](#posix-regex-char-classes)

  Character class   Description
  ----------------- ---------------------------------------------------------------------------------------------------------------
  \[:alnum:\]       Alphanumeric characters
  \[:alpha:\]       Alphabetic characters
  \[:blank:\]       Space or tab characters
  \[:cntrl:\]       Control characters
  \[:digit:\]       Numeric characters
  \[:graph:\]       Characters that are both printable and visible. (A space is printable, but not visible, while an “a” is both)
  \[:lower:\]       Lower-case alphabetic characters
  \[:print:\]       Printable characters (characters that are not control characters)
  \[:punct:\]       Punctuation characters (characters that are not letter, digits, control characters, or space characters)
  \[:space:\]       Space characters (such as space, tab and formfeed, to name a few)
  \[:upper:\]       Upper-case alphabetic characters
  \[:xdigit:\]      Characters that are hexadecimal digits

  : POSIX regular expression character classes

A character class is only valid in a regular expression inside the
brackets of a character list.

> **Note**
>
> Note that the brackets in these class names are part of the symbolic
> names, and must be included in addition to the brackets delimiting the
> bracket list. For example, *\[\[:digit:\]\]*is equivalent to
> *\[0-9\]*.

Two additional special sequences can appear in character lists. These
apply to non-ASCII character sets, which can have single symbols (called
collating elements) that are represented with more than one character,
as well as several characters that are equivalent for collating or
sorting purposes:

Collating Symbols

:   A collating symbol is a multi-character collating element enclosed
    in “\[.”and “.\]”. For example, if “ch” is a collating element, then
    *\[\[.ch.\]\]*is a regexp that matches this collating element, while
    *\[ch\]*is a regexp that matches either “c” or “h”.

Equivalence Classes

:   An equivalence class is a locale-specific name for a list of
    characters that are equivalent. The name is enclosed in “\[=”and
    “=\]”. For example, the name “e” might be used to represent all of
    “e” with grave ( “è”), “e” with acute ( “é”) and “e”. In this case,
    *\[\[=e=\]\]*is a regexp that matches any of: “e” with grave ( “è”),
    “e” with acute ( “é”) and “e”.

A regular expression matching a single character may be followed by one
of several repetition operators described in
[table\_title](#regex-repeat).

  Operator   Description
  ---------- ------------------------------------------------------------------------------
  ?          The preceding item is optional and matched at most once
  \*         The preceding item will be matched zero or more times
  +          The preceding item will be matched one or more times
  {n}        The preceding item is matched exactly *n* times
  {n,}       The preceding item is matched *n* or more times
  {,m}       The preceding item is matched at most *m* times
  {n,m}      The preceding item is matched at least *n* times, but no more than *m* times

  : Regular expression repetition operators

Two regular expressions may be concatenated; the resulting regular
expression matches any string formed by concatenating two substrings
that respectively match the concatenated subexpressions.

Two regular expressions may be joined by the infix operator “|”; the
resulting regular expression matches any string matching either
subexpression.

Repetition takes precedence over concatenation, which in turn takes
precedence over alternation. A whole subexpression may be enclosed in
parentheses to override these precedence rules.

> **Note**
>
> If you compile Mutt with the included regular expression engine, the
> following operators may also be used in regular expressions as
> described in [table\_title](#regex-gnu-ext).

  Expression   Description
  ------------ -----------------------------------------------------------------------
  \\\\y        Matches the empty string at either the beginning or the end of a word
  \\\\B        Matches the empty string within a word
  \\\\&lt;     Matches the empty string at the beginning of a word
  \\\\&gt;     Matches the empty string at the end of a word
  \\\\w        Matches any word-constituent character (letter, digit, or underscore)
  \\\\W        Matches any character that is not word-constituent
  \\\\\`       Matches the empty string at the beginning of a buffer (string)
  \\\\'        Matches the empty string at the end of a buffer

  : GNU regular expression extensions

Please note however that these operators are not defined by POSIX, so
they may or may not be available in stock libraries on various systems.

Patterns: Searching, Limiting and Tagging {#patterns}
-----------------------------------------

### Pattern Modifier {#patterns-modifier}

Many of Mutt's commands allow you to specify a pattern to match (
`limit`, `tag-pattern`, `delete-pattern`, etc.).
[table\_title](#tab-patterns)shows several ways to select messages.

  Pattern modifier            Description
  --------------------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  \~A                         all messages
  \~b *EXPR*                  messages which contain *EXPR* in the message body
  =b *STRING*                 messages which contain *STRING* in the message body. If IMAP is enabled, searches for *STRING* on the server, rather than downloading each message and searching it locally.
  \~B *EXPR*                  messages which contain *EXPR* in the whole message
  =B *STRING*                 messages which contain *STRING* in the whole message. If IMAP is enabled, searches for *STRING* on the server, rather than downloading each message and searching it locally.
  \~c *EXPR*                  messages carbon-copied to *EXPR*
  %c *GROUP*                  messages carbon-copied to any member of *GROUP*
  \~C *EXPR*                  messages either to: or cc: *EXPR*
  %C *GROUP*                  messages either to: or cc: to any member of *GROUP*
  \~d \[ *MIN*\]-\[ *MAX*\]   messages with “date-sent” in a Date range
  \~D                         deleted messages
  \~e *EXPR*                  messages which contains *EXPR* in the “Sender” field
  %e *GROUP*                  messages which contain a member of *GROUP* in the “Sender” field
  \~E                         expired messages
  \~F                         flagged messages
  \~f *EXPR*                  messages originating from *EXPR*
  %f *GROUP*                  messages originating from any member of *GROUP*
  \~g                         cryptographically signed messages
  \~G                         cryptographically encrypted messages
  \~h *EXPR*                  messages which contain *EXPR* in the message header
  =h *STRING*                 messages which contain *STRING* in the message header. If IMAP is enabled, searches for *STRING* on the server, rather than downloading each message and searching it locally; *STRING* must be of the form “header: substring”(see below).
  \~H *EXPR*                  messages with a spam attribute matching *EXPR*
  \~i *EXPR*                  messages which match *EXPR* in the “Message-ID” field
  \~k                         messages which contain PGP key material
  \~L *EXPR*                  messages either originated or received by *EXPR*
  %L *GROUP*                  message either originated or received by any member of *GROUP*
  \~l                         messages addressed to a known mailing list
  \~m \[ *MIN*\]-\[ *MAX*\]   messages with numbers in the range *MIN* to *MAX*\*\*\*)
  \~m &lt;\[ *MAX*\]          messages with numbers less than *MAX*\*\*\*)
  \~m &gt;\[ *MIN*\]          messages with numbers greater than *MIN*\*\*\*)
  \~m \[ *M*\]                just message number *M*\*\*\*)
  \~m \[ *MIN*\],\[ *MAX*\]   messages with offsets (from selected message) in the range *MIN* to *MAX*\*\*\*)
  \~n \[ *MIN*\]-\[ *MAX*\]   messages with a score in the range *MIN* to *MAX*\*)
  \~N                         new messages
  \~O                         old messages
  \~p                         messages addressed to you (consults `alternates`)
  \~P                         messages from you (consults `alternates`)
  \~Q                         messages which have been replied to
  \~r \[ *MIN*\]-\[ *MAX*\]   messages with “date-received” in a Date range
  \~R                         read messages
  \~s *EXPR*                  messages having *EXPR* in the “Subject” field.
  \~S                         superseded messages
  \~t *EXPR*                  messages addressed to *EXPR*
  \~T                         tagged messages
  \~u                         messages addressed to a subscribed mailing list
  \~U                         unread messages
  \~v                         messages part of a collapsed thread.
  \~V                         cryptographically verified messages
  \~x *EXPR*                  messages which contain *EXPR* in the “References” or “In-Reply-To” field
  \~X \[ *MIN*\]-\[ *MAX*\]   messages with *MIN* to *MAX* attachments \*)
  \~y *EXPR*                  messages which contain *EXPR* in their keywords
  \~z \[ *MIN*\]-\[ *MAX*\]   messages with a size in the range *MIN* to *MAX*\*) \*\*)
  \~=                         duplicated messages (see [\$duplicate\_threads](#duplicate-threads))
  \~\$                        unreferenced messages (requires threaded view)
  \~( *PATTERN*)              messages in threads containing messages matching *PATTERN*, e.g. all threads containing messages from you: \~(\~P)

  : Pattern modifiers

Where *EXPR* is a [regular expression](#regexp), and *GROUP* is an
[address group](#addrgroup).

\*) The forms “&lt;\[ *MAX*\]”, “&gt;\[ *MIN*\]”, “\[ *MIN*\]-”and “-\[
*MAX*\]”are allowed, too.

\*\*) The suffixes “K” and “M” are allowed to specify kilobyte and
megabyte respectively.

\*\*\*) The message number ranges (introduced by `~m`) are even more
general and powerful than the other types of ranges. Read on and see
[Message Ranges](#message-ranges)below.

Special attention has to be paid when using regular expressions inside
of patterns. Specifically, Mutt's parser for these patterns will strip
one level of backslash ( “\\”), which is normally used for quoting. If
it is your intention to use a backslash in the regular expression, you
will need to use two backslashes instead ( “\\\\”). You can force Mutt
to treat *EXPR* as a simple string instead of a regular expression by
using = instead of \~ in the pattern name. For example, `=b *.*`will
find all messages that contain the literal string “\*.\*”. Simple string
matches are less powerful than regular expressions but can be
considerably faster. This is especially true for IMAP folders, because
string matches can be performed on the server instead of by fetching
every message. IMAP treats `=h` specially: it must be of the form
“header: substring” and will not partially match header names. The
substring part may be omitted if you simply wish to find messages
containing a particular header without regard to its value.

Patterns matching lists of addresses (notably c, C, p, P and t) match if
there is at least one match in the whole list. If you want to make sure
that all elements of that list match, you need to prefix your pattern
with “\^”. This example matches all mails which only has recipients from
Germany.

    ^~C \.de$

You can restrict address pattern matching to aliases that you have
defined with the "@" modifier. This example matches messages whose
recipients are all from Germany, and who are known to your alias list.

    ^@~C \.de$

To match any defined alias, use a regular expression that matches any
string. This example matches messages whose senders are known aliases.

    @~f .

#### Message Ranges

If a message number range (from now on: MNR) contains a comma ( `,`), it
is a *relative* MNR. That means the numbers denote *offsets* from the
highlighted message. For example:

  Pattern     Explanation
  ----------- -------------------------------------------
  `~m -2,2`   Previous 2, highlighted and next 2 emails
  `~m 0,1`    Highlighted and next email

  : Relative Message Number Ranges

In addition to numbers, either side of the range can also contain one of
the special characters (shortcuts) `.^$`. The meaning is:

  Shortcut   Explanation             Example     Meaning
  ---------- ----------------------- ----------- --------------------------------------------
  `.`        Current / Highlighted   `~m -3,.`   Previous 3 emails plus the highlighted one
  `$`        Last                    `~m .,$`    Highlighted email and all the later ones
  `^`        First                   `~m ^,1`    Highlighted, next and all preceding ones

  : Message Number Shortcuts

Lastly, you can also leave either side of the range blank, to make it
extend as far as possible. For example, `~m ,1` has the same meaning as
the last example in [table\_title](#mnrs-shortcuts).

Otherwise, if a MNR *doesn't* contain a comma, the meaning is similar to
other ranges, except that the shortcuts are still available. Examples:

  Pattern     Explanation
  ----------- ----------------------------
  `~m 3-10`   Emails 3 to 10
  `~m -10`    Emails 1 to 10
  `~m 10-`    Emails 10 to last
  `~m <3`     First and second email
  `~m ^-2`    First and second email
  `~m >1`     Everything but first email
  `~m 2-$`    Everything but first email
  `~m 2`      Just the second email

  : Absolute Message Number Ranges

### Simple Searches

Mutt supports two versions of so called “simple searches”. These are
issued if the query entered for searching, limiting and similar
operations does not seem to contain a valid pattern modifier (i.e. it
does not contain one of these characters: “\~”, “=”or “%”). If the query
is supposed to contain one of these special characters, they must be
escaped by prepending a backslash ( “\\”).

The first type is by checking whether the query string equals a keyword
case-insensitively from [table\_title](#tab-simplesearch-keywords): If
that is the case, Mutt will use the shown pattern modifier instead. If a
keyword would conflict with your search keyword, you need to turn it
into a regular expression to avoid matching the keyword table. For
example, if you want to find all messages matching “flag”(using
[\$simple\_search](#simple-search)) but don't want to match flagged
messages, simply search for “`[f]lag`”.

  Keyword   Pattern modifier
  --------- ------------------
  all       \~A
  .         \~A
  \^        \~A
  del       \~D
  flag      \~F
  new       \~N
  old       \~O
  repl      \~Q
  read      \~R
  tag       \~T
  unread    \~U

  : Simple search keywords

The second type of simple search is to build a complex search pattern
using [\$simple\_search](#simple-search) as a template. Mutt will insert
your query properly quoted and search for the composed complex query.

### Nesting and Boolean Operators {#complex-patterns}

Logical AND is performed by specifying more than one criterion. For
example:

    ~t mutt ~f elkins

would select messages which contain the word “mutt” in the list of
recipients *and* that have the word “elkins” in the “From” header field.

Mutt also recognizes the following operators to create more complex
search patterns:

-   ! — logical NOT operator

-   | — logical OR operator

-   () — logical grouping operator

Here is an example illustrating a complex search pattern. This pattern
will select all messages which do not contain “mutt” in the “To” or “Cc”
field and which are from “elkins”.

    !(~t mutt|~c mutt) ~f elkins

Here is an example using white space in the regular expression (note the
“'”and “"”delimiters). For this to match, the mail's subject must match
the “\^Junk +From +Me\$”and it must be from either “Jim +Somebody” or
“Ed +SomeoneElse”:

    '~s "^Junk +From +Me$" ~f ("Jim +Somebody"|"Ed +SomeoneElse")'

> **Note**
>
> If a regular expression contains parenthesis, or a vertical bar ("|"),
> you *must* enclose the expression in double or single quotes since
> those characters are also used to separate different parts of Mutt's
> pattern language. For example:
> `~f "me@(mutt\.org|cs\.hmc\.edu)"`Without the quotes, the parenthesis
> wouldn't end. This would be separated to two OR'd patterns: *\~f
> me@(mutt\\.org* and *cs\\.hmc\\.edu)*. They are never what you want.

### Searching by Date {#date-patterns}

Mutt supports two types of dates, *absolute* and *relative*.

#### Absolute Dates {#date-absolute}

Dates *must* be in DD/MM/YY format (month and year are optional,
defaulting to the current month and year). An example of a valid range
of dates is:

    Limit to messages matching: ~d 20/1/95-31/10

If you omit the minimum (first) date, and just specify “-DD/MM/YY”, all
messages *before* the given date will be selected. If you omit the
maximum (second) date, and specify “DD/MM/YY-”, all messages *after* the
given date will be selected. If you specify a single date with no dash (
“-”), only messages sent on the given date will be selected.

You can add error margins to absolute dates. An error margin is a sign
(+ or -), followed by a digit, followed by one of the units in
[table\_title](#tab-date-units). As a special case, you can replace the
sign by a “\*”character, which is equivalent to giving identical plus
and minus error margins.

  Unit   Description
  ------ -------------
  y      Years
  m      Months
  w      Weeks
  d      Days

  : Date units

Example: To select any messages two weeks around January 15, 2001, you'd
use the following pattern:

    Limit to messages matching: ~d 15/1/2001*2w

#### Relative Dates {#dates-relative}

This type of date is relative to the current date, and may be specified
as:

-   &gt; *offset* for messages older than *offset* units

-   &lt; *offset* for messages newer than *offset* units

-   = *offset* for messages exactly *offset* units old

*offset* is specified as a positive number with one of the units from
[table\_title](#tab-date-units).

Example: to select messages less than 1 month old, you would use

    Limit to messages matching: ~d <1m

> **Note**
>
> All dates used when searching are relative to the *local* time zone,
> so unless you change the setting of your
> [\$index\_format](#index-format) to include a `%[...]`format, these
> are *not* the dates shown in the main index.

Marking Messages {#markmsg}
----------------

There are times that it's useful to ask Mutt to "remember" which message
you're currently looking at, while you move elsewhere in your mailbox.
You can do this with the “mark-message” operator, which is bound to the
“\~”key by default. Press this key to enter an identifier for the marked
message. When you want to return to this message, press “'”and the name
that you previously entered.

(Message marking is really just a shortcut for defining a macro that
returns you to the current message by searching for its Message-ID. You
can choose a different prefix by setting the
[\$mark\_macro\_prefix](#mark-macro-prefix) variable.)

Using Tags {#tags}
----------

Sometimes it is desirable to perform an operation on a group of messages
all at once rather than one at a time. An example might be to save
messages to a mailing list to a separate folder, or to delete all
messages with a given subject. To tag all messages matching a pattern,
use the `<tag-pattern>`function, which is bound to “shift-T” by default.
Or you can select individual messages by hand using the
`<tag-message>`function, which is bound to “t” by default. See
[patterns](#patterns) for Mutt's pattern matching syntax.

Once you have tagged the desired messages, you can use the “tag-prefix”
operator, which is the “;”(semicolon) key by default. When the
“tag-prefix” operator is used, the *next* operation will be applied to
all tagged messages if that operation can be used in that manner. If the
[\$auto\_tag](#auto-tag) variable is set, the next operation applies to
the tagged messages automatically, without requiring the “tag-prefix”.

In [`macro`s](#macro)or [`push`](#push)commands, you can use the
`<tag-prefix-cond>`operator. If there are no tagged messages, Mutt will
“eat” the rest of the macro to abort it's execution. Mutt will stop
“eating” the macro when it encounters the `<end-cond>`operator; after
this operator the rest of the macro will be executed as normal.

Using Hooks {#hooks}
-----------

A *hook* is a concept found in many other programs which allows you to
execute arbitrary commands before performing some operation. For
example, you may wish to tailor your configuration based upon which
mailbox you are reading, or to whom you are sending mail. In the Mutt
world, a *hook* consists of a [regular expression](#regexp) or
[pattern](#patterns) along with a configuration option/command. See:

-   [`account-hook`](#account-hook)

-   [`append-hook`](#append-hook)

-   [`charset-hook`](#charset-hook)

-   [`close-hook`](#close-hook)

-   [`crypt-hook`](#crypt-hook)

-   [`fcc-hook`](#fcc-hook)

-   [`fcc-save-hook`](#fcc-save-hook)

-   [`folder-hook`](#folder-hook)

-   [`iconv-hook`](#iconv-hook)

-   [`mbox-hook`](#mbox-hook)

-   [`message-hook`](#message-hook)

-   [`open-hook`](#open-hook)

-   [`reply-hook`](#reply-hook)

-   [`save-hook`](#save-hook)

-   [`send-hook`](#send-hook)

-   [`send2-hook`](#send2-hook)

for specific details on each type of *hook* available.

> **Note**
>
> If a hook changes configuration settings, these changes remain
> effective until the end of the current Mutt session. As this is
> generally not desired, a “default” hook needs to be added before all
> other hooks of that type to restore configuration defaults.

    send-hook . 'unmy_hdr From:'
    send-hook ~C'^b@b\.b$' my_hdr from: c@c.c

In [example\_title](#ex-default-hook), by default the value of
[\$from](#from) and [\$realname](#realname) is not overridden. When
sending messages either To: or Cc: to `<b@b.b>`, the From: header is
changed to `<c@c.c>`.

### Message Matching in Hooks {#pattern-hook}

Hooks that act upon messages ( `message-hook`, `reply-hook`,
`send-hook`, `send2-hook`, `save-hook`, `fcc-hook`) are evaluated in a
slightly different manner. For the other types of hooks, a [regular
expression](#regexp) is sufficient. But in dealing with messages a finer
grain of control is needed for matching since for different purposes you
want to match different criteria.

Mutt allows the use of the [search pattern](#patterns) language for
matching messages in hook commands. This works in exactly the same way
as it would when *limiting* or *searching* the mailbox, except that you
are restricted to those operators which match information Mutt extracts
from the header of the message (i.e., from, to, cc, date, subject,
etc.).

For example, if you wanted to set your return address based upon sending
mail to a specific address, you could do something like:

    send-hook '~t ^me@cs\.hmc\.edu$' 'my_hdr From: Mutt User <user@host>'

which would execute the given command when sending mail to
*me@cs.hmc.edu*.

However, it is not required that you write the pattern to match using
the full searching language. You can still specify a simple *regular
expression* like the other hooks, in which case Mutt will translate your
pattern into the full language, using the translation specified by the
[\$default\_hook](#default-hook) variable. The pattern is translated at
the time the hook is declared, so the value of
[\$default\_hook](#default-hook) that is in effect at that time will be
used.

### Mailbox Matching in Hooks {#mailbox-hook}

Hooks that match against mailboxes ( `folder-hook`, `mbox-hook`) apply
both [regular expression](#regexp) syntax as well as [mailbox
shortcut](#shortcuts) expansion on the regexp parameter. There is some
overlap between these, so special attention should be paid to the first
character of the regexp.

    # Here, ^ will expand to "the current mailbox" not "beginning of string":
    folder-hook ^/home/user/Mail/bar "set sort=threads"
    # If you want ^ to be interpreted as "beginning of string", one workaround
    # is to enclose the regexp in parenthesis:
    folder-hook (^/home/user/Mail/bar) "set sort=threads"
    # This will expand to the default save folder for the alias "imap.example.com", which
    # is probably not what you want:
    folder-hook @imap.example.com "set sort=threads"
    # A workaround is to use parenthesis or a backslash:
    folder-hook (@imap.example.com) "set sort=threads"
    folder-hook '\@imap.example.com' "set sort=threads"

Keep in mind that mailbox shortcut expansion on the regexp parameter
takes place when the hook is initially parsed, not when the hook is
matching against a mailbox. When Mutt starts up and is reading the
.muttrc, some mailbox shortcuts may not be usable. For example, the
"current mailbox" shortcut, \^, will expand to an empty string because
no mailbox has been opened yet. Mutt will issue an error for this case
or if the mailbox shortcut results in an empty regexp.

Managing the Environment {#setenv}
------------------------

You can alter the environment that Mutt passes on to its child processes
using the “setenv” and “unsetenv” operators. (N.B. These follow
Mutt-style syntax, not shell-style!) You can also query current
environment values by prefixing a “?”character.

    setenv TERM vt100
    setenv ORGANIZATION "The Mutt Development Team"
    unsetenv DISPLAY
    setenv ?LESS

External Address Queries {#query}
------------------------

Mutt supports connecting to external directory databases such as LDAP,
ph/qi, bbdb, or NIS through a wrapper script which connects to Mutt
using a simple interface. Using the [\$query\_command](#query-command)
variable, you specify the wrapper command to use. For example:

    set query_command = "mutt_ldap_query.pl %s"

The wrapper script should accept the query on the command-line. It
should return a one line message, then each matching response on a
single line, each line containing a tab separated address then name then
some other optional information. On error, or if there are no matching
addresses, return a non-zero exit code and a one line error message.

An example multiple response output:

    Searching database ... 20 entries ... 3 matching:
    me@cs.hmc.edu           Michael Elkins  mutt dude
    blong@fiction.net       Brandon Long    mutt and more
    roessler@does-not-exist.org        Thomas Roessler mutt pgp

There are two mechanisms for accessing the query function of Mutt. One
is to do a query from the index menu using the `<query>`function
(default: Q). This will prompt for a query, then bring up the query menu
which will list the matching responses. From the query menu, you can
select addresses to create aliases, or to mail. You can tag multiple
addresses to mail, start a new query, or have a new query appended to
the current responses.

The other mechanism for accessing the query function is for address
completion, similar to the alias completion. In any prompt for address
entry, you can use the `<complete-query>`function (default: \^T) to run
a query based on the current address you have typed. Like aliases, Mutt
will look for what you have typed back to the last space or comma. If
there is a single response for that query, Mutt will expand the address
in place. If there are multiple responses, Mutt will activate the query
menu. At the query menu, you can select one or more addresses to be
added to the prompt.

Mailbox Formats
---------------

Mutt supports reading and writing of four different local mailbox
formats: mbox, MMDF, MH and Maildir. The mailbox type is auto detected,
so there is no need to use a flag for different mailbox types. When
creating new mailboxes, Mutt uses the default specified with the
[\$mbox\_type](#mbox-type) variable. A short description of the formats
follows.

*mbox*. This is a widely used mailbox format for UNIX. All messages are
stored in a single file. Each message has a line of the form:

    From me@cs.hmc.edu Fri, 11 Apr 1997 11:44:56 PST

to denote the start of a new message (this is often referred to as the
“From\_” line). The mbox format requires mailbox locking, is prone to
mailbox corruption with concurrently writing clients or misinterpreted
From\_ lines. Depending on the environment, new mail detection can be
unreliable. Mbox folders are fast to open and easy to archive.

*MMDF*. This is a variant of the *mbox* format. Each message is
surrounded by lines containing “\^A\^A\^A\^A”(four times control-A's).
The same problems as for mbox apply (also with finding the right message
separator as four control-A's may appear in message bodies).

*MH*. A radical departure from *mbox* and *MMDF*, a mailbox consists of
a directory and each message is stored in a separate file. The filename
indicates the message number (however, this is may not correspond to the
message number Mutt displays). Deleted messages are renamed with a comma
( “,”) prepended to the filename. Mutt detects this type of mailbox by
looking for either `.mh_sequences` or `.xmhcache` files (needed to
distinguish normal directories from MH mailboxes). MH is more robust
with concurrent clients writing the mailbox, but still may suffer from
lost flags; message corruption is less likely to occur than with
mbox/mmdf. It's usually slower to open compared to mbox/mmdf since many
small files have to be read (Mutt provides
[Header Caching](#header-caching)to greatly speed this process up).
Depending on the environment, MH is not very disk-space efficient.

*Maildir*. The newest of the mailbox formats, used by the Qmail MTA (a
replacement for sendmail). Similar to *MH*, except that it adds three
subdirectories of the mailbox: *tmp*, *new* and *cur*. Filenames for the
messages are chosen in such a way they are unique, even when two
programs are writing the mailbox over NFS, which means that no file
locking is needed and corruption is very unlikely. Maildir maybe slower
to open without caching in Mutt, it too is not very disk-space efficient
depending on the environment. Since no additional files are used for
metadata (which is embedded in the message filenames) and Maildir is
locking-free, it's easy to sync across different machines using
file-level synchronization tools.

Mailbox Shortcuts {#shortcuts}
-----------------

There are a number of built in shortcuts which refer to specific
mailboxes. These shortcuts can be used anywhere you are prompted for a
file or mailbox path or in path-related configuration variables. Note
that these only work at the beginning of a string.

  Shortcut     Refers to...
  ------------ ------------------------------------------------------------------------------------
  `!`          your [\$spoolfile](#spoolfile)(incoming) mailbox
  `>`          your [\$mbox](#mbox) file
  `<`          your [\$record](#record) file
  `^`          the current mailbox
  `-`or `!!`   the file you've last visited
  `~`          your home directory
  `=`or `+`    your [\$folder](#folder) directory
  *@alias*     to the [default save folder](#save-hook) as determined by the address of the alias

  : Mailbox shortcuts

For example, to store a copy of outgoing messages in the folder they
were composed in, a [`folder-hook`](#folder-hook)can be used to set
[\$record](#record):

    folder-hook . 'set record=^'

Handling Mailing Lists {#using-lists}
----------------------

Mutt has a few configuration options that make dealing with large
amounts of mail easier. The first thing you must do is to let Mutt know
what addresses you consider to be mailing lists (technically this does
not have to be a mailing list, but that is what it is most often used
for), and what lists you are subscribed to. This is accomplished through
the use of the [`lists` and `subscribe`](#lists)commands in your
`.muttrc`.

Now that Mutt knows what your mailing lists are, it can do several
things, the first of which is the ability to show the name of a list
through which you received a message (i.e., of a subscribed list) in the
*index* menu display. This is useful to distinguish between personal and
list mail in the same mailbox. In the [\$index\_format](#index-format)
variable, the expando “%L” will print the string “To &lt;list&gt;”when
“list” appears in the “To” field, and “Cc &lt;list&gt;”when it appears
in the “Cc” field (otherwise it prints the name of the author).

Often times the “To” and “Cc” fields in mailing list messages tend to
get quite large. Most people do not bother to remove the author of the
message they reply to from the list, resulting in two or more copies
being sent to that person. The `<list-reply>`function, which by default
is bound to “L” in the *index* menu and *pager*, helps reduce the
clutter by only replying to the known mailing list addresses instead of
all recipients (except as specified by `Mail-Followup-To`, see below).

Mutt also supports the `Mail-Followup-To` header. When you send a
message to a list of recipients which includes one or several subscribed
mailing lists, and if the [\$followup\_to](#followup-to) option is set,
Mutt will generate a Mail-Followup-To header which contains all the
recipients to whom you send this message, but not your address. This
indicates that group-replies or list-replies (also known as “followups”)
to this message should only be sent to the original recipients of the
message, and not separately to you - you'll receive your copy through
one of the mailing lists you are subscribed to.

Conversely, when group-replying or list-replying to a message which has
a `Mail-Followup-To` header, Mutt will respect this header if the
[\$honor\_followup\_to](#honor-followup-to) configuration variable is
set. Using [list-reply](#list-reply) will in this case also make sure
that the reply goes to the mailing list, even if it's not specified in
the list of recipients in the `Mail-Followup-To`.

> **Note**
>
> When header editing is enabled, you can create a `Mail-Followup-To`
> header manually. Mutt will only auto-generate this header if it
> doesn't exist when you send the message.

The other method some mailing list admins use is to generate a
“Reply-To” field which points back to the mailing list address rather
than the author of the message. This can create problems when trying to
reply directly to the author in private, since most mail clients will
automatically reply to the address given in the “Reply-To” field. Mutt
uses the [\$reply\_to](#reply-to) variable to help decide which address
to use. If set to *ask-yes* or *ask-no*, you will be prompted as to
whether or not you would like to use the address given in the “Reply-To”
field, or reply directly to the address given in the “From” field. When
set to *yes*, the “Reply-To” field will be used when present.

You can change or delete the “X-Label:”field within Mutt using the
“edit-label” command, bound to the “y” key by default. This works for
tagged messages, too. While in the edit-label function, pressing the
&lt;complete&gt; binding (TAB, by default) will perform completion
against all labels currently in use.

Lastly, Mutt has the ability to [sort](#sort) the mailbox into
[threads](#threads). A thread is a group of messages which all relate to
the same subject. This is usually organized into a tree-like structure
where a message and all of its replies are represented graphically. If
you've ever used a threaded news client, this is the same concept. It
makes dealing with large volume mailing lists easier because you can
easily delete uninteresting threads and quickly find topics of value.

Keyword Management {#using-keywords}
------------------

Mutt has supported textual labels (usually known as X-Labels after the
header that we use to store them) for many years. Since we initially
added support for X-Labels, however, the larger community has evolved
more common ways of using and managing such labels, often known as
“keywords” or “tags”.

If you are new to Mutt or to using keywords in Mutt, you only need to
know that the &lt;edit-label&gt; binding will edit keywords, and that
you can search for keywords using the `~y` pattern, and use the `%y`
expando to display it in your `$index_format`. You also can sort by
keyword. Keywords that you set will be stored to the `X-Label:`header by
default.

If you've been using X-Labels for a while, things have grown slightly.
Mutt still supports X-Labels much as it has since 2000, but the scope of
this support has expanded to support three additional header-based
techniques for storing keyword metadata on messages:

X-Keywords

:   Informal design; space-delimited keywords

X-Mozilla-Keys

:   Informal design used by Mozilla-based agents; space-delimited
    keywords

Keywords

:   Standardized in RFC2822 (2001); comma-space-delimited keywords

X-Label

:   Mutt-specific design; freeform text (but see
    [\$xlabel\_delimiter](#xlabel-delimiter))

With X-Label, mutt's only notion of a message keyword was the literal
string value of the X-Label header. Under the new, integrated support,
each message may have a list of distinct message keywords. When reading
keywords from one of the headers in the list above, the header value is
split on the indicated delimiter (space or comma-space) for X-Keywords:,
X-Mozilla-Keys:, and Keywords:. By default, X-Label: is parsed as a
single keyword. By setting \$xlabel\_delimiter, you can force splitting
of X-Label: as well.

Two boolean variables control how keywords are saved when writing
messages to a mailbox. The default settings preserve backward
compatibility within mutt completely, but by changing these values you
can transition to more standard keyword storage.
[\$keywords\_legacy](#keywords-legacy), if set, will tell mutt to use
only "legacy" headers -- i.e., `X-Keywords:`, `X-Mozilla-Keys`,
`Keywords`, or `X-Label:`. Keywords will be saved to whichever header
was in use by the message the keyword was read from. If
[\$keywords\_standard](#keywords-standard) is set, keywords will be
saved without exception to the standard `Keywords:`header. (If both are
set, both will be used; if both are unset, legacy headers are used.)
Additionally, [\$xlabel\_delimiter](#xlabel-delimiter) is used to format
the X-Label: header on saves.

To migrate completely to the new standard, unset `$keywords_legacy` and
set `$keywords_standard`, and set `$xlabel_delimiter` either to what you
currently use to delimit keywords in X-Labels, or to “, ”(comma space).

Note that it is common practice to insert `X-Label:`or other keyword
headers from proxmail or other mail filters. This is a useful trick for
categorizing messages en masse as they are delivered to your inbox, and
it is fully compatible with the new keywords code.

Display Munging
---------------

Working within the confines of a console or terminal window, it is often
useful to be able to modify certain information elements in a
non-destructive way -- to change how they display, without changing the
stored value of the information itself. This is especially so of message
subjects, which may often be polluted with extraneous metadata that
either is reproduced elsewhere, or is of secondary interest.

subjectrx
pattern
replacement
unsubjectrx
\*
pattern
`subjectrx` specifies a regular expression “pattern” which, if detected
in a message subject, causes the subject to be replaced with the
“replacement” value. The replacement is subject to substitutions in the
same way as for the [spam](#spam) command: `%L` for the text to the left
of the match, `%R` for text to the right of the match, and `%1` for the
first subgroup in the match (etc). If you simply want to erase the
match, set it to “%L%R”. Any number of `subjectrx` commands may coexist.

Note this well: the “replacement” value replaces the entire subject, not
just the match!

`unsubjectrx` removes a given subjectrx from the substitution list. If
`*`is used as the pattern, all substitutions will be removed.

    # Erase [rt #12345] tags from Request Tracker (RT) e-mails
    subjectrx '\[rt #[0-9]+\] *' '%L%R'
    # Servicedesk is another RT that sends more complex subjects.

    # Keep the ticket number.

    subjectrx '\[servicedesk #([0-9]+)\] ([^.]+)\.([^.]+) - (new|open|pending|update) - ' '%L[#%1] %R'
    # Strip out annoying [listname] prefixes in subjects
    subjectrx '\[[^\]]*\]:? *' '%L%R'

New Mail Detection {#new-mail}
------------------

Mutt supports setups with multiple folders, allowing all of them to be
monitored for new mail (see [Monitoring Incoming Mail](#mailboxes)for
details).

### How New Mail Detection Works {#new-mail-formats}

For Mbox and Mmdf folders, new mail is detected by comparing access
and/or modification times of files: Mutt assumes a folder has new mail
if it wasn't accessed after it was last modified. Utilities like `biff`
or `frm` or any other program which accesses the mailbox might cause
Mutt to never detect new mail for that mailbox if they do not properly
reset the access time. Other possible causes of Mutt not detecting new
mail in these folders are backup tools (updating access times) or
filesystems mounted without access time update support (for Linux
systems, see the `relatime` option).

> **Note**
>
> Contrary to older Mutt releases, it now maintains the new mail status
> of a folder by properly resetting the access time if the folder
> contains at least one message which is neither read, nor deleted, nor
> marked as old.

In cases where new mail detection for Mbox or Mmdf folders appears to be
unreliable, the [\$check\_mbox\_size](#check-mbox-size) option can be
used to make Mutt track and consult file sizes for new mail detection
instead which won't work for size-neutral changes.

New mail for Maildir is assumed if there is one message in the
`new/`subdirectory which is not marked deleted (see
[\$maildir\_trash](#maildir-trash)). For MH folders, a mailbox is
considered having new mail if there's at least one message in the
“unseen” sequence as specified by [\$mh\_seq\_unseen](#mh-seq-unseen).
Optionally, [\$new\_mail\_command](#new-mail-command) can be configured
to execute an external program every time new mail is detected in the
current inbox.

Mutt does not poll POP3 folders for new mail, it only periodically
checks the currently opened folder (if it's a POP3 folder).

For IMAP, by default Mutt uses recent message counts provided by the
server to detect new mail. If the [\$imap\_idle](#imap-idle) option is
set, it'll use the IMAP IDLE extension if advertised by the server.

The [\$mail\_check\_recent](#mail-check-recent) option changes whether
Mutt will notify you of new mail in an already visited mailbox. When set
(the default) it will only notify you of new mail received since the
last time you opened the mailbox. When unset, Mutt will notify you of
any new mail in the mailbox.

### Polling For New Mail {#new-mail-polling}

When in the index menu and being idle (also see [\$timeout](#timeout)),
Mutt periodically checks for new mail in all folders which have been
configured via the `mailboxes` command. The interval depends on the
folder type: for local/IMAP folders it consults
[\$mail\_check](#mail-check) and
[\$pop\_checkinterval](#pop-checkinterval) for POP folders.

Outside the index menu the directory browser supports checking for new
mail using the `<check-new>`function which is unbound by default.
Pressing TAB will bring up a menu showing the files specified by the
`mailboxes` command, and indicate which contain new messages. Mutt will
automatically enter this mode when invoked from the command line with
the `-y` option.

For the pager, index and directory browser menus, Mutt contains the
`<buffy-list>`function (bound to “.”by default) which will print a list
of folders with new mail in the command line at the bottom of the
screen.

For the index, by default Mutt displays the number of mailboxes with new
mail in the status bar, please refer to the
[\$status\_format](#status-format) variable for details.

When changing folders, Mutt fills the prompt with the first folder from
the mailboxes list containing new mail (if any), pressing `<Space>`will
cycle through folders with new mail. The (by default unbound) function
`<next-unread-mailbox>`in the index can be used to immediately open the
next folder with unread mail (if any).

### Calculating Mailbox Message Counts {#calc-mailbox-counts}

If [\$mail\_check\_stats](#mail-check-stats) is set, Mutt will
periodically calculate the unread, flagged, and total message counts for
each mailbox watched by the `mailboxes` command. This calculation takes
place at the same time as new mail polling, but is controlled by a
separate timer:
[\$mail\_check\_stats\_interval](#mail-check-stats-interval).

The sidebar can display these message counts. See
[\$sidebar\_format](#sidebar-format).

Editing Threads
---------------

Mutt has the ability to dynamically restructure threads that are broken
either by misconfigured software or bad behavior from some
correspondents. This allows to clean your mailboxes from these
annoyances which make it hard to follow a discussion.

### Linking Threads {#link-threads}

Some mailers tend to “forget” to correctly set the “In-Reply-To:”and
“References:”headers when replying to a message. This results in broken
discussions because Mutt has not enough information to guess the correct
threading. You can fix this by tagging the reply, then moving to the
parent message and using the `<link-threads>`function (bound to & by
default). The reply will then be connected to this parent message.

You can also connect multiple children at once, tagging them and using
the `<tag-prefix>`command ( “;”) or the [\$auto\_tag](#auto-tag) option.

### Breaking Threads {#break-threads}

On mailing lists, some people are in the bad habit of starting a new
discussion by hitting “reply” to any message from the list and changing
the subject to a totally unrelated one. You can fix such threads by
using the `<break-thread>`function (bound by default to \#), which will
turn the subthread starting from the current message into a whole
different thread.

Delivery Status Notification (DSN) Support {#dsn}
------------------------------------------

RFC1894 defines a set of MIME content types for relaying information
about the status of electronic mail messages. These can be thought of as
“return receipts.”

To support DSN, there are two variables. [\$dsn\_notify](#dsn-notify) is
used to request receipts for different results (such as failed message,
message delivered, etc.). [\$dsn\_return](#dsn-return) requests how much
of your message should be returned with the receipt (headers or full
message).

When using [\$sendmail](#sendmail) for mail delivery, you need to use
either Berkeley sendmail 8.8.x (or greater) a MTA supporting DSN command
line options compatible to Sendmail: The -N and -R options can be used
by the mail client to make requests as to what type of status messages
should be returned. Please consider your MTA documentation whether DSN
is supported.

For SMTP delivery using [\$smtp\_url](#smtp-url), it depends on the
capabilities announced by the server whether Mutt will attempt to
request DSN or not.

Start a WWW Browser on URLs {#urlview}
---------------------------

If a message contains URLs, it is efficient to get a menu with all the
URLs and start a WWW browser on one of them. This functionality is
provided by the external urlview program which can be retrieved at
<ftp://ftp.mutt.org/mutt/contrib/>and the configuration commands:

    macro index \cb |urlview\n
    macro pager \cb |urlview\n

Miscellany {#misc-topics}
----------

This section documents various features that fit nowhere else.

Address normalization

:   Mutt normalizes all e-mail addresses to the simplest form possible.
    If an address contains a realname, the form *Joe User
    &lt;joe@example.com&gt;*is used and the pure e-mail address without
    angle brackets otherwise, i.e. just *joe@example.com*.

    This normalization affects all headers Mutt generates
    including aliases.

Initial folder selection

:   The folder Mutt opens at startup is determined as follows: the
    folder specified in the `$MAIL` environment variable if present.
    Otherwise, the value of `$MAILDIR` is taken into account. If that
    isn't present either, Mutt takes the user's mailbox in the mailspool
    as determined at compile-time (which may also reside in the
    home directory). The [\$spoolfile](#spoolfile) setting overrides
    this selection. Highest priority has the mailbox given with the `-f`
    command line option.

Mutt's MIME Support {#mimesupport}
===================

Quite a bit of effort has been made to make Mutt the premier text-mode
MIME MUA. Every effort has been made to provide the functionality that
the discerning MIME user requires, and the conformance to the standards
wherever possible. When configuring Mutt for MIME, there are two extra
types of configuration files which Mutt uses. One is the `mime.types`
file, which contains the mapping of file extensions to IANA MIME types.
The other is the `mailcap` file, which specifies the external commands
to use for handling specific MIME types.

Using MIME in Mutt {#using-mime}
------------------

### MIME Overview

MIME is short for “Multipurpose Internet Mail Extension” and describes
mechanisms to internationalize and structure mail messages. Before the
introduction of MIME, messages had a single text part and were limited
to us-ascii header and content. With MIME, messages can have attachments
(and even attachments which itself have attachments and thus form a tree
structure), nearly arbitrary characters can be used for sender names,
recipients and subjects.

Besides the handling of non-ascii characters in message headers, to Mutt
the most important aspect of MIME are so-called MIME types. These are
constructed using a *major* and *minor* type separated by a forward
slash. These specify details about the content that follows. Based upon
these, Mutt decides how to handle this part. The most popular major type
is “`text`”with minor types for plain text, HTML and various other
formats. Major types also exist for images, audio, video and of course
general application data (e.g. to separate cryptographically signed data
with a signature, send office documents, and in general arbitrary binary
data). There's also the `multipart` major type which represents the root
of a subtree of MIME parts. A list of supported MIME types can be found
in [table\_title](#supported-mime-types).

MIME also defines a set of encoding schemes for transporting MIME
content over the network: `7bit`, `8bit`, `quoted-printable`, `base64`
and `binary`. There're some rules when to choose what for encoding
headers and/or body (if needed), and Mutt will in general make a good
choice.

Mutt does most of MIME encoding/decoding behind the scenes to form
messages conforming to MIME on the sending side. On reception, it can be
flexibly configured as to how what MIME structure is displayed (and if
it's displayed): these decisions are based on the content's MIME type.
There are three areas/menus in dealing with MIME: the pager (while
viewing a message), the attachment menu and the compose menu.

### Viewing MIME Messages in the Pager {#mime-pager}

When you select a message from the index and view it in the pager, Mutt
decodes as much of a message as possible to a text representation. Mutt
internally supports a number of MIME types, including the `text` major
type (with all minor types), the `message/rfc822`(mail messages) type
and some `multipart` types. In addition, it recognizes a variety of PGP
MIME types, including PGP/MIME and `application/pgp`.

Mutt will denote attachments with a couple lines describing them. These
lines are of the form:

    [-- Attachment #1: Description --]
    [-- Type: text/plain, Encoding: 7bit, Size: 10000 --]

Where the *Description* is the description or filename given for the
attachment, and the *Encoding* is one of the already mentioned content
encodings.

If Mutt cannot deal with a MIME type, it will display a message like:

    [-- image/gif is unsupported (use 'v' to view this part) --]

### The Attachment Menu {#attach-menu}

The default binding for `<view-attachments>`is “v”, which displays the
attachment menu for a message. The attachment menu displays a list of
the attachments in a message. From the attachment menu, you can save,
print, pipe, delete, and view attachments. You can apply these
operations to a group of attachments at once, by tagging the attachments
and by using the `<tag-prefix>`operator. You can also reply to the
current message from this menu, and only the current attachment (or the
attachments tagged) will be quoted in your reply. You can view
attachments as text, or view them using the mailcap viewer definition
(the mailcap mechanism is explained later in detail).

Finally, you can apply the usual message-related functions (like
[`<resend-message>`](#resend-message), and the `<reply>`and
`<forward>`functions) to attachments of type `message/rfc822`.

See table [table\_title](#tab-attachment-bindings)for all available
functions.

### The Compose Menu {#compose-menu}

The compose menu is the menu you see before you send a message. It
allows you to edit the recipient list, the subject, and other aspects of
your message. It also contains a list of the attachments of your
message, including the main body. From this menu, you can print, copy,
filter, pipe, edit, compose, review, and rename an attachment or a list
of tagged attachments. You can also modifying the attachment
information, notably the type, encoding and description.

Attachments appear as follows by default:

    - 1 [text/plain, 7bit, 1K]           /tmp/mutt-euler-8082-0 <no description>
      2 [applica/x-gunzip, base64, 422K] ~/src/mutt-0.85.tar.gz <no description>

The “-”denotes that Mutt will delete the file after sending (or
postponing, or canceling) the message. It can be toggled with the
`<toggle-unlink>`command (default: u). The next field is the MIME
content-type, and can be changed with the `<edit-type>`command (default:
\^T). The next field is the encoding for the attachment, which allows a
binary message to be encoded for transmission on 7bit links. It can be
changed with the `<edit-encoding>`command (default: \^E). The next field
is the size of the attachment, rounded to kilobytes or megabytes. The
next field is the filename, which can be changed with the
`<rename-file>`command (default: R). The final field is the description
of the attachment, and can be changed with the
`<edit-description>`command (default: d). See
[\$attach\_format](#attach-format) for a full list of available expandos
to format this display to your needs.

MIME Type Configuration with `mime.types` {#mime-types}
-----------------------------------------

To get most out of MIME, it's important that a MIME part's content type
matches the content as closely as possible so that the recipient's
client can automatically select the right viewer for the content.
However, there's no reliable for Mutt to know how to detect every
possible file type. Instead, it uses a simple plain text mapping file
that specifies what file extension corresponds to what MIME type. This
file is called `mime.types`.

When you add an attachment to your mail message, Mutt searches your
personal `mime.types` file at `$HOME/.mime.types`, and then the system
`mime.types` file at `/usr/local/share/mutt/mime.types` or
`/etc/mime.types`

Each line starts with the full MIME type, followed by a space and
space-separated list of file extensions. For example you could use:

    application/postscript          ps eps
    application/pgp                 pgp
    audio/x-aiff                    aif aifc aiff

A sample `mime.types` file comes with the Mutt distribution, and should
contain most of the MIME types you are likely to use.

If Mutt can not determine the MIME type by the extension of the file you
attach, it will look at the file. If the file is free of binary
information, Mutt will assume that the file is plain text, and mark it
as `text/plain`. If the file contains binary information, then Mutt will
mark it as `application/octet-stream`. You can change the MIME type that
Mutt assigns to an attachment by using the `<edit-type>`command from the
compose menu (default: \^T), see
[table\_title](#supported-mime-types)for supported major types. Mutt
recognizes all of these if the appropriate entry is found in the
`mime.types` file. Non-recognized mime types should only be used if the
recipient of the message is likely to be expecting such attachments.

  MIME major type   Standard   Description
  ----------------- ---------- -------------------------------------------
  `application`     yes        General application data
  `audio`           yes        Audio data
  `image`           yes        Image data
  `message`         yes        Mail messages, message status information
  `model`           yes        VRML and other modeling data
  `multipart`       yes        Container for other MIME parts
  `text`            yes        Text data
  `video`           yes        Video data
  `chemical`        no         Mostly molecular data

  : Supported MIME types

MIME types are not arbitrary, they need to be assigned by
[IANA](http://www.iana.org/assignments/media-types/).

MIME Viewer Configuration with Mailcap {#mailcap}
--------------------------------------

Mutt supports RFC 1524 MIME Configuration, in particular the Unix
specific format specified in Appendix A of RFC 1524. This file format is
commonly referred to as the “mailcap” format. Many MIME compliant
programs utilize the mailcap format, allowing you to specify handling
for all MIME types in one place for all programs. Programs known to use
this format include Firefox, lynx and metamail.

In order to handle various MIME types that Mutt doesn't have built-in
support for, it parses a series of external configuration files to find
an external handler. The default search string for these files is a
colon delimited list containing the following files:

1.  `$HOME/.mailcap`

2.  `$PKGDATADIR/mailcap`

3.  `$SYSCONFDIR/mailcap`

4.  `/etc/mailcap`

5.  `/usr/etc/mailcap`

6.  `/usr/local/etc/mailcap`

where `$HOME` is your home directory. The `$PKGDATADIR` and the
`$SYSCONFDIR` directories depend on where Mutt is installed: the former
is the default for shared data, the latter for system configuration
files.

The default search path can be obtained by running the following
command:

    mutt -nF /dev/null -Q mailcap_path

In particular, the metamail distribution will install a mailcap file,
usually as `/usr/local/etc/mailcap`, which contains some baseline
entries.

### The Basics of the Mailcap File {#mailcap-basics}

A mailcap file consists of a series of lines which are comments, blank,
or definitions.

A comment line consists of a \# character followed by anything you want.

A blank line is blank.

A definition line consists of a content type, a view command, and any
number of optional fields. Each field of a definition line is divided by
a semicolon “;”character.

The content type is specified in the MIME standard “type/subtype”
notation. For example, `text/plain`, `text/html`, `image/gif`, etc. In
addition, the mailcap format includes two formats for wildcards, one
using the special “\*”subtype, the other is the implicit wild, where you
only include the major type. For example, `image/*`, or `video` will
match all image types and video types, respectively.

The view command is a Unix command for viewing the type specified. There
are two different types of commands supported. The default is to send
the body of the MIME message to the command on stdin. You can change
this behavior by using `%s` as a parameter to your view command. This
will cause Mutt to save the body of the MIME message to a temporary
file, and then call the view command with the `%s` replaced by the name
of the temporary file. In both cases, Mutt will turn over the terminal
to the view program until the program quits, at which time Mutt will
remove the temporary file if it exists. This means that mailcap does
*not* work out of the box with programs which detach themselves from the
terminal right after starting, like `open` on Mac OS X. In order to
nevertheless use these programs with mailcap, you probably need custom
shell scripts.

So, in the simplest form, you can send a `text/plain` message to the
external pager more on standard input:

    text/plain; more

Or, you could send the message as a file:

    text/plain; more %s

Perhaps you would like to use lynx to interactively view a `text/html`
message:

    text/html; lynx %s

In this case, lynx does not support viewing a file from standard input,
so you must use the `%s` syntax.

> **Note**
>
> *Some older versions of lynx contain a bug where they will check the
> mailcap file for a viewer for `text/html`. They will find the line
> which calls lynx, and run it. This causes lynx to continuously spawn
> itself to view the object.*

On the other hand, maybe you don't want to use lynx interactively, you
just want to have it convert the `text/html` to `text/plain`, then you
can use:

    text/html; lynx -dump %s | more

Perhaps you wish to use lynx to view `text/html` files, and a pager on
all other text formats, then you would use the following:

    text/html; lynx %s
    text/*; more

### Secure Use of Mailcap {#secure-mailcap}

The interpretation of shell meta-characters embedded in MIME parameters
can lead to security problems in general. Mutt tries to quote parameters
in expansion of `%s` syntaxes properly, and avoids risky characters by
substituting them, see the [\$mailcap\_sanitize](#mailcap-sanitize)
variable.

Although Mutt's procedures to invoke programs with mailcap seem to be
safe, there are other applications parsing mailcap, maybe taking less
care of it. Therefore you should pay attention to the following rules:

*Keep the %-expandos away from shell quoting.*Don't quote them with
single or double quotes. Mutt does this for you, the right way, as
should any other program which interprets mailcap. Don't put them into
backtick expansions. Be highly careful with evil statements, and avoid
them if possible at all. Trying to fix broken behavior with quotes
introduces new leaks — there is no alternative to correct quoting in the
first place.

If you have to use the %-expandos' values in context where you need
quoting or backtick expansions, put that value into a shell variable and
reference the shell variable where necessary, as in the following
example (using `$charset` inside the backtick expansion is safe, since
it is not itself subject to any further expansion):

    text/test-mailcap-bug; cat %s; copiousoutput; test=charset=%{charset} \
            && test "`echo $charset | tr '[A-Z]' '[a-z]'`" != iso-8859-1

### Advanced Mailcap Usage {#advanced-mailcap}

#### Optional Fields {#optional-mailcap-fields}

In addition to the required content-type and view command fields, you
can add semi-colon “;”separated fields to set flags and other options.
Mutt recognizes the following optional fields:

copiousoutput

:   This flag tells Mutt that the command passes possibly large amounts
    of text on standard output. This causes Mutt to invoke a pager
    (either the internal pager or the external pager defined by the
    pager variable) on the output of the view command. Without this
    flag, Mutt assumes that the command is interactive. One could use
    this to replace the pipe to `more` in the `lynx -dump` example in
    the Basic section:

        text/html; lynx -dump %s ; copiousoutput

    This will cause lynx to format the `text/html` output as
    `text/plain` and Mutt will use your standard pager to display
    the results.

    Mutt will set the `COLUMNS` environment variable to the width of
    the pager. Some programs make use of this environment
    variable automatically. Others provide a command line argument that
    can use this to set the output width:

        text/html; lynx -dump -width ${COLUMNS:-80} %s; copiousoutput

    Note that when using the built-in pager, *only* entries with this
    flag will be considered a handler for a MIME type — all other
    entries will be ignored.

needsterminal

:   Mutt uses this flag when viewing attachments with
    [`auto_view`](#auto-view), in order to decide whether it should
    honor the setting of the [\$wait\_key](#wait-key) variable or not.
    When an attachment is viewed using an interactive program, and the
    corresponding mailcap entry has a *needsterminal* flag, Mutt will
    use [\$wait\_key](#wait-key) and the exit status of the program to
    decide if it will ask you to press a key after the external program
    has exited. In all other situations it will not prompt you for
    a key.

compose=&lt;command&gt;

:   This flag specifies the command to use to create a new attachment of
    a specific MIME type. Mutt supports this from the compose menu.

composetyped=&lt;command&gt;

:   This flag specifies the command to use to create a new attachment of
    a specific MIME type. This command differs from the compose command
    in that Mutt will expect standard MIME headers on the data. This can
    be used to specify parameters, filename, description, etc. for a
    new attachment. Mutt supports this from the compose menu.

print=&lt;command&gt;

:   This flag specifies the command to use to print a specific
    MIME type. Mutt supports this from the attachment and compose menus.

edit=&lt;command&gt;

:   This flag specifies the command to use to edit a specific MIME type.
    Mutt supports this from the compose menu, and also uses it to
    compose new attachments. Mutt will default to the defined
    [\$editor](#editor) for text attachments.

nametemplate=&lt;template&gt;

:   This field specifies the format for the file denoted by `%s` in the
    command fields. Certain programs will require a certain file
    extension, for instance, to correctly view a file. For instance,
    lynx will only interpret a file as `text/html` if the file ends in
    `.html`. So, you would specify lynx as a `text/html` viewer with a
    line in the mailcap file like:

        text/html; lynx %s; nametemplate=%s.html

test=&lt;command&gt;

:   This field specifies a command to run to test whether this mailcap
    entry should be used. The command is defined with the command
    expansion rules defined in the next section. If the command returns
    0, then the test passed, and Mutt uses this entry. If the command
    returns non-zero, then the test failed, and Mutt continues searching
    for the right entry. Note that the content-type must match before
    Mutt performs the test. For example:

        text/html; firefox -remote 'openURL(%s)' ; test=RunningX
        text/html; lynx %s

    In this example, Mutt will run the program `RunningX` which will
    return 0 if the X Window manager is running, and non-zero if
    it isn't. If `RunningX` returns 0, then Mutt will run firefox to
    display the `text/html` object. If RunningX doesn't return 0, then
    Mutt will go on to the next entry and use lynx to display the
    `text/html` object.

#### Search Order {#mailcap-search-order}

When searching for an entry in the mailcap file, Mutt will search for
the most useful entry for its purpose. For instance, if you are
attempting to print an `image/gif`, and you have the following entries
in your mailcap file, Mutt will search for an entry with the print
command:

    image/*;        xv %s
    image/gif;      ; print= anytopnm %s | pnmtops | lpr; \
                    nametemplate=%s.gif

Mutt will skip the `image/*`entry and use the `image/gif` entry with the
print command.

In addition, you can use this with [`auto_view`](#auto-view)to denote
two commands for viewing an attachment, one to be viewed automatically,
the other to be viewed interactively from the attachment menu using the
`<view-mailcap>`function (bound to “m” by default). In addition, you can
then use the test feature to determine which viewer to use interactively
depending on your environment.

    text/html;      firefox -remote 'openURL(%s)' ; test=RunningX
    text/html;      lynx %s; nametemplate=%s.html
    text/html;      lynx -dump %s; nametemplate=%s.html; copiousoutput

For [`auto_view`](#auto-view), Mutt will choose the third entry because
of the `copiousoutput` tag. For interactive viewing, Mutt will run the
program `RunningX` to determine if it should use the first entry. If the
program returns non-zero, Mutt will use the second entry for interactive
viewing. The last entry is for inline display in the pager and the
`<view-attach>`function in the attachment menu.

Entries with the `copiousoutput` tag should always be specified as the
last one per type. For non-interactive use, the last entry will then
actually be the first matching one with the tag set. For non-interactive
use, only `copiousoutput`-tagged entries are considered. For interactive
use, Mutt ignores this tag and treats all entries equally. Therefore, if
not specified last, all following entries without this tag would never
be considered for `<view-attach>`because the `copiousoutput` before them
matched already.

#### Command Expansion {#mailcap-command-expansion}

The various commands defined in the mailcap files are passed to the
`/bin/sh` shell using the `system(3)`function. Before the command is
passed to `/bin/sh -c`, it is parsed to expand various special
parameters with information from Mutt. The keywords Mutt expands are:

%s

:   As seen in the basic mailcap section, this variable is expanded to a
    filename specified by the calling program. This file contains the
    body of the message to view/print/edit or where the composing
    program should place the results of composition. In addition, the
    use of this keyword causes Mutt to not pass the body of the message
    to the view/print/edit program on stdin.

%t

:   Mutt will expand `%t` to the text representation of the content type
    of the message in the same form as the first parameter of the
    mailcap definition line, i.e. `text/html` or `image/gif`.

%{&lt;parameter&gt;}

:   Mutt will expand this to the value of the specified parameter from
    the Content-Type: line of the mail message. For instance, if your
    mail message contains:

        Content-Type: text/plain; charset=iso-8859-1

    then Mutt will expand `%{charset}`to “iso-8859-1”. The default
    metamail mailcap file uses this feature to test the charset to spawn
    an xterm using the right charset to view the message.

\\%

:   This will be replaced by a literal `%`.

Mutt does not currently support the `%F` and `%n` keywords specified in
RFC 1524. The main purpose of these parameters is for multipart
messages, which is handled internally by Mutt.

### Example Mailcap Files {#mailcap-example}

This mailcap file is fairly simple and standard:

    # I'm always running X :)
    video/*;        xanim %s > /dev/null
    image/*;        xv %s > /dev/null
    # I'm always running firefox (if my computer had more memory, maybe)
    text/html;      firefox -remote 'openURL(%s)'

This mailcap file shows quite a number of examples:

    # Use xanim to view all videos   Xanim produces a header on startup,
    # send that to /dev/null so I don't see it
    video/*;        xanim %s > /dev/null
    # Send html to a running firefox by remote
    text/html;      firefox -remote 'openURL(%s)'; test=RunningFirefox
    # If I'm not running firefox but I am running X, start firefox on the
    # object
    text/html;      firefox %s; test=RunningX
    # Else use lynx to view it as text
    text/html;      lynx %s
    # This version would convert the text/html to text/plain
    text/html;      lynx -dump %s; copiousoutput
    # I use enscript to print text in two columns to a page
    text/*;         more %s; print=enscript -2Gr %s
    # Firefox adds a flag to tell itself to view jpegs internally
    image/jpeg;xv %s; x-mozilla-flags=internal
    # Use xv to view images if I'm running X
    # In addition, this uses the \ to extend the line and set my editor
    # for images
    image/*;xv %s; test=RunningX; \
            edit=xpaint %s
    # Convert images to text using the netpbm tools
    image/*;  (anytopnm %s | pnmscale -xysize 80 46 | ppmtopgm | pgmtopbm |
    pbmtoascii -1x2 ) 2>&1 ; copiousoutput
    # Send excel spreadsheets to my NT box
    application/ms-excel; open.pl %s

MIME Autoview {#auto-view}
-------------

Usage:

auto\_view
mimetype
mimetype
unauto\_view
\*
mimetype
In addition to explicitly telling Mutt to view an attachment with the
MIME viewer defined in the mailcap file from the attachments menu, Mutt
has support for automatically viewing MIME attachments while in the
pager.

For this to work, you must define a viewer in the mailcap file which
uses the `copiousoutput` option to denote that it is non-interactive.
Usually, you also use the entry to convert the attachment to a text
representation which you can view in the pager.

You then use the `auto_view` configuration command to list the
content-types that you wish to view automatically. For instance, if you
set it to:

    auto_view text/html application/x-gunzip \
      application/postscript image/gif application/x-tar-gz

...Mutt would try to find corresponding entries for rendering
attachments of these types as text. A corresponding mailcap could look
like:

    text/html;      lynx -dump %s; copiousoutput; nametemplate=%s.html
    image/*;        anytopnm %s | pnmscale -xsize 80 -ysize 50 | ppmtopgm | \
                    pgmtopbm | pbmtoascii ; copiousoutput
    application/x-gunzip;   gzcat; copiousoutput
    application/x-tar-gz; gunzip -c %s | tar -tf - ; copiousoutput
    application/postscript; ps2ascii %s; copiousoutput

`unauto_view` can be used to remove previous entries from the
`auto_view` list. This can be used with
[`message-hook`](#message-hook)to autoview messages based on size, etc.
“`unauto_view`\*”will remove all previous entries.

MIME Multipart/Alternative {#alternative-order}
--------------------------

The `multipart/alternative` container type only has child MIME parts
which represent the same content in an alternative way. This is often
used to send HTML messages which contain an alternative plain text
representation.

Mutt has some heuristics for determining which attachment of a
`multipart/alternative` type to display:

1.  First, Mutt will check the `alternative_order` list to determine if
    one of the available types is preferred. It consists of a number of
    MIME types in order, including support for implicit and
    explicit wildcards. For example:

        alternative_order text/enriched text/plain text \
          application/postscript image/*

2.  Next, Mutt will check if any of the types have a defined
    [`auto_view`](#auto-view), and use that.

3.  Failing that, Mutt will look for any text type.

4.  As a last attempt, Mutt will look for any type it knows how
    to handle.

To remove a MIME type from the `alternative_order` list, use the
`unalternative_order` command.

Attachment Searching and Counting {#attachments}
---------------------------------

If you ever lose track of attachments in your mailboxes, Mutt's
attachment-counting and -searching support might be for you. You can
make your message index display the number of qualifying attachments in
each message, or search for messages by attachment count. You also can
configure what kinds of attachments qualify for this feature with the
`attachments` and `unattachments` commands.

In order to provide this information, Mutt needs to fully MIME-parse all
messages affected first. This can slow down operation especially for
remote mail folders such as IMAP because all messages have to be
downloaded first regardless whether the user really wants to view them
or not though using [Body Caching](#body-caching)usually means to
download the message just once.

The syntax is:

attachments
{ + | - }disposition
mime-type
unattachments
{ + | - }disposition
mime-type
attachments
?
*disposition* is the attachment's Content-Disposition type — either
`inline` or `attachment`. You can abbreviate this to `I` or `A`.

Disposition is prefixed by either a “+”symbol or a “-”symbol. If it's a
“+”, you're saying that you want to allow this disposition and MIME type
to qualify. If it's a “-”, you're saying that this disposition and MIME
type is an exception to previous “+”rules. There are examples below of
how this is useful.

*mime-type* is the MIME type of the attachment you want the command to
affect. A MIME type is always of the format `major/minor`, where `major`
describes the broad category of document you're looking at, and `minor`
describes the specific type within that category. The major part of
mime-type must be literal text (or the special token “`*`”), but the
minor part may be a regular expression. (Therefore, “`*/.*`”matches any
MIME type.)

The MIME types you give to the `attachments` directive are a kind of
pattern. When you use the `attachments` directive, the patterns you
specify are added to a list. When you use `unattachments`, the pattern
is removed from the list. The patterns are not expanded and matched to
specific MIME types at this time — they're just text in a list. They're
only matched when actually evaluating a message.

Some examples might help to illustrate. The examples that are not
commented out define the default configuration of the lists.


    # Removing a pattern from a list removes that pattern literally. It
    # does not remove any type matching the pattern.

    #
    #  attachments   +A */.*
    #  attachments   +A image/jpeg
    #  unattachments +A */.*
    #
    # This leaves "attached" image/jpeg files on the allowed attachments
    # list. It does not remove all items, as you might expect, because the
    # second */.* is not a matching expression at this time.

    #
    # Remember: "unattachments" only undoes what "attachments" has done!

    # It does not trigger any matching on actual messages.

    # Qualify any MIME part with an "attachment" disposition, EXCEPT for
    # text/x-vcard and application/pgp parts. (PGP parts are already known
    # to mutt, and can be searched for with ~g, ~G, and ~k.)
    #
    # I've added x-pkcs7 to this, since it functions (for S/MIME)
    # analogously to PGP signature attachments. S/MIME isn't supported
    # in a stock mutt build, but we can still treat it specially here.

    #

    attachments   +A */.*
    attachments   -A text/x-vcard application/pgp.*
    attachments   -A application/x-pkcs7-.*

    # Discount all MIME parts with an "inline" disposition, unless they're
    # text/plain. (Why inline a text/plain part unless it's external to the
    # message flow?)

    attachments   +I text/plain

    # These two lines make Mutt qualify MIME containers.  (So, for example,
    # a message/rfc822 forward will count as an attachment.)  The first
    # line is unnecessary if you already have "attach-allow */.*", of
    # course.  These are off by default!  The MIME elements contained
    # within a message/* or multipart/* are still examined, even if the
    # containers themselves don't qualify.

    #attachments  +A message/.* multipart/.*
    #attachments  +I message/.* multipart/.*

    ## You probably don't really care to know about deleted attachments.
    attachments   -A message/external-body
    attachments   -I message/external-body

Entering the command “`attachments`?”as a command will list your current
settings in Muttrc format, so that it can be pasted elsewhere.

MIME Lookup
-----------

Usage:

mime\_lookup
mimetype
mimetype
unmime\_lookup
\*
mimetype
Mutt's `mime_lookup` list specifies a list of MIME types that should
*not* be treated according to their mailcap entry. This option is
designed to deal with binary types such as `application/octet-stream`.
When an attachment's MIME type is listed in `mime_lookup`, then the
extension of the filename will be compared to the list of extensions in
the `mime.types` file. The MIME type associated with this extension will
then be used to process the attachment according to the rules in the
mailcap file and according to any other configuration options (such as
`auto_view`) specified. Common usage would be:

    mime_lookup application/octet-stream application/X-Lotus-Manuscript

In addition, the `unmime_lookup` command may be used to disable this
feature for any particular MIME type if it had been set, for example, in
a global `.muttrc`.

Optional Features {#optionalfeatures}
=================

General Notes {#optionalfeatures-notes}
-------------

### Enabling/Disabling Features {#compile-time-features}

Mutt supports several of optional features which can be enabled or
disabled at compile-time by giving the *configure* script certain
arguments. These are listed in the “Optional features” section of the
*configure --help* output.

Which features are enabled or disabled can later be determined from the
output of `mutt -v`. If a compile option starts with “+”it is enabled
and disabled if prefixed with “-”. For example, if Mutt was compiled
using GnuTLS for encrypted communication instead of OpenSSL, `mutt -v`
would contain:

    -openssl +gnutls

### URL Syntax

Mutt optionally supports the IMAP, POP3 and SMTP protocols which require
to access servers using URLs. The canonical syntax for specifying URLs
in Mutt is (an item enclosed in `[]`means it is optional and may be
omitted):

    proto[s]://[username[:password]@]server[:port][/path]

*proto* is the communication protocol: `imap` for IMAP, `pop` for POP3
and `smtp` for SMTP. If “s” for “secure communication” is appended, Mutt
will attempt to establish an encrypted communication using SSL or TLS.

Since all protocols supported by Mutt support/require authentication,
login credentials may be specified in the URL. This has the advantage
that multiple IMAP, POP3 or SMTP servers may be specified (which isn't
possible using, for example, [\$imap\_user](#imap-user)). The username
may contain the “@”symbol being used by many mail systems as part of the
login name. The special characters “/”( `%2F`), “:”( `%3A`) and “%”(
`%25`) have to be URL-encoded in usernames using the `%`-notation.

A password can be given, too but is not recommended if the URL is
specified in a configuration file on disk.

If no port number is given, Mutt will use the system's default for the
given protocol (usually consulting `/etc/services`).

The optional path is only relevant for IMAP and ignored elsewhere.

    pops://host/
    imaps://user@host/INBOX/Sent
    smtp://user@host:587/

SSL/TLS Support {#ssl}
---------------

If Mutt is compiled with IMAP, POP3 and/or SMTP support, it can also be
compiled with support for SSL or TLS using either OpenSSL or GnuTLS ( by
running the *configure* script with the *--enable-ssl=...*option for
OpenSSL or *--enable-gnutls=...*for GnuTLS). Mutt can then attempt to
encrypt communication with remote servers if these protocols are
suffixed with “s” for “secure communication”.

POP3 Support {#pop}
------------

Mutt has POP3 support and has the ability to work with mailboxes located
on a remote POP3 server and fetch mail for local browsing.

Remote POP3 servers can be accessed using URLs with the `pop` protocol
for unencrypted and `pops` for encrypted communication, see
[URL Syntax](#url-syntax)for details.

Polling for new mail is more expensive over POP3 than locally. For this
reason the frequency at which Mutt will check for mail remotely can be
controlled by the [\$pop\_checkinterval](#pop-checkinterval) variable,
which defaults to every 60 seconds.

POP is read-only which doesn't allow for some features like editing
messages or changing flags. However, using
[Header Caching](#header-caching)and [Body Caching](#body-caching)Mutt
simulates the new/old/read flags as well as flagged and replied. Mutt
applies some logic on top of remote messages but cannot change them so
that modifications of flags are lost when messages are downloaded from
the POP server (either by Mutt or other tools).

Another way to access your POP3 mail is the `<fetch-mail>`function
(default: G). It allows to connect to [\$pop\_host](#pop-host), fetch
all your new mail and place it in the local [\$spoolfile](#spoolfile).
After this point, Mutt runs exactly as if the mail had always been
local.

> **Note**
>
> If you only need to fetch all messages to a local mailbox you should
> consider using a specialized program, such as `fetchmail(1)`,
> `getmail(1)`or similar.

IMAP Support {#imap}
------------

Mutt has IMAP support and has the ability to work with folders located
on a remote IMAP server.

You can access the remote inbox by selecting the folder by its URL (see
[URL Syntax](#url-syntax)for details) using the `imap` or `imaps`
protocol. Alternatively, a pine-compatible notation is also supported,
i.e. `
      {[username@]imapserver[:port][/ssl]}path/to/folder`

Note that not all servers use “/”as the hierarchy separator. Mutt should
correctly notice which separator is being used by the server and convert
paths accordingly.

When browsing folders on an IMAP server, you can toggle whether to look
at only the folders you are subscribed to, or all folders with the
*toggle-subscribed* command. See also the
[\$imap\_list\_subscribed](#imap-list-subscribed) variable.

Polling for new mail on an IMAP server can cause noticeable delays. So,
you'll want to carefully tune the [\$mail\_check](#mail-check) and
[\$timeout](#timeout) variables. Reasonable values are:

    set mail_check=90
    set timeout=15

with relatively good results even over slow modem lines.

> **Note**
>
> Note that if you are using mbox as the mail store on UW servers prior
> to v12.250, the server has been reported to disconnect a client if
> another client selects the same folder.

### The IMAP Folder Browser {#imap-browser}

As of version 1.2, Mutt supports browsing mailboxes on an IMAP server.
This is mostly the same as the local file browser, with the following
differences:

-   In lieu of file permissions, Mutt displays the string “IMAP”,
    possibly followed by the symbol “+”, indicating that the entry
    contains both messages and subfolders. On Cyrus-like servers folders
    will often contain both messages and subfolders.

-   For the case where an entry can contain both messages and
    subfolders, the selection key (bound to `enter` by default) will
    choose to descend into the subfolder view. If you wish to view the
    messages in that folder, you must use `view-file` instead (bound to
    `space` by default).

-   You can create, delete and rename mailboxes with the
    `<create-mailbox>`, `<delete-mailbox>`, and
    `<rename-mailbox>`commands (default bindings: `C`, `d` and
    `r`, respectively). You may also `<subscribe>`and `<unsubscribe>`to
    mailboxes (normally these are bound to `s` and `u`, respectively).

### Authentication {#imap-authentication}

Mutt supports four authentication methods with IMAP servers: SASL,
GSSAPI, CRAM-MD5, and LOGIN. There is also support for the
pseudo-protocol ANONYMOUS, which allows you to log in to a public IMAP
server without having an account. To use ANONYMOUS, simply make your
username blank or “anonymous”.

SASL is a special super-authenticator, which selects among several
protocols (including GSSAPI, CRAM-MD5, ANONYMOUS, and DIGEST-MD5) the
most secure method available on your host and the server. Using some of
these methods (including DIGEST-MD5 and possibly GSSAPI), your entire
session will be encrypted and invisible to those teeming network snoops.
It is the best option if you have it. To use it, you must have the Cyrus
SASL library installed on your system and compile Mutt with the
*--with-sasl* flag.

Mutt will try whichever methods are compiled in and available on the
server, in the following order: SASL, ANONYMOUS, GSSAPI, CRAM-MD5,
LOGIN.

There are a few variables which control authentication:

-   [\$imap\_user](#imap-user)- controls the username under which you
    request authentication on the IMAP server, for all authenticators.
    This is overridden by an explicit username in the mailbox path (i.e.
    by using a mailbox name of the form `{user@host}`).

-   [\$imap\_pass](#imap-pass)- a password which you may preset, used by
    all authentication methods where a password is needed.

-   [\$imap\_authenticators](#imap-authenticators)- a colon-delimited
    list of IMAP authentication methods to try, in the order you wish to
    try them. If specified, this overrides Mutt's default (attempt
    everything, in the order listed above).

SMTP Support {#smtp}
------------

Besides supporting traditional mail delivery through a
sendmail-compatible program, Mutt supports delivery through SMTP.

If the configuration variable [\$smtp\_url](#smtp-url) is set, Mutt will
contact the given SMTP server to deliver messages; if it is unset, Mutt
will use the program specified by [\$sendmail](#sendmail).

For details on the URL syntax, please see [URL Syntax](#url-syntax).

The built-in SMTP support supports encryption (the `smtps` protocol
using SSL or TLS) as well as SMTP authentication using SASL. The
authentication mechanisms for SASL are specified in
[\$smtp\_authenticators](#smtp-authenticators) defaulting to an empty
list which makes Mutt try all available methods from most-secure to
least-secure.

Managing Multiple Accounts {#account-hook}
--------------------------

Usage:

account-hook
regexp
command
If you happen to have accounts on multiple IMAP, POP and/or SMTP
servers, you may find managing all the authentication settings
inconvenient and error-prone. The [`account-hook`](#account-hook)command
may help. This hook works like [`folder-hook`](#folder-hook)but is
invoked whenever Mutt needs to access a remote mailbox (including inside
the folder browser), not just when you open the mailbox. This includes
(for example) polling for new mail, storing Fcc messages and saving
messages to a folder. As a consequence,
[`account-hook`](#account-hook)should only be used to set
connection-related settings such as passwords or tunnel commands but not
settings such as sender address or name (because in general it should be
considered unpredictable which [`account-hook`](#account-hook)was last
used).

Some examples:

    account-hook . 'unset imap_user; unset imap_pass; unset tunnel'
    account-hook imap://host1/ 'set imap_user=me1 imap_pass=foo'
    account-hook imap://host2/ 'set tunnel="ssh host2 /usr/libexec/imapd"'
    account-hook smtp://user@host3/ 'set tunnel="ssh host3 /usr/libexec/smtpd"'

To manage multiple accounts with, for example, different values of
[\$record](#record) or sender addresses,
[`folder-hook`](#folder-hook)has to be be used together with the
[`mailboxes`](#mailboxes)command.

    mailboxes imap://user@host1/INBOX
    folder-hook imap://user@host1/ 'set folder=imap://host1/ ; set record=+INBOX/Sent'
    mailboxes imap://user@host2/INBOX
    folder-hook imap://user@host2/ 'set folder=imap://host2/ ; set record=+INBOX/Sent'

In example [example\_title](#ex-multiaccount)the folders are defined
using [`mailboxes`](#mailboxes)so Mutt polls them for new mail. Each
[`folder-hook`](#folder-hook)triggers when one mailbox below each IMAP
account is opened and sets [\$folder](#folder) to the account's root
folder. Next, it sets [\$record](#record) to the *INBOX/Sent* folder
below the newly set [\$folder](#folder). Please notice that the value
the “+” [mailbox shortcut](#shortcuts) refers to depends on the
*current* value of [\$folder](#folder) and therefore has to be set
separately per account. Setting other values like [\$from](#from) or
[\$signature](#signature) is analogous to setting [\$record](#record).

Local Caching {#caching}
-------------

Mutt contains two types of local caching: *(1)*the so-called “header
caching” and *(2)*the so-called “body caching” which are both described
in this section.

Header caching is optional as it depends on external libraries, body
caching is always enabled if Mutt is compiled with POP and/or IMAP
support as these use it (body caching requires no external library).

### Header Caching

Mutt provides optional support for caching message headers for the
following types of folders: IMAP, POP, Maildir and MH. Header caching
greatly speeds up opening large folders because for remote folders,
headers usually only need to be downloaded once. For Maildir and MH,
reading the headers from a single file is much faster than looking at
possibly thousands of single files (since Maildir and MH use one file
per message.)

Header caching can be enabled by configuring one of the database
backends. One of tokyocabinet, kyotocabinet, qdbm, gdbm, lmdb or bdb.

If enabled, [\$header\_cache](#header-cache) can be used to either point
to a file or a directory. If set to point to a file, one database file
for all folders will be used (which may result in lower performance),
but one file per folder if it points to a directory.

Additionally, [\$header\_cache\_backend](#header-cache-backend) can be
used to specify which backend to use. The list of available backends can
be specified at configure time with a set of --with-&lt;backend&gt;
options. Currently, the following backends are supported: tokyocabinet,
kyotocabinet, qdbm, gdbm, bdb, lmdb.

### Body Caching

Both cache methods can be combined using the same directory for storage
(and for IMAP/POP even provide meaningful file names) which simplifies
manual maintenance tasks.

In addition to caching message headers only, Mutt can also cache whole
message bodies. This results in faster display of messages for POP and
IMAP folders because messages usually have to be downloaded only once.

For configuration, the variable [\$message\_cachedir](#message-cachedir)
must point to a directory. There, Mutt will create a hierarchy of
subdirectories named like the account and mailbox path the cache is for.

### Cache Directories {#cache-dirs}

For using both, header and body caching,
[\$header\_cache](#header-cache) and
[\$message\_cachedir](#message-cachedir) can be safely set to the same
value.

In a header or body cache directory, Mutt creates a directory hierarchy
named like: `proto:user@hostname` where `proto` is either “pop” or
“imap.”Within there, for each folder, Mutt stores messages in single
files and header caches in files with the “.hcache” extension. All files
can be removed as needed if the consumed disk space becomes an issue as
Mutt will silently fetch missing items again. Pathnames are always
stored in UTF-8 encoding.

For Maildir and MH, the header cache files are named after the MD5
checksum of the path.

### Maintenance {#maint-cache}

Mutt does not (yet) support maintenance features for header cache
database files so that files have to be removed in case they grow too
big. It depends on the database library used for header caching whether
disk space freed by removing messages is re-used.

For body caches, Mutt can keep the local cache in sync with the remote
mailbox if the [\$message\_cache\_clean](#message-cache-clean) variable
is set. Cleaning means to remove messages from the cache which are no
longer present in the mailbox which only happens when other mail clients
or instances of Mutt using a different body cache location delete
messages (Mutt itself removes deleted messages from the cache when
syncing a mailbox). As cleaning can take a noticeable amount of time, it
should not be set in general but only occasionally.

Sending Anonymous Messages via Mixmaster {#sending-mixmaster}
----------------------------------------

You may also have compiled Mutt to co-operate with Mixmaster, an
anonymous remailer. Mixmaster permits you to send your messages
anonymously using a chain of remailers. Mixmaster support in Mutt is for
mixmaster version 2.04 or later.

To use it, you'll have to obey certain restrictions. Most important, you
cannot use the `Cc` and `Bcc` headers. To tell Mutt to use mixmaster,
you have to select a remailer chain, using the mix function on the
compose menu.

The chain selection screen is divided into two parts. In the (larger)
upper part, you get a list of remailers you may use. In the lower part,
you see the currently selected chain of remailers.

You can navigate in the chain using the `<chain-prev>`and
`<chain-next>`functions, which are by default bound to the left and
right arrows and to the `h` and `l` keys (think vi keyboard bindings).
To insert a remailer at the current chain position, use the
`<insert>`function. To append a remailer behind the current chain
position, use `<select-entry>`or `<append>`. You can also delete entries
from the chain, using the corresponding function. Finally, to abandon
your changes, leave the menu, or `<accept>`them pressing (by default)
the `Return` key.

Note that different remailers do have different capabilities, indicated
in the %c entry of the remailer menu lines (see
[\$mix\_entry\_format](#mix-entry-format)). Most important is the
“middleman” capability, indicated by a capital “M”: This means that the
remailer in question cannot be used as the final element of a chain, but
will only forward messages to other mixmaster remailers. For details on
the other capabilities, please have a look at the mixmaster
documentation.

Attach Headers Color Feature {#attach-headers-color}
----------------------------

Color attachment headers using regexp, just like mail bodies
### Support {#attach-headers-color-support}

**Since:**NeoMutt 2016-09-10

**Dependencies:**None

### Introduction {#attach-headers-color-intro}

This feature allows specifying regexps to color attachment headers just
like the mail body would. The headers are the parts colored by the
`attachment` color. Coloring them is useful to highlight the results of
GPGME's signature checks or simply the mimetype or size of the
attachment. Only the part matched by the regexp is colored.

### Usage {#attach-headers-color-usage}

The `attach_headers` color should be used just like the `body` color.

    color attach_headers foreground background pattern

### Muttrc {#attach-headers-color-muttrc}

    # Example NeoMutt config file for the attach-headers-color feature.

    # Color if the attachment is autoviewed
    color   attach_headers     brightgreen     default        "Autoview"
    # Color only the brackets around the headers
    color   attach_headers     brightyellow    default        "^\\[--"
    color   attach_headers     brightyellow    default        "--]$"
    # Color the mime type and the size
    color   attach_headers     green           default        "Type: [a-z]+/[a-z0-9\-]+"
    color   attach_headers     green           default        "Size: [0-9\.]+[KM]"
    # Color GPGME signature checks
    color   attach_headers     brightgreen     default        "Good signature from.*"
    color   attach_headers     brightred       default        "Bad signature from.*"
    color   attach_headers     brightred       default        "BAD signature from.*"
    color   attach_headers     brightred       default        "Note: This key has expired!"
    color   attach_headers     brightmagenta   default        "Problem signature from.*"
    color   attach_headers     brightmagenta   default        "WARNING: This key is not certified with a trusted signature!"
    color   attach_headers     brightmagenta   default        "         There is no indication that the signature belongs to the owner."
    color   attach_headers     brightmagenta   default        "can't handle these multiple signatures"
    color   attach_headers     brightmagenta   default        "signature verification suppressed"
    color   attach_headers     brightmagenta   default        "invalid node with packet of type"

            # vim: syntax=muttrc

### See Also {#attach-headers-color-see-also}

-   [Color command](#color)

-   [Regular Expressions](#regexp)

### Known Bugs {#attach-headers-color-known-bugs}

None

### Credits {#attach-headers-color-credits}

-   Guillaume Brogi <gui-gui@netcourrier.com>

Compose to Sender Feature {#compose-to-sender}
-------------------------

Send new mail to the sender of the current mail
### Support {#compose-to-sender-support}

**Since:**NeoMutt 2016-10-02

**Dependencies:**None

### Introduction {#compose-to-sender-intro}

The compose-to-sender feature adds a new command to start composing a
new email to the sender of the current message. This is not a reply, but
a new, separate, message.

It works on tagged messages too, sending one email to all of the senders
of the tagged messages.

### Functions {#compose-to-sender-functions}

compose-to-sender adds the following function to Mutt. By default, it is
not bound to a key.

  Menus         Function                Description
  ------------- ----------------------- --------------------------------------------------------
  index,pager   `<compose-to-sender>`   compose a new email to the sender of the current email

  : compose-to-sender Functions

### Muttrc {#compose-to-sender-muttrc}

    # Example NeoMutt config file for the compose-to-sender feature.

    # --------------------------------------------------------------------------
    # FUNCTIONS - shown with an example mapping
    # --------------------------------------------------------------------------
    # Compose a new email (not a reply) to the sender
    bind index,pager @ compose-to-sender

            # vim: syntax=muttrc

### Known Bugs {#compose-to-sender-known-bugs}

None

### Credits {#compose-to-sender-credits}

-   Brian Medley

-   Guillaume Brogi <gui-gui@netcourrier.com>

Compressed Folders Feature {#compress}
--------------------------

Read from/write to compressed mailboxes
### Support {#compress-support}

**Since:**NeoMutt 2016-05-30

**Dependencies:**None

### Introduction {#compress-intro}

The Compressed Folder feature allows Mutt to read mailbox files that are
compressed. But it isn't limited to compressed files. It works well with
encrypted files, too. In fact, if you can create a program/script to
convert to and from your format, then Mutt can read it.

The feature adds three hooks to Mutt: `open-hook`, `close-hook` and
`append-hook`. They define commands to: uncompress a file; compress a
file; append messages to an already compressed file.

There are some examples of both compressed and encrypted files, later.
For now, the documentation will just concentrate on compressed files.

### Commands {#compress-commands}

open-hook
pattern
shell-command
close-hook
pattern
shell-command
append-hook
pattern
shell-command
The shell-command must contain two placeholders for filenames: `%f` and
`%t`. These represent “from” and “to” filenames. These placeholders
should be placed inside single-quotes to prevent unintended shell
expansions.

If you need the exact string “%f” or “%t” in your command, simply double
up the “%”character, e.g. “%%f” or “%%t”.

  Open   Close   Append   Effect                                                                               Useful if
  ------ ------- -------- ------------------------------------------------------------------------------------ ---------------------------------------------------
  Open   -       -        Folder is readonly                                                                   The folder is just a backup
  Open   Close   -        Folder is read/write, but the entire folder must be written if anything is changed   Your compression format doesn't support appending
  Open   Close   Append   Folder is read/write and emails can be efficiently added to the end                  Your compression format supports appending
  Open   -       Append   Folder is readonly, but can be appended to                                           You want to store emails, but never change them

  : Not all Hooks are Required

> **Note**
>
> The command:
>
> -   should return a non-zero exit status on failure
>
> -   should not delete any files
>
#### Read from compressed mailbox {#open-hook}

    open-hook regexp shell-command

If Mutt is unable to open a file, it then looks for `open-hook` that
matches the filename.

If your compression program doesn't have a well-defined extension, then
you can use `.`as the regexp.

##### Example of `open-hook` {#compress-open-hook-example}

    open-hook '\.gz$' "gzip --stdout --decompress '%f' > '%t'"

-   Mutt finds a file, “example.gz”, that it can't read

-   Mutt has an `open-hook` whose regexp matches the filename: `\.gz$`

-   Mutt uses the command `gzip -cd` to create a temporary file that it
    *can* read

#### Write to a compressed mailbox {#close-hook}

    close-hook regexp shell-command

When Mutt has finished with a compressed mail folder, it will look for a
matching `close-hook` to recompress the file. This hook is
[optional](#table-compress-optional).

> **Note**
>
> If the folder has not been modified, the `close-hook` will not be
> called.

##### Example of `close-hook` {#compress-close-hook-example}

    close-hook '\.gz$' "gzip --stdout '%t' > '%f'"

-   Mutt has finished with a folder, “example.gz”, that it opened with
    `open-hook`

-   The folder has been modified

-   Mutt has a `close-hook` whose regexp matches the filename: `\.gz$`

-   Mutt uses the command `gzip -c` to create a new compressed file

> **Note**
>
> The `close-hook` can also include extra options, e.g. compression
> level: `--best`

#### Append to a compressed mailbox {#append-hook}

    append-hook regexp shell-command

When Mutt wants to append an email to a compressed mail folder, it will
look for a matching `append-hook`. This hook is
[optional](#table-compress-optional).

Using the `append-hook` will save time, but Mutt won't be able to
determine the type of the mail folder inside the compressed file.

Mutt will *assume* the type to be that of the `$mbox_type` variable.
Mutt also uses this type for temporary files.

Mutt will only use the `append-hook` for existing files. The
`close-hook` will be used for empty, or missing files.

> **Note**
>
> If your command writes to stdout, it is vital that you use `>>`in the
> “append-hook”. If not, data will be lost.

##### Example of `append-hook` {#compress-append-hook-example}

    append-hook '\.gz$' "gzip --stdout '%t' >> '%f'"

-   Mutt wants to append an email to a folder, “example.gz”, that it
    opened with `open-hook`

-   Mutt has an `append-hook` whose regexp matches the filename: `\.gz$`

-   Mutt knows the mailbox type from the `$mbox` variable

-   Mutt uses the command `gzip -c` to append to an existing compressed
    file

> **Note**
>
> The `append-hook` can also include extra options, e.g. compression
> level: `--best`

#### Empty Files {#compress-empty}

Mutt assumes that an empty file is not compressed. In this situation,
unset [\$save\_empty](#save-empty), so that the compressed file will be
removed if you delete all of the messages.

#### Security {#compress-security}

Encrypted files are decrypted into temporary files which are stored in
the [\$tmpdir](#tmpdir) directory. This could be a security risk.

### Muttrc {#compress-muttrc}

    # Example NeoMutt config file for the compress feature.

    # This feature adds three hooks to Mutt which allow it to
    # work with compressed, or encrypted, mailboxes.

    # The hooks are of the form:
    #       open-hook   regexp "shell-command"
    #       close-hook  regexp "shell-command"
    #       append-hook regexp "shell-command"
    # The 'append-hook' is optional.

    # Handler for gzip compressed mailboxes
    open-hook   '\.gz$' "gzip --stdout --decompress '%f' >  '%t'"
    close-hook  '\.gz$' "gzip --stdout              '%t' >  '%f'"
    append-hook '\.gz$' "gzip --stdout              '%t' >> '%f'"
    # Handler for bzip2 compressed mailboxes
    open-hook   '\.bz2$' "bzip2 --stdout --decompress '%f' >  '%t'"
    close-hook  '\.bz2$' "bzip2 --stdout              '%t' >  '%f'"
    append-hook '\.bz2$' "bzip2 --stdout              '%t' >> '%f'"
    # Handler for xz compressed mailboxes
    open-hook   '\.xz$' "xz --stdout --decompress '%f' >  '%t'"
    close-hook  '\.xz$' "xz --stdout              '%t' >  '%f'"
    append-hook '\.xz$' "xz --stdout              '%t' >> '%f'"
    # Handler for pgp encrypted mailboxes
    # PGP does not support appending to an encrypted file
    open-hook   '\.pgp$' "pgp -f < '%f' > '%t'"
    close-hook  '\.pgp$' "pgp -fe YourPgpUserIdOrKeyId < '%t' > '%f'"
    # Handler for gpg encrypted mailboxes
    # gpg does not support appending to an encrypted file
    open-hook   '\.gpg$' "gpg --decrypt < '%f' > '%t'"
    close-hook  '\.gpg$' "gpg --encrypt --recipient YourGpgUserIdOrKeyId < '%t' > '%f'"

            # vim: syntax=muttrc

### See Also {#compress-see-also}

-   [Compile-Time Features](#compile-time-features)

-   [Regular Expressions](#regexp)

-   [\$tmpdir](#tmpdir)

-   [\$mbox\_type](#mbox-type)

-   [\$save\_empty](#save-empty)

-   [folder-hook](#folder-hook)

### Credits {#compress-credits}

-   Roland Rosenfeld <roland@spinnaker.de>

-   Alain Penders <Alain@Finale-Dev.com>

-   Christoph “Myon” Berg <myon@debian.org>

-   Evgeni Golov <evgeni@debian.org>

-   Richard Russon <rich@flatcap.org>

Conditional Dates Feature {#cond-date}
-------------------------

Use rules to choose date format
### Support {#cond-date-support}

**Since:**NeoMutt 2016-03-07

**Dependencies:**

:   [nested-if feature](#nested-if)

### Introduction {#cond-date-intro}

The “Conditional Dates” feature allows you to construct
[\$index\_format](#index-format) expressions based on the age of the
email.

Mutt's default `$index_format` displays email dates in the form:
abbreviated-month day-of-month — “Jan 14”.

The format is configurable but only per-mailbox. This feature allows you
to configure the display depending on the age of the email.

  Email Sent          Format    Example
  ------------------- --------- ---------
  Today               `%H:%M`   13:23
  This Month          `%a %d`   Thu 17
  This Year           `%b %d`   Dec 10
  Older than 1 Year   `%m/%y`   06/14

  : Potential Formatting Scheme

For an explanation of the date formatting strings, see `strftime(3).`

By carefully picking your formats, the dates can remain unambiguous and
compact.

Mutt's conditional format strings have the form: (whitespace introduced
for clarity)

    %? TEST ? TRUE & FALSE ?

The examples below use the test “%\[”— the date of the message in the
local timezone. They will also work with “%(”— the local time that the
message arrived.

The date tests are of the form:

    %[nX? TRUE & FALSE ?

-   “n” is an optional count (defaults to 1 if missing)

-   “X” is the time period

  Letter   Time Period
  -------- -------------
  y        Years
  m        Months
  w        Weeks
  d        Days
  H        Hours
  M        Minutes

  : Date Formatting Codes

  Test     Meaning
  -------- ----------------------
  `%[y`    This year
  `%[1y`   This year
  `%[6m`   In the last 6 months
  `%[w`    This week
  `%[d`    Today
  `%[4H`   In the last 4 hours

  : Example Date Tests

#### Example 1 {#cond-date-example1}

We start with a one-condition test.

  Test     Date Range   Format String   Example
  -------- ------------ --------------- ------------
  `%[1m`   This month   `%[%b %d]`      Dec 10
           Older        `%[%Y-%m-%d]`   2015-04-23

  : Example 1

The \$index\_format string would contain:

    %?[1m?%[%b %d]&%[%Y-%m-%d]?

Reparsed a little, for clarity, you can see the test condition and the
two format strings.

    %?[1m?        &           ?

          %[%b %d] %[%Y-%m-%d]

#### Example 2 {#cond-date-example2}

This example contains three test conditions and four date formats.

  Test    Date Range   Format String   Example
  ------- ------------ --------------- ---------
  `%[d`   Today        `%[%H:%M ]`     12:34
  `%[m`   This month   `%[%a %d]`      Thu 12
  `%[y`   This year    `%[%b %d]`      Dec 10
          Older        `%[%m/%y ]`     06/15

  : Example 2

The \$index\_format string would contain:

    %<[y?%<[m?%<[d?%[%H:%M ]&%[%a %d]>&%[%b %d]>&%[%m/%y ]>

Reparsed a little, for clarity, you can see the test conditions and the
four format strings.

    %<[y?                                       &%[%m/%y ]>  Older
         %<[m?                        &%[%b %d]>             This year
              %<[d?         &%[%a %d]>                       This month
                   %[%H:%M ]                                 Today

This a another view of the same example, with some whitespace for
clarity.

    %<[y? %<[m? %<[d? AAA & BBB > & CCC > & DDD >

    AAA = %[%H:%M ] BBB = %[%a %d] CCC = %[%b %d] DDD =
              %[%m/%y ]

### Variables {#cond-date-variables}

The “Conditional Dates” feature doesn't have any config of its own. It
modifies the behavior of the format strings.

### Muttrc {#cond-date-muttrc}

    # Example NeoMutt config file for the cond-date feature.

    #
    # The default index_format is:
    #       '%4C %Z %{%b %d} %-15.15L (%?l?%4l&%4c?) %s'
    #
    # We replace the date field '%{%b %d}', giving:
    set index_format='%4C %Z %<[y?%<[m?%<[d?%[%H:%M ]&%[%a %d]>&%[%b %d]>&%[%m/%y ]> %-15.15L (%?l?%4l&%4c?) %s'
    # Test  Date Range  Format String  Example
    # --------------------------------------------
    # %[d   Today       %[%H:%M ]      12:34
    # %[m   This month  %[%a %d]       Thu 12
    # %[y   This year   %[%b %d]       Dec 10
    # -     Older       %[%m/%y ]      06/15
    # vim: syntax=muttrc

### See Also {#cond-date-see-also}

-   [\$index\_format](#index-format)

-   [nested-if feature](#nested-if)

-   `strftime(3)`

### Known Bugs {#cond-date-known-bugs}

Date parsing doesn't quite do what you expect. “1w” doesn't mean the “in
the last 7 days”, but “*this* week”. This doesn't match the normal Mutt
behavior: for example `~d>1w` means emails dated in the last 7 days.

### Credits {#cond-date-credits}

-   Aaron Schrab <aaron@schrab.com>

-   Eric Davis <edavis@insanum.com>

-   Richard Russon <rich@flatcap.org>

Encrypt-to-Self Feature {#encrypt-to-self}
-----------------------

Save a self-encrypted copy of emails
### Support {#encrypt-to-self-support}

**Since:**NeoMutt 2016-07-23

**Dependencies:**None

### Introduction {#encrypt-to-self-intro}

Once you encrypt an email to someone you cannot read it. This is good
for security, but bad for record-keeping. If you wanted to keep a copy
of an encrypted email you could set [\$fcc\_clear](#fcc-clear).

A better option is to enable
[\$smime\_encrypt\_self](#smime-encrypt-self), then set
[\$smime\_default\_key](#smime-default-key) to your personal S/MIME key
id.

    set smime_encrypt_self = yes
    set smime_default_key  = bb345e23.0

Or, if you use PGP, [\$pgp\_encrypt\_self](#pgp-encrypt-self), then set
[\$pgp\_sign\_as](#pgp-sign-as) to your personal PGP key id.

    set pgp_encrypt_self = yes
    set pgp_sign_as      = A4AF18C5582473BD35A1E9CE78BB3D480042198E

### Variables {#encrypt-to-self-variables}

  Name                   Type   Default
  ---------------------- ------ ---------
  `smime_encrypt_self`   quad   No
  `pgp_encrypt_self`     quad   No

  : encrypt-self Variables

### Muttrc {#encrypt-to-self-muttrc}

    # Example NeoMutt config file for the encrypt-to-self feature.

    # --------------------------------------------------------------------------
    # VARIABLES - shown with their default values
    # --------------------------------------------------------------------------
    # Save a copy of outgoing email, encrypted to yourself
    set smime_encrypt_self = "no"
    # Save a copy of outgoing email, encrypted to yourself
    set pgp_encrypt_self = "no"

            # vim: syntax=muttrc

### Known Bugs {#encrypt-to-self-known-bugs}

None

### Credits {#encrypt-to-self-credits}

-   Omen Wild <omen@mandarb.com>

-   Richard Russon <rich@flatcap.org>

-   Guillaume Brogi <gui-gui@netcourrier.com>

Fmemopen Feature {#fmemopen}
----------------

Replace some temporary files with memory buffers
### Support {#fmemopen-support}

**Since:**NeoMutt 2016-03-07

**Dependencies:**

:   `open_memstream()`, `fmemopen()`from glibc

This feature can be enabled by running `configure` with the option
`--enable-fmemopen`

### Introduction {#fmemopen-intro}

The “fmemopen” feature speeds up some searches.

This feature changes a few places where Mutt creates temporary files. It
replaces them with in-memory buffers. This should improve the
performance when searching the header or body using the
[\$thorough\_search](#thorough-search) option.

There are no user-configurable parts.

This feature depends on `open_memstream()`and `fmemopen()`. They are
provided by glibc. Without them, Mutt will simply create temporary
files.

### See Also {#fmemopen-see-also}

-   [Compile-Time Features](#compile-time-features)

-   `fmemopen(3)`

### Known Bugs {#fmemopen-known-bugs}

[debian bug
834408](https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=834408)

### Credits {#fmemopen-credits}

-   Julius Plenz <plenz@cis.fu-berlin.de>

-   Richard Russon <rich@flatcap.org>

Forgotten Attachment Feature {#forgotten-attachment}
----------------------------

Alert user when (s)he forgets to attach a file to an outgoing email.
### Support {#forgotten-attachment-support}

**Since:**NeoMutt 2016-09-10

**Dependencies:**None

### Introduction {#forgotten-attachment-intro}

The “forgotten-attachment” feature provides a new setting for Mutt that
alerts the user if the message body contains a certain keyword but there
are no attachments added. This is meant to ensure that the user does not
forget to attach a file after promising to do so in the mail. The
attachment keyword will not be scanned in text matched by
[\$quote\_regexp](#quote-regexp).

### Variables {#forgotten-attachment-variables}

  Name               Type                 Default
  ------------------ -------------------- ----------------------------------------
  `attach_keyword`   regular expression   `\\<(attach|attached|attachments?)\\>`
  `abort_noattach`   quadoption           `no`

  : forgotten-attachment Variables

### Muttrc {#forgotten-attachment-muttrc}

    # Example NeoMutt config file for the forgotten-attachment feature.

    # The 'forgotten-attachment' feature provides a new setting for Mutt that
    # alerts the user if the message body contains a certain regular expression but there are
    # no attachments added. This is meant to ensure that the user does not forget
    # to attach a file after promising to do so in the mail.

    # Ask if the user wishes to abort sending if $attach_keyword is found in the
    # body, but no attachments have been added
    # It can be set to:
    #    "yes"     : always abort
    #    "ask-yes" : ask whether to abort
    #    "no"      : send the mail
    set abort_noattach = no
    # Search for the following regular expression in the body of the email
    # English: attach, attached, attachment, attachments
    set attach_keyword = "\\<attach(|ed|ments?)\\>"
    # Nederlands:
    # set attach_keyword = "\\<(bijvoegen|bijgevoegd|bijlage|bijlagen)\\>"
    # Deutsch:
    # set attach_keyword = "\\<(anhängen|angehängt|anhang|anhänge|hängt an)\\>"
    # Français:
    # set attach_keyword = "\\<(attaché|attachés|attache|attachons|joint|jointe|joints|jointes|joins|joignons)\\>"
    # vim: syntax=muttrc

### See Also {#forgotten-attachment-see-also}

-   [The Attachment Menu](#attach-menu)

-   [The Attachment Menu key mappings](#attachment-map)

### Known Bugs {#forgotten-attachment-known-bugs}

None

### Credits {#forgotten-attachment-credits}

-   Darshit Shah <darnir@gmail.com>

-   Richard Russon <rich@flatcap.org>

-   Johannes Weißl <jargon@molb.org>

-   Steven! Ragnarök <steven@nuclearsandwich.com>

Global Hooks
------------

Define actions to run globally within Mutt
### Introduction {#global-hooks-intro}

These hooks are called when global events take place in Mutt.

-   **timeout-hook**- periodically

-   **startup-hook**- when mutt starts up, before opening the first
    mailbox

-   **shutdown-hook**- mutt shuts down, before closing the last mailbox

#### Timeout Hook {#timeout-hook-intro}

Run a command periodically
**Since:**NeoMutt 2016-08-08

This feature implements a new hook that is called periodically when Mutt
checks for new mail. This hook is called every `$timeout` seconds.

#### Startup Hook {#startup-hook-intro}

Run a command when mutt starts up, before opening the first mailbox
**Since:**NeoMutt 2016-11-25

This feature implements a new hook that is called when Mutt first starts
up, but before opening the first mailbox. This is most likely to be
useful to users of [notmuch](#notmuch).

#### Shutdown Hook

Run a command when mutt shuts down, before closing the last mailbox
**Since:**NeoMutt 2016-11-25

This feature implements a hook that is called when Mutt shuts down, but
before closing the first mailbox. This is most likely to be useful to
users of [notmuch](#notmuch).

### Commands {#global-hooks-commands}

timeout-hook
MUTT-COMMAND
startup-hook
MUTT-COMMAND
shutdown-hook
MUTT-COMMAND
### Muttrc {#global-hooks-muttrc}

    # Example NeoMutt config file for the global hooks feature.

    # --------------------------------------------------------------------------
    # COMMANDS - shown with an example argument
    # --------------------------------------------------------------------------
    # After $timeout seconds of inactivity, run this mutt command
    timeout-hook 'exec sync-mailbox'
    # When mutt first loads, run this mutt command
    startup-hook 'exec sync-mailbox'
    # When mutt quits, run this mutt command
    shutdown-hook 'exec sync-mailbox'

            # vim: syntax=muttrc

### See Also {#timeout-see-also}

-   [\$timeout](#timeout)

### Known Bugs {#global-hooks-known-bugs}

None

### Credits {#global-hooks-credits}

-   Armin Wolfermann <armin@wolfermann.org>

-   Richard Russon <rich@flatcap.org>

-   Thomas Adam <thomas@xteddy.org>

Ifdef Feature {#ifdef}
-------------

Conditional config options
### Support {#ifdef-support}

**Since:**NeoMutt 2016-03-07

**Dependencies:**None

### Introduction {#ifdef-intro}

The “ifdef” feature introduces three new commands to Mutt and allow you
to share one config file between versions of Mutt that may have
different features compiled in.

    ifdef  symbol config-command [args...]  # If a symbol is defined
    ifndef symbol config-command [args...]  # If a symbol is not defined
    finish                                  # Finish reading the current file

Here a symbol can be a [\$variable](#variables),
[&lt;function&gt;](#functions), [command](#commands) or compile-time
symbol, such as “imap”.

A list of compile-time symbols can be seen in the output of the command

    mutt -v

(in the “Compile options” section).

`finish` is particularly useful when combined with `ifndef`. e.g.

    # Sidebar config file
    ifndef sidebar finish

### Commands {#ifdef-commands}

ifdef
symbol
"config-command \[args\]"
ifndef
symbol
"config-command \[args\]"
finish
### Muttrc {#ifdef-muttrc}

    # Example NeoMutt config file for the ifdef feature.

    # This feature introduces three useful commands which allow you to share
    # one config file between versions of Mutt that may have different
    # features compiled in.

    #   ifdef  symbol config-command [args...]
    #   ifndef symbol config-command [args...]
    #   finish
    # The 'ifdef' command tests whether Mutt understands the name of
    # a variable, function, command or compile-time symbol.

    # If it does, then it executes a config command.

    # The 'ifndef' command tests whether a symbol does NOT exist.

    # The 'finish' command tells Mutt to stop reading current config file.

    # If the 'trash' variable exists, set it.
    ifdef trash 'set trash=~/Mail/trash'
    # If the 'tag-pattern' function exists, bind a key to it.
    ifdef tag-pattern 'bind index <F6> tag-pattern'
    # If the 'imap-fetch-mail' command exists, read my IMAP config.
    ifdef imap-fetch-mail 'source ~/.mutt/imap.rc'
    # If the compile-time symbol 'sidebar' does not exist, then
    # stop reading the current config file.
    ifndef sidebar finish

            # vim: syntax=muttrc

### Known Bugs {#ifdef-known-bugs}

None

### Credits {#ifdef-credits}

-   Cedric Duval <cedricduval@free.fr>

-   Matteo F. Vescovi <mfvescovi@gmail.com>

-   Richard Russon <rich@flatcap.org>

Index Color Feature {#index-color}
-------------------

Custom rules for theming the email index
### Support {#index-color-support}

**Since:**NeoMutt 2016-03-07

**Dependencies:**

:   [status-color feature](#status-color)

### Introduction {#index-color-intro}

The “index-color” feature allows you to specify colors for individual
parts of the email index. e.g. Subject, Author, Flags.

First choose which part of the index you'd like to color. Then, if
needed, pick a pattern to match.

Note: The pattern does not have to refer to the object you wish to
color. e.g.

    color index_author red default "~smutt"

The author appears red when the subject (\~s) contains “mutt”.

### Colors {#index-color-colors}

All the colors default to `default`, i.e. unset.

The index objects can be themed using the `color` command. Some objects
require a pattern.

    color index-object foreground background
    color index-object foreground background pattern

  Object              Pattern   Highlights
  ------------------- --------- ----------------------------------------------
  `index`             yes       Entire index line
  `index_author`      yes       Author name, %A %a %F %L %n
  `index_collapsed`   no        Number of messages in a collapsed thread, %M
  `index_date`        no        Date field
  `index_flags`       yes       Message flags, %S %Z
  `index_label`       no        Message label, %y %Y
  `index_number`      no        Message number, %C
  `index_size`        no        Message size, %c %l
  `index_subject`     yes       Subject, %s

  : Index Colors

### Muttrc {#index-color-muttrc}

    # Example NeoMutt config file for the index-color feature.

    # Entire index line
    color index white black '.*'
    # Author name, %A %a %F %L %n
    # Give the author column a dark grey background
    color index_author default color234 '.*'
    # Highlight a particular from (~f)
    color index_author brightyellow color234 '~fRay Charles'
    # Message flags, %S %Z
    # Highlight the flags for flagged (~F) emails
    color index_flags default red '~F'
    # Subject, %s
    # Look for a particular subject (~s)
    color index_subject brightcyan default '~s\(closes #[0-9]+\)'
    # Number of messages in a collapsed thread, %M
    color index_collapsed default brightblue
    # Date field
    color index_date green default
    # Message label, %y %Y
    color index_label default brightgreen
    # Message number, %C
    color index_number red default
    # Message size, %c %l
    color index_size cyan default

            # vim: syntax=muttrc

### See Also {#index-color-see-also}

-   [Regular Expressions](#regexp)

-   [Patterns](#patterns)

-   [\$index\_format](#index-format)

-   [Color command](#color)

-   [Status-Color feature](#status-color)

-   [Keywords feature](#keywords)

### Known Bugs {#index-color-known-bugs}

None

### Credits {#index-color-credits}

-   Christian Aichinger <Greek0@gmx.net>

-   Christoph “Myon” Berg <myon@debian.org>

-   Elimar Riesebieter <riesebie@lxtec.de>

-   Eric Davis <edavis@insanum.com>

-   Vladimir Marek <Vladimir.Marek@oracle.com>

-   Richard Russon <rich@flatcap.org>

Initials Expando Feature {#initials}
------------------------

Expando for author's initials
### Support {#initials-support}

**Since:**NeoMutt 2016-03-07

**Dependencies:**None

### Introduction {#initials-intro}

The “initials” feature adds an expando (%I) for an author's initials.

The index panel displays a list of emails. Its layout is controlled by
the [\$index\_format](#index-format) variable. Using this expando saves
space in the index panel. This can be useful if you are regularly
working with a small set of people.

### Variables {#initials-variables}

This feature has no config of its own. It adds an expando which can be
used in the [\$index\_format](#index-format) variable.

### Muttrc {#initials-muttrc}

    # Example NeoMutt config file for the initials feature.

    # The 'initials' feature has no config of its own.

    # It adds an expando for an author's initials,
    # which can be used in the 'index_format' variable.

    # The default 'index_format' is:
    set index_format='%4C %Z %{%b %d} %-15.15L (%?l?%4l&%4c?) %s'
    # Where %L represents the author/recipient
    # This might look like:
    #       1   + Nov 17 David Bowie   Changesbowie    ( 689)
    #       2   ! Nov 17 Stevie Nicks  Rumours         ( 555)
    #       3   + Nov 16 Jimi Hendrix  Voodoo Child    ( 263)
    #       4   + Nov 16 Debbie Harry  Parallel Lines  ( 540)
    # Using the %I expando:
    set index_format='%4C %Z %{%b %d} %I (%?l?%4l&%4c?) %s'
    # This might look like:
    #       1   + Nov 17 DB Changesbowie    ( 689)
    #       2   ! Nov 17 SN Rumours         ( 555)
    #       3   + Nov 16 JH Voodoo Child    ( 263)
    #       4   + Nov 16 DH Parallel Lines  ( 540)
    # vim: syntax=muttrc

### See Also {#initials-see-also}

-   [\$index\_format](#index-format)

-   [index-color feature](#index-color)

-   [folder-hook](#folder-hook)

### Known Bugs {#initials-known-bugs}

None

### Credits {#initials-credits}

-   Vsevolod Volkov <vvv@mutt.org.ua>

-   Richard Russon <rich@flatcap.org>

Keywords Feature {#keywords}
----------------

Labels/Tagging for emails
### Support {#keywords-support}

**Since:**NeoMutt 2016-05-30

**Dependencies:**None

### Introduction {#keywords-intro}

Unify label/keyword handling.

Since x-labels were added to mutt in 2000, a number of other approaches
to what we now call “tagging” have also emerged. One of them was even
made standard in RFC 2822. This update unifies the handling of all these
strategies.

We start by changing mutt's internal keyword storage from a single
string which may contain whitespace to a list of discrete keywords. This
has advantages for keyword completion as well as for portability among
varying "standards" for keyword storage. This may represent a
significant change for existing mutt users who have set x-labels
containing spaces, and should be regarded with suspicion. The advantages
are significant, though.

Next we allow mutt to parse keywords into this internal list from any of
the following headers: X-Label (freeform), X-Keywords (space-delimited),
X-Mozilla-Keys (space-delimited), and Keywords (RFC 2822,
comma-space-delimited). Mutt remembers which headers it sourced keywords
from, and can rewrite those headers when saving messages for
compatibility with the mailer of origin.

(X-Label was specified as freeform text by mutt, its only known
implementation. X-Labels have been used both as a “tagging” device,
probably with space delimiting, and as a “memo” field, where
space-delimited parsing would ruin the semantics of the memo. By default
mutt will not split X-Labels at all. Set \$xlabel\_delimiter if your
needs vary.)

Finally we add two booleans: \$keywords\_legacy=true and
\$keywords\_standard=FALSE. When \$keywords\_legacy is true, mutt will
always save keyword to whatever original header it came from. When
\$keywords\_standard=true, mutt will save to the Keywords: header. If
both are true mutt saves to both; if neither is true, mutt saves only to
legacy headers to avoid complete loss of keywords.

Overall this represents convergence path for all competing
labelling/tagging/keywording systems toward one that is specified by
RFC.

You can change or delete the X-Label: field within Mutt using the
edit-label command. This works for tagged messages, too.

### Variables {#keywords-variables}

  Name                  Type      Default
  --------------------- --------- ---------
  `keywords_legacy`     boolean   `yes`
  `keywords_standard`   boolean   `no`
  `xlabel_delimiter`    string    (empty)

  : Keywords Variables

### Functions {#keywords-functions}

Keywords adds the following function to Mutt. By default, it is not
bound to a key.

  Menus         Function         Description
  ------------- ---------------- ------------------------------------------
  index,pager   `<edit-label>`   add, change, or delete a message's label

  : Keyword Functions

### Sort {#keywords-sort}

  Sort      Description
  --------- ---------------
  `label`   Sort by label

  : Keywords Sort

### Muttrc {#keywords-muttrc}

    # Example NeoMutt config file for the keywords feature.

    # --------------------------------------------------------------------------
    # VARIABLES - shown with their default values
    # --------------------------------------------------------------------------
    # Should Mutt save the keywords to whatever keyword it came from?
    set keywords_legacy = yes
    # Should Mutt use the "Keywords:" header?
    set keywords_standard = no
    # How should the keywords be separated?
    set xlabel_delimiter = ""
    # --------------------------------------------------------------------------
    # FUNCTIONS - shown with an example mapping
    # --------------------------------------------------------------------------
    # Bind 'y' to edit labels/keywords
    bind index,pager y edit-label

            # vim: syntax=muttrc

### See Also {#keywords-see-also}

-   [\$index\_format](#index-format)

-   [index-color feature](#index-color)

-   [folder-hook](#folder-hook)

### Known Bugs {#keywords-known-bugs}

None

### Credits {#keywords-credits}

-   David Champion <dgc@uchicago.edu>

-   Richard Russon <rich@flatcap.org>

Kyoto Cabinet Feature {#kyoto-cabinet}
---------------------

Kyoto Cabinet backend for the header cache
### Support {#kyoto-cabinet-support}

**Since:**NeoMutt 2016-10-02

**Dependencies:**

:   [Kyoto Cabinet libraries](http://fallabs.com/kyotocabinet/)

To check if Mutt supports Kyoto Cabinet, look for

-   “kyoto” in the mutt version.

-   “+hcache” in the compile options

-   “hcache backend: kyotocabinet” in the mutt version

### Introduction {#kyoto-cabinet-intro}

This feature adds support for using Kyoto Cabinet, the successor to
Tokyo Cabinet, as a storage backend for Mutt's header cache (hcache). It
is enabled at configure time with the
*--with-kyotocabinet=&lt;path&gt;*switch.

### See Also {#kyoto-cabinet-see-also}

-   [Local Caching](#caching)

-   [Kyoto Cabinet](http://fallabs.com/kyotocabinet/)

### Known Bugs {#kyoto-cabinet-known-bugs}

None

### Credits {#kyoto-cabinet-credits}

-   Clemens Lang <neverpanic@gmail.com>

Limit Current Thread Feature {#limit-current-thread}
----------------------------

Focus on one Email Thread
### Support {#limit-current-thread-support}

**Since:**NeoMutt 2016-03-28

**Dependencies:**None

### Introduction {#limit-current-thread-intro}

This feature adds a new way of using the [Limit
Command](#tuning-search). The `<limit-current-thread>`function restricts
the view to just the current thread. Setting the limit (the `l` key) to
“all” will restore the full email list.

### Functions {#limit-current-thread-functions}

Limit-current-thread adds the following function to Mutt. By default, it
is not bound to a key.

  Menus   Function                   Description
  ------- -------------------------- ------------------------------
  index   `<limit-current-thread>`   Limit view to current thread

  : Limit-Current-Thread Functions

### Muttrc {#limit-current-thread-muttrc}

    # Example NeoMutt config file for the limit-current-thread feature.

    # Limit view to current thread
    bind index <esc>L limit-current-thread

            # vim: syntax=muttrc

### Known Bugs {#limit-current-thread-known-bugs}

None

### Credits {#limit-current-thread-credits}

-   David Sterba <dsterba@suse.cz>

-   Richard Russon <rich@flatcap.org>

LMDB Feature {#lmdb}
------------

LMDB backend for the header cache
### Support {#lmdb-support}

**Since:**NeoMutt 2016-07-23

**Dependencies:**None

### Introduction {#lmdb-intro}

This feature adds support for using LMDB as a storage backend for Mutt's
header cache (hcache). It is enabled at configure time with the
*--with-lmdb=&lt;path&gt;*switch.

> **Note**
>
> It is not recommended to store the lmdb database on a shared drive.

### See Also {#lmdb-see-also}

-   [Local Caching](#caching)

### Known Bugs {#lmdb-known-bugs}

None

### Credits {#lmdb-credits}

-   Pietro Cerutti <gahr@gahr.ch>

-   Jan-Piet Mens <jp@mens.de>

-   Clemens Lang <neverpanic@gmail.com>

Multiple FCC Feature {#multiple-fcc}
--------------------

Save multiple copies of outgoing mail
### Support {#multiple-fcc-support}

**Since:**NeoMutt 2016-08-08

**Dependencies:**None

### Introduction {#multiple-fcc-intro}

This feature allows the user to save outgoing emails in multiple
folders.

Folders should be listed separated by commas, **but no spaces**.

The “fcc” field of an email can be set in two ways:

-   The &lt;edit-fcc&gt; command in the compose menu (default key: “f”)

-   Creating a `fcc-hook` in your `.muttrc`

### See Also {#multiple-fcc-see-also}

-   [\$record](#record)

-   [fcc-hook](#fcc-hook)

### Known Bugs {#multiple-fcc-known-bugs}

None

### Credits {#multiple-fcc-credits}

-   Omen Wild <omen@mandarb.com>

-   Richard Russon <rich@flatcap.org>

Nested If Feature {#nested-if}
-----------------

Allow complex nested conditions in format strings
### Support {#nested-if-support}

**Since:**NeoMutt 2016-03-07

**Dependencies:**None

### Introduction {#nested-if-intro}

Mutt's format strings can contain embedded if-then-else conditions. They
are of the form:

    %?VAR?TRUE&FALSE?

If the variable “VAR” has a value greater than zero, print the “TRUE”
string, otherwise print the “FALSE” string.

e.g. `%?S?Size: %S&Empty?`

Which can be read as:

    if (%S > 0) { print "Size: %S" } else { print "Empty"
            }

These conditions are useful, but in Mutt they cannot be nested within
one another. This feature uses the notation `%<VAR?TRUE&FALSE>`and
allows them to be nested.

The `%<...>`notation was used to format the current local time. but
that's not really very useful since mutt has no means of refreshing the
screen periodically.

A simple nested condition might be: (Some whitespace has been introduced
for clarity)

    %<x? %<y? XY & X > & %<y? Y & NONE > >  Conditions
         %<y? XY & X >                      x>0
              XY                            x>0,y>0
                   X                        x>0,y=0

    %<x? %<y? XY & X > & %<y? Y & NONE > >  Conditions
                         %<y? Y & NONE >    x=0
                              Y             x=0,y>0
                                  NONE      x=0,y=0

Equivalent to:

    if (x > 0) { if (y > 0) { print 'XY' } else {
            print 'X' } } else { if (y > 0) { print 'Y' } else { print 'NONE' }
            }

Examples:

    set index_format='%4C %Z %{%b %d} %-25.25n %s%> %<M?%M Msgs &%<l?%l Lines&%c Bytes>>'

    if a thread is folded display the number of messages
            (%M) else if we know how many lines in the message display lines in
            message (%l) else display the size of the message in bytes
            (%c)

    set index_format='%4C %Z %{%b %d} %-25.25n %<M?[%M] %s&%s%* %<l?%l&%c>>'

    if a thread is folded display the number of messages
            (%M) display the subject (%s) else if we know how many lines in the
            message display lines in message (%l) else display the size of the
            message in bytes (%c)

### Variables {#nested-if-variables}

The “nested-if” feature doesn't have any config of its own. It modifies
the behavior of the format strings.

### Muttrc {#nested-if-muttrc}

    # Example NeoMutt config file for the nested-if feature.

    # This feature uses the format: '%<VAR?TRUE&FALSE>' for conditional
    # format strings that can be nested.

    # Example 1
    # if a thread is folded
    #       display the number of messages (%M)
    # else if we know how many lines in the message
    #       display lines in message (%l)
    # else display the size of the message in bytes (%c)
    set index_format='%4C %Z %{%b %d} %-25.25n %s%> %<M?%M Msgs &%<l?%l Lines&%c Bytes>>'
    # Example 2
    # if a thread is folded
    #       display the number of messages (%M)
    #       display the subject (%s)
    # else if we know how many lines in the message
    #       display lines in message (%l)
    # else
    #       display the size of the message in bytes (%c)
    set index_format='%4C %Z %{%b %d} %-25.25n %<M?[%M] %s&%s%* %<l?%l&%c>>'

            # vim: syntax=muttrc

### See Also {#nested-if-see-also}

-   [cond-date feature](#cond-date)

-   [\$index\_format](#index-format)

-   [\$status\_format](#status-format)

### Known Bugs {#nested-if-known-bugs}

Feature overwrites \$&lt;fmt&gt; handler in `$index_format`

### Credits {#nested-if-credits}

-   David Champion <dgc@uchicago.edu>

-   Richard Russon <rich@flatcap.org>

New Mail Feature {#new-mail-hook}
----------------

Execute a command upon the receipt of new mail.
### Support {#new-mail-support}

**Since:**NeoMutt 2016-07-23

**Dependencies:**None

### Introduction {#new-mail-intro}

This feature enables the new\_mail\_command setting, which can be used
to execute a custom script (e.g., a notification handler) upon receiving
a new mail.

The command string can contain expandos, such as `%f` for the folder
name. For a complete list, see: [\$status\_format](#status-format).

For example in Linux you can use (most distributions already provide
notify-send):

    set new_mail_command="notify-send --icon='/home/santiago/Pictures/mutt.png' 'New Email in %f' '%n new messages, %u unread.' &"

And in OS X you will need to install a command line interface for
Notification Center, for example
[terminal-notifier](https://github.com/julienXX/terminal-notifier):

    set new_mail_command="terminal-notifier -title '%v' -subtitle 'New Mail in %f' -message '%n new messages, %u unread.' -activate 'com.apple.Terminal'"

### Variables {#new-mail-variables}

  Name                 Type     Default
  -------------------- -------- ---------
  `new_mail_command`   string   (empty)

  : New Mail Command Variables

### Muttrc {#new-mail-muttrc}

    # Example NeoMutt config file for the new-mail feature.

    # --------------------------------------------------------------------------
    # VARIABLES - shown with their default values
    # --------------------------------------------------------------------------
    # Set the command you want mutt to execute upon the receipt of a new email
    set new_mail_command = ""
    # Linux example:
    # set new_command="notify-send --icon='/home/santiago/Pictures/mutt.png' 'New Email in %f' '%n new messages, %u unread.' &"
    # OS X example:
    # set new_mail_command="terminal-notifier -title '%v' -subtitle 'New Mail in %f' -message '%n new messages, %u unread.' -activate 'com.apple.Terminal'"
    # --------------------------------------------------------------------------
    # vim: syntax=muttrc

### See Also {#new-mail-see-also}

-   [folder-hook](#folder-hook)

### Known Bugs {#new-mail-known-bugs}

None

### Credits {#new-mail-credits}

-   Yoshiki Vazquez-Baeza <yoshiki@ucsd.edu>

-   Santiago Torres-Arias <santiago@nyu.edu>

-   Richard Russon <rich@flatcap.org>

NNTP Feature {#nntp}
------------

Talk to a Usenet news server
### Support {#nntp-support}

**Since:**NeoMutt 2016-05-30

**Dependencies:**None

### Introduction {#nntp-intro}

Reading news via NNTP

Mutt can read from a news server using NNTP.

The default news server can be obtained from the `$NNTPSERVER`
environment variable or from the `/etc/nntpserver` file. Like in other
news readers, information about the subscribed newsgroups is saved in
the file specified by the [\$newsrc](#newsrc) variable. You can open a
newsgroup with the function `<change-newsgroup>`

The variable [\$news\_cache\_dir](#news-cache-dir) can be used to point
to a directory. Mutt will create a hierarchy of subdirectories named
like the account and newsgroup the cache is for. The hierarchy is also
used to store header cache if Mutt was compiled with [header
cache](#header-caching) support.

### Variables {#nntp-variables}

  Name                      Type      Default
  ------------------------- --------- ----------------------------
  `ask_follow_up`           boolean   `no`
  `ask_x_comment_to`        boolean   `no`
  `catchup_newsgroup`       quad      `ask-yes`
  `followup_to_poster`      quad      `ask-yes`
  `group_index_format`      string    `%4C %M%N %5s %-45.45f %d`
  `inews`                   string    (empty)
  `mime_subject`            boolean   `yes`
  `newsgroups_charset`      string    `utf-8`
  `newsrc`                  string    `~/.newsrc`
  `news_cache_dir`          string    `~/.mutt`
  `news_server`             string    (empty)
  `nntp_authenticators`     string    (empty)
  `nntp_context`            number    `1000`
  `nntp_listgroup`          boolean   `yes`
  `nntp_load_description`   boolean   `yes`
  `nntp_pass`               string    (empty)
  `nntp_poll`               number    `60`
  `nntp_user`               string    (empty)
  `post_moderated`          quad      `ask-yes`
  `save_unsubscribed`       boolean   `no`
  `show_new_news`           boolean   `yes`
  `show_only_unread`        boolean   `no`
  `x_comment_to`            boolean   `no`

  : NNTP Variables

### Functions {#nntp-functions}

NNTP adds the following functions to Mutt. By default, none of them are
bound to keys.

  Menus                Function                        Description
  -------------------- ------------------------------- ------------------------------------------------
  browser,index        `<catchup>`                     mark all articles in newsgroup as read
  index,pager          `<change-newsgroup>`            open a different newsgroup
  compose              `<edit-followup-to>`            edit the Followup-To field
  compose              `<edit-newsgroups>`             edit the newsgroups list
  compose              `<edit-x-comment-to>`           edit the X-Comment-To field
  attach,index,pager   `<followup-message>`            followup to newsgroup
  index,pager          `<post-message>`                post message to newsgroup
  browser              `<reload-active>`               load list of all newsgroups from NNTP server
  browser              `<subscribe>`                   subscribe to current mbox (IMAP/NNTP only)
  browser              `<subscribe-pattern>`           subscribe to newsgroups matching a pattern
  browser              `<uncatchup>`                   mark all articles in newsgroup as unread
  browser              `<unsubscribe>`                 unsubscribe from current mbox (IMAP/NNTP only)
  browser              `<unsubscribe-pattern>`         unsubscribe from newsgroups matching a pattern
  index,pager          `<change-newsgroup-readonly>`   open a different newsgroup in read only mode
  attach,index,pager   `<forward-to-group>`            forward to newsgroup
  index                `<get-children>`                get all children of the current message
  index                `<get-parent>`                  get parent of the current message
  index                `<reconstruct-thread>`          reconstruct thread containing current message
  index                `<get-message>`                 get message with Message-Id

  : NNTP Functions

### Muttrc {#nntp-muttrc}

    # Example NeoMutt config file for the nntp feature.

    # --------------------------------------------------------------------------
    # VARIABLES - shown with their default values
    # --------------------------------------------------------------------------
    set ask_follow_up = no
    set ask_x_comment_to = no
    set catchup_newsgroup = ask-yes
    set followup_to_poster = ask-yes
    set group_index_format = '%4C %M%N %5s  %-45.45f %d'
    set inews = ''
    set mime_subject = yes
    set newsgroups_charset = utf-8
    set newsrc = '~/.newsrc'
    set news_cache_dir = '~/.mutt'
    set news_server = ''
    set nntp_authenticators = ''
    set nntp_context = 1000
    set nntp_listgroup = yes
    set nntp_load_description = yes
    set nntp_pass = ''
    set nntp_poll = 60
    set nntp_user = ''
    set post_moderated = ask-yes
    set save_unsubscribed = no
    set show_new_news = yes
    set show_only_unread = no
    set x_comment_to = no
    # --------------------------------------------------------------------------
    # FUNCTIONS - shown with an example mapping
    # --------------------------------------------------------------------------
    # mark all articles in newsgroup as read
    bind browser,index y catchup
    # open a different newsgroup
    bind index,pager i change-newsgroup
    # edit the Followup-To field
    bind compose o edit-followup-to
    # edit the newsgroups list
    bind compose N edit-newsgroups
    # edit the X-Comment-To field
    bind compose x edit-x-comment-to
    # followup to newsgroup
    bind attach,index,pager F followup-message
    # post message to newsgroup
    bind index,pager P post-message
    # load list of all newsgroups from NNTP server
    bind browser g reload-active
    # subscribe to current mbox (IMAP/NNTP only)
    bind browser s subscribe
    # subscribe to newsgroups matching a pattern
    bind browser S subscribe-pattern
    # mark all articles in newsgroup as unread
    bind browser Y uncatchup
    # unsubscribe from current mbox (IMAP/NNTP only)
    bind browser u unsubscribe
    # unsubscribe from newsgroups matching a pattern
    bind browser U unsubscribe-pattern
    # open a different newsgroup in read only mode
    bind index,pager \ei change-newsgroup-readonly
    # forward to newsgroup
    bind attach,index,pager \eF forward-to-group
    # get all children of the current message
    # bind index ??? get-children
    # get parent of the current message
    bind index \eG get-parent
    # reconstruct thread containing current message
    # bind index ??? reconstruct-thread
    # get message with Message-Id
    bind index \CG get-message
    # --------------------------------------------------------------------------
    # vim: syntax=muttrc

### See Also {#nntp-see-also}

-   [Compile-Time Features](#compile-time-features)

### Known Bugs {#nntp-known-bugs}

None

### Credits {#nntp-credits}

-   Vsevolod Volkov <vvv@mutt.org.ua>

-   Felix von Leitner <leitner@fefe.de>

-   Richard Russon <rich@flatcap.org>

Notmuch Feature {#notmuch}
---------------

Email search engine
### Support {#notmuch-support}

**Since:**NeoMutt 2016-03-17

**Dependencies:**

-   [quasi-delete feature](#quasi-delete)

-   [index-color feature](#index-color)

-   Notmuch libraries

### Introduction {#notmuch-intro}

Notmuch is an email fulltext indexing and tagging engine.

-   For more information, see: <https://notmuchmail.org/>

-   More examples: <https://notmuchmail.org/mutttips/>

### Using NotMuch {#notmuch-using}

#### Folders URI {#notmuch-folder-uri}

**notmuch://\[&lt;path&gt;\]\[?&lt;item&gt;=&lt;name&gt;\[& ...\]\]**

The &lt;path&gt; is an absolute path to the directory where the notmuch
database is found as returned by “notmuch config get database.path”
command. Note that the &lt;path&gt; should NOT include `.notmuch`
directory name.

If the "&lt;path&gt;" is not defined then `$nm_default_uri` or `$folder`
is used, for example:

    set nm_default_uri = "notmuch:///home/foo/maildir"
    virtual-mailboxes "My INBOX" "notmuch://?query=tag:inbox"

#### Items {#notmuch-items}

**query=&lt;string&gt;**

See SEARCH SYNTAX in notmuch man page. Don't forget to use operators (
“and”/ “or”) in your queries.

Note that proper URI should not contain blank space and all “bad” chars
should be encoded, for example

`tag:AAA and tag:BBB`--encoding-&gt; `tag:AAA%20and%20tag:BBB`

but mutt config file parser is smart enough to accept space in quoted
strings. It means that you can use

`notmuch:///foo?query=tag:AAA and tag:BBB`

in your config files to keep things readable.

For more details about Xapian queries, see:
<https://xapian.org/docs/queryparser.html>

**limit=&lt;number&gt;**

Restricts number of messages/threads in the result. The default limit is
nm\_db\_limit.

**type=&lt;threads|messages&gt;**

Reads all matching messages or whole-threads. The default is 'messages'
or nm\_query\_type.

#### Format String for the NotMuch Browser {#notmuch-vfolder-format}

Default: `%2C %?n?%4n/& ?%4m %f`

This variable allows you to customize the browser display to your
personal taste. This string is similar to
[\$index\_format](#index-format), but has its own set of
`printf(3)`-like sequences:

  -------- -----------------------------------------------------------------
  %C       current file number
  %f       folder name (description)
  %m       number of messages in the mailbox \*
  %n       number of unread messages in the mailbox \*
  %N       N if mailbox has new mail, blank otherwise
  %&gt;X   right justify the rest of the string and pad with character “X”
  %|X      pad to the end of the line with character “X”
  %\*X     soft-fill with character “X” as pad
  -------- -----------------------------------------------------------------

For an explanation of “soft-fill”, see the
[\$index\_format](#index-format) documentation.

\* = can be optionally printed if nonzero

### Variables {#notmuch-variables}

  --------------------------------------------------------------------------------------------------------------------
  Name                  Type      Default
  --------------------- --------- ------------------------------------------------------------------------------------
  `nm_db_limit`         number    `0`

  `nm_default_uri`      string    (empty)

  `nm_exclude_tags`     string    (empty)

  `nm_hidden_tags`      string    `
                                                    unread,draft,flagged,passed,replied,attachment,signed,encrypted`

  `nm_open_timeout`     number    `5`

  `nm_query_type`       string    `messages`

  `nm_record`           boolean   `no`

  `nm_record_tags`      string    (empty)

  `nm_unread_tag`       string    `unread`

  `vfolder_format`      string    `%6n(%6N) %f`

  `virtual_spoolfile`   boolean   `no`
  --------------------------------------------------------------------------------------------------------------------

  : Notmuch Variables

### Functions {#notmuch-functions}

Notmuch adds the following functions to Mutt. By default, none of them
are bound to keys.

  Menus         Function                      Description
  ------------- ----------------------------- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  index,pager   `<change-vfolder>`            switch to another virtual folder, a new folder maybe be specified by vfolder description (see virtual-mailboxes) or URI. the default is next vfolder with unread messages
  index,pager   `<entire-thread>`             read entire thread of the current message
  index,pager   `<modify-labels>`             add, remove, or toggle notmuch tags; \[+\]&lt;tag&gt; to add, -&lt;tag&gt; to remove, !&lt;tag&gt; to toggle(notmuch) tags. Note: Tab completion of tag names is available
  index,pager   `<modify-labels-then-hide>`   add, remove, or toggle notmuch tags; \[+\]&lt;tag&gt; to add, -&lt;tag&gt; to remove, !&lt;tag&gt; to togglelabels and then hide message by applying the "quasi-deleted" state. Normal redisplay rules apply here, so the user must call &lt;sync-mailbox&gt; for the changes to be displayed. Note: Tab completion of tag names is available.
  index,pager   `<sidebar-toggle-virtual>`    toggle between mailboxes and virtual mailboxes
  index,pager   `<vfolder-from-query>`        generate virtual folder from notmuch search query. Note: TAB completion of 'tag:' names is available.
  index,pager   `<vfolder-window-forward>`    generate virtual folder by moving the query's time window forward
  index,pager   `<vfolder-window-backward>`   generate virtual folder by moving the query's time window backward

  : Notmuch Functions

### Commands {#notmuch-commands}

virtual-mailboxes
description
notmuch-URI
description
notmuch-URI
unvirtual-mailboxes
\*
mailbox
tag-transforms
tag
transformed-string
tag
transformed-string
tag-formats
tag
format-string
tag
format-string
### Colors {#notmuch-colors}

Adds these to index-color feature:

  Object         Pattern   Highlights
  -------------- --------- ----------------------------------------------
  `index_tag`    yes       an individual message tag, %G, uses tag name
  `index_tags`   no        the transformed message tags, %g

  : Index Colors

### Muttrc {#notmuch-muttrc}

    # Example NeoMutt config file for the notmuch feature.

    # --------------------------------------------------------------------------
    # VARIABLES - shown with their default values
    # --------------------------------------------------------------------------
    # This variable specifies notmuch query limit.
    set nm_db_limit = 0
    # This variable specifies the default Notmuch database in format:
    # notmuch://<absolute path>
    set nm_default_uri = ""
    # The messages tagged with these tags are excluded and not loaded
    # from notmuch DB to mutt unless specified explicitly.
    set nm_exclude_tags = ""
    # This variable specifies private notmuch tags which should not be printed
    # on screen (index, pager).
    set nm_hidden_tags = "unread,draft,flagged,passed,replied,attachment,signed,encrypted"
    # This option specifies timeout for Notmuch database. Default is 5 seconds.
    set nm_open_timeout = 5
    # This variable specifies notmuch query type, supported types: 'threads' and
    # 'messages'.
    set nm_query_type = messages
    # Add messages stored to the mutt record (see $record in the mutt docs) also to notmuch DB. If you reply to an email then the new email inherits tags from the original email.

    set nm_record = no
    # Tags that should be removed or added to the to the messages stored in the mutt record.

    example:
    set record = "~/sent-mails"
    set nm_record = yes
    set nm_record_tags = "-inbox,archive,me"

    set nm_record_tags = ""
    # This variable specifies notmuch tag which is used for unread messages.
    set nm_unread_tag = unread
    # This variable allows you to customize the file browser display for virtual
    # folders to your personal taste.
    # %C   current folder number
    # %f   folder name (description)
    # %m   number of messages in the mailbox *
    # %n   number of unread messages in the mailbox *
    # %N   N if mailbox has new mail, blank otherwise
    # %>X  right justify the rest of the string and pad with character ``X''
    # %|X  pad to the end of the line with character ``X''
    # %*X  soft-fill with character ``X'' as pad

    set vfolder_format = "%6n(%6N) %f"
    # When set, mutt will use the first virtual mailbox (see virtual-mailboxes)
    # as a spoolfile.
    set virtual_spoolfile = no
    # setup time window preferences
    # first setup the duration, and then the time unit of that duration
    # when set to 0 (the default) the search window feature is disabled
    set nm_query_window_duration=2
    set nm_query_window_timebase="week" # or "hour", "day", "week", "month", "year"
    # --------------------------------------------------------------------------
    # FUNCTIONS - shown with an example mapping
    # --------------------------------------------------------------------------
    # open a different virtual folder
    bind index,pager X change-vfolder
    # read entire thread of the current message
    bind index,pager + entire-thread
    # modify (notmuch) tags
    bind index,pager \` modify-labels
    # modify (notmuch) tag non-interactively.
    bind index,pager tt "<modify-labels>!todo\n" "Toggle the 'todo' tag"
    # generate virtual folder from query
    bind index,pager \eX vfolder-from-query
    # generate virtual folder from query with time window
    bind index,pager < vfolder-window-backward
    bind index,pager > vfolder-window-forward
    # modify labels and then hide message
    # bind index,pager ??? modify-labels-then-hide
    # toggle between mailboxes and virtual mailboxes
    # bind index,pager ??? sidebar-toggle-virtual
    # --------------------------------------------------------------------------
    # COMMANDS - shown with an example
    # --------------------------------------------------------------------------
    # virtual-mailboxes description notmuch-URI { description notmuch-URI ...}
    # virtual-mailboxes "Climbing" "notmuch://?query=climbing"
    # unvirtual-mailboxes { * | mailbox ...}
    # Replace some tags with icons
    # tag-transforms tag transformed-string { tag transformed-string ...}
    # tag-transforms "inbox"   "i"   \
    #                "unread"  "u"   \
    #                "replied" "↻ "  \
    #                "sent"    "➥ "  \
    #                "todo"    "T"   \
    #                "deleted" "DEL" \
    #                "invites" "CAL"

    # The formats must start with 'G' and the entire sequence is case sensitive.
    # tag-formats tag format-string { tag format-string ...}
    # tag-formats "inbox"   "GI" \
    #              "unread"  "GU" \
    #              "replied" "GR" \
    #              "sent"    "GS" \
    #              "todo"    "Gt" \
    #              "deleted" "GD" \
    #              "invites" "Gi"

    # Now instead of using '%g' in your $index_format, which lists all tags
    # in a non-deterministic order, you can something like the following which puts
    # a transformed tag name in a specific spot on the index line:
    # set index_format='%4C %S %[%y.%m.%d] %-18.18n %?GU?%GU& ? %?GR?%GR& ? %?GI?%GI& ? %s'

    # The %G formatting sequence may display all tags including tags hidden by
    # nm_hidden_tags.
    #
    # --------------------------------------------------------------------------
    # COLORS - some unpleasant examples are given
    # --------------------------------------------------------------------------
    # These symbols are added to the index-color feature:
    # an individual message tag, %G, uses tag name
    # this symbol uses a pattern
    color index_tag red white "inbox"
    # the transformed message tags, %g
    # this symbol does not use a pattern
    color index_tags green default
    # --------------------------------------------------------------------------
    # vim: syntax=muttrc

### See Also {#notmuch-see-also}

-   [Compile-Time Features](#compile-time-features)

### Known Bugs {#notmuch-known-bugs}

None

### Credits {#notmuch-credits}

-   Karel Zak <kzak@redhat.com>

-   Chris Mason <clm@fb.com>

-   Christoph Rissner <cri@visotech.at>

-   David Riebenbauer <davrieb@liegesta.at>

-   David Sterba <dsterba@suse.cz>

-   David Wilson <dw@botanicus.net>

-   Don Zickus <dzickus@redhat.com>

-   Eric Davis <edavis@insanum.com>

-   Jan Synacek <jsynacek@redhat.com>

-   Jeremiah C. Foster <jeremiah@jeremiahfoster.com>

-   Josh Poimboeuf <jpoimboe@redhat.com>

-   Kirill A. Shutemov <kirill@shutemov.name>

-   Luke Macken <lmacken@redhat.com>

-   Mantas Mikulėnas <grawity@gmail.com>

-   Patrick Brisbin <pbrisbin@gmail.com>

-   Philippe Le Brouster <plb@nebkha.net>

-   Raghavendra D Prabhu <rprabhu@wnohang.net>

-   Sami Farin <hvtaifwkbgefbaei@gmail.com>

-   Stefan Assmann <sassmann@kpanic.de>

-   Stefan Kuhn <p_regius@gmx.ch>

-   Tim Stoakes <tim@stoakes.net>

-   Vladimir Marek <Vladimir.Marek@oracle.com>

-   Víctor Manuel Jáquez Leal <vjaquez@igalia.com>

-   Richard Russon <rich@flatcap.org>

-   Bernard 'Guyzmo' Pratz <guyzmo+github+pub@m0g.net>

Progress Bar Feature {#progress}
--------------------

Show a visual progress bar on slow operations
### Support {#progress-support}

**Since:**NeoMutt 2016-03-07

**Dependencies:**None

### Introduction {#progress-intro}

The “progress” feature shows a visual progress bar on slow tasks, such
as indexing a large folder over the net.

### Colors {#progress-colors}

  Name         Default Color   Description
  ------------ --------------- ---------------------
  `progress`   default         Visual progress bar

  : Progress Colors

### Muttrc {#progress-muttrc}

    # Example NeoMutt config file for the progress feature.

    # The 'progress' feature provides clear visual feedback for
    # slow tasks, such as indexing a large folder over the net.

    # Set the color of the progress bar
    # White text on a red background
    color progress white red

            # vim: syntax=muttrc

### See Also {#progress-see-also}

-   [Color command](#color)

### Known Bugs {#progress-known-bugs}

None

### Credits {#progress-credits}

-   Rocco Rutte <pdmef@gmx.net>

-   Vincent Lefevre <vincent@vinc17.org>

-   Stefan Kuhn <wuodan@hispeed.ch>

-   Karel Zak <kzak@redhat.com>

-   Richard Russon <rich@flatcap.org>

Quasi-Delete Feature {#quasi-delete}
--------------------

Mark emails that should be hidden, but not deleted
### Support {#quasi-delete-support}

**Since:**NeoMutt 2016-03-07

**Dependencies:**None

### Introduction {#quasi-delete-intro}

The “quasi-delete” function marks an email that should be hidden from
the index, but NOT deleted.

On its own, this feature isn't very useful. It forms a useful part of
the notmuch plugin.

### Functions {#quasi-delete-functions}

  Menus         Default Key   Function           Description
  ------------- ------------- ------------------ ---------------------------------------
  index,pager   (none)        `<quasi-delete>`   delete from mutt, don't touch on disk

  : Quasi-Delete Functions

### Muttrc {#quasi-delete-muttrc}

    # Example NeoMutt config file for the quasi-delete feature.

    # The 'quasi-delete' function marks an email that should be hidden
    # from the index, but NOT deleted.
    bind index,pager Q quasi-delete

            # vim: syntax=muttrc

### See Also {#quasi-delete-see-also}

-   [notmuch feature](#notmuch)

### Known Bugs {#quasi-delete-known-bugs}

None

### Credits {#quasi-delete-credits}

-   Karel Zak <kzak@redhat.com>

-   Richard Russon <rich@flatcap.org>

Reply With X-Original-To Feature {#reply-with-xorig-patch}
--------------------------------

Direct reply to email using X-Original-To header
### Support {#reply-with-xorig-support}

**Since:**NeoMutt 2016-09-10

**Dependencies:**None

### Introduction {#reply-with-xorig-intro}

Adds a reply\_with\_xorig for mutt configuration files. If enabled,
allows to reply to an email using the email address in the first
X-Original-To: header of a mail as the From: header of the answer.

### Variables {#reply-with-xorig-variables}

  Name                 Type      Default
  -------------------- --------- ---------
  `reply_with_xorig`   Boolean   `no`

  : Reply With X-Original-To Variables

### Muttrc {#reply-with-xorig-muttrc}

    # Example NeoMutt config file for the reply-with-xorig feature.

    # --------------------------------------------------------------------------
    # VARIABLES - shown with their default values
    # --------------------------------------------------------------------------
    # Use X-Original-To header to reply when reverse is disabled or no alternate
    # is found.
    set reply_with_xorig = "yes"

            # vim: syntax=muttrc

### Credits {#reply-with-xorig-credits}

-   Pierre-Elliott Bécue <becue@crans.org>

Sensible Browser Feature {#sensible-browser}
------------------------

Make the file browser behave
### Support {#sensible-browser-support}

**Since:**NeoMutt 2016-09-10

**Dependencies:**None

### Introduction {#sensible-browser-intro}

The “sensible browser” is a set of small changes to NeoMutt's mailbox
browser which make the browser behave in a more predictable way.

The behavior is divided into two use cases: Fixed Order; Variable Order.

#### A Fixed Order of Mailboxes {#sensible-browser-sort-fixed}

This is for users who like their mailboxes in a fixed order, e.g.
alphabetical, or unsorted (in the order of the config file).

    # Fixed order
    set sort_browser="alpha"
    set sort_browser="unsorted"

When you first start the browser, e.g. `c?`your current mailbox will be
highlighted.

When you navigate to a parent mailbox ( “..”) your old mailbox will be
highlighted.

“..”will always be listed at the top, however the rest of the list is
sorted.

#### A Variable Order of Mailboxes {#sensible-browser-sort-variable}

This is for users who like their mailboxes sorted by a characteristic
that changes, e.g. count of new mail, or the size of mailbox.

    # Variable order
    set sort_browser="reverse-count"
    set sort_browser="reverse-size"

When you first start the browser, e.g. `c?`the highlight will be on the
first mailbox, e.g. the one with the most new mail.

When you navigate to a parent mailbox ( “..”) your old mailbox will be
highlighted.

“..”will always be listed at the top, however the rest of the list is
sorted.

### See Also {#sensible-browser-see-also}

-   [\$folder\_format](#folder-format)

### Known Bugs {#sensible-browser-known-bugs}

None

### Credits {#sensible-browser-credits}

-   Pierre-Elliott Bécue <becue@crans.org>

-   Haakon Riiser <haakon.riiser@fys.uio.no>

-   Richard Russon <rich@flatcap.org>

Sidebar Feature {#sidebar}
---------------

Overview of mailboxes
### Support {#sidebar-support}

**Since:**NeoMutt 2016-09-10, Mutt 1.7.0

**Dependencies:**None

### Introduction {#sidebar-intro}

The Sidebar shows a list of all your mailboxes. The list can be turned
on and off, it can be themed and the list style can be configured.

This part of the manual is a reference guide. If you want a simple
introduction with examples see the [Sidebar Howto](#intro-sidebar). If
you just want to get started, you could use the sample [Sidebar
muttrc](#sidebar-muttrc).

### Variables {#sidebar-variables}

  Name                      Type      Default
  ------------------------- --------- ------------------
  `sidebar_delim_chars`     string    `/.`
  `sidebar_divider_char`    string    `|`
  `sidebar_folder_indent`   boolean   `no`
  `sidebar_format`          string    `%B%* %n`
  `sidebar_indent_string`   string    `  `(two spaces)
  `sidebar_new_mail_only`   boolean   `no`
  `sidebar_next_new_wrap`   boolean   `no`
  `sidebar_on_right`        boolean   `no`
  `sidebar_short_path`      boolean   `no`
  `sidebar_sort_method`     enum      `unsorted`
  `sidebar_visible`         boolean   `no`
  `sidebar_width`           number    `20`

  : Sidebar Variables

For more details, and examples, about the `$sidebar_format`, see the
[Sidebar Intro](#intro-sidebar-format).

### Functions {#sidebar-functions}

Sidebar adds the following functions to Mutt. By default, none of them
are bound to keys.

  Menus         Function                     Description
  ------------- ---------------------------- ------------------------------------------------------
  index,pager   `<sidebar-next>`             Move the highlight to next mailbox
  index,pager   `<sidebar-next-new>`         Move the highlight to next mailbox with new mail
  index,pager   `<sidebar-open>`             Open highlighted mailbox
  index,pager   `<sidebar-page-down>`        Scroll the Sidebar down 1 page
  index,pager   `<sidebar-page-up>`          Scroll the Sidebar up 1 page
  index,pager   `<sidebar-prev>`             Move the highlight to previous mailbox
  index,pager   `<sidebar-prev-new>`         Move the highlight to previous mailbox with new mail
  index,pager   `<sidebar-toggle-visible>`   Make the Sidebar (in)visible

  : Sidebar Functions

### Commands {#sidebar-commands}

sidebar\_whitelist
mailbox
mailbox
unsidebar\_whitelist
\*
mailbox
This command specifies mailboxes that will always be displayed in the
sidebar, even if [\$sidebar\_new\_mail\_only](#sidebar-new-mail-only) is
set and the mailbox does not contain new mail.

The “unsidebar\_whitelist” command is used to remove a mailbox from the
list of whitelisted mailboxes. Use “unsidebar\_whitelist \*”to remove
all mailboxes.

### Colors {#sidebar-colors}

  Name                  Default Color      Description
  --------------------- ------------------ ------------------------------------------------------------------
  `sidebar_divider`     default            The dividing line between the Sidebar and the Index/Pager panels
  `sidebar_flagged`     default            Mailboxes containing flagged mail
  `sidebar_highlight`   underline          Cursor to select a mailbox
  `sidebar_indicator`   mutt `indicator`   The mailbox open in the Index panel
  `sidebar_new`         default            Mailboxes containing new mail
  `sidebar_ordinary`    default            Mailboxes that have no new/flagged mails, etc
  `sidebar_spoolfile`   default            Mailbox that receives incoming mail

  : Sidebar Colors

If the `sidebar_indicator` color isn't set, then the default Mutt
indicator color will be used (the color used in the index panel).

### Sort {#sidebar-sort}

  Sort         Description
  ------------ ----------------------------------
  `alpha`      Alphabetically by path
  `count`      Total number of messages
  `flagged`    Number of flagged messages
  `name`       Alphabetically by path
  `new`        Number of unread messages
  `path`       Alphabetically by path
  `unread`     Number of unread messages
  `unsorted`   Order of the `mailboxes` command

  : Sidebar Sort

### Muttrc {#sidebar-muttrc}

    # Example NeoMutt config file for the sidebar feature.

    # --------------------------------------------------------------------------
    # VARIABLES - shown with their default values
    # --------------------------------------------------------------------------
    # Should the Sidebar be shown?
    set sidebar_visible = no
    # How wide should the Sidebar be in screen columns?

    # Note: Some characters, e.g. Chinese, take up two columns each.
    set sidebar_width = 20
    # Should the mailbox paths be abbreviated?
    set sidebar_short_path = no
    # When abbreviating mailbox path names, use any of these characters as path
    # separators.  Only the part after the last separators will be shown.

    # For file folders '/' is good.  For IMAP folders, often '.' is useful.
    set sidebar_delim_chars = '/.'
    # If the mailbox path is abbreviated, should it be indented?
    set sidebar_folder_indent = no
    # Indent mailbox paths with this string.
    set sidebar_indent_string = '  '
    # Make the Sidebar only display mailboxes that contain new, or flagged,
    # mail.
    set sidebar_new_mail_only = no
    # Any mailboxes that are whitelisted will always be visible, even if the
    # sidebar_new_mail_only option is enabled.
    sidebar_whitelist '/home/user/mailbox1'
    sidebar_whitelist '/home/user/mailbox2'
    # When searching for mailboxes containing new mail, should the search wrap
    # around when it reaches the end of the list?
    set sidebar_next_new_wrap = no
    # Show the Sidebar on the right-hand side of the screen
    set sidebar_on_right = no
    # The character to use as the divider between the Sidebar and the other Mutt
    # panels.
    set sidebar_divider_char = '|'
    # Enable extended buffy mode to calculate total, new, and flagged
    # message counts for each mailbox.
    set mail_check_stats
    # Display the Sidebar mailboxes using this format string.
    set sidebar_format = '%B%?F? [%F]?%* %?N?%N/?%S'
    # Sort the mailboxes in the Sidebar using this method:
    #       count    - total number of messages
    #       flagged  - number of flagged messages
    #       new      - number of new messages
    #       path     - mailbox path
    #       unsorted - do not sort the mailboxes
    set sidebar_sort_method = 'unsorted'
    # --------------------------------------------------------------------------
    # FUNCTIONS - shown with an example mapping
    # --------------------------------------------------------------------------
    # Move the highlight to the previous mailbox
    bind index,pager \Cp sidebar-prev
    # Move the highlight to the next mailbox
    bind index,pager \Cn sidebar-next
    # Open the highlighted mailbox
    bind index,pager \Co sidebar-open
    # Move the highlight to the previous page
    # This is useful if you have a LOT of mailboxes.
    bind index,pager <F3> sidebar-page-up
    # Move the highlight to the next page
    # This is useful if you have a LOT of mailboxes.
    bind index,pager <F4> sidebar-page-down
    # Move the highlight to the previous mailbox containing new, or flagged,
    # mail.
    bind index,pager <F5> sidebar-prev-new
    # Move the highlight to the next mailbox containing new, or flagged, mail.
    bind index,pager <F6> sidebar-next-new
    # Toggle the visibility of the Sidebar.
    bind index,pager B sidebar-toggle-visible
    # --------------------------------------------------------------------------
    # COLORS - some unpleasant examples are given
    # --------------------------------------------------------------------------
    # Note: All color operations are of the form:
    #       color OBJECT FOREGROUND BACKGROUND
    # Color of the current, open, mailbox
    # Note: This is a general Mutt option which colors all selected items.
    color indicator cyan black
    # Color of the highlighted, but not open, mailbox.
    color sidebar_highlight black color8
    # Color of the divider separating the Sidebar from Mutt panels
    color sidebar_divider color8 black
    # Color to give mailboxes containing flagged mail
    color sidebar_flagged red black
    # Color to give mailboxes containing new mail
    color sidebar_new green black
    # Color to give mailboxes containing no new/flagged mail, etc
    color sidebar_ordinary color245 default
    # --------------------------------------------------------------------------
    # vim: syntax=muttrc

### See Also {#sidebar-see-also}

-   [Regular Expressions](#regexp)

-   [Patterns](#patterns)

-   [Color command](#color)

-   [notmuch feature](#notmuch)

### Known Bugs {#sidebar-known-bugs}

None

### Credits {#sidebar-credits}

-   Justin Hibbits <jrh29@po.cwru.edu>

-   Thomer M. Gil <mutt@thomer.com>

-   David Sterba <dsterba@suse.cz>

-   Evgeni Golov <evgeni@debian.org>

-   Fabian Groffen <grobian@gentoo.org>

-   Jason DeTiberus <jdetiber@redhat.com>

-   Stefan Assmann <sassmann@kpanic.de>

-   Steve Kemp <steve@steve.org.uk>

-   Terry Chan <tchan@lunar-linux.org>

-   Tyler Earnest <tylere@rne.st>

-   Richard Russon <rich@flatcap.org>

Skip Quoted Feature {#skip-quoted-patch}
-------------------

Leave some context visible
### Support {#skip-quoted-support}

**Since:**NeoMutt 2016-03-28

**Dependencies:**None

### Introduction {#skip-quoted-intro}

When viewing an email, the `<skip-to-quoted>`function (by default the
`S` key) will scroll past any email headers or quoted text. Sometimes, a
little context is useful.

By setting the `$skip_quoted_offset` variable, you can select how much
of the quoted text is left visible.

### Variables {#skip-quoted-variables}

  Name                   Type     Default
  ---------------------- -------- ---------
  `skip_quoted_offset`   number   0

  : Skip-Quoted Variables

### Muttrc {#skip-quoted-muttrc}

    # Example NeoMutt config file for the skip-quoted feature.

    # The 'S' (skip-quoted) command scrolls the pager past the quoted text (usually
    # indented with '> '.  Setting 'skip_quoted_offset' leaves some lines of quoted
    # text on screen for context.

    # Show three quoted lines before the reply
    set skip_quoted_offset = 3

            # vim: syntax=muttrc

### Known Bugs {#skip-quoted-known-bugs}

None

### Credits {#skip-quoted-credits}

-   David Sterba <dsterba@suse.cz>

-   Richard Russon <rich@flatcap.org>

Status Color Feature {#status-color}
--------------------

Custom rules for theming the status bar
### Support {#status-color-support}

**Since:**NeoMutt 2016-03-07

**Dependencies:**None

### Introduction {#status-color-intro}

The “status-color” feature allows you to theme different parts of the
status bar (also when it's used by the index).

Unlike normal color commands, `color status` can now take up to 2 extra
parameters (regex, num).

### Commands {#status-color-commands}

color
status
foreground
background
regex
num
With zero parameters, Mutt will set the default color for the entire
status bar.

With one parameter, Mutt will only color the parts matching the regex.

With two parameters, Mutt will only color the num'th sub-match of the
regex.

### Colors {#status-color-colors}

  Name     Default Color   Description
  -------- --------------- -------------
  status   `reverse`       Status bar

  : Status Colors

### Muttrc {#status-color-muttrc}

    # Example NeoMutt config file for the status-color feature.

    # The 'status-color' feature allows you to theme different parts of
    # the status bar (also when it's used by the index).

    # For the examples below, set some defaults
    set status_format='-%r-Mutt: %f [Msgs:%?M?%M/?%m%?n? New:%n?%?o? Old:%o?%?d? Del:%d?%?F? Flag:%F?%?t? Tag:%t?%?p? Post:%p?%?b? Inc:%b?%?l? %l?]---(%s/%S)-%>-(%P)---'
    set index_format='%4C %Z %{%b %d} %-15.15L (%?l?%4l&%4c?) %s'
    set sort=threads
    set sort_aux=last-date-received
    # 'status color' can take up to 2 extra parameters
    # color status foreground background [ regex [ num ]]
    # 0 extra parameters
    # Set the default color for the entire status line
    color status blue white
    # 1 extra parameter
    # Set the color for a matching pattern
    # color status foreground background regexp
    # Highlight New, Deleted, or Flagged emails
    color status brightred white '(New|Del|Flag):[0-9]+'
    # Highlight mailbox ordering if it's different from the default
    # First, highlight anything (*/*)
    color status brightred default '\([^)]+/[^)]+\)'
    # Then override the color for one specific case
    color status default   default '\(threads/last-date-received\)'
    # 2 extra parameters
    # Set the color for the nth submatch of a pattern
    # color status foreground background regexp num
    # Highlight the contents of the []s but not the [] themselves
    color status red default '\[([^]]+)\]' 1
    # The '1' refers to the first regex submatch, which is the inner
    # part in ()s
    # Highlight the mailbox
    color status brightwhite default 'Mutt: ([^ ]+)' 1
    # Search for 'Mutt: ' but only highlight what comes after it
    # vim: syntax=muttrc

### See Also {#status-color-see-also}

-   [Compile-Time Features](#compile-time-features)

-   [Regular Expressions](#regexp)

-   [Patterns](#patterns)

-   [index-color feature](#index-color)

-   [Color command](#color)

### Known Bugs {#status-color-known-bugs}

None

### Credits {#status-color-credits}

-   David Sterba <dsterba@suse.cz>

-   Thomas Glanzmann <thomas@glanzmann.de>

-   Kirill A. Shutemov <kirill@shutemov.name>

-   Richard Russon <rich@flatcap.org>

TLS-SNI Feature {#tls-sni}
---------------

Negotiate with a server for a TLS/SSL certificate
### Support {#tls-sni-support}

**Since:**NeoMutt 2016-03-07

**Dependencies:**

:   OpenSSL

### Introduction {#tls-sni-intro}

The “TLS-SNI” feature adds support for TLS virtual hosting. If your mail
server doesn't support this everything will still work normally.

TLS supports sending the expected server hostname during the handshake,
via the SNI extension. This can be used to select a server certificate
to issue to the client, permitting virtual-hosting without requiring
multiple IP addresses.

This has been tested against Exim 4.80, which optionally logs SNI and
can perform vhosting.

To verify TLS SNI support by a server, you can use:

    openssl s_client -host <imap server> -port <port> -tls1 -servername <imap server>

### Known Bugs {#tls-sni-known-bugs}

None

### Credits {#tls-sni-credits}

-   Jeremy Katz <katzj@linuxpower.org>

-   Phil Pennock <mutt-dev@spodhuis.demon.nl>

-   Richard Russon <rich@flatcap.org>

Trash Folder Feature {#trash-folder}
--------------------

Automatically move deleted emails to a trash bin
### Support {#trash-folder-support}

**Since:**NeoMutt 2016-09-10, Mutt 1.7.0

**Dependencies:**

:   If IMAP is enabled, the trash folder will use it wisely

### Introduction {#trash-folder-intro}

In Mutt, when you “delete” an email it is first marked deleted. The
email isn't really gone until [&lt;sync-mailbox&gt;](#index-map)is
called. This happens when the user leaves the folder, or the function is
called manually.

After `<sync-mailbox>`has been called the email is gone forever.

The [\$trash](#trash) variable defines a folder in which to keep old
emails. As before, first you mark emails for deletion. When
&lt;sync-mailbox&gt; is called the emails are moved to the trash folder.

The `$trash` path can be either a full directory, or be relative to the
[\$folder](#folder) variable, like the `mailboxes` command.

> **Note**
>
> Emails deleted from the trash folder are gone forever.

### Variables {#trash-folder-variables}

  Name    Type     Default
  ------- -------- ---------
  trash   string   (none)

  : Trash Variables

### Functions {#trash-folder-functions}

  Menus         Default Key   Function            Description
  ------------- ------------- ------------------- -------------------------------------------------------------
  index,pager   (none)        `<purge-message>`   really delete the current entry, bypassing the trash folder

  : Trash Functions

### Muttrc {#trash-folder-muttrc}

    # Example Mutt config file for the 'trash' feature.

    # This feature defines a new 'trash' folder.

    # When mail is deleted it will be moved to this folder.

    # Folder in which to put deleted emails
    set trash='+Trash'
    set trash='/home/flatcap/Mail/Trash'
    # The default delete key 'd' will move an email to the 'trash' folder
    # Bind 'D' to REALLY delete an email
    bind index D purge-message
    # Note: Deleting emails from the 'trash' folder will REALLY delete them.

    # vim: syntax=muttrc

### See Also {#trash-folder-see-also}

-   [folder-hook](#folder-hook)

### Known Bugs {#trash-folder-known-bugs}

None

### Credits {#trash-folder-credits}

-   Cedric Duval <cedricduval@free.fr>

-   Benjamin Kuperman <kuperman@acm.org>

-   Paul Miller <paul@voltar.org>

-   Richard Russon <rich@flatcap.org>

Security Considerations {#security}
=======================

First of all, Mutt contains no security holes included by intention but
may contain unknown security holes. As a consequence, please run Mutt
only with as few permissions as possible. Especially, do not run Mutt as
the super user.

When configuring Mutt, there're some points to note about secure setups
so please read this chapter carefully.

Passwords {#security-passwords}
---------

Although Mutt can be told the various passwords for accounts, please
never store passwords in configuration files. Besides the fact that the
system's operator can always read them, you could forget to mask it out
when reporting a bug or asking for help via a mailing list. Even worse,
your mail including your password could be archived by internet search
engines, mail-to-news gateways etc. It may already be too late before
you notice your mistake.

Temporary Files {#security-tempfiles}
---------------

Mutt uses many temporary files for viewing messages, verifying digital
signatures, etc. As long as being used, these files are visible by other
users and maybe even readable in case of misconfiguration. Also, a
different location for these files may be desired which can be changed
via the [\$tmpdir](#tmpdir) variable.

Information Leaks {#security-leaks}
-----------------

### Message-Id: headers {#security-leaks-mid}

Message-Id: headers contain a local part that is to be created in a
unique fashion. In order to do so, Mutt will “leak” some information to
the outside world when sending messages: the generation of this header
includes a step counter which is increased (and rotated) with every
message sent. In a longer running mutt session, others can make
assumptions about your mailing habits depending on the number of
messages sent. If this is not desired, the header can be manually
provided using [\$edit\_headers](#edit-headers)(though not recommended).

### `mailto:`-style Links {#security-leaks-mailto}

As Mutt be can be set up to be the mail client to handle `mailto:`style
links in websites, there're security considerations, too. Arbitrary
header fields can be embedded in these links which could override
existing header fields or attach arbitrary files using [the Attach:
pseudoheader](#attach-header). This may be problematic if the
[\$edit-headers](#edit-headers) variable is *unset*, i.e. the user
doesn't want to see header fields while editing the message and doesn't
pay enough attention to the compose menu's listing of attachments.

For example, following a link like

    mailto:joe@host?Attach=~/.gnupg/secring.gpg

will send out the user's private gnupg keyring to `joe@host` if the user
doesn't follow the information on screen carefully enough.

To prevent these issues, Mutt by default only accepts the `Subject` and
`Body` headers. Allowed headers can be adjusted with the
[`mailto_allow`](#mailto-allow)and
[`unmailto_allow`](#mailto-allow)commands.

External Applications {#security-external}
---------------------

Mutt in many places has to rely on external applications or for
convenience supports mechanisms involving external applications.

One of these is the `mailcap` mechanism as defined by RfC1524. Details
about a secure use of the mailcap mechanisms is given in
[Secure Use of Mailcap](#secure-mailcap).

Besides the mailcap mechanism, Mutt uses a number of other external
utilities for operation, for example to provide crypto support, in
backtick expansion in configuration files or format string filters. The
same security considerations apply for these as for tools involved via
mailcap.

Performance Tuning {#tuning}
==================

Reading and Writing Mailboxes {#tuning-mailboxes}
-----------------------------

Mutt's performance when reading mailboxes can be improved in two ways:

1.  For remote folders (IMAP and POP) as well as folders using
    one-file-per message storage (Maildir and MH), Mutt's performance
    can be greatly improved using [header caching](#header-caching).
    using a single database per folder.

2.  Mutt provides the [\$read\_inc](#read-inc) and
    [\$write\_inc](#write-inc) variables to specify at which rate to
    update progress counters. If these values are too low, Mutt may
    spend more time on updating the progress counter than it spends on
    actually reading/writing folders.

    For example, when opening a maildir folder with a few thousand
    messages, the default value for [\$read\_inc](#read-inc) may be
    too low. It can be tuned on on a folder-basis using
    [`folder-hook`s](#folder-hook):

        # use very high $read_inc to speed up reading hcache'd maildirs
        folder-hook . 'set read_inc=1000'
        # use lower value for reading slower remote IMAP folders
        folder-hook ^imap 'set read_inc=100'
        # use even lower value for reading even slower remote POP folders
        folder-hook ^pop 'set read_inc=1'

These settings work on a per-message basis. However, as messages may
greatly differ in size and certain operations are much faster than
others, even per-folder settings of the increment variables may not be
desirable as they produce either too few or too much progress updates.
Thus, Mutt allows to limit the number of progress updates per second
it'll actually send to the terminal using the [\$time\_inc](#time-inc)
variable.

Reading Messages from Remote Folders {#tuning-messages}
------------------------------------

Reading messages from remote folders such as IMAP an POP can be slow
especially for large mailboxes since Mutt only caches a very limited
number of recently viewed messages (usually 10) per session (so that it
will be gone for the next session.)

To improve performance and permanently cache whole messages, please
refer to Mutt's so-called [body caching](#body-caching) for details.

Searching and Limiting {#tuning-search}
----------------------

When searching mailboxes either via a search or a limit action, for some
patterns Mutt distinguishes between regular expression and string
searches. For regular expressions, patterns are prefixed with “\~”and
with “=”for string searches.

Even though a regular expression search is fast, it's several times
slower than a pure string search which is noticeable especially on large
folders. As a consequence, a string search should be used instead of a
regular expression search if the user already knows enough about the
search pattern.

For example, when limiting a large folder to all messages sent to or by
an author, it's much faster to search for the initial part of an e-mail
address via `=Luser@`instead of `~Luser@`. This is especially true for
searching message bodies since a larger amount of input has to be
searched.

As for regular expressions, a lower case string search pattern makes
Mutt perform a case-insensitive search except for IMAP (because for IMAP
Mutt performs server-side searches which don't support
case-insensitivity).

Reference
=========

Command-Line Options {#commandline}
--------------------

Running `mutt` with no arguments will make Mutt attempt to read your
spool mailbox. However, it is possible to read other mailboxes and to
send messages from the command line as well.

  Option   Description
  -------- ------------------------------------------------------------------------------------------------------------------------------------------------------
  -A       expand an alias
  -a       attach a file to a message
  -b       specify a blind carbon-copy (BCC) address
  -c       specify a carbon-copy (Cc) address
  -d       log debugging output to \~/.muttdebug0 if mutt was compiled with `+debug`; it can range from 1-5 and affects verbosity (a value of 2 is recommended)
  -D       print the value of all Mutt variables to stdout
  -D -S    like -D but hide the value of sensitive variables
  -E       edit the draft (-H) or include (-i) file
  -e       specify a config command to be run after initialization files are read
  -f       specify a mailbox to load
  -F       specify an alternate file to read initialization commands
  -h       print help on command line options
  -H       specify a draft file from which to read a header and body
  -i       specify a file to include in a message composition
  -m       specify a default mailbox type
  -n       do not read the system Muttrc
  -p       recall a postponed message
  -Q       query a configuration variable
  -R       open mailbox in read-only mode
  -s       specify a subject (enclose in quotes if it contains spaces)
  -v       show version number and compile-time definitions
  -x       simulate the mailx(1) compose mode
  -y       show a menu containing the files specified by the `mailboxes` command
  -z       exit immediately if there are no messages in the mailbox
  -Z       open the first folder with new message, exit immediately if none

  : Command line options

To read messages in a mailbox

mutt
-nz
-F
muttrc
-m
type
-f
mailbox
To compose a new message

mutt
-En
-F
muttrc
-c
address
-Hi
filename
-s
subject
-a
file
--
address
mailto\_url
Mutt also supports a “batch” mode to send prepared messages. Simply
redirect input from the file you wish to send. For example,

    mutt -s "data set for run #2" professor@bigschool.edu < ~/run2.dat

will send a message to `<professor@bigschool.edu>`with a subject of
“data set for run \#2”. In the body of the message will be the contents
of the file “\~/run2.dat”.

An include file passed with `-i` will be used as the body of the
message. When combined with `-E`, the include file will be directly
edited during message composition. The file will be modified regardless
of whether the message is sent or aborted.

A draft file passed with `-H` will be used as the initial header and
body for the message. Multipart messages can be used as a draft file.
When combined with `-E`, the draft file will be updated to the final
state of the message after composition, regardless of whether the
message is sent, aborted, or even postponed. Note that if the message is
sent encrypted or signed, the draft file will be saved that way too.

All files passed with `-a` *file* will be attached as a MIME part to the
message. To attach a single or several files, use “--”to separate files
and recipient addresses:

    mutt -a image.png -- some@one.org

or

    mutt -a *.png -- some@one.org

> **Note**
>
> The `-a` option must be last in the option list.

In addition to accepting a list of email addresses, Mutt also accepts a
URL with the `mailto:`schema as specified in RFC2368. This is useful
when configuring a web browser to launch Mutt when clicking on mailto
links.

    mutt mailto:some@one.org?subject=test&cc=other@one.org

Configuration Commands {#commands}
----------------------

The following are the commands understood by Mutt:

-   account-hook
    regexp
    command
-   alias
    -group
    name
    key
    address
    address
    unalias
    -group
    name
    \*
    key
-   alternates
    -group
    name
    regexp
    regexp
    unalternates
    -group
    name
    \*
    regexp
-   alternative\_order
    mimetype
    mimetype
    unalternative\_order
    \*
    mimetype
-   attachments
    { + | - }disposition
    mime-type
    unattachments
    { + | - }disposition
    mime-type
-   append-hook
    pattern
    shell-command
-   auto\_view
    mimetype
    mimetype
    unauto\_view
    \*
    mimetype
-   bind
    map
    key
    function
-   charset-hook
    alias
    charset
-   iconv-hook
    charset
    local-charset
-   close-hook
    pattern
    shell-command
-   color
    object
    foreground
    background
    color
    header
    body
    foreground
    background
    regexp
    color
    index
    foreground
    background
    pattern
    uncolor
    index
    header
    body
    \*
    pattern
-   open-hook
    pattern
    shell-command
-   crypt-hook
    regexp
    keyid
-   exec
    function
    function
-   fcc-hook
    \[!\]pattern
    mailbox
-   fcc-save-hook
    \[!\]pattern
    mailbox
-   folder-hook
    \[!\]regexp
    command
-   group
    -group
    name
    -rx
    expr
    -addr
    expr
    ungroup
    -group
    name
    \*
    -rx
    expr
    -addr
    expr
-   hdr\_order
    header
    header
    unhdr\_order
    \*
    header
-   ifdef
    item
    "config-command \[args\]"
-   ignore
    pattern
    pattern
    unignore
    \*
    pattern
-   lists
    -group
    name
    regexp
    regexp
    unlists
    -group
    name
    \*
    regexp
-   macro
    menu
    key
    sequence
    description
-   mailboxes
    mailbox
    mailbox
    unmailboxes
    \*
    mailbox
-   mailto\_allow
    \*
    header-field
    unmailto\_allow
    \*
    header-field
-   mbox-hook
    \[!\]regexp
    mailbox
-   message-hook
    \[!\]pattern
    command
-   mime\_lookup
    mimetype
    mimetype
    unmime\_lookup
    \*
    mimetype
-   mono
    object
    attribute
    mono
    header
    body
    attribute
    regexp
    mono
    index
    attribute
    pattern
    unmono
    index
    header
    body
    \*
    pattern
-   my\_hdr
    string
    unmy\_hdr
    \*
    field
-   push
    string
-   save-hook
    \[!\]pattern
    mailbox
-   score
    pattern
    value
    unscore
    \*
    pattern
-   reply-hook
    \[!\]pattern
    command
-   send-hook
    \[!\]pattern
    command
-   send2-hook
    \[!\]pattern
    command
-   set
    no
    inv
    variable
    variable=value
    toggle
    variable
    variable
    unset
    variable
    variable
    reset
    variable
    variable
-   setenv
    \[?\]variable
    value
    unsetenv
    variable
-   sidebar\_whitelist
    mailbox
    mailbox
    unsidebar\_whitelist
    \*
    mailbox
-   source
    filename
-   spam
    pattern
    format
    nospam
    \*
    pattern
-   subjectrx
    pattern
    replacement
    unsubjectrx
    \*
    pattern
-   subscribe
    -group
    name
    regexp
    regexp
    unsubscribe
    -group
    name
    \*
    regexp
-   unhook
    \*
    hook-type

Configuration Variables {#variables}
-----------------------

### abort\_noattach {#abort-noattach}

    Type: quadoption
    Default: no

If set to *yes*, when composing messages containing the regular
expression specified by [attach\_keyword](#attach-keyword) and no
attachments \*\* are given, composition will be aborted. If set to *no*,
composing \*\* messages as such will never be aborted.

Example:

    set attach_keyword = "\\<attach(|ed|ments?)\\>"

### abort\_nosubject {#abort-nosubject}

    Type: quadoption
    Default: ask-yes

If set to *yes*, when composing messages and no subject is given at the
subject prompt, composition will be aborted. If set to *no*, composing
messages with no subject given at the subject prompt will never be
aborted.

### abort\_unmodified {#abort-unmodified}

    Type: quadoption
    Default: yes

If set to *yes*, composition will automatically abort after editing the
message body if no changes are made to the file (this check only happens
after the *first* edit of the file). When set to *no*, composition will
never be aborted.

### alias\_file {#alias-file}

    Type: path
    Default: ~/.muttrc

The default file in which to save aliases created by the
`<create-alias>` function. Entries added to this file are encoded in the
character set specified by [\$config\_charset](#config-charset) if it is
*set* or the current character set otherwise.

**Note:** Mutt will not automatically source this file; you must
explicitly use the “[source](#source)” command for it to be executed in
case this option points to a dedicated alias file.

The default for this option is the currently used muttrc file, or
“\~/.muttrc” if no user muttrc was found.

### alias\_format {#alias-format}

    Type: string
    Default: %4n %2f %t %-10a   %r

Specifies the format of the data displayed for the “[alias](#alias)”
menu. The following `printf(3)`-style sequences are available:

  ---- ----------------------------------------------------------------
  %a   alias name
  %f   flags - currently, a “d” for an alias marked for deletion
  %n   index number
  %r   address which alias expands to
  %t   character which indicates if the alias is tagged for inclusion
  ---- ----------------------------------------------------------------

### allow\_8bit {#allow-8bit}

    Type: boolean
    Default: yes

Controls whether 8-bit data is converted to 7-bit using either Quoted-
Printable or Base64 encoding when sending mail.

### allow\_ansi {#allow-ansi}

    Type: boolean
    Default: no

Controls whether ANSI color codes in messages (and color tags in rich
text messages) are to be interpreted. Messages containing these codes
are rare, but if this option is *set*, their text will be colored
accordingly. Note that this may override your color choices, and even
present a security problem, since a message could include a line like

    [-- PGP output follows ...

and give it the same color as your attachment color (see also
[\$crypt\_timestamp](#crypt-timestamp)).

### arrow\_cursor {#arrow-cursor}

    Type: boolean
    Default: no

When *set*, an arrow (“-&gt;”) will be used to indicate the current
entry in menus instead of highlighting the whole line. On slow network
or modem links this will make response faster because there is less that
has to be redrawn on the screen when moving to the next or previous
entries in the menu.

### ascii\_chars {#ascii-chars}

    Type: boolean
    Default: no

If *set*, Mutt will use plain ASCII characters when displaying thread
and attachment trees, instead of the default *ACS* characters.

### askbcc

    Type: boolean
    Default: no

If *set*, Mutt will prompt you for blind-carbon-copy (Bcc) recipients
before editing an outgoing message.

### askcc

    Type: boolean
    Default: no

If *set*, Mutt will prompt you for carbon-copy (Cc) recipients before
editing the body of an outgoing message.

### ask\_follow\_up {#ask-follow-up}

    Type: boolean
    Default: no

If set, Mutt will prompt you for follow-up groups before editing the
body of an outgoing message.

### ask\_x\_comment\_to {#ask-x-comment-to}

    Type: boolean
    Default: no

If set, Mutt will prompt you for x-comment-to field before editing the
body of an outgoing message.

### assumed\_charset {#assumed-charset}

    Type: string
    Default: (empty)

This variable is a colon-separated list of character encoding schemes
for messages without character encoding indication. Header field values
and message body content without character encoding indication would be
assumed that they are written in one of this list. By default, all the
header fields and message body without any charset indication are
assumed to be in “us-ascii”.

For example, Japanese users might prefer this:

    set assumed_charset="iso-2022-jp:euc-jp:shift_jis:utf-8"

However, only the first content is valid for the message body.

### attach\_charset {#attach-charset}

    Type: string
    Default: (empty)

This variable is a colon-separated list of character encoding schemes
for text file attachments. Mutt uses this setting to guess which
encoding files being attached are encoded in to convert them to a proper
character set given in [\$send\_charset](#send-charset).

If *unset*, the value of [\$charset](#charset) will be used instead. For
example, the following configuration would work for Japanese text
handling:

    set attach_charset="iso-2022-jp:euc-jp:shift_jis:utf-8"

Note: for Japanese users, “iso-2022-\*” must be put at the head of the
value as shown above if included.

### attach\_format {#attach-format}

    Type: string
    Default: %u%D%I %t%4n %T%.40d%> [%.7m/%.10M, %.6e%?C?, %C?, %s] 

This variable describes the format of the “attachment” menu. The
following `printf(3)`-style sequences are understood:

  -------- -------------------------------------------------------------------------------------------------------------------------------------------------
  %C       charset
  %c       requires charset conversion (“n” or “c”)
  %D       deleted flag
  %d       description (if none, falls back to %F)
  %e       MIME content-transfer-encoding
  %F       filename in content-disposition header (if none, falls back to %f)
  %f       filename
  %I       disposition (“I” for inline, “A” for attachment)
  %m       major MIME type
  %M       MIME subtype
  %n       attachment number
  %Q       “Q”, if MIME part qualifies for attachment counting
  %s       size
  %t       tagged flag
  %T       graphic tree characters
  %u       unlink (=to delete) flag
  %X       number of qualifying MIME parts in this part and its children (please see the “[attachments](#attachments)” section for possible speed effects)
  %&gt;X   right justify the rest of the string and pad with character “X”
  %|X      pad to the end of the line with character “X”
  %\*X     soft-fill with character “X” as pad
  -------- -------------------------------------------------------------------------------------------------------------------------------------------------

For an explanation of “soft-fill”, see the
[\$index\_format](#index-format) documentation.

### attach\_keyword {#attach-keyword}

    Type: regular expression
    Default: \<(attach|attached|attachments?)\>

If [abort\_noattach](#abort-noattach) is not set to no, then the body of
the message will be scanned for this regular expression, and if found,
you will be prompted if there are no attachments.

### attach\_sep {#attach-sep}

    Type: string
    Default: \n

The separator to add between attachments when operating (saving,
printing, piping, etc) on a list of tagged attachments.

### attach\_split {#attach-split}

    Type: boolean
    Default: yes

If this variable is *unset*, when operating (saving, printing, piping,
etc) on a list of tagged attachments, Mutt will concatenate the
attachments and will operate on them as a single attachment. The
[\$attach\_sep](#attach-sep) separator is added after each attachment.
When *set*, Mutt will operate on the attachments one by one.

### attribution

    Type: string
    Default: On %d, %n wrote:

This is the string that will precede a message which has been included
in a reply. For a full listing of defined `printf(3)`-like sequences see
the section on [\$index\_format](#index-format).

### attribution\_locale {#attribution-locale}

    Type: string
    Default: (empty)

The locale used by `strftime(3)` to format dates in the
[attribution](#attribution) string. Legal values are the strings your
system accepts for the locale environment variable `$LC_TIME`.

This variable is to allow the attribution date format to be customized
by recipient or folder using hooks. By default, Mutt will use your
locale environment, so there is no need to set this except to override
that default.

### auto\_tag {#auto-tag}

    Type: boolean
    Default: no

When *set*, functions in the *index* menu which affect a message will be
applied to all tagged messages (if there are any). When unset, you must
first use the `<tag-prefix>` function (bound to “;” by default) to make
the next function apply to all tagged messages.

### autoedit

    Type: boolean
    Default: no

When *set* along with [\$edit\_headers](#edit-headers), Mutt will skip
the initial send-menu (prompting for subject and recipients) and allow
you to immediately begin editing the body of your message. The send-menu
may still be accessed once you have finished editing the body of your
message.

**Note:** when this option is *set*, you cannot use send-hooks that
depend on the recipients when composing a new (non-reply) message, as
the initial list of recipients is empty.

Also see [\$fast\_reply](#fast-reply).

### beep

    Type: boolean
    Default: yes

When this variable is *set*, mutt will beep when an error occurs.

### beep\_new {#beep-new}

    Type: boolean
    Default: no

When this variable is *set*, mutt will beep whenever it prints a message
notifying you of new mail. This is independent of the setting of the
[\$beep](#beep) variable.

### bounce

    Type: quadoption
    Default: ask-yes

Controls whether you will be asked to confirm bouncing messages. If set
to *yes* you don't get asked if you want to bounce a message. Setting
this variable to *no* is not generally useful, and thus not recommended,
because you are unable to bounce messages.

### bounce\_delivered {#bounce-delivered}

    Type: boolean
    Default: yes

When this variable is *set*, mutt will include Delivered-To headers when
bouncing messages. Postfix users may wish to *unset* this variable.

### braille\_friendly {#braille-friendly}

    Type: boolean
    Default: no

When this variable is *set*, mutt will place the cursor at the beginning
of the current line in menus, even when the
[\$arrow\_cursor](#arrow-cursor) variable is *unset*, making it easier
for blind persons using Braille displays to follow these menus. The
option is *unset* by default because many visual terminals don't permit
making the cursor invisible.

### catchup\_newsgroup {#catchup-newsgroup}

    Type: quadoption
    Default: ask-yes

If this variable is *set*, Mutt will mark all articles in newsgroup as
read when you quit the newsgroup (catchup newsgroup).

### certificate\_file {#certificate-file}

    Type: path
    Default: ~/.mutt_certificates

This variable specifies the file where the certificates you trust are
saved. When an unknown certificate is encountered, you are asked if you
accept it or not. If you accept it, the certificate can also be saved in
this file and further connections are automatically accepted.

You can also manually add CA certificates in this file. Any server
certificate that is signed with one of these CA certificates is also
automatically accepted.

Example:

    set certificate_file=~/.mutt/certificates

### charset

    Type: string
    Default: (empty)

Character set your terminal uses to display and enter textual data. It
is also the fallback for [\$send\_charset](#send-charset).

Upon startup Mutt tries to derive this value from environment variables
such as `$LC_CTYPE` or `$LANG`.

**Note:** It should only be set in case Mutt isn't able to determine the
character set used correctly.

### check\_mbox\_size {#check-mbox-size}

    Type: boolean
    Default: no

When this variable is *set*, mutt will use file size attribute instead
of access time when checking for new mail in mbox and mmdf folders.

This variable is *unset* by default and should only be enabled when new
mail detection for these folder types is unreliable or doesn't work.

Note that enabling this variable should happen before any
“[mailboxes](#mailboxes)” directives occur in configuration files
regarding mbox or mmdf folders because mutt needs to determine the
initial new mail status of such a mailbox by performing a fast mailbox
scan when it is defined. Afterwards the new mail status is tracked by
file size changes.

### check\_new {#check-new}

    Type: boolean
    Default: yes

**Note:** this option only affects *maildir* and *MH* style mailboxes.

When *set*, Mutt will check for new mail delivered while the mailbox is
open. Especially with MH mailboxes, this operation can take quite some
time since it involves scanning the directory and checking each file to
see if it has already been looked at. If this variable is *unset*, no
check for new mail is performed while the mailbox is open.

### collapse\_unread {#collapse-unread}

    Type: boolean
    Default: yes

When *unset*, Mutt will not collapse a thread if it contains any unread
messages.

### compose\_format {#compose-format}

    Type: string
    Default: -- NeoMutt: Compose  [Approx. msg size: %l   Atts: %a]%>-

Controls the format of the status line displayed in the “compose” menu.
This string is similar to [\$status\_format](#status-format), but has
its own set of `printf(3)`-like sequences:

  ---- ----------------------------------------------------
  %a   total number of attachments
  %h   local hostname
  %l   approximate size (in bytes) of the current message
  %v   Mutt version string
  ---- ----------------------------------------------------

See the text describing the [\$status\_format](#status-format) option
for more information on how to set [\$compose\_format](#compose-format).

### config\_charset {#config-charset}

    Type: string
    Default: (empty)

When defined, Mutt will recode commands in rc files from this encoding
to the current character set as specified by [\$charset](#charset) and
aliases written to [\$alias\_file](#alias-file) from the current
character set.

Please note that if setting [\$charset](#charset) it must be done before
setting [\$config\_charset](#config-charset).

Recoding should be avoided as it may render unconvertable characters as
question marks which can lead to undesired side effects (for example in
regular expressions).

### confirmappend

    Type: boolean
    Default: yes

When *set*, Mutt will prompt for confirmation when appending messages to
an existing mailbox.

### confirmcreate

    Type: boolean
    Default: yes

When *set*, Mutt will prompt for confirmation when saving messages to a
mailbox which does not yet exist before creating it.

### connect\_timeout {#connect-timeout}

    Type: number
    Default: 30

Causes Mutt to timeout a network connection (for IMAP, POP or SMTP)
after this many seconds if the connection is not able to be established.
A negative value causes Mutt to wait indefinitely for the connection
attempt to succeed.

### content\_type {#content-type}

    Type: string
    Default: text/plain

Sets the default Content-Type for the body of newly composed messages.

### copy

    Type: quadoption
    Default: yes

This variable controls whether or not copies of your outgoing messages
will be saved for later references. Also see [\$record](#record),
[\$save\_name](#save-name), [\$force\_name](#force-name) and
“[fcc-hook](#fcc-hook)”.

### crypt\_autoencrypt {#crypt-autoencrypt}

    Type: boolean
    Default: no

Setting this variable will cause Mutt to always attempt to PGP encrypt
outgoing messages. This is probably only useful in connection to the
“[send-hook](#send-hook)” command. It can be overridden by use of the
pgp menu, when encryption is not required or signing is requested as
well. If [\$smime\_is\_default](#smime-is-default) is *set*, then
OpenSSL is used instead to create S/MIME messages and settings can be
overridden by use of the smime menu instead. (Crypto only)

### crypt\_autopgp {#crypt-autopgp}

    Type: boolean
    Default: yes

This variable controls whether or not mutt may automatically enable PGP
encryption/signing for messages. See also
[\$crypt\_autoencrypt](#crypt-autoencrypt),
[\$crypt\_replyencrypt](#crypt-replyencrypt),
[\$crypt\_autosign](#crypt-autosign),
[\$crypt\_replysign](#crypt-replysign) and
[\$smime\_is\_default](#smime-is-default).

### crypt\_autosign {#crypt-autosign}

    Type: boolean
    Default: no

Setting this variable will cause Mutt to always attempt to
cryptographically sign outgoing messages. This can be overridden by use
of the pgp menu, when signing is not required or encryption is requested
as well. If [\$smime\_is\_default](#smime-is-default) is *set*, then
OpenSSL is used instead to create S/MIME messages and settings can be
overridden by use of the smime menu instead of the pgp menu. (Crypto
only)

### crypt\_autosmime {#crypt-autosmime}

    Type: boolean
    Default: yes

This variable controls whether or not mutt may automatically enable
S/MIME encryption/signing for messages. See also
[\$crypt\_autoencrypt](#crypt-autoencrypt),
[\$crypt\_replyencrypt](#crypt-replyencrypt),
[\$crypt\_autosign](#crypt-autosign),
[\$crypt\_replysign](#crypt-replysign) and
[\$smime\_is\_default](#smime-is-default).

### crypt\_confirmhook {#crypt-confirmhook}

    Type: boolean
    Default: yes

If set, then you will be prompted for confirmation of keys when using
the *crypt-hook* command. If unset, no such confirmation prompt will be
presented. This is generally considered unsafe, especially where typos
are concerned.

### crypt\_opportunistic\_encrypt {#crypt-opportunistic-encrypt}

    Type: boolean
    Default: no

Setting this variable will cause Mutt to automatically enable and
disable encryption, based on whether all message recipient keys can be
located by Mutt.

When this option is enabled, Mutt will enable/disable encryption each
time the TO, CC, and BCC lists are edited. If
[\$edit\_headers](#edit-headers) is set, Mutt will also do so each time
the message is edited.

While this is set, encryption can't be manually enabled/disabled. The
pgp or smime menus provide a selection to temporarily disable this
option for the current message.

If [\$crypt\_autoencrypt](#crypt-autoencrypt) or
[\$crypt\_replyencrypt](#crypt-replyencrypt) enable encryption for a
message, this option will be disabled for that message. It can be
manually re-enabled in the pgp or smime menus. (Crypto only)

### crypt\_replyencrypt {#crypt-replyencrypt}

    Type: boolean
    Default: yes

If *set*, automatically PGP or OpenSSL encrypt replies to messages which
are encrypted. (Crypto only)

### crypt\_replysign {#crypt-replysign}

    Type: boolean
    Default: no

If *set*, automatically PGP or OpenSSL sign replies to messages which
are signed.

**Note:** this does not work on messages that are encrypted *and*
signed! (Crypto only)

### crypt\_replysignencrypted {#crypt-replysignencrypted}

    Type: boolean
    Default: no

If *set*, automatically PGP or OpenSSL sign replies to messages which
are encrypted. This makes sense in combination with
[\$crypt\_replyencrypt](#crypt-replyencrypt), because it allows you to
sign all messages which are automatically encrypted. This works around
the problem noted in [\$crypt\_replysign](#crypt-replysign), that mutt
is not able to find out whether an encrypted message is also signed.
(Crypto only)

### pgp\_encrypt\_self {#pgp-encrypt-self}

    Type: quadoption
    Default: no

Encrypt the message to [\$pgp\_sign\_as](#pgp-sign-as) too. (PGP only)

### crypt\_timestamp {#crypt-timestamp}

    Type: boolean
    Default: yes

If *set*, mutt will include a time stamp in the lines surrounding PGP or
S/MIME output, so spoofing such lines is more difficult. If you are
using colors to mark these lines, and rely on these, you may *unset*
this setting. (Crypto only)

### crypt\_use\_gpgme {#crypt-use-gpgme}

    Type: boolean
    Default: no

This variable controls the use of the GPGME-enabled crypto backends. If
it is *set* and Mutt was built with gpgme support, the gpgme code for
S/MIME and PGP will be used instead of the classic code. Note that you
need to set this option in .muttrc; it won't have any effect when used
interactively.

Note that the GPGME backend does not support creating old-style inline
(traditional) PGP encrypted or signed messages (see
[\$pgp\_autoinline](#pgp-autoinline)).

### crypt\_use\_pka {#crypt-use-pka}

    Type: boolean
    Default: no

Controls whether mutt uses PKA (see
http://www.g10code.de/docs/pka-intro.de.pdf) during signature
verification (only supported by the GPGME backend).

### crypt\_verify\_sig {#crypt-verify-sig}

    Type: quadoption
    Default: yes

If *“yes”*, always attempt to verify PGP or S/MIME signatures. If
*“ask-\*”*, ask whether or not to verify the signature. If *“no”*, never
attempt to verify cryptographic signatures. (Crypto only)

### date\_format {#date-format}

    Type: string
    Default: !%a, %b %d, %Y at %I:%M:%S%p %Z

This variable controls the format of the date printed by the “%d”
sequence in [\$index\_format](#index-format). This is passed to the
`strftime(3)` function to process the date, see the man page for the
proper syntax.

Unless the first character in the string is a bang (“!”), the month and
week day names are expanded according to the locale. If the first
character in the string is a bang, the bang is discarded, and the month
and week day names in the rest of the string are expanded in the *C*
locale (that is in US English).

### default\_hook {#default-hook}

    Type: string
    Default: ~f %s !~P | (~P ~C %s)

This variable controls how “[message-hook](#message-hook)”,
“[reply-hook](#reply-hook)”, “[send-hook](#send-hook)”,
“[send2-hook](#send2-hook)”, “[save-hook](#save-hook)”, and
“[fcc-hook](#fcc-hook)” will be interpreted if they are specified with
only a simple regexp, instead of a matching pattern. The hooks are
expanded when they are declared, so a hook will be interpreted according
to the value of this variable at the time the hook is declared.

The default value matches if the message is either from a user matching
the regular expression given, or if it is from you (if the from address
matches “[alternates](#alternates)”) and is to or cc'ed to a user
matching the given regular expression.

### delete

    Type: quadoption
    Default: ask-yes

Controls whether or not messages are really deleted when closing or
synchronizing a mailbox. If set to *yes*, messages marked for deleting
will automatically be purged without prompting. If set to *no*, messages
marked for deletion will be kept in the mailbox.

### delete\_untag {#delete-untag}

    Type: boolean
    Default: yes

If this option is *set*, mutt will untag messages when marking them for
deletion. This applies when you either explicitly delete a message, or
when you save it to another folder.

### digest\_collapse {#digest-collapse}

    Type: boolean
    Default: yes

If this option is *set*, mutt's received-attachments menu will not show
the subparts of individual messages in a multipart/digest. To see these
subparts, press “v” on that menu.

### display\_filter {#display-filter}

    Type: path
    Default: (empty)

When set, specifies a command used to filter messages. When a message is
viewed it is passed as standard input to
[\$display\_filter](#display-filter), and the filtered message is read
from the standard output.

### dsn\_notify {#dsn-notify}

    Type: string
    Default: (empty)

This variable sets the request for when notification is returned. The
string consists of a comma separated list (no spaces!) of one or more of
the following: *never*, to never request notification, *failure*, to
request notification on transmission failure, *delay*, to be notified of
message delays, *success*, to be notified of successful transmission.

Example:

    set dsn_notify="failure,delay"

**Note:** when using [\$sendmail](#sendmail) for delivery, you should
not enable this unless you are either using Sendmail 8.8.x or greater or
a MTA providing a `sendmail(1)`-compatible interface supporting the `-N`
option for DSN. For SMTP delivery, DSN support is auto-detected so that
it depends on the server whether DSN will be used or not.

### dsn\_return {#dsn-return}

    Type: string
    Default: (empty)

This variable controls how much of your message is returned in DSN
messages. It may be set to either *hdrs* to return just the message
header, or *full* to return the full message.

Example:

    set dsn_return=hdrs

**Note:** when using [\$sendmail](#sendmail) for delivery, you should
not enable this unless you are either using Sendmail 8.8.x or greater or
a MTA providing a `sendmail(1)`-compatible interface supporting the `-R`
option for DSN. For SMTP delivery, DSN support is auto-detected so that
it depends on the server whether DSN will be used or not.

### duplicate\_threads {#duplicate-threads}

    Type: boolean
    Default: yes

This variable controls whether mutt, when [\$sort](#sort) is set to
*threads*, threads messages with the same Message-Id together. If it is
*set*, it will indicate that it thinks they are duplicates of each other
with an equals sign in the thread tree.

### edit\_headers {#edit-headers}

    Type: boolean
    Default: no

This option allows you to edit the header of your outgoing messages
along with the body of your message.

**Note** that changes made to the References: and Date: headers are
ignored for interoperability reasons.

### editor

    Type: path
    Default: (empty)

This variable specifies which editor is used by mutt. It defaults to the
value of the `$VISUAL`, or `$EDITOR`, environment variable, or to the
string “vi” if neither of those are set.

The `$editor` string may contain a *%s* escape, which will be replaced
by the name of the file to be edited. If the *%s* escape does not appear
in `$editor`, a space and the name to be edited are appended.

The resulting string is then executed by running

    sh -c 'string'

where *string* is the expansion of `$editor` described above.

### empty\_subject {#empty-subject}

    Type: string
    Default: Re: your mail

This variable specifies the subject to be used when replying to an email
with an empty subject. It defaults to "Re: your mail".

### encode\_from {#encode-from}

    Type: boolean
    Default: no

When *set*, mutt will quoted-printable encode messages when they contain
the string “From” (note the trailing space) in the beginning of a line.
This is useful to avoid the tampering certain mail delivery and
transport agents tend to do with messages (in order to prevent tools
from misinterpreting the line as a mbox message separator).

### entropy\_file {#entropy-file}

    Type: path
    Default: (empty)

The file which includes random data that is used to initialize SSL
library functions.

### envelope\_from\_address {#envelope-from-address}

    Type: e-mail address
    Default: (empty)

Manually sets the *envelope* sender for outgoing messages. This value is
ignored if [\$use\_envelope\_from](#use-envelope-from) is *unset*.

### escape

    Type: string
    Default: ~

Escape character to use for functions in the built-in editor.

### fast\_reply {#fast-reply}

    Type: boolean
    Default: no

When *set*, the initial prompt for recipients and subject are skipped
when replying to messages, and the initial prompt for subject is skipped
when forwarding messages.

**Note:** this variable has no effect when the [\$autoedit](#autoedit)
variable is *set*.

### fcc\_attach {#fcc-attach}

    Type: quadoption
    Default: yes

This variable controls whether or not attachments on outgoing messages
are saved along with the main body of your message.

### fcc\_clear {#fcc-clear}

    Type: boolean
    Default: no

When this variable is *set*, FCCs will be stored unencrypted and
unsigned, even when the actual message is encrypted and/or signed. (PGP
only)

### flag\_safe {#flag-safe}

    Type: boolean
    Default: no

If set, flagged messages cannot be deleted.

### folder

    Type: path
    Default: ~/Mail

Specifies the default location of your mailboxes. A “+” or “=” at the
beginning of a pathname will be expanded to the value of this variable.
Note that if you change this variable (from the default) value you need
to make sure that the assignment occurs *before* you use “+” or “=” for
any other variables since expansion takes place when handling the
“[mailboxes](#mailboxes)” command.

### folder\_format {#folder-format}

    Type: string
    Default: %2C %t %N %F %2l %-8.8u %-8.8g %8s %d %f

This variable allows you to customize the file browser display to your
personal taste. This string is similar to
[\$index\_format](#index-format), but has its own set of
`printf(3)`-like sequences:

  -------- ---------------------------------------------------------------------------------------------------
  %C       current file number
  %d       date/time folder was last modified
  %D       date/time folder was last modified using [\$date\_format](#date-format).
  %f       filename (“/” is appended to directory names, “@” to symbolic links and “\*” to executable files)
  %F       file permissions
  %g       group name (or numeric gid, if missing)
  %l       number of hard links
  %m       number of messages in the mailbox \*
  %n       number of unread messages in the mailbox \*
  %N       N if mailbox has new mail, blank otherwise
  %s       size in bytes
  %t       “\*” if the file is tagged, blank otherwise
  %u       owner name (or numeric uid, if missing)
  %&gt;X   right justify the rest of the string and pad with character “X”
  %|X      pad to the end of the line with character “X”
  %\*X     soft-fill with character “X” as pad
  -------- ---------------------------------------------------------------------------------------------------

For an explanation of “soft-fill”, see the
[\$index\_format](#index-format) documentation.

\* = can be optionally printed if nonzero

%m, %n, and %N only work for monitored mailboxes. %m requires
[\$mail\_check\_stats](#mail-check-stats) to be set. %n requires
[\$mail\_check\_stats](#mail-check-stats) to be set (except for IMAP
mailboxes).

### followup\_to {#followup-to}

    Type: boolean
    Default: yes

Controls whether or not the “Mail-Followup-To:” header field is
generated when sending mail. When *set*, Mutt will generate this field
when you are replying to a known mailing list, specified with the
“[subscribe](#subscribe)” or “[lists](#lists)” commands.

This field has two purposes. First, preventing you from receiving
duplicate copies of replies to messages which you send to mailing lists,
and second, ensuring that you do get a reply separately for any messages
sent to known lists to which you are not subscribed.

The header will contain only the list's address for subscribed lists,
and both the list address and your own email address for unsubscribed
lists. Without this header, a group reply to your message sent to a
subscribed list will be sent to both the list and your address,
resulting in two copies of the same email for you.

### followup\_to\_poster {#followup-to-poster}

    Type: quadoption
    Default: ask-yes

If this variable is *set* and the keyword "poster" is present in
*Followup-To* header, follow-up to newsgroup function is not permitted.
The message will be mailed to the submitter of the message via mail.

### force\_name {#force-name}

    Type: boolean
    Default: no

This variable is similar to [\$save\_name](#save-name), except that Mutt
will store a copy of your outgoing message by the username of the
address you are sending to even if that mailbox does not exist.

Also see the [\$record](#record) variable.

### forward\_decode {#forward-decode}

    Type: boolean
    Default: yes

Controls the decoding of complex MIME messages into `text/plain` when
forwarding a message. The message header is also RFC2047 decoded. This
variable is only used, if [\$mime\_forward](#mime-forward) is *unset*,
otherwise [\$mime\_forward\_decode](#mime-forward-decode) is used
instead.

### forward\_decrypt {#forward-decrypt}

    Type: boolean
    Default: yes

Controls the handling of encrypted messages when forwarding a message.
When *set*, the outer layer of encryption is stripped off. This variable
is only used if [\$mime\_forward](#mime-forward) is *set* and
[\$mime\_forward\_decode](#mime-forward-decode) is *unset*. (PGP only)

### forward\_edit {#forward-edit}

    Type: quadoption
    Default: yes

This quadoption controls whether or not the user is automatically placed
in the editor when forwarding messages. For those who always want to
forward with no modification, use a setting of “no”.

### forward\_format {#forward-format}

    Type: string
    Default: [%a: %s]

This variable controls the default subject when forwarding a message. It
uses the same format sequences as the [\$index\_format](#index-format)
variable.

### forward\_quote {#forward-quote}

    Type: boolean
    Default: no

When *set*, forwarded messages included in the main body of the message
(when [\$mime\_forward](#mime-forward) is *unset*) will be quoted using
[\$indent\_string](#indent-string).

### forward\_references {#forward-references}

    Type: boolean
    Default: no

When *set*, forwarded messages set the “In-Reply-To:” and “References:”
headers in the same way as normal replies would. Hence the forwarded
message becomes part of the original thread instead of starting a new
one.

### from

    Type: e-mail address
    Default: (empty)

When *set*, this variable contains a default from address. It can be
overridden using “[my\_hdr](#my-hdr)” (including from a
“[send-hook](#send-hook)”) and [\$reverse\_name](#reverse-name). This
variable is ignored if [\$use\_from](#use-from) is *unset*.

This setting defaults to the contents of the environment variable
`$EMAIL`.

### from\_chars {#from-chars}

    Type: string
    Default: (empty)

Controls the character used to prefix the %F and %L fields in the index.

  --------------- ---------------------------------------------------------------------------------------------
  **Character**   **Description**
  1               Mail is written by you and has a To address, or has a known mailing list in the To address.
  2               Mail is written by you and has a Cc address, or has a known mailing list in the Cc address.
  3               Mail is written by you and has a Bcc address.
  4               All remaining cases.
  --------------- ---------------------------------------------------------------------------------------------

If this is empty or unset (default), the traditional long "To ", "Cc "
and "Bcc " prefixes are used. If set but too short to include a
character for a particular case, a single space will be prepended to the
field. To prevent any prefix at all from being added in a particular
case, use the special value CR (aka \^M) for the corresponding
character.

This slightly odd interface is necessitated by mutt's handling of string
variables; one cannot tell a variable that is unset from one that is set
to the empty string.

### gecos\_mask {#gecos-mask}

    Type: regular expression
    Default: ^[^,]*

A regular expression used by mutt to parse the GECOS field of a password
entry when expanding the alias. The default value will return the string
up to the first “,” encountered. If the GECOS field contains a string
like “lastname, firstname” then you should set it to “`.*`”.

This can be useful if you see the following behavior: you address an
e-mail to user ID “stevef” whose full name is “Steve Franklin”. If mutt
expands “stevef” to “"Franklin" stevef@foo.bar” then you should set the
[\$gecos\_mask](#gecos-mask) to a regular expression that will match the
whole name so mutt will expand “Franklin” to “Franklin, Steve”.

### group\_index\_format {#group-index-format}

    Type: string
    Default: %4C %M%N %5s  %-45.45f %d

This variable allows you to customize the newsgroup browser display to
your personal taste. This string is similar to
“[index\_format](#index-format)”, but has its own set of printf()-like
sequences:

  -------- --------------------------------------------------------------------
  %C       current newsgroup number
  %d       description of newsgroup (becomes from server)
  %f       newsgroup name
  %M       - if newsgroup not allowed for direct post (moderated for example)
  %N       N if newsgroup is new, u if unsubscribed, blank otherwise
  %n       number of new articles in newsgroup
  %s       number of unread articles in newsgroup
  %&gt;X   right justify the rest of the string and pad with character "X"
  %|X      pad to the end of the line with character "X"
  -------- --------------------------------------------------------------------

### hdrs

    Type: boolean
    Default: yes

When *unset*, the header fields normally added by the
“[my\_hdr](#my-hdr)” command are not created. This variable *must* be
unset before composing a new message or replying in order to take
effect. If *set*, the user defined header fields are added to every new
message.

### header

    Type: boolean
    Default: no

When *set*, this variable causes Mutt to include the header of the
message you are replying to into the edit buffer. The [\$weed](#weed)
setting applies.

### header\_cache {#header-cache}

    Type: path
    Default: (empty)

This variable points to the header cache database. If pointing to a
directory Mutt will contain a header cache database file per folder, if
pointing to a file that file will be a single global header cache. By
default it is *unset* so no header caching will be used.

Header caching can greatly improve speed when opening POP, IMAP MH or
Maildir folders, see “[caching](#caching)” for details.

### header\_cache\_backend {#header-cache-backend}

    Type: -none-
    Default: 0

This variable specifies the header cache backend.

### header\_cache\_compress {#header-cache-compress}

    Type: boolean
    Default: yes

When mutt is compiled with qdbm, tokyocabinet or kyotocabinet as header
cache backend, this option determines whether the database will be
compressed. Compression results in database files roughly being one
fifth of the usual diskspace, but the decompression can result in a
slower opening of cached folder(s) which in general is still much faster
than opening non header cached folders.

### header\_cache\_pagesize {#header-cache-pagesize}

    Type: string
    Default: 16384

When mutt is compiled with either gdbm or bdb4 as the header cache
backend, this option changes the database page size. Too large or too
small values can waste space, memory, or CPU time. The default should be
more or less optimal for most use cases.

### header\_color\_partial {#header-color-partial}

    Type: boolean
    Default: no

When *set*, color header regexps behave like color body regexps: color
is applied to the exact text matched by the regexp. When *unset*, color
is applied to the entire header.

One use of this option might be to apply color to just the header
labels.

See “[color](#color)” for more details.

### help {#help}

    Type: boolean
    Default: yes

When *set*, help lines describing the bindings for the major functions
provided by each menu are displayed on the first line of the screen.

**Note:** The binding will not be displayed correctly if the function is
bound to a sequence rather than a single keystroke. Also, the help line
may not be updated if a binding is changed while Mutt is running. Since
this variable is primarily aimed at new users, neither of these should
present a major problem.

### hidden\_host {#hidden-host}

    Type: boolean
    Default: no

When *set*, mutt will skip the host name part of [\$hostname](#hostname)
variable when adding the domain part to addresses. This variable does
not affect the generation of Message-IDs, and it will not lead to the
cut-off of first-level domains.

### hide\_limited {#hide-limited}

    Type: boolean
    Default: no

When *set*, mutt will not show the presence of messages that are hidden
by limiting, in the thread tree.

### hide\_missing {#hide-missing}

    Type: boolean
    Default: yes

When *set*, mutt will not show the presence of missing messages in the
thread tree.

### hide\_thread\_subject {#hide-thread-subject}

    Type: boolean
    Default: yes

When *set*, mutt will not show the subject of messages in the thread
tree that have the same subject as their parent or closest previously
displayed sibling.

### hide\_top\_limited {#hide-top-limited}

    Type: boolean
    Default: no

When *set*, mutt will not show the presence of messages that are hidden
by limiting, at the top of threads in the thread tree. Note that when
[\$hide\_limited](#hide-limited) is *set*, this option will have no
effect.

### hide\_top\_missing {#hide-top-missing}

    Type: boolean
    Default: yes

When *set*, mutt will not show the presence of missing messages at the
top of threads in the thread tree. Note that when
[\$hide\_missing](#hide-missing) is *set*, this option will have no
effect.

### history {#history}

    Type: number
    Default: 10

This variable controls the size (in number of strings remembered) of the
string history buffer per category. The buffer is cleared each time the
variable is set.

### history\_file {#history-file}

    Type: path
    Default: ~/.mutthistory

The file in which Mutt will save its history.

Also see [\$save\_history](#save-history).

### history\_remove\_dups {#history-remove-dups}

    Type: boolean
    Default: no

When *set*, all of the string history will be scanned for duplicates
when a new entry is added. Duplicate entries in the
[\$history\_file](#history-file) will also be removed when it is
periodically compacted.

### honor\_disposition {#honor-disposition}

    Type: boolean
    Default: no

When *set*, Mutt will not display attachments with a disposition of
“attachment” inline even if it could render the part to plain text.
These MIME parts can only be viewed from the attachment menu.

If *unset*, Mutt will render all MIME parts it can properly transform to
plain text.

### honor\_followup\_to {#honor-followup-to}

    Type: quadoption
    Default: yes

This variable controls whether or not a Mail-Followup-To header is
honored when group-replying to a message.

### hostname

    Type: string
    Default: (empty)

Specifies the fully-qualified hostname of the system mutt is running on
containing the host's name and the DNS domain it belongs to. It is used
as the domain part (after “@”) for local email addresses as well as
Message-Id headers.

Its value is determined at startup as follows: the node's hostname is
first determined by the `uname(3)` function. The domain is then looked
up using the `gethostname(2)` and `getaddrinfo(3)` functions. If those
calls are unable to determine the domain, the full value returned by
uname is used. Optionally, Mutt can be compiled with a fixed domain name
in which case a detected one is not used.

Also see [\$use\_domain](#use-domain) and
[\$hidden\_host](#hidden-host).

### idn\_decode {#idn-decode}

    Type: boolean
    Default: yes

When *set*, Mutt will show you international domain names decoded. Note:
You can use IDNs for addresses even if this is *unset*. This variable
only affects decoding. (IDN only)

### idn\_encode {#idn-encode}

    Type: boolean
    Default: yes

When *set*, Mutt will encode international domain names using IDN. Unset
this if your SMTP server can handle newer (RFC 6531) UTF-8 encoded
domains. (IDN only)

### ignore\_linear\_white\_space {#ignore-linear-white-space}

    Type: boolean
    Default: no

This option replaces linear-white-space between encoded-word and text to
a single space to prevent the display of MIME-encoded “Subject:” field
from being divided into multiple lines.

### ignore\_list\_reply\_to {#ignore-list-reply-to}

    Type: boolean
    Default: no

Affects the behavior of the `<reply>` function when replying to messages
from mailing lists (as defined by the “[subscribe](#subscribe)” or
“[lists](#lists)” commands). When *set*, if the “Reply-To:” field is set
to the same value as the “To:” field, Mutt assumes that the “Reply-To:”
field was set by the mailing list to automate responses to the list, and
will ignore this field. To direct a response to the mailing list when
this option is *set*, use the `<list-reply>` function; `<group-reply>`
will reply to both the sender and the list.

### show\_multipart\_alternative {#show-multipart-alternative}

    Type: string
    Default: (empty)

When *set* to `info`, the multipart/alternative information is shown.
When *set* to `inline`, all of the alternatives are displayed. When not
set, the default behavior is to show only the chosen alternative.

### imap\_authenticators {#imap-authenticators}

    Type: string
    Default: (empty)

This is a colon-delimited list of authentication methods mutt may
attempt to use to log in to an IMAP server, in the order mutt should try
them. Authentication methods are either “login” or the right side of an
IMAP “AUTH=xxx” capability string, e.g. “digest-md5”, “gssapi” or
“cram-md5”. This option is case-insensitive. If it's *unset* (the
default) mutt will try all available methods, in order from most-secure
to least-secure.

Example:

    set imap_authenticators="gssapi:cram-md5:login"

**Note:** Mutt will only fall back to other authentication methods if
the previous methods are unavailable. If a method is available but
authentication fails, mutt will not connect to the IMAP server.

### imap\_check\_subscribed {#imap-check-subscribed}

    Type: boolean
    Default: no

When *set*, mutt will fetch the set of subscribed folders from your
server on connection, and add them to the set of mailboxes it polls for
new mail just as if you had issued individual “[mailboxes](#mailboxes)”
commands.

### imap\_delim\_chars {#imap-delim-chars}

    Type: string
    Default: /.

This contains the list of characters which you would like to treat as
folder separators for displaying IMAP paths. In particular it helps in
using the “=” shortcut for your *folder* variable.

### imap\_headers {#imap-headers}

    Type: string
    Default: (empty)

Mutt requests these header fields in addition to the default headers
(“Date:”, “From:”, “Subject:”, “To:”, “Cc:”, “Message-Id:”,
“References:”, “Content-Type:”, “Content-Description:”, “In-Reply-To:”,
“Reply-To:”, “Lines:”, “List-Post:”, “X-Label:”) from IMAP servers
before displaying the index menu. You may want to add more headers for
spam detection.

**Note:** This is a space separated list, items should be uppercase and
not contain the colon, e.g. “X-BOGOSITY X-SPAM-STATUS” for the
“X-Bogosity:” and “X-Spam-Status:” header fields.

### imap\_idle {#imap-idle}

    Type: boolean
    Default: no

When *set*, mutt will attempt to use the IMAP IDLE extension to check
for new mail in the current mailbox. Some servers (dovecot was the
inspiration for this option) react badly to mutt's implementation. If
your connection seems to freeze up periodically, try unsetting this.

### imap\_keepalive {#imap-keepalive}

    Type: number
    Default: 300

This variable specifies the maximum amount of time in seconds that mutt
will wait before polling open IMAP connections, to prevent the server
from closing them before mutt has finished with them. The default is
well within the RFC-specified minimum amount of time (30 minutes) before
a server is allowed to do this, but in practice the RFC does get
violated every now and then. Reduce this number if you find yourself
getting disconnected from your IMAP server due to inactivity.

### imap\_list\_subscribed {#imap-list-subscribed}

    Type: boolean
    Default: no

This variable configures whether IMAP folder browsing will look for only
subscribed folders or all folders. This can be toggled in the IMAP
browser with the `<toggle-subscribed>` function.

### imap\_login {#imap-login}

    Type: string
    Default: (empty)

Your login name on the IMAP server.

This variable defaults to the value of [\$imap\_user](#imap-user).

### imap\_pass {#imap-pass}

    Type: string
    Default: (empty)

Specifies the password for your IMAP account. If *unset*, Mutt will
prompt you for your password when you invoke the `<imap-fetch-mail>`
function or try to open an IMAP folder.

**Warning**: you should only use this option when you are on a fairly
secure machine, because the superuser can read your muttrc even if you
are the only one who can read the file.

### imap\_passive {#imap-passive}

    Type: boolean
    Default: yes

When *set*, mutt will not open new IMAP connections to check for new
mail. Mutt will only check for new mail over existing IMAP connections.
This is useful if you don't want to be prompted to user/password pairs
on mutt invocation, or if opening the connection is slow.

### imap\_peek {#imap-peek}

    Type: boolean
    Default: yes

When *set*, mutt will avoid implicitly marking your mail as read
whenever you fetch a message from the server. This is generally a good
thing, but can make closing an IMAP folder somewhat slower. This option
exists to appease speed freaks.

### imap\_pipeline\_depth {#imap-pipeline-depth}

    Type: number
    Default: 15

Controls the number of IMAP commands that may be queued up before they
are sent to the server. A deeper pipeline reduces the amount of time
mutt must wait for the server, and can make IMAP servers feel much more
responsive. But not all servers correctly handle pipelined commands, so
if you have problems you might want to try setting this variable to 0.

**Note:** Changes to this variable have no effect on open connections.

### imap\_servernoise {#imap-servernoise}

    Type: boolean
    Default: yes

When *set*, mutt will display warning messages from the IMAP server as
error messages. Since these messages are often harmless, or generated
due to configuration problems on the server which are out of the users'
hands, you may wish to suppress them at some point.

### imap\_user {#imap-user}

    Type: string
    Default: (empty)

The name of the user whose mail you intend to access on the IMAP server.

This variable defaults to your user name on the local machine.

### implicit\_autoview {#implicit-autoview}

    Type: boolean
    Default: no

If set to “yes”, mutt will look for a mailcap entry with the
“`copiousoutput`” flag set for *every* MIME attachment it doesn't have
an internal viewer defined for. If such an entry is found, mutt will use
the viewer defined in that entry to convert the body part to text form.

### include

    Type: quadoption
    Default: ask-yes

Controls whether or not a copy of the message(s) you are replying to is
included in your reply.

### include\_onlyfirst {#include-onlyfirst}

    Type: boolean
    Default: no

Controls whether or not Mutt includes only the first attachment of the
message you are replying.

### indent\_string {#indent-string}

    Type: string
    Default: > 

Specifies the string to prepend to each line of text quoted in a message
to which you are replying. You are strongly encouraged not to change
this value, as it tends to agitate the more fanatical netizens.

The value of this option is ignored if [\$text\_flowed](#text-flowed) is
set, too because the quoting mechanism is strictly defined for
format=flowed.

This option is a format string, please see the description of
[\$index\_format](#index-format) for supported `printf(3)`-style
sequences.

### index\_format {#index-format}

    Type: string
    Default: %4C %Z %{%b %d} %-15.15L (%?l?%4l&%4c?) %s

This variable allows you to customize the message index display to your
personal taste.

“Format strings” are similar to the strings used in the C function
`printf(3)` to format output (see the man page for more details). The
following sequences are defined in Mutt:

  -------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  %a             address of the author
  %A             reply-to address (if present; otherwise: address of author)
  %b             filename of the original message folder (think mailbox)
  %B             the list to which the letter was sent, or else the folder name (%b).
  %c             number of characters (bytes) in the message
  %C             current message number
  %d             date and time of the message in the format specified by [\$date\_format](#date-format) converted to sender's time zone
  %D             date and time of the message in the format specified by [\$date\_format](#date-format) converted to the local time zone
  %e             current message number in thread
  %E             number of messages in current thread
  %f             sender (address + real name), either From: or Return-Path:
  %F             author name, or recipient name if the message is from you
  %g             newsgroup name (if compiled with NNTP support)
  %g             message labels (e.g. notmuch tags)
  %H             spam attribute(s) of this message
  %I             initials of author
  %i             message-id of the current message
  %K             the list to which the letter was sent (if any; otherwise: empty).
  %l             number of lines in the message (does not work with maildir, mh, and possibly IMAP folders)
  %L             If an address in the “To:” or “Cc:” header field matches an address defined by the users “[subscribe](#subscribe)” command, this displays "To &lt;list-name&gt;", otherwise the same as %F.
  %m             total number of message in the mailbox
  %M             number of hidden messages if the thread is collapsed.
  %N             message score
  %n             author's real name (or address if missing)
  %O             original save folder where mutt would formerly have stashed the message: list name or recipient name if not sent to a list
  %P             progress indicator for the built-in pager (how much of the file has been displayed)
  %q             newsgroup name (if compiled with NNTP support)
  %r             comma separated list of “To:” recipients
  %R             comma separated list of “Cc:” recipients
  %s             subject of the message
  %S             status of the message (“N”/“D”/“d”/“!”/“r”/\*)
  %t             “To:” field (recipients)
  %T             the appropriate character from the [\$to\_chars](#to-chars) string
  %u             user (login) name of the author
  %v             first name of the author, or the recipient if the message is from you
  %W             name of organization of author (“Organization:” field)
  %x             “X-Comment-To:” field (if present and compiled with NNTP support)
  %X             number of attachments (please see the “[attachments](#attachments)” section for possible speed effects)
  %y             “X-Label:” field, if present
  %Y             “X-Label:” field, if present, and *(1)* not at part of a thread tree, *(2)* at the top of a thread, or *(3)* “X-Label:” is different from preceding message's “X-Label:”.
  %Z             Combined message flags
  %zs            message status flags
  %zc            message crypto flags
  %zt            message tag flags
  %{fmt}         the date and time of the message is converted to sender's time zone, and “fmt” is expanded by the library function `strftime(3)`; a leading bang disables locales
  %\[fmt\]       the date and time of the message is converted to the local time zone, and “fmt” is expanded by the library function `strftime(3)`; a leading bang disables locales
  %(fmt)         the local date and time when the message was received. “fmt” is expanded by the library function `strftime(3)`; a leading bang disables locales
  %&lt;fmt&gt;   the current local time. “fmt” is expanded by the library function `strftime(3)`; a leading bang disables locales.
  %&gt;X         right justify the rest of the string and pad with character “X”
  %|X            pad to the end of the line with character “X”
  %\*X           soft-fill with character “X” as pad
  -------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Date format expressions can be constructed based on relative dates.
Using the date formatting operators along with nested conditionals, the
date format can be modified based on how old a message is. See the
section on “Conditional Dates” for an explanation and examples
“Soft-fill” deserves some explanation: Normal right-justification will
print everything to the left of the “%&gt;”, displaying padding and
whatever lies to the right only if there's room. By contrast, soft-fill
gives priority to the right-hand side, guaranteeing space to display it
and showing padding only if there's still room. If necessary, soft-fill
will eat text leftwards to make room for rightward text.

Note that these expandos are supported in “[save-hook](#save-hook)”,
“[fcc-hook](#fcc-hook)” and “[fcc-save-hook](#fcc-save-hook)”, too.

### inews

    Type: path
    Default: (empty)

If set, specifies the program and arguments used to deliver news posted
by Mutt. Otherwise, mutt posts article using current connection to news
server. The following printf-style sequence is understood:

  ---- -------------------
  %a   account url
  %p   port
  %P   port if specified
  %s   news server name
  %S   url schema
  %u   username
  ---- -------------------

Example:

    set inews="/usr/local/bin/inews -hS"

### ispell

    Type: path
    Default: /usr/bin/ispell

How to invoke ispell (GNU's spell-checking software).

### keep\_flagged {#keep-flagged}

    Type: boolean
    Default: no

If *set*, read messages marked as flagged will not be moved from your
spool mailbox to your [\$mbox](#mbox) mailbox, or as a result of a
“[mbox-hook](#mbox-hook)” command.

### keywords\_legacy {#keywords-legacy}

    Type: boolean
    Default: yes

If *set*, keywords/labels/tags will be written to whatever legacy,
nonstandard headers (X-Label, X-Keywords, X-Mozilla-Keys) they were
sourced from.

If both “[\$keywords\_legacy](#keywords-legacy)” and
“[\$keywords\_standard](#keywords-standard)” are `false`, mutt will save
keywords to legacy headers to ensure that it does not lose your labels.

### keywords\_standard {#keywords-standard}

    Type: boolean
    Default: no

If *set*, keywords/labels/tags will be written to the RFC2822-standard
Keywords: header; this may imply a conversion from legacy headers.

If both “[\$keywords\_legacy](#keywords-legacy)” and
“[\$keywords\_standard](#keywords-standard)” are `false`, mutt will save
keywords to legacy headers to ensure that it does not lose your labels.

### mail\_check {#mail-check}

    Type: number
    Default: 5

This variable configures how often (in seconds) mutt should look for new
mail. Also see the [\$timeout](#timeout) variable.

### mail\_check\_recent {#mail-check-recent}

    Type: boolean
    Default: yes

When *set*, Mutt will only notify you about new mail that has been
received since the last time you opened the mailbox. When *unset*, Mutt
will notify you if any new mail exists in the mailbox, regardless of
whether you have visited it recently.

When *[\$mark\_old](#mark-old)* is set, Mutt does not consider the
mailbox to contain new mail if only old messages exist.

### mail\_check\_stats {#mail-check-stats}

    Type: boolean
    Default: no

When *set*, mutt will periodically calculate message statistics of a
mailbox while polling for new mail. It will check for unread, flagged,
and total message counts. Because this operation is more performance
intensive, it defaults to *unset*, and has a separate option,
[\$mail\_check\_stats\_interval](#mail-check-stats-interval), to control
how often to update these counts.

### mail\_check\_stats\_interval {#mail-check-stats-interval}

    Type: number
    Default: 60

When [\$mail\_check\_stats](#mail-check-stats) is *set*, this variable
configures how often (in seconds) mutt will update message counts.

### mailcap\_path {#mailcap-path}

    Type: string
    Default: (empty)

This variable specifies which files to consult when attempting to
display MIME bodies not directly supported by Mutt.

### mailcap\_sanitize {#mailcap-sanitize}

    Type: boolean
    Default: yes

If *set*, mutt will restrict possible characters in mailcap % expandos
to a well-defined set of safe characters. This is the safe setting, but
we are not sure it doesn't break some more advanced MIME stuff.

**DON'T CHANGE THIS SETTING UNLESS YOU ARE REALLY SURE WHAT YOU ARE
DOING!**

### maildir\_header\_cache\_verify {#maildir-header-cache-verify}

    Type: boolean
    Default: yes

Check for Maildir unaware programs other than mutt having modified
maildir files when the header cache is in use. This incurs one `stat(2)`
per message every time the folder is opened (which can be very slow for
NFS folders).

### maildir\_trash {#maildir-trash}

    Type: boolean
    Default: no

If *set*, messages marked as deleted will be saved with the maildir
trashed flag instead of unlinked. **Note:** this only applies to
maildir-style mailboxes. Setting it will have no effect on other mailbox
types.

### maildir\_check\_cur {#maildir-check-cur}

    Type: boolean
    Default: no

If *set*, mutt will poll both the new and cur directories of a maildir
folder for new messages. This might be useful if other programs
interacting with the folder (e.g. dovecot) are moving new messages to
the cur directory. Note that setting this option may slow down polling
for new messages in large folders, since mutt has to scan all cur
messages.

### mark\_macro\_prefix {#mark-macro-prefix}

    Type: string
    Default: '

Prefix for macros created using mark-message. A new macro automatically
generated with *&lt;mark-message&gt;a* will be composed from this prefix
and the letter *a*.

### mark\_old {#mark-old}

    Type: boolean
    Default: yes

Controls whether or not mutt marks *new* **unread** messages as *old* if
you exit a mailbox without reading them. With this option *set*, the
next time you start mutt, the messages will show up with an “O” next to
them in the index menu, indicating that they are old.

### markers

    Type: boolean
    Default: yes

Controls the display of wrapped lines in the internal pager. If set, a
“+” marker is displayed at the beginning of wrapped lines.

Also see the [\$smart\_wrap](#smart-wrap) variable.

### mask

    Type: regular expression
    Default: !^\.[^.]

A regular expression used in the file browser, optionally preceded by
the *not* operator “!”. Only files whose names match this mask will be
shown. The match is always case-sensitive.

### mbox

    Type: path
    Default: ~/mbox

This specifies the folder into which read mail in your
[\$spoolfile](#spoolfile) folder will be appended.

Also see the [\$move](#move) variable.

### mbox\_type {#mbox-type}

    Type: folder magic
    Default: mbox

The default mailbox type used when creating new folders. May be any of
“mbox”, “MMDF”, “MH” and “Maildir”. This is overridden by the `-m`
command-line option.

### menu\_context {#menu-context}

    Type: number
    Default: 0

This variable controls the number of lines of context that are given
when scrolling through menus. (Similar to
[\$pager\_context](#pager-context).)

### menu\_move\_off {#menu-move-off}

    Type: boolean
    Default: yes

When *unset*, the bottom entry of menus will never scroll up past the
bottom of the screen, unless there are less entries than lines. When
*set*, the bottom entry may move off the bottom.

### menu\_scroll {#menu-scroll}

    Type: boolean
    Default: no

When *set*, menus will be scrolled up or down one line when you attempt
to move across a screen boundary. If *unset*, the screen is cleared and
the next or previous page of the menu is displayed (useful for slow
links to avoid many redraws).

### message\_cache\_clean {#message-cache-clean}

    Type: boolean
    Default: no

If *set*, mutt will clean out obsolete entries from the message cache
when the mailbox is synchronized. You probably only want to set it every
once in a while, since it can be a little slow (especially for large
folders).

### message\_cachedir {#message-cachedir}

    Type: path
    Default: (empty)

Set this to a directory and mutt will cache copies of messages from your
IMAP and POP servers here. You are free to remove entries at any time.

When setting this variable to a directory, mutt needs to fetch every
remote message only once and can perform regular expression searches as
fast as for local folders.

Also see the [\$message\_cache\_clean](#message-cache-clean) variable.

### message\_format {#message-format}

    Type: string
    Default: %s

This is the string displayed in the “attachment” menu for attachments of
type `message/rfc822`. For a full listing of defined `printf(3)`-like
sequences see the section on [\$index\_format](#index-format).

### meta\_key {#meta-key}

    Type: boolean
    Default: no

If *set*, forces Mutt to interpret keystrokes with the high bit (bit 8)
set as if the user had pressed the Esc key and whatever key remains
after having the high bit removed. For example, if the key pressed has
an ASCII value of `0xf8`, then this is treated as if the user had
pressed Esc then “x”. This is because the result of removing the high
bit from `0xf8` is `0x78`, which is the ASCII character “x”.

### metoo

    Type: boolean
    Default: no

If *unset*, Mutt will remove your address (see the
“[alternates](#alternates)” command) from the list of recipients when
replying to a message.

### mh\_purge {#mh-purge}

    Type: boolean
    Default: no

When *unset*, mutt will mimic mh's behavior and rename deleted messages
to *,&lt;old file name&gt;* in mh folders instead of really deleting
them. This leaves the message on disk but makes programs reading the
folder ignore it. If the variable is *set*, the message files will
simply be deleted.

This option is similar to [\$maildir\_trash](#maildir-trash) for Maildir
folders.

### mh\_seq\_flagged {#mh-seq-flagged}

    Type: string
    Default: flagged

The name of the MH sequence used for flagged messages.

### mh\_seq\_replied {#mh-seq-replied}

    Type: string
    Default: replied

The name of the MH sequence used to tag replied messages.

### mh\_seq\_unseen {#mh-seq-unseen}

    Type: string
    Default: unseen

The name of the MH sequence used for unseen messages.

### mime\_forward {#mime-forward}

    Type: quadoption
    Default: no

When *set*, the message you are forwarding will be attached as a
separate `message/rfc822` MIME part instead of included in the main body
of the message. This is useful for forwarding MIME messages so the
receiver can properly view the message as it was delivered to you. If
you like to switch between MIME and not MIME from mail to mail, set this
variable to “ask-no” or “ask-yes”.

Also see [\$forward\_decode](#forward-decode) and
[\$mime\_forward\_decode](#mime-forward-decode).

### mime\_forward\_decode {#mime-forward-decode}

    Type: boolean
    Default: no

Controls the decoding of complex MIME messages into `text/plain` when
forwarding a message while [\$mime\_forward](#mime-forward) is *set*.
Otherwise [\$forward\_decode](#forward-decode) is used instead.

### mime\_forward\_rest {#mime-forward-rest}

    Type: quadoption
    Default: yes

When forwarding multiple attachments of a MIME message from the
attachment menu, attachments which cannot be decoded in a reasonable
manner will be attached to the newly composed message if this option is
*set*.

### mime\_subject {#mime-subject}

    Type: boolean
    Default: yes

If *unset*, 8-bit “subject:” line in article header will not be encoded
according to RFC2047 to base64. This is useful when message is Usenet
article, because MIME for news is nonstandard feature.

### mix\_entry\_format {#mix-entry-format}

    Type: string
    Default: %4n %c %-16s %a

This variable describes the format of a remailer line on the mixmaster
chain selection screen. The following `printf(3)`-like sequences are
supported:

  ---- ---------------------------------
  %n   The running number on the menu.
  %c   Remailer capabilities.
  %s   The remailer's short name.
  %a   The remailer's e-mail address.
  ---- ---------------------------------

### mixmaster

    Type: path
    Default: mixmaster

This variable contains the path to the Mixmaster binary on your system.
It is used with various sets of parameters to gather the list of known
remailers, and to finally send a message through the mixmaster chain.

### move

    Type: quadoption
    Default: no

Controls whether or not Mutt will move read messages from your spool
mailbox to your [\$mbox](#mbox) mailbox, or as a result of a
“[mbox-hook](#mbox-hook)” command.

### narrow\_tree {#narrow-tree}

    Type: boolean
    Default: no

This variable, when *set*, makes the thread tree narrower, allowing
deeper threads to fit on the screen.

### net\_inc {#net-inc}

    Type: number
    Default: 10

Operations that expect to transfer a large amount of data over the
network will update their progress every [\$net\_inc](#net-inc)
kilobytes. If set to 0, no progress messages will be displayed.

See also [\$read\_inc](#read-inc), [\$write\_inc](#write-inc) and
[\$net\_inc](#net-inc).

### new\_mail\_command {#new-mail-command}

    Type: path
    Default: NULL

If *set*, Mutt will call this command after a new message is received.
See the [\$status\_format](#status-format) documentation for the values
that can be formatted into this command.

### news\_cache\_dir {#news-cache-dir}

    Type: path
    Default: ~/.mutt

This variable pointing to directory where Mutt will save cached news
articles and headers in. If *unset*, articles and headers will not be
saved at all and will be reloaded from the server each time.

### news\_server {#news-server}

    Type: string
    Default: (empty)

This variable specifies domain name or address of NNTP server. It
defaults to the news server specified in the environment variable
\$NNTPSERVER or contained in the file /etc/nntpserver. You can also
specify username and an alternative port for each news server, ie:

\[\[s\]news://\]\[username\[:password\]@\]server\[:port\]

### newsgroups\_charset {#newsgroups-charset}

    Type: string
    Default: utf-8

Character set of newsgroups descriptions.

### newsrc

    Type: path
    Default: ~/.newsrc

The file, containing info about subscribed newsgroups - names and
indexes of read articles. The following printf-style sequence is
understood:

  ---- -------------------
  %a   account url
  %p   port
  %P   port if specified
  %s   news server name
  %S   url schema
  %u   username
  ---- -------------------

### nntp\_authenticators {#nntp-authenticators}

    Type: string
    Default: (empty)

This is a colon-delimited list of authentication methods mutt may
attempt to use to log in to a news server, in the order mutt should try
them. Authentication methods are either “user” or any SASL mechanism,
e.g. “digest-md5”, “gssapi” or “cram-md5”. This option is
case-insensitive. If it's *unset* (the default) mutt will try all
available methods, in order from most-secure to least-secure.

Example:

    set nntp_authenticators="digest-md5:user"

**Note:** Mutt will only fall back to other authentication methods if
the previous methods are unavailable. If a method is available but
authentication fails, mutt will not connect to the IMAP server.

### nntp\_context {#nntp-context}

    Type: number
    Default: 1000

This variable defines number of articles which will be in index when
newsgroup entered. If active newsgroup have more articles than this
number, oldest articles will be ignored. Also controls how many articles
headers will be saved in cache when you quit newsgroup.

### nntp\_listgroup {#nntp-listgroup}

    Type: boolean
    Default: yes

This variable controls whether or not existence of each article is
checked when newsgroup is entered.

### nntp\_load\_description {#nntp-load-description}

    Type: boolean
    Default: yes

This variable controls whether or not descriptions for each newsgroup
must be loaded when newsgroup is added to list (first time list loading
or new newsgroup adding).

### nntp\_user {#nntp-user}

    Type: string
    Default: (empty)

Your login name on the NNTP server. If *unset* and NNTP server requires
authentication, Mutt will prompt you for your account name when you
connect to news server.

### nntp\_pass {#nntp-pass}

    Type: string
    Default: (empty)

Your password for NNTP account.

### nntp\_poll {#nntp-poll}

    Type: number
    Default: 60

The time in seconds until any operations on newsgroup except post new
article will cause recheck for new news. If set to 0, Mutt will recheck
newsgroup on each operation in index (stepping, read article, etc.).

### pager {#pager}

    Type: path
    Default: builtin

This variable specifies which pager you would like to use to view
messages. The value “builtin” means to use the built-in pager, otherwise
this variable should specify the pathname of the external pager you
would like to use.

Using an external pager may have some disadvantages: Additional
keystrokes are necessary because you can't call mutt functions directly
from the pager, and screen resizes cause lines longer than the screen
width to be badly formatted in the help menu.

### pager\_context {#pager-context}

    Type: number
    Default: 0

This variable controls the number of lines of context that are given
when displaying the next or previous page in the internal pager. By
default, Mutt will display the line after the last one on the screen at
the top of the next page (0 lines of context).

This variable also specifies the amount of context given for search
results. If positive, this many lines will be given before a match, if
0, the match will be top-aligned.

### pager\_format {#pager-format}

    Type: string
    Default: -%Z- %C/%m: %-20.20n   %s%*  -- (%P)

This variable controls the format of the one-line message “status”
displayed before each message in either the internal or an external
pager. The valid sequences are listed in the
[\$index\_format](#index-format) section.

### pager\_index\_lines {#pager-index-lines}

    Type: number
    Default: 0

Determines the number of lines of a mini-index which is shown when in
the pager. The current message, unless near the top or bottom of the
folder, will be roughly one third of the way down this mini-index,
giving the reader the context of a few messages before and after the
message. This is useful, for example, to determine how many messages
remain to be read in the current thread. One of the lines is reserved
for the status bar from the index, so a setting of 6 will only show 5
lines of the actual index. A value of 0 results in no index being shown.
If the number of messages in the current folder is less than
[\$pager\_index\_lines](#pager-index-lines), then the index will only
use as many lines as it needs.

### pager\_stop {#pager-stop}

    Type: boolean
    Default: no

When *set*, the internal-pager will **not** move to the next message
when you are at the end of a message and invoke the `<next-page>`
function.

### pgp\_auto\_decode {#pgp-auto-decode}

    Type: boolean
    Default: no

If *set*, mutt will automatically attempt to decrypt traditional PGP
messages whenever the user performs an operation which ordinarily would
result in the contents of the message being operated on. For example, if
the user displays a pgp-traditional message which has not been manually
checked with the `<check-traditional-pgp>` function, mutt will
automatically check the message for traditional pgp.

### pgp\_autoinline {#pgp-autoinline}

    Type: boolean
    Default: no

This option controls whether Mutt generates old-style inline
(traditional) PGP encrypted or signed messages under certain
circumstances. This can be overridden by use of the pgp menu, when
inline is not required. The GPGME backend does not support this option.

Note that Mutt might automatically use PGP/MIME for messages which
consist of more than a single MIME part. Mutt can be configured to ask
before sending PGP/MIME messages when inline (traditional) would not
work.

Also see the [\$pgp\_mime\_auto](#pgp-mime-auto) variable.

Also note that using the old-style PGP message format is **strongly**
**deprecated**. (PGP only)

### pgp\_check\_exit {#pgp-check-exit}

    Type: boolean
    Default: yes

If *set*, mutt will check the exit code of the PGP subprocess when
signing or encrypting. A non-zero exit code means that the subprocess
failed. (PGP only)

### pgp\_clearsign\_command {#pgp-clearsign-command}

    Type: string
    Default: (empty)

This format is used to create an old-style “clearsigned” PGP message.
Note that the use of this format is **strongly** **deprecated**.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pgp\_decode\_command {#pgp-decode-command}

    Type: string
    Default: (empty)

This format strings specifies a command which is used to decode
application/pgp attachments.

The PGP command formats have their own set of `printf(3)`-like
sequences:

  ---- --------------------------------------------------------------------------------------------------------------------------------
  %p   Expands to PGPPASSFD=0 when a pass phrase is needed, to an empty string otherwise. Note: This may be used with a %? construct.
  %f   Expands to the name of a file containing a message.
  %s   Expands to the name of a file containing the signature part of a `multipart/signed` attachment when verifying it.
  %a   The value of [\$pgp\_sign\_as](#pgp-sign-as).
  %r   One or more key IDs (or fingerprints if available).
  ---- --------------------------------------------------------------------------------------------------------------------------------

For examples on how to configure these formats for the various versions
of PGP which are floating around, see the pgp and gpg sample
configuration files in the `samples/` subdirectory which has been
installed on your system alongside the documentation. (PGP only)

### pgp\_decrypt\_command {#pgp-decrypt-command}

    Type: string
    Default: (empty)

This command is used to decrypt a PGP encrypted message.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pgp\_decryption\_okay {#pgp-decryption-okay}

    Type: regular expression
    Default: (empty)

If you assign text to this variable, then an encrypted PGP message is
only considered successfully decrypted if the output from
[\$pgp\_decrypt\_command](#pgp-decrypt-command) contains the text. This
is used to protect against a spoofed encrypted message, with
multipart/encrypted headers but containing a block that is not actually
encrypted. (e.g. simply signed and ascii armored text). (PGP only)

### pgp\_encrypt\_only\_command {#pgp-encrypt-only-command}

    Type: string
    Default: (empty)

This command is used to encrypt a body part without signing it.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pgp\_encrypt\_sign\_command {#pgp-encrypt-sign-command}

    Type: string
    Default: (empty)

This command is used to both sign and encrypt a body part.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pgp\_entry\_format {#pgp-entry-format}

    Type: string
    Default: %4n %t%f %4l/0x%k %-4a %2c %u

This variable allows you to customize the PGP key selection menu to your
personal taste. This string is similar to
[\$index\_format](#index-format), but has its own set of
`printf(3)`-like sequences:

  ---------------- ----------------------------------------------------------------
  %n               number
  %k               key id
  %u               user id
  %a               algorithm
  %l               key length
  %p               protocol
  %f               flags
  %c               capabilities
  %t               trust/validity of the key-uid association
  %\[&lt;s&gt;\]   date of the key where &lt;s&gt; is an `strftime(3)` expression
  ---------------- ----------------------------------------------------------------

(PGP only)

### pgp\_export\_command {#pgp-export-command}

    Type: string
    Default: (empty)

This command is used to export a public key from the user's key ring.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pgp\_getkeys\_command {#pgp-getkeys-command}

    Type: string
    Default: (empty)

This command is invoked whenever Mutt needs to fetch the public key
associated with an email address. Of the sequences supported by
[\$pgp\_decode\_command](#pgp-decode-command), %r is the only
`printf(3)`-like sequence used with this format. Note that in this case,
%r expands to the email address, not the public key ID (the key ID is
unknown, which is why Mutt is invoking this command). (PGP only)

### pgp\_good\_sign {#pgp-good-sign}

    Type: regular expression
    Default: (empty)

If you assign a text to this variable, then a PGP signature is only
considered verified if the output from
[\$pgp\_verify\_command](#pgp-verify-command) contains the text. Use
this variable if the exit code from the command is 0 even for bad
signatures. (PGP only)

### pgp\_ignore\_subkeys {#pgp-ignore-subkeys}

    Type: boolean
    Default: yes

Setting this variable will cause Mutt to ignore OpenPGP subkeys.
Instead, the principal key will inherit the subkeys' capabilities.
*Unset* this if you want to play interesting key selection games. (PGP
only)

### pgp\_import\_command {#pgp-import-command}

    Type: string
    Default: (empty)

This command is used to import a key from a message into the user's
public key ring.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pgp\_list\_pubring\_command {#pgp-list-pubring-command}

    Type: string
    Default: (empty)

This command is used to list the public key ring's contents. The output
format must be analogous to the one used by

    gpg --list-keys --with-colons --with-fingerprint

This format is also generated by the `pgpring` utility which comes with
mutt.

Note: gpg's `fixed-list-mode` option should not be used. It produces a
different date format which may result in mutt showing incorrect key
generation dates.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pgp\_list\_secring\_command {#pgp-list-secring-command}

    Type: string
    Default: (empty)

This command is used to list the secret key ring's contents. The output
format must be analogous to the one used by:

    gpg --list-keys --with-colons --with-fingerprint

This format is also generated by the `pgpring` utility which comes with
mutt.

Note: gpg's `fixed-list-mode` option should not be used. It produces a
different date format which may result in mutt showing incorrect key
generation dates.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pgp\_long\_ids {#pgp-long-ids}

    Type: boolean
    Default: yes

If *set*, use 64 bit PGP key IDs, if *unset* use the normal 32 bit key
IDs. NOTE: Internally, Mutt has transitioned to using fingerprints (or
long key IDs as a fallback). This option now only controls the display
of key IDs in the key selection menu and a few other places. (PGP only)

### pgp\_mime\_auto {#pgp-mime-auto}

    Type: quadoption
    Default: ask-yes

This option controls whether Mutt will prompt you for automatically
sending a (signed/encrypted) message using PGP/MIME when inline
(traditional) fails (for any reason).

Also note that using the old-style PGP message format is **strongly**
**deprecated**. (PGP only)

### pgp\_replyinline {#pgp-replyinline}

    Type: boolean
    Default: no

Setting this variable will cause Mutt to always attempt to create an
inline (traditional) message when replying to a message which is PGP
encrypted/signed inline. This can be overridden by use of the pgp menu,
when inline is not required. This option does not automatically detect
if the (replied-to) message is inline; instead it relies on Mutt
internals for previously checked/flagged messages.

Note that Mutt might automatically use PGP/MIME for messages which
consist of more than a single MIME part. Mutt can be configured to ask
before sending PGP/MIME messages when inline (traditional) would not
work.

Also see the [\$pgp\_mime\_auto](#pgp-mime-auto) variable.

Also note that using the old-style PGP message format is **strongly**
**deprecated**. (PGP only)

### pgp\_retainable\_sigs {#pgp-retainable-sigs}

    Type: boolean
    Default: no

If *set*, signed and encrypted messages will consist of nested
`multipart/signed` and `multipart/encrypted` body parts.

This is useful for applications like encrypted and signed mailing lists,
where the outer layer (`multipart/encrypted`) can be easily removed,
while the inner `multipart/signed` part is retained. (PGP only)

### pgp\_self\_encrypt {#pgp-self-encrypt}

    Type: boolean
    Default: no

When *set*, PGP encrypted messages will also be encrypted using the key
in [\$pgp\_self\_encrypt\_as](#pgp-self-encrypt-as). (PGP only)

### pgp\_self\_encrypt\_as {#pgp-self-encrypt-as}

    Type: string
    Default: (empty)

This is an additional key used to encrypt messages when
[\$pgp\_self\_encrypt](#pgp-self-encrypt) is *set*. It is also used to
specify the key for [\$postpone\_encrypt](#postpone-encrypt). It should
be in keyid or fingerprint form (e.g. 0x00112233). (PGP only)

### pgp\_show\_unusable {#pgp-show-unusable}

    Type: boolean
    Default: yes

If *set*, mutt will display non-usable keys on the PGP key selection
menu. This includes keys which have been revoked, have expired, or have
been marked as “disabled” by the user. (PGP only)

### pgp\_sign\_as {#pgp-sign-as}

    Type: string
    Default: (empty)

If you have more than one key pair, this option allows you to specify
which of your private keys to use. It is recommended that you use the
keyid form to specify your key (e.g. `0x00112233`). (PGP only)

### pgp\_sign\_command {#pgp-sign-command}

    Type: string
    Default: (empty)

This command is used to create the detached PGP signature for a
`multipart/signed` PGP/MIME body part.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pgp\_sort\_keys {#pgp-sort-keys}

    Type: sort order
    Default: address

Specifies how the entries in the pgp menu are sorted. The following are
legal values:

  --------- --------------------------------
  address   sort alphabetically by user id
  keyid     sort alphabetically by key id
  date      sort by key creation date
  trust     sort by the trust of the key
  --------- --------------------------------

If you prefer reverse order of the above values, prefix it with
“reverse-”. (PGP only)

### pgp\_strict\_enc {#pgp-strict-enc}

    Type: boolean
    Default: yes

If *set*, Mutt will automatically encode PGP/MIME signed messages as
quoted-printable. Please note that unsetting this variable may lead to
problems with non-verifyable PGP signatures, so only change this if you
know what you are doing. (PGP only)

### pgp\_timeout {#pgp-timeout}

    Type: number
    Default: 300

The number of seconds after which a cached passphrase will expire if not
used. (PGP only)

### pgp\_use\_gpg\_agent {#pgp-use-gpg-agent}

    Type: boolean
    Default: no

If *set*, mutt will use a possibly-running `gpg-agent(1)` process. Note
that as of version 2.1, GnuPG no longer exports GPG\_AGENT\_INFO, so
mutt no longer verifies if the agent is running. (PGP only)

### pgp\_verify\_command {#pgp-verify-command}

    Type: string
    Default: (empty)

This command is used to verify PGP signatures.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pgp\_verify\_key\_command {#pgp-verify-key-command}

    Type: string
    Default: (empty)

This command is used to verify key information from the key selection
menu.

This is a format string, see the
[\$pgp\_decode\_command](#pgp-decode-command) command for possible
`printf(3)`-like sequences. (PGP only)

### pipe\_decode {#pipe-decode}

    Type: boolean
    Default: no

Used in connection with the `<pipe-message>` command. When *unset*, Mutt
will pipe the messages without any preprocessing. When *set*, Mutt will
weed headers and will attempt to decode the messages first.

### pipe\_sep {#pipe-sep}

    Type: string
    Default: \n

The separator to add between messages when piping a list of tagged
messages to an external Unix command.

### pipe\_split {#pipe-split}

    Type: boolean
    Default: no

Used in connection with the `<pipe-message>` function following
`<tag-prefix>`. If this variable is *unset*, when piping a list of
tagged messages Mutt will concatenate the messages and will pipe them
all concatenated. When *set*, Mutt will pipe the messages one by one. In
both cases the messages are piped in the current sorted order, and the
[\$pipe\_sep](#pipe-sep) separator is added after each message.

### pop\_auth\_try\_all {#pop-auth-try-all}

    Type: boolean
    Default: yes

If *set*, Mutt will try all available authentication methods. When
*unset*, Mutt will only fall back to other authentication methods if the
previous methods are unavailable. If a method is available but
authentication fails, Mutt will not connect to the POP server.

### pop\_authenticators {#pop-authenticators}

    Type: string
    Default: (empty)

This is a colon-delimited list of authentication methods mutt may
attempt to use to log in to an POP server, in the order mutt should try
them. Authentication methods are either “user”, “apop” or any SASL
mechanism, e.g. “digest-md5”, “gssapi” or “cram-md5”. This option is
case-insensitive. If this option is *unset* (the default) mutt will try
all available methods, in order from most-secure to least-secure.

Example:

    set pop_authenticators="digest-md5:apop:user"

### pop\_checkinterval {#pop-checkinterval}

    Type: number
    Default: 60

This variable configures how often (in seconds) mutt should look for new
mail in the currently selected mailbox if it is a POP mailbox.

### pop\_delete {#pop-delete}

    Type: quadoption
    Default: ask-no

If *set*, Mutt will delete successfully downloaded messages from the POP
server when using the `<fetch-mail>` function. When *unset*, Mutt will
download messages but also leave them on the POP server.

### pop\_host {#pop-host}

    Type: string
    Default: (empty)

The name of your POP server for the `<fetch-mail>` function. You can
also specify an alternative port, username and password, i.e.:

    [pop[s]://][username[:password]@]popserver[:port]

where “\[...\]” denotes an optional part.

### pop\_last {#pop-last}

    Type: boolean
    Default: no

If this variable is *set*, mutt will try to use the “`LAST`” POP command
for retrieving only unread messages from the POP server when using the
`<fetch-mail>` function.

### pop\_pass {#pop-pass}

    Type: string
    Default: (empty)

Specifies the password for your POP account. If *unset*, Mutt will
prompt you for your password when you open a POP mailbox.

**Warning**: you should only use this option when you are on a fairly
secure machine, because the superuser can read your muttrc even if you
are the only one who can read the file.

### pop\_reconnect {#pop-reconnect}

    Type: quadoption
    Default: ask-yes

Controls whether or not Mutt will try to reconnect to the POP server if
the connection is lost.

### pop\_user {#pop-user}

    Type: string
    Default: (empty)

Your login name on the POP server.

This variable defaults to your user name on the local machine.

### post\_indent\_string {#post-indent-string}

    Type: string
    Default: (empty)

Similar to the [\$attribution](#attribution) variable, Mutt will append
this string after the inclusion of a message which is being replied to.

### post\_moderated {#post-moderated}

    Type: quadoption
    Default: ask-yes

If set to *yes*, Mutt will post article to newsgroup that have not
permissions to posting (e.g. moderated). **Note:** if news server does
not support posting to that newsgroup or totally read-only, that posting
will not have an effect.

### postpone

    Type: quadoption
    Default: ask-yes

Controls whether or not messages are saved in the
[\$postponed](#postponed) mailbox when you elect not to send
immediately.

Also see the [\$recall](#recall) variable.

### postponed

    Type: path
    Default: ~/postponed

Mutt allows you to indefinitely “[postpone](#postpone) sending a
message” which you are editing. When you choose to postpone a message,
Mutt saves it in the mailbox specified by this variable.

Also see the [\$postpone](#postpone) variable.

### postpone\_encrypt {#postpone-encrypt}

    Type: boolean
    Default: no

When *set*, postponed messages that are marked for encryption will be
self-encrypted. Mutt will first try to encrypt using the value specified
in [\$pgp\_self\_encrypt\_as](#pgp-self-encrypt-as) or
[\$smime\_self\_encrypt\_as](#smime-self-encrypt-as). If those are not
set, it will try the deprecated
[\$postpone\_encrypt\_as](#postpone-encrypt-as). (Crypto only)

### postpone\_encrypt\_as {#postpone-encrypt-as}

    Type: string
    Default: (empty)

This is a deprecated fall-back variable for
[\$postpone\_encrypt](#postpone-encrypt). Please use
[\$pgp\_self\_encrypt\_as](#pgp-self-encrypt-as) or
[\$smime\_self\_encrypt\_as](#smime-self-encrypt-as). (Crypto only)

### preconnect

    Type: string
    Default: (empty)

If *set*, a shell command to be executed if mutt fails to establish a
connection to the server. This is useful for setting up secure
connections, e.g. with `ssh(1)`. If the command returns a nonzero
status, mutt gives up opening the server. Example:

    set preconnect="ssh -f -q -L 1234:mailhost.net:143 mailhost.net \
    sleep 20 < /dev/null > /dev/null"

Mailbox “foo” on “mailhost.net” can now be reached as
“{localhost:1234}foo”.

Note: For this example to work, you must be able to log in to the remote
machine without having to enter a password.

### print

    Type: quadoption
    Default: ask-no

Controls whether or not Mutt really prints messages. This is set to
“ask-no” by default, because some people accidentally hit “p” often.

### print\_command {#print-command}

    Type: path
    Default: lpr

This specifies the command pipe that should be used to print messages.

### print\_decode {#print-decode}

    Type: boolean
    Default: yes

Used in connection with the `<print-message>` command. If this option is
*set*, the message is decoded before it is passed to the external
command specified by [\$print\_command](#print-command). If this option
is *unset*, no processing will be applied to the message when printing
it. The latter setting may be useful if you are using some advanced
printer filter which is able to properly format e-mail messages for
printing.

### print\_split {#print-split}

    Type: boolean
    Default: no

Used in connection with the `<print-message>` command. If this option is
*set*, the command specified by [\$print\_command](#print-command) is
executed once for each message which is to be printed. If this option is
*unset*, the command specified by [\$print\_command](#print-command) is
executed only once, and all the messages are concatenated, with a form
feed as the message separator.

Those who use the `enscript`(1) program's mail-printing mode will most
likely want to *set* this option.

### prompt\_after {#prompt-after}

    Type: boolean
    Default: yes

If you use an *external* [\$pager](#pager), setting this variable will
cause Mutt to prompt you for a command when the pager exits rather than
returning to the index menu. If *unset*, Mutt will return to the index
menu when the external pager exits.

### query\_command {#query-command}

    Type: path
    Default: (empty)

This specifies the command Mutt will use to make external address
queries. The string may contain a “%s”, which will be substituted with
the query string the user types. Mutt will add quotes around the string
substituted for “%s” automatically according to shell quoting rules, so
you should avoid adding your own. If no “%s” is found in the string,
Mutt will append the user's query to the end of the string. See
“[query](#query)” for more information.

### query\_format {#query-format}

    Type: string
    Default: %4c %t %-25.25a %-25.25n %?e?(%e)?

This variable describes the format of the “query” menu. The following
`printf(3)`-style sequences are understood:

  -------- -------------------------------------------------------
  %a       destination address
  %c       current entry number
  %e       extra information \*
  %n       destination name
  %t       “\*” if current entry is tagged, a space otherwise
  %&gt;X   right justify the rest of the string and pad with “X”
  %|X      pad to the end of the line with “X”
  %\*X     soft-fill with character “X” as pad
  -------- -------------------------------------------------------

For an explanation of “soft-fill”, see the
[\$index\_format](#index-format) documentation.

\* = can be optionally printed if nonzero, see the
[\$status\_format](#status-format) documentation.

### quit

    Type: quadoption
    Default: yes

This variable controls whether “quit” and “exit” actually quit from
mutt. If this option is *set*, they do quit, if it is *unset*, they have
no effect, and if it is set to *ask-yes* or *ask-no*, you are prompted
for confirmation when you try to quit.

### quote\_regexp {#quote-regexp}

    Type: regular expression
    Default: ^([ \t]*[|>:}#])+

A regular expression used in the internal pager to determine quoted
sections of text in the body of a message. Quoted text may be filtered
out using the `<toggle-quoted>` command, or colored according to the
“color quoted” family of directives.

Higher levels of quoting may be colored differently (“color quoted1”,
“color quoted2”, etc.). The quoting level is determined by removing the
last character from the matched text and recursively reapplying the
regular expression until it fails to produce a match.

Match detection may be overridden by the [\$smileys](#smileys) regular
expression.

### read\_inc {#read-inc}

    Type: number
    Default: 10

If set to a value greater than 0, Mutt will display which message it is
currently on when reading a mailbox or when performing search actions
such as search and limit. The message is printed after this many
messages have been read or searched (e.g., if set to 25, Mutt will print
a message when it is at message 25, and then again when it gets to
message 50). This variable is meant to indicate progress when reading or
searching large mailboxes which may take some time. When set to 0, only
a single message will appear before the reading the mailbox.

Also see the [\$write\_inc](#write-inc), [\$net\_inc](#net-inc) and
[\$time\_inc](#time-inc) variables and the “[tuning](#tuning)” section
of the manual for performance considerations.

### read\_only {#read-only}

    Type: boolean
    Default: no

If *set*, all folders are opened in read-only mode.

### realname

    Type: string
    Default: (empty)

This variable specifies what “real” or “personal” name should be used
when sending messages.

By default, this is the GECOS field from `/etc/passwd`. Note that this
variable will *not* be used when the user has set a real name in the
[\$from](#from) variable.

### recall

    Type: quadoption
    Default: ask-yes

Controls whether or not Mutt recalls postponed messages when composing a
new message.

Setting this variable to *yes* is not generally useful, and thus not
recommended. Note that the `<recall-message>` function can be used to
manually recall postponed messages.

Also see [\$postponed](#postponed) variable.

### record

    Type: path
    Default: ~/sent

This specifies the file into which your outgoing messages should be
appended. (This is meant as the primary method for saving a copy of your
messages, but another way to do this is using the “[my\_hdr](#my-hdr)”
command to create a “Bcc:” field with your email address in it.)

The value of *[\$record](#record)* is overridden by the
[\$force\_name](#force-name) and [\$save\_name](#save-name) variables,
and the “[fcc-hook](#fcc-hook)” command.

### reflow\_space\_quotes {#reflow-space-quotes}

    Type: boolean
    Default: yes

This option controls how quotes from format=flowed messages are
displayed in the pager and when replying (with
[\$text\_flowed](#text-flowed) *unset*). When set, this option adds
spaces after each level of quote marks, turning "&gt;&gt;&gt;foo" into
"&gt; &gt; &gt; foo".

**Note:** If [\$reflow\_text](#reflow-text) is *unset*, this option has
no effect. Also, this option does not affect replies when
[\$text\_flowed](#text-flowed) is *set*.

### reflow\_text {#reflow-text}

    Type: boolean
    Default: yes

When *set*, Mutt will reformat paragraphs in text/plain parts marked
format=flowed. If *unset*, Mutt will display paragraphs unaltered from
how they appear in the message body. See RFC3676 for details on the
*format=flowed* format.

Also see [\$reflow\_wrap](#reflow-wrap), and [\$wrap](#wrap).

### reflow\_wrap {#reflow-wrap}

    Type: number
    Default: 78

This variable controls the maximum paragraph width when reformatting
text/plain parts when [\$reflow\_text](#reflow-text) is *set*. When the
value is 0, paragraphs will be wrapped at the terminal's right margin. A
positive value sets the paragraph width relative to the left margin. A
negative value set the paragraph width relative to the right margin.

Also see [\$wrap](#wrap).

### reply\_regexp {#reply-regexp}

    Type: regular expression
    Default: ^(re([\[0-9\]+])*|aw):[ \t]*

A regular expression used to recognize reply messages when threading and
replying. The default value corresponds to the English "Re:" and the
German "Aw:".

### reply\_self {#reply-self}

    Type: boolean
    Default: no

If *unset* and you are replying to a message sent by you, Mutt will
assume that you want to reply to the recipients of that message rather
than to yourself.

Also see the “[alternates](#alternates)” command.

### reply\_to {#reply-to}

    Type: quadoption
    Default: ask-yes

If *set*, when replying to a message, Mutt will use the address listed
in the Reply-to: header as the recipient of the reply. If *unset*, it
will use the address in the From: header field instead. This option is
useful for reading a mailing list that sets the Reply-To: header field
to the list address and you want to send a private message to the author
of a message.

### reply\_with\_xorig {#reply-with-xorig}

    Type: boolean
    Default: no

This variable provides a toggle. When active, the From: header will be
extracted from the current mail's \`X-Original-To:' header. This setting
does not have precedence over “[reverse\_realname](#reverse-realname)”.

Assuming \`fast\_reply' is disabled, this option will prompt the user
with a prefilled From: header.

### resolve

    Type: boolean
    Default: yes

When *set*, the cursor will be automatically advanced to the next
(possibly undeleted) message whenever a command that modifies the
current message is executed.

### resume\_draft\_files {#resume-draft-files}

    Type: boolean
    Default: no

If *set*, draft files (specified by `-H` on the command line) are
processed similarly to when resuming a postponed message. Recipients are
not prompted for; send-hooks are not evaluated; no alias expansion takes
place; user-defined headers and signatures are not added to the message.

### resume\_edited\_draft\_files {#resume-edited-draft-files}

    Type: boolean
    Default: yes

If *set*, draft files previously edited (via `-E -H` on the command
line) will have [\$resume\_draft\_files](#resume-draft-files)
automatically set when they are used as a draft file again.

The first time a draft file is saved, mutt will add a header,
X-Mutt-Resume-Draft to the saved file. The next time the draft file is
read in, if mutt sees the header, it will set
[\$resume\_draft\_files](#resume-draft-files).

This option is designed to prevent multiple signatures, user-defined
headers, and other processing effects from being made multiple times to
the draft file.

### reverse\_alias {#reverse-alias}

    Type: boolean
    Default: no

This variable controls whether or not Mutt will display the “personal”
name from your aliases in the index menu if it finds an alias that
matches the message's sender. For example, if you have the following
alias:

    alias juser abd30425@somewhere.net (Joe User)

and then you receive mail which contains the following header:

    From: abd30425@somewhere.net

It would be displayed in the index menu as “Joe User” instead of
“abd30425@somewhere.net.” This is useful when the person's e-mail
address is not human friendly.

### reverse\_name {#reverse-name}

    Type: boolean
    Default: no

It may sometimes arrive that you receive mail to a certain machine, move
the messages to another machine, and reply to some the messages from
there. If this variable is *set*, the default *From:* line of the reply
messages is built using the address where you received the messages you
are replying to **if** that address matches your
“[alternates](#alternates)”. If the variable is *unset*, or the address
that would be used doesn't match your “[alternates](#alternates)”, the
*From:* line will use your address on the current machine.

Also see the “[alternates](#alternates)” command.

### reverse\_realname {#reverse-realname}

    Type: boolean
    Default: yes

This variable fine-tunes the behavior of the
[\$reverse\_name](#reverse-name) feature. When it is *set*, mutt will
use the address from incoming messages as-is, possibly including
eventual real names. When it is *unset*, mutt will override any such
real names with the setting of the [\$realname](#realname) variable.

### rfc2047\_parameters {#rfc2047-parameters}

    Type: boolean
    Default: no

When this variable is *set*, Mutt will decode RFC2047-encoded MIME
parameters. You want to set this variable when mutt suggests you to save
attachments to files named like:

    =?iso-8859-1?Q?file=5F=E4=5F991116=2Ezip?=

When this variable is *set* interactively, the change won't be active
until you change folders.

Note that this use of RFC2047's encoding is explicitly prohibited by the
standard, but nevertheless encountered in the wild.

Also note that setting this parameter will *not* have the effect that
mutt *generates* this kind of encoding. Instead, mutt will
unconditionally use the encoding specified in RFC2231.

### save\_address {#save-address}

    Type: boolean
    Default: no

If *set*, mutt will take the sender's full address when choosing a
default folder for saving a mail. If [\$save\_name](#save-name) or
[\$force\_name](#force-name) is *set* too, the selection of the Fcc
folder will be changed as well.

### save\_empty {#save-empty}

    Type: boolean
    Default: yes

When *unset*, mailboxes which contain no saved messages will be removed
when closed (the exception is [\$spoolfile](#spoolfile) which is never
removed). If *set*, mailboxes are never removed.

**Note:** This only applies to mbox and MMDF folders, Mutt does not
delete MH and Maildir directories.

### save\_history {#save-history}

    Type: number
    Default: 0

This variable controls the size of the history (per category) saved in
the [\$history\_file](#history-file) file.

### save\_name {#save-name}

    Type: boolean
    Default: no

This variable controls how copies of outgoing messages are saved. When
*set*, a check is made to see if a mailbox specified by the recipient
address exists (this is done by searching for a mailbox in the
[\$folder](#folder) directory with the *username* part of the recipient
address). If the mailbox exists, the outgoing message will be saved to
that mailbox, otherwise the message is saved to the [\$record](#record)
mailbox.

Also see the [\$force\_name](#force-name) variable.

### score

    Type: boolean
    Default: yes

When this variable is *unset*, scoring is turned off. This can be useful
to selectively disable scoring for certain folders when the
[\$score\_threshold\_delete](#score-threshold-delete) variable and
related are used.

### score\_threshold\_delete {#score-threshold-delete}

    Type: number
    Default: -1

Messages which have been assigned a score equal to or lower than the
value of this variable are automatically marked for deletion by mutt.
Since mutt scores are always greater than or equal to zero, the default
setting of this variable will never mark a message for deletion.

### score\_threshold\_flag {#score-threshold-flag}

    Type: number
    Default: 9999

Messages which have been assigned a score greater than or equal to this
variable's value are automatically marked "flagged".

### score\_threshold\_read {#score-threshold-read}

    Type: number
    Default: -1

Messages which have been assigned a score equal to or lower than the
value of this variable are automatically marked as read by mutt. Since
mutt scores are always greater than or equal to zero, the default
setting of this variable will never mark a message read.

### search\_context {#search-context}

    Type: number
    Default: 0

For the pager, this variable specifies the number of lines shown before
search results. By default, search results will be top-aligned.

### send\_charset {#send-charset}

    Type: string
    Default: us-ascii:iso-8859-1:utf-8

A colon-delimited list of character sets for outgoing messages. Mutt
will use the first character set into which the text can be converted
exactly. If your [\$charset](#charset) is not “iso-8859-1” and
recipients may not understand “UTF-8”, it is advisable to include in the
list an appropriate widely used standard character set (such as
“iso-8859-2”, “koi8-r” or “iso-2022-jp”) either instead of or after
“iso-8859-1”.

In case the text cannot be converted into one of these exactly, mutt
uses [\$charset](#charset) as a fallback.

### sendmail

    Type: path
    Default: /usr/sbin/sendmail -oem -oi

Specifies the program and arguments used to deliver mail sent by Mutt.
Mutt expects that the specified program interprets additional arguments
as recipient addresses. Mutt appends all recipients after adding a `--`
delimiter (if not already present). Additional flags, such as for
[\$use\_8bitmime](#use-8bitmime),
[\$use\_envelope\_from](#use-envelope-from),
[\$dsn\_notify](#dsn-notify), or [\$dsn\_return](#dsn-return) will be
added before the delimiter.

### sendmail\_wait {#sendmail-wait}

    Type: number
    Default: 0

Specifies the number of seconds to wait for the [\$sendmail](#sendmail)
process to finish before giving up and putting delivery in the
background.

Mutt interprets the value of this variable as follows:

  ------- --------------------------------------------------------------------
  &gt;0   number of seconds to wait for sendmail to finish before continuing
  0       wait forever for sendmail to finish
  &lt;0   always put sendmail in the background without waiting
  ------- --------------------------------------------------------------------

Note that if you specify a value other than 0, the output of the child
process will be put in a temporary file. If there is some error, you
will be informed as to where to find the output.

### shell

    Type: path
    Default: (empty)

Command to use when spawning a subshell. By default, the user's login
shell from `/etc/passwd` is used.

### save\_unsubscribed {#save-unsubscribed}

    Type: boolean
    Default: no

When *set*, info about unsubscribed newsgroups will be saved into
“newsrc” file and into cache.

### show\_new\_news {#show-new-news}

    Type: boolean
    Default: yes

If *set*, news server will be asked for new newsgroups on entering the
browser. Otherwise, it will be done only once for a news server. Also
controls whether or not number of new articles of subscribed newsgroups
will be then checked.

### show\_only\_unread {#show-only-unread}

    Type: boolean
    Default: no

If *set*, only subscribed newsgroups that contain unread articles will
be displayed in browser.

### sidebar\_delim\_chars {#sidebar-delim-chars}

    Type: string
    Default: /.

This contains the list of characters which you would like to treat as
folder separators for displaying paths in the sidebar.

Local mail is often arranged in directories: \`dir1/dir2/mailbox'.

    set sidebar_delim_chars='/'

IMAP mailboxes are often named: \`folder1.folder2.mailbox'.

    set sidebar_delim_chars='.'

**See also:** [\$sidebar\_short\_path](#sidebar-short-path),
[\$sidebar\_folder\_indent](#sidebar-folder-indent),
[\$sidebar\_indent\_string](#sidebar-indent-string).

### sidebar\_divider\_char {#sidebar-divider-char}

    Type: string
    Default: (empty)

This specifies the characters to be drawn between the sidebar (when
visible) and the other Mutt panels. ASCII and Unicode line-drawing
characters are supported.

### sidebar\_folder\_indent {#sidebar-folder-indent}

    Type: boolean
    Default: no

Set this to indent mailboxes in the sidebar.

**See also:** [\$sidebar\_short\_path](#sidebar-short-path),
[\$sidebar\_indent\_string](#sidebar-indent-string),
[\$sidebar\_delim\_chars](#sidebar-delim-chars).

### sidebar\_format {#sidebar-format}

    Type: string
    Default: %B%*  %n

This variable allows you to customize the sidebar display. This string
is similar to [\$index\_format](#index-format), but has its own set of
`printf(3)`-like sequences:

  -------- -----------------------------------------------------------------------------------------------------------------------------
  %B       Name of the mailbox
  %S       \* Size of mailbox (total number of messages)
  %N       \* Number of unread messages in the mailbox
  %n       N if mailbox has new mail, blank otherwise
  %F       \* Number of Flagged messages in the mailbox
  %!       “!” : one flagged message; “!!” : two flagged messages; “n!” : n flagged messages (for n &gt; 2). Otherwise prints nothing.
  %d       \* @ Number of deleted messages
  %L       \* @ Number of messages after limiting
  %t       \* @ Number of tagged messages
  %&gt;X   right justify the rest of the string and pad with “X”
  %|X      pad to the end of the line with “X”
  %\*X     soft-fill with character “X” as pad
  -------- -----------------------------------------------------------------------------------------------------------------------------

\* = Can be optionally printed if nonzero @ = Only applicable to the
current folder

In order to use %S, %N, %F, and %!,
[\$mail\_check\_stats](#mail-check-stats) must be *set*. When thus set,
a suggested value for this option is "%B%?F? \[%F\]?%\* %?N?%N/?%S".

### sidebar\_indent\_string {#sidebar-indent-string}

    Type: string
    Default:   

This specifies the string that is used to indent mailboxes in the
sidebar. It defaults to two spaces.

**See also:** [\$sidebar\_short\_path](#sidebar-short-path),
[\$sidebar\_folder\_indent](#sidebar-folder-indent),
[\$sidebar\_delim\_chars](#sidebar-delim-chars).

### sidebar\_new\_mail\_only {#sidebar-new-mail-only}

    Type: boolean
    Default: no

When set, the sidebar will only display mailboxes containing new, or
flagged, mail.

**See also:** [sidebar\_whitelist](#sidebar-whitelist).

### sidebar\_next\_new\_wrap {#sidebar-next-new-wrap}

    Type: boolean
    Default: no

When set, the `<sidebar-next-new>` command will not stop and the end of
the list of mailboxes, but wrap around to the beginning. The
`<sidebar-prev-new>` command is similarly affected, wrapping around to
the end of the list.

### sidebar\_on\_right {#sidebar-on-right}

    Type: boolean
    Default: no

When set, the sidebar will appear on the right-hand side of the screen.

### sidebar\_short\_path {#sidebar-short-path}

    Type: boolean
    Default: no

By default the sidebar will show the mailbox's path, relative to the
[\$folder](#folder) variable. Setting `sidebar_shortpath=yes` will
shorten the names relative to the previous name. Here's an example:

  ------------------ ------------------- -----------------------------------------------------
  **shortpath=no**   **shortpath=yes**   **shortpath=yes, folderindent=yes, indentstr=".."**
  `fruit`            `fruit`             `fruit`
  `fruit.apple`      `apple`             `..apple`
  `fruit.banana`     `banana`            `..banana`
  `fruit.cherry`     `cherry`            `..cherry`
  ------------------ ------------------- -----------------------------------------------------

**See also:** [\$sidebar\_delim\_chars](#sidebar-delim-chars),
[\$sidebar\_folder\_indent](#sidebar-folder-indent),
[\$sidebar\_indent\_string](#sidebar-indent-string).

### sidebar\_sort\_method {#sidebar-sort-method}

    Type: sort order
    Default: order

Specifies how to sort entries in the file browser. By default, the
entries are sorted alphabetically. Valid values:

-   alpha (alphabetically)

-   count (all message count)

-   flagged (flagged message count)

-   name (alphabetically)

-   new (unread message count)

-   path (alphabetically)

-   unread (unread message count)

-   unsorted

You may optionally use the “reverse-” prefix to specify reverse sorting
order (example: “`set sort_browser=reverse-date`”).

### sidebar\_visible {#sidebar-visible}

    Type: boolean
    Default: no

This specifies whether or not to show sidebar. The sidebar shows a list
of all your mailboxes.

**See also:** [\$sidebar\_format](#sidebar-format),
[\$sidebar\_width](#sidebar-width)

### sidebar\_width {#sidebar-width}

    Type: number
    Default: 30

This controls the width of the sidebar. It is measured in screen
columns. For example: sidebar\_width=20 could display 20 ASCII
characters, or 10 Chinese characters.

### sig\_dashes {#sig-dashes}

    Type: boolean
    Default: yes

If *set*, a line containing “--” (note the trailing space) will be
inserted before your [\$signature](#signature). It is **strongly**
recommended that you not *unset* this variable unless your signature
contains just your name. The reason for this is because many software
packages use “-- \\n” to detect your signature. For example, Mutt has
the ability to highlight the signature in a different color in the
built-in pager.

### sig\_on\_top {#sig-on-top}

    Type: boolean
    Default: no

If *set*, the signature will be included before any quoted or forwarded
text. It is **strongly** recommended that you do not set this variable
unless you really know what you are doing, and are prepared to take some
heat from netiquette guardians.

### signature

    Type: path
    Default: ~/.signature

Specifies the filename of your signature, which is appended to all
outgoing messages. If the filename ends with a pipe (“|”), it is assumed
that filename is a shell command and input should be read from its
standard output.

### simple\_search {#simple-search}

    Type: string
    Default: ~f %s | ~s %s

Specifies how Mutt should expand a simple search into a real search
pattern. A simple search is one that does not contain any of the “\~”
pattern operators. See “[patterns](#patterns)” for more information on
search patterns.

For example, if you simply type “joe” at a search or limit prompt, Mutt
will automatically expand it to the value specified by this variable by
replacing “%s” with the supplied string. For the default value, “joe”
would be expanded to: “\~f joe | \~s joe”.

### skip\_quoted\_offset {#skip-quoted-offset}

    Type: number
    Default: 0

Lines of quoted text that are displayed before the unquoted text after
“skip to quoted” command (S)

### sleep\_time {#sleep-time}

    Type: number
    Default: 1

Specifies time, in seconds, to pause while displaying certain
informational messages, while moving from folder to folder and after
expunging messages from the current folder. The default is to pause one
second, so a value of zero for this option suppresses the pause.

### smart\_wrap {#smart-wrap}

    Type: boolean
    Default: yes

Controls the display of lines longer than the screen width in the
internal pager. If *set*, long lines are wrapped at a word boundary. If
*unset*, lines are simply wrapped at the screen edge. Also see the
[\$markers](#markers) variable.

### smileys

    Type: regular expression
    Default: (>From )|(:[-^]?[][)(><}{|/DP])

The *pager* uses this variable to catch some common false positives of
[\$quote\_regexp](#quote-regexp), most notably smileys and not consider
a line quoted text if it also matches [\$smileys](#smileys). This mostly
happens at the beginning of a line.

### smime\_ask\_cert\_label {#smime-ask-cert-label}

    Type: boolean
    Default: yes

This flag controls whether you want to be asked to enter a label for a
certificate about to be added to the database or not. It is *set* by
default. (S/MIME only)

### smime\_ca\_location {#smime-ca-location}

    Type: path
    Default: (empty)

This variable contains the name of either a directory, or a file which
contains trusted certificates for use with OpenSSL. (S/MIME only)

### smime\_certificates {#smime-certificates}

    Type: path
    Default: (empty)

Since for S/MIME there is no pubring/secring as with PGP, mutt has to
handle storage and retrieval of keys by itself. This is very basic right
now, and keys and certificates are stored in two different directories,
both named as the hash-value retrieved from OpenSSL. There is an index
file which contains mailbox-address keyid pairs, and which can be
manually edited. This option points to the location of the certificates.
(S/MIME only)

### smime\_decrypt\_command {#smime-decrypt-command}

    Type: string
    Default: (empty)

This format string specifies a command which is used to decrypt
`application/x-pkcs7-mime` attachments.

The OpenSSL command formats have their own set of `printf(3)`-like
sequences similar to PGP's:

  ---- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  %f   Expands to the name of a file containing a message.
  %s   Expands to the name of a file containing the signature part of a `multipart/signed` attachment when verifying it.
  %k   The key-pair specified with [\$smime\_default\_key](#smime-default-key)
  %i   Intermediate certificates
  %c   One or more certificate IDs.
  %a   The algorithm used for encryption.
  %d   The message digest algorithm specified with [\$smime\_sign\_digest\_alg](#smime-sign-digest-alg).
  %C   CA location: Depending on whether [\$smime\_ca\_location](#smime-ca-location) points to a directory or file, this expands to “-CApath [\$smime\_ca\_location](#smime-ca-location)” or “-CAfile [\$smime\_ca\_location](#smime-ca-location)”.
  ---- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

For examples on how to configure these formats, see the `smime.rc` in
the `samples/` subdirectory which has been installed on your system
alongside the documentation. (S/MIME only)

### smime\_decrypt\_use\_default\_key {#smime-decrypt-use-default-key}

    Type: boolean
    Default: yes

If *set* (default) this tells mutt to use the default key for
decryption. Otherwise, if managing multiple certificate-key-pairs, mutt
will try to use the mailbox-address to determine the key to use. It will
ask you to supply a key, if it can't find one. (S/MIME only)

### smime\_default\_key {#smime-default-key}

    Type: string
    Default: (empty)

This is the default key-pair to use for signing. This must be set to the
keyid (the hash-value that OpenSSL generates) to work properly (S/MIME
only)

### smime\_encrypt\_command {#smime-encrypt-command}

    Type: string
    Default: (empty)

This command is used to create encrypted S/MIME messages.

This is a format string, see the
[\$smime\_decrypt\_command](#smime-decrypt-command) command for possible
`printf(3)`-like sequences. (S/MIME only)

### smime\_encrypt\_self {#smime-encrypt-self}

    Type: quadoption
    Default: no

Encrypt the message to [\$smime\_default\_key](#smime-default-key) too.
(S/MIME only)

### smime\_encrypt\_with {#smime-encrypt-with}

    Type: string
    Default: aes256

This sets the algorithm that should be used for encryption. Valid
choices are “aes128”, “aes192”, “aes256”, “des”, “des3”, “rc2-40”,
“rc2-64”, “rc2-128”. (S/MIME only)

### smime\_get\_cert\_command {#smime-get-cert-command}

    Type: string
    Default: (empty)

This command is used to extract X509 certificates from a PKCS7
structure.

This is a format string, see the
[\$smime\_decrypt\_command](#smime-decrypt-command) command for possible
`printf(3)`-like sequences. (S/MIME only)

### smime\_get\_cert\_email\_command {#smime-get-cert-email-command}

    Type: string
    Default: (empty)

This command is used to extract the mail address(es) used for storing
X509 certificates, and for verification purposes (to check whether the
certificate was issued for the sender's mailbox).

This is a format string, see the
[\$smime\_decrypt\_command](#smime-decrypt-command) command for possible
`printf(3)`-like sequences. (S/MIME only)

### smime\_get\_signer\_cert\_command {#smime-get-signer-cert-command}

    Type: string
    Default: (empty)

This command is used to extract only the signers X509 certificate from a
S/MIME signature, so that the certificate's owner may get compared to
the email's “From:” field.

This is a format string, see the
[\$smime\_decrypt\_command](#smime-decrypt-command) command for possible
`printf(3)`-like sequences. (S/MIME only)

### smime\_import\_cert\_command {#smime-import-cert-command}

    Type: string
    Default: (empty)

This command is used to import a certificate via smime\_keys.

This is a format string, see the
[\$smime\_decrypt\_command](#smime-decrypt-command) command for possible
`printf(3)`-like sequences. (S/MIME only)

### smime\_is\_default {#smime-is-default}

    Type: boolean
    Default: no

The default behavior of mutt is to use PGP on all auto-sign/encryption
operations. To override and to use OpenSSL instead this must be *set*.
However, this has no effect while replying, since mutt will
automatically select the same application that was used to sign/encrypt
the original message. (Note that this variable can be overridden by
unsetting [\$crypt\_autosmime](#crypt-autosmime).) (S/MIME only)

### smime\_keys {#smime-keys}

    Type: path
    Default: (empty)

Since for S/MIME there is no pubring/secring as with PGP, mutt has to
handle storage and retrieval of keys/certs by itself. This is very basic
right now, and stores keys and certificates in two different
directories, both named as the hash-value retrieved from OpenSSL. There
is an index file which contains mailbox-address keyid pair, and which
can be manually edited. This option points to the location of the
private keys. (S/MIME only)

### smime\_pk7out\_command {#smime-pk7out-command}

    Type: string
    Default: (empty)

This command is used to extract PKCS7 structures of S/MIME signatures,
in order to extract the public X509 certificate(s).

This is a format string, see the
[\$smime\_decrypt\_command](#smime-decrypt-command) command for possible
`printf(3)`-like sequences. (S/MIME only)

### smime\_self\_encrypt {#smime-self-encrypt}

    Type: boolean
    Default: no

When *set*, S/MIME encrypted messages will also be encrypted using the
certificate in [\$smime\_self\_encrypt\_as](#smime-self-encrypt-as).
(S/MIME only)

### smime\_self\_encrypt\_as {#smime-self-encrypt-as}

    Type: string
    Default: (empty)

This is an additional certificate used to encrypt messages when
[\$smime\_self\_encrypt](#smime-self-encrypt) is *set*. It is also used
to specify the certificate for [\$postpone\_encrypt](#postpone-encrypt).
It should be the hash-value that OpenSSL generates. (S/MIME only)

### smime\_sign\_command {#smime-sign-command}

    Type: string
    Default: (empty)

This command is used to created S/MIME signatures of type
`multipart/signed`, which can be read by all mail clients.

This is a format string, see the
[\$smime\_decrypt\_command](#smime-decrypt-command) command for possible
`printf(3)`-like sequences. (S/MIME only)

### smime\_sign\_digest\_alg {#smime-sign-digest-alg}

    Type: string
    Default: sha256

This sets the algorithm that should be used for the signature message
digest. Valid choices are “md5”, “sha1”, “sha224”, “sha256”, “sha384”,
“sha512”. (S/MIME only)

### smime\_timeout {#smime-timeout}

    Type: number
    Default: 300

The number of seconds after which a cached passphrase will expire if not
used. (S/MIME only)

### smime\_verify\_command {#smime-verify-command}

    Type: string
    Default: (empty)

This command is used to verify S/MIME signatures of type
`multipart/signed`.

This is a format string, see the
[\$smime\_decrypt\_command](#smime-decrypt-command) command for possible
`printf(3)`-like sequences. (S/MIME only)

### smime\_verify\_opaque\_command {#smime-verify-opaque-command}

    Type: string
    Default: (empty)

This command is used to verify S/MIME signatures of type
`application/x-pkcs7-mime`.

This is a format string, see the
[\$smime\_decrypt\_command](#smime-decrypt-command) command for possible
`printf(3)`-like sequences. (S/MIME only)

### smtp\_authenticators {#smtp-authenticators}

    Type: string
    Default: (empty)

This is a colon-delimited list of authentication methods mutt may
attempt to use to log in to an SMTP server, in the order mutt should try
them. Authentication methods are any SASL mechanism, e.g. “plain”,
“digest-md5”, “gssapi” or “cram-md5”. This option is case-insensitive.
If it is “unset” (the default) mutt will try all available methods, in
order from most-secure to least-secure. Support for the “plain”
mechanism is bundled; other mechanisms are provided by an external SASL
library (look for +USE\_SASL in the output of mutt -v).

Example:

    set smtp_authenticators="digest-md5:cram-md5"

### smtp\_pass {#smtp-pass}

    Type: string
    Default: (empty)

Specifies the password for your SMTP account. If *unset*, Mutt will
prompt you for your password when you first send mail via SMTP. See
[\$smtp\_url](#smtp-url) to configure mutt to send mail via SMTP.

**Warning**: you should only use this option when you are on a fairly
secure machine, because the superuser can read your muttrc even if you
are the only one who can read the file.

### smtp\_url {#smtp-url}

    Type: string
    Default: (empty)

Defines the SMTP smarthost where sent messages should relayed for
delivery. This should take the form of an SMTP URL, e.g.:

    smtp[s]://[user[:pass]@]host[:port]

where “\[...\]” denotes an optional part. Setting this variable
overrides the value of the [\$sendmail](#sendmail) variable.

### sort {#sort}

    Type: sort order
    Default: date

Specifies how to sort messages in the “index” menu. Valid values are:

-   date or date-sent

-   date-received

-   from

-   mailbox-order (unsorted)

-   score

-   size

-   spam

-   subject

-   threads

-   to

You may optionally use the “reverse-” prefix to specify reverse sorting
order.

Example:

    set sort=reverse-date-sent

### sort\_alias {#sort-alias}

    Type: sort order
    Default: alias

Specifies how the entries in the “alias” menu are sorted. The following
are legal values:

-   address (sort alphabetically by email address)

-   alias (sort alphabetically by alias name)

-   unsorted (leave in order specified in .muttrc)

### sort\_aux {#sort-aux}

    Type: sort order
    Default: date

When sorting by threads, this variable controls how threads are sorted
in relation to other threads, and how the branches of the thread trees
are sorted. This can be set to any value that [\$sort](#sort) can,
except “threads” (in that case, mutt will just use “date-sent”). You can
also specify the “last-” prefix in addition to the “reverse-” prefix,
but “last-” must come after “reverse-”. The “last-” prefix causes
messages to be sorted against its siblings by which has the last
descendant, using the rest of [\$sort\_aux](#sort-aux) as an ordering.
For instance,

    set sort_aux=last-date-received

would mean that if a new message is received in a thread, that thread
becomes the last one displayed (or the first, if you have
“`set sort=reverse-threads`”.)

Note: For reversed [\$sort](#sort) order [\$sort\_aux](#sort-aux) is
reversed again (which is not the right thing to do, but kept to not
break any existing configuration setting).

### sort\_browser {#sort-browser}

    Type: sort order
    Default: alpha

Specifies how to sort entries in the file browser. By default, the
entries are sorted alphabetically. Valid values:

-   alpha (alphabetically)

-   count (all message count)

-   date

-   desc (description)

-   new (new message count)

-   size

-   unsorted

You may optionally use the “reverse-” prefix to specify reverse sorting
order (example: “`set sort_browser=reverse-date`”).

### sort\_re {#sort-re}

    Type: boolean
    Default: yes

This variable is only useful when sorting by mailboxes in sidebar. By
default, entries are unsorted. Valid values:

-   count (all message count)

-   desc (virtual mailbox description)

-   new (new message count)

-   path

-   unsorted

### spam\_separator {#spam-separator}

    Type: string
    Default: ,

This variable controls what happens when multiple spam headers are
matched: if *unset*, each successive header will overwrite any previous
matches value for the spam label. If *set*, each successive match will
append to the previous, using this variable's value as a separator.

### spoolfile

    Type: path
    Default: (empty)

If your spool mailbox is in a non-default place where Mutt cannot find
it, you can specify its location with this variable. Mutt will initially
set this variable to the value of the environment variable `$MAIL` or
`$MAILDIR` if either is defined.

### ssl\_ca\_certificates\_file {#ssl-ca-certificates-file}

    Type: path
    Default: (empty)

This variable specifies a file containing trusted CA certificates. Any
server certificate that is signed with one of these CA certificates is
also automatically accepted.

Example:

    set ssl_ca_certificates_file=/etc/ssl/certs/ca-certificates.crt

### ssl\_client\_cert {#ssl-client-cert}

    Type: path
    Default: (empty)

The file containing a client certificate and its associated private key.

### ssl\_force\_tls {#ssl-force-tls}

    Type: boolean
    Default: no

If this variable is *set*, Mutt will require that all connections to
remote servers be encrypted. Furthermore it will attempt to negotiate
TLS even if the server does not advertise the capability, since it would
otherwise have to abort the connection anyway. This option supersedes
[\$ssl\_starttls](#ssl-starttls).

### ssl\_min\_dh\_prime\_bits {#ssl-min-dh-prime-bits}

    Type: number
    Default: 0

This variable specifies the minimum acceptable prime size (in bits) for
use in any Diffie-Hellman key exchange. A value of 0 will use the
default from the GNUTLS library.

### ssl\_starttls {#ssl-starttls}

    Type: quadoption
    Default: yes

If *set* (the default), mutt will attempt to use `STARTTLS` on servers
advertising the capability. When *unset*, mutt will not attempt to use
`STARTTLS` regardless of the server's capabilities.

### ssl\_use\_sslv2 {#ssl-use-sslv2}

    Type: boolean
    Default: no

This variable specifies whether to attempt to use SSLv2 in the SSL
authentication process. Note that SSLv2 and SSLv3 are now considered
fundamentally insecure and are no longer recommended.

### ssl\_use\_sslv3 {#ssl-use-sslv3}

    Type: boolean
    Default: no

This variable specifies whether to attempt to use SSLv3 in the SSL
authentication process. Note that SSLv2 and SSLv3 are now considered
fundamentally insecure and are no longer recommended.

### ssl\_use\_tlsv1 {#ssl-use-tlsv1}

    Type: boolean
    Default: yes

This variable specifies whether to attempt to use TLSv1.0 in the SSL
authentication process.

### ssl\_use\_tlsv1\_1 {#ssl-use-tlsv1-1}

    Type: boolean
    Default: yes

This variable specifies whether to attempt to use TLSv1.1 in the SSL
authentication process.

### ssl\_use\_tlsv1\_2 {#ssl-use-tlsv1-2}

    Type: boolean
    Default: yes

This variable specifies whether to attempt to use TLSv1.2 in the SSL
authentication process.

### ssl\_usesystemcerts {#ssl-usesystemcerts}

    Type: boolean
    Default: yes

If set to *yes*, mutt will use CA certificates in the system-wide
certificate store when checking if a server certificate is signed by a
trusted CA.

### ssl\_verify\_dates {#ssl-verify-dates}

    Type: boolean
    Default: yes

If *set* (the default), mutt will not automatically accept a server
certificate that is either not yet valid or already expired. You should
only unset this for particular known hosts, using the `<account-hook>`
function.

### ssl\_verify\_host {#ssl-verify-host}

    Type: boolean
    Default: yes

If *set* (the default), mutt will not automatically accept a server
certificate whose host name does not match the host used in your folder
URL. You should only unset this for particular known hosts, using the
`<account-hook>` function.

### ssl\_verify\_partial\_chains {#ssl-verify-partial-chains}

    Type: boolean
    Default: no

This option should not be changed from the default unless you understand
what you are doing.

Setting this variable to *yes* will permit verifying partial
certification chains, i. e. a certificate chain where not the root, but
an intermediate certificate CA, or the host certificate, are marked
trusted (in [\$certificate\_file](#certificate-file)), without marking
the root signing CA as trusted.

(OpenSSL 1.0.2b and newer only).

### ssl\_ciphers {#ssl-ciphers}

    Type: string
    Default: (empty)

Contains a colon-seperated list of ciphers to use when using SSL. For
OpenSSL, see ciphers(1) for the syntax of the string.

For GnuTLS, this option will be used in place of "NORMAL" at the start
of the priority string. See gnutls\_priority\_init(3) for the syntax and
more details. (Note: GnuTLS version 2.1.7 or higher is required.)

### status\_chars {#status-chars}

    Type: string
    Default: -*%A

Controls the characters used by the “%r” indicator in
[\$status\_format](#status-format).

  --------------- ------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  **Character**   **Default**   **Description**
  1               -             Mailbox is unchanged
  2               \*            Mailbox has been changed and needs to be resynchronized
  3               %             Mailbox is read-only, or will not be written when exiting. (You can toggle whether to write changes to a mailbox with the `<toggle-write>` operation, bound by default to “%”)
  4               A             Folder opened in attach-message mode. (Certain operations like composing a new mail, replying, forwarding, etc. are not permitted in this mode)
  --------------- ------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### status\_format {#status-format}

    Type: string
    Default: -%r-NeoMutt: %f [Msgs:%?M?%M/?%m%?n? New:%n?%?o? Old:%o?%?d? Del:%d?%?F? Flag:%F?%?t? Tag:%t?%?p? Post:%p?%?b? Inc:%b?%?l? %l?]---(%s/%S)-%>-(%P)---

Controls the format of the status line displayed in the “index” menu.
This string is similar to [\$index\_format](#index-format), but has its
own set of `printf(3)`-like sequences:

  -------- --------------------------------------------------------------------------------------------------------
  %b       number of mailboxes with new mail \*
  %d       number of deleted messages \*
  %f       the full pathname of the current mailbox
  %F       number of flagged messages \*
  %h       local hostname
  %l       size (in bytes) of the current mailbox \*
  %L       size (in bytes) of the messages shown (i.e., which match the current limit) \*
  %m       the number of messages in the mailbox \*
  %M       the number of messages shown (i.e., which match the current limit) \*
  %n       number of new messages in the mailbox \*
  %o       number of old unread messages \*
  %p       number of postponed messages \*
  %P       percentage of the way through the index
  %r       modified/read-only/won't-write/attach-message indicator, according to [\$status\_chars](#status-chars)
  %s       current sorting mode ([\$sort](#sort))
  %S       current aux sorting method ([\$sort\_aux](#sort-aux))
  %t       number of tagged messages \*
  %u       number of unread messages \*
  %v       Mutt version string
  %V       currently active limit pattern, if any \*
  %&gt;X   right justify the rest of the string and pad with “X”
  %|X      pad to the end of the line with “X”
  %\*X     soft-fill with character “X” as pad
  -------- --------------------------------------------------------------------------------------------------------

For an explanation of “soft-fill”, see the
[\$index\_format](#index-format) documentation.

\* = can be optionally printed if nonzero

Some of the above sequences can be used to optionally print a string if
their value is nonzero. For example, you may only want to see the number
of flagged messages if such messages exist, since zero is not
particularly meaningful. To optionally print a string based upon one of
the above sequences, the following construct is used:

`%?<sequence_char>?<optional_string>?`

where *sequence\_char* is a character from the table above, and
*optional\_string* is the string you would like printed if
*sequence\_char* is nonzero. *optional\_string* **may** contain other
sequences as well as normal text, but you may **not** nest optional
strings.

Here is an example illustrating how to optionally print the number of
new messages in a mailbox:

`%?n?%n new messages.?`

You can also switch between two strings using the following construct:

`%?<sequence_char>?<if_string>&<else_string>?`

If the value of *sequence\_char* is non-zero, *if\_string* will be
expanded, otherwise *else\_string* will be expanded.

You can force the result of any `printf(3)`-like sequence to be
lowercase by prefixing the sequence character with an underscore (“\_”)
sign. For example, if you want to display the local hostname in
lowercase, you would use: “`%_h`”.

If you prefix the sequence character with a colon (“:”) character, mutt
will replace any dots in the expansion by underscores. This might be
helpful with IMAP folders that don't like dots in folder names.

### status\_on\_top {#status-on-top}

    Type: boolean
    Default: no

Setting this variable causes the “status bar” to be displayed on the
first line of the screen rather than near the bottom. If [\$help](#help)
is *set*, too it'll be placed at the bottom.

### strict\_threads {#strict-threads}

    Type: boolean
    Default: no

If *set*, threading will only make use of the “In-Reply-To” and
“References:” fields when you [\$sort](#sort) by message threads. By
default, messages with the same subject are grouped together in “pseudo
threads.”. This may not always be desirable, such as in a personal
mailbox where you might have several unrelated messages with the
subjects like “hi” which will get grouped together. See also
[\$sort\_re](#sort-re) for a less drastic way of controlling this
behavior.

### suspend

    Type: boolean
    Default: yes

When *unset*, mutt won't stop when the user presses the terminal's
*susp* key, usually “\^Z”. This is useful if you run mutt inside an
xterm using a command like “`xterm -e mutt`”.

### text\_flowed {#text-flowed}

    Type: boolean
    Default: no

When *set*, mutt will generate “format=flowed” bodies with a content
type of “`text/plain; format=flowed`”. This format is easier to handle
for some mailing software, and generally just looks like ordinary text.
To actually make use of this format's features, you'll need support in
your editor.

Note that [\$indent\_string](#indent-string) is ignored when this option
is *set*.

### thorough\_search {#thorough-search}

    Type: boolean
    Default: yes

Affects the `~b` and `~h` search operations described in section
“[patterns](#patterns)”. If *set*, the headers and body/attachments of
messages to be searched are decoded before searching. If *unset*,
messages are searched as they appear in the folder.

Users searching attachments or for non-ASCII characters should *set*
this value because decoding also includes MIME parsing/decoding and
possible character set conversions. Otherwise mutt will attempt to match
against the raw message received (for example quoted-printable encoded
or with encoded headers) which may lead to incorrect search results.

### thread\_received {#thread-received}

    Type: boolean
    Default: no

When *set*, mutt uses the date received rather than the date sent to
thread messages by subject.

### tilde

    Type: boolean
    Default: no

When *set*, the internal-pager will pad blank lines to the bottom of the
screen with a tilde (“\~”).

### time\_inc {#time-inc}

    Type: number
    Default: 0

Along with [\$read\_inc](#read-inc), [\$write\_inc](#write-inc), and
[\$net\_inc](#net-inc), this variable controls the frequency with which
progress updates are displayed. It suppresses updates less than
[\$time\_inc](#time-inc) milliseconds apart. This can improve throughput
on systems with slow terminals, or when running mutt on a remote system.

Also see the “[tuning](#tuning)” section of the manual for performance
considerations.

### timeout

    Type: number
    Default: 600

When Mutt is waiting for user input either idling in menus or in an
interactive prompt, Mutt would block until input is present. Depending
on the context, this would prevent certain operations from working, like
checking for new mail or keeping an IMAP connection alive.

This variable controls how many seconds Mutt will at most wait until it
aborts waiting for input, performs these operations and continues to
wait for input.

A value of zero or less will cause Mutt to never time out.

### tmpdir

    Type: path
    Default: (empty)

This variable allows you to specify where Mutt will place its temporary
files needed for displaying and composing messages. If this variable is
not set, the environment variable `$TMPDIR` is used. If `$TMPDIR` is not
set then “`/tmp`” is used.

### to\_chars {#to-chars}

    Type: string
    Default:  +TCFL

Controls the character used to indicate mail addressed to you.

  --------------- --------------- ----------------------------------------------------------------------------------------------------
  **Character**   **Default**     **Description**
  1               &lt;space&gt;   The mail is *not* addressed to your address.
  2               +               You are the only recipient of the message.
  3               T               Your address appears in the “To:” header field, but you are not the only recipient of the message.
  4               C               Your address is specified in the “Cc:” header field, but you are not the only recipient.
  5               F               Indicates the mail that was sent by *you*.
  6               L               Indicates the mail was sent to a mailing-list you subscribe to.
  --------------- --------------- ----------------------------------------------------------------------------------------------------

### flag\_chars {#flag-chars}

    Type: string
    Default: *!DdrONon- 

Controls the characters used in several flags.

  --------------- --------------- -----------------------------------------------
  **Character**   **Default**     **Description**
  1               \*              The mail is tagged.
  2               !               The mail is flagged as important.
  3               D               The mail is marked for deletion.
  4               d               The mail has attachments marked for deletion.
  5               r               The mail has been replied to.
  6               O               The mail is Old (Unread but seen).
  7               N               The mail is New (Unread but not seen).
  8               o               The mail thread is Old (Unread but seen).
  9               n               The mail thread is New (Unread but not seen).
  10              -               The mail is read - %S expando.
  11              &lt;space&gt;   The mail is read - %Z expando.
  --------------- --------------- -----------------------------------------------

### trash

    Type: path
    Default: (empty)

If set, this variable specifies the path of the trash folder where the
mails marked for deletion will be moved, instead of being irremediably
purged.

NOTE: When you delete a message in the trash folder, it is really
deleted, so that you have a way to clean the trash.

### ts\_icon\_format {#ts-icon-format}

    Type: string
    Default: M%?n?AIL&ail?

Controls the format of the icon title, as long as
“[\$ts\_enabled](#ts-enabled)” is set. This string is identical in
formatting to the one used by “[\$status\_format](#status-format)”.

### ts\_enabled {#ts-enabled}

    Type: boolean
    Default: no

Controls whether mutt tries to set the terminal status line and icon
name. Most terminal emulators emulate the status line in the window
title.

### ts\_status\_format {#ts-status-format}

    Type: string
    Default: NeoMutt with %?m?%m messages&no messages?%?n? [%n NEW]?

Controls the format of the terminal status line (or window title),
provided that “[\$ts\_enabled](#ts-enabled)” has been set. This string
is identical in formatting to the one used by
“[\$status\_format](#status-format)”.

### tunnel

    Type: string
    Default: (empty)

Setting this variable will cause mutt to open a pipe to a command
instead of a raw socket. You may be able to use this to set up
preauthenticated connections to your IMAP/POP3/SMTP server. Example:

    set tunnel="ssh -q mailhost.net /usr/local/libexec/imapd"

Note: For this example to work you must be able to log in to the remote
machine without having to enter a password.

When set, Mutt uses the tunnel for all remote connections. Please see
“[account-hook](#account-hook)” in the manual for how to use different
tunnel commands per connection.

### uncollapse\_jump {#uncollapse-jump}

    Type: boolean
    Default: no

When *set*, Mutt will jump to the next unread message, if any, when the
current thread is *un*collapsed.

### uncollapse\_new {#uncollapse-new}

    Type: boolean
    Default: yes

When *set*, Mutt will automatically uncollapse any collapsed thread that
receives a new message. When *unset*, collapsed threads will remain
collapsed. the presence of the new message will still affect index
sorting, though.

### use\_8bitmime {#use-8bitmime}

    Type: boolean
    Default: no

**Warning:** do not set this variable unless you are using a version of
sendmail which supports the `-B8BITMIME` flag (such as sendmail 8.8.x)
or you may not be able to send mail.

When *set*, Mutt will invoke [\$sendmail](#sendmail) with the
`-B8BITMIME` flag when sending 8-bit messages to enable ESMTP
negotiation.

### use\_domain {#use-domain}

    Type: boolean
    Default: yes

When *set*, Mutt will qualify all local addresses (ones without the
“@host” portion) with the value of [\$hostname](#hostname). If *unset*,
no addresses will be qualified.

### use\_envelope\_from {#use-envelope-from}

    Type: boolean
    Default: no

When *set*, mutt will set the *envelope* sender of the message. If
[\$envelope\_from\_address](#envelope-from-address) is *set*, it will be
used as the sender address. If *unset*, mutt will attempt to derive the
sender from the “From:” header.

Note that this information is passed to sendmail command using the `-f`
command line switch. Therefore setting this option is not useful if the
[\$sendmail](#sendmail) variable already contains `-f` or if the
executable pointed to by [\$sendmail](#sendmail) doesn't support the
`-f` switch.

### use\_from {#use-from}

    Type: boolean
    Default: yes

When *set*, Mutt will generate the “From:” header field when sending
messages. If *unset*, no “From:” header field will be generated unless
the user explicitly sets one using the “[my\_hdr](#my-hdr)” command.

### use\_ipv6 {#use-ipv6}

    Type: boolean
    Default: yes

When *set*, Mutt will look for IPv6 addresses of hosts it tries to
contact. If this option is *unset*, Mutt will restrict itself to IPv4
addresses. Normally, the default should work.

### user\_agent {#user-agent}

    Type: boolean
    Default: yes

When *set*, mutt will add a “User-Agent:” header to outgoing messages,
indicating which version of mutt was used for composing them.

### visual

    Type: path
    Default: (empty)

Specifies the visual editor to invoke when the “`~v`” command is given
in the built-in editor.

### wait\_key {#wait-key}

    Type: boolean
    Default: yes

Controls whether Mutt will ask you to press a key after an external
command has been invoked by these functions: `<shell-escape>`,
`<pipe-message>`, `<pipe-entry>`, `<print-message>`, and `<print-entry>`
commands.

It is also used when viewing attachments with
“[auto\_view](#auto-view)”, provided that the corresponding mailcap
entry has a *needsterminal* flag, and the external program is
interactive.

When *set*, Mutt will always ask for a key. When *unset*, Mutt will wait
for a key only if the external command returned a non-zero status.

### weed

    Type: boolean
    Default: yes

When *set*, mutt will weed headers when displaying, forwarding,
printing, or replying to messages.

### wrap

    Type: number
    Default: 0

When set to a positive value, mutt will wrap text at [\$wrap](#wrap)
characters. When set to a negative value, mutt will wrap text so that
there are [\$wrap](#wrap) characters of empty space on the right side of
the terminal. Setting it to zero makes mutt wrap at the terminal width.

Also see [\$reflow\_wrap](#reflow-wrap).

### wrap\_headers {#wrap-headers}

    Type: number
    Default: 78

This option specifies the number of characters to use for wrapping an
outgoing message's headers. Allowed values are between 78 and 998
inclusive.

**Note:** This option usually shouldn't be changed. RFC5233 recommends a
line length of 78 (the default), so **please only change this setting
when you know what you're doing**.

### wrap\_search {#wrap-search}

    Type: boolean
    Default: yes

Controls whether searches wrap around the end.

When *set*, searches will wrap around the first (or last) item. When
*unset*, incremental searches will not wrap.

### wrapmargin

    Type: number
    Default: 0

(DEPRECATED) Equivalent to setting [\$wrap](#wrap) with a negative
value.

### write\_bcc {#write-bcc}

    Type: boolean
    Default: yes

Controls whether mutt writes out the “Bcc:” header when preparing
messages to be sent. Exim users may wish to unset this. If mutt is set
to deliver directly via SMTP (see [\$smtp\_url](#smtp-url)), this option
does nothing: mutt will never write out the “Bcc:” header in this case.

### write\_inc {#write-inc}

    Type: number
    Default: 10

When writing a mailbox, a message will be printed every
[\$write\_inc](#write-inc) messages to indicate progress. If set to 0,
only a single message will be displayed before writing a mailbox.

Also see the [\$read\_inc](#read-inc), [\$net\_inc](#net-inc) and
[\$time\_inc](#time-inc) variables and the “[tuning](#tuning)” section
of the manual for performance considerations.

### xlabel\_delimiter {#xlabel-delimiter}

    Type: string
    Default: (empty)

The character used to delimit distinct keywords in X-Label headers.
X-Label is primarily a Mutt artifact, and the semantics of the field
were never defined: it is free-form text. However interaction with
X-Keywords:, X-Mozilla-Keys:, and Keywords: requires that we adopt some
means of identifying separate keywords within the field. Set this to
your personal convention.

This affect both parsing existing X-Label headers and writing new
X-Label headers. You can modify this variable in runtime to accomplish
various kinds of conversion.

### x\_comment\_to {#x-comment-to}

    Type: boolean
    Default: no

If *set*, Mutt will add “X-Comment-To:” field (that contains full name
of original article author) to article that followuped to newsgroup.

### collapse\_all {#collapse-all}

    Type: boolean
    Default: no

When *set*, Mutt will collapse all threads when entering a folder.

Functions {#functions}
---------

The following is the list of available functions listed by the mapping
in which they are available. The default key setting is given, and an
explanation of what the function does. The key bindings of these
functions can be changed with the [bind](#bind) command.

### Generic Menu {#generic-map}

The *generic* menu is not a real menu, but specifies common functions
(such as movement) available in all menus except for *pager* and
*editor*. Changing settings for this menu will affect the default
bindings for all menus (except as noted).

  Function              Default key      Description
  --------------------- ---------------- ---------------------------------------------
  `<top-page>`          H                move to the top of the page
  `<next-entry>`        j                move to the next entry
  `<previous-entry>`    k                move to the previous entry
  `<bottom-page>`       L                move to the bottom of the page
  `<refresh>`           \^L              clear and redraw the screen
  `<middle-page>`       M                move to the middle of the page
  `<search-next>`       n                search for next match
  `<exit>`              q                exit this menu
  `<tag-entry>`         t                tag the current entry
  `<next-page>`         z                move to the next page
  `<previous-page>`     Z                move to the previous page
  `<last-entry>`        \*               move to the last entry
  `<first-entry>`       =                move to the first entry
  `<enter-command>`     :                enter a muttrc command
  `<next-line>`         &gt;             scroll down one line
  `<previous-line>`     &lt;             scroll up one line
  `<half-up>`           \[               scroll up 1/2 page
  `<half-down>`         \]               scroll down 1/2 page
  `<help>`              ?                this screen
  `<tag-prefix>`        ;                apply next function to tagged messages
  `<tag-prefix-cond>`                    apply next function ONLY to tagged messages
  `<end-cond>`                           end of conditional execution (noop)
  `<shell-escape>`      !                invoke a command in a subshell
  `<select-entry>`      &lt;Enter&gt;    select the current entry
  `<select-entry>`      &lt;Return&gt;   select the current entry
  `<search>`            /                search for a regular expression
  `<search-reverse>`    Esc /            search backwards for a regular expression
  `<search-opposite>`                    search for next match in opposite direction
  `<jump>`                               jump to an index number
  `<current-top>`                        move entry to top of screen
  `<current-middle>`                     move entry to middle of screen
  `<current-bottom>`                     move entry to bottom of screen
  `<what-key>`                           display the keycode for a key press

  : Default Generic Menu Bindings

### Index Menu {#index-map}

  Function                        Default key       Description
  ------------------------------- ----------------- --------------------------------------------------------------
  `<create-alias>`                a                 create an alias from a message sender
  `<bounce-message>`              b                 remail a message to another user
  `<break-thread>`                \#                break the thread in two
  `<change-folder>`               c                 open a different folder
  `<change-folder-readonly>`      Esc c             open a different folder in read only mode
  `<change-newsgroup>`                              open a different newsgroup
  `<change-newsgroup-readonly>`                     open a different newsgroup in read only mode
  `<next-unread-mailbox>`                           open next mailbox with new mail
  `<collapse-thread>`             Esc v             collapse/uncollapse current thread
  `<collapse-all>`                Esc V             collapse/uncollapse all threads
  `<copy-message>`                C                 copy a message to a file/mailbox
  `<decode-copy>`                 Esc C             make decoded (text/plain) copy
  `<decode-save>`                 Esc s             make decoded copy (text/plain) and delete
  `<delete-message>`              d                 delete the current entry
  `<delete-pattern>`              D                 delete messages matching a pattern
  `<delete-thread>`               \^D               delete all messages in thread
  `<delete-subthread>`            Esc d             delete all messages in subthread
  `<edit>`                        e                 edit the raw message
  `<edit-label>`                  Y                 add, change, or delete a message's label
  `<edit-type>`                   \^E               edit attachment content type
  `<forward-message>`             f                 forward a message with comments
  `<forward-to-group>`                              forward to newsgroup
  `<followup-message>`                              followup to newsgroup
  `<get-children>`                                  get all children of the current message
  `<get-message>`                                   get message with Message-Id
  `<get-parent>`                                    get parent of the current message
  `<reconstruct-thread>`                            reconstruct thread containing current message
  `<flag-message>`                F                 toggle a message's 'important' flag
  `<group-reply>`                 g                 reply to all recipients
  `<fetch-mail>`                  G                 retrieve mail from POP server
  `<imap-fetch-mail>`                               force retrieval of mail from IMAP server
  `<imap-logout-all>`                               logout from all IMAP servers
  `<display-toggle-weed>`         h                 display message and toggle header weeding
  `<next-undeleted>`              j                 move to the next undeleted message
  `<previous-undeleted>`          k                 move to the previous undeleted message
  `<limit>`                       l                 show only messages matching a pattern
  `<limit-current-thread>`                          limit view to current thread
  `<link-threads>`                &                 link tagged message to the current one
  `<list-reply>`                  L                 reply to specified mailing list
  `<mail>`                        m                 compose a new mail message
  `<toggle-new>`                  N                 toggle a message's 'new' flag
  `<toggle-write>`                %                 toggle whether the mailbox will be rewritten
  `<next-thread>`                 \^N               jump to the next thread
  `<next-subthread>`              Esc n             jump to the next subthread
  `<purge-message>`                                 really delete the current entry, bypassing the trash folder
  `<purge-thread>`                                  really delete the current thread, bypassing the trash folder
  `<query>`                       Q                 query external program for addresses
  `<quit>`                        q                 save changes to mailbox and quit
  `<reply>`                       r                 reply to a message
  `<show-limit>`                  Esc l             show currently active limit pattern
  `<sort-mailbox>`                o                 sort messages
  `<sort-reverse>`                O                 sort messages in reverse order
  `<print-message>`               p                 print the current entry
  `<post-message>`                                  post message to newsgroup
  `<previous-thread>`             \^P               jump to previous thread
  `<previous-subthread>`          Esc p             jump to previous subthread
  `<recall-message>`              R                 recall a postponed message
  `<read-thread>`                 \^R               mark the current thread as read
  `<read-subthread>`              Esc r             mark the current subthread as read
  `<resend-message>`              Esc e             use the current message as a template for a new one
  `<compose-to-sender>`                             compose a new message to the sender
  `<save-message>`                s                 save message/attachment to a mailbox/file
  `<tag-pattern>`                 T                 tag messages matching a pattern
  `<tag-subthread>`                                 tag the current subthread
  `<tag-thread>`                  Esc t             tag the current thread
  `<untag-pattern>`               \^T               untag messages matching a pattern
  `<undelete-message>`            u                 undelete the current entry
  `<undelete-pattern>`            U                 undelete messages matching a pattern
  `<undelete-subthread>`          Esc u             undelete all messages in subthread
  `<undelete-thread>`             \^U               undelete all messages in thread
  `<view-attachments>`            v                 show MIME attachments
  `<show-version>`                V                 show the Mutt version number and date
  `<set-flag>`                    w                 set a status flag on a message
  `<clear-flag>`                  W                 clear a status flag from a message
  `<toggle-read>`                                   toggle view of read messages
  `<catchup>`                                       mark all articles in newsgroup as read
  `<display-message>`             &lt;Enter&gt;     display a message
  `<display-message>`             &lt;Return&gt;    display a message
  `<mark-message>`                \~                create a hotkey macro for the current message
  `<buffy-list>`                  .                 list mailboxes with new mail
  `<sync-mailbox>`                \$                save changes to mailbox
  `<display-address>`             @                 display full address of sender
  `<pipe-message>`                |                 pipe message/attachment to a shell command
  `<next-new>`                                      jump to the next new message
  `<next-new-then-unread>`        &lt;Tab&gt;       jump to the next new or unread message
  `<previous-new>`                                  jump to the previous new message
  `<previous-new-then-unread>`    Esc &lt;Tab&gt;   jump to the previous new or unread message
  `<next-unread>`                                   jump to the next unread message
  `<previous-unread>`                               jump to the previous unread message
  `<parent-message>`              P                 jump to parent message in thread
  `<root-message>`                                  jump to root message in thread
  `<extract-keys>`                \^K               extract supported public keys
  `<forget-passphrase>`           \^F               wipe passphrase(s) from memory
  `<check-traditional-pgp>`       Esc P             check for classic PGP
  `<mail-key>`                    Esc k             mail a PGP public key
  `<decrypt-copy>`                                  make decrypted copy
  `<decrypt-save>`                                  make decrypted copy and delete
  `<quasi-delete>`                                  delete from mutt, don't touch on disk
  `<sidebar-next>`                                  move the highlight to next mailbox
  `<sidebar-next-new>`                              move the highlight to next mailbox with new mail
  `<sidebar-open>`                                  open highlighted mailbox
  `<sidebar-page-down>`                             scroll the sidebar down 1 page
  `<sidebar-page-up>`                               scroll the sidebar up 1 page
  `<sidebar-prev>`                                  move the highlight to previous mailbox
  `<sidebar-prev-new>`                              move the highlight to previous mailbox with new mail
  `<sidebar-toggle-virtual>`                        toggle between mailboxes and virtual mailboxes
  `<sidebar-toggle-visible>`                        make the sidebar (in)visible

  : Default Index Menu Bindings

### Pager Menu {#pager-map}

  Function                        Default key      Description
  ------------------------------- ---------------- --------------------------------------------------------------
  `<break-thread>`                \#               break the thread in two
  `<create-alias>`                a                create an alias from a message sender
  `<bounce-message>`              b                remail a message to another user
  `<change-folder>`               c                open a different folder
  `<change-folder-readonly>`      Esc c            open a different folder in read only mode
  `<change-newsgroup>`                             open a different newsgroup
  `<change-newsgroup-readonly>`                    open a different newsgroup in read only mode
  `<next-unread-mailbox>`                          open next mailbox with new mail
  `<copy-message>`                C                copy a message to a file/mailbox
  `<decode-copy>`                 Esc C            make decoded (text/plain) copy
  `<delete-message>`              d                delete the current entry
  `<delete-thread>`               \^D              delete all messages in thread
  `<delete-subthread>`            Esc d            delete all messages in subthread
  `<set-flag>`                    w                set a status flag on a message
  `<clear-flag>`                  W                clear a status flag from a message
  `<edit>`                        e                edit the raw message
  `<edit-label>`                  Y                add, change, or delete a message's label
  `<edit-type>`                   \^E              edit attachment content type
  `<followup-message>`                             followup to newsgroup
  `<forward-to-group>`                             forward to newsgroup
  `<forward-message>`             f                forward a message with comments
  `<flag-message>`                F                toggle a message's 'important' flag
  `<group-reply>`                 g                reply to all recipients
  `<imap-fetch-mail>`                              force retrieval of mail from IMAP server
  `<imap-logout-all>`                              logout from all IMAP servers
  `<display-toggle-weed>`         h                display message and toggle header weeding
  `<next-undeleted>`              j                move to the next undeleted message
  `<next-entry>`                  J                move to the next entry
  `<previous-undeleted>`          k                move to the previous undeleted message
  `<previous-entry>`              K                move to the previous entry
  `<link-threads>`                &                link tagged message to the current one
  `<list-reply>`                  L                reply to specified mailing list
  `<redraw-screen>`               \^L              clear and redraw the screen
  `<mail>`                        m                compose a new mail message
  `<mark-as-new>`                 N                toggle a message's 'new' flag
  `<search-next>`                 n                search for next match
  `<next-thread>`                 \^N              jump to the next thread
  `<next-subthread>`              Esc n            jump to the next subthread
  `<sort-mailbox>`                o                sort messages
  `<sort-reverse>`                O                sort messages in reverse order
  `<print-message>`               p                print the current entry
  `<post-message>`                                 post message to newsgroup
  `<previous-thread>`             \^P              jump to previous thread
  `<previous-subthread>`          Esc p            jump to previous subthread
  `<purge-message>`                                really delete the current entry, bypassing the trash folder
  `<purge-thread>`                                 really delete the current thread, bypassing the trash folder
  `<quit>`                        Q                save changes to mailbox and quit
  `<exit>`                        q                exit this menu
  `<reply>`                       r                reply to a message
  `<recall-message>`              R                recall a postponed message
  `<reconstruct-thread>`                           reconstruct thread containing current message
  `<read-thread>`                 \^R              mark the current thread as read
  `<read-subthread>`              Esc r            mark the current subthread as read
  `<resend-message>`              Esc e            use the current message as a template for a new one
  `<compose-to-sender>`                            compose a new message to the sender
  `<save-message>`                s                save message/attachment to a mailbox/file
  `<skip-quoted>`                 S                skip beyond quoted text
  `<decode-save>`                 Esc s            make decoded copy (text/plain) and delete
  `<tag-message>`                 t                tag the current entry
  `<toggle-quoted>`               T                toggle display of quoted text
  `<undelete-message>`            u                undelete the current entry
  `<undelete-subthread>`          Esc u            undelete all messages in subthread
  `<undelete-thread>`             \^U              undelete all messages in thread
  `<view-attachments>`            v                show MIME attachments
  `<show-version>`                V                show the Mutt version number and date
  `<search-toggle>`               \\\\             toggle search pattern coloring
  `<display-address>`             @                display full address of sender
  `<next-new>`                                     jump to the next new message
  `<next-new-then-unread>`        &lt;Tab&gt;      jump to the next new or unread message
  `<pipe-message>`                |                pipe message/attachment to a shell command
  `<help>`                        ?                this screen
  `<next-page>`                   &lt;Space&gt;    move to the next page
  `<previous-page>`               -                move to the previous page
  `<top>`                         \^               jump to the top of the message
  `<sync-mailbox>`                \$               save changes to mailbox
  `<shell-escape>`                !                invoke a command in a subshell
  `<enter-command>`               :                enter a muttrc command
  `<buffy-list>`                  .                list mailboxes with new mail
  `<search>`                      /                search for a regular expression
  `<search-reverse>`              Esc /            search backwards for a regular expression
  `<search-opposite>`                              search for next match in opposite direction
  `<next-line>`                   &lt;Enter&gt;    scroll down one line
  `<next-line>`                   &lt;Return&gt;   scroll down one line
  `<jump>`                                         jump to an index number
  `<next-unread>`                                  jump to the next unread message
  `<previous-new>`                                 jump to the previous new message
  `<previous-new-then-unread>`                     jump to the previous new or unread message
  `<previous-unread>`                              jump to the previous unread message
  `<half-up>`                                      scroll up 1/2 page
  `<half-down>`                                    scroll down 1/2 page
  `<previous-line>`                                scroll up one line
  `<bottom>`                                       jump to the bottom of the message
  `<parent-message>`              P                jump to parent message in thread
  `<root-message>`                                 jump to root message in thread
  `<check-traditional-pgp>`       Esc P            check for classic PGP
  `<mail-key>`                    Esc k            mail a PGP public key
  `<extract-keys>`                \^K              extract supported public keys
  `<forget-passphrase>`           \^F              wipe passphrase(s) from memory
  `<decrypt-copy>`                                 make decrypted copy
  `<decrypt-save>`                                 make decrypted copy and delete
  `<what-key>`                                     display the keycode for a key press
  `<quasi-delete>`                                 delete from mutt, don't touch on disk
  `<sidebar-next>`                                 move the highlight to next mailbox
  `<sidebar-next-new>`                             move the highlight to next mailbox with new mail
  `<sidebar-open>`                                 open highlighted mailbox
  `<sidebar-page-down>`                            scroll the sidebar down 1 page
  `<sidebar-page-up>`                              scroll the sidebar up 1 page
  `<sidebar-prev>`                                 move the highlight to previous mailbox
  `<sidebar-prev-new>`                             move the highlight to previous mailbox with new mail
  `<sidebar-toggle-virtual>`                       toggle between mailboxes and virtual mailboxes
  `<sidebar-toggle-visible>`                       make the sidebar (in)visible

  : Default Pager Menu Bindings

### Alias Menu {#alias-map}

  Function             Default key   Description
  -------------------- ------------- ----------------------------
  `<delete-entry>`     d             delete the current entry
  `<undelete-entry>`   u             undelete the current entry

  : Default Alias Menu Bindings

### Query Menu {#query-map}

  Function           Default key   Description
  ------------------ ------------- ---------------------------------------------
  `<create-alias>`   a             create an alias from a message sender
  `<mail>`           m             compose a new mail message
  `<query>`          Q             query external program for addresses
  `<query-append>`   A             append new query results to current results

  : Default Query Menu Bindings

### Attachment Menu {#attachment-map}

  Function                    Default key      Description
  --------------------------- ---------------- -----------------------------------------------------
  `<bounce-message>`          b                remail a message to another user
  `<display-toggle-weed>`     h                display message and toggle header weeding
  `<edit-type>`               \^E              edit attachment content type
  `<followup-message>`                         followup to newsgroup
  `<forward-to-group>`                         forward to newsgroup
  `<print-entry>`             p                print the current entry
  `<save-entry>`              s                save message/attachment to a mailbox/file
  `<pipe-entry>`              |                pipe message/attachment to a shell command
  `<view-mailcap>`            m                force viewing of attachment using mailcap
  `<reply>`                   r                reply to a message
  `<resend-message>`          Esc e            use the current message as a template for a new one
  `<group-reply>`             g                reply to all recipients
  `<list-reply>`              L                reply to specified mailing list
  `<forward-message>`         f                forward a message with comments
  `<view-text>`               T                view attachment as text
  `<view-attach>`             &lt;Enter&gt;    view attachment using mailcap entry if necessary
  `<view-attach>`             &lt;Return&gt;   view attachment using mailcap entry if necessary
  `<delete-entry>`            d                delete the current entry
  `<undelete-entry>`          u                undelete the current entry
  `<collapse-parts>`          v                Toggle display of subparts
  `<check-traditional-pgp>`   Esc P            check for classic PGP
  `<extract-keys>`            \^K              extract supported public keys
  `<forget-passphrase>`       \^F              wipe passphrase(s) from memory

  : Default Attachment Menu Bindings

### Compose Menu {#compose-map}

  Function                  Default key      Description
  ------------------------- ---------------- -----------------------------------------------------
  `<attach-file>`           a                attach file(s) to this message
  `<attach-message>`        A                attach message(s) to this message
  `<attach-news-message>`                    attach news article(s) to this message
  `<edit-bcc>`              b                edit the BCC list
  `<edit-cc>`               c                edit the CC list
  `<copy-file>`             C                save message/attachment to a mailbox/file
  `<detach-file>`           D                delete the current entry
  `<toggle-disposition>`    \^D              toggle disposition between inline/attachment
  `<edit-description>`      d                edit attachment description
  `<edit-message>`          e                edit the message
  `<edit-headers>`          E                edit the message with headers
  `<edit-file>`             \^X e            edit the file to be attached
  `<edit-encoding>`         \^E              edit attachment transfer-encoding
  `<edit-from>`             Esc f            edit the from field
  `<edit-fcc>`              f                enter a file to save a copy of this message in
  `<filter-entry>`          F                filter attachment through a shell command
  `<get-attachment>`        G                get a temporary copy of an attachment
  `<display-toggle-weed>`   h                display message and toggle header weeding
  `<ispell>`                i                run ispell on the message
  `<print-entry>`           l                print the current entry
  `<edit-mime>`             m                edit attachment using mailcap entry
  `<new-mime>`              n                compose new attachment using mailcap entry
  `<edit-newsgroups>`                        edit the newsgroups list
  `<edit-followup-to>`                       edit the Followup-To field
  `<edit-x-comment-to>`                      edit the X-Comment-To field
  `<postpone-message>`      P                save this message to send later
  `<edit-reply-to>`         r                edit the Reply-To field
  `<rename-attachment>`     \^O              send attachment with a different name
  `<rename-file>`           R                rename/move an attached file
  `<edit-subject>`          s                edit the subject of this message
  `<edit-to>`               t                edit the TO list
  `<edit-type>`             \^T              edit attachment content type
  `<write-fcc>`             w                write the message to a folder
  `<toggle-unlink>`         u                toggle whether to delete file after sending it
  `<toggle-recode>`                          toggle recoding of this attachment
  `<update-encoding>`       U                update an attachment's encoding info
  `<view-attach>`           &lt;Enter&gt;    view attachment using mailcap entry if necessary
  `<view-attach>`           &lt;Return&gt;   view attachment using mailcap entry if necessary
  `<send-message>`          y                send the message
  `<pipe-entry>`            |                pipe message/attachment to a shell command
  `<attach-key>`            Esc k            attach a PGP public key
  `<pgp-menu>`              p                show PGP options
  `<forget-passphrase>`     \^F              wipe passphrase(s) from memory
  `<smime-menu>`            S                show S/MIME options
  `<mix>`                   M                send the message through a mixmaster remailer chain

  : Default Compose Menu Bindings

### Postpone Menu {#postpone-map}

  Function             Default key   Description
  -------------------- ------------- ----------------------------
  `<delete-entry>`     d             delete the current entry
  `<undelete-entry>`   u             undelete the current entry

  : Default Postpone Menu Bindings

### Browser Menu {#browser-map}

  Function                  Default key     Description
  ------------------------- --------------- -------------------------------------------------------------
  `<change-dir>`            c               change directories
  `<display-filename>`      @               display the currently selected file's name
  `<enter-mask>`            m               enter a file mask
  `<sort>`                  o               sort messages
  `<sort-reverse>`          O               sort messages in reverse order
  `<select-new>`            N               select a new file in this directory
  `<check-new>`                             check mailboxes for new mail
  `<toggle-mailboxes>`      &lt;Tab&gt;     toggle whether to browse mailboxes or all files
  `<reload-active>`                         load list of all newsgroups from NNTP server
  `<subscribe-pattern>`                     subscribe to newsgroups matching a pattern
  `<unsubscribe-pattern>`                   unsubscribe from newsgroups matching a pattern
  `<catchup>`                               mark all articles in newsgroup as read
  `<uncatchup>`                             mark all articles in newsgroup as unread
  `<view-file>`             &lt;Space&gt;   view file
  `<buffy-list>`            .               list mailboxes with new mail
  `<create-mailbox>`        C               create a new mailbox (IMAP only)
  `<delete-mailbox>`        d               delete the current mailbox (IMAP only)
  `<rename-mailbox>`        r               rename the current mailbox (IMAP only)
  `<subscribe>`             s               subscribe to current mbox (IMAP/NNTP only)
  `<unsubscribe>`           u               unsubscribe from current mbox (IMAP/NNTP only)
  `<toggle-subscribed>`     T               toggle view all/subscribed mailboxes (IMAP only)
  `<goto-folder>`           =               swap the current folder position with \$folder if it exists

  : Default Browser Menu Bindings

### Pgp Menu {#pgp-map}

  Function         Default key   Description
  ---------------- ------------- -------------------------
  `<verify-key>`   c             verify a PGP public key
  `<view-name>`    %             view the key's user id

  : Default Pgp Menu Bindings

### Smime Menu {#smime-map}

  Function         Default key   Description
  ---------------- ------------- -------------------------
  `<verify-key>`   c             verify a PGP public key
  `<view-name>`    %             view the key's user id

  : Default Smime Menu Bindings

### Mixmaster Menu {#mixmaster-map}

  Function         Default key      Description
  ---------------- ---------------- ------------------------------------------
  `<accept>`       &lt;Enter&gt;    accept the chain constructed
  `<accept>`       &lt;Return&gt;   accept the chain constructed
  `<append>`       a                append a remailer to the chain
  `<insert>`       i                insert a remailer into the chain
  `<delete>`       d                delete a remailer from the chain
  `<chain-prev>`   &lt;Left&gt;     select the previous element of the chain
  `<chain-next>`   &lt;Right&gt;    select the next element of the chain

  : Default Mixmaster Menu Bindings

### Editor Menu {#editor-map}

  Function              Default key         Description
  --------------------- ------------------- -----------------------------------------------------
  `<bol>`               \^A                 jump to the beginning of the line
  `<backward-char>`     \^B                 move the cursor one character to the left
  `<backward-word>`     Esc b               move the cursor to the beginning of the word
  `<capitalize-word>`   Esc c               capitalize the word
  `<downcase-word>`     Esc l               convert the word to lower case
  `<upcase-word>`       Esc u               convert the word to upper case
  `<delete-char>`       \^D                 delete the char under the cursor
  `<eol>`               \^E                 jump to the end of the line
  `<forward-char>`      \^F                 move the cursor one character to the right
  `<forward-word>`      Esc f               move the cursor to the end of the word
  `<backspace>`         &lt;Backspace&gt;   delete the char in front of the cursor
  `<kill-eol>`          \^K                 delete chars from cursor to end of line
  `<kill-eow>`          Esc d               delete chars from the cursor to the end of the word
  `<kill-line>`         \^U                 delete all chars on the line
  `<quote-char>`        \^V                 quote the next typed key
  `<kill-word>`         \^W                 delete the word in front of the cursor
  `<complete>`          &lt;Tab&gt;         complete filename or alias
  `<complete-query>`    \^T                 complete address with query
  `<buffy-cycle>`       &lt;Space&gt;       cycle among incoming mailboxes
  `<history-up>`                            scroll up through the history list
  `<history-down>`                          scroll down through the history list
  `<transpose-chars>`                       transpose character under cursor with previous

  : Default Editor Menu Bindings

Miscellany {#miscellany}
==========

Acknowledgements
----------------

Kari Hurtta <kari.hurtta@fmi.fi> co-developed the original MIME parsing
code back in the ELM-ME days.

The following people have been very helpful to the development of Mutt:

-   Vikas Agnihotri <vikasa@writeme.com>

-   Francois Berjon <Francois.Berjon@aar.alcatel-alsthom.fr>

-   Aric Blumer <aric@fore.com>

-   John Capo <jc@irbs.com>

-   David Champion <dgc@uchicago.edu>

-   Brendan Cully <brendan@kublai.com>

-   Liviu Daia <daia@stoilow.imar.ro>

-   Thomas E. Dickey <dickey@herndon4.his.com>

-   David DeSimone <fox@convex.hp.com>

-   Nickolay N. Dudorov <nnd@wint.itfs.nsk.su>

-   Ruslan Ermilov <ru@freebsd.org>

-   Edmund Grimley Evans <edmundo@rano.org>

-   Michael Finken <finken@conware.de>

-   Sven Guckes <guckes@math.fu-berlin.de>

-   Lars Hecking <lhecking@nmrc.ie>

-   Mark Holloman <holloman@nando.net>

-   Andreas Holzmann <holzmann@fmi.uni-passau.de>

-   Marco d'Itri <md@linux.it>

-   Björn Jacke <bjacke@suse.com>

-   Byrial Jensen <byrial@image.dk>

-   David Jeske <jeske@igcom.net>

-   Christophe Kalt <kalt@hugo.int-evry.fr>

-   Tommi Komulainen <Tommi.Komulainen@iki.fi>

-   Felix von Leitner (a.k.a “Fefe”) <leitner@math.fu-berlin.de>

-   Brandon Long <blong@fiction.net>

-   Jimmy Mäkelä <jmy@flashback.net>

-   Lars Marowsky-Bree <lmb@pointer.in-minden.de>

-   Thomas “Mike” Michlmayr <mike@cosy.sbg.ac.at>

-   Andrew W. Nosenko <awn@bcs.zp.ua>

-   David O'Brien <obrien@Nuxi.cs.ucdavis.edu>

-   Clint Olsen <olsenc@ichips.intel.com>

-   Park Myeong Seok <pms@romance.kaist.ac.kr>

-   Thomas Parmelan <tom@ankh.fr.eu.org>

-   Ollivier Robert <roberto@keltia.freenix.fr>

-   Thomas Roessler <roessler@does-not-exist.org>

-   Roland Rosenfeld <roland@spinnaker.de>

-   Rocco Rutte <pdmef@gmx.net>

-   TAKIZAWA Takashi <taki@luna.email.ne.jp>

-   Allain Thivillon <Allain.Thivillon@alma.fr>

-   Gero Treuner <gero@70t.de>

-   Vsevolod Volkov <vvv@lucky.net>

-   Ken Weinert <kenw@ihs.com>

About This Document {#about}
-------------------

This document was written in [DocBook](http://docbook.sourceforge.net),
and then rendered using the [Gnome XSLT
toolkit](http://xmlsoft.org/XSLT/).
