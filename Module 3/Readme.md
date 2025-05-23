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

The output of the code can get varied according to the order of execution but the output. The output produced will be combination of the following patterns **3 4**, **2 4** and **1 4** depending on the execution of fork() by the OS and the conditional statements it is subjected to.

**Question 5 Execution :**

![image](https://github.com/user-attachments/assets/70d25487-b895-4c4a-a38e-a5dd4f8a304d)

**Question 6 Execution :**

Race and Deadlocks can be prevented by use of Mutex which stands for Mutual Exclusion. It is used to prevent deadlocks rising out of the critical section of the code. It protects shared resources from concurrent access by multiple threads and locks the critical section for one particular thread and later unlocks it.

**Question 7 Execution :**

| **FORK** | **EXEC**|
|   :---:  |   :---: |
|Creates a child process | Replaces the current program with a new program |
| Returns twice: Once for parent and another for child | Does not return |
| The child gets a new Process Id different from that of the parent | The Process Id remains the same |
| Duplicates parent's resources | Replaces existent resources |

**Question 8 Execution :**
| **PROCESS** | **THREADS**|
|   :---:     |   :---:    |
| A program under execution is called a process | Threads are instances/segments of a process |
| Since they are not lightweight, they take time to terminate | Threads are lightweight processes and take minimal time for execution |
| Individual process have their own memory | Threads used shared memory |

**Question 9 Execution :**

![image](https://github.com/user-attachments/assets/7448c291-a45c-4e1d-84a6-4b751bbd6834)
