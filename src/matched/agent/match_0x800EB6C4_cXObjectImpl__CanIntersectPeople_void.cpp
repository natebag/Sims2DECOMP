// 0x800EB6C4 cXObjectImpl::CanIntersectPeople(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x470(9); lwz 9,0x474(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x398(9); lwz 9,0x39c(9); add 3,3,0; mtspr 8,9; blrl; rlwinm 3,3,28,31,31; b 1f; 0:; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x398(9); lwz 0,0x39c(9); add 3,11,3; mtspr 8,0; blrl; xori 3,3,2; rlwinm 3,3,31,31,31; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_800EB6C4() {}
