// 0x800C2E98 MotiveCurveSet::LoadFromStringSet(char (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr. 0,5; mr 27,3; mtspr 9,0; ble 2f; mr 29,4; mfspr 30,9; li 28,0; 0:; lwz 0,0x0(27); add 31,0,28; mr 3,31; bl _s800C2E98_0; lwz 4,0x0(29); addi 29,29,4; cmpwi 4,0; beq 1f; mr 3,31; bl _s800C2E98_1; 1:; addi 28,28,20; addic. 30,30,-1; bne 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800C2E98_0();
extern "C" void _s800C2E98_1();
extern "C" void f_800C2E98() {}
