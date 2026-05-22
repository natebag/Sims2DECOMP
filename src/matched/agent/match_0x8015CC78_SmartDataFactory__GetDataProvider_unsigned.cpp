// 0x8015CC78 SmartDataFactory::GetDataProvider(unsigned (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 24,0x20(1); stw 0,0x44(1); mr 25,3; mr 24,4; mr 26,5; stw 24,0x8(1); addi 3,1,12; mr 4,26; addi 28,1,8; addi 27,25,4; bl _s8015CC78_0; lwz 31,0x4(27); lwz 30,0x4(31); 0:; cmpwi 30,0; beq 4f; lwz 9,0x10(30); li 29,0; lwz 0,0x0(28); cmplw 9,0; blt 1f; cmplw 0,9; blt 2f; addi 3,30,20; addi 4,28,4; bl _s8015CC78_1; cmpwi 3,0; beq 2f; 1:; li 29,1; 2:; cmpwi 29,0; bne 3f; mr 31,30; lwz 30,0x8(31); b 0b; 3:; lwz 30,0xc(30); b 0b; 4:; lwz 0,0x4(27); cmpw 31,0; beq 7f; lwz 9,0x0(28); li 30,0; lwz 0,0x10(31); cmplw 9,0; blt 5f; cmplw 0,9; blt 6f; ori 3,28,4; addi 4,31,20; bl _s8015CC78_2; cmpwi 3,0; beq 6f; 5:; li 30,1; 6:; cmpwi 30,0; beq 8f; 7:; lwz 31,0x4(27); 8:; lwz 0,0x8(25); cmpw 31,0; bne 11f; lhz 0,0x4(26); cmpwi 0,0; bne 9f; lis 0,3023; ori 0,0,30787; cmpw 24,0; beq 10f; 9:; addi 30,1,24; lwz 4,0x0(26); li 5,0; mr 3,30; bl _s8015CC78_3; lis 4,3023; mr 3,25; mr 5,30; ori 4,4,30787; bl _s8015CC78_4; b 12f; 10:; li 3,4; b 12f; 11:; lwz 3,0x1c(31); 12:; lwz 0,0x44(1); mtspr 8,0; lmw 24,0x20(1); addi 1,1,64"
extern "C" void _s8015CC78_0();
extern "C" void _s8015CC78_1();
extern "C" void _s8015CC78_2();
extern "C" void _s8015CC78_3();
extern "C" void _s8015CC78_4();
extern "C" void f_8015CC78() {}
