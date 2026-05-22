// 0x80148C84 TreeStack::GetNewFrame(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x8(3); lwz 0,0xc(3); subf 0,11,0; srawi. 9,0,2; bne 0f; lwz 3,0x0(3); b 1f; 0:; addi 9,9,-1; rlwinm 9,9,2,0,29; lwzx 3,11,9; bl _s80148C84_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80148C84_0();
extern "C" void f_80148C84() {}
