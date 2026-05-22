// 0x80317CC4 CalcShadowBounds(TArray<ESubModel, (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,3; li 11,0; lwz 26,0x4(25); mr 27,4; cmpw 11,26; bge 3f; 0:; mulli 9,11,24; lwz 0,0x0(25); addi 28,11,1; add 29,0,9; lwz 0,0x4(29); cmpwi 0,0; ble 2f; mr 31,0; li 30,0; 1:; lwz 3,0x0(29); mr 4,27; add 3,3,30; bl _s80317CC4_0; addi 30,30,112; addic. 31,31,-1; bne 1b; 2:; mr 11,28; cmpw 11,26; blt 0b; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s80317CC4_0();
extern "C" void f_80317CC4() {}
