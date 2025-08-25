
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

## Prerequisites
- A C compiler (e.g., `gcc` or `clang`)
- `make`

## Compilation
To compile pipex:

1. Clone the repository:
```
git clone git@github.com:k2matu/42-pipex.git pipex
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
#### Example:
1. Ensure infile exists in the same directory as your compiled program.
#### e.g., infile:
```
Example content:
The names "John Doe" for males, "Jane Doe" or "Jane Roe" for females, or "Jonnie Doe" and "Janie Doe" for children, or just "Doe" non-gender-specifically are used as placeholder names for a party whose true identity is unknown or must be withheld in a legal action, case, or discussion.
The names are also used to refer to acorpse or hospital patient whose identity is unknown.
This practice is widely used in the United States and Canada, but is rarely used in other English-speaking countries including the United Kingdom itself, from where the use of "John Doe" in a legal context originates.
The names Joe Bloggs or John Smith are used in the UK instead, as well as in Australia and New Zealand.
```
```
./pipex infile "ls -l" "wc -l" outfile
```
Should behave like:
```
< infile ls -l | wc -l > outfile
```
Output:
```
18
```

## Notes
Ensure that cmd1 and cmd2 are valid shell commands and available in your system's PATH.
