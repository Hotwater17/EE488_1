Indexing and Searching Engine 
by Michal Gorywoda, 20204787

### BUILD ###
To build the project, execute the following command in the project directory:

$ make all

If compiled successfully, "search" file should appear in the directory.

To clean, execute this command:

$ make clean


### RUNNING THE PROGRAM ###

To run the program with sample text files provided in docs directory, type the following command in main directory:

$ ./search docs/

In total, five text files should be opened. 
Then you will be prompted for a word to search. For example, type:

search Caesar

The file names along with the lines in which the word has occured, will be displayed.

### POTENTIAL ISSUES ###

-For the first opened file, the line number may differ by 1.

-If the directory path will not have a slash, the program might not recognize the path.

-You must follow the specified format when prompted for a word. 
The program will be expectng two input words, first being "search" and the second being the word the user is looking for.
