// 0x803691B0 ERDataset::TryIncrementSubResources(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; lis 0,-21846; addi 10,31,20; lwz 11,0x14(31); lwz 9,0x4(10); ori 0,0,43691; li 29,0; subf 9,11,9; mullw 9,9,0; rlwinm. 0,9,30,2,31; beq 2f; lis 28,-21846; mr 27,10; ori 28,28,43691; li 30,0; 0:; lwz 4,0x14(31); add 5,4,30; lwz 0,0x8(5); cmpwi 0,0; bne 1f; lwz 3,0x4(5); cmpwi 3,0; beq 1f; lwzx 4,4,30; cmpwi 4,0; beq 1f; addi 5,5,8; bl _s803691B0_0; cmpwi 3,0; bne 1f; lwz 9,0x0(31); lha 3,0x68(9); lwz 0,0x6c(9); add 3,31,3; mtspr 8,0; blrl; li 3,0; b 3f; 1:; lwz 0,0x4(27); addi 29,29,1; lwz 9,0x14(31); addi 30,30,12; subf 0,9,0; mullw 0,0,28; srawi 0,0,2; cmplw 29,0; blt 0b; 2:; li 3,1; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s803691B0_0();

struct ERDataset {
    void TryIncrementSubResources();
};

void ERDataset::TryIncrementSubResources() {
}
