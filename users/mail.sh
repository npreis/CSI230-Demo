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
    cat << EOF
    Must run as root user!
    EOF
    exit
  fi
}
