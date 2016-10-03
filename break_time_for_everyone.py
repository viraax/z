import time
import webbrowser
import random 

def main():

	tot_breaks = 10 
	break_counter = 0
	

	songs = ["https://www.youtube.com/watch?v=vE2ETqUGj6Q", "https://www.youtube.com/watch?v=ih2xubMaZWI", "https://www.youtube.com/watch?v=SPhsSzfAoBA", "https://www.youtube.com/watch?v=AoSKNG-8Xvg", "https://www.youtube.com/watch?v=8MoUCeyVRIk", "https://www.youtube.com/watch?v=aOe9I1Ylj9c", "https://www.youtube.com/watch?v=I3Ri7WD7ZLg", "https://www.youtube.com/watch?v=Ygjj7WqTIS4", "https://www.youtube.com/watch?v=4_m2uB5NEgI", "https://www.youtube.com/watch?v=h-S7_--2hbI", "https://www.youtube.com/watch?v=h7clEaBeMoc"]
	
	
	for i in range(0, len(songs)):
			
		while (break_counter < tot_breaks):
			
			random_c = random.choice(songs)
			webbrowser.open(random_c)
					#songs[i]
			time.sleep(600)
			break_counter += 1			
main()

