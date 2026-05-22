// 0x80250E48 __OSCallResetFunctions (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); li 30,0; stw 29,0x14(1); addi 29,3,0; li 3,0; lwz 31,-23632(13); b 2f; 0:; cmpwi 30,0; beq 1f; lwz 0,0x4(31); cmplw 3,0; bne 3f; 1:; lwz 12,0x0(31); addi 3,29,0; mtspr 8,12; blrl; cntlzw 0,3; lwz 3,0x4(31); rlwinm 0,0,27,5,31; lwz 31,0x8(31); or 30,30,0; 2:; cmplwi 31,0; bne 0b; 3:; bl _s80250E48_0; cntlzw 0,3; rlwinm 0,0,27,5,31; or. 30,30,0; beq 4f; li 3,0; b 5f; 4:; li 3,1; 5:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80250E48_0();
extern "C" void f_80250E48() {}
