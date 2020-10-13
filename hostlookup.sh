#!/bin/bash

for h in champlain.edu umv.edu umd.edu abcdefg.edu
do
  out=$(host -W1 -t A $h)
  if [ $? -eq 0 ]; then
    ip=$(echo $out | cut -d " " -f 4)
    echo $host - $ip
  else
    echo "{h} does not have a DNS record."
  fi
done
