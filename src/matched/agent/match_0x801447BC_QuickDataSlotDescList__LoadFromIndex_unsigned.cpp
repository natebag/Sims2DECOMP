// 0x801447BC QuickDataSlotDescList::LoadFromIndex(unsigned (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 9,-21508(13); mr 27,3; mr 28,4; mr 29,5; lwz 11,0x0(9); lha 3,0x38(11); lwz 0,0x3c(11); add 3,9,3; mtspr 8,0; blrl; lwz 31,0x8(3); cmpwi 29,0; ble 1f; lwz 9,0x28(31); li 0,0; cmpwi 9,0; beq 0f; lwz 0,-4(9); 0:; cmpw 29,0; ble 2f; 1:; li 3,0; b 3f; 2:; addi 30,27,76; mr 4,28; mr 3,30; addi 29,29,-1; bl _s801447BC_0; rlwinm 29,29,3,0,28; lwz 9,0x28(31); mr 3,30; add 9,9,29; lhz 4,0x6(9); bl _s801447BC_1; lwz 11,0x28(31); li 3,1; add 11,11,29; lwz 9,0x0(11); lwz 10,0x4(11); stw 9,0x54(27); stw 10,0x58(27); 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801447BC_0();
extern "C" void _s801447BC_1();
extern "C" void f_801447BC() {}
