// 0x8004E6A0 OtherSide(unsigned (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,5; mr 31,6; bl _s8004E6A0_0; sth 3,0x0(31); mr 4,3; sth 3,0x0(30); lwz 3,-21472(13); cmpwi 3,0; beq 0f; li 0,0; rlwinm 4,4,0,16,31; ori 0,0,65530; cmplw 4,0; bgt 0f; bl _s8004E6A0_1; mr. 3,3; beq 0f; lhz 0,0x2(3); sth 0,0x0(31); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8004E6A0_0();
extern "C" void _s8004E6A0_1();
extern "C" void f_8004E6A0() {}
