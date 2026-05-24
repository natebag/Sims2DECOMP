// 0x802F0678 EAnimController::GetNodeMatrix(int) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,0x10(3); cmpwi 0,0; beq 1f; cmpwi 4,0; blt 1f; lwz 9,0x24(3); cmpwi 9,0; li 0,0; beq 0f; lwz 0,0x18(9); 0:; cmpw 4,0; bge 1f; lwz 0,0x10(3); rlwinm 3,4,6,0,25; add 3,0,3; b 3f; 1:; lwz 0,-22728(13); cmpwi 0,0; bne 2f; li 0,1; stw 0,-22728(13); 2:; lis 30,-32693; addi 3,30,-10912; bl _s802F0678_0; addi 3,30,-10912; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802F0678_0();

struct EAnimController {
    void GetNodeMatrix();
};

void EAnimController::GetNodeMatrix() {
}
