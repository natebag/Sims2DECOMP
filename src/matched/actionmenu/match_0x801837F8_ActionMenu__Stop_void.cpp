// 0x801837F8 ActionMenu::Stop(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; addi 30,31,12; bl _s801837F8_0; mr 3,30; bl _s801837F8_1; li 8,7; li 0,0; li 9,1; mtspr 9,8; stb 9,0x8(31); li 10,0; stw 30,0x70(31); addi 11,31,146; sth 0,0x90(31); addi 9,31,116; sth 0,0x4(31); sth 0,0x6(31); stb 0,0x9(31); 0:; stw 10,0x0(9); sth 10,0x0(11); addi 9,9,4; addi 11,11,2; bdnz 0b; lwz 9,0xac(31); li 0,0; li 30,0; stb 0,0xa2(31); cmpwi 9,0; stb 0,0xa0(31); stw 30,0xa4(31); beq 1f; lwz 4,0xa8(31); lwz 3,-26524(13); bl _s801837F8_2; lwz 4,0xac(31); bl _s801837F8_3; stw 30,0xac(31); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801837F8_0();
extern "C" void _s801837F8_1();
extern "C" void _s801837F8_2();
extern "C" void _s801837F8_3();

struct ActionMenu {
    void Stop();
};

void ActionMenu::Stop() {
}
