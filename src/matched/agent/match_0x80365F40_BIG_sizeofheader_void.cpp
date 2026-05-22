// 0x80365F40 BIG_sizeofheader(void (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; bl _s80365F40_0; cmpwi 3,1; bne 0f; lbz 9,0x2(31); lbz 0,0x3(31); rlwinm 9,9,8,0,23; or 9,9,0; addi 30,9,4; b 1f; 0:; blt 1f; cmpwi 3,3; bgt 1f; addi 11,31,12; lbz 0,0xc(31); lbz 9,0x1(11); lbz 10,0x2(11); rlwinm 0,0,24,0,7; rlwinm 9,9,16,0,15; lbz 8,0x3(11); or 0,0,9; rlwinm 10,10,8,0,23; or 0,0,10; or 30,0,8; 1:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80365F40_0();
extern "C" void f_80365F40() {}
