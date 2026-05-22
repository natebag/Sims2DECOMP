// 0x801C3DF8 MDITarget::DeleteAllModelessDialogs(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; lwz 0,0x84(28); cmpwi 0,0; beq 5f; li 27,0; lis 26,-32692; 0:; lwz 31,0x84(28); lwz 29,0x20(31); cmpwi 31,0; beq 4f; lwz 30,0x8(31); cmpwi 30,0; beq 1f; mr 3,30; bl _s801C3DF8_0; stw 27,0x8(31); stw 27,0xc(31); b 2f; 1:; lwz 4,0xc(31); cmpwi 4,0; beq 2f; addi 3,26,-17444; bl _s801C3DF8_1; stw 30,0xc(31); 2:; lwz 3,0x10(31); cmpwi 3,0; beq 3f; bl _s801C3DF8_2; stw 27,0x10(31); 3:; addi 3,31,4; li 4,2; bl _s801C3DF8_3; mr 3,31; li 4,2; bl _s801C3DF8_4; mr 3,31; bl _s801C3DF8_5; 4:; cmpwi 29,0; stw 29,0x84(28); bne 0b; 5:; li 0,0; stw 0,0x88(28); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s801C3DF8_0();
extern "C" void _s801C3DF8_1();
extern "C" void _s801C3DF8_2();
extern "C" void _s801C3DF8_3();
extern "C" void _s801C3DF8_4();
extern "C" void _s801C3DF8_5();
extern "C" void f_801C3DF8() {}
