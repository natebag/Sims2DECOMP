// 0x802FB004 ESubModel::DrawGeometry(ERC (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; li 28,0; lwz 0,0x4(27); mr 31,4; cmpw 28,0; bge 1f; li 29,0; 0:; lwz 11,0x70(31); li 4,0; lwz 30,0x0(27); addi 28,28,1; lwz 0,0x1bc(11); lha 3,0x1b8(11); add 9,30,29; lfs f1,0x24(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); lwzx 4,30,29; lwz 0,0xbc(9); addi 29,29,112; lha 3,0xb8(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x4(27); cmpw 28,0; blt 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void f_802FB004() {}
