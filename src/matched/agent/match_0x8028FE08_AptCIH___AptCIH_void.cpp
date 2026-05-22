// 0x8028FE08 AptCIH::~AptCIH(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32704; mr 31,3; addi 9,9,23568; mr 30,4; stw 9,0x8(31); li 4,0; bl _s8028FE08_0; lwz 0,0x5c(31); rlwinm 0,0,20,30,31; cmpwi 0,1; beq 0f; mr 3,31; bl _s8028FE08_1; 0:; lwz 4,0x60(31); cmpwi 4,0; beq 1f; lwz 3,-23020(13); li 5,4; bl _s8028FE08_2; 1:; lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028FE08_3; 2:; mr 3,31; li 4,0; bl _s8028FE08_4; andi. 0,30,1; beq 3f; lwz 3,-23016(13); mr 4,31; li 5,100; bl _s8028FE08_5; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8028FE08_0();
extern "C" void _s8028FE08_1();
extern "C" void _s8028FE08_2();
extern "C" void _s8028FE08_3();
extern "C" void _s8028FE08_4();
extern "C" void _s8028FE08_5();
extern "C" void f_8028FE08() {}
