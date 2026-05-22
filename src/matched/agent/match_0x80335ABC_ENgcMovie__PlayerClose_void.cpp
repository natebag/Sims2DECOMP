// 0x80335ABC ENgcMovie::PlayerClose(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32691; addi 3,9,14656; lwz 0,0xa0(3); cmpwi 0,0; beq 0f; lbz 0,0xa4(3); cmpwi 0,0; bne 0f; stw 0,0xa0(3); bl _s80335ABC_0; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80335ABC_0();
extern "C" void f_80335ABC() {}
