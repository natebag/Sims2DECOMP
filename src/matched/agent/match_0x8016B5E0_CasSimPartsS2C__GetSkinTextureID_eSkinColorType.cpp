// 0x8016B5E0 CasSimPartsS2C::GetSkinTextureID(eSkinColorType, (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 27,3; mr 31,4; addi 3,1,8; mr 30,5; mr 28,3; mr 29,6; bl _s8016B5E0_0; addi 3,1,16; bl _s8016B5E0_1; cmpwi 31,5; bne 0f; lis 4,-32706; mr 3,28; addi 4,4,1792; bl _s8016B5E0_2; b 2f; 0:; cmpwi 30,0; blt 1f; cmpwi 30,1; ble 1f; cmpwi 30,2; bne 1f; lis 4,-32706; mr 3,28; addi 4,4,1796; bl _s8016B5E0_3; b 2f; 1:; lis 4,-32706; addi 3,1,8; addi 4,4,1792; bl _s8016B5E0_4; 2:; addi 0,31,-6; cmplwi 0,4; bgt 3f; lis 4,-32706; addi 3,1,8; addi 4,4,1804; bl _s8016B5E0_5; 3:; cmpwi 29,0; blt 4f; cmpwi 29,3; li 10,3; bgt 5f; mr 10,29; b 5f; 4:; li 10,0; 5:; cmpwi 31,0; blt 6f; cmpwi 31,10; li 11,10; bgt 7f; mr 11,31; b 7f; 6:; li 11,0; 7:; lwz 0,0x8(27); addi 3,1,16; cmpwi 0,0; beq 8f; lis 9,-32706; addi 5,9,1824; b 9f; 8:; lis 9,-32706; addi 5,9,1828; 9:; lis 6,-32707; lis 7,-32706; rlwinm 0,10,2,0,29; rlwinm 9,11,4,0,27; lwz 8,0x8(1); addi 6,6,21862; addi 7,7,-411; lis 4,-32706; add 6,0,6; add 7,9,7; addi 4,4,1812; crxor 6,6,6; bl _s8016B5E0_6; lwz 3,0x10(1); bl _s8016B5E0_7; mr 4,3; mr 3,27; bl _s8016B5E0_8; lwz 4,0x10(1); mr 30,3; addi 3,1,16; bl _s8016B5E0_9; lwz 4,0x8(1); mr 3,28; bl _s8016B5E0_10; mr 3,30; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s8016B5E0_0();
extern "C" void _s8016B5E0_1();
extern "C" void _s8016B5E0_2();
extern "C" void _s8016B5E0_3();
extern "C" void _s8016B5E0_4();
extern "C" void _s8016B5E0_5();
extern "C" void _s8016B5E0_6();
extern "C" void _s8016B5E0_7();
extern "C" void _s8016B5E0_8();
extern "C" void _s8016B5E0_9();
extern "C" void _s8016B5E0_10();
extern "C" void f_8016B5E0() {}
