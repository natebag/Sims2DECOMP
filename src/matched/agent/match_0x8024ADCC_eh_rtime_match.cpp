// 0x8024ADCC __eh_rtime_match (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8024ADCC_0; lwz 9,0x0(3); li 3,0; lwz 0,0x0(9); cmpwi 0,0; beq 0f; mr 3,9; mr 4,31; li 5,0; mtspr 8,0; blrl; cmpwi 3,0; li 3,1; bne 0f; li 3,0; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8024ADCC_0();
extern "C" void f_8024ADCC() {}
