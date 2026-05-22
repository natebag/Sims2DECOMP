// 0x802D4AC4 EString2::Mid(int, (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,6; mr 31,3; cmpwi 29,-1; bne 0f; lwz 0,0x0(4); add 4,5,5; add 4,4,0; bl _s802D4AC4_0; b 1f; 0:; lwz 0,0x0(4); addi 30,1,8; add 4,5,5; mr 3,30; add 4,4,0; bl _s802D4AC4_1; mr 3,31; mr 4,30; mr 5,29; bl _s802D4AC4_2; lwz 4,0x8(1); mr 3,30; bl _s802D4AC4_3; 1:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802D4AC4_0();
extern "C" void _s802D4AC4_1();
extern "C" void _s802D4AC4_2();
extern "C" void _s802D4AC4_3();
extern "C" void f_802D4AC4() {}
