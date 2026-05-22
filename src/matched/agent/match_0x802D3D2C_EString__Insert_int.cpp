// 0x802D3D2C EString::Insert(int, (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 31,4; mr 27,5; bl _s802D3D2C_0; cmpw 31,3; ble 0f; mr 3,28; bl _s802D3D2C_1; mr 31,3; 0:; mr 3,28; bl _s802D3D2C_2; addi 30,3,1; mr 4,30; mr 3,28; bl _s802D3D2C_3; mr 29,3; subf 5,31,30; add 3,29,31; mr 4,3; addi 3,3,1; bl _s802D3D2C_4; stbx 27,29,31; mr 3,28; bl _s802D3D2C_5; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802D3D2C_0();
extern "C" void _s802D3D2C_1();
extern "C" void _s802D3D2C_2();
extern "C" void _s802D3D2C_3();
extern "C" void _s802D3D2C_4();
extern "C" void _s802D3D2C_5();
extern "C" void f_802D3D2C() {}
