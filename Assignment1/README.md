# CMPT 360 - Assignment 1
Name: Kevin Usuanlele / Scott Weaver
ID:  3103649 / 3144661
Date: May 10, 2026
# 1. Academic Integrity
We certify that this submission represents entirely our own work.
# 2. Overview
A command-line utility that reads a username from standard input and checks
if its meets a set of validity criteria. If the username is valid, it reports
as such, if not, the program attempts to fix the username using predefined rules.
If no valid transformation is possible, the program deems the input as invalid
and unfixable
# 3. Build
/
# 4. Run
/
# 5. Logic Summary
- Reads username
- If reserved label as unfixable
- Otherwise clean:
    - convert to lowercase
    - replace spaces with underscores
    - remove invalid characters
    - pad/trun to be between 3 and 16 characters
- Validate again
# 6. Status
userclean runs correctly and passes input and valgrind tests.
Outputs exactly match specifications
# 6. Notes / Assumptions (Optional)
