// 0x802BC0F0 AptValueVector::ReleaseValues(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; b 2f; 0:; lwz 9,0x4(31); lwz 11,0x8(31); addi 9,9,-1; stw 9,0x4(31); rlwinm 9,9,2,0,29; lwzx 11,9,11; lwz 0,0x0(11); rlwinm. 9,0,18,20,31; beq 1f; rlwinm 0,0,0,3,1; stw 0,0x0(11); b 2f; 1:; lwz 9,0x8(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 0,0x4(31); cmpwi 0,0; bne 0b; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_802BC0F0() {}
