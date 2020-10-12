#!/bin/bash
#liste.sh

for lines in $(grep -n 'passed' "$1")
do
    echo "${lines}" | grep 'valider'
done
