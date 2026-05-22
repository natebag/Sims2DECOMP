// 0x800C798C cXMTObjectImpl::GetNumTiles(int (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); li 0,1; mr 29,4; stw 0,0x0(29); mr 30,5; stw 0,0x0(30); lwz 11,0x4(3); lwz 9,0x4(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; b 3f; 0:; lwz 11,0x0(31); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lha 9,0x16(3); lwz 0,0x0(29); srawi 11,9,8; rlwinm 9,9,0,24,31; addi 11,11,1; addi 9,9,1; cmpw 11,0; ble 1f; stw 11,0x0(29); 1:; lwz 0,0x0(30); cmpw 9,0; ble 2f; stw 9,0x0(30); 2:; lwz 9,0x4(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; 3:; mtspr 8,0; blrl; mr. 31,3; bne 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_800C798C() {}
