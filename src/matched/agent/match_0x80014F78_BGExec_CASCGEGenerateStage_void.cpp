// 0x80014F78 BGExec_CASCGEGenerateStage(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; lwz 0,0x5bc0(9); cmpwi 0,0; beq 0f; bl _s80014F78_0; 0:; li 0,1; stw 0,-21480(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80014F78_0();
extern "C" void f_80014F78() {}
