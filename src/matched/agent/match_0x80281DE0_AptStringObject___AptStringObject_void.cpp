// 0x80281DE0 AptStringObject::~AptStringObject(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32704; lwz 11,0x24(31); addi 9,9,8912; mr 30,4; stw 9,0x8(31); cmpwi 11,0; beq 0f; lwz 9,0x8(11); lis 4,-32704; lis 5,-32704; addi 4,4,5492; lha 3,0x10(9); addi 5,5,5412; lwz 0,0x14(9); li 6,329; add 3,11,3; mtspr 8,0; blrl; 0:; lis 9,-32703; li 0,0; addi 9,9,21120; stw 0,0x24(31); stw 9,0x8(31); addi 3,31,12; li 4,2; bl _s80281DE0_0; mr 3,31; li 4,0; bl _s80281DE0_1; andi. 0,30,1; beq 1f; lwz 3,-23016(13); mr 4,31; li 5,40; bl _s80281DE0_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80281DE0_0();
extern "C" void _s80281DE0_1();
extern "C" void _s80281DE0_2();
extern "C" void f_80281DE0() {}
