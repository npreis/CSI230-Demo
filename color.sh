#!/bin/bash
red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
purple='\33[0;35m'
default='\33[0m'

read -p "Select a color (yellow or purple): " color
color=${color^^}

echo "${color}"
