// 0x801A2C34 ACTTarget::GetInteractionFromID(int) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 0,0xdc(3); lis 9,-32697; addi 9,9,24012; mr 28,4; rlwinm 0,0,2,0,29; addi 9,9,188; lwzx 30,9,0; li 4,1; li 31,0; lwz 9,0x4(30); lha 3,0xd8(9); lwz 0,0xdc(9); add 3,30,3; mtspr 8,0; blrl; mr 29,3; cmpw 31,29; bge 1f; 0:; lwz 9,0x4(30); mr 4,31; li 5,1; lwz 0,0xe4(9); lha 3,0xe0(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0x38(3); cmpw 0,28; beq 2f; addi 31,31,1; cmpw 31,29; blt 0b; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_801A2C34() {}
