#!/bin/bash

# file mail.sh
# brief  Script to give users new passwords 
# author nicholas.preis
# Project 2 comments
# date 10/22/2020

#Checks to see if the user is root
isRoot()
{
  if [ $(id -u) != 0 ]; then
    echo "Must run as root user!"
    exit 1
  fi
}
isRoot
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

sendMail()
{
  while read line
  do
    for h in $line
    do
      #Gets user and generates a password
      users=$(echo ${h}|cut -d "@" -f 1)
      passwd=$(openssl rand -hex 6)
      echo $users - $passwd

      #Checks if user exists
      if [ "$(cat /etc/passwd) | cut -d ':' -f 1 | grep $user)" = "$users" ]; then
        title="XYZ PopOS Password Updated"
        $(echo "$users:$passwd" | chpasswd)
      else
        title="XYZ PopOS New User"
        useradd -m -G CSI230 -s /bin/bash $users -p passwd
        chage -d 0 $users
      fi

      echo An account on PopOS was created for you! Username: $users - Password: $passwd > message.txt
      $(mail -s "$title" nicholas.preis@mymail.champlain.edu < message.txt)

    done
  done < $f
}
sendMail

exit 0
