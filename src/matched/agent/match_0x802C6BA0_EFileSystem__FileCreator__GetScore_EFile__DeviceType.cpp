// 0x802C6BA0 EFileSystem::FileCreator::GetScore(EFile::DeviceType, (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 0,4; mr 30,5; lwz 4,0x4(29); mr 27,6; mr 5,0; mr 28,7; li 6,8; bl _s802C6BA0_0; mr 31,3; lwz 4,0x8(29); mr 5,30; mr 3,29; li 6,4; bl _s802C6BA0_1; or. 31,31,3; blt 1f; lwz 4,0xc(29); mr 5,27; mr 3,29; li 6,2; bl _s802C6BA0_2; or 31,31,3; cmpwi 28,0; rlwinm 31,31,0,1,31; beq 1f; lbz 0,0x0(28); extsb 0,0; cmpwi 0,0; beq 1f; cmpwi 0,46; bne 0f; addi 28,28,1; 0:; lbz 0,0x10(29); cmpwi 0,0; beq 1f; addi 3,29,16; mr 4,28; li 5,3; bl _s802C6BA0_3; cmpwi 3,0; bne 1f; ori 31,31,1; 1:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802C6BA0_0();
extern "C" void _s802C6BA0_1();
extern "C" void _s802C6BA0_2();
extern "C" void _s802C6BA0_3();
extern "C" void f_802C6BA0() {}
