// 0x80365430 LLInsertItem (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 30,5; lwz 3,-25844(13); mr 29,6; bl _s80365430_0; mr. 31,3; li 3,0; beq 0f; li 4,0; li 5,16; mr 3,31; bl _s80365430_1; stw 30,0x8(31); mr 3,28; mr 5,29; mr 4,31; bl _s80365430_2; mr 3,31; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80365430_0();
extern "C" void _s80365430_1();
extern "C" void _s80365430_2();
extern "C" void f_80365430() {}
