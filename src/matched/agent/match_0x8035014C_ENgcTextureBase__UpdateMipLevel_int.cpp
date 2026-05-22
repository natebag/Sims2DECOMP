// 0x8035014C ENgcTextureBase::UpdateMipLevel(int, (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 27,4; lwz 0,0x8(31); mr 29,5; mr 28,6; andi. 9,0,128; bne 2f; lwz 3,0x78(31); cmpwi 3,0; beq 0f; mr 30,3; b 3f; 0:; lwz 0,0x98(31); cmpwi 0,0; beq 2f; lhz 0,0x16(31); li 4,1; cmplwi 0,1; ble 1f; mr 4,0; 1:; addi 5,1,8; addi 6,1,12; mr 3,31; bl _s8035014C_0; mr 30,3; bl _s8035014C_1; mr 4,30; li 5,32; li 6,0; li 7,0; bl _s8035014C_2; mr 30,3; stw 3,0x78(31); b 3f; 2:; lwz 30,0x74(31); 3:; mr 4,27; mr 6,28; mr 3,31; mr 5,29; bl _s8035014C_3; lwz 0,0x0(29); add 11,30,3; lbz 9,0x1a(31); mullw 3,0,9; addic. 0,3,7; bge 4f; addi 0,3,14; 4:; srawi 0,0,3; mr 3,11; stw 0,0x0(29); lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8035014C_0();
extern "C" void _s8035014C_1();
extern "C" void _s8035014C_2();
extern "C" void _s8035014C_3();
extern "C" void f_8035014C() {}
