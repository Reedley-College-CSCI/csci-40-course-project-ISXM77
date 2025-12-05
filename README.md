[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7mdzU3H2)
# CS1 Final Project - [Project Title]

## 1. Overview
- What problem does your project solve?  
- My project solves the issue of having to manually keep track of a baseball game with traditional pen & paper
- by allowing you easily keep track of the game using user input.

- Briefly describe the purpose and key features of your program. 
- My program keeps track of key team statistics based off of user input throughout each inning of a baseball game, 
- outputs a final scoreboard to a file, shows the highest scoring inning for each team, and sorts innings in 
- descending scoring order for each team.
---

## 2. Design Decisions
- What fundamental programming constructs and data types did you use, and why?  
- I implemented the use of a single class to hold functions, variables, arrays, and a struct that handles integer
- inputs from the user to determine the values for each inning and for each team. I used loops to iterate through
- innings and continously read user input until the innning is over. I decided to use an array of structs for each 
- team to separate each teams stats. 
- 
- Why did you choose to structure your data using structs?  
- I chose to structure my data using a struct to easily have a set of variables for each team.
- It tracks hits, outs, and runs for each team and can be easily updated by member functions
- using loops.
-
- How did you implement searching and sorting? What algorithms did you use and why?  
- I decided to implement searching and sorting by iterating through each inning to return
- the highest scoring innings for each team using both methods. I chose to use a linear search and
- selection sort for simplicity and because the data set will likely remain rather small.
- 
- How do you ensure data persistence between program runs?  
- Scoreboard data is sent to a File to ensure data persistence.
-
- Did you consider alternative approaches? If so, why did you not use them?  
- Yes, I considered using if statements to get user input and determine the play, but I found it unneccesary
- to have the user type "out" or "hit" everytime. I ended up changing the user input method to switch statement
- with different cases for each integer input from the user.

---

## 3. Testing Summary
- **Structured Testing Log:** Include a table with test cases, expected output, actual output, and pass/fail status.  
- What testing methods did you use?  
- For the sake of length and time, I would continously input 1 for outs until I reached the 8th or 9th inning
- and then began to input hits and runs to test various functions.

- Provide examples of test inputs (valid and invalid) and describe how your program responds.


Invalid Input:

PASS- Expected Output:
- 1. Out | 2. Hit | 3. Walk | 4. HR | 5. HBP|

What is the result of the next play in the top of inning #1: 11
Enter a number between 1 and 5:

Program correctly asked for valid input after invalid input of 11.

FAIL:
What is the result of the next play in the top of inning #1: 11
What is the result of the next play in the top of inning #1:

Program incorrectly does indicate that the invalid input was invalid

Valid Input:

PASS- Expected Output:
- 1. Out | 2. Hit | 3. Walk | 4. HR | 5. HBP|

What is the result of the next play in the top of inning #1: 1
What is the result of the next play in the top of inning #1: 2
Runs Scored: 0
On Base: 1

Program correctly prompt the user for runs scored and on base after inputting 2 for hit.

FAIL:
What is the result of the next play in the top of inning #1: 2
What is the result of the next play in the top of inning #1:

Program incorrectly does not prompt the user for runs scored or on base.

---

## 4. Technical Walkthrough
- Explain the main functionality of your program.  
- **Include a link to your required video demonstration** showcasing how the project works (**3-7 minutes**). 
    Make sure it shareable without approval needed.
- https://youtu.be/_JRj_75oZVo

---

## 5. Challenges and Lessons Learned
- What challenges did you encounter while working on this project?  
- While working on the project, I had trouble getting the separate files to work properly
- as Game.h, Game.cpp, and main.cpp but messing around with it I was able to get it to work.
- I suspect it was the placement of using namespace std; but I am still not 100% sure.
- Additionally, I had trouble sending the scoreboard to the file but it was because I misunderstood
- function return types and I decidedly changed to a string return type and output the scoreboard as a string.
- 
- What key lessons did you learn about programming and problem-solving?  
- I learned that programming involves a ton of testing, input validation, and attention to detail because
- the amount of times that an error in my code was caused by a missing semicolon, an unidentified/undeclared 
- variable, a variable out of scope, or an invalid input breaking the program consumed most of the time I spent 
- troubleshooting.

---

## 6. Future Improvements
- If you had more time, what changes or enhancements would you make?  
- If I had more time, I would've considered integrating a roster for each team and key player stats
- to be tracked like rbi's, batting avg, plate appearances, hits, and at bats and then outputting
- the roster and their updated stats to files to be easily reused and updated after each game.
- Additionally, I would've liked to add more specific play types like Sac Flies, Sac Bunts,
- Stolen Bases, etc. but I decided to keep it simple in order keep expectations within reach.
