// 0x8015D8BC TreeTableAdQuickData::~TreeTableAdQuickData(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; li 0,0; addi 9,9,24192; stw 0,0x4(3); stw 9,0x0(3); andi. 9,4,1; beq 0f; bl _s8015D8BC_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8015D8BC_0();
extern "C" void f_8015D8BC() {}
