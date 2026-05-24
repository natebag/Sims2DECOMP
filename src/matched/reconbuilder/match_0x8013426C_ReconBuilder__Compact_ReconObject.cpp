// 0x8013426C ReconBuilder::Compact(ReconObject (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 25,0x3c(1); stw 0,0x5c(1); mr 26,3; mr 28,4; addi 3,1,8; mr 27,5; bl _s8013426C_0; lwz 9,0x0(28); addi 4,1,8; mr 5,27; lha 3,0x10(9); lwz 0,0x14(9); add 3,28,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; lwz 25,0x8(3); bl _s8013426C_1; bl _s8013426C_2; addi 30,25,12; li 4,12; li 5,0; bl _s8013426C_3; mr 31,3; cmpwi 30,0; stw 30,0x0(31); beq 0f; bl _s8013426C_4; mr 4,30; li 5,0; bl _s8013426C_5; stw 3,0x4(31); b 1f; 0:; stw 30,0x4(31); 1:; li 0,1; cmpwi 31,0; stw 0,0x8(31); beq 2f; lwz 30,0x4(31); li 0,0; stb 0,0x3(30); addi 29,30,4; stb 0,0x0(30); stb 0,0x1(30); stb 0,0x2(30); stw 27,0x4(30); lwz 9,0x0(28); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,28,3; blrl; stw 3,0x8(30); li 6,1; li 7,0; addi 3,1,8; mr 5,25; addi 4,30,12; bl _s8013426C_6; lwz 9,0x0(28); addi 4,1,8; mr 5,27; lha 3,0x10(9); lwz 0,0x14(9); add 3,28,3; mtspr 8,0; blrl; mr 3,26; addi 4,30,8; bl _s8013426C_7; mr 4,30; mr 3,26; bl _s8013426C_8; mr 3,26; mr 4,29; bl _s8013426C_9; addi 3,1,8; li 4,2; bl _s8013426C_10; mr 3,31; b 3f; 2:; li 3,0; 3:; lwz 0,0x5c(1); mtspr 8,0; lmw 25,0x3c(1); addi 1,1,88"

extern "C" void _s8013426C_0();
extern "C" void _s8013426C_1();
extern "C" void _s8013426C_2();
extern "C" void _s8013426C_3();
extern "C" void _s8013426C_4();
extern "C" void _s8013426C_5();
extern "C" void _s8013426C_6();
extern "C" void _s8013426C_7();
extern "C" void _s8013426C_8();
extern "C" void _s8013426C_9();
extern "C" void _s8013426C_10();

struct ReconBuilder {
    void Compact_ReconObject();
};

void ReconBuilder::Compact_ReconObject() {
}
