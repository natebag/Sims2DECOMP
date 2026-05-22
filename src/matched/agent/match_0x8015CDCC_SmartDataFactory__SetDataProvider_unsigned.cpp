// 0x8015CDCC SmartDataFactory::SetDataProvider(unsigned (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 24,0x40(1); stw 0,0x64(1); mr 26,3; stw 4,0x8(1); addi 3,1,12; mr 25,6; mr 24,3; mr 4,5; bl _s8015CDCC_0; addi 27,26,4; li 0,0; addi 28,1,8; stw 0,0x18(1); lwz 30,0x4(27); lwz 31,0x4(30); 0:; cmpwi 31,0; beq 4f; lwz 9,0x10(31); li 29,0; lwz 0,0x0(28); cmplw 9,0; blt 1f; cmplw 0,9; blt 2f; addi 3,31,20; addi 4,28,4; bl _s8015CDCC_1; cmpwi 3,0; beq 2f; 1:; li 29,1; 2:; cmpwi 29,0; bne 3f; mr 30,31; lwz 31,0x8(30); b 0b; 3:; lwz 31,0xc(31); b 0b; 4:; lwz 0,0x4(27); cmpw 30,0; beq 7f; lwz 9,0x0(28); li 31,0; lwz 0,0x10(30); cmplw 9,0; blt 5f; cmplw 0,9; blt 6f; ori 3,28,4; addi 4,30,20; bl _s8015CDCC_2; cmpwi 3,0; beq 6f; 5:; li 31,1; 6:; cmpwi 31,0; beq 8f; 7:; lwz 30,0x4(27); 8:; stw 30,0x20(1); addi 31,26,4; stw 30,0x18(1); lwz 0,0x4(31); cmpw 30,0; stw 0,0x20(1); bne 9f; lwz 0,0x8(1); mr 4,24; addi 3,1,52; stw 0,0x30(1); bl _s8015CDCC_3; stw 25,0x3c(1); mr 4,31; addi 3,1,40; addi 5,1,48; bl _s8015CDCC_4; b 10f; 9:; stw 25,0x1c(30); 10:; lwz 0,0x64(1); mtspr 8,0; lmw 24,0x40(1); addi 1,1,96"
extern "C" void _s8015CDCC_0();
extern "C" void _s8015CDCC_1();
extern "C" void _s8015CDCC_2();
extern "C" void _s8015CDCC_3();
extern "C" void _s8015CDCC_4();
extern "C" void f_8015CDCC() {}
