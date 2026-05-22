// 0x800BA5D8 cGZSnd::Unpause(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 31,0x24(1); stw 0,0x2c(1); mr 31,3; lwz 4,0x1c(31); cmpwi 4,0; beq 0f; lis 9,-32706; li 0,0; lfs f0,-25344(9); addi 5,1,8; stw 0,0x8(1); stfs f0,0xc(5); lwz 11,-26564(13); lwz 0,0x8(1); ori 0,0,4; stw 0,0x8(1); lwz 9,0x0(11); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 0,0; li 3,1; stw 0,0x10(31); lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x24(1); addi 1,1,40"
extern "C" void f_800BA5D8() {}
