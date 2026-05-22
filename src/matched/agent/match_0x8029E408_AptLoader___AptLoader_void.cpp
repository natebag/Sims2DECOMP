// 0x8029E408 AptLoader::~AptLoader(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; b 1f; 0:; lwz 9,0x0(31); mr 3,31; stw 9,0x8(1); lwz 4,0x0(9); addi 4,4,4; bl _s8029E408_0; 1:; lwz 0,0x0(31); cmpwi 0,0; bne 0b; andi. 0,30,1; beq 2f; lwz 3,-23020(13); mr 4,31; li 5,4; bl _s8029E408_1; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8029E408_0();
extern "C" void _s8029E408_1();
extern "C" void f_8029E408() {}
