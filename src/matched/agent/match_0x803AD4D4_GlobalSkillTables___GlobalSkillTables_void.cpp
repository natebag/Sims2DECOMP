// 0x803AD4D4 GlobalSkillTables::~GlobalSkillTables(void) (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 24,0x10(1); stw 0,0x34(1); stw 12,0xc(1); mr 31,3; mr 24,4; lwz 3,0x3c(31); li 30,0; bl _s803AD4D4_0; lwz 3,0x38(31); stw 30,0x3c(31); bl _s803AD4D4_1; stw 30,0x38(31); lwz 3,0x34(31); bl _s803AD4D4_2; addic. 29,31,40; stw 30,0x34(31); beq 1f; addi 30,31,52; cmpw 29,30; beq 1f; li 28,0; 0:; lwzu 3,-4(30); bl _s803AD4D4_3; stw 28,0x0(30); cmpw 29,30; bne 0b; 1:; addic. 0,31,32; addi 25,31,24; mr 29,0; addi 28,31,16; addi 27,31,8; cmpwi 4,31,0; beq 3f; addi 30,31,40; cmpw 29,30; beq 3f; li 26,0; 2:; lwzu 3,-4(30); bl _s803AD4D4_4; stw 26,0x0(30); cmpw 29,30; bne 2b; 3:; lwz 3,0x1c(31); li 30,0; bl _s803AD4D4_5; stw 30,0x1c(31); lwz 3,0x18(31); bl _s803AD4D4_6; stw 30,0x18(31); cmpwi 28,0; beq 5f; mr 30,25; cmpw 28,30; beq 5f; li 29,0; 4:; lwzu 3,-4(30); bl _s803AD4D4_7; stw 29,0x0(30); cmpw 28,30; bne 4b; 5:; cmpwi 27,0; beq 7f; mr 30,28; cmpw 27,30; beq 7f; li 29,0; 6:; lwzu 3,-4(30); bl _s803AD4D4_8; stw 29,0x0(30); cmpw 27,30; bne 6b; 7:; beq cr4,9f; mr 30,27; cmpw 31,30; beq 9f; li 29,0; 8:; lwzu 3,-4(30); bl _s803AD4D4_9; stw 29,0x0(30); cmpw 31,30; bne 8b; 9:; andi. 0,24,1; beq 10f; mr 3,31; bl _s803AD4D4_10; 10:; lwz 0,0x34(1); lwz 12,0xc(1); mtspr 8,0; lmw 24,0x10(1); mtcrf 8,12; addi 1,1,48"
extern "C" void _s803AD4D4_0();
extern "C" void _s803AD4D4_1();
extern "C" void _s803AD4D4_2();
extern "C" void _s803AD4D4_3();
extern "C" void _s803AD4D4_4();
extern "C" void _s803AD4D4_5();
extern "C" void _s803AD4D4_6();
extern "C" void _s803AD4D4_7();
extern "C" void _s803AD4D4_8();
extern "C" void _s803AD4D4_9();
extern "C" void _s803AD4D4_10();
extern "C" void f_803AD4D4() {}
