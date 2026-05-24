// 0x801D21F4 PCTTarget::cCellInfo::GetName(unsigned (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); lwz 0,0x0(3); mr 31,4; cmpwi 0,2; beq 3f; bgt 0f; cmpwi 0,0; beq 7f; cmpwi 0,1; beq 1f; b 7f; 0:; cmpwi 0,3; beq 4f; cmpwi 0,4; beq 4f; b 7f; 1:; lwz 3,0x14(3); cmpwi 31,0; beq 7f; cmpwi 3,0; beq 7f; bl _s801D21F4_0; mr. 3,3; beq 7f; mr 4,3; addi 3,1,8; crxor 6,6,6; bl _s801D21F4_1; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; cmpwi 4,0; li 3,0; beq 8f; mr 3,31; bl _s801D21F4_2; li 3,1; b 8f; 3:; lwz 3,0x14(3); cmpwi 3,0; beq 7f; lwz 3,0x8(3); b 5f; 4:; lwz 3,0x14(3); cmpwi 3,0; beq 7f; lwz 3,0x4(3); 5:; li 4,0; cmpwi 3,0; beq 6f; lwz 4,0x0(3); 6:; mr 3,31; bl _s801D21F4_3; li 3,1; b 8f; 7:; li 3,0; 8:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"

extern "C" void _s801D21F4_0();
extern "C" void _s801D21F4_1();
extern "C" void _s801D21F4_2();
extern "C" void _s801D21F4_3();

struct PCTTarget {
    void cCellInfo__GetName();
};

void PCTTarget::cCellInfo__GetName() {
}
