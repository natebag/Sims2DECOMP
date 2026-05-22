// 0x80234A70 ERLevel::DrawOrderTableSlot(EOrderTableData (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr. 30,4; addis 9,31,3; lwz 29,-24008(9); beq 1f; 0:; mr 4,30; mr 3,31; lwz 30,0x28(30); mr 5,29; bl _s80234A70_0; mr. 30,30; bne 0b; 1:; lwz 9,0x70(29); lis 11,-32704; lfs f1,-2820(11); lha 3,0x258(9); lwz 0,0x25c(9); add 3,29,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80234A70_0();
extern "C" void f_80234A70() {}
