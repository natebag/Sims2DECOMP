// 0x802935F0 AptCIH::hasRenderData(void) (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 29,0; li 30,0; bl _s802935F0_0; cmpwi 3,13; bne 0f; mr 3,31; bl _s802935F0_1; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; bne 2f; mr 3,31; li 30,0; bl _s802935F0_2; cmpwi 3,18; bne 1f; mr 3,31; bl _s802935F0_3; subfic 0,3,0; adde 30,0,3; 1:; cmpwi 30,0; beq 3f; 2:; li 29,1; 3:; cmpwi 29,0; beq 4f; lwz 3,0x4c(31); addi 3,3,36; bl _s802935F0_4; bl _s802935F0_5; b 11f; 4:; mr 3,31; li 30,0; bl _s802935F0_6; cmpwi 3,12; bne 5f; mr 3,31; bl _s802935F0_7; subfic 0,3,0; adde 30,0,3; 5:; cmpwi 30,0; bne 9f; mr 3,31; li 30,0; bl _s802935F0_8; cmpwi 3,15; bne 6f; mr 3,31; bl _s802935F0_9; subfic 0,3,0; adde 30,0,3; 6:; cmpwi 30,0; bne 9f; mr 3,31; li 30,0; bl _s802935F0_10; cmpwi 3,16; bne 7f; mr 3,31; bl _s802935F0_11; subfic 0,3,0; adde 30,0,3; 7:; cmpwi 30,0; bne 9f; mr 3,31; li 30,0; bl _s802935F0_12; cmpwi 3,14; bne 8f; mr 3,31; bl _s802935F0_13; subfic 0,3,0; adde 30,0,3; 8:; cmpwi 30,0; beq 10f; 9:; li 3,1; b 11f; 10:; li 3,0; 11:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802935F0_0();
extern "C" void _s802935F0_1();
extern "C" void _s802935F0_2();
extern "C" void _s802935F0_3();
extern "C" void _s802935F0_4();
extern "C" void _s802935F0_5();
extern "C" void _s802935F0_6();
extern "C" void _s802935F0_7();
extern "C" void _s802935F0_8();
extern "C" void _s802935F0_9();
extern "C" void _s802935F0_10();
extern "C" void _s802935F0_11();
extern "C" void _s802935F0_12();
extern "C" void _s802935F0_13();
extern "C" void f_802935F0() {}
