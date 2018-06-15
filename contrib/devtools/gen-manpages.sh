#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

BITCOINRANDOMD=${BITCOINRANDOMD:-$SRCDIR/bitcoinrandomd}
BITCOINRANDOMCLI=${BITCOINRANDOMCLI:-$SRCDIR/bitcoinrandom-cli}
BITCOINRANDOMTX=${BITCOINRANDOMTX:-$SRCDIR/bitcoinrandom-tx}
BITCOINRANDOMQT=${BITCOINRANDOMQT:-$SRCDIR/qt/bitcoinrandom-qt}

[ ! -x $BITCOINRANDOMD ] && echo "$BITCOINRANDOMD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCRVER=($($BITCOINRANDOMCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for bitcoinrandomd if --version-string is not set,
# but has different outcomes for bitcoinrandom-qt and bitcoinrandom-cli.
echo "[COPYRIGHT]" > footer.h2m
$BITCOINRANDOMD --version | sed -n '1!p' >> footer.h2m

for cmd in $BITCOINRANDOMD $BITCOINRANDOMCLI $BITCOINRANDOMTX $BITCOINRANDOMQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCRVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCRVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
