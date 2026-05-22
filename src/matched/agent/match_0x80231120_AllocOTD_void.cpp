// 0x80231120 AllocOTD(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32695; addi 11,9,-29652; lwz 3,0x4(11); cmpwi 3,0; beq 0f; lwz 9,0x4(3); lis 0,17477; ori 0,0,21333; stw 9,0x4(11); stw 0,0x0(3); 0:; bne 1f; bl _s80231120_0; li 4,56; li 5,0; bl _s80231120_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80231120_0();
extern "C" void _s80231120_1();
extern "C" void f_80231120() {}
