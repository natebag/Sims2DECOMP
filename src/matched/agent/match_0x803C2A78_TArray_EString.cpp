// 0x803C2A78 TArray<EString, (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 26,0x10(1); stw 0,0x2c(1); stw 12,0xc(1); mr 31,3; mr 27,6; lwz 30,0x4(31); mr 26,4; lwz 0,0x8(31); mr 29,5; add 9,30,27; cmpw 9,0; ble 2f; li 5,1; cmpw cr4,29,30; cmpw 5,9; rlwinm 28,29,2,0,29; bge 1f; 0:; add 5,5,5; cmpw 5,9; blt 0b; 1:; mr 4,9; mr 3,31; bl _s803C2A78_0; b 3f; 2:; lwz 0,0x0(31); rlwinm 3,30,2,0,29; subf 4,30,9; stw 9,0x4(31); add 3,0,3; bl _s803C2A78_1; cmpw cr4,29,30; rlwinm 28,29,2,0,29; 3:; beq cr4,4f; lwz 4,0x0(31); rlwinm 3,27,2,0,29; subf 5,29,30; add 4,4,28; add 3,4,3; bl _s803C2A78_2; 4:; lwz 3,0x0(31); mr 4,26; mr 5,27; add 3,3,28; bl _s803C2A78_3; lwz 0,0x2c(1); lwz 12,0xc(1); mtspr 8,0; lmw 26,0x10(1); mtcrf 8,12; addi 1,1,40"
extern "C" void _s803C2A78_0();
extern "C" void _s803C2A78_1();
extern "C" void _s803C2A78_2();
extern "C" void _s803C2A78_3();
extern "C" void f_803C2A78() {}
