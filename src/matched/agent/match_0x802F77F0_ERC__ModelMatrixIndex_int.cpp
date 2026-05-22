// 0x802F77F0 ERC::ModelMatrixIndex(int, (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,5; mr 31,3; mr 29,4; cmplwi 30,247; bgt 0f; lwz 0,0x44(31); cmpw 30,0; ble 0f; stw 30,0x44(31); 0:; lwz 9,0x70(31); li 4,1; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; rlwinm 11,29,2,0,29; addi 9,31,36; stwx 30,9,11; li 0,1; stw 0,0x34(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_802F77F0() {}
