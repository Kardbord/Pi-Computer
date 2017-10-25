# Assignment 5

### Tanner Kvarfordt

### A02052217

### Preface

The description below is taken directly from Dr. Mathias's canvas page for this assignment and modified
to be a markdown file.

See the assignment in Canvas for additional info, unless you're not a student registered in this class, 
in which case you're SOL. :P

### Introduction

In this assignment you'll be computing the digits of Pi using your Raspberry Pi!  I realize I'm more excited about that than I really should be, but I am.  The purpose of this assignment is to have you write a multi-threaded application that utilizes all four cores of the Raspberry Pi in a coordinated effort to compute 1000 digits of the constant Pi.  Each core will work on a task to compute a single digit of the fractional part of Pi, while sharing a common data structure from which to obtain the tasks and another shared data structure into which the results should be placed.  This will help you become familiar with multi-threaded coding in C++, which includes coordination of shared resources.

### Assignment

Write a multi-threaded program that computes the first 1000 digits of Pi (to the right of the decimal).  The program must utilize all system CPU cores simultaneously, using a task-based scheme to distribute the work.  The program should be written according to the following specifications:

1. Create a FIFO queue that stores the compute tasks (http://www.cplusplus.com/reference/queue/queue/ (Links to an external site.)Links to an external site.).
    1. This queue must be protected against race conditions.
    2. At program startup, before creating any of the worker threads, fully populate this queue with 1 task per digit to be computed; 1000 tasks.  Each task will say which digit to compute.
    3. This is a shared resource available to all worker threads (not a global variable, however).
    4. Use aggregation, rather than inheritance, to create this queue.  Use a mutex, private to the queue, to protect the write/read operations.
2. Create a hash table to store the results (http://www.cplusplus.com/reference/unordered_map/unordered_map/ (Links to an external site.)Links to an external site.).  Each entry in the hash table has as its key the digit position and the computed Pi digit as its value.
    1. This hash table must be protected against race conditions.
    2. This is a shared resource available to all worker threads (not a global variable, however).
    3. Use aggregation, rather than inheritance, to create this hash table.  Use a mutex, private to the hash table, to protect the write/read operations.
3. Create as many worker threads as there are CPU cores (std::thread::hardware_concurrency()); rather than hard-coding the number of threads.  Each of these worker threads obtains a task from the FIFO task queue, computes the requested digit, then stores the result in the hash table.  It continues retrieving tasks from the queue until there are none, then it voluntarily terminates.
    1. As each worker begins a task, print a "." to the screen to indicate progress.  You may/will need to execute a std::cout.flush() right after printing the "." to ensure it gets displayed to the console immediately.
4. When the FIFO queue is empty and all threads have finished their work, display the computed value of Pi.
5. After the display is complete, the program should gracefully exit.
6. I've provided a screenshot of a sample run on my program at the end of this page; have your output match this approach.  On my Raspberry Pi it took almost 3 minutes (2 minutes, 51 seconds) to run.  The same run takes 8.8 seconds on my desktop system (8 CPU cores).

### Notes

* Create a CMakeLists.txt file that CMake can use to create a makefile that builds your program.
    * You'll want the compiler flags line to look like: 

            set(CMAKE_CXX_FLAGS "-std=c++11 -lpthread -O3 ${CMAKE_CXX_FLAGS}")

* You can use the utility 'htop' to visually watch the CPU cores utilization on your Raspberry Pi.  It can be installed by "sudo apt-get install htop".
* I have provided some code you may use to compute the nth digit of Pi at this linkPreview the documentView in a new window.  I have adapted it from this source (http://stackoverflow.com/questions/5905822/function-to-find-the-nth-digit-of-pi (Links to an external site.)Links to an external site.).  It is really horrible to read, I don't recommend this coding style, but who am I to judge, the author of the code wrote something I didn't.  This implementation is O(n2), which isn't great, it slows down pretty quickly (that is why only 1000 digits).  Also, inside this code file there is a far, far faster way I've adapted from a Python source, which is something like O(log(n3) * log(n2)), but it gives results in base 16 (hex digits).  That is all well and good, but we can't convert those hex digits to decimal, because we'd need a floating point type with thousands of digits of precision, which we don't have.  If anyone tackles this, you are a hero!  I don't have the time to take it on.
    * There is another technique for computing the digits of PI, one I haven't tried.  It is supposed to be the standard for computing the digits FAST.  If anyone tries this code, let me know how it goes, I suspect it is significantly faster than the C code I originally found and provided.  You can find code and discussion at the following links:
* https://gmplib.org/pi-with-gmp.html (Links to an external site.)Links to an external site.
* https://en.wikipedia.org/wiki/Chudnovsky_algorithm (Links to an external site.)Links to an external site.
* http://www.craig-wood.com/nick/articles/pi-chudnovsky/ (Links to an external site.)Links to an external site. (and it is "math" in the US, not "maths", that is British English).

