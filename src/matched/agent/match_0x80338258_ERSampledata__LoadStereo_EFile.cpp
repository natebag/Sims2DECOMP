// 0x80338258 ERSampledata::LoadStereo(EFile (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; li 3,96; bl _s80338258_0; mr 4,3; li 5,96; stw 4,0x18(29); lwz 9,0x28(30); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x18(29); lwz 9,0x4(11); andi. 0,9,1; beq 0f; addi 0,9,1; stw 0,0x4(11); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80338258_0();
extern "C" void f_80338258() {}
