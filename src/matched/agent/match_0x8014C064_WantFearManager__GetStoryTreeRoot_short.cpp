// 0x8014C064 WantFearManager::GetStoryTreeRoot(short, (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 10,4; li 7,0; lwz 9,0x4(10); mr 29,3; addi 31,1,8; lwz 0,0x10(9); cmplw 7,0; bge 3f; mr 28,31; li 8,0; 0:; lwz 11,0x14(10); add 9,11,8; lha 0,0x2(9); cmpw 0,5; bne 2f; lha 0,0x4(9); cmpw 0,6; bne 2f; lhzx 4,11,8; mr 3,10; bl _s8014C064_0; mr 30,3; li 4,0; bl _s8014C064_1; mr 31,3; bl _s8014C064_2; lbz 0,0xb(3); li 7,0; cmpwi 0,2; bne 1f; lhz 7,0x8(31); 1:; lhz 4,0x0(30); mr 6,31; addi 3,1,8; li 5,0; bl _s8014C064_3; lwz 0,0x8(28); lwz 9,0x8(1); lwz 11,0x4(28); b 4f; 2:; lwz 9,0x4(10); addi 7,7,1; addi 8,8,6; lwz 0,0x10(9); cmplw 7,0; blt 0b; 3:; addi 3,1,8; bl _s8014C064_4; lwz 0,0x8(31); lwz 9,0x8(1); lwz 11,0x4(31); 4:; stw 9,0x0(29); stw 11,0x4(29); stw 0,0x8(29); mr 3,29; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8014C064_0();
extern "C" void _s8014C064_1();
extern "C" void _s8014C064_2();
extern "C" void _s8014C064_3();
extern "C" void _s8014C064_4();
extern "C" void f_8014C064() {}
