// 0x8034FE3C ENgcTextureBase::Create(ETextureDef (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; li 0,0; stw 0,0x80(31); bl _s8034FE3C_0; cmpwi 3,0; bne 0f; li 3,0; b 4f; 0:; lhz 0,0x16(31); li 4,1; cmplwi 0,1; ble 1f; mr 4,0; 1:; addi 5,1,8; addi 6,1,12; mr 3,31; lis 29,-32692; bl _s8034FE3C_1; lwz 9,-25904(13); mr 30,3; lwz 0,-25900(13); addi 3,29,-7364; addi 9,9,1; mr 4,30; add 0,0,30; stw 9,-25904(13); stw 0,-25900(13); li 5,32; bl _s8034FE3C_2; lwz 0,0x8(31); stw 3,0x74(31); not 0,0; andi. 9,0,128; beq 2f; bl _s8034FE3C_3; mr 4,30; li 5,32; li 6,0; li 7,0; bl _s8034FE3C_4; stw 3,0x78(31); 2:; lwz 9,0x70(31); addi 9,9,-8; cmplwi 9,2; bgt 3f; lhz 9,0x14(31); lbz 0,0x1b(31); mullw 9,9,0; addi 4,9,7; addi 3,29,-7364; rlwinm 4,4,29,3,31; li 5,32; bl _s8034FE3C_5; stw 3,0x90(31); 3:; li 3,1; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8034FE3C_0();
extern "C" void _s8034FE3C_1();
extern "C" void _s8034FE3C_2();
extern "C" void _s8034FE3C_3();
extern "C" void _s8034FE3C_4();
extern "C" void _s8034FE3C_5();
extern "C" void f_8034FE3C() {}
