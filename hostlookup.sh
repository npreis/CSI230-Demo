#!/bin/bash

for h in champlain.edu umv.edu umd.edu abcdefg.edu
do
  host -W1 -t A $h
done
