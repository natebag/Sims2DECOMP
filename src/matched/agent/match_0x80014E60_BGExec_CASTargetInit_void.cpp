// 0x80014E60 BGExec_CASTargetInit(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; addi 31,9,23428; lwz 0,0x3c(31); cmpwi 0,0; bne 0f; li 3,5688; bl _s80014E60_0; lwz 4,-32688(13); bl _s80014E60_1; stw 3,0x3c(31); 0:; li 0,1; stw 0,-21480(13); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80014E60_0();
extern "C" void _s80014E60_1();
extern "C" void f_80014E60() {}
