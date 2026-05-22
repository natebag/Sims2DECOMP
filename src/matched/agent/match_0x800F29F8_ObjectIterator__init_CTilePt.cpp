// 0x800F29F8 ObjectIterator::init(CTilePt (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,-21484(13); mr 30,3; mr 29,5; lwz 9,0x0(11); lwz 0,0x254(9); lha 3,0x250(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21484(13); mr 4,3; lwz 9,0x0(11); lha 3,0x90(9); lwz 0,0x94(9); add 3,11,3; mtspr 8,0; blrl; stw 29,0x8(30); stw 3,0x4(30); stw 3,0x0(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_800F29F8() {}
