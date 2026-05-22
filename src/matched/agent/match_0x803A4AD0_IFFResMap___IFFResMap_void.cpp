// 0x803A4AD0 IFFResMap::~IFFResMap(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 27,4; lwz 29,0x4(28); lwz 11,0x0(28); cmpw 11,29; beq 5f; lis 31,-17874; ori 31,31,35747; 0:; lwz 9,0x0(11); addi 30,11,24; lwz 0,0x4(11); mr 3,9; cmpw 9,0; beq 2f; 1:; addi 9,9,88; cmpw 9,0; bne 1b; 2:; cmpwi 3,0; beq 4f; lwz 0,0xc(11); subf 0,3,0; mullw 0,0,31; srawi 0,0,3; mulli 4,0,88; cmplwi 4,128; ble 3f; bl _s803A4AD0_0; b 4f; 3:; bl _s803A4AD0_1; 4:; mr 11,30; cmpw 11,29; bne 0b; 5:; lwz 3,0x0(28); cmpwi 3,0; beq 7f; lwz 0,0xc(28); lis 9,-21846; ori 9,9,43691; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 4,0,24; cmplwi 4,128; ble 6f; bl _s803A4AD0_2; b 7f; 6:; bl _s803A4AD0_3; 7:; andi. 0,27,1; beq 8f; mr 3,28; bl _s803A4AD0_4; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803A4AD0_0();
extern "C" void _s803A4AD0_1();
extern "C" void _s803A4AD0_2();
extern "C" void _s803A4AD0_3();
extern "C" void _s803A4AD0_4();
extern "C" void f_803A4AD0() {}
