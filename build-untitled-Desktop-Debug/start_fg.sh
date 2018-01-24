#!/bin/sh
START=uniset2-start.sh

GTK2_RC_FILES=./gtkrc LC_ALL=ru_RU.UTF-8 ${START} -f ./untitled --smemory-id SharedMemoryGUI \
	--mpu-guifile mpu15310-gui.ui \
	--mpu-confile guiconfigure.xml \
	--pass-check-off --no-beep \
	--pulsar-id Pulsar_S \
	--pulsar-msec 5000 \
	--e-filter evnt_gui \
	$*
killall get-gate-version.sh
