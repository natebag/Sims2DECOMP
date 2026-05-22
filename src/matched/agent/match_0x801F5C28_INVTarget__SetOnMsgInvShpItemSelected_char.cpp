// 0x801F5C28 INVTarget::SetOnMsgInvShpItemSelected(char (560 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; addi 30,1,8; lbz 4,0x3251(31); mr 5,30; addi 6,1,16; bl _s801F5C28_0; li 29,1; lwz 0,0x84(31); cmpwi 0,0; bne 0f; li 29,0; 0:; lwz 0,0x10(1); mr 9,0; cmpwi 0,11; beq 6f; bgt 1f; cmpwi 9,9; beq 2f; cmpwi 9,10; beq 5f; b 9f; 1:; cmpwi 9,13; bgt 9f; b 7f; 2:; lwz 5,0x4(30); cmpwi 5,-1; bne 3f; lwz 3,0x90(31); li 4,4; lbz 6,0x3253(31); li 5,-1; bl _s801F5C28_1; li 0,20; b 4f; 3:; lwz 3,0x90(31); li 4,2; lbz 6,0x3253(31); bl _s801F5C28_2; lwz 9,0x8(1); lwz 0,0x4(9); 4:; lwz 4,0x318c(31); mr 5,29; b 8f; 5:; lbz 6,0x3253(31); li 4,5; lwz 5,0x4(30); lwz 3,0x90(31); bl _s801F5C28_3; lwz 9,0x8(1); mr 5,29; lwz 4,0x318c(31); lwz 0,0x0(9); b 8f; 6:; lbz 6,0x3253(31); li 4,3; lwz 5,0x4(30); lwz 3,0x90(31); bl _s801F5C28_4; lwz 9,0x8(1); mr 5,29; lwz 4,0x318c(31); lwz 0,0x0(9); b 8f; 7:; lwz 3,0x8(1); lwz 30,0x90(31); bl _s801F5C28_5; lbz 6,0x3253(31); mr 5,3; li 4,1; mr 3,30; bl _s801F5C28_6; lwz 3,0x8(1); bl _s801F5C28_7; lbz 0,0x3253(31); mr 5,29; lwz 4,0x318c(31); mullw 0,0,3; 8:; lwz 11,-21496(13); subf 4,0,4; stw 4,0x318c(31); lwz 9,0x0(11); lha 3,0xd0(9); lwz 0,0xd4(9); add 3,11,3; mtspr 8,0; blrl; mr 3,31; bl _s801F5C28_8; bl _s801F5C28_9; mr 4,3; mr 3,31; bl _s801F5C28_10; b 11f; 9:; cmplwi 9,14; ble 10f; li 0,0; b 12f; 10:; lwz 3,0x8(1); li 0,1; stb 0,0x3253(31); lwz 30,0x90(31); bl _s801F5C28_11; lbz 6,0x3252(31); mr 4,3; lbz 5,0x3253(31); mr 3,30; bl _s801F5C28_12; lwz 3,0x8(1); bl _s801F5C28_13; lbz 0,0x3253(31); mr 5,29; lwz 4,0x318c(31); mullw 0,0,3; lwz 11,-21496(13); subf 4,0,4; stw 4,0x318c(31); lwz 9,0x0(11); lha 3,0xd0(9); lwz 0,0xd4(9); add 3,11,3; mtspr 8,0; blrl; mr 3,31; bl _s801F5C28_14; bl _s801F5C28_15; mr 4,3; mr 3,31; bl _s801F5C28_16; 11:; li 0,0; stb 0,0x3252(31); 12:; stb 0,0x3251(31); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801F5C28_0();
extern "C" void _s801F5C28_1();
extern "C" void _s801F5C28_2();
extern "C" void _s801F5C28_3();
extern "C" void _s801F5C28_4();
extern "C" void _s801F5C28_5();
extern "C" void _s801F5C28_6();
extern "C" void _s801F5C28_7();
extern "C" void _s801F5C28_8();
extern "C" void _s801F5C28_9();
extern "C" void _s801F5C28_10();
extern "C" void _s801F5C28_11();
extern "C" void _s801F5C28_12();
extern "C" void _s801F5C28_13();
extern "C" void _s801F5C28_14();
extern "C" void _s801F5C28_15();
extern "C" void _s801F5C28_16();
extern "C" void f_801F5C28() {}
