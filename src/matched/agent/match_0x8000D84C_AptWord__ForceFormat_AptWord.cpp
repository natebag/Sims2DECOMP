// 0x8000D84C AptWord::ForceFormat(AptWord (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0xc(31); cmpwi 0,0; bne 0f; li 3,144; bl _s8000D84C_0; mr 4,31; bl _s8000D84C_1; stw 3,0xc(31); li 3,144; bl _s8000D84C_2; mr 4,31; bl _s8000D84C_3; stw 3,0x10(31); 0:; cmpwi 30,0; beq 2f; lwz 4,0xc(30); cmpwi 4,0; beq 1f; lwz 3,0xc(31); bl _s8000D84C_4; 1:; lwz 4,0x10(30); cmpwi 4,0; beq 2f; lwz 3,0x10(31); bl _s8000D84C_5; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8000D84C_0();
extern "C" void _s8000D84C_1();
extern "C" void _s8000D84C_2();
extern "C" void _s8000D84C_3();
extern "C" void _s8000D84C_4();
extern "C" void _s8000D84C_5();
extern "C" void f_8000D84C() {}
