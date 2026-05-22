// 0x8035A5F8 EConfig::SetString(char (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-4136(1); mfspr 0,8; stmw 27,0x1014(1); stw 0,0x102c(1); mr 29,3; mr 30,4; addi 28,29,20; mr 27,5; mr 3,28; addi 5,1,4104; bl _s8035A5F8_0; cmpwi 3,0; beq 0f; lwz 9,0x1008(1); lwz 31,0x0(9); b 1f; 0:; li 3,4; bl _s8035A5F8_1; mr 0,3; mr 31,0; bl _s8035A5F8_2; mr 4,31; addi 3,29,8; bl _s8035A5F8_3; mr 0,3; mr 4,30; mr 5,0; stw 0,0x1008(1); mr 3,28; bl _s8035A5F8_4; li 0,1; stw 0,0x0(29); 1:; mr 5,30; addi 3,1,8; lis 4,-32702; mr 6,27; addi 4,4,11440; mr 30,3; crxor 6,6,6; bl _s8035A5F8_5; mr 3,31; mr 4,30; bl _s8035A5F8_6; cmpwi 3,0; li 0,1; bne 2f; li 0,0; 2:; cmpwi 0,0; beq 3f; mr 3,31; mr 4,30; bl _s8035A5F8_7; li 0,1; stw 0,0x0(29); 3:; lwz 0,0x102c(1); mtspr 8,0; lmw 27,0x1014(1); addi 1,1,4136"
extern "C" void _s8035A5F8_0();
extern "C" void _s8035A5F8_1();
extern "C" void _s8035A5F8_2();
extern "C" void _s8035A5F8_3();
extern "C" void _s8035A5F8_4();
extern "C" void _s8035A5F8_5();
extern "C" void _s8035A5F8_6();
extern "C" void _s8035A5F8_7();
extern "C" void f_8035A5F8() {}
