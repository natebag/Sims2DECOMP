// 0x800595B8 Player::GetPrimaryNeighbor(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 31,-21476(13); mr 29,3; lis 9,-32697; li 30,0; lwz 11,0x0(31); lwz 4,0x5c5c(9); lha 3,0x120(11); lwz 0,0x124(11); add 3,31,3; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0x0(11); lwz 4,0x0(29); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 0f; lwz 9,0x0(31); lwz 4,0x0(3); lha 3,0xc0(9); lwz 0,0xc4(9); add 3,31,3; mtspr 8,0; blrl; mr 30,3; 0:; stw 30,0x4(29); mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_800595B8() {}
