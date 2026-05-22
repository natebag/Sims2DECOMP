// 0x80363248 EDL::operator (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lis 9,-32690; mr 31,3; lwz 11,-6992(9); addi 30,9,-6992; li 0,0; cmplw 31,11; blt 0f; lwz 0,0xc(30); lwz 9,0x8(30); mullw 0,0,9; add 0,11,0; subfc 0,0,31; subfe 0,0,0; neg 0,0; 0:; cmpwi 0,0; beq 1f; addi 0,30,24; lwz 9,0x18(30); stw 0,0x8(1); li 4,-1; lha 3,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; mr 3,30; mr 4,31; bl _s80363248_0; lwz 11,0x8(1); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; b 2f; 1:; bl _s80363248_1; mr 4,31; bl _s80363248_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80363248_0();
extern "C" void _s80363248_1();
extern "C" void _s80363248_2();
extern "C" void f_80363248() {}
