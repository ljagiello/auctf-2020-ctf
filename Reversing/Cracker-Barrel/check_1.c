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
