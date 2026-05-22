// 0x8029B7BC AptDisplayList::tick(void) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,0x0(3); lwz 11,0x0(9); lwz 31,0x54(11); cmpwi 31,0; beq 8f; 0:; mr 3,31; li 29,0; bl _s8029B7BC_0; li 30,0; cmpwi 3,13; bne 1f; mr 3,31; bl _s8029B7BC_1; subfic 0,3,0; adde 30,0,3; 1:; cmpwi 30,0; bne 3f; mr 3,31; li 30,0; bl _s8029B7BC_2; cmpwi 3,18; bne 2f; mr 3,31; bl _s8029B7BC_3; subfic 0,3,0; adde 30,0,3; 2:; cmpwi 30,0; beq 4f; 3:; li 29,1; 4:; cmpwi 29,0; bne 6f; mr 3,31; li 30,0; bl _s8029B7BC_4; cmpwi 3,14; bne 5f; mr 3,31; bl _s8029B7BC_5; subfic 0,3,0; adde 30,0,3; 5:; cmpwi 30,0; beq 7f; 6:; mr 3,31; bl _s8029B7BC_6; 7:; lwz 31,0x54(31); cmpwi 31,0; bne 0b; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8029B7BC_0();
extern "C" void _s8029B7BC_1();
extern "C" void _s8029B7BC_2();
extern "C" void _s8029B7BC_3();
extern "C" void _s8029B7BC_4();
extern "C" void _s8029B7BC_5();
extern "C" void _s8029B7BC_6();
extern "C" void f_8029B7BC() {}
