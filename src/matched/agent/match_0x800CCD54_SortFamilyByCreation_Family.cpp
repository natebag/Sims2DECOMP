// 0x800CCD54 SortFamilyByCreation(Family (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 11,0x0(31); lwz 9,0x0(11); lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x0(29); mr 30,3; lwz 9,0x0(11); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,11,3; mtspr 8,0; blrl; cmpw 30,3; beq 0f; mfcr 3; rlwinm 3,3,2,31,31; b 1f; 0:; lwz 11,0x0(31); lwz 9,0x0(11); lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x0(29); mr 30,3; lwz 9,0x0(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; cmpw cr7,30,3; mfcr 3; rlwinm 3,3,30,31,31; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_800CCD54() {}
