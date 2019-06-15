**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- running - while the code is being executed.
- waiting - a process is waiting for a child process to finish running.
- sleeping - a process is not running, may be waiting for CPU time.
- zombie - a process has completed running, but has yet to be cleaned up.

**2. What is a zombie process?**

- a process that has finished running, but has yet to be cleaned up from memory.

**3. How does a zombie process get created? How does one get destroyed?**

- Once a process is finished running, it will persist in memory, becoming a zombie process. Once the process has been cleaned up, the zombie process is destroyed. This may occur if the parent cleans up the child. If not, the main process may clean up the orphaned process. If neither occur, the process will be cleaned up when you exit the program.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

- compiled languages are typically faster, because they are compiled down runtime
- compiled languages will not compile unless they are error free
