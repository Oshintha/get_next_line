<p align=center>
  <img src="https://github.com/miladrahmat/42-badges/blob/master/badges/get_next_linem.png"> <img width=15% src="https://github.com/user-attachments/assets/1f7290fc-1559-453c-ab19-e7acd1c7fd1e"> 
</p>


# get_next_line
The get_next_line function is a utility designed to read and return the next line from a file descriptor. It is particularly useful for reading text files line-by-line, making it a fundamental function for many applications dealing with file I/O operations. This function handles both normal text files and larger input streams, efficiently managing memory to ensure seamless operation.

## Features
* Line-by-Line Reading: Efficiently reads and returns one line at a time from a file descriptor.
* Handles Multiple Calls: Remembers its position between calls, allowing for continuous reading across multiple function calls.
* Buffer Management: Utilizes a buffer to manage data read from the file, minimizing the number of read operations and enhancing performance.
* Memory Efficiency: Ensures that no memory leaks occur by carefully managing dynamically allocated memory.

### Function Signature

char *get_next_line(int fd);

## Parameters

* fd: The file descriptor from which to read.

## Return Value
* Returns a null-terminated string representing the next line from the file descriptor, including the newline character if present.
* Returns NULL if there is an error or if the end of the file is reached and no more lines are available.

### Example Usage
Here's an example of how you might use get_next_line in a simple program:

![image](https://github.com/user-attachments/assets/2406c7aa-6ca1-4d78-a29b-58d1b312c5a3)

 
## Implementation Details
The get_next_line function relies on several helper functions to manage its operations:

* read_left_str(int fd, char *left_str): Reads data from the file descriptor into a buffer and appends it to left_str until a newline character is encountered or the end of the file is reached.
* get_line(char *left_str): Extracts the next line from left_str, up to and including the newline character.
* new_left_str(char *left_str): Updates left_str to remove the line that has been extracted, preparing it for the next read operation.

### Integration
To integrate get_next_line into your project, include the following files:

* get_next_line.c
* get_next_line.h
* get_next_line_utils.c

Ensure these files are compiled and linked with your project. For example, if you are using gcc, you might compile your project with:

* gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -o my_program my_program.c get_next_line.c get_next_line_utils.c

## Notes
* Buffer Size: The BUFFER_SIZE macro determines the size of the buffer used during read operations. You can adjust this value as needed to optimize performance based on your specific use case.
* Error Handling: Make sure to handle possible errors, such as failing to open a file or running out of memory, appropriately in your application.
