
Debian
====================
This directory contains files used to package bitcoinrandomd/bitcoinrandom-qt
for Debian-based Linux systems. If you compile bitcoinrandomd/bitcoinrandom-qt yourself, there are some useful files here.

## bitcoinrandom: URI support ##


bitcoinrandom-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install bitcoinrandom-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your bitcoinrandom-qt binary to `/usr/bin`
and the `../../share/pixmaps/bitcoinrandom128.png` to `/usr/share/pixmaps`

bitcoinrandom-qt.protocol (KDE)

