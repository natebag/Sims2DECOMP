// 0x800B8EE8 cGZSndSys::~cGZSndSys(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32698; mr 30,3; addi 9,9,-3928; mr 27,4; stw 9,0x0(30); bl _s800B8EE8_0; addi 28,30,4; li 0,0; mr 3,30; stw 0,-24468(13); li 26,0; stw 0,0x408(30); stw 0,0x404(30); bl _s800B8EE8_1; lwz 11,-22652(13); lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; bl _s800B8EE8_2; li 9,0; 0:; rlwinm 11,9,2,0,29; addi 29,9,1; lwzx 31,28,11; cmpwi 31,0; beq 3f; stwx 26,28,11; 1:; mr 3,31; lwz 31,0x18(31); cmpwi 3,0; beq 2f; li 4,3; bl _s800B8EE8_3; 2:; cmpwi 31,0; bne 1b; 3:; mr 9,29; cmpwi 9,255; ble 0b; mr 3,30; mr 4,27; bl _s800B8EE8_4; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800B8EE8_0();
extern "C" void _s800B8EE8_1();
extern "C" void _s800B8EE8_2();
extern "C" void _s800B8EE8_3();
extern "C" void _s800B8EE8_4();
extern "C" void f_800B8EE8() {}
