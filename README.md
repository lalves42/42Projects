<h1>42Projects</h1>
There are my school projects at 42. All of them are made in C respecting : [42 norm](https://github.com/lalves42/Files/blob/master/norm.pdf).

If you want more infos about a project, all the subjects are in their directories.

[42 norm](https://github.com/lalves42/Files/blob/master/norm.pdf).

### Libft
First project of the cursus, reimplement functions of C standard library in order to use them for the next projects.
Allowed functions: `write`, `malloc` and `free`.

### Fillit
A program that takes between 1 and 26 Tetris pieces and fit them in the smallest square possible.

### Get_next_line
A function that reads on a fd line by line to parse a file. It handles reading on multiple fd at the same time.

### Printf
Reimplement the function printf.

### Push_swap
Two programs :
1. The first one takes integers and displays the smallest list of specific instructions that sort them.
2. The second one takes same integers and checks if the instructions given correctly sort them.

Push swap has at his disposal 2 stacks and the following instructions :
* `sa / sb / ss`      Swap the first 2 elements at the top of stack a / b / both.
* `ra / rb / rr`      Shift up all element of stack a / b / both by 1. The first element becomes the last one.
* `rra / rrb / rrr`   Shift down all element of stack a / b / both by 1. The last element becomes the first one.
* `pa / pb`           Take the first element of a / b and put it at the top of the other stack.

At start a represent the integers given and b is empty, at end integers must be sorted on a.

### Lem_in


### Corewar