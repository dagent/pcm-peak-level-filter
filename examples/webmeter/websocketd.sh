#!/bin/bash

logf=/tmp/websocketd-dev.log 

#websocketd --port=1234 --loglevel=debug --devconsole --dir=. &>>$logf &

websocketd --port=2345 --staticdir=html ./mic-peaks.sh &>>$logf &
