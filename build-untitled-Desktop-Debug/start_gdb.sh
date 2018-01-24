#!/bin/sh
START=uniset2-start.sh

GTK2_RC_FILES=./gtkrc LC_ALL=ru_RU.UTF-8 ${START} -g ./untitled --smemory-id SharedMemoryGUI \
    --guifile mpu15310-gui.ui --pass-check-off --no-beep \
            --mpu-guifile mpu15310-gui.ui \
        --mpu-confile guiconfigure.xml \
	--skip-mb1 \
	--skip-mb2 \
	--dlog-add-levels info,warn,crit $*

#	--mbtcp-filter-field tcp --mbtcp-filetr-value 1 \

#	--dlog-add-levels warn,crit

#	--mbtcp-filter-field mbtcp --mbtcp-filter-value 1

killall get-gate-version.sh
