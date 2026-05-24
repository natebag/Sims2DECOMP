// 0x801498B0 TreeTable::GetIndexOfResource(short) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr 5,4; lwz 3,0x0(31); li 4,0; cmpwi 3,0; beq 0f; lwz 4,-4(3); 0:; mulli 4,4,36; add 4,3,4; bl _s801498B0_0; mr. 3,3; beq 1f; lwz 9,0x0(31); lis 0,14563; ori 0,0,36409; subf 9,9,3; mullw 9,9,0; srawi 3,9,2; b 2f; 1:; li 3,-1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801498B0_0();

struct TreeTable {
    void GetIndexOfResource();
};

void TreeTable::GetIndexOfResource() {
}
