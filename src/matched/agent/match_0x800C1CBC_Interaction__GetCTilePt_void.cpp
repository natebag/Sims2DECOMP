// 0x800C1CBC Interaction::GetCTilePt(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-24448(13); cmpwi 0,0; bne 0f; bl _s800C1CBC_0; mr 4,3; lwz 9,0x4(4); addi 3,13,-24452; lha 0,0x358(9); lwz 9,0x35c(9); add 4,4,0; mtspr 8,9; blrl; li 0,1; lis 3,-32756; stw 0,-24448(13); addi 3,3,7316; bl _s800C1CBC_1; 0:; addi 3,13,-24452; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800C1CBC_0();
extern "C" void _s800C1CBC_1();
extern "C" void f_800C1CBC() {}
