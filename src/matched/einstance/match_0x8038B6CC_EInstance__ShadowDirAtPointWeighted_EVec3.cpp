// 0x8038B6CC EInstance::ShadowDirAtPointWeighted(EVec3 (500 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,3,19,29,31; cmpwi 4,7; bne 0f; li 5,4; b 1f; 0:; subfic 5,4,10; 1:; rlwinm 0,3,0,19,31; subfic 3,4,24; li 4,-1; slw 3,4,3; slw 0,0,5; or 0,3,0; rlwinm 31,0,0,8,31; b 4f; rlwinm 4,3,20,28,31; cmpwi 4,12; bne 2f; li 5,0; b 3f; 2:; subfic 5,4,11; 3:; rlwinm 0,3,0,20,31; subfic 3,4,24; li 4,-1; slw 3,4,3; slw 0,0,5; or 0,3,0; rlwinm 31,0,0,8,31; b 4f; lis 3,-32698; crxor 6,6,6; lis 4,-32698; addi 5,4,-25784; addi 3,3,-25832; li 4,1054; bl _s8038B6CC_0; 4:; mr 3,31; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0; blr; mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); lwz 3,-17720(13); lwz 31,0x5ac(3); rlwinm. 0,31,0,31,31; beq 5f; bl _s8038B6CC_1; 5:; rlwinm. 0,31,0,30,30; beq 6f; bl _s8038B6CC_2; 6:; rlwinm. 0,31,0,29,29; beq 7f; bl _s8038B6CC_3; 7:; rlwinm. 0,31,0,28,28; beq 8f; bl _s8038B6CC_4; 8:; rlwinm. 0,31,0,27,27; beq 9f; bl _s8038B6CC_5; 9:; rlwinm. 0,31,0,27,28; beq 10f; bl _s8038B6CC_6; 10:; lwz 3,-17720(13); li 0,0; stw 0,0x5ac(3); lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0; blr; mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); addi 30,5,0; stw 29,0x1c(1); addi 29,4,0; stw 28,0x18(1); addi 28,3,0; lwz 6,-17720(13); lwz 31,0x5ac(6); cmplwi 31,0; beq 17f; rlwinm. 0,31,0,31,31; beq 11f; bl _s8038B6CC_7; 11:; rlwinm. 0,31,0,30,30; beq 12f; bl _s8038B6CC_8; 12:; rlwinm. 0,31,0,29,29; beq 13f; bl _s8038B6CC_9; 13:; rlwinm. 0,31,0,28,28; beq 14f; bl _s8038B6CC_10; 14:; rlwinm. 0,31,0,27,27; beq 15f; bl _s8038B6CC_11; 15:; rlwinm. 0,31,0,27,28; beq 16f; bl _s8038B6CC_12; 16:; lwz 3,-17720(13); li 0,0; stw 0,0x5ac(3); 17:; lwz 3,-17720(13); lwz 0,0x0(3); cmplwi 0,0; bne 18f; bl _s8038B6CC_13; 18:; or 0,29,28; lis 3,-13311; stb 0,-32768(3); sth 30,-32768(3); lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"

extern "C" void _s8038B6CC_0();
extern "C" void _s8038B6CC_1();
extern "C" void _s8038B6CC_2();
extern "C" void _s8038B6CC_3();
extern "C" void _s8038B6CC_4();
extern "C" void _s8038B6CC_5();
extern "C" void _s8038B6CC_6();
extern "C" void _s8038B6CC_7();
extern "C" void _s8038B6CC_8();
extern "C" void _s8038B6CC_9();
extern "C" void _s8038B6CC_10();
extern "C" void _s8038B6CC_11();
extern "C" void _s8038B6CC_12();
extern "C" void _s8038B6CC_13();

struct EInstance {
    void ShadowDirAtPointWeighted_EVec3();
};

void EInstance::ShadowDirAtPointWeighted_EVec3() {
}
