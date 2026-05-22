// 0x802D565C EString2::ExtractDirectory(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; mr 3,31; li 4,92; bl _s802D565C_0; cmpwi 3,-1; bne 1f; mr 3,31; li 4,58; bl _s802D565C_1; cmpwi 3,-1; bne 0f; lis 4,-32702; mr 3,30; addi 4,4,-6876; bl _s802D565C_2; b 2f; 0:; addi 5,3,1; mr 4,31; mr 3,30; bl _s802D565C_3; b 2f; 1:; addi 5,3,1; mr 4,31; mr 3,30; bl _s802D565C_4; 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D565C_0();
extern "C" void _s802D565C_1();
extern "C" void _s802D565C_2();
extern "C" void _s802D565C_3();
extern "C" void _s802D565C_4();
extern "C" void f_802D565C() {}
