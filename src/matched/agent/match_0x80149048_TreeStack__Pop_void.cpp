// 0x80149048 TreeStack::Pop(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); addi 31,3,8; lwz 9,0x8(3); lwz 0,0x4(31); subf 0,9,0; rlwinm. 9,0,30,2,31; bne 0f; lwz 11,0x18(3); li 9,1; stw 9,-24512(13); li 0,1001; sth 0,0x34(11); li 4,1001; lwz 11,0x18(3); lwz 9,0x40(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 9,0x4(31); addi 9,9,-4; stw 9,0x4(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80149048() {}
