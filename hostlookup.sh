#!/bin/bash

#Checks to see if the file is valid
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

#Reads through each host, and prints out a valid ip address
while read line
do
  if [ ${f} == "hosts.txt" ]; then
    for h in $line
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
  #If the file isn't hosts.txt, exit the file
  else
    echo "Incorrect file."
    exit 1
  fi
done < $f

exit 0
