// 0x80193928 CASTarget::GetVariable(char (592 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,3; mr 31,4; li 3,32; bl _s80193928_0; mr 29,3; li 0,0; lis 3,-32705; stb 0,0x0(29); addi 3,3,-16488; mr 4,31; bl _s80193928_1; cmpwi 3,0; bne 5f; lwz 9,0x90(30); li 31,0; addi 9,9,-16; cmplwi 9,1; ble 2f; addi 3,30,168; addi 7,30,184; lwz 5,0xc(7); lwz 9,0xc(3); lwz 6,0x4(7); lwz 8,0xb8(30); subf 9,9,5; lwz 11,0x8(3); srawi 9,9,2; lwz 10,0xa8(30); addi 9,9,-1; subf 0,6,8; rlwinm 9,9,5,0,26; subf 11,10,11; srawi 0,0,2; srawi 11,11,2; add 9,9,0; add 9,9,11; cmpwi 9,0; beq 2f; lwz 0,0x8(7); cmpw 8,6; addi 10,1,8; stw 8,0x8(1); stw 0,0x10(1); stw 6,0xc(1); stw 5,0x14(1); bne 0f; addi 0,5,-4; stw 0,0x14(1); lwz 9,-4(5); addi 11,9,128; stw 9,0xc(1); stw 11,0x10(1); lwz 0,0x8(10); stw 0,0x8(1); 0:; lwz 9,0x8(1); addi 0,9,-4; stw 0,0x8(1); lwz 11,0x10(3); lwz 0,0x14(3); lwz 31,-4(9); cmpw 11,0; beq 1f; addi 0,11,-4; stw 0,0x10(3); b 2f; 1:; bl _s80193928_2; 2:; cmpwi 31,-1; beq 3f; lis 5,-32705; mr 6,31; addi 5,5,-15596; mr 3,29; li 4,32; crxor 6,6,6; bl _s80193928_3; li 0,0; stb 0,0x1f(29); b 12f; 3:; lwz 0,0x90(30); cmpwi 0,13; bne 12f; mr 3,30; bl _s80193928_4; cmpwi 3,0; bne 6f; 4:; lis 9,-32705; addi 4,9,-15588; b 7f; 5:; lis 3,-32705; mr 4,31; addi 3,3,-15584; bl _s80193928_5; cmpwi 3,0; bne 8f; lwz 0,0x104(30); cmpwi 0,1; beq 4b; 6:; lis 9,-32705; addi 4,9,-15592; 7:; mr 3,29; bl _s80193928_6; b 12f; 8:; lis 3,-32705; mr 4,31; addi 3,3,-16444; li 5,10; bl _s80193928_7; cmpwi 3,0; bne 9f; lwz 0,0x1348(30); andi. 9,0,64; beq 12f; lis 9,-32705; addi 11,9,-15564; lwz 10,-15564(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(29); sth 0,0x4(29); stb 8,0x6(29); b 12f; 9:; lis 3,-32705; mr 4,31; addi 3,3,-16468; bl _s80193928_8; cmpwi 3,0; bne 12f; lwz 3,0x84(30); bl _s80193928_9; cmpwi 3,0; beq 10f; lis 9,-32705; addi 4,9,-15588; b 11f; 10:; lis 9,-32705; addi 4,9,-15592; 11:; mr 3,29; bl _s80193928_10; 12:; mr 3,29; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80193928_0();
extern "C" void _s80193928_1();
extern "C" void _s80193928_2();
extern "C" void _s80193928_3();
extern "C" void _s80193928_4();
extern "C" void _s80193928_5();
extern "C" void _s80193928_6();
extern "C" void _s80193928_7();
extern "C" void _s80193928_8();
extern "C" void _s80193928_9();
extern "C" void _s80193928_10();
extern "C" void f_80193928() {}
