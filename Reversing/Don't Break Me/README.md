# Reversing - Don't Break Me!

## Challenge
I've been working on my anti-reversing lately. See if you can get this flag!

Connect at challenges.auctf.com 30005

Author: nadrojisk

## Solution
In this challenge binary checks if you use debugger like `gdb`.  To avoid that
I've used Binary Ninja and NOP all calls to function `debugger_check`.

New modified binary I could debug with `gdb`.

Interesting call where we should breakpoint debugger is:
```
   0x56556356 <+228>: call   0x56556030 <strcmp@plt>
```
It seems to be the place where we compare our key with correct key.

Before we get to this step the key provided by user is encrypted by function
`encrypt`.

Let's see how that works:
input : `ABCDEFGHIJKLMNOPQRSTUWXYZ`
output: `MDULCTKBSJARIZQHYPGXOWNEV`

Now, we know encrypted key is `SASRRWSXBIEBCMPX`, if we use output
to construct input result is:

key - `IKILLWITHMYHEART`

## Links
* https://binary.ninja/

## Flag
```
auctf{static_or_dyn@mIc?_12923}
```
