// 0x801FEA10 PDATarget::SelectionCallback(int) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x170(31); cmpwi 0,0; beq 1f; lwz 0,0x174(31); cmpwi 0,0; bne 0f; lis 3,-32704; stw 0,0x170(31); addi 3,3,-20028; bl _s801FEA10_0; mr 5,3; li 4,0; mr 3,31; bl _s801FEA10_1; b 1f; 0:; cmpwi 0,1; bne 1f; li 0,0; lis 3,-32704; stw 0,0x170(31); addi 3,3,-20012; bl _s801FEA10_2; mr 5,3; li 4,1; mr 3,31; bl _s801FEA10_3; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801FEA10_0();
extern "C" void _s801FEA10_1();
extern "C" void _s801FEA10_2();
extern "C" void _s801FEA10_3();
extern "C" void f_801FEA10() {}
