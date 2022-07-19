# Exercises
---
1) Yes, fork() can return an error. This would occur if, for some reason, our process was not able to properly create a child process. This is important, because if we're trying to do necessary operations in the child, we need to know if the fork was success or not beforehand. Furthermore, once we go back to our parent, we want to know whether or not the child fork was successful as well.
---
2) Yes, exec() can return an error. This would occur if, for some reason, our executable image wasn't brought into memory properly. This is important, since if any point in the sequence of exec() fails, then our image will not be able to start. 
---
3) Essentially, this would endlessly create forks until no memory was left.
---
4) The child process must complete in some form, e.g. by finishing instructions, failing at an instruction point, or some other form of termination.
---
5) You would need to use open() and close() to access each homework assignment file. From there, you would also need to utilize read() to put each assignment's contents into a buffer, so that you could have code to check answers and grade each file. Write() could also be used, for example, to add a grade at the bottom of the assignment file, before sending it back to the student.
---
6) This causes our current shell (here, BASH) to exit and a new process is started; here, c-shell (csh).
---
7) Our shell window exits. This is because, by calling ls to execute, we are ending the shell itself as a consequence.
---
8) Generally, we would use an algorithm of form ```(2^N)-1```. Here, ```N = 5```, so ```2^5 - 1 = 31```. Here, we subtract one to account for the original parent, which is not included in this answer.
---
9) Here, our original process would fork, creating a child process. That parent process would then fork and create another child process. These three processes would have the x values of 20, 15, and 10, respectively. 
---
10) Here, our first program has a parent process that prints out val = 6, and then a child process that prints out val = 7. Our second program has a parent process that exits (printing nothing), and then a child process that prints out val = 6. 
---
11) Defined in 'turtlehouse.c'. 
