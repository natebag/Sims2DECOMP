// 0x80072E30 SimModel::RebuildModified(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 28,0; li 30,0; addi 29,31,104; 0:; lwz 3,0x0(29); addi 28,28,1; addi 29,29,4; cmpwi 3,0; beq 1f; lwz 3,0x120(3); cmpwi 3,0; beq 1f; lwzx 0,30,31; andi. 9,0,4; mcrf cr7,cr0; andi. 9,0,2; beq 1f; bne cr7,1f; bl _s80072E30_0; 1:; lwzx 0,30,31; cmplwi 28,25; rlwinm 0,0,0,31,29; stwx 0,30,31; addi 30,30,4; ble 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80072E30_0();

struct SimModel {
    void RebuildModified();
};

void SimModel::RebuildModified() {
}
