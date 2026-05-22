// 0x8019D1F8 CASMorphTarget::GetVariable(char (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 30,4; li 3,32; bl _s8019D1F8_0; li 0,0; mr 28,3; stb 0,0x0(28); lwz 3,0x84(29); bl _s8019D1F8_1; mr 31,3; mr 4,30; lis 3,-32705; li 5,14; addi 3,3,-13380; bl _s8019D1F8_2; cmpwi 3,0; bne 13f; mr 3,30; bl _s8019D1F8_3; cmpwi 3,15; bne 13f; lbz 0,0xe(30); extsb 0,0; cmpwi 0,72; beq 0f; cmpwi 0,86; bne 13f; 0:; lwz 3,0x8c(29); lis 9,-32705; lfs f1,-13360(9); cmpwi 3,3; beq 3f; cmplwi 3,3; ble 1f; cmpwi 3,5; beq 7f; cmplwi 3,5; blt 6f; cmpwi 3,6; beq 8f; cmpwi 3,7; beq 9f; b 12f; 1:; cmpwi 3,1; beq 2f; cmplwi 3,1; bgt 5f; lfs f0,0xf8(31); b 4f; 2:; lfs f0,0xfc(31); b 4f; 3:; lfs f0,0x100(31); 4:; lis 9,-32705; lfs f13,-13356(9); fsubs f0,f0,f1; fmuls f1,f0,f13; b 12f; 5:; lfs f0,0x104(31); lis 9,-32705; lfs f13,-13352(9); b 11f; 6:; lfs f0,0x108(31); b 10f; 7:; lfs f0,0x10c(31); b 10f; 8:; lfs f0,0x110(31); b 10f; 9:; lfs f0,0x114(31); 10:; lis 9,-32705; lfs f13,-13348(9); 11:; fsubs f0,f0,f1; fdivs f1,f0,f13; 12:; lis 5,-32705; addi 5,5,-13364; mr 3,28; li 4,32; creqv 6,6,6; bl _s8019D1F8_4; b 15f; 13:; lis 3,-32705; mr 4,30; addi 3,3,-13580; li 5,12; bl _s8019D1F8_5; cmpwi 3,0; bne 15f; lbz 0,0x8c(31); li 6,0; cmpwi 0,0; beq 14f; li 6,1; 14:; lis 5,-32705; mr 3,28; addi 5,5,-15596; li 4,32; crxor 6,6,6; bl _s8019D1F8_6; 15:; li 0,0; mr 3,28; stb 0,0x1f(28); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8019D1F8_0();
extern "C" void _s8019D1F8_1();
extern "C" void _s8019D1F8_2();
extern "C" void _s8019D1F8_3();
extern "C" void _s8019D1F8_4();
extern "C" void _s8019D1F8_5();
extern "C" void _s8019D1F8_6();
extern "C" void f_8019D1F8() {}
