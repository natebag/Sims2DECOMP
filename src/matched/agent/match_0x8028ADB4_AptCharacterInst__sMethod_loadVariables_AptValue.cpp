// 0x8028ADB4 AptCharacterInst::sMethod_loadVariables(AptValue (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; cmpwi 4,0; ble 0f; lis 30,-32694; lis 10,-32700; lwz 11,-16032(30); addi 29,1,8; addi 30,30,-16032; lhz 9,-6476(10); lwz 0,0x8(30); rlwinm 11,11,2,0,29; addi 9,9,1; addi 8,10,-6476; add 11,11,0; mr 4,29; lwz 3,-4(11); sth 9,-6476(10); stw 8,0x8(1); bl _s8028ADB4_0; mr 4,31; mr 3,30; mr 6,29; li 5,0; bl _s8028ADB4_1; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028ADB4_2; 0:; lwz 3,-22936(13); lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8028ADB4_0();
extern "C" void _s8028ADB4_1();
extern "C" void _s8028ADB4_2();
extern "C" void f_8028ADB4() {}
