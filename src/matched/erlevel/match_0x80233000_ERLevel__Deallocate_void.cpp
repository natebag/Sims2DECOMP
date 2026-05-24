// 0x80233000 ERLevel::Deallocate(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; addis 9,29,3; lwz 0,-15688(9); addic. 30,0,-1; blt 1f; rlwinm 9,30,2,0,29; addis 9,9,3; addi 9,9,-23880; add 31,9,29; 0:; lwz 3,0x0(31); addi 31,31,-4; lwz 9,0x0(3); lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; addic. 30,30,-1; bge 0b; 1:; addis 30,29,3; li 0,0; mr 3,29; stw 0,-15688(30); bl _s80233000_0; addi 3,30,-23948; bl _s80233000_1; addi 3,30,-23964; bl _s80233000_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80233000_0();
extern "C" void _s80233000_1();
extern "C" void _s80233000_2();

struct ERLevel {
    void Deallocate();
};

void ERLevel::Deallocate() {
}
