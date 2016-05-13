#!/bin/bash

pass="0715"

input=$(whiptail --passwordbox "Please enter the secret password for access" 8 30 --nocancel --title "Password Authentication" 3>&1 1>&2 2>&3)

if [ "$pass" = "$input" ];
then
	whiptail --ok-button Next --msgbox "     Congratulations" 8 30
else
	if [ "$input" == "" ];
	then
		whiptail --ok-button lol --msgbox "You didn't enter anything" 8 30
	else
		whiptail --ok-button Loser --msgbox "	Incorrect" 8 30
	fi
fi

## echo "(Exit status was $exitstatus)" Shows exit status

## I'm not quite sure what to do with this now.
## Continue thinking...
