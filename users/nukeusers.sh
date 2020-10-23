#!/bin/bash

#Checks to see if the file is valid
while getopts ":f:" options;
do
  case "${options}" in
    f)
      f=${OPTARG}
      if [[ -f "$f" ]]; then
        echo "Nuking Users"
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
  for h in $line | cut -d "@" -f 1)
  do
    userdel -r $user
  done
done
