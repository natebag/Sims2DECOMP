// 0x80187BC4 HUDTarget::GetNextRepUnlockValue(int) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); li 28,0; mr 25,3; mr 27,4; stw 28,0x8(1); bl _s80187BC4_0; lwz 9,0x0(3); addi 26,1,8; lwz 11,0x8(1); lha 0,0x28(9); addi 30,9,40; lwz 29,-31848(13); cmpwi 11,0; add 31,3,0; beq 0f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; stw 28,0x8(1); 0:; lwz 0,0x4(30); lis 4,-5160; mr 3,31; mr 5,29; mtspr 8,0; mr 6,26; ori 4,4,51892; blrl; lwz 8,0x8(1); add 10,27,27; li 0,999; addi 9,25,2224; sthx 0,9,10; addi 11,25,2216; sthx 28,11,10; cmpwi 8,0; beq 1f; lwz 9,0x0(8); lha 3,0x18(9); lwz 0,0x1c(9); add 3,8,3; mtspr 8,0; blrl; 1:; li 3,999; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"

extern "C" void _s80187BC4_0();

struct HUDTarget {
    void GetNextRepUnlockValue();
};

void HUDTarget::GetNextRepUnlockValue() {
}
