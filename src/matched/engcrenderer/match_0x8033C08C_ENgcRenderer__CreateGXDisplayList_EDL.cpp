// 0x8033C08C ENgcRenderer::CreateGXDisplayList(EDL (1156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; mfcr 12; stmw 23,0x24(1); stw 0,0x4c(1); stw 12,0x20(1); mr 0,9; mr 30,4; mr 25,5; mr 27,6; lwz 31,0x50(1); li 9,1; lwz 23,0x54(1); mr. 26,10; beq 0f; li 9,2; 0:; cmpwi 3,0,0; beq cr3,1f; addi 9,9,1; 1:; cmpwi 4,8,0; beq cr4,2f; addi 9,9,1; cmpwi 23,0; beq 2f; addi 9,9,1; 2:; cmpwi 27,254; li 0,2; mfcr 28; bgt 3f; li 0,1; 3:; mullw 9,9,0; rlwinm 29,27,0,16,31; mullw 9,9,27; addi 9,9,34; rlwinm 9,9,0,0,26; stw 9,0x0(31); bl _s8033C08C_0; lwz 4,0x0(31); li 6,0; li 7,0; li 5,32; bl _s8033C08C_1; mr 24,3; mr 4,24; mr 3,30; bl _s8033C08C_2; lis 9,-32690; li 4,-1; addi 0,9,-25796; lwz 11,-25796(9); stw 0,0x18(1); lwz 9,0x14(11); lha 3,0x10(11); mtspr 8,9; add 3,3,0; blrl; lwz 5,0x0(31); addi 3,1,8; mr 4,24; bl _s8033C08C_3; addi 11,1,8; ori 0,25,7; lwz 9,0x8(11); rlwinm 31,0,0,24,31; lwz 10,0xc(11); addi 9,9,1; stw 11,-21544(13); cmplw 9,10; ble 4f; bl _s8033C08C_4; 4:; lwz 10,-21544(13); lwz 9,0x8(10); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(10); lwz 11,-21544(13); lwz 9,0x8(11); lwz 0,0xc(11); addi 9,9,2; cmplw 9,0; ble 5f; bl _s8033C08C_5; 5:; lwz 10,-21544(13); rlwinm 0,29,24,8,31; mtcrf 128,28; lwz 9,0x8(10); stb 0,0x0(9); addi 9,9,1; stw 9,0x8(10); lwz 11,-21544(13); lwz 9,0x8(11); stb 29,0x0(9); addi 9,9,1; stw 9,0x8(11); bgt 15f; li 30,0; cmpw 30,27; bge 25f; 6:; lwz 9,-21544(13); rlwinm 31,30,0,24,31; lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,1; cmplw 11,0; ble 7f; bl _s8033C08C_6; 7:; lwz 11,-21544(13); cmpwi 26,0; lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); beq 9f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,1; cmplw 11,0; ble 8f; bl _s8033C08C_7; 8:; lwz 11,-21544(13); lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); 9:; beq cr3,11f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,1; cmplw 11,0; ble 10f; bl _s8033C08C_8; 10:; lwz 11,-21544(13); lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); 11:; beq cr4,14f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,1; cmplw 11,0; ble 12f; bl _s8033C08C_9; 12:; lwz 11,-21544(13); cmpwi 23,0; lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); beq 14f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,1; cmplw 11,0; ble 13f; bl _s8033C08C_10; 13:; lwz 11,-21544(13); lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); 14:; addi 30,30,1; cmpw 30,27; blt 6b; b 25f; 15:; li 28,0; cmpw 28,27; bge 25f; 16:; lwz 9,-21544(13); rlwinm 31,28,0,16,31; lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,2; cmplw 11,0; ble 17f; bl _s8033C08C_11; 17:; lwz 10,-21544(13); rlwinm 30,31,24,8,31; rlwinm 29,31,0,24,31; cmpwi 26,0; lwz 9,0x8(10); stb 30,0x0(9); addi 9,9,1; stw 9,0x8(10); lwz 11,-21544(13); lwz 9,0x8(11); stb 29,0x0(9); addi 9,9,1; stw 9,0x8(11); beq 19f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,2; cmplw 11,0; ble 18f; bl _s8033C08C_12; 18:; lwz 11,-21544(13); lwz 9,0x8(11); stb 30,0x0(9); addi 9,9,1; stw 9,0x8(11); lwz 10,-21544(13); lwz 9,0x8(10); stb 29,0x0(9); addi 9,9,1; stw 9,0x8(10); 19:; beq cr3,21f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,2; cmplw 11,0; ble 20f; bl _s8033C08C_13; 20:; lwz 10,-21544(13); rlwinm 0,31,24,8,31; lwz 9,0x8(10); stb 0,0x0(9); addi 9,9,1; stw 9,0x8(10); lwz 11,-21544(13); lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); 21:; beq cr4,24f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,2; cmplw 11,0; ble 22f; bl _s8033C08C_14; 22:; lwz 10,-21544(13); rlwinm 30,31,24,8,31; rlwinm 31,31,0,24,31; cmpwi 23,0; lwz 9,0x8(10); stb 30,0x0(9); addi 9,9,1; stw 9,0x8(10); lwz 11,-21544(13); lwz 9,0x8(11); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(11); beq 24f; lwz 9,-21544(13); lwz 11,0x8(9); lwz 0,0xc(9); addi 11,11,2; cmplw 11,0; ble 23f; bl _s8033C08C_15; 23:; lwz 11,-21544(13); lwz 9,0x8(11); stb 30,0x0(9); addi 9,9,1; stw 9,0x8(11); lwz 10,-21544(13); lwz 9,0x8(10); stb 31,0x0(9); addi 9,9,1; stw 9,0x8(10); 24:; addi 28,28,1; cmpw 28,27; blt 16b; 25:; bl _s8033C08C_16; bl _s8033C08C_17; lwz 3,0x18(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,24; lwz 0,0x4c(1); lwz 12,0x20(1); mtspr 8,0; lmw 23,0x24(1); mtcrf 24,12; addi 1,1,72"

extern "C" void _s8033C08C_0();
extern "C" void _s8033C08C_1();
extern "C" void _s8033C08C_2();
extern "C" void _s8033C08C_3();
extern "C" void _s8033C08C_4();
extern "C" void _s8033C08C_5();
extern "C" void _s8033C08C_6();
extern "C" void _s8033C08C_7();
extern "C" void _s8033C08C_8();
extern "C" void _s8033C08C_9();
extern "C" void _s8033C08C_10();
extern "C" void _s8033C08C_11();
extern "C" void _s8033C08C_12();
extern "C" void _s8033C08C_13();
extern "C" void _s8033C08C_14();
extern "C" void _s8033C08C_15();
extern "C" void _s8033C08C_16();
extern "C" void _s8033C08C_17();

struct ENgcRenderer {
    void CreateGXDisplayList_EDL();
};

void ENgcRenderer::CreateGXDisplayList_EDL() {
}
