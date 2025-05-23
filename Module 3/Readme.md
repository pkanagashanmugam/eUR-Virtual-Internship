# Module 3 - Signals and Threads

**Question 1 Execution :**

| **ACTION** | **SIGNAL TRIGGERED** | **DESCRIPTION** |
| :---:      | :---:                | :---:           |
| Ctrl+C | SIGINT (Value 2) | A Signal Interrupt signal is sent to the process to handle the user interrupt |
| Kill System Call | SIGTERM/SIGKILL/SIGQUIT | The Kill() system calls can internally call any signals. Some common examples are listed. According to the process, different signals can be used |
| CPU trying to execute illegal instruction | SIGILL | When CPU tries to execute illegal instruction, a SIGILL signal is triggered which terminates the program |
| Program access unassigned memory | SIGSEGV | This signal handles segmentation fault which is a result of a program trying to access illegal/unassigned memory |

**Question 2 Execution :**

GDB commands used to perform following operations are :
- Run the current executable file : `run`
- Setting breakpoints : `b [options]` (or) `b [function_name]` (or) `break[file_name]:[line_number]`
- Resume execution after breakpoint : `continue` or `c`
- Clearing a breakpoint : `clear [line_number]` or `clear [function_name]`
- Print parameters of function : `info args` or `show args`

**Question 3 Execution :**

The output of the code given will print a pattern of 2's with **minimum frequency being 2** and **maximum frequency being 6**. Depending on the return value of fork, the conditional execution takes place and further fork calls get executed.

**Question 4 Execution :**

The output of the code can get varied according to the order of execution but the output. The output produced will be combination of the following patterns **3 4**, **2 4** and **1 4**

**Question 5 Execution :**

**Question 6 Execution :**

**Question 7 Execution :**

**Question 8 Execution :**

**Question 9 Execution :**
