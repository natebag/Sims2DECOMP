// 0x800B27C4 ChainResFile::GetIndType(short) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 29,3; mr 31,4; li 4,0; bl _s800B27C4_0; li 0,0; addi 30,1,8; stw 0,0x8(1); addi 9,30,8; stw 0,0x4(30); mr 3,29; mr 4,30; stw 0,0x4(9); bl _s800B27C4_1; cmpwi 31,0; ble 2f; lwz 11,0x8(1); lwz 0,0x4(30); mr 3,11; subf 0,11,0; srawi 0,0,2; cmpw 31,0; bgt 2f; addi 9,31,-1; cmpwi 3,0; rlwinm 9,9,2,0,29; lwzx 31,3,9; beq 1f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s800B27C4_2; b 1f; 0:; mr 3,11; bl _s800B27C4_3; 1:; mr 3,31; b 5f; 2:; lwz 3,0x8(1); cmpwi 3,0; beq 4f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 3f; bl _s800B27C4_4; b 4f; 3:; bl _s800B27C4_5; 4:; li 3,0; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s800B27C4_0();
extern "C" void _s800B27C4_1();
extern "C" void _s800B27C4_2();
extern "C" void _s800B27C4_3();
extern "C" void _s800B27C4_4();
extern "C" void _s800B27C4_5();
extern "C" void f_800B27C4() {}
