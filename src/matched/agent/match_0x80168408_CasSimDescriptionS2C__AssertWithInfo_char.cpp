// 0x80168408 CasSimDescriptionS2C::AssertWithInfo(char (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-1040(1); mfspr 0,8; stmw 30,0x408(1); stw 0,0x414(1); mr 31,3; mr 30,4; li 5,1024; addi 3,1,8; bl _s80168408_0; li 0,0; mr 3,30; stb 0,0x407(1); bl _s80168408_1; mr 7,31; addi 9,1,8; lhzu 11,0x4(7); li 0,32; add 8,9,3; stbx 0,9,3; stbu 0,0x1(8); cmpwi 11,0; li 10,0; addi 8,8,1; beq 1f; li 0,32; mtspr 9,0; 0:; add 9,10,10; add 9,7,9; addi 10,10,1; lbz 11,0x1(9); add 0,10,10; lhzx 9,7,0; stb 11,0x0(8); cmpwi 9,0; addi 8,8,1; beq 1f; bdnz 0b; 1:; mr 7,31; li 0,32; lhzu 9,0x44(7); li 10,0; stb 0,0x0(8); cmpwi 9,0; addi 8,8,1; beq 3f; li 0,32; mtspr 9,0; 2:; add 9,10,10; add 9,7,9; addi 10,10,1; lbz 11,0x1(9); add 0,10,10; lhzx 9,7,0; stb 11,0x0(8); cmpwi 9,0; addi 8,8,1; beq 3f; bdnz 2b; 3:; li 0,0; stb 0,0x0(8); lwz 0,0x414(1); mtspr 8,0; lmw 30,0x408(1); addi 1,1,1040"
extern "C" void _s80168408_0();
extern "C" void _s80168408_1();
extern "C" void f_80168408() {}
