// 0x8016B768 CasSimPartsS2C::GetSkinTexturesDatasetID(eSkinColorType, (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 28,3; mr 31,4; addi 3,1,8; mr 30,5; mr 29,3; bl _s8016B768_0; addi 3,1,16; bl _s8016B768_1; cmpwi 31,5; bne 0f; lis 4,-32706; mr 3,29; addi 4,4,1792; bl _s8016B768_2; b 2f; 0:; cmpwi 30,0; blt 1f; cmpwi 30,1; ble 1f; cmpwi 30,2; bne 1f; lis 4,-32706; mr 3,29; addi 4,4,1796; bl _s8016B768_3; b 2f; 1:; lis 4,-32706; addi 3,1,8; addi 4,4,1792; bl _s8016B768_4; 2:; addi 0,31,-6; cmplwi 0,4; bgt 3f; lis 4,-32706; addi 3,1,8; addi 4,4,1804; bl _s8016B768_5; 3:; cmpwi 31,0; blt 4f; cmpwi 31,10; li 11,10; bgt 5f; mr 11,31; b 5f; 4:; li 11,0; 5:; lwz 0,0x8(28); addi 3,1,16; cmpwi 0,0; beq 6f; lis 9,-32706; addi 5,9,1824; b 7f; 6:; lis 9,-32706; addi 5,9,1828; 7:; lis 6,-32706; rlwinm 0,11,4,0,27; lwz 7,0x8(1); addi 6,6,-411; lis 4,-32706; add 6,0,6; addi 4,4,1832; crxor 6,6,6; bl _s8016B768_6; lwz 3,0x10(1); bl _s8016B768_7; mr 4,3; mr 3,28; bl _s8016B768_8; lwz 4,0x10(1); mr 30,3; addi 3,1,16; bl _s8016B768_9; lwz 4,0x8(1); mr 3,29; bl _s8016B768_10; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8016B768_0();
extern "C" void _s8016B768_1();
extern "C" void _s8016B768_2();
extern "C" void _s8016B768_3();
extern "C" void _s8016B768_4();
extern "C" void _s8016B768_5();
extern "C" void _s8016B768_6();
extern "C" void _s8016B768_7();
extern "C" void _s8016B768_8();
extern "C" void _s8016B768_9();
extern "C" void _s8016B768_10();
extern "C" void f_8016B768() {}
