#!/bin/bash
red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
magenta='\33[0;35m'
default='\33[0m'

read -p "Select a color (yellow or purple): " color
color=${color^^}

case $color in
     "YELLOW")
       selected_color=$yellow
       echo -e "${selected_color}Your selected color is ${color}."
       exit 0
       ;;
     "PURPLE")
       echo "Purple is not a valid color."
       exit 1
       ;;
     "")
       echo "You didn't enter a valid input."
       exit 1
       ;;
     *)
esac
