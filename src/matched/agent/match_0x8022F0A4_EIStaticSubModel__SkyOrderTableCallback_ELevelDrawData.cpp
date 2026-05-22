// 0x8022F0A4 EIStaticSubModel::SkyOrderTableCallback(ELevelDrawData (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,0x24(4); mr 30,3; lwz 31,0x20(4); lwz 9,0x0(11); lwz 29,0x18(4); lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0xa8(30); mr 5,3; cmpw 0,31; beq 2f; stw 31,0xa8(30); lwz 4,0x98(30); lwz 3,0x14(31); cmpwi 3,0; beq 0f; mr 11,3; b 1f; 0:; lwz 9,0x18(31); li 11,0; cmpwi 9,0; beq 1f; lwz 11,0x14(9); 1:; lwz 9,0xf0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 3,0x98(30); mr 4,29; lwz 9,0x70(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_8022F0A4() {}
