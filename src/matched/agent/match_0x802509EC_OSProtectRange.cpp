// 0x802509EC OSProtectRange (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 26,0x18(1); addi 26,3,0; cmplwi 26,4; bge 1f; add 3,4,5; addi 0,3,1023; rlwinm 27,4,0,0,21; rlwinm 29,0,0,0,21; addi 3,27,0; rlwinm 31,6,0,30,31; subf 4,27,29; bl _s802509EC_0; bl _s802509EC_1; lis 0,-32768; srw 30,0,26; addi 28,3,0; addi 3,30,0; bl _s802509EC_2; lis 3,-13312; addi 5,3,16384; rlwinm 3,26,2,0,29; rlwinm 0,27,22,16,31; sthx 0,5,3; rlwinm 4,29,22,16,31; add 3,5,3; sth 4,0x2(3); addi 4,5,16; rlwinm 6,26,1,0,30; li 0,3; lhz 5,0x10(5); slw 3,0,6; slw 0,31,6; andc 5,5,3; or 5,5,0; cmplwi 31,3; sth 5,0x0(4); beq 0f; mr 3,30; bl _s802509EC_3; 0:; mr 3,28; bl _s802509EC_4; 1:; lmw 26,0x18(1); lwz 0,0x34(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s802509EC_0();
extern "C" void _s802509EC_1();
extern "C" void _s802509EC_2();
extern "C" void _s802509EC_3();
extern "C" void _s802509EC_4();
extern "C" void f_802509EC() {}
