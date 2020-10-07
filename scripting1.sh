#!/bin/bash

# file commenting.sh
# brief  Our First Script with commenting for the file and functions 
# author bilbo.baggins
# lecture 5.1 comments 
# date 7/8/2020

#title
title="Scripting 1"

#functions

#Checks to see if user is root
isroot()
{
  if [ "$(id -u)" != "0"  ]; then
    echo "Must run in root."
    exit
  fi
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
  STORAGESPACE=$(df -h -l)
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

#Gets the current date and time
dateandtime()
{
  DATEANDTIME=$(date)
  echo "Date and Time: " $DATEANDTIME
}

#Gets current user
getcurrentuser()
{
  CURRENTUSER=$(whoami)
  echo "Current User: " $CURRENTUSER
}

isroot
echo "Welcome to CSI230: " $title

systeminfo
storagespace
diskinfo
getusers
networkinfo
dateandtime
getcurrentuser
