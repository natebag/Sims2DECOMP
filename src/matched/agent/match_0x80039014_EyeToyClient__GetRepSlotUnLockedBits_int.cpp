// 0x80039014 EyeToyClient::GetRepSlotUnLockedBits(int) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); lis 9,-32697; lis 4,-32707; lwz 3,0x5eb4(9); addi 4,4,5808; li 27,0; bl _s80039014_0; mr. 3,3; li 9,0; beq 0f; mr 9,3; 0:; lwz 26,0x4(9); lis 11,-32697; lis 9,-32707; addi 25,11,23428; addi 29,9,5788; li 30,0; li 28,1; 1:; lwz 0,0x0(29); lwz 11,0x20(26); addi 29,29,4; mulli 0,0,12; add 11,11,0; lwz 9,0x8(11); lhz 9,0x6(9); mr 0,9; lwz 11,-21476(13); rlwinm 0,0,0,15,27; subf 0,0,9; lwz 4,0xd8(25); lwz 9,0x0(11); slw 0,28,0; extsh 31,0; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 2f; lwz 9,0x0(11); lha 3,0x148(9); lwz 0,0x14c(9); add 3,11,3; mtspr 8,0; blrl; 2:; addi 30,30,1; cmpwi 30,4; ble 1b; mr 3,27; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s80039014_0();
extern "C" void f_80039014() {}
