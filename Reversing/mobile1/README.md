# Reversing - mobile1

## Challenge
My friend sent this file to me and said that there was a flag in it. Can you help me?

https://drive.google.com/open?id=1iglx4cQ_iVi1RABBa1eF0OXcOGECjVLy

Author: kensocolo

## Solution
`mobile1.ipa` is a zip archive:
```
# file mobile1.ipa
mobile1.ipa: iOS App Zip archive data, at least v2.0 to extract
```
We can uncompress archive and check what's inside:
```
# unzip mobile1.ipa
Archive:  mobile1.ipa
   creating: Payload/
   creating: Payload/mobile1.app/
   creating: Payload/mobile1.app/_CodeSignature/
  inflating: Payload/mobile1.app/_CodeSignature/CodeResources
   creating: Payload/mobile1.app/Base.lproj/
   creating: Payload/mobile1.app/Base.lproj/Main.storyboardc/
  inflating: Payload/mobile1.app/Base.lproj/Main.storyboardc/UIViewController-BYZ-38-t0r.nib
  inflating: Payload/mobile1.app/Base.lproj/Main.storyboardc/BYZ-38-t0r-view-8bC-Xf-vdC.nib
  inflating: Payload/mobile1.app/Base.lproj/Main.storyboardc/Info.plist
   creating: Payload/mobile1.app/Base.lproj/LaunchScreen.storyboardc/
  inflating: Payload/mobile1.app/Base.lproj/LaunchScreen.storyboardc/01J-lp-oVM-view-Ze5-6b-2t3.nib
  inflating: Payload/mobile1.app/Base.lproj/LaunchScreen.storyboardc/UIViewController-01J-lp-oVM.nib
  inflating: Payload/mobile1.app/Base.lproj/LaunchScreen.storyboardc/Info.plist
  inflating: Payload/mobile1.app/mobile1
  inflating: Payload/mobile1.app/Info.plist
  inflating: Payload/mobile1.app/PkgInfo
# grep -ir ctf Payload/
Binary file Payload//mobile1.app/Base.lproj/Main.storyboardc/BYZ-38-t0r-view-8bC-Xf-vdC.nib matches
Binary file Payload//mobile1.app/mobile1 matches
Binary file Payload//mobile1.app/Info.plist matches
# strings Payload//mobile1.app/Base.lproj/Main.storyboardc/BYZ-38-t0r-view-8bC-Xf-vdC.nib | grep ctf
auctf{i0s_r3v3rs1ng_1s_1nt3r3st1ng}
auctf{i0s_r3v3rs1ng_1s_1nt3r3st1ng}
```

## Flag
```
auctf{i0s_r3v3rs1ng_1s_1nt3r3st1ng}
```
