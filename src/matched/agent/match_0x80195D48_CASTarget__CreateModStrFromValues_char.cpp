// 0x80195D48 CASTarget::CreateModStrFromValues(char (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,5; mr 3,31; li 4,0; li 5,8; bl _s80195D48_0; li 0,7; li 9,0; mtspr 9,0; 0:; lwz 0,0x0(30); li 11,48; srw 0,0,9; andi. 10,0,1; beq 1f; li 11,49; 1:; stbx 11,31,9; addi 9,9,1; bdnz 0b; li 9,49; li 0,0; stb 0,0x8(31); stb 9,0x7(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80195D48_0();
extern "C" void f_80195D48() {}
