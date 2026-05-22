// 0x8031146C EResourceLoaderImpl::allocateGlobalIndex(void) (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-360(1); mfspr 0,8; stmw 19,0x134(1); stw 0,0x16c(1); mr 24,3; li 28,0; addi 23,24,852; bl _s8031146C_0; lis 19,-32702; addi 31,1,8; lis 20,-32702; addi 27,1,288; lis 22,-32694; lis 21,-32702; addi 25,1,16; 0:; mr 3,31; addi 4,19,1092; bl _s8031146C_1; cmpwi 28,0; ble 1f; lis 4,-32702; mr 3,25; addi 4,4,1104; mr 5,28; crxor 6,6,6; bl _s8031146C_2; mr 3,31; mr 4,25; bl _s8031146C_3; 1:; mr 3,31; addi 4,20,1108; bl _s8031146C_4; li 30,10; addi 26,28,1; 2:; lwz 5,0x8(1); addi 3,22,-10620; mr 4,27; addi 6,21,1116; lis 7,-32768; lis 8,-32768; li 9,0; bl _s8031146C_5; lwz 0,0x120(1); cmpwi 0,0; bne 3f; addic. 30,30,-1; bgt 2b; b 4f; 3:; addi 30,1,32; addi 3,1,296; mr 4,30; rlwinm 28,28,2,0,29; bl _s8031146C_6; lwz 11,0x120(1); mr 4,30; li 5,4; lwz 9,0x28(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,0x120(1); addi 4,1,36; lwz 9,0x128(1); lwz 11,0x28(10); lwz 30,0x0(9); lwz 0,0x1c(11); lha 3,0x18(11); addi 30,30,1; rlwinm 30,30,2,0,29; mtspr 8,0; add 3,10,3; mr 5,30; addi 30,30,4; blrl; lwz 11,0x128(1); lwz 9,0x0(11); rlwinm 9,9,2,0,29; add 9,9,11; lwz 29,0x4(9); bl _s8031146C_7; mr 4,29; li 5,0; bl _s8031146C_8; mr 0,3; addi 4,1,32; mr 5,30; stwx 0,23,28; bl _s8031146C_9; lwz 11,0x120(1); subf 5,30,29; lwzx 4,23,28; lwz 9,0x28(11); add 4,4,30; lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; addi 3,22,-10620; mr 4,27; bl _s8031146C_10; 4:; addi 3,1,8; mr 28,26; bl _s8031146C_11; lwz 4,0x8(1); mr 3,31; bl _s8031146C_12; cmpwi 28,1; ble 0b; lwz 30,0x348(24); cmpwi 30,0; beq 6f; mr 29,31; 5:; lwz 4,0x40(30); mr 3,29; bl _s8031146C_13; mr 4,29; mr 3,24; bl _s8031146C_14; stw 3,0x4c(30); mr 3,29; lwz 4,0x8(1); bl _s8031146C_15; lwz 30,0xd04(30); cmpwi 30,0; bne 5b; 6:; lwz 0,0x16c(1); mtspr 8,0; lmw 19,0x134(1); addi 1,1,360"
extern "C" void _s8031146C_0();
extern "C" void _s8031146C_1();
extern "C" void _s8031146C_2();
extern "C" void _s8031146C_3();
extern "C" void _s8031146C_4();
extern "C" void _s8031146C_5();
extern "C" void _s8031146C_6();
extern "C" void _s8031146C_7();
extern "C" void _s8031146C_8();
extern "C" void _s8031146C_9();
extern "C" void _s8031146C_10();
extern "C" void _s8031146C_11();
extern "C" void _s8031146C_12();
extern "C" void _s8031146C_13();
extern "C" void _s8031146C_14();
extern "C" void _s8031146C_15();
extern "C" void f_8031146C() {}
