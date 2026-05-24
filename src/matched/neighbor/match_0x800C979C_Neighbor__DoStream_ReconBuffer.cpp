// 0x800C979C Neighbor::DoStream(ReconBuffer (752 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 25,0x34(1); stw 0,0x54(1); mr 25,5; mr 29,3; mr 28,4; cmpwi 25,29; bgt 0f; li 0,0; stw 0,0x28(1); b 1f; 0:; li 0,4; mr 3,28; stw 0,0x28(1); addi 4,1,40; li 5,1; bl _s800C979C_0; 1:; addi 31,29,40; mr 3,28; mr 4,31; bl _s800C979C_1; mr 3,28; addi 4,29,20; li 5,1; bl _s800C979C_2; mr 3,28; mr 4,29; li 5,1; bl _s800C979C_3; lwz 0,0x0(29); cmpwi 0,0; beq 2f; mr 3,28; addi 4,29,112; li 5,80; bl _s800C979C_4; 2:; mr 3,28; addi 4,29,272; li 5,16; bl _s800C979C_5; mr 3,28; addi 4,29,336; li 5,16; bl _s800C979C_6; mr 3,28; addi 4,29,4; li 5,1; bl _s800C979C_7; mr 3,28; addi 4,29,8; li 5,1; bl _s800C979C_8; lwz 0,0xc(28); cmpwi 0,0; bne 3f; lwz 3,-21508(13); lwz 4,0x8(29); lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; stw 3,0xc(29); 3:; lwz 0,0x28(1); cmpwi 0,1; bgt 4f; lwz 0,0xc(29); cmpwi 0,0; beq 4f; mr 3,31; bl _s800C979C_9; cmpwi 3,0; bne 4f; lwz 3,0xc(29); mr 4,31; bl _s800C979C_10; 4:; lwz 3,0x10(29); mr 4,28; mr 5,25; lwz 9,0x0(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 25,94; ble 5f; mr 3,28; addi 4,29,436; li 5,1; bl _s800C979C_11; b 6f; 5:; li 0,0; stw 0,0x1b4(29); 6:; cmpwi 25,93; ble 14f; li 11,7; addi 27,1,8; mtspr 9,11; lha 0,-21220(13); mr 9,27; 7:; stw 0,0x0(9); addi 9,9,4; bdnz 7b; lha 26,-21222(13); li 31,0; li 30,0; 8:; lwz 3,0x194(29); mr 4,28; mr 5,25; add 3,3,30; bl _s800C979C_12; lwz 0,0xc(28); cmpwi 0,1; bne 9f; lwz 4,0x194(29); mr 3,29; add 4,4,30; bl _s800C979C_13; cmpw 3,26; beq 9f; rlwinm 0,3,2,0,29; stwx 31,27,0; 9:; addi 31,31,1; addi 30,30,12; cmplwi 31,19; ble 8b; mr 3,28; addi 4,1,8; li 5,7; bl _s800C979C_14; lwz 0,0xc(28); cmpwi 0,0; bne 20f; li 0,7; lha 7,-21220(13); mtspr 9,0; mr 8,27; addi 10,29,408; li 6,0; li 11,0; 10:; lwzx 9,11,8; cmpw 9,7; beq 11f; cmpwi 9,0; blt 11f; cmpwi 9,19; ble 12f; 11:; stwx 6,11,10; b 13f; 12:; mulli 9,9,12; lwz 0,0x194(29); add 0,0,9; stwx 0,11,10; 13:; addi 11,11,4; bdnz 10b; b 15f; 14:; mr 3,29; bl _s800C979C_15; 15:; lwz 0,0xc(28); cmpwi 0,0; bne 20f; li 30,0; addi 31,29,408; 16:; lwz 9,0x0(31); addi 31,31,4; cmpwi 9,0; beq 18f; lwz 0,0x4(9); li 9,1; cmpwi 0,0; bne 17f; li 9,0; 17:; cmpwi 9,0; bne 19f; 18:; mr 3,29; mr 4,30; bl _s800C979C_16; 19:; addi 30,30,1; cmpwi 30,6; ble 16b; 20:; lwz 0,0x54(1); mtspr 8,0; lmw 25,0x34(1); addi 1,1,80"

extern "C" void _s800C979C_0();
extern "C" void _s800C979C_1();
extern "C" void _s800C979C_2();
extern "C" void _s800C979C_3();
extern "C" void _s800C979C_4();
extern "C" void _s800C979C_5();
extern "C" void _s800C979C_6();
extern "C" void _s800C979C_7();
extern "C" void _s800C979C_8();
extern "C" void _s800C979C_9();
extern "C" void _s800C979C_10();
extern "C" void _s800C979C_11();
extern "C" void _s800C979C_12();
extern "C" void _s800C979C_13();
extern "C" void _s800C979C_14();
extern "C" void _s800C979C_15();
extern "C" void _s800C979C_16();

struct Neighbor {
    void DoStream_ReconBuffer();
};

void Neighbor::DoStream_ReconBuffer() {
}
