// 0x80233DDC UnregisterFloorOTDsFromList(EOrderTableData (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 26,4; lwz 31,0x0(29); cmpwi 31,0; beq 6f; lis 28,17733; lis 27,-32695; ori 28,28,21062; 0:; lwz 0,0x24(31); lwz 30,0x28(31); cmpw 0,26; bne 4f; lwz 11,-29652(27); addi 10,27,-29652; li 0,0; cmplw 31,11; blt 1f; lwz 0,0xc(10); lwz 9,0x8(10); mullw 0,0,9; add 0,11,0; subfc 0,0,31; subfe 0,0,0; neg 0,0; 1:; cmpwi 0,0; beq 2f; cmpwi 31,0; beq 3f; stw 28,0x0(31); lwz 0,0x4(10); stw 0,0x4(31); stw 31,0x4(10); b 3f; 2:; bl _s80233DDC_0; mr 4,31; bl _s80233DDC_1; 3:; stw 30,0x0(29); b 5f; 4:; addi 29,31,40; 5:; mr. 31,30; bne 0b; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80233DDC_0();
extern "C" void _s80233DDC_1();
extern "C" void f_80233DDC() {}
