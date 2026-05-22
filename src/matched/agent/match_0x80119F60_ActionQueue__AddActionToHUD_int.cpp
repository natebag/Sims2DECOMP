// 0x80119F60 ActionQueue::AddActionToHUD(int) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); lis 9,-32697; mr 30,3; addi 28,9,23428; mr 29,4; lwz 0,0x48(28); cmpwi 0,0; beq 0f; li 0,0; stb 0,0x2b0(30); 0:; lbz 0,0x2b0(30); cmpwi 0,0; bne 3f; lwz 9,0x2a8(30); lis 0,-13108; ori 0,0,52429; mr 3,30; add 9,9,29; mulhwu 0,9,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 9,0,9; mulli 9,9,68; add 31,30,9; mr 4,31; bl _s80119F60_0; cmpwi 3,0; beq 3f; mr 3,31; bl _s80119F60_1; addi 4,1,8; bl _s80119F60_2; mr. 27,3; bne 1f; lwz 0,0x8(1); cmpwi 0,0; beq 3f; 1:; mr 4,29; mr 3,30; bl _s80119F60_3; lwz 29,0x48(28); mr 28,3; cmpwi 29,0; beq 2f; lbz 30,0x2b1(30); mr 3,31; bl _s80119F60_4; mr 6,3; lwz 8,0x8(1); mr 3,29; mr 4,30; mr 5,31; mr 7,27; mr 9,28; bl _s80119F60_5; 2:; lwz 3,0x8(1); cmpwi 3,0; beq 3f; bl _s80119F60_6; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s80119F60_0();
extern "C" void _s80119F60_1();
extern "C" void _s80119F60_2();
extern "C" void _s80119F60_3();
extern "C" void _s80119F60_4();
extern "C" void _s80119F60_5();
extern "C" void _s80119F60_6();
extern "C" void f_80119F60() {}
