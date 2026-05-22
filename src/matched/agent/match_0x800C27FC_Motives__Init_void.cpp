// 0x800C27FC Motives::Init(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-32020(13); mr 31,3; cmpwi 0,0; bne 0f; bl _s800C27FC_0; lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; 0:; li 0,16; lis 9,-32706; mtspr 9,0; lfs f0,-23648(9); addi 11,31,64; addi 9,31,60; 1:; stfs f0,0x0(9); addi 9,9,-4; bdnz 1b; li 0,16; lis 9,-32706; mtspr 9,0; lfs f0,-23648(9); addi 11,11,60; 2:; stfs f0,0x0(11); addi 11,11,-4; bdnz 2b; li 0,0; stw 0,0x80(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800C27FC_0();
extern "C" void f_800C27FC() {}
