// 0x802E136C EPathUtil::ExtractExtension(char (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 3,4; li 4,46; bl _s802E136C_0; mr. 31,3; beq 2f; mr 3,31; li 4,47; bl _s802E136C_1; cmpwi 3,0; bne 0f; mr 3,31; li 4,92; bl _s802E136C_2; cmpwi 3,0; beq 1f; 0:; li 0,0; stb 0,0x0(30); b 3f; 1:; addi 4,31,1; mr 3,30; bl _s802E136C_3; b 3f; 2:; stb 31,0x0(30); 3:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E136C_0();
extern "C" void _s802E136C_1();
extern "C" void _s802E136C_2();
extern "C" void _s802E136C_3();
extern "C" void f_802E136C() {}
