IDEA::
Whenever a debugger sets a breakoint at entry of a function, the first byte of the 
function is writtent with 0xCC.Whenerever this instruction (INT 3) us executed it 
raises a software breakpoint.

First thing that comes to the mind to escape this break point is to skip executing 0xCC. 

But there are problems in just skipping the 0th byte. We need (in most cases)the orignal 
byte which debugger overwrote when BP was set.
