#!/bin/bash

#Skrypt przenosi pliki no nowego katalogu, zamienia wielkie litery w rozszerzeniach na male, ...

ext=(".PNG" ".JPG" ".JPEG" ".png" ".jpg" ".jpeg")

if [ ! -d "arch/" ]; then
	mkdir arch
fi

for e in *${ext[@]}
do
	for i in *"$e"; do cp "$i" arch/; done

	for k in arch/*; do mv -- "$k" "${k// /_}"; done

	for j in arch/*$e; do mv -- "$j" "${j%$e}`echo $e|tr [:upper:] [:lower:]`"; done
done
zip -r arch.zip arch
