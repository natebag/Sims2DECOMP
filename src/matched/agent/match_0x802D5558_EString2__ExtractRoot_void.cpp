// 0x802D5558 EString2::ExtractRoot(void) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 29,3; addi 31,1,8; mr 3,4; bl _s802D5558_0; mr 4,3; mr 3,31; bl _s802D5558_1; mr 3,31; li 4,46; bl _s802D5558_2; cmpwi 3,-1; beq 0f; addi 30,1,16; mr 5,3; mr 3,30; mr 4,31; bl _s802D5558_3; lwz 4,0x10(1); mr 3,31; bl _s802D5558_4; lwz 4,0x10(1); mr 3,30; bl _s802D5558_5; 0:; li 4,92; mr 3,31; bl _s802D5558_6; mr 30,3; li 4,58; mr 3,31; bl _s802D5558_7; cmpwi 30,-1; beq 1f; mr 3,29; mr 4,31; addi 5,30,1; b 2f; 1:; cmpwi 3,-1; beq 3f; addi 5,3,1; mr 4,31; mr 3,29; 2:; li 6,-1; bl _s802D5558_8; lwz 4,0x8(1); mr 3,31; bl _s802D5558_9; b 4f; 3:; mr 3,31; bl _s802D5558_10; mr 4,3; mr 3,29; bl _s802D5558_11; lwz 4,0x8(1); mr 3,31; bl _s802D5558_12; 4:; mr 3,29; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s802D5558_0();
extern "C" void _s802D5558_1();
extern "C" void _s802D5558_2();
extern "C" void _s802D5558_3();
extern "C" void _s802D5558_4();
extern "C" void _s802D5558_5();
extern "C" void _s802D5558_6();
extern "C" void _s802D5558_7();
extern "C" void _s802D5558_8();
extern "C" void _s802D5558_9();
extern "C" void _s802D5558_10();
extern "C" void _s802D5558_11();
extern "C" void _s802D5558_12();
extern "C" void f_802D5558() {}
