// 0x80285640 AptIntervalTimer::cleanParams(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; lwz 0,0x14(31); cmpwi 0,0; ble 1f; mr 30,0; addi 29,31,20; lis 27,-32704; lis 28,-32704; 0:; lwz 11,0x14(31); addi 4,27,10768; lwz 0,0x8(29); addi 5,28,10808; rlwinm 11,11,2,0,29; li 6,126; add 11,11,0; lwz 10,-4(11); lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; lwz 9,0x14(31); addic. 30,30,-1; addi 9,9,-1; stw 9,0x14(31); bne 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void f_80285640() {}
