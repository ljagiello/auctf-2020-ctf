# Reversing - TI-83 Beta

## Challenge
Hey I'm building a new calculator! I hid a flag inside it, think you can find it?

Author: nadrojisk

## Solution
This is a reverse challenge. With Ghidra we can decompile `ti_83_beta.exe`.

Interesting function is:
```
void FUN_00412560(void)

{
  int iVar1;
[...]
  iVar1 = 0x30;
  puVar2 = local_c4;
  while (iVar1 != 0) {
    iVar1 = iVar1 + -1;
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uStack239 = 0x75;
  uStack238 = 99;
  uStack237 = 0x74;
  iStack236 = 0x6f6f7b66;
  uStack232 = 0x70;
  uStack231 = 0x73;
  uStack230 = 0x5f;
  uStack229 = 100;
  uStack228 = 0x69;
  uStack227 = 100;
  uStack226 = 0x5f;
  uStack225 = 0x69;
  uStack224 = 0x5f;
  uStack223 = 100;
  uStack222 = 0x6f;
  uStack221 = 0x5f;
  uStack220 = 0x74;
  uStack219 = 0x68;
  uStack218 = 0x74;
  uStack217 = 0x7d;
  uStack216 = 10;
  uStack215 = 0;
  thunk_FUN_004123b0(&stack0xffffff10,0x61);
  *in_FS_OFFSET = **(undefined4 **)*in_FS_OFFSET;
  *(undefined4 *)(iStack236 + 0xd0) = 0x412640;
  thunk_FUN_00412840();
  return;
}
```

If we convert:
```
[0x75, 0x63, 0x74, 0x66, 0x7b, 0x6f, 0x6f, 0x70, 0x73, 0x5f, 0x64, 0x69, 0x64, 0x5f, 0x69, 0x5f, 0x64, 0x6f, 0x5f, 0x74, 0x68, 0x74, 0x7d]
```
to ascii we will get:
```
uctf{oops_did_i_do_tht}
```

## Links
* https://ghidra-sre.org/

## Flag
```
auctf{oops_did_i_do_tht}
```
