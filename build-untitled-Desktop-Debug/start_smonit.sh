#!/bin/sh

START=uniset2-start.sh
${START} -f uniset2-smonit --sid $*
# --script event.sh --sid $1 
#  --unideb-add-levels info,system