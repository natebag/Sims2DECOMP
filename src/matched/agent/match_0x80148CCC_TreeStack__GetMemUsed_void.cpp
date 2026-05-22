// 0x80148CCC TreeStack::GetMemUsed(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 11,0x8(31); lwz 0,0xc(31); subf 0,11,0; srawi. 9,0,2; bne 0f; li 3,0; b 1f; 0:; addi 9,9,-1; rlwinm 9,9,2,0,29; lwzx 3,11,9; bl _s80148CCC_0; lwz 0,0x0(31); subf 3,0,3; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80148CCC_0();
extern "C" void f_80148CCC() {}
