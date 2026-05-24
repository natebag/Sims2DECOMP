// 0x80117EFC cTrack::SetRegister(int, (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,4; mr 29,5; mr 30,3; mr 4,29; li 5,0; bl _s80117EFC_0; li 28,1; cmpwi 31,12; beq 8f; bgt 1f; cmpwi 31,9; beq 4f; bgt 0f; cmpwi 31,1; blt 15f; b 3f; 0:; cmpwi 31,10; beq 5f; cmpwi 31,11; beq 7f; b 15f; 1:; cmpwi 31,15; beq 12f; bgt 2f; cmpwi 31,13; beq 10f; cmpwi 31,14; beq 11f; b 15f; 2:; cmpwi 31,16; beq 13f; cmpwi 31,17; beq 14f; b 15f; 3:; addi 0,31,-1; addi 9,30,84; rlwinm 0,0,2,0,29; stwx 29,9,0; b 15f; 4:; stw 29,0x74(30); b 6f; 5:; stw 29,0x78(30); 6:; mr 3,30; bl _s80117EFC_1; mr 28,3; b 15f; 7:; stw 29,0x7c(30); mr 4,29; lfs f1,0x4c(30); mr 3,30; bl _s80117EFC_2; mr. 28,3; beq 16f; mr 3,30; bl _s80117EFC_3; b 15f; 8:; lwz 0,0x34(30); cmpwi 0,0; beq 9f; cmpwi 29,0; beq 9f; stw 28,0x80(30); b 15f; 9:; li 0,0; stw 0,0x80(30); b 15f; 10:; stw 29,0x84(30); b 15f; 11:; stw 29,0x88(30); b 15f; 12:; stw 29,0x8c(30); b 15f; 13:; stw 29,0x90(30); b 15f; 14:; lwz 3,-24136(13); mr 5,29; mr 4,30; bl _s80117EFC_4; 15:; cmpwi 28,0; bne 17f; 16:; lis 4,-32706; mr 3,30; addi 4,4,-14912; bl _s80117EFC_5; 17:; mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80117EFC_0();
extern "C" void _s80117EFC_1();
extern "C" void _s80117EFC_2();
extern "C" void _s80117EFC_3();
extern "C" void _s80117EFC_4();
extern "C" void _s80117EFC_5();

struct cTrack {
    void SetRegister();
};

void cTrack::SetRegister() {
}
