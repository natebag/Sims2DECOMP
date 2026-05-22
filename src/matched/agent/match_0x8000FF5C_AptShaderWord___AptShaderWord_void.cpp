// 0x8000FF5C AptShaderWord::~AptShaderWord(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lwz 3,0x8(31); addi 9,9,-21112; mr 30,4; stw 9,0x2c(31); cmpwi 3,0; beq 0f; bl _s8000FF5C_0; 0:; lwz 11,0xc(31); cmpwi 11,0; beq 1f; lwz 9,0x8c(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; lwz 11,0x10(31); cmpwi 11,0; beq 1f; lwz 9,0x8c(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x10(31); 1:; andi. 0,30,1; beq 2f; mr 3,31; bl _s8000FF5C_1; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8000FF5C_0();
extern "C" void _s8000FF5C_1();
extern "C" void f_8000FF5C() {}
