// 0x802F03B4 EAnimController::Draw(ERC (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x60(31); mr 30,5; mr 4,6; cmpwi 0,0; beq 2f; lwz 5,-26812(13); bl _s802F03B4_0; lwz 7,0x24(31); lwz 5,0x10(31); lwz 6,0xc(31); cmpwi 7,0; beq 0f; lwz 7,0x18(7); b 1f; 0:; li 7,0; 1:; mr 3,30; mr 4,29; bl _s802F03B4_1; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s802F03B4_0();
extern "C" void _s802F03B4_1();

struct EAnimController {
    void Draw_ERC();
};

void EAnimController::Draw_ERC() {
}
