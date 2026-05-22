// 0x803AC3D0 void (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 29,5; lwz 9,0x0(30); addi 4,1,8; lwz 0,0x4(30); li 5,1; mr 28,6; mr 3,29; subf 0,9,0; srawi 0,0,2; stw 0,0x8(1); bl _s803AC3D0_0; lwz 4,0x4(30); lwz 0,0x0(30); lwz 5,0x8(1); subf 0,0,4; srawi 9,0,2; subf. 0,5,9; bge 0f; li 0,0; subf 5,9,5; stw 0,0xc(1); mr 3,30; addi 6,1,12; bl _s803AC3D0_1; b 3f; 0:; ble 3f; rlwinm 0,0,2,0,29; subf 0,0,4; lwz 11,0x4(30); mr 9,0; cmpw 0,11; beq 2f; 1:; addi 9,9,4; cmpw 9,11; bne 1b; 2:; stw 0,0x4(30); 3:; lwz 31,0x0(30); b 5f; 4:; mr 3,31; mr 4,29; mr 5,28; addi 31,31,4; bl _s803AC3D0_2; 5:; lwz 0,0x4(30); cmpw 31,0; bne 4b; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s803AC3D0_0();
extern "C" void _s803AC3D0_1();
extern "C" void _s803AC3D0_2();
extern "C" void f_803AC3D0() {}
