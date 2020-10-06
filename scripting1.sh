#!/bin/bash

# file commenting.sh
# brief  Our First Script with commenting for the file and functions 
# author bilbo.baggins
# lecture 5.1 comments 
# date 7/8/2020

#title
title="Scripting 1"

#functions

# brief Calculates the difference between today and 8/31/2020 and reports
# the number of days until the Fall Semester Begins
daystilschool()
{
  DATETODAY=$(date -d "$1" +%s)
  DATESCHOOLSTARTS=$(date -d "8/31/2020" +%s)
  echo $((($DATESCHOOLSTARTS-$DATETODAY)/86400)) days til school starts
}

#Basic System Information
systeminfo()
{
  DISTRIBUTION=$(lsb_release -a)
  KERNELVERSION=$(uname -a)
  CPUARCHITECTURE=$(lscpu | awk '/Architecture/ {print}')

  echo "Linux Distribution: " $DISTRIBUTION
  echo "Kernel Version: " $KERNELVERSION
  echo $CPUARCHITECTURE
}

#Gets the system's IP address
networkinfo()
{
  IPADDRESS=$(hostname -I)
  echo "IP Address: " $IPADDRESS
}

#Gets the amount of available storage space
storagespace()
{
  STORAGESPACE=$(df -h)
  echo "Free Storage Space:"
  echo $STORAGESPACE
}

#Checks disk information
diskinfo()
{
  DISKINFO=$(lsblk)
  echo "Disk Information:"
  echo $DISKINFO
}

#Gets all users on this system
getusers()
{
  USERS=$(cat /etc/passwd | grep bash | cut -d ":" -f 1 | sort)
  echo "All Users In Order:"
  echo $USERS
}

echo "Welcome to CSI230: " $title

systeminfo
storagespace
diskinfo
getusers
networkinfo
