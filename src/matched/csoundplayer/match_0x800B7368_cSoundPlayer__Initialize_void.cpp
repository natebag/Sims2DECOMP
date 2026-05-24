// 0x800B7368 cSoundPlayer::Initialize(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; bne 2f; lwz 9,-21436(13); lwz 0,0x2cc(9); cmpwi 0,0; bne 0f; lwz 3,-26564(13); lwz 9,0x0(3); lha 0,0x48(9); lwz 9,0x4c(9); add 3,3,0; mtspr 8,9; blrl; b 1f; 0:; bl _s800B7368_0; stw 3,-24464(13); stw 3,0x4(31); lwz 9,0x0(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x0(31); cmpwi 0,0; bne 1f; lwz 0,0x4(31); cmpwi 0,0; beq 1f; li 30,1; li 3,124; stw 30,0x8(31); bl _s800B7368_1; bl _s800B7368_2; mr 0,3; stw 0,-24508(13); bl _s800B7368_3; stw 30,0x0(31); 1:; lis 3,-32692; lis 4,-32757; addi 3,3,9472; addi 4,4,29196; bl _s800B7368_4; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800B7368_0();
extern "C" void _s800B7368_1();
extern "C" void _s800B7368_2();
extern "C" void _s800B7368_3();
extern "C" void _s800B7368_4();

struct cSoundPlayer {
    void Initialize();
};

void cSoundPlayer::Initialize() {
}
