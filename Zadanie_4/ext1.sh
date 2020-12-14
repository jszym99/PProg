#!/bin/bash

for i in *$1; do mv -- "$i" "${i%$1}`echo $1|tr [:upper:] [:lower:]`"; done
