// 0x80188FC8 HUDTarget::RemoveAllActions(int) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mulli 9,4,796; mr 11,3; li 10,1; add 9,9,11; lwz 0,0x10c(9); cmpwi 0,0; bne 0f; li 10,0; 0:; cmpwi 10,0; beq 1f; mulli 3,4,796; addi 3,3,264; add 3,11,3; bl _s80188FC8_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s80188FC8_0();

struct HUDTarget {
    void RemoveAllActions();
};

void HUDTarget::RemoveAllActions() {
}
