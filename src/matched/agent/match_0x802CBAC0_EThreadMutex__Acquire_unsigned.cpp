// 0x802CBAC0 EThreadMutex::Acquire(unsigned (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; addi 30,31,28; 0:; mr 3,31; li 4,-1; bl _s802CBAC0_0; lwz 0,0x3c(31); cmpwi 0,0; beq 1f; bl _s802CBAC0_1; lwz 0,0x38(31); cmpw 0,3; bne 3f; lwz 0,0x3c(31); cmpwi 0,0; bne 2f; 1:; li 4,-1; addi 3,31,28; bl _s802CBAC0_2; bl _s802CBAC0_3; stw 3,0x38(31); 2:; lwz 9,0x3c(31); addi 9,9,1; stw 9,0x3c(31); b 4f; 3:; mr 3,31; bl _s802CBAC0_4; mr 3,30; li 4,-1; bl _s802CBAC0_5; mr 3,30; bl _s802CBAC0_6; b 0b; 4:; mr 3,31; bl _s802CBAC0_7; li 3,1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802CBAC0_0();
extern "C" void _s802CBAC0_1();
extern "C" void _s802CBAC0_2();
extern "C" void _s802CBAC0_3();
extern "C" void _s802CBAC0_4();
extern "C" void _s802CBAC0_5();
extern "C" void _s802CBAC0_6();
extern "C" void _s802CBAC0_7();
extern "C" void f_802CBAC0() {}
