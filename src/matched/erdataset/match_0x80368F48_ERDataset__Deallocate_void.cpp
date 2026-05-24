// 0x80368F48 ERDataset::Deallocate(void) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 30,3; lwz 9,0x0(30); lwz 0,0x6c(9); lha 3,0x68(9); mtspr 8,0; add 3,30,3; blrl; li 0,0; addi 6,1,8; stw 0,0x8(1); addi 10,6,8; stw 0,0x4(6); addi 7,30,28; stw 0,0x4(10); lwz 0,0x18(30); lwz 9,0x14(30); lwz 11,0x8(1); lwz 8,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x14(30); lwz 0,0x4(10); stw 8,0x18(30); stw 0,0x24(1); lwz 9,0x1c(30); lwz 0,0x4(7); stw 9,0x8(6); stw 0,0x4(10); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x1c(30); stw 0,0x4(7); lwz 0,0x4(6); lwz 9,0x8(1); cmpw 9,0; beq 1f; 0:; addi 9,9,12; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(6); cmpwi 3,0; beq 3f; lwz 0,0xc(6); lis 9,-21846; ori 9,9,43691; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,12; cmplwi 4,128; ble 2f; bl _s80368F48_0; b 3f; 2:; bl _s80368F48_1; 3:; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"

extern "C" void _s80368F48_0();
extern "C" void _s80368F48_1();

struct ERDataset {
    void Deallocate();
};

void ERDataset::Deallocate() {
}
