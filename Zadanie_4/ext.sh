#!/bin/bash

for i in *.PNG; do mv -- "$i" "${i%.PNG}.png"; done
for j in *.JPG; do mv -- "$j" "${j%.JPG}.jpg"; done
for k in *.JPEG; do mv -- "$k" "${k%.JPEG}.jpeg"; done
