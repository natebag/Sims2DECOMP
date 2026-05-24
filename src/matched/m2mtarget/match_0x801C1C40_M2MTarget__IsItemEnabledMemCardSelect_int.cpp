// 0x801C1C40 M2MTarget::IsItemEnabledMemCardSelect(int) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); li 30,0; cmpwi 4,1; mr 31,3; stw 30,0x8(1); beq 3f; bgt 0f; cmpwi 4,0; beq 1f; b 6f; 0:; cmpwi 4,2; beq 5f; b 6f; 1:; li 3,0; addi 4,1,8; bl _s801C1C40_0; cmpwi 3,1; bne 2f; lwz 0,0x8(1); stw 0,0x178(31); b 8f; 2:; stw 30,0x178(31); stw 30,0x8(1); b 8f; 3:; li 3,1; addi 4,1,8; bl _s801C1C40_1; cmpwi 3,1; bne 4f; lwz 0,0x8(1); stw 0,0x17c(31); b 8f; 4:; stw 30,0x17c(31); stw 30,0x8(1); b 8f; 5:; li 0,1; b 7f; 6:; li 0,0; 7:; stw 0,0x8(1); 8:; lwz 3,0x8(1); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s801C1C40_0();
extern "C" void _s801C1C40_1();

struct M2MTarget {
    void IsItemEnabledMemCardSelect();
};

void M2MTarget::IsItemEnabledMemCardSelect() {
}
