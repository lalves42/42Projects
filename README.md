<h1>42Projects</h1>

There are my school projects at 42.
All of them are made in C respecting [42 norm](https://github.com/lalves42/Files/blob/master/norm.pdf).  
You can find the subject and, if needed, a more detailed README in each project directory.


### [Libft](https://github.com/lalves42/42Projects/tree/master/Libft)
First project of the cursus, reimplement functions of C standard library in order to use them for the next projects.  
Allowed functions: `write`, `malloc` and `free`.


### [Fillit](https://github.com/lalves42/42Projects/tree/master/Fillit)
A program that takes between 1 and 26 Tetris pieces and fit them in the smallest square possible.


### [Get_next_line](https://github.com/lalves42/42Projects/tree/master/Gnl)
A function that reads on a fd line by line to parse a file. It handles reading on multiple file descriptors at the same time.


### [Printf](https://github.com/lalves42/42Projects/tree/master/Printf)
Reimplement the function printf.


### [Push_swap](https://github.com/lalves42/42Projects/tree/master/Push_Swap)
Push_swap is an algorithm that sorts as quickcly as possible a list of integers.  
There are two programs :
1. `push_swap` takes integers and displays the smallest list of specific instructions that sorts them.
2. `checker` takes same integers and checks if the instructions given correctly sort them.


### [Lem_in](https://github.com/lalves42/42Projects/tree/master/Lem_In)
A program that takes an ant farm and shows the fastest way to bring all ants room by room from start to end. A room can only contain one ant at a time, except start and end ones.

### [Corewar](https://github.com/lalves42/42Projects/tree/master/Corewar)
Corewar is a programming game in which two or more *battle programs* (called champions) compete for control of a virtual machine.  
There are two programs :
1. `asm` compilates a champion.s, written in an assembly language, to a bytecode readable by the virtual machine.
2. `corewar`, the virtual machine, loads champions bytecode in a 4096 bytes memory arena and run them until only one survive. A graphical interface allows you to see the state of the memory arena during the battle.