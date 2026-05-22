// 0x80365324 LLCreate (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 30,4; lwz 3,-25848(13); mr 29,5; bl _s80365324_0; mr. 31,3; li 3,-2; beq 0f; li 4,0; li 5,152; mr 3,31; bl _s80365324_1; mr 4,30; addi 3,31,4; bl _s80365324_2; li 0,0; stw 29,0x94(31); stw 0,0x90(31); li 3,0; stw 0,0x88(31); stw 0,0x8c(31); stw 31,0x0(28); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80365324_0();
extern "C" void _s80365324_1();
extern "C" void _s80365324_2();
extern "C" void f_80365324() {}
