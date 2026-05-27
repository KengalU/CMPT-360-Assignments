# CMPT 360 - Assignment 2
Name: Kevin Usuanlele / Scott Weaver
ID:  3103649 / 3144661
Date: May 25, 2026
# 1. Academic Integrity
We certify that this submission represents entirely our own work.
# 2. Overview
A program that parses a command line, then reads files and uses the input recieved to 
simulate how a cpu might run processes using either round robin or first in first out.
Tracks the time of completion and statistics of the run in order to 
compare and contrast results.
# 3. Build
/
# 4. Run
/
# 5. Logic Summary
- Reads command line inputs and stores parameters
- Uses file given in command line to access the process information for the simulation
- Runs Round Robin style simulation or FIFO depending on input from command line
- Round Robin
    - Processes will run for a number of cycles determined by quantum
    - If quantum is hit, places process at the back of the queue
    - If task completes quantum is reset and next task is run (context switch)
    - Continues until no processes remain
- First in First Out
    - Processes run in order that they were recieved
    - A process must finish before the next process can be run
    - Continues until no processes remain
- Statistics are measured based on results
    - Average Turnaround Time 
    - Average Response Time
    - Context Switches
    - 
- Displays run time stats while running
- Statistics are displayed after calculation

# 6. Status
Make file works correctly
Command Line parsing works properly
Reading file works properly
Simulation loop correctly runs
Output to console matches required output
Statistics match properly
# 6. Notes / Assumptions (Optional)
Decided that simulation should include both RR logic and FIFO logic as it would get
too complicated to separate them both due to the arrays of structs used.
Passing too many things as a return value and as parameters might get messy and confusing
