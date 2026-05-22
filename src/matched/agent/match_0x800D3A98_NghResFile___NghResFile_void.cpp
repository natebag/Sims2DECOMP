// 0x800D3A98 NghResFile::~NghResFile(void) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32698; mr 30,3; addi 9,9,2096; mr 27,4; stw 9,0xc(30); bl _s800D3A98_0; lwz 3,0x138(30); cmpwi 3,0; beq 0f; bl _s800D3A98_1; 0:; lwz 3,0x17c(30); cmpwi 3,0; beq 1f; bl _s800D3A98_2; 1:; addi 28,30,16; addi 31,30,316; addi 29,30,376; 2:; lwz 3,0x0(31); addi 31,31,4; cmpwi 3,0; beq 3f; bl _s800D3A98_3; 3:; cmpw 31,29; ble 2b; lwz 31,0x190(30); cmpwi 31,0; beq 4f; mr 3,31; bl _s800D3A98_4; mr 3,31; bl _s800D3A98_5; li 0,0; stw 0,0x190(30); 4:; lwz 0,0x4(28); lwz 9,0x10(30); cmpw 9,0; beq 6f; 5:; addi 9,9,16; cmpw 9,0; bne 5b; 6:; lwz 3,0x0(28); cmpwi 3,0; beq 8f; lwz 0,0xc(28); subf 0,3,0; rlwinm 4,0,0,0,27; cmplwi 4,128; ble 7f; bl _s800D3A98_6; b 8f; 7:; bl _s800D3A98_7; 8:; mr 3,30; mr 4,27; bl _s800D3A98_8; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800D3A98_0();
extern "C" void _s800D3A98_1();
extern "C" void _s800D3A98_2();
extern "C" void _s800D3A98_3();
extern "C" void _s800D3A98_4();
extern "C" void _s800D3A98_5();
extern "C" void _s800D3A98_6();
extern "C" void _s800D3A98_7();
extern "C" void _s800D3A98_8();
extern "C" void f_800D3A98() {}
