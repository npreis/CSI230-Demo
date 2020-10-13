#!/bin/bash

while getopts ":f:" options;
do
  case "${options}" in
    f)
      f=${OPTARG}
      if [[ -f "$f" ]]; then
        echo "Begin reading hosts:"
      else
        echo "Not a valid file."
        exit 1
      fi
      ;;
    *)
  esac
done

while read line
do
  if [ ${f} == "hosts.txt" ]; then
    for h in champlain.edu uvm.edu umd.edu abcdefg.hi
    do
      out=$(host -W1 -t A $h)
      if [ $? -eq 0 ]; then
        ip=$(echo $out | cut -d " " -f 4)
        if [[ $ip =~ ^92.242.140.21$ ]]; then
          echo "${h} - not found."
        else
           echo ${h} - $ip
        fi
      fi
    done
  fi
done < $f

exit 0
