// 0x80132F4C ReconBuffer::ReconCmprInt(int (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 31,3; mr 28,4; lwz 9,0xc(31); mr 29,5; addi 9,9,-1; cmplwi 9,1; bgt 10f; lwz 9,0x0(28); li 0,1; stw 0,0x8(1); cmpwi 9,0; bne 0f; stw 9,0x8(1); 0:; mr 3,31; li 4,1; addi 5,1,8; bl _s80132F4C_0; lwz 0,0x8(1); cmpwi 0,0; beq 12f; lwz 0,0x4(29); li 10,0; lwz 11,0x0(28); and 9,11,0; cmpw 9,0; beq 1f; cmpwi 9,0; bne 2f; 1:; li 10,1; 2:; cmpwi 10,0; li 0,0; bne 9f; lwz 0,0xc(29); li 10,0; and 9,11,0; cmpw 9,0; beq 3f; cmpwi 9,0; bne 4f; 3:; li 10,1; 4:; cmpwi 10,0; li 0,1; bne 9f; lwz 0,0x14(29); li 10,0; and 9,11,0; cmpw 9,0; beq 5f; cmpwi 9,0; bne 6f; 5:; li 10,1; 6:; cmpwi 10,0; li 0,2; bne 9f; lwz 0,0x1c(29); li 10,0; and 9,11,0; cmpw 9,0; beq 7f; cmpwi 9,0; bne 8f; 7:; li 10,1; 8:; cmpwi 10,0; li 0,4; beq 9f; li 0,3; 9:; stw 0,0xc(1); mr 3,31; li 4,2; addi 5,1,12; bl _s80132F4C_1; lwz 0,0xc(1); mr 3,31; mr 5,28; rlwinm 0,0,3,0,28; lwzx 4,29,0; bl _s80132F4C_2; b 12f; 10:; mr 3,31; li 4,1; addi 5,1,16; bl _s80132F4C_3; lwz 0,0x10(1); cmpwi 0,0; beq 11f; addi 5,1,20; mr 3,31; li 4,2; bl _s80132F4C_4; lwz 30,0x14(1); mr 5,28; mr 3,31; rlwinm 30,30,3,0,28; lwzx 4,29,30; add 30,29,30; bl _s80132F4C_5; lwz 5,0x4(30); lwz 0,0x0(28); and. 9,0,5; beq 12f; or 0,0,5; 11:; stw 0,0x0(28); 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s80132F4C_0();
extern "C" void _s80132F4C_1();
extern "C" void _s80132F4C_2();
extern "C" void _s80132F4C_3();
extern "C" void _s80132F4C_4();
extern "C" void _s80132F4C_5();
extern "C" void f_80132F4C() {}
