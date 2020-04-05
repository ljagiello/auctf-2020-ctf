# Reversing - Mr. Game and Watch

## Challenge
My friend is learning some wacky new interpreted language and different hashing algorithms. He's hidden a flag inside this program but I cant find it...

He told me to connect to challenges.auctf.com 30001 once I figured it out though.

Author: nadrojisk

## Solution
This is a reverse challenge. The file is Java class file. We can decompile class file in many ways for example via online service like: http://www.javadecompilers.com/

`secret_1` is just a string:
```
mr_game_and_watch.secret_1 = "d5c67e2fc5f5f155dff8da4bdc914f41";
```

If we check this string at https://crackstation.net/, we can find it's md5 hash of `masterchief`.

`secret_2` is calculated by function `decrypt`:
```
mr_game_and_watch.secret_2 = new int[] { 114, 118, 116, 114, 113, 114, 36, 37, 38, 38, 120, 121, 33, 36, 37, 113, 117, 118, 118, 113, 33, 117, 121, 37, 119, 34, 118, 115, 114, 120, 119, 114, 36, 120, 117, 120, 38, 114, 35, 118 };
mr_game_and_watch.key_2 = 64;
[...]
decrypt(mr_game_and_watch.secret_2, mr_game_and_watch.key_2)
[...]
```
We can print result of this function to get hash - `264212deff89ade15661a59e7b632872d858f2c6`. If we check this string at https://crackstation.net/, we can find it's SHA1 hash of `princesspeach`.

`secret_3` is calculated also by function `decrypt`:
```
mr_game_and_watch.secret_3 = new int[] { 268, 348, 347, 347, 269, 256, 348, 269, 256, 256, 344, 271, 271, 264, 266, 348, 257, 266, 267, 348, 269, 266, 266, 344, 267, 270, 267, 267, 348, 349, 349, 265, 349, 267, 256, 269, 270, 349, 268, 271, 351, 349, 347, 269, 349, 271, 257, 269, 344, 351, 265, 351, 265, 271, 346, 271, 266, 264, 351, 349, 351, 271, 266, 266 };
mr_game_and_watch.key_3 = 313;
[...]
decrypt(mr_game_and_watch.secret_3, mr_game_and_watch.key_3)
[...]
```

We can print result of this function to get hash - `5ebb49e499a6613e832e433a2722edd0d2947d56fdb4d684af0f06c631fdf633`. If we check this string at https://crackstation.net/, we can find it's SHA256 hash of `solidsnake`.

Result:
```
# nc challenges.auctf.com 30001
Welcome to the Land of Interpreted Languages!
If you are used to doing compiled languages this might be a shock... but if you hate assembly this is the place to be!

Unfortunately, if you hate Java, this may suck...
Good luck!

Let's try some hash cracking!! I'll go easy on you the first time. The first hash we are checking is this
	d5c67e2fc5f5f155dff8da4bdc914f41
Think you can crack it? If so give me the value that hashes to that!
	masterchief
Nice work! One down, two to go ...
This next one you don't get to see, if you aren't already digging into the class file you may wanna try that out!
	princesspeach
Nice work! Here's the last one...
	solidsnake
That's correct!
auctf{If_u_h8_JAVA_and_@SM_try_c_sharp_2922}
```

## Links
* https://crackstation.net/

## Flag
```
auctf{If_u_h8_JAVA_and_@SM_try_c_sharp_2922}
```
