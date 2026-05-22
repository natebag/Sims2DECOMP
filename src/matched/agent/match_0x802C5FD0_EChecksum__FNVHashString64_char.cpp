// 0x802C5FD0 EChecksum::FNVHashString64(char (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); stmw 30,0x8(1); mr 31,3; lbz 0,0x0(31); mr 3,5; mr 4,6; cmpwi 0,0; beq 1f; li 30,435; 0:; mulhwu 11,4,30; rlwinm 6,4,8,0,23; extsb 0,0; mulli 5,3,435; mr 10,0; srawi 9,0,31; mullw 12,4,30; add 11,11,6; lbzu 0,0x1(31); add 11,11,5; cmpwi 0,0; mr 3,11; mr 4,12; xor 7,3,9; xor 8,4,10; mr 3,7; mr 4,8; bne 0b; 1:; lmw 30,0x8(1); addi 1,1,16"
extern "C" int f_802C5FD0() {}
