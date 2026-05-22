// 0x803C6E80 void (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; lis 9,-21846; subf 0,3,29; ori 9,9,43691; mullw 0,0,9; mr 31,5; srawi 0,0,2; cmpwi 0,16; ble 0f; addi 30,3,192; mr 4,30; bl _s803C6E80_0; mr 3,30; mr 4,29; mr 6,31; li 5,0; bl _s803C6E80_1; b 1f; 0:; mr 4,29; mr 5,31; bl _s803C6E80_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803C6E80_0();
extern "C" void _s803C6E80_1();
extern "C" void _s803C6E80_2();
extern "C" void f_803C6E80() {}
