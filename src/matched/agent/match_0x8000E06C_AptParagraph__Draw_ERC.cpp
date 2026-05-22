// 0x8000E06C AptParagraph::Draw(ERC (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 3,0x0(3); mr 27,4; mr 28,5; mr 29,6; mr 31,7; cmpwi 3,0; beq 1f; mr 30,3; 0:; mr 3,30; mr 4,27; lwz 30,0x0(30); mr 5,28; mr 6,29; mr 7,31; bl _s8000E06C_0; mr. 30,30; bne 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8000E06C_0();
extern "C" void f_8000E06C() {}
