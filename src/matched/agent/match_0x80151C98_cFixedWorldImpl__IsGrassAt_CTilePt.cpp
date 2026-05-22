// 0x80151C98 cFixedWorldImpl::IsGrassAt(CTilePt (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lha 0,0x88(9); lwz 9,0x8c(9); add 3,3,0; mtspr 8,9; blrl; lis 9,-32697; li 0,0; lwz 11,0x5ea0(9); lwz 11,0x0(11); cmpwi 11,0; beq 0f; lwz 0,-4(11); 0:; cmpw 3,0; bge 2f; rlwinm 9,3,2,0,29; lwzx 11,11,9; lwz 3,0x10(11); cmpwi 3,8; beq 1f; cmpwi 3,9; bne 2f; 1:; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80151C98() {}
