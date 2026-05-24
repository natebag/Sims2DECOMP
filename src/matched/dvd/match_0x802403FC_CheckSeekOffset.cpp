// 0x802403FC CheckSeekOffset (32B)
//
// Bounds-check helper: returns 0x52100 if seek > 0x5705FFFF, else 0.
// 8 instructions:
//   lis r0, 22277; ori r0, r0, 65535          ; r0 = 0x5705FFFF
//   cmpw r3, r0
//   lis r3, 5; ori r3, r3, 8448                ; r3 = 0x00052100
//   bgtlr
//   li r3, 0
//   blr

extern "C" int CheckSeekOffset(int seek) {
    if (seek > 0x5705FFFF) return 0x52100;
    return 0;
}
