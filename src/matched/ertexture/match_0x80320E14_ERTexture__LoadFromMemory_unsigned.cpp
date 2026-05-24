// 0x80320E14 ERTexture::LoadFromMemory(unsigned (736 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 21,0x34(1); stw 0,0x64(1); li 0,0; addi 9,1,8; stw 0,0x8(1); li 8,64; li 11,1; li 10,32; mr 24,4; stb 11,0x18(9); stb 10,0x1a(9); mr 22,3; sth 8,0x10(9); mr 10,9; stw 0,0x1c(9); mr 11,24; stw 0,0x4(9); li 7,24; stw 0,0x8(9); sth 8,0x12(9); stb 0,0x19(9); stb 0,0x1b(9); sth 0,0x14(9); sth 0,0x16(9); 0:; lwz 0,0x0(11); addic. 7,7,-24; stw 0,0x0(10); lwz 0,0x4(11); stw 0,0x4(10); lwz 0,0x8(11); stw 0,0x8(10); lwz 0,0xc(11); stw 0,0xc(10); lwz 0,0x10(11); stw 0,0x10(10); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(10); addi 10,10,24; bne 0b; lwz 0,0x0(11); lis 9,-32702; addi 9,9,2752; stw 0,0x0(10); lwz 0,0x4(11); stw 0,0x4(10); stw 9,0x24(1); lhz 9,0x1a(1); lhz 11,0x18(1); lbz 10,0x22(1); mullw 11,11,9; lhz 0,0x1c(1); lbz 9,0x23(1); mullw 0,0,9; mullw 11,11,10; add. 9,11,0; bge 1f; addi 9,9,7; 1:; lwz 0,0x10(22); srawi 9,9,3; lwz 10,0x14(22); addi 24,24,32; rlwimi 0,9,8,0,23; stw 0,0x10(22); cmpwi 10,0; beq 2f; lwz 9,0x24(10); addi 4,1,8; lha 3,0x78(9); lwz 0,0x7c(9); add 3,10,3; mtspr 8,0; blrl; b 3f; 2:; lwz 3,-26392(13); addi 4,1,8; lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; stw 3,0x14(22); 3:; lwz 11,0x14(22); cmpwi 11,0; beq 12f; lwz 9,0x24(11); li 4,2; li 21,1; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,0x1e(1); cmplwi 0,1; ble 4f; mr 21,0; 4:; li 23,0; lhz 27,0x18(1); lhz 31,0x1a(1); cmpw 23,21; bge 10f; 5:; lwz 11,0x14(22); addi 5,1,40; mr 4,23; addi 6,1,44; lwz 9,0x24(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; lbz 0,0x22(1); mr 29,3; mullw 9,27,0; addic. 5,9,7; bge 6f; addi 5,9,14; 6:; lwz 28,0x28(1); srawi 30,5,3; cmpw 30,28; bne 7f; mullw 0,28,31; mr 4,24; srawi 25,27,1; mr 3,29; srawi 26,31,1; addi 27,23,1; mr 5,0; add 24,24,0; bl _s80320E14_0; b 9f; 7:; srawi 25,27,1; cmpwi 31,0; addi 27,23,1; srawi 26,31,1; ble 9f; 8:; mr 3,29; mr 4,24; mr 5,30; add 24,24,30; bl _s80320E14_1; add 29,29,28; addic. 31,31,-1; bne 8b; 9:; mr 23,27; mr 31,26; mr 27,25; cmpw 23,21; blt 5b; 10:; lbz 0,0x21(1); cmpwi 0,0; beq 11f; lwz 3,0x14(22); lwz 9,0x24(3); lha 0,0x48(9); lwz 9,0x4c(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 11f; lhz 9,0x1c(1); lbz 0,0x23(1); mullw 9,9,0; addi 5,9,7; mr 4,24; rlwinm 5,5,29,3,31; bl _s80320E14_2; 11:; lwz 3,0x14(22); lwz 9,0x24(3); lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; 12:; lwz 0,0x64(1); mtspr 8,0; lmw 21,0x34(1); addi 1,1,96"

extern "C" void _s80320E14_0();
extern "C" void _s80320E14_1();
extern "C" void _s80320E14_2();

struct ERTexture {
    void LoadFromMemory();
};

void ERTexture::LoadFromMemory() {
}
