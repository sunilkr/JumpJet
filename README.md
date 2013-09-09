IDEA::
Whenever a debugger sets a breakpoint at entry of a function, the first byte of the 
function is written with 0xCC. Whenever this instruction (INT 3) is executed it 
raises a software breakpoint.

First thing that comes to the mind to escape this break point is to skip executing 0xCC. 

But there are problems in just skipping the 0th byte. We need (in most cases)the original byte which debugger overwrote when BP was set.

Solution::
Resolve the VA to file-offset and copy a few bytes from original function code. Write it to executable memory, execute it from there and and the end make a jump to the original code.
