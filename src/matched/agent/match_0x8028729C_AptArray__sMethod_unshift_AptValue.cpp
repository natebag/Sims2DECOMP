// 0x8028729C AptArray::sMethod_unshift(AptValue (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 30,3; mr 29,4; lwz 9,0x0(30); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 6f; lwz 4,0x2c(30); mr 3,30; add 4,4,29; bl _s8028729C_0; cmpwi 29,0; beq 2f; lwz 4,0x24(30); rlwinm 3,29,2,0,29; lwz 5,0x2c(30); li 31,0; add 3,4,3; rlwinm 5,5,2,0,29; bl _s8028729C_1; lwz 0,0x2c(30); cmpw 31,29; add 0,0,29; stw 0,0x2c(30); bge 2f; lis 27,-32694; li 25,0; addi 26,27,-16032; li 28,0; 1:; lwz 9,0x24(30); mr 4,31; mr 3,30; stwx 25,28,9; addi 28,28,4; lwz 9,-16032(27); lwz 0,0x8(26); subf 9,31,9; rlwinm 9,9,2,0,29; addi 31,31,1; add 9,9,0; lwz 5,-4(9); bl _s8028729C_2; cmpw 31,29; blt 1b; 2:; lwz 3,-26908(13); lwz 31,0x2c(30); cmpwi 3,0; beq 5f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 4:; stw 31,0xc(3); b 7f; 5:; lwz 3,-23020(13); li 4,16; bl _s8028729C_3; mr 30,3; li 4,7; bl _s8028729C_4; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 3,30; stw 9,0x8(30); b 7f; 6:; lwz 3,-22936(13); 7:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8028729C_0();
extern "C" void _s8028729C_1();
extern "C" void _s8028729C_2();
extern "C" void _s8028729C_3();
extern "C" void _s8028729C_4();
extern "C" void f_8028729C() {}
