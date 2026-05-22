// 0x801623A8 CasNpcEditor::~CasNpcEditor(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lis 9,-32698; lwz 4,0x64(31); addi 9,9,24520; addi 3,31,100; stw 9,0x4(31); bl _s801623A8_0; lwz 4,0x60(31); addi 3,31,96; bl _s801623A8_1; lwz 4,0x5c(31); addi 3,31,92; bl _s801623A8_2; lis 9,-32698; andi. 0,30,1; addi 9,9,24424; stw 9,0x4(31); beq 0f; mr 3,31; bl _s801623A8_3; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801623A8_0();
extern "C" void _s801623A8_1();
extern "C" void _s801623A8_2();
extern "C" void _s801623A8_3();
extern "C" void f_801623A8() {}
