#!/bin/bash

for h in $(cat users.txt | cut -d "@" -f 1)
do
  userdel -r $h
done

