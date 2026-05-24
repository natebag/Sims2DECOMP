// 0x80086848 Wrapper::WrapperShutdown(void) (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 26,0x28(1); stw 0,0x44(1); mr 29,3; addi 28,1,8; addi 9,29,140; lwz 30,0x8c(29); lwz 0,0x4(9); addi 26,1,32; cmpw 30,0; beq 2f; mr 27,9; 0:; lwz 31,0x0(30); lwz 9,0x5c(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 31,0; beq 1f; lwz 9,0x5c(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 0,0x4(27); addi 30,30,4; cmpw 30,0; bne 0b; 2:; li 0,0; addi 8,28,8; stw 0,0x8(1); addi 7,29,148; stw 0,0x4(28); stw 0,0x4(8); lwz 0,0x90(29); lwz 9,0x8c(29); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x8c(29); lwz 0,0x4(8); stw 10,0x90(29); stw 0,0x4(26); lwz 9,0x94(29); lwz 0,0x4(7); stw 9,0x8(28); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x94(29); stw 0,0x4(7); lwz 3,0x8(1); cmpwi 3,0; beq 4f; lwz 0,0xc(28); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 3f; bl _s80086848_0; b 4f; 3:; bl _s80086848_1; 4:; lwz 4,0x88(29); cmpwi 4,0; beq 5f; lis 9,-32697; lwz 3,0x5e80(9); bl _s80086848_2; 5:; lwz 0,0x44(1); mtspr 8,0; lmw 26,0x28(1); addi 1,1,64"

extern "C" void _s80086848_0();
extern "C" void _s80086848_1();
extern "C" void _s80086848_2();

struct Wrapper {
    void WrapperShutdown();
};

void Wrapper::WrapperShutdown() {
}
