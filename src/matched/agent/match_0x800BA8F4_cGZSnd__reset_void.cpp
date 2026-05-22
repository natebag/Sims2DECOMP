// 0x800BA8F4 cGZSnd::reset(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 4,0x1c(31); cmpwi 4,0; beq 0f; lwz 11,-26564(13); lwz 9,0x0(11); lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x1c(31); 0:; lwz 11,0x18(31); cmpwi 11,0; beq 1f; lwz 9,0x4(11); li 0,0; addi 9,9,-1; stw 9,0x4(11); stw 0,0x18(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_800BA8F4() {}
