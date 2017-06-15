#!/bin/bash

counter=0

if [ $counter = 0 ];
then
	for i in $(seq 0 10 100) ;
	do sleep 1;
	echo $i | dialog --gauge "Don't click CTRL+C ;)" 10 70 0; 
	done
else
	echo ""
fi
	echo "

Haha should have clicked it :) :) :) "
sleep 1
echo "Please wait..."
sleep 2
clear
echo "Wait.... A secret level....
"
sleep 4
echo "The FitnessGram Pacer Test is a multistage aerobic capacity test that progressively gets more difficult as it continues. The 20 meter pacer test will begin in 30 seconds. Line up at the start. The running speed starts slowly but gets faster each minute after you hear this signal bodeboop. A sing lap should be completed every time you hear this sound. ding Remember to run in a straight line and run as long as possible. The second time you fail to complete a lap before the sound, your test is over. The test will begin on the word start. On your mark. Get ready!… Start. Ding!"
sleep 4
clear
echo "I'm just joking."
echo "You passed all the rounds!" 
echo "Thanks for playing! 
" 

sleep 1
echo "You won!!!!!!!!!!!!
"
sleep 4
clear
#	clear


# if user commits to "c"  then exit and print
# use getch() and scanf

# except im not quite sure how to impliment c code in here. Do I add the usual "main" and headers?
