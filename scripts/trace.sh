#!/bin/bash

if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

function flush_caches
{
	echo Syncing and dropping caches ...
	sync
	echo 3 > /proc/sys/vm/drop_caches
}

source /home/user/S/utilities/tracing.sh

TRACE=1
DEVS=sda
init_tracing

flush_caches

echo > /sys/kernel/debug/tracing/trace
set_tracing 1
$@
set_tracing 0
cat trace
rm trace