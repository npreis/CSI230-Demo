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
cat << EOF
Must run in root.
EOF
    exit
  fi
}

#Basic System Information
systeminfo()
{
  DISTRIBUTION=$(lsb_release -a)
  KERNELVERSION=$(uname -a)
  CPUARCHITECTURE=$(lscpu | awk '/Architecture/ {print}')

cat << EOF
Linux Distribution:
$DISTRIBUTION
Kernel Version:
$KERNELVERSION
$CPUARCHITECTURE
EOF
}

#Gets the system's IP address
networkinfo()
{
  IPADDRESS=$(hostname -I)
cat << EOF
IP Address:$IPADDRESS
EOF
}

#Gets the amount of available storage space
storagespace()
{
  STORAGESPACE=$(df -h -l)
cat<<EOF
Free Storage Space:
$STORAGESPACE
EOF
}

#Checks disk information
diskinfo()
{
  DISKINFO=$(lsblk)
cat<<EOF
Disk Information:
$DISKINFO
EOF
}

#Gets all users on this system
getusers()
{
  USERS=$(cat /etc/passwd | grep bash | cut -d ":" -f 1 | sort)
cat<<EOF
All Users In Order:
$USERS
EOF
}

#Gets the current date and time
dateandtime()
{
  DATEANDTIME=$(date)
cat<<EOF
Date and Time:$DATEANDTIME
EOF
}

#Gets current user
getcurrentuser()
{
  CURRENTUSER=$(whoami)
cat<<EOF
Current User:$CURRENTUSER
EOF
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
