// 0x8023C9C4 GetSkuLine(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); lis 9,-32704; addi 11,1,8; lwz 6,-1056(9); lis 29,-32695; addi 9,9,-1056; lis 7,-32704; lwz 5,0x14(9); lis 4,-32704; lwz 30,0x4(9); addi 4,4,-1028; lwz 8,0x8(9); addi 7,7,-1032; lwz 10,0xc(9); addi 3,29,-528; lwz 0,0x10(9); stw 6,0x8(1); stw 5,0x14(11); stw 30,0x4(11); li 5,1; stw 8,0x8(11); stw 10,0xc(11); stw 0,0x10(11); lwz 6,0xc(1); crxor 6,6,6; bl _s8023C9C4_0; addi 3,29,-528; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s8023C9C4_0();
extern "C" void f_8023C9C4() {}
