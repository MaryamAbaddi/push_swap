*This project has been created as part
of the 42 curriculum by mabaddi*

# Description
Push_swap is a core algorithmic project at 42 School that focuses on sorting data efficiently using a very limited set of operations and two stacks.

🎯 Project Goal
The objective of push_swap is to sort a list of integers in ascending order using:

Stack A (initially contains all numbers)
Stack B (initially empty)
You must output the smallest possible sequence of operations to sort Stack A.

📦 Rules & Constraints
You are not allowed to use standard sorting functions.
You can only manipulate data using predefined operations.
The program must be efficient in both logic and number of moves.
All inputs must be validated (duplicates, non-numeric values, integer overflow).


🔁 Allowed Operations
Swap
sa – swap the first two elements of stack A
sb – swap the first two elements of stack B
ss – sa and sb at the same time
Push
pa – push top of B to A
pb – push top of A to B
Rotate
ra – rotate stack A upwards
rb – rotate stack B upwards
rr – ra and rb
Reverse Rotate
rra – rotate stack A downwards
rrb – rotate stack B downwards

# instruction 
se two stacks: A and B
Stack A starts full, stack B empty
Sort numbers in ascending order
Use only allowed operations
Print only the operations
One operation per line
If already sorted → print nothing
If error → print Error

Check input:
Only numbers
No duplicates

Inside INT_MIN / INT_MAX
Sorting:
2 numbers → swap if needed
3 numbers → hardcoded logic
4–5 numbers → push small ones to B, sort A, push back
Big input → use radix sort

Rules:
No printf except operations
No sort functions
No memory leaks

# Resources
42 Intra – push_swap subject
libft documentation
📚 Algorithms
Radix Sort (Binary)
YouTube: “Radix Sort explained visually”
Stack sorting logic
Search: “push_swap radix sort 42”

# Ai usage 
understand the project requirements, sorting strategies




