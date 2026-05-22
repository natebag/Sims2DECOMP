// 0x802D54C4 EString2::ExtractFilename(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 29,3; li 4,92; mr 3,31; bl _s802D54C4_0; mr 30,3; li 4,58; mr 3,31; bl _s802D54C4_1; cmpwi 30,-1; beq 0f; mr 4,31; addi 5,30,1; b 1f; 0:; cmpwi 3,-1; beq 2f; addi 5,3,1; mr 4,31; 1:; mr 3,29; li 6,-1; bl _s802D54C4_2; b 3f; 2:; mr 3,31; bl _s802D54C4_3; mr 4,3; mr 3,29; bl _s802D54C4_4; 3:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D54C4_0();
extern "C" void _s802D54C4_1();
extern "C" void _s802D54C4_2();
extern "C" void _s802D54C4_3();
extern "C" void _s802D54C4_4();
extern "C" void f_802D54C4() {}
