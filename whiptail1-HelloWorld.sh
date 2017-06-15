#!/bin/bash

echo "Okay, here we go!"
sleep 1
#echo "3"
#sleep 1
#echo "2"
#sleep 1
#echo "1"
#sleep 1

clear
# echo -e '\0033\0143' clears the screen, & skips a line

if (whiptail --title "Hello, welcome..." --yesno "Lets get to know each other. \n  Are you a boy or girl?" 15 40) then 
	echo "Passed Round 1
"
	if  (whiptail --title "Good"  --yesno "Are you under 18?" 15 40) then
		echo "Passed Round 2.
"
	else
		echo "Sorry to to hear that.
Bye
"
	fi  
else
	echo "Sorry, no boys allowed :)
Couldn't even pass the first level."
fi

# The goal of this is to play a litle game. Exit if No, and say, "ew." If Yes, then continue on with random questions. Then after 5 questions, return a random percentage and tell them that's how much they got right.
