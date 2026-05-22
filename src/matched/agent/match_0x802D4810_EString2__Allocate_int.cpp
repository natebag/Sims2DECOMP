// 0x802D4810 EString2::Allocate(int, (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,5; mr. 30,4; beq 2f; bl _s802D4810_0; mr 29,3; cmpw 30,29; ble 3f; addi 30,30,1; add 30,30,30; bl _s802D4810_1; mr 4,30; li 5,0; bl _s802D4810_2; mr. 30,3; beq 0f; lwz 4,0x0(31); addi 5,29,1; rlwinm 5,5,1,0,30; mr 3,30; crxor 6,6,6; bl _s802D4810_3; lwz 4,0x0(31); mr 3,31; bl _s802D4810_4; stw 30,0x0(31); b 3f; 0:; cmpwi 28,0; beq 1f; lwz 4,0x0(31); mr 3,31; bl _s802D4810_5; mr 3,31; bl _s802D4810_6; 1:; li 3,0; b 4f; 2:; mr 3,31; bl _s802D4810_7; 3:; li 3,1; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802D4810_0();
extern "C" void _s802D4810_1();
extern "C" void _s802D4810_2();
extern "C" void _s802D4810_3();
extern "C" void _s802D4810_4();
extern "C" void _s802D4810_5();
extern "C" void _s802D4810_6();
extern "C" void _s802D4810_7();
extern "C" void f_802D4810() {}
