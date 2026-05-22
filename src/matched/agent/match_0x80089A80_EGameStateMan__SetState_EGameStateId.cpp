// 0x80089A80 EGameStateMan::SetState(EGameStateId) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,3; mr 28,4; lwz 31,0x4(29); cmpwi 31,0; beq 3f; lis 27,-32697; 0:; lwz 30,0x0(31); lwz 0,0x0(28); lwz 4,0x0(30); cmpw 4,0; stw 4,0x8(1); bne 2f; lwz 3,0x0(29); cmpwi 3,0; beq 1f; lwz 3,0x0(3); lwz 9,0x8(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; 1:; stw 31,0x0(29); lwz 4,0x0(28); stw 4,0x5e6c(27); lwz 9,0x8(30); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; b 3f; 2:; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void f_80089A80() {}
