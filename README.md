# A3-Part-II-Q1
includes: Source.cpp, README.md, printOut.md (a script of the program log of running the algorithim)

UPDATE: the Source.cpp is broken, I commented close to the code that I was unable to make run unfortunately. I have the skeleton of what the broken portion looks like.

README.md (This is the current file you're on)
  - Give a basic description of the QuickSort.cpp

Source.cpp is an integer array quicksort program.
It comes with a greeting and instructions for inputs: 
"Hello and welcome to the Integer QuickSort Program!"
"Please type out any integers to input (Enter a character when you're done inputting)"

Once you finish inputting, enter a character and then the program will begin it's sorting.
We will also calculate our specific "cutoff".
If the arraylist.size() or the sublist.size() created from the arraylist is less than or equal to the cutoff, we will instead call insertionSort on that section.

This Integer QuickSort program uses the median of three technique to determine the pivot.

We will sort the three so that our pivot is at the middle of the array.
Then we will switch our pivot with our last value and proceed to sort the array.
We will begin to sort our values with the left side of the array containing values less than the pivot.
The right side of the array will contain the values greater than the pivot.

Then the program will call itself recursively through sublists based on the different sides of the pivot.

Once the intArray has been sorted, it will then be printed out by a helper function.

A sample of the Integer QuickSort program is provided through: printOut.md. (This will include my last best attempt)
