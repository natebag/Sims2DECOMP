// 0x8036AF4C REffectsSequencer::Load(EFile (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; mr 30,4; bl _s8036AF4C_0; cmpwi 30,0; beq 1f; addi 3,1,8; bl _s8036AF4C_1; lis 5,17747; mr 4,30; addi 3,1,8; ori 5,5,17745; li 6,1; li 7,1; bl _s8036AF4C_2; cmpwi 3,0; bne 0f; addi 3,1,8; li 4,2; bl _s8036AF4C_3; b 1f; 0:; addi 3,1,8; bl _s8036AF4C_4; lwz 0,0x10(31); lwz 9,0x18(1); lwz 11,0x0(31); rlwimi 0,9,8,0,23; stw 0,0x10(31); lha 3,0x70(11); lwz 0,0x74(11); add 3,31,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s8036AF4C_5; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"

extern "C" void _s8036AF4C_0();
extern "C" void _s8036AF4C_1();
extern "C" void _s8036AF4C_2();
extern "C" void _s8036AF4C_3();
extern "C" void _s8036AF4C_4();
extern "C" void _s8036AF4C_5();

struct REffectsSequencer {
    void Load_EFile();
};

void REffectsSequencer::Load_EFile() {
}
