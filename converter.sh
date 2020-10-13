#!/bin/bash

usage()
{
  echo "$0 usage: [-f input file] [-c U(pper) L(ower)]"
  exit 1
}

#Checks to see if file and casing is valid
while getopts ":f:c:" options;
do
  case "${options}" in
    f)
      f=${OPTARG}
      if [[ -f "$f" ]]; then
        echo "This is a valid file"
      else
        usage
      fi
      ;;
    c)
      c=${OPTARG}
      if [[ ${c} == "U" || ${c} == "L" ]]; then
        echo "${f} - ${c}"
      else
        usage
      fi
      ;;
    *)
      usage
      ;;
  esac
done

#Reads through file, and prints everything in upper or lowercase
while read line
do
  if [ ${c} == "U" ]; then
    echo $line | tr [:lower:] [:upper:]
  else
    echo $line | tr [:upper:] [:lower:]
  fi
done < $f

exit 0
