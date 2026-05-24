// 0x80233F10 ERLevel::RemoveInstance(EInstance (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 11,4; mr 29,3; lwz 9,0x0(11); stw 4,0x8(1); mr 4,29; lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x8(1); lwz 4,0x34(9); cmpwi 4,0; beq 0f; addis 3,29,3; addi 3,3,-23948; bl _s80233F10_0; lwz 9,0x8(1); li 0,0; stw 0,0x34(9); 0:; lwz 4,0x8(1); mr 3,29; bl _s80233F10_1; lwz 9,0x8(1); lwz 0,0x5c(9); andis. 11,0,4; beq 1f; lwz 4,0x78(9); addis 3,29,3; addi 3,3,-23900; bl _s80233F10_2; lwz 9,0x8(1); li 0,0; stw 0,0x78(9); b 6f; 1:; andis. 9,0,1; bne 6f; addis 30,29,3; addi 28,1,8; lwz 0,-15688(30); addi 3,30,-23880; mr 5,28; rlwinm 0,0,2,0,29; add 31,0,29; addis 9,31,3; addi 31,9,-23880; mr 4,31; bl _s80233F10_3; cmpw 3,31; bne 2f; mr 3,31; b 5f; 2:; addi 10,3,4; cmpw 10,31; beq 5f; 3:; lwz 11,0x0(10); lwz 0,0x0(28); cmpw 11,0; beq 4f; stw 11,0x0(3); addi 3,3,4; 4:; addi 10,10,4; cmpw 10,31; bne 3b; 5:; lwz 0,-15688(30); rlwinm 9,0,2,0,29; addis 9,9,3; addi 9,9,-23880; add 9,29,9; subf 9,3,9; srawi 9,9,2; subf 0,9,0; stw 0,-15688(30); 6:; lwz 4,0x8(1); mr 3,29; bl _s80233F10_4; lwz 9,0x8(1); li 0,0; mr 4,29; stw 0,0x4(9); lwz 11,0x8(1); lwz 9,0x0(11); lha 3,0x140(9); lwz 0,0x144(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s80233F10_0();
extern "C" void _s80233F10_1();
extern "C" void _s80233F10_2();
extern "C" void _s80233F10_3();
extern "C" void _s80233F10_4();

struct ERLevel {
    void RemoveInstance_EInstance();
};

void ERLevel::RemoveInstance_EInstance() {
}
