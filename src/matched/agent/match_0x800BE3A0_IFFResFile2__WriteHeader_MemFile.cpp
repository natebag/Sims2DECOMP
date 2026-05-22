// 0x800BE3A0 IFFResFile2::WriteHeader(MemFile (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 28,0x50(1); stw 0,0x64(1); mr 31,3; mr 28,4; lwz 30,0x140(31); mr 29,5; cmpwi 30,0; beq 0f; li 0,0; stw 0,0x140(31); mr 4,30; bl _s800BE3A0_0; stw 30,0x140(31); mr. 3,3; bne 3f; 0:; li 0,64; lis 9,-32702; mtspr 9,0; li 11,0; addi 9,9,16524; srawi 8,29,24; srawi 7,29,16; srawi 6,29,8; addi 10,1,8; 1:; lbzx 0,9,11; stbx 0,10,11; addi 11,11,1; bdnz 1b; li 0,50; li 9,53; li 11,64; stb 0,0x11(1); stb 9,0x13(1); mr 3,28; stb 8,0x44(1); li 4,0; stb 7,0x45(1); stb 6,0x46(1); stw 11,0x48(1); stb 29,0x47(1); bl _s800BE3A0_1; mr. 3,3; bne 3f; mr 3,28; addi 4,1,8; addi 5,1,72; bl _s800BE3A0_2; mr. 3,3; bne 3f; addi 30,31,16; mr 3,30; bl _s800BE3A0_3; cmpw 28,30; stw 29,0x140(31); bne 2f; li 0,1; stw 0,0x144(31); 2:; li 3,0; 3:; lwz 0,0x64(1); mtspr 8,0; lmw 28,0x50(1); addi 1,1,96"
extern "C" void _s800BE3A0_0();
extern "C" void _s800BE3A0_1();
extern "C" void _s800BE3A0_2();
extern "C" void _s800BE3A0_3();
extern "C" void f_800BE3A0() {}
