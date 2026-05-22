// 0x800754CC SimsMemCardWrap::IsDifferentCard(int, (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,-32056(13); mr 29,3; mr 31,4; lwz 0,0x20(9); cmpwi 0,1; bne 0f; stw 0,0x0(31); li 3,1; b 2f; 0:; mr 3,9; mr 4,29; mr 5,31; bl _s800754CC_0; mr 30,3; cmpwi 30,1; beq 1f; li 0,1; stw 0,0x0(31); 1:; lwz 3,-31932(13); mr 4,29; bl _s800754CC_1; mr 3,30; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800754CC_0();
extern "C" void _s800754CC_1();
extern "C" void f_800754CC() {}
