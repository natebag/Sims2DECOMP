// 0x80159C84 ObjectDataBehaviorConstants::SetValueCount(int) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 27,4; lwz 3,0x14(28); cmpwi 3,0; beq 0f; bl _s80159C84_0; li 0,0; stw 0,0x14(28); 0:; cmpwi 27,0; lwz 9,0x10(28); mfcr 30; cmpwi 9,0; beq 3f; lwz 0,-8(9); rlwinm 0,0,2,0,29; add 31,9,0; cmpw 9,31; beq 2f; 1:; addi 31,31,-4; li 4,0; mr 3,31; bl _s80159C84_1; lwz 0,0x10(28); cmpw 0,31; bne 1b; 2:; lwz 3,0x10(28); addi 3,3,-8; bl _s80159C84_2; li 0,0; stw 0,0x10(28); 3:; lhz 0,0x4(28); rlwinm 9,27,0,17,31; mtcrf 128,30; rlwinm 0,0,0,0,16; or 0,0,9; sth 0,0x4(28); ble 6f; rlwinm 3,27,1,0,30; addi 30,27,-1; bl _s80159C84_3; stw 3,0x14(28); rlwinm 3,27,2,0,29; addi 3,3,8; bl _s80159C84_4; addi 29,3,8; cmpwi 27,0; stw 27,-8(29); mr 31,29; beq 5f; 4:; mr 3,31; bl _s80159C84_5; addi 31,31,4; cmpwi 30,0; addi 30,30,-1; bne 4b; 5:; stw 29,0x10(28); 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80159C84_0();
extern "C" void _s80159C84_1();
extern "C" void _s80159C84_2();
extern "C" void _s80159C84_3();
extern "C" void _s80159C84_4();
extern "C" void _s80159C84_5();
extern "C" void f_80159C84() {}
