// 0x801E5CBC WXFTarget::SetVariable(char (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 3,-28720(13); mr 29,5; bl _s801E5CBC_0; cmpwi 3,0; bne 0f; lwz 0,0x128(30); cmpwi 0,0; bne 5f; mr 3,30; bl _s801E5CBC_1; b 5f; 0:; lis 3,-32705; mr 4,31; addi 3,3,26108; bl _s801E5CBC_2; cmpwi 3,0; bne 1f; mr 3,30; mr 4,31; mr 5,29; bl _s801E5CBC_3; b 5f; 1:; lwz 3,-28724(13); mr 4,31; bl _s801E5CBC_4; cmpwi 3,0; bne 2f; mr 3,30; mr 4,31; mr 5,29; bl _s801E5CBC_5; b 5f; 2:; lis 3,-32705; mr 4,31; addi 3,3,26128; bl _s801E5CBC_6; cmpwi 3,0; bne 3f; mr 3,30; mr 4,31; mr 5,29; bl _s801E5CBC_7; b 5f; 3:; lis 3,-32705; mr 4,31; addi 3,3,26144; bl _s801E5CBC_8; cmpwi 3,0; bne 4f; mr 3,30; mr 4,31; mr 5,29; bl _s801E5CBC_9; b 5f; 4:; lwz 3,-28716(13); mr 4,31; bl _s801E5CBC_10; cmpwi 3,0; bne 5f; mr 3,30; bl _s801E5CBC_11; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801E5CBC_0();
extern "C" void _s801E5CBC_1();
extern "C" void _s801E5CBC_2();
extern "C" void _s801E5CBC_3();
extern "C" void _s801E5CBC_4();
extern "C" void _s801E5CBC_5();
extern "C" void _s801E5CBC_6();
extern "C" void _s801E5CBC_7();
extern "C" void _s801E5CBC_8();
extern "C" void _s801E5CBC_9();
extern "C" void _s801E5CBC_10();
extern "C" void _s801E5CBC_11();

struct WXFTarget {
    void SetVariable();
};

void WXFTarget::SetVariable() {
}
