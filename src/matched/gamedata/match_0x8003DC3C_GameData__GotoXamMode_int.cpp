// 0x8003DC3C GameData::GotoXamMode(int, (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 28,0x10(1); stw 0,0x24(1); stw 12,0xc(1); mr 30,4; mr 31,5; mr 29,6; mr 28,7; cmplwi 30,1; bgt 0f; cmplwi 31,13; ble 1f; 0:; li 3,0; b 12f; 1:; cmpwi 31,11; bne 4f; cmpwi 4,30,0; bne cr4,2f; lis 3,-32707; li 4,1; addi 3,3,7856; bl _s8003DC3C_0; b 3f; 2:; lis 3,-32707; li 4,1; addi 3,3,7868; bl _s8003DC3C_1; 3:; lis 3,-32707; mr 4,29; addi 3,3,7880; bl _s8003DC3C_2; b 6f; 4:; cmpwi 4,30,0; bne cr4,5f; lis 3,-32707; li 4,0; addi 3,3,7856; bl _s8003DC3C_3; b 6f; 5:; lis 3,-32707; li 4,0; addi 3,3,7868; bl _s8003DC3C_4; 6:; li 4,0; bne cr4,7f; lis 9,-32707; addi 3,9,7896; b 8f; 7:; lis 9,-32707; addi 3,9,7908; 8:; cmpwi 3,31,12; bne cr3,9f; cmpwi 4,31,13; li 4,1; b 10f; 9:; cmpwi 4,31,13; bne cr4,10f; li 4,2; 10:; bl _s8003DC3C_5; li 31,0; lis 3,-32707; mr 4,29; addi 3,3,7880; bl _s8003DC3C_6; bgt cr4,11f; blt cr3,11f; lis 9,-32707; lis 3,-32707; addi 31,9,7920; addi 3,3,7660; mr 4,30; bl _s8003DC3C_7; mr 3,28; bl _s8003DC3C_8; 11:; cmpwi 31,0; li 3,1; beq 12f; mr 3,31; bl _s8003DC3C_9; li 3,1; 12:; lwz 0,0x24(1); lwz 12,0xc(1); mtspr 8,0; lmw 28,0x10(1); mtcrf 24,12; addi 1,1,32"

extern "C" void _s8003DC3C_0();
extern "C" void _s8003DC3C_1();
extern "C" void _s8003DC3C_2();
extern "C" void _s8003DC3C_3();
extern "C" void _s8003DC3C_4();
extern "C" void _s8003DC3C_5();
extern "C" void _s8003DC3C_6();
extern "C" void _s8003DC3C_7();
extern "C" void _s8003DC3C_8();
extern "C" void _s8003DC3C_9();

struct GameData {
    void GotoXamMode();
};

void GameData::GotoXamMode() {
}
