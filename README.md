
# Pipex
Pipex is a project that emulates the behavior of shell piping in a bash environment. It replicates the functionality of the following shell command:
```
$> < file1 cmd1 | cmd2 > file2
```
This program creates a pipeline between two commands, where the output of the first command (cmd1) is used as the input for the second command (cmd2). The result is then redirected to an output file (file2).

Arguments:
- **file1**: The input file from which data is read.
- **cmd1**: The first shell command to execute.
- **cmd2**: The second shell command to execute.
- **file2**: The output file where the final result is written.

## Compilation
To compile pipex:

1. Clone the repository:
```
git clone git@github.com:k2matu/pipex.git
````
2. Navigate into the directory:
```
cd pipex
```
3. Compile the program using make:
```
make
```
4. This will produce an executable named pipex.

## Usage
After compilation, you can use the program as follows:
```
./pipex file1 cmd1 cmd2 file2
```
Example:
```
./pipex infile "ls -l" "wc -l" outfile
```
Should behave like:
```
< infile ls -l | wc -l > outfile
```

## Notes
Ensure that cmd1 and cmd2 are valid shell commands and available in your system's PATH.
