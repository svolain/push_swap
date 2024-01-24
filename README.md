# Push_Swap 42

This project is meant to sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. In order for the project to it has to manipulate various types of algorithms and use the most appropriate solution (out of many) for an
optimized data sorting.

You have at your disposal a set of integer values, 2 stacks, and a set of instructions
to manipulate both stacks.

## Instructions

The set of instructions that the program is allowed to use in order to sort the data, using two stacks (stack a & stack b). The purpose is to have the data sorted into stack a from smallest to biggest integer.

sa (swap a): Swap the first 2 elements at the top of stack a.
            Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
            Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
            Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
            Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
                The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
                The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
                        The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
                        The last element becomes the first one.

rrr : rra and rrb at the same time.

## Examples

The program is executed by giving it a set of integers as arguments, it will print the moves done in order to sort the integers.

```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```
Errors include for: some arguments aren’t integers, some arguments are
bigger than an integer and there are duplicate integers in the set.