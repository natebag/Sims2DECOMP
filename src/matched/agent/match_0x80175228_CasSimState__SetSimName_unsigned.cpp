// 0x80175228 CasSimState::SetSimName(unsigned (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,5; mr. 30,4; beq 0f; addi 3,31,12; mr 4,30; li 5,32; bl _s80175228_0; li 0,0; sth 0,0x4a(31); 0:; cmpwi 29,0; beq 1f; mr 4,30; addi 3,31,12; li 5,32; bl _s80175228_1; li 0,0; sth 0,0x4a(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80175228_0();
extern "C" void _s80175228_1();
extern "C" void f_80175228() {}
