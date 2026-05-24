// 0x80304B98 EController::AddPressedEventData(unsigned (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 30,3; li 31,0; rlwinm. 0,29,31,1,31; beq 1f; 0:; addi 31,31,1; addi 0,31,1; srw. 9,29,0; bne 0b; 1:; lwz 3,0x1fc(30); mr 4,31; bl _s80304B98_0; cmpwi 3,0; bne 2f; lwz 3,0x1fc(30); mr 4,31; li 5,1; bl _s80304B98_1; lwz 3,0x1fc(30); mr 4,31; li 5,1; bl _s80304B98_2; 2:; lwz 9,0x1fc(30); lwz 0,0x8(9); or 0,0,29; stw 0,0x8(9); lwz 11,0x1fc(30); lwz 0,0x10(11); or 0,0,29; stw 0,0x10(11); lwz 9,0x1fc(30); lwz 0,0x18(9); or 0,0,29; stw 0,0x18(9); lwz 11,0x1fc(30); lwz 0,0x0(11); or 0,0,29; stw 0,0x0(11); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80304B98_0();
extern "C" void _s80304B98_1();
extern "C" void _s80304B98_2();

struct EController {
    void AddPressedEventData();
};

void EController::AddPressedEventData() {
}
