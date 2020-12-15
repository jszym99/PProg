#!/bin/bash

if [ "$HOSTNAME" = "diablo" ]; then
PING_COM="/usr/sbin/ping"
else
PING_COM="ping"
fi

#export DISPLAY=:0.0

# sprawdzamy czy userfriendly się odzywa, jeśli nie kończymy
$PING_COM -c 1 userfriendly.org > /dev/null || exit 1

# w katalogu domowym usuwamy ewentualnie istniejący katalog pomoczniczy uf_temp
# i tworzymy nowy, pusty
cd $HOME
test -d uf_temp && rm -rf uf_temp
mkdir uf_temp
cd uf_temp

wget -q en.wikiquote.org/wiki/Wikiquote:Quote_of_the_Day

rand=$((1 + $RANDOM % 139))

grep -e "<dd>" Wikiquote:Quote_of_the_Day | sed -e 's/<[^>]*>//g' | tail +2 | sed "${rand}q;d" | cut --complement -d "." -f1 | sed -e 's/^[[:space:]]*//' | sed 's/ *$//g'
