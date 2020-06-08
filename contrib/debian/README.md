
Debian
====================
This directory contains files used to package billetcoind/billetcoin-qt
for Debian-based Linux systems. If you compile billetcoind/billetcoin-qt yourself, there are some useful files here.

## billetcoin: URI support ##


billetcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install billetcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your billetcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/billetcoin128.png` to `/usr/share/pixmaps`

billetcoin-qt.protocol (KDE)

