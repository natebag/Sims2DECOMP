// 0x80201F9C RGTTarget::SetupNames(int) (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 16,0x38(1); stw 0,0x7c(1); addi 26,1,8; addi 28,1,40; lis 20,-32704; lis 21,-32704; addi 25,20,-30484; mr 29,26; mr 22,28; addi 23,21,-17576; mr 27,3; mr 18,4; li 30,0; lis 24,-32704; addi 19,1,48; lis 16,-32697; addi 31,1,24; lis 17,-32704; 0:; lwz 10,-30484(20); mr 5,30; lbz 0,0xa(25); addi 4,24,-30472; lwz 11,0x4(25); mr 3,22; lhz 9,0x8(25); stw 10,0x8(1); stb 0,0xa(29); stw 11,0x4(29); sth 9,0x8(29); crxor 6,6,6; bl _s80201F9C_0; mr 4,22; mr 3,29; bl _s80201F9C_1; lwz 0,0x8c(27); addi 4,17,-30464; mr 3,26; cmpwi 0,1; bne 1f; bl _s80201F9C_2; 1:; add 4,18,30; mr 3,27; bl _s80201F9C_3; addi 30,30,1; mr 5,3; addi 4,24,-30472; mr 3,28; cmpwi 5,99; bne 2f; li 5,0; 2:; lwz 0,-17576(21); lwz 9,0x4(23); lhz 11,0x8(23); stw 0,0x18(1); stw 9,0x4(31); sth 11,0x8(31); crxor 6,6,6; bl _s80201F9C_4; mr 4,28; mr 3,31; bl _s80201F9C_5; mr 3,19; addi 4,16,24012; mr 5,31; crxor 6,6,6; bl _s80201F9C_6; lwz 9,0x30(1); mr 3,29; li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; bl _s80201F9C_7; cmpwi 30,11; ble 0b; lwz 0,0x7c(1); mtspr 8,0; lmw 16,0x38(1); addi 1,1,120"
extern "C" void _s80201F9C_0();
extern "C" void _s80201F9C_1();
extern "C" void _s80201F9C_2();
extern "C" void _s80201F9C_3();
extern "C" void _s80201F9C_4();
extern "C" void _s80201F9C_5();
extern "C" void _s80201F9C_6();
extern "C" void _s80201F9C_7();
extern "C" void f_80201F9C() {}
