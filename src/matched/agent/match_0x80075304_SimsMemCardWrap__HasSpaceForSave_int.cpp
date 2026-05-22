// 0x80075304 SimsMemCardWrap::HasSpaceForSave(int, (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 31,4; mr. 5,5; beq 0f; li 0,0; stw 0,0x0(5); 0:; lwz 3,-26384(13); mr 4,28; li 5,1; mr 6,31; bl _s80075304_0; lwz 0,0x0(31); cmpwi 0,0; beq 1f; lwz 29,-26384(13); lwz 30,0x0(29); lha 0,0x80(30); addi 30,30,128; add 29,29,0; bl _s80075304_1; lwz 0,0x4(30); mr 5,3; mr 3,29; mr 4,28; mr 6,31; mtspr 8,0; blrl; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80075304_0();
extern "C" void _s80075304_1();
extern "C" void f_80075304() {}
