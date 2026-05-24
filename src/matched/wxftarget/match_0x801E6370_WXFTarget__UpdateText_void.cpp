// 0x801E6370 WXFTarget::UpdateText(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); lis 9,-32705; lis 11,-32705; mr 30,3; addi 31,9,25920; addi 29,11,25940; addi 3,1,8; bl _s801E6370_0; addi 3,1,8; bl _s801E6370_1; lwz 0,0x8c(30); cmpwi 0,0; bne 0f; addi 3,1,8; li 5,0; mr 4,31; bl _s801E6370_2; addi 3,1,8; li 4,1; bl _s801E6370_3; mr 4,29; addi 3,1,8; li 5,0; bl _s801E6370_4; addi 3,1,8; li 4,0; bl _s801E6370_5; b 1f; 0:; cmpwi 0,1; bne 1f; addi 3,1,8; li 5,0; mr 4,31; bl _s801E6370_6; addi 3,1,8; li 4,0; bl _s801E6370_7; mr 4,29; addi 3,1,8; li 5,0; bl _s801E6370_8; addi 3,1,8; li 4,1; bl _s801E6370_9; 1:; addi 3,1,8; bl _s801E6370_10; addi 3,1,8; li 4,2; bl _s801E6370_11; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"

extern "C" void _s801E6370_0();
extern "C" void _s801E6370_1();
extern "C" void _s801E6370_2();
extern "C" void _s801E6370_3();
extern "C" void _s801E6370_4();
extern "C" void _s801E6370_5();
extern "C" void _s801E6370_6();
extern "C" void _s801E6370_7();
extern "C" void _s801E6370_8();
extern "C" void _s801E6370_9();
extern "C" void _s801E6370_10();
extern "C" void _s801E6370_11();

struct WXFTarget {
    void UpdateText();
};

void WXFTarget::UpdateText() {
}
