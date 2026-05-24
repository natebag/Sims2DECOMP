// 0x8033BBF8 ENgcRenderer::CreateGXDisplayList(EDL (1172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 22,0x28(1); stw 0,0x54(1); stw 12,0x24(1); lwz 23,0x5c(1); mr 28,4; mr 26,5; mr 30,6; mr 24,7; mr 31,8; lwz 29,0x60(1); li 9,1; lwz 22,0x64(1); cmpwi 23,0; beq 0f; li 9,2; 0:; lwz 0,0x58(1); cmpwi 3,0,0; beq cr3,1f; addi 9,9,1; 1:; cmpwi 4,10,0; beq cr4,2f; addi 9,9,1; cmpwi 22,0; beq 2f; addi 9,9,1; 2:; li 0,2; cmpwi 2,31,254; bgt cr2,3f; li 0,1; 3:; mullw 9,9,0; rlwinm 27,31,0,16,31; mullw 9,9,30; addi 9,9,34; rlwinm 9,9,0,0,26; stw 9,0x0(29); bl _s8033BBF8_0; lwz 4,0x0(29); li 6,0; li 7,0; li 5,32; bl _s8033BBF8_1; mr 25,3; mr 4,25; mr 3,28; bl _s8033BBF8_2; lis 9,-32690; li 4,-1; addi 0,9,-25796; lwz 11,-25796(9); stw 0,0x18(1); lwz 9,0x14(11); lha 3,0x10(11); mtspr 8,9; add 3,3,0; blrl; lwz 5,0x0(29); addi 3,1,8; mr 4,25; bl _s8033BBF8_3; addi 11,1,8; ori 0,26,6; lwz 9,0x8(11); rlwinm 31,0,0,24,31; lwz 10,0xc(11); addi 9,9,1; stw 11,-21544(13); cmplw 9,10; ble 4f; bl _s8033BBF8_4; 4:; lwz 10,-21544(13); lwz 9,0x8(10); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(10); lwz 11,-21544(13); lwz 9,0x8(11); lwz 0,0xc(11); addi 9,9,2; cmplw 9,0; ble 5f; bl _s8033BBF8_5; 5:; lwz 10,-21544(13); rlwinm 0,27,24,8,31; lwz 9,0x8(10); stb 0,0x0(9); addi 9,9,1; stw 9,0x8(10); lwz 11,-21544(13); lwz 9,0x8(11); stb 27,0x0(9); addi 9,9,1; stw 9,0x8(11); bgt cr2,15f; cmpwi 30,0; ble 25f; addi 29,24,1; 6:; lwz 11,-21544(13); lbz 10,0x0(29); lwz 9,0x8(11); addi 29,29,2; lwz 0,0xc(11); mr 31,10; addi 9,9,1; cmplw 9,0; ble 7f; bl _s8033BBF8_6; 7:; lwz 11,-21544(13); cmpwi 23,0; lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); beq 9f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,1; cmplw 11,0; ble 8f; bl _s8033BBF8_7; 8:; lwz 11,-21544(13); lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); 9:; beq cr3,11f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,1; cmplw 11,0; ble 10f; bl _s8033BBF8_8; 10:; lwz 11,-21544(13); lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); 11:; beq cr4,14f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,1; cmplw 11,0; ble 12f; bl _s8033BBF8_9; 12:; lwz 11,-21544(13); cmpwi 22,0; lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); beq 14f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,1; cmplw 11,0; ble 13f; bl _s8033BBF8_10; 13:; lwz 11,-21544(13); lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); 14:; addic. 30,30,-1; bne 6b; b 25f; 15:; cmpwi 30,0; ble 25f; cmpwi 2,23,0; mr 27,24; mr 28,30; 16:; lwz 11,-21544(13); lhz 10,0x0(27); lwz 9,0x8(11); addi 27,27,2; lwz 0,0xc(11); mr 31,10; addi 9,9,2; cmplw 9,0; ble 17f; bl _s8033BBF8_11; 17:; lwz 10,-21544(13); rlwinm 0,31,24,8,31; mr 30,0; rlwinm 8,31,0,24,31; lwz 9,0x8(10); mr 31,30; mr 29,8; stb 30,0x0(9); addi 9,9,1; stw 9,0x8(10); lwz 11,-21544(13); lwz 9,0x8(11); stb 8,0x0(9); addi 9,9,1; stw 9,0x8(11); beq cr2,19f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,2; cmplw 11,0; ble 18f; bl _s8033BBF8_12; 18:; lwz 11,-21544(13); lwz 9,0x8(11); stb 30,0x0(9); addi 9,9,1; stw 9,0x8(11); lwz 10,-21544(13); lwz 9,0x8(10); stb 29,0x0(9); addi 9,9,1; stw 9,0x8(10); 19:; beq cr3,21f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,2; cmplw 11,0; ble 20f; bl _s8033BBF8_13; 20:; lwz 11,-21544(13); lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); lwz 10,-21544(13); lwz 9,0x8(10); stb 29,0x0(9); addi 9,9,1; stw 9,0x8(10); 21:; beq cr4,24f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,2; cmplw 11,0; ble 22f; bl _s8033BBF8_14; 22:; lwz 10,-21544(13); cmpwi 22,0; lwz 9,0x8(10); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(10); lwz 11,-21544(13); lwz 9,0x8(11); stb 29,0x0(9); addi 9,9,1; stw 9,0x8(11); beq 24f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,2; cmplw 11,0; ble 23f; bl _s8033BBF8_15; 23:; lwz 11,-21544(13); lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); lwz 10,-21544(13); lwz 9,0x8(10); stb 29,0x0(9); addi 9,9,1; stw 9,0x8(10); 24:; addic. 28,28,-1; bne 16b; 25:; bl _s8033BBF8_16; bl _s8033BBF8_17; lwz 3,0x18(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,25; lwz 0,0x54(1); lwz 12,0x24(1); mtspr 8,0; lmw 22,0x28(1); mtcrf 56,12; addi 1,1,80"

extern "C" void _s8033BBF8_0();
extern "C" void _s8033BBF8_1();
extern "C" void _s8033BBF8_2();
extern "C" void _s8033BBF8_3();
extern "C" void _s8033BBF8_4();
extern "C" void _s8033BBF8_5();
extern "C" void _s8033BBF8_6();
extern "C" void _s8033BBF8_7();
extern "C" void _s8033BBF8_8();
extern "C" void _s8033BBF8_9();
extern "C" void _s8033BBF8_10();
extern "C" void _s8033BBF8_11();
extern "C" void _s8033BBF8_12();
extern "C" void _s8033BBF8_13();
extern "C" void _s8033BBF8_14();
extern "C" void _s8033BBF8_15();
extern "C" void _s8033BBF8_16();
extern "C" void _s8033BBF8_17();

struct ENgcRenderer {
    void CreateGXDisplayList_EDL();
};

void ENgcRenderer::CreateGXDisplayList_EDL() {
}
