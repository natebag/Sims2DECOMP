// 0x801C70F0 MMUTarget::EndPlayerNumberChooser(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0xa4(3); cmpwi 0,2; bne 0f; lis 3,-32705; li 4,0; addi 3,3,-2032; bl _s801C70F0_0; lis 3,-32705; addi 3,3,11588; bl _s801C70F0_1; b 1f; 0:; lis 9,-32697; lis 4,-32705; lwz 11,0x5ef8(9); lis 5,-32705; addi 4,4,-5352; addi 5,5,11580; lwz 9,0x80(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801C70F0_0();
extern "C" void _s801C70F0_1();
extern "C" void f_801C70F0() {}
