// 0x801D22FC PCTTarget::cCellInfo::GetDesc(unsigned (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); lwz 0,0x0(3); mr 31,4; cmpwi 0,1; bne 1f; lwz 3,0x14(3); cmpwi 31,0; beq 1f; cmpwi 3,0; beq 1f; bl _s801D22FC_0; mr. 3,3; beq 1f; mr 4,3; addi 3,1,8; crxor 6,6,6; bl _s801D22FC_1; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,31; bl _s801D22FC_2; li 3,1; b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"

extern "C" void _s801D22FC_0();
extern "C" void _s801D22FC_1();
extern "C" void _s801D22FC_2();

struct PCTTarget {
    void cCellInfo__GetDesc();
};

void PCTTarget::cCellInfo__GetDesc() {
}
