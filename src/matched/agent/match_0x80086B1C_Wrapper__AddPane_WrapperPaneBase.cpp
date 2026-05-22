// 0x80086B1C Wrapper::AddPane(WrapperPaneBase (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 31,3; stw 4,0x8(1); bl _s80086B1C_0; cmpwi 3,0; bne 11f; addi 29,31,140; addi 27,1,8; lwz 30,0x4(29); lwz 0,0xc(29); cmpw 30,0; beq 0f; lwz 0,0x8(1); stw 0,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 11f; 0:; lwz 0,0x8c(31); li 9,1; stw 9,0x10(1); addi 11,1,16; subf 0,0,30; addi 9,1,12; srawi 3,0,2; stw 3,0xc(1); cmplwi 3,1; bge 1f; mr 9,11; 1:; lwz 0,0x0(9); add. 0,3,0; beq 3f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 2f; mr 3,28; bl _s80086B1C_1; mr 31,3; b 4f; 2:; mr 3,28; bl _s80086B1C_2; mr 31,3; b 4f; 3:; li 31,0; li 28,0; 4:; lwz 4,0x0(29); cmpw 30,4; beq 5f; subf 30,4,30; mr 3,31; mr 5,30; bl _s80086B1C_3; add 0,3,30; b 6f; 5:; mr 0,31; 6:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 8f; 7:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 7b; 8:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 10f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 9f; bl _s80086B1C_4; b 10f; 9:; bl _s80086B1C_5; 10:; add 0,28,31; stw 31,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 11:; lwz 3,0x8(1); lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s80086B1C_0();
extern "C" void _s80086B1C_1();
extern "C" void _s80086B1C_2();
extern "C" void _s80086B1C_3();
extern "C" void _s80086B1C_4();
extern "C" void _s80086B1C_5();
extern "C" void f_80086B1C() {}
