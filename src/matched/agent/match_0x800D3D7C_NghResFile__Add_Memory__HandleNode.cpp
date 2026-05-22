// 0x800D3D7C NghResFile::Add(Memory::HandleNode (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 27,0xc(1); stw 0,0x24(1); stw 12,0x8(1); mr 29,4; mr 28,6; mr 4,5; li 30,0; bl _s800D3D7C_0; mr 27,3; lwz 31,0x0(27); cmpwi 31,0; beq 2f; lhz 0,0x8(31); cmpwi 7,29,0; cmpw 0,28; beq 1f; 0:; mr 30,31; lwz 31,0x0(31); cmpwi 31,0; beq 2f; lhz 0,0x8(31); cmpw 0,28; bne 0b; 1:; cmpwi 4,31,0; bne cr4,8f; 2:; cmpwi 7,29,0; li 0,0; beq cr7,3f; lwz 0,0x0(29); 3:; cmpwi 0,0; beq 6f; cmpwi 30,0; beq 4f; li 3,12; bl _s800D3D7C_1; li 0,0; mr 31,3; sth 0,0x8(3); stw 0,0x0(3); stw 0,0x4(3); stw 31,0x0(30); b 5f; 4:; li 3,12; bl _s800D3D7C_2; sth 30,0x8(3); mr 31,3; stw 30,0x0(3); stw 30,0x4(3); stw 31,0x0(27); 5:; stw 29,0x4(31); sth 28,0x8(31); b 19f; 6:; beq cr7,19f; lwz 0,0x8(29); cmpwi 0,0; beq 7f; bl _s800D3D7C_3; lwz 4,0x4(29); bl _s800D3D7C_4; 7:; bl _s800D3D7C_5; mr 4,29; bl _s800D3D7C_6; b 19f; 8:; li 0,0; beq cr7,9f; lwz 0,0x0(29); 9:; cmpwi 0,0; bne 16f; beq cr7,11f; lwz 0,0x8(29); cmpwi 0,0; beq 10f; bl _s800D3D7C_7; lwz 4,0x4(29); bl _s800D3D7C_8; 10:; bl _s800D3D7C_9; mr 4,29; bl _s800D3D7C_10; 11:; cmpwi 30,0; beq 12f; lwz 0,0x0(31); stw 0,0x0(30); b 13f; 12:; lwz 0,0x0(31); stw 0,0x0(27); 13:; beq cr4,19f; lwz 30,0x4(31); cmpwi 30,0; beq 15f; lwz 0,0x8(30); cmpwi 0,0; beq 14f; bl _s800D3D7C_11; lwz 4,0x4(30); bl _s800D3D7C_12; 14:; bl _s800D3D7C_13; mr 4,30; bl _s800D3D7C_14; 15:; mr 3,31; bl _s800D3D7C_15; b 19f; 16:; lwz 30,0x4(31); cmpwi 30,0; beq 18f; lwz 0,0x8(30); cmpwi 0,0; beq 17f; bl _s800D3D7C_16; lwz 4,0x4(30); bl _s800D3D7C_17; 17:; bl _s800D3D7C_18; mr 4,30; bl _s800D3D7C_19; 18:; stw 29,0x4(31); 19:; lwz 0,0x24(1); lwz 12,0x8(1); mtspr 8,0; lmw 27,0xc(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s800D3D7C_0();
extern "C" void _s800D3D7C_1();
extern "C" void _s800D3D7C_2();
extern "C" void _s800D3D7C_3();
extern "C" void _s800D3D7C_4();
extern "C" void _s800D3D7C_5();
extern "C" void _s800D3D7C_6();
extern "C" void _s800D3D7C_7();
extern "C" void _s800D3D7C_8();
extern "C" void _s800D3D7C_9();
extern "C" void _s800D3D7C_10();
extern "C" void _s800D3D7C_11();
extern "C" void _s800D3D7C_12();
extern "C" void _s800D3D7C_13();
extern "C" void _s800D3D7C_14();
extern "C" void _s800D3D7C_15();
extern "C" void _s800D3D7C_16();
extern "C" void _s800D3D7C_17();
extern "C" void _s800D3D7C_18();
extern "C" void _s800D3D7C_19();
extern "C" void f_800D3D7C() {}
