// 0x80285F30 AptArray::_reserve(int) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 29,0; lwz 0,0x28(31); cmpw 0,4; bge 4f; lwz 3,-23020(13); addic. 4,4,-1; beq 1f; 0:; addi 29,29,1; srawi. 4,4,1; bne 0b; 1:; li 0,1; slw 29,0,29; cmpwi 29,8; bge 2f; li 29,8; 2:; rlwinm 30,29,2,0,29; mr 4,30; bl _s80285F30_0; mr 28,3; li 4,0; mr 5,30; bl _s80285F30_1; lwz 4,0x24(31); cmpwi 4,0; beq 3f; lwz 5,0x28(31); mr 3,28; rlwinm 5,5,2,0,29; crxor 6,6,6; bl _s80285F30_2; lwz 5,0x28(31); lwz 3,-23020(13); lwz 4,0x24(31); rlwinm 5,5,2,0,29; bl _s80285F30_3; 3:; stw 29,0x28(31); stw 28,0x24(31); 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80285F30_0();
extern "C" void _s80285F30_1();
extern "C" void _s80285F30_2();
extern "C" void _s80285F30_3();
extern "C" void f_80285F30() {}
