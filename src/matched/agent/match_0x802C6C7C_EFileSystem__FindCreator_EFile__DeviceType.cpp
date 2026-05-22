// 0x802C6C7C EFileSystem::FindCreator(EFile::DeviceType, (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 29,3; li 31,0; lwz 28,0x8(29); mr 22,4; mr 23,6; mr 24,7; rlwinm 25,5,0,24,31; li 26,-1; li 27,-1; cmpw 31,28; bge 2f; li 30,0; 0:; lwz 3,0x4(29); mr 4,22; mr 5,25; mr 6,23; add 3,3,30; mr 7,24; bl _s802C6C7C_0; cmpw 3,27; ble 1f; mr 27,3; mr 26,31; 1:; addi 31,31,1; addi 30,30,20; cmpw 31,28; blt 0b; 2:; cmpwi 26,0; blt 3f; mulli 0,26,20; lwz 3,0x4(29); add 3,3,0; bl _s802C6C7C_1; b 5f; 3:; bl _s802C6C7C_2; cmpwi 3,0; beq 4f; li 9,0; stw 9,0x0(9); 4:; .long 0x00000001; li 3,0; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s802C6C7C_0();
extern "C" void _s802C6C7C_1();
extern "C" void _s802C6C7C_2();
extern "C" void f_802C6C7C() {}
