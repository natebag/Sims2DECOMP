// 0x802D75E0 efseek (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 9,-32700; lwz 11,0x28(30); addi 9,9,-4764; rlwinm 5,5,2,0,29; lwz 0,0x2c(11); lha 3,0x28(11); lwzx 5,9,5; mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); lha 3,0x40(9); lwz 0,0x44(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_802D75E0() {}
