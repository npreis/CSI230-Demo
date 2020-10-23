#!/bin/bash

# file mail.sh
# brief  Script to give users new passwords 
# author nicholas.preis
# Project 2 comments
# date 10/22/2020

#Checks to see if the user is root
isRoot()
{
  if [ "$(id -u)" != root ]; then
    echo "Must run as root user!"
    exit
  fi
}

usage()
{
  echo "$0 usage: [-f input file]"
  exit 1
}

while getopts ":f:" options;
do
  case "${options}" in
    f)
      f=${OPTARG}
      if [[ -f "$f" ]]; then
        echo "Valid file"
      else
        usage
      fi
      ;;
    *)
      usage
      ;;
  esac
done

getuser()
{
  while read line
  do
    for h in $line
    do
      users=$(echo ${h} | cut -d "@" -f 1)
      echo $users
    done
  done < $f
}

randpasswd()
{
  while read line
  do
    for h in $line
    do
      passwd=$(openssl rand -hex 6)
      echo $passwd
    done
  done < $f
}

getuser
#randpasswd

exit 0
