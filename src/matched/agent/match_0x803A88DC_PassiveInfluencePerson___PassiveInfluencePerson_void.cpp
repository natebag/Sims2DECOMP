// 0x803A88DC PassiveInfluencePerson::~PassiveInfluencePerson(void) (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 26,0x28(1); stw 0,0x44(1); lis 9,-32698; mr 31,3; addi 9,9,8888; mr 26,4; stw 9,0x0(31); addi 5,1,8; li 0,0; addi 8,5,8; stw 0,0x8(1); addi 7,31,8; stw 0,0x4(5); addi 6,7,8; stw 0,0x4(8); mr 30,5; lwz 0,0xc(31); addi 28,1,24; lwz 11,0x8(31); lwz 9,0x8(1); lwz 10,0xc(1); stw 11,0x8(1); stw 0,0xc(1); stw 9,0x8(31); lwz 0,0x4(8); stw 10,0xc(31); stw 0,0x24(1); lwz 9,0x8(7); lwz 0,0x4(6); stw 9,0x8(5); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x8(7); stw 0,0x4(6); lwz 0,0x4(5); lwz 9,0x8(1); cmpw 9,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(5); cmpwi 3,0; beq 3f; lwz 0,0xc(5); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 2f; bl _s803A88DC_0; b 3f; 2:; bl _s803A88DC_1; 3:; li 0,0; addi 8,30,8; stw 0,0x8(1); addi 7,31,40; stw 0,0x4(30); addi 27,31,8; stw 0,0x4(8); addi 29,31,32; lwz 0,0x20(31); lwz 9,0x24(31); lwz 11,0x8(1); lwz 10,0xc(1); stw 0,0x8(1); stw 9,0xc(1); stw 11,0x20(31); lwz 0,0x4(8); stw 10,0x24(31); stw 0,0x4(28); lwz 9,0x28(31); lwz 0,0x4(7); stw 9,0x8(30); stw 0,0x4(8); lwz 9,0x18(1); lwz 0,0x1c(1); stw 9,0x28(31); stw 0,0x4(7); lwz 0,0x4(30); lwz 9,0x8(1); cmpw 9,0; beq 5f; 4:; addi 9,9,12; cmpw 9,0; bne 4b; 5:; lwz 3,0x0(30); cmpwi 3,0; beq 7f; lwz 0,0xc(30); lis 9,-21846; ori 9,9,43691; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,12; cmplwi 4,128; ble 6f; bl _s803A88DC_2; b 7f; 6:; bl _s803A88DC_3; 7:; lwz 0,0x4(29); lwz 9,0x20(31); cmpw 9,0; beq 9f; 8:; addi 9,9,12; cmpw 9,0; bne 8b; 9:; lwz 3,0x0(29); cmpwi 3,0; beq 11f; lwz 0,0xc(29); lis 9,-21846; ori 9,9,43691; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,12; cmplwi 4,128; ble 10f; bl _s803A88DC_4; b 11f; 10:; bl _s803A88DC_5; 11:; lwz 0,0x4(27); lwz 9,0x8(31); cmpw 9,0; beq 13f; 12:; addi 9,9,8; cmpw 9,0; bne 12b; 13:; lwz 3,0x0(27); cmpwi 3,0; beq 15f; lwz 0,0xc(27); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 14f; bl _s803A88DC_6; b 15f; 14:; bl _s803A88DC_7; 15:; lis 9,-32698; andi. 0,26,1; addi 9,9,8984; stw 9,0x0(31); beq 16f; mr 3,31; bl _s803A88DC_8; 16:; lwz 0,0x44(1); mtspr 8,0; lmw 26,0x28(1); addi 1,1,64"
extern "C" void _s803A88DC_0();
extern "C" void _s803A88DC_1();
extern "C" void _s803A88DC_2();
extern "C" void _s803A88DC_3();
extern "C" void _s803A88DC_4();
extern "C" void _s803A88DC_5();
extern "C" void _s803A88DC_6();
extern "C" void _s803A88DC_7();
extern "C" void _s803A88DC_8();
extern "C" void f_803A88DC() {}
