// 0x802C7120 EFileSystem::RegisterFileCreator(EFile::DeviceType, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 10,4; mr 0,5; mr 9,6; mr 11,7; mr 29,3; mr 4,8; mr 6,0; mr 7,9; mr 5,10; mr 8,11; addi 3,1,8; li 31,0; bl _s802C7120_0; addi 9,29,4; lwz 0,0x4(9); cmpw 31,0; bge 1f; mr 28,9; li 30,0; 0:; lwz 4,0x4(29); addi 3,1,8; add 4,4,30; bl _s802C7120_1; cmpwi 3,0; bne 2f; lwz 0,0x4(28); addi 31,31,1; addi 30,30,20; cmpw 31,0; blt 0b; 1:; addi 3,29,4; addi 4,1,8; bl _s802C7120_2; 2:; li 3,1; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s802C7120_0();
extern "C" void _s802C7120_1();
extern "C" void _s802C7120_2();
extern "C" void f_802C7120() {}
