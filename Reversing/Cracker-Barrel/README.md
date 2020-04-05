# Reversing - Cracker Barrel

## Challenge
I found a USB drive under the checkers board at cracker barrel. My friends told me not to plug it in but surely nothing bad is on it?

I found this file, but I can't seem to unlock it's secrets. Can you help me out?

Also.. once you think you've got it I think you should try to connect to challenges.auctf.com at port 30000 not sure what that means, but it written on the flash drive..

Author: nadrojisk

## Solution
This is a reverse challenge. With Ghidra we can decompile `cracker_barrel`.

Interesting function is `check`, where we do multiple keys check:
```
{
  int check_result;
  undefined8 uVar1;
  long in_FS_OFFSET;
  char local_2018 [8200];
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  puts("Give me a key!");
  fgets(local_2018,0x2000,stdin);
  remove_newline(local_2018);
  check_result = check_1(local_2018);
  if (check_result != 0) {
    puts("You have passed the first test! Now I need another key!");
    fgets(local_2018,0x2000,stdin);
    remove_newline(local_2018);
    check_result = check_2(local_2018);
    if (check_result != 0) {
      puts("Nice work! You\'ve passes the second test, we aren\'t done yet!");
      fgets(local_2018,0x2000,stdin);
      remove_newline(local_2018);
      check_result = check_3(local_2018);
      if (check_result != 0) {
        puts("Congrats you finished! Here is your flag!");
        uVar1 = 1;
        goto LAB_00101450;
      }
    }
  }
  [...]
}
```

Lets start with first key and function `check_1`:
```
undefined8 check_1(char *key1)
{
  int iVar1;
  undefined8 uVar2;

  iVar1 = strcmp(key1,"starwars");
  if (iVar1 == 0) {
    iVar1 = strcmp(key1,"startrek");
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
```
The logic is very simple and return needs to be different than `0`. The key we're looking for is `starwars`.

Now lets look into function `check_2`, where we check second key:
```
ulong check_2(char *key2)

{
  int iVar1;
  size_t sVar2;
  char *__s1;
  int local_20;

  sVar2 = strlen(key2);
  iVar1 = (int)sVar2;
  __s1 = (char *)malloc((long)(iVar1 + 1) << 3);
  local_20 = 0;
  while (local_20 < iVar1) {
    __s1[local_20] = "si siht egassem terces"[(iVar1 + -1) - local_20];
    local_20 = local_20 + 1;
  }
  iVar1 = strcmp(__s1,key2);
  return (ulong)(iVar1 == 0);
}
```
Again the logic is very simple and return needs to be different than `0`. There is also an innteresting twist here.

The logic reverse the string `si siht egassem terces` and compare with `key2`. The key we're looking for is `secret message this is`.

There is also another solution, if we pass an empty string as `key2`. `strlen(key2)` will be `0`, so `sVar2` will be `0` and `iVar1` will be `0`.

Next while loop will be skipped and we will return `0`, because `iVar1` is `0`.

Lets look into last function `check_3`, where we check third key:
```
ulong check_3(char *key3)

{
  bool bVar1;
  size_t sVar2;
  void *pvVar3;
  long in_FS_OFFSET;
  int local_5c;
  int local_54;
  int local_48 [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  long local_20;

  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_48[0] = 0x7a;
  local_48[1] = 0x21;
  local_48[2] = 0x21;
  local_48[3] = 0x62;
  local_38 = 0x36;
  local_34 = 0x7e;
  local_30 = 0x77;
  local_2c = 0x6e;
  local_28 = 0x26;
  local_24 = 0x60;
  sVar2 = strlen(key3);
  pvVar3 = malloc(sVar2 << 2);
  local_5c = 0;
  while (sVar2 = strlen(key3), (ulong)(long)local_5c < sVar2) {
    *(uint *)((long)pvVar3 + (long)local_5c * 4) = (int)key3[local_5c] + 2U ^ 0x14;
    local_5c = local_5c + 1;
  }
  bVar1 = false;
  local_54 = 0;
  while (sVar2 = strlen(key3), (ulong)(long)local_54 < sVar2) {
    if (*(int *)((long)pvVar3 + (long)local_54 * 4) != local_48[local_54]) {
      bVar1 = true;
    }
    local_54 = local_54 + 1;
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)!bVar1;
}
```
We can analyze how we compare `key3` with an actual secret, but we can also again use the same trick from `check_2` and pass an empty string.

`sVar2` will be `0`, because `strlen(key3)` will be `0`. First `while` we skip, `bVar1` by default is `false` and we skip second `while`. Result will be `!bVar1` so `true`.

Result:
```
# nc challenges.auctf.com 30000
Give me a key!
starwars
You have passed the first test! Now I need another key!

Nice work! You've passes the second test, we aren't done yet!

Congrats you finished! Here is your flag!
auctf{w3lc0m3_to_R3_1021}
```

## Links
* https://ghidra-sre.org/

## Flag
```
auctf{w3lc0m3_to_R3_1021}
```
