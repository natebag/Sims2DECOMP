// 0x802E2AB8 EEngine::~EEngine(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-26876(13); lis 9,-32697; mr 31,3; addi 9,9,-22776; mr 29,4; stw 9,0x0(31); cmpwi 0,0; bne 0f; bl _s802E2AB8_0; 0:; addi 30,31,52; mr 3,30; bl _s802E2AB8_1; li 4,2; mr 3,30; bl _s802E2AB8_2; lis 9,-32697; mr 3,31; addi 9,9,-24288; stw 9,0x0(31); bl _s802E2AB8_3; andi. 0,29,1; beq 1f; mr 3,31; bl _s802E2AB8_4; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E2AB8_0();
extern "C" void _s802E2AB8_1();
extern "C" void _s802E2AB8_2();
extern "C" void _s802E2AB8_3();
extern "C" void _s802E2AB8_4();
extern "C" void f_802E2AB8() {}
