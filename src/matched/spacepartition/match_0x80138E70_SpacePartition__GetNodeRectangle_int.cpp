// 0x80138E70 SpacePartition::GetNodeRectangle(int, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,5; cmpwi 4,-1; li 3,0; beq 1f; mr 3,31; bl _s80138E70_0; mr. 3,3; beq 0f; lwz 3,0x4(3); cmpwi 3,0; blt 0f; lwz 10,0xc(31); lis 9,-13108; lwz 0,0x10(31); ori 9,9,52429; subf 0,10,0; mullw 0,0,9; srawi 0,0,2; cmplw 3,0; bge 0f; mulli 11,3,20; li 3,1; lwzx 8,10,11; add 9,10,11; lwz 0,0xc(9); lwz 11,0x4(9); lwz 10,0x8(9); stw 0,0xc(30); stw 8,0x0(30); stw 11,0x4(30); stw 10,0x8(30); b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80138E70_0();

struct SpacePartition {
    void GetNodeRectangle();
};

void SpacePartition::GetNodeRectangle() {
}
