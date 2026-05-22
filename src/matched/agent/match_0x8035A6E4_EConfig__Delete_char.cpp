// 0x8035A6E4 EConfig::Delete(char (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; addi 5,1,8; addi 29,30,20; mr 3,29; bl _s8035A6E4_0; mr. 28,3; beq 1f; lwz 4,0x8(1); addi 3,30,8; lwz 31,0x0(4); bl _s8035A6E4_1; mr 3,29; mr 4,28; bl _s8035A6E4_2; cmpwi 31,0; beq 0f; lwz 4,0x0(31); mr 3,31; bl _s8035A6E4_3; mr 3,31; bl _s8035A6E4_4; 0:; li 0,1; li 3,1; stw 0,0x0(30); b 2f; 1:; li 3,0; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8035A6E4_0();
extern "C" void _s8035A6E4_1();
extern "C" void _s8035A6E4_2();
extern "C" void _s8035A6E4_3();
extern "C" void _s8035A6E4_4();
extern "C" void f_8035A6E4() {}
