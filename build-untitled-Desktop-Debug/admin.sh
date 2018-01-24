#!/bin/sh

START=uniset2-start.sh
${START} -f "uniset2-admin --`basename $0 .sh` $1 $2 $3 $4 --confile configure.xml"
#${START} -f uniset-admin --`basename $0 .sh` --confile ./configure.xml $1 $2 $3 $4
