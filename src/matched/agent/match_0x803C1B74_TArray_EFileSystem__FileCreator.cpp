// 0x803C1B74 TArray<EFileSystem::FileCreator, (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 26,0x10(1); stw 0,0x2c(1); stw 12,0xc(1); mr 31,3; mr 27,6; lwz 30,0x4(31); mr 26,4; lwz 0,0x8(31); mr 29,5; add 9,30,27; cmpw 9,0; ble 2f; li 5,1; cmpw cr4,29,30; cmpw 5,9; mulli 28,29,20; bge 1f; 0:; add 5,5,5; cmpw 5,9; blt 0b; 1:; mr 4,9; mr 3,31; bl _s803C1B74_0; b 3f; 2:; mulli 0,30,20; lwz 3,0x0(31); subf 4,30,9; stw 9,0x4(31); mulli 28,29,20; cmpw cr4,29,30; add 3,3,0; bl _s803C1B74_1; 3:; beq cr4,4f; mulli 0,27,20; lwz 3,0x0(31); subf 5,29,30; add 3,3,28; mr 4,3; add 3,3,0; bl _s803C1B74_2; 4:; lwz 3,0x0(31); mr 4,26; mr 5,27; add 3,3,28; bl _s803C1B74_3; lwz 0,0x2c(1); lwz 12,0xc(1); mtspr 8,0; lmw 26,0x10(1); mtcrf 8,12; addi 1,1,40"
extern "C" void _s803C1B74_0();
extern "C" void _s803C1B74_1();
extern "C" void _s803C1B74_2();
extern "C" void _s803C1B74_3();
extern "C" void f_803C1B74() {}
