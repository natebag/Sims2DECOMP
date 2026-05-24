// 0x800B2200 ChainResFile::Update(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; li 4,0; li 27,0; bl _s800B2200_0; addi 31,29,16; lwzx 0,31,27; li 28,0; cmpwi 0,0; beq 2f; li 30,0; 0:; lwzx 3,31,30; lwz 9,0xc(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; lwzx 3,31,30; lwz 9,0xc(3); lha 0,0x48(9); lwz 9,0x4c(9); add 3,3,0; mtspr 8,9; blrl; lwzx 3,31,30; bl _s800B2200_1; mr. 3,3; beq 1f; cmpwi 27,0; bne 1f; mr 27,3; 1:; addi 28,28,1; addi 30,30,24; cmpwi 28,7; bgt 2f; addi 31,29,16; lwzx 0,31,30; cmpwi 0,0; bne 0b; 2:; mr 3,29; mr 4,27; bl _s800B2200_2; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800B2200_0();
extern "C" void _s800B2200_1();
extern "C" void _s800B2200_2();

struct ChainResFile {
    void Update();
};

void ChainResFile::Update() {
}
