// 0x800CCAD8 NeighborhoodImpl::NeighborhoodImpl(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 31,0x24(1); stw 0,0x2c(1); lis 9,-32698; mr 31,3; addi 9,9,1216; addi 3,31,4; stw 9,0x0(31); addi 4,31,12; li 5,32; bl _s800CCAD8_0; li 0,0; addi 9,31,84; stw 0,0x4c(31); addi 11,31,92; stw 0,0x50(31); addi 10,31,100; stw 0,0x4(9); addi 8,31,116; stw 0,0x5c(31); addi 9,31,124; stw 0,0x4(11); li 7,0; stw 0,0x4(10); addi 11,31,202; stw 0,0x74(31); li 10,36; stw 0,0x4(8); mtspr 9,10; stw 0,0x4(9); 0:; sth 7,0x0(11); addi 11,11,-2; bdnz 0b; li 0,0; mr 3,31; sth 0,0x6c(31); stw 0,0x70(31); lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x24(1); addi 1,1,40"
extern "C" void _s800CCAD8_0();
extern "C" void f_800CCAD8() {}
