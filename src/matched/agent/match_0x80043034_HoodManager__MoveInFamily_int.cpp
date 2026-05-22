// 0x80043034 HoodManager::MoveInFamily(int, (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; bl _s80043034_0; addi 29,30,1; mr. 28,3; blt 0f; lwz 3,-21476(13); lwz 9,0x0(3); lha 0,0x190(9); lwz 9,0x194(9); add 3,3,0; mtspr 8,9; blrl; mr 5,29; mr 4,31; bl _s80043034_1; cmpwi 3,0; bne 0f; lwz 9,0x0(31); mr 4,28; lwz 0,0xd4(9); lha 3,0xd0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); lwz 4,-32056(13); lha 3,0x68(9); lwz 0,0x6c(9); lwz 5,-32040(13); add 3,31,3; mtspr 8,0; blrl; mr 3,30; mr 4,31; bl _s80043034_2; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80043034_0();
extern "C" void _s80043034_1();
extern "C" void _s80043034_2();
extern "C" void f_80043034() {}
