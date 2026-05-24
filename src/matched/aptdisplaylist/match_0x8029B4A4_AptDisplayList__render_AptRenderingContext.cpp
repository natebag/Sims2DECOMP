// 0x8029B4A4 AptDisplayList::render(AptRenderingContext (628 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stmw 26,0x90(1); stw 0,0xac(1); lwz 9,0x0(3); addi 10,1,8; lwz 8,-27588(13); li 0,0; lwz 11,0x0(9); mr 29,10; mr 28,4; mr 26,5; lwz 30,0x54(11); andi. 9,8,4; stw 0,0x80(10); beq 0f; lis 9,-32726; addi 27,9,-20268; b 11f; 0:; lis 9,-32726; addi 27,9,-20444; b 11f; 1:; lwz 0,0x0(30); andis. 9,0,2048; beq 10f; mr 3,30; li 31,0; bl _s8029B4A4_0; cmpwi 3,19; bne 2f; mr 3,30; bl _s8029B4A4_1; subfic 0,3,0; adde 31,0,3; 2:; cmpwi 31,0; bne 10f; lwz 10,0x4c(30); lwz 6,0x0(10); cmpwi 6,0; blt 7f; lwz 7,0x80(29); li 8,0; cmpw 8,7; bge 4f; lwz 9,0x0(29); lwz 11,0x4c(9); lwz 0,0x0(11); cmpw 0,6; blt 4f; mr 5,7; mr 6,10; mr 7,29; 3:; addi 8,8,1; cmpw 8,5; bge 4f; lwzu 11,0x4(7); lwz 10,0x0(6); lwz 9,0x4c(11); lwz 0,0x0(9); cmpw 0,10; bge 3b; 4:; lwz 11,0x80(29); rlwinm 10,8,2,0,29; cmpw 11,8; ble 6f; rlwinm 0,11,2,0,29; add 9,0,29; 5:; lwz 0,-4(9); addi 11,11,-1; cmpw 11,8; stw 0,0x0(9); addi 9,9,-4; bgt 5b; 6:; stwx 30,29,10; mr 3,28; mr 4,30; li 5,1; lwz 9,0x80(29); mtspr 8,27; addi 9,9,1; stw 9,0x80(29); blrl; b 10f; 7:; lwz 9,0x80(29); cmpwi 9,0; ble 9f; addi 0,9,-1; lwz 11,0x58(30); rlwinm 0,0,2,0,29; lwzx 10,29,0; srawi 11,11,15; lwz 9,0x4c(10); lwz 0,0x0(9); cmpw 0,11; bge 9f; mr 31,29; 8:; lwz 9,0x80(31); mr 3,28; li 5,-1; mtspr 8,27; addi 9,9,-1; rlwinm 9,9,2,0,29; lwzx 4,31,9; blrl; lwz 9,0x80(29); addi 9,9,-1; stw 9,0x80(29); cmpwi 9,0; ble 9f; addi 0,9,-1; lwz 11,0x58(30); rlwinm 0,0,2,0,29; lwzx 10,29,0; srawi 11,11,15; lwz 9,0x4c(10); lwz 0,0x0(9); cmpw 0,11; blt 8b; 9:; mr 3,28; mr 4,30; mr 5,26; mtspr 8,27; blrl; 10:; lwz 30,0x54(30); 11:; cmpwi 30,0; bne 1b; lwz 0,0x80(29); cmpwi 0,0; ble 15f; 12:; mr 3,28; lwz 4,0x8(1); li 5,-1; mtspr 8,27; blrl; lwz 0,0x80(29); li 10,0; addic. 9,0,-1; ble 14f; mr 11,29; 13:; lwz 0,0x4(11); addi 10,10,1; stw 0,0x0(11); addi 11,11,4; lwz 9,0x80(29); addi 9,9,-1; cmpw 10,9; blt 13b; 14:; lwz 9,0x80(29); addi 9,9,-1; cmpwi 9,0; stw 9,0x80(29); bgt 12b; 15:; lwz 0,0xac(1); mtspr 8,0; lmw 26,0x90(1); addi 1,1,168"

extern "C" void _s8029B4A4_0();
extern "C" void _s8029B4A4_1();

struct AptDisplayList {
    void render_AptRenderingContext();
};

void AptDisplayList::render_AptRenderingContext() {
}
