// 0x803C0FA0 CTilePt (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; mr 31,3; lis 9,-21846; subf 0,31,28; ori 9,9,43691; mr 30,5; mullw 0,0,9; srawi. 29,0,2; ble 1f; 0:; mr 3,31; mr 4,30; bl _s803C0FA0_0; cmpwi 3,0; bne 4f; addi 31,31,3; mr 4,30; mr 3,31; bl _s803C0FA0_1; cmpwi 3,0; bne 4f; addi 31,31,3; mr 4,30; mr 3,31; bl _s803C0FA0_2; cmpwi 3,0; bne 4f; addi 31,31,3; mr 4,30; mr 3,31; bl _s803C0FA0_3; cmpwi 3,0; bne 4f; addi 31,31,3; addic. 29,29,-1; bgt 0b; 1:; lis 0,-21846; subf 9,31,28; ori 0,0,43691; mullw 9,9,0; cmpwi 9,1; beq 3f; ble 5f; cmpwi 9,2; beq 2f; cmpwi 9,3; bne 5f; mr 3,31; mr 4,30; bl _s803C0FA0_4; cmpwi 3,0; bne 4f; addi 31,31,3; 2:; mr 3,31; mr 4,30; bl _s803C0FA0_5; cmpwi 3,0; bne 4f; addi 31,31,3; 3:; mr 4,30; mr 3,31; bl _s803C0FA0_6; cmpwi 3,0; beq 5f; 4:; mr 3,31; b 6f; 5:; mr 3,28; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803C0FA0_0();
extern "C" void _s803C0FA0_1();
extern "C" void _s803C0FA0_2();
extern "C" void _s803C0FA0_3();
extern "C" void _s803C0FA0_4();
extern "C" void _s803C0FA0_5();
extern "C" void _s803C0FA0_6();
extern "C" void f_803C0FA0() {}
