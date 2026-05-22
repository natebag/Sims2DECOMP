// 0x80287C0C AptArray::sMethod_slice(AptValue (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; mr 30,4; lwz 9,0x0(27); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 6f; li 31,0; lwz 28,0x2c(27); cmpwi 30,0; ble 1f; lis 9,-32694; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s80287C0C_0; mr. 31,3; bge 1f; lwz 0,0x2c(27); add 31,31,0; 1:; cmpwi 30,1; ble 3f; lis 9,-32694; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); addi 11,11,-1; rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s80287C0C_1; mr. 28,3; bge 2f; lwz 0,0x2c(27); add 28,28,0; b 3f; 2:; lwz 0,0x2c(27); cmpw 28,0; ble 3f; mr 28,0; 3:; cmpw 31,28; mfcr 30; bgt 6f; cmpwi 31,0; blt 6f; cmpwi 28,0; blt 6f; lwz 3,-23016(13); li 4,48; bl _s80287C0C_2; bl _s80287C0C_3; mr 29,3; mtcrf 128,30; bge 5f; rlwinm 30,31,2,0,29; subf 31,31,28; 4:; lwz 9,0x24(27); mr 3,29; lwz 4,0x2c(29); lwzx 5,30,9; addi 30,30,4; bl _s80287C0C_4; addic. 31,31,-1; bne 4b; 5:; mr 3,29; b 7f; 6:; lwz 3,-22936(13); 7:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80287C0C_0();
extern "C" void _s80287C0C_1();
extern "C" void _s80287C0C_2();
extern "C" void _s80287C0C_3();
extern "C" void _s80287C0C_4();
extern "C" void f_80287C0C() {}
