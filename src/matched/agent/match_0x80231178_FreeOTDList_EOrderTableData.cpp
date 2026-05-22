// 0x80231178 FreeOTDList(EOrderTableData (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 26,3; lwz 31,0x0(26); cmpwi 31,0; beq 4f; lis 27,-32695; lis 28,17733; addi 29,27,-29652; ori 28,28,21062; 0:; lwz 11,-29652(27); li 0,0; lwz 30,0x28(31); cmplw 31,11; blt 1f; lwz 0,0xc(29); lwz 9,0x8(29); mullw 0,0,9; add 0,11,0; subfc 0,0,31; subfe 0,0,0; neg 0,0; 1:; cmpwi 0,0; beq 2f; cmpwi 31,0; beq 3f; stw 28,0x0(31); lwz 0,0x4(29); stw 0,0x4(31); stw 31,0x4(29); b 3f; 2:; bl _s80231178_0; mr 4,31; bl _s80231178_1; 3:; mr. 31,30; bne 0b; 4:; li 0,0; stw 0,0x0(26); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80231178_0();
extern "C" void _s80231178_1();
extern "C" void f_80231178() {}
