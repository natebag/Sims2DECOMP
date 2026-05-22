// 0x801F7550 INVTarget::ExitFloorTilingMode(bool) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 0,0; mr 30,4; stw 0,0x32e4(31); stw 0,0x32e8(31); bl _s801F7550_0; stw 30,0x32ec(31); cmpwi 30,0; beq 0f; mr 3,31; bl _s801F7550_1; bl _s801F7550_2; lwz 4,0x84(31); bl _s801F7550_3; mr 4,30; mr 3,31; bl _s801F7550_4; 0:; addi 9,31,172; lwz 11,0xac(31); lwz 0,0x4(9); mr 28,9; mr 10,11; li 29,0; subf 0,11,0; srawi. 9,0,3; ble 4f; li 30,0; 1:; lwz 11,0xac(31); add 9,11,30; lwz 6,0x4(9); cmpwi 6,0; ble 2f; lwzx 5,11,30; li 4,3; lwz 3,0x90(31); bl _s801F7550_5; b 3f; 2:; lwzx 5,11,30; neg 6,6; lwz 3,0x90(31); li 4,3; bl _s801F7550_6; 3:; lwz 9,0xac(31); addi 29,29,1; lwz 0,0x4(28); addi 30,30,8; mr 10,9; subf 0,9,0; srawi 0,0,3; cmpw 29,0; blt 1b; 4:; mr 9,10; lwz 0,0x4(28); cmpw 9,0; beq 6f; 5:; addi 10,10,8; cmpw 10,0; bne 5b; 6:; stw 9,0x4(28); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801F7550_0();
extern "C" void _s801F7550_1();
extern "C" void _s801F7550_2();
extern "C" void _s801F7550_3();
extern "C" void _s801F7550_4();
extern "C" void _s801F7550_5();
extern "C" void _s801F7550_6();
extern "C" void f_801F7550() {}
