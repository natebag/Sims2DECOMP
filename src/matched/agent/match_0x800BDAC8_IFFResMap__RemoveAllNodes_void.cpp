// 0x800BDAC8 IFFResMap::RemoveAllNodes(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; lwz 28,0x0(27); lwz 29,0x4(27); mr 11,28; cmpw 28,29; beq 5f; lis 31,-17874; ori 31,31,35747; 0:; lwz 9,0x0(11); addi 30,11,24; lwz 0,0x4(11); mr 3,9; cmpw 9,0; beq 2f; 1:; addi 9,9,88; cmpw 9,0; bne 1b; 2:; cmpwi 3,0; beq 4f; lwz 0,0xc(11); subf 0,3,0; mullw 0,0,31; srawi 0,0,3; mulli 4,0,88; cmplwi 4,128; ble 3f; bl _s800BDAC8_0; b 4f; 3:; bl _s800BDAC8_1; 4:; mr 11,30; cmpw 11,29; bne 0b; 5:; stw 28,0x4(27); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800BDAC8_0();
extern "C" void _s800BDAC8_1();
extern "C" void f_800BDAC8() {}
