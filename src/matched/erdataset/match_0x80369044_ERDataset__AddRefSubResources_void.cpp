// 0x80369044 ERDataset::AddRefSubResources(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; lis 0,-21846; addi 10,28,20; lwz 11,0x14(28); lwz 9,0x4(10); ori 0,0,43691; li 29,0; subf 9,11,9; mullw 9,9,0; rlwinm. 0,9,30,2,31; beq 2f; lis 27,-21846; mr 26,10; ori 27,27,43691; li 30,0; 0:; lwz 4,0x14(28); add 31,4,30; lwz 0,0x8(31); cmpwi 0,0; bne 1f; lwz 3,0x4(31); cmpwi 3,0; beq 1f; lwzx 4,4,30; cmpwi 4,0; beq 1f; li 5,0; li 6,0; bl _s80369044_0; stw 3,0x8(31); 1:; lwz 0,0x4(26); addi 29,29,1; lwz 9,0x14(28); addi 30,30,12; subf 0,9,0; mullw 0,0,27; srawi 0,0,2; cmplw 29,0; blt 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80369044_0();

struct ERDataset {
    void AddRefSubResources();
};

void ERDataset::AddRefSubResources() {
}
