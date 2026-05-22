// 0x802C62E8 DupString(char (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr. 31,3; beq 0f; bl _s802C62E8_0; mr 30,3; mr 3,31; bl _s802C62E8_1; addi 4,3,1; li 5,0; mr 3,30; bl _s802C62E8_2; mr. 30,3; beq 0f; mr 4,31; mr 3,30; bl _s802C62E8_3; mr 3,30; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C62E8_0();
extern "C" void _s802C62E8_1();
extern "C" void _s802C62E8_2();
extern "C" void _s802C62E8_3();
extern "C" void f_802C62E8() {}
