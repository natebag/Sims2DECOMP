// 0x8014A544 RotateWallBits(unsigned (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,4,0,27; subfic 4,4,8; or 0,0,3; srawi 4,4,1; sraw 0,0,4; rlwinm 3,0,0,24,31"
extern "C" int f_8014A544() {}
