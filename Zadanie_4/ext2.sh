#!/bin/bash

ext=(".PNG" ".JPG" ".JPEG" ".png" ".jpg" ".jpeg")

for j in *${ext[@]}
do
	for i in *$j; do mv -- "$i" "${i%$j}`echo $j|tr [:upper:] [:lower:]`"; done
done
