#!/bin/bash

usage()
{
  echo "$0 usage: [-f input file] [-c U(pper) L(ower)]"
  exit 1
}

while getopts ":f:c:" options;
do
  case "${options}" in
    f)
      f=${OPTARG}
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
exit 0
