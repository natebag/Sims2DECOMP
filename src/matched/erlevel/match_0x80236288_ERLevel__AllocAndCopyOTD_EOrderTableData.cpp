// 0x80236288 ERLevel::AllocAndCopyOTD(EOrderTableData (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; bl _s80236288_0; mr. 3,3; bne 0f; li 3,0; b 2f; 0:; mr 4,31; mr 9,3; li 11,48; 1:; lwz 0,0x0(4); addic. 11,11,-24; stw 0,0x0(9); lwz 0,0x4(4); stw 0,0x4(9); lwz 0,0x8(4); stw 0,0x8(9); lwz 0,0xc(4); stw 0,0xc(9); lwz 0,0x10(4); stw 0,0x10(9); lwz 0,0x14(4); addi 4,4,24; stw 0,0x14(9); addi 9,9,24; bne 1b; lwz 0,0x0(4); stw 0,0x0(9); lwz 0,0x4(4); stw 0,0x4(9); 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80236288_0();

struct ERLevel {
    void AllocAndCopyOTD_EOrderTableData();
};

void ERLevel::AllocAndCopyOTD_EOrderTableData() {
}
