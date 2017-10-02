# This is the NeoMutt Project

[![License: GPL v2](https://img.shields.io/badge/License-GPL%20v2-blue.svg)](https://github.com/neomutt/neomutt/blob/neomutt/COPYRIGHT)
[![Travis branch](https://api.travis-ci.org/neomutt/neomutt.svg?branch=neomutt)](https://travis-ci.org/neomutt/neomutt)
[![Coverity Scan](https://img.shields.io/coverity/scan/8495.svg)](https://scan.coverity.com/projects/neomutt-neomutt)
[![Backlog](https://badge.waffle.io/neomutt/neomutt.svg?label=status:backlog&title=Backlog)](http://waffle.io/neomutt/neomutt)
[![In Progress](https://badge.waffle.io/neomutt/neomutt.svg?label=status:in-progress&title=In%20Progress)](http://waffle.io/neomutt/neomutt)
[![Ready](https://badge.waffle.io/neomutt/neomutt.svg?label=status:ready&title=Ready)](http://waffle.io/neomutt/neomutt)

## What is NeoMutt?

* NeoMutt is a project of projects.
* A place to gather all the patches against Mutt.
* A place for all the developers to gather.

Hopefully this will build the community and reduce duplicated effort.

NeoMutt was created when Richard Russon (FlatCap) took all the old Mutt patches,
sorted through them, fixed them up and documented them.

## What Features does NeoMutt have?

| Name                 | Description
| -------------------- | ------------------------------------------------------
| Attach Headers Color | Color attachment headers using regex, just like mail bodies
| Compose to Sender    | Send new mail to the sender of the current mail
| Compressed Folders   | Read from/write to compressed mailboxes
| Conditional Dates    | Use rules to choose date format
| Encrypt-to-Self      | Save a self-encrypted copy of emails
| Fmemopen             | Replace some temporary files with memory buffers
| Forgotten Attachment | Alert user when (s)he forgets to attach a file to an outgoing email.
| Global Hooks         | Define actions to run globally within Mutt
| Ifdef                | Conditional config options
| Index Color          | Custom rules for theming the email index
| Initials Expando     | Expando for author's initials
| Keywords             | Labels/Tagging for emails
| Kyoto Cabinet        | Kyoto Cabinet backend for the header cache
| Limit Current Thread | Focus on one Email Thread
| LMDB                 | LMDB backend for the header cache
| Multiple FCC         | Save multiple copies of outgoing mail
| Nested If            | Allow complex nested conditions in format strings
| New Mail             | Execute a command upon the receipt of new mail.
| NNTP                 | Talk to a Usenet news server
| Notmuch              | Email search engine
| Progress Bar         | Show a visual progress bar on slow operations
| Quasi-Delete         | Mark emails that should be hidden, but not deleted
| Reply With X-Orig-To | Direct reply to email using X-Original-To header
| Sensible Browser     | Make the file browser behave
| Sidebar              | Panel containing list of Mailboxes
| Skip Quoted          | Leave some context visible
| Status Color         | Custom rules for theming the status bar
| TLS-SNI              | Negotiate with a server for a TLS/SSL certificate
| Trash Folder         | Automatically move deleted emails to a trash bin

## Contributed Scripts and Config

| Name                   | Description
| ---------------------- | ---------------------------------------------
| Header Cache Benchmark | Script to test the speed of the header cache
| Keybase                | Keybase Integration
| Useful programs        | List of useful programs interacting with mutt
| Vi Keys                | Easy and clean Vi-keys for Mutt
| Vim Syntax             | Vim Syntax File

## Where is NeoMutt?

- Source Code:     https://github.com/neomutt/neomutt
- Releases:        https://github.com/neomutt/neomutt/releases/latest
- Questions/Bugs:  https://github.com/neomutt/neomutt/issues
- Website:         http://www.neomutt.org/
- IRC:             irc://irc.freenode.net/neomutt - please be patient.
  We're a small group, so our answer might take some time.
- Mailinglists:    [neomutt-users](mailto:neomutt-users-request@neomutt.org?subject=subscribe)
  and [neomutt-devel](mailto:neomutt-devel-request@neomutt.org?subject=subscribe)
- Development:     http://www.neomutt.org/dev.html

## NeoMutt Developers

Here's a list of everyone who's helped NeoMutt:

Adam Borowski, Alex Pearce, Alok Singh, Ander Punnar, André Berger,
Antonio Radici, Baptiste Daroussin, Bernard Pratz, Bo Yu, Bryan Bennett,
Chris Czettel, Chris Salzberg, Christian Dröge, Christoph Berg, Cinder88,
Clemens Lang, Damien Riegel, Darshit Shah, David Sterba,
Dimitrios Semitsoglou-Tsiapos, Doug Stone-Weaver, Edward Betts,
Elimar Riesebieter, Evgeni Golov, Fabian Groffen, Fabio Alessandro Locati,
Fabrice Bellet, Faidon Liambotis, Florian Klink, František Hájik,
Guillaume Brogi, Hugo Barrera, Ian Zimmerman, Ismaël Bouya, Ivan Tham,
Jack Stratton, Jasper Adriaanse, Jenya Sovetkin, Johannes Frankenau,
Johannes Weißl, Jonathan Perkin, Joshua Jordi, Julian Andres Klode, Karel Zak,
Kevin Decherf, Kevin Velghe, Kurt Jaeger, Leonidas Spyropoulos,
Manos Pitsidianakis, Marcin Rajner, Marco Hinz, Matteo Vescovi, Mehdi Abaakouk,
ng0, Olaf Lessenich, Peter Hogg, Peter Lewis, Phil Pennock, Philipp Marek,
Pierre-Elliott Bécue, Pietro Cerutti, R3lgar, Regid Ichira, Riad Wahby,
Richard Hartmann, Richard Russon, Rubén Llorente, Santiago Torres,
Serge Gebhardt, Somini, Stefan Assmann, Stefan Bühler, Stephen Gilles,
Steven Ragnarök, Sven Guckes, Thomas Adam, Thomas Klausner, Thomas Schneider,
Tobias Angele, Udo Schweigert, Vsevolod Volkov, Werner Fink, Wieland Hoffmann,
William Pettersson, Yoshiki Vázquez Baeza, Zero King.

## Original Patch Authors

Without the original patch authors, there would be nothing.
So, a Big Thank You to:

Aaron Schrab, Alain Penders, Benjamin Kuperman, Cedric Duval, Chris Mason,
Christian Aichinger, Christoph Berg, Christoph Rissner, David Champion,
David Riebenbauer, David Sterba, David Wilson, Don Zickus, Elimar Riesebieter,
Eric Davis, Evgeni Golov, Fabian Groffen, Felix von Leitner, Jan Synacek,
Jason DeTiberus, Jeremiah Foster, Jeremy Katz, Josh Poimboeuf, Julius Plenz,
Justin Hibbits, Karel Zak, Kirill Shutemov, Luke Macken, Mantas Mikulenas,
Matteo Vescovi, Patrick Brisbin, Paul Miller, Phil Pennock,
Philippe Le Brouster, Richard Russon, Rocco Rutte, Roland Rosenfeld, Sami Farin,
Stefan Assmann, Stefan Kuhn, Steve Kemp, Terry Chan, Thomas Glanzmann,
Thomer Gil, Tim Stoakes, Tyler Earnest, Victor Manuel Jaquez Leal,
Vincent Lefevre, Vladimir Marek, Vsevolod Volkov.

## Original Mutt Authors

And of course, we should thank the original Mutt authors, including the original
author Michael Elkins and all the people that have contributed to Mutt during
its long history, see the Acknowledgements section of the user manual for a
detailed list.

http://www.neomutt.org/guide/miscellany.html#acknowledgements

