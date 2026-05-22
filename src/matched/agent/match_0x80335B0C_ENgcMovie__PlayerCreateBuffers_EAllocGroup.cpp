// 0x80335B0C ENgcMovie::PlayerCreateBuffers(EAllocGroup (472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lis 9,-32691; mr 28,4; addi 31,9,14656; lwz 0,0xa0(31); cmpwi 0,0; beq 6f; lbz 0,0xa4(31); cmpwi 0,0; bne 6f; lwz 0,0xb0(31); cmpwi 0,0; beq 0f; lwz 4,0x58(31); mr 3,28; li 5,64; addi 4,4,31; rlwinm 4,4,0,0,26; bl _s80335B0C_0; stw 3,0xb4(31); b 2f; 0:; mr 29,31; li 30,0; addi 31,29,256; 1:; lwz 4,0x44(29); mr 3,28; li 5,64; addi 30,30,1; addi 4,4,31; rlwinm 4,4,0,0,26; bl _s80335B0C_1; stw 3,0x0(31); cmplwi 30,9; addi 31,31,12; ble 1b; 2:; lis 9,-32691; li 30,0; addi 9,9,14656; lwz 11,0x80(9); addi 29,9,384; lwz 0,0x84(9); mullw 11,11,0; rlwinm 9,11,30,2,31; addi 11,11,31; addi 9,9,31; rlwinm 27,11,0,0,26; rlwinm 31,9,0,0,26; 3:; li 5,64; mr 4,27; mr 3,28; addi 30,30,1; bl _s80335B0C_2; mr 0,3; mr 4,27; stw 0,-8(29); bl _s80335B0C_3; li 5,64; mr 4,31; mr 3,28; bl _s80335B0C_4; mr 0,3; mr 4,31; stw 0,-4(29); bl _s80335B0C_5; mr 4,31; li 5,64; mr 3,28; bl _s80335B0C_6; mr 0,3; mr 4,31; stw 0,0x0(29); bl _s80335B0C_7; addi 29,29,16; cmplwi 30,2; ble 3b; lis 9,-32691; addi 11,9,14656; lbz 0,0xa7(11); cmpwi 0,0; beq 5f; lwz 9,0x48(11); addi 26,11,432; li 30,0; li 25,0; rlwinm 9,9,2,0,29; mr 31,26; addi 9,9,31; li 29,0; rlwinm 27,9,0,0,26; 4:; mr 3,28; mr 4,27; li 5,64; addi 30,30,1; bl _s80335B0C_8; stw 3,-4(31); cmplwi 30,2; stw 3,-8(31); stwx 25,26,29; addi 31,31,12; addi 29,29,12; ble 4b; 5:; mr 3,28; li 4,4096; li 5,64; bl _s80335B0C_9; lis 9,-32691; stw 3,0x39dc(9); li 3,1; b 7f; 6:; li 3,0; 7:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s80335B0C_0();
extern "C" void _s80335B0C_1();
extern "C" void _s80335B0C_2();
extern "C" void _s80335B0C_3();
extern "C" void _s80335B0C_4();
extern "C" void _s80335B0C_5();
extern "C" void _s80335B0C_6();
extern "C" void _s80335B0C_7();
extern "C" void _s80335B0C_8();
extern "C" void _s80335B0C_9();
extern "C" void f_80335B0C() {}
