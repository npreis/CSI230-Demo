#!/bin/bash

# file commenting.sh
# brief  Our First Script with commenting for the file and functions 
# author bilbo.baggins
# lecture 5.1 comments 
# date 7/8/2020

#functions

# brief Calculates the difference between today and 8/31/2020 and reports
# the number of days until the Fall Semester Begins
daystilschool()
{
  DATETODAY=$(date -d "$1" +%s)
  DATESCHOOLSTARTS=$(date -d "8/31/2020" +%s)
  echo $((($DATESCHOOLSTARTS-$DATETODAY)/86400)) days til school starts
}

echo "Welcome to CSI230"
echo "Kernel Version" $(uname -a)
echo "CentOS Version"
cat /etc/redhat-release
echo "Logged on Users"
w
daystilschool
