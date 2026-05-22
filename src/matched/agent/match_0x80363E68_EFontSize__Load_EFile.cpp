// 0x80363E68 EFontSize::Load(EFile (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 31,4; bl _s80363E68_0; lis 9,-32688; lhz 0,-10462(9); cmpwi 0,0; bne 1f; lwz 9,0x28(31); addi 4,30,4; li 5,4; addi 28,30,32; lwz 0,0x1c(9); li 29,0; lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,30,8; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); li 5,4; addi 4,30,12; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; addi 4,30,16; mr 3,31; bl _s80363E68_1; mr 30,3; addi 4,1,8; lwz 9,0x28(30); li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 4,0x8(1); mr 3,28; li 5,0; bl _s80363E68_2; lwz 0,0x8(1); cmpw 29,0; bge 1f; li 31,0; 0:; lwz 4,0x0(28); mr 3,30; addi 29,29,1; add 4,4,31; bl _s80363E68_3; addi 31,31,4; lwz 0,0x8(1); cmpw 29,0; blt 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80363E68_0();
extern "C" void _s80363E68_1();
extern "C" void _s80363E68_2();
extern "C" void _s80363E68_3();
extern "C" void f_80363E68() {}
