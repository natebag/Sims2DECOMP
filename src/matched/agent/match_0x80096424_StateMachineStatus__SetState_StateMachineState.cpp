// 0x80096424 StateMachineStatus::SetState(StateMachineState (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; lwz 11,0x0(30); cmpw 31,11; bne 0f; cmpwi 31,0; beq 2f; lwz 9,0x18(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; b 2f; 0:; cmpwi 11,0; beq 1f; lwz 9,0x18(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x0(30); cmpwi 31,0; stw 31,0x0(30); stw 0,0x8(30); beq 2f; lwz 9,0x18(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; lis 9,-32706; lfs f0,-30516(9); stfs f0,0x14(30); 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80096424() {}
