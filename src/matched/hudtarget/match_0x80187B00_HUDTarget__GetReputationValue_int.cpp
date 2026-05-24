// 0x80187B00 HUDTarget::GetReputationValue(int) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32697; mr 31,4; addi 9,9,24012; rlwinm 0,31,2,0,29; addi 9,9,188; mr 28,3; lwzx 11,9,0; cmpwi 11,0; beq 0f; lwz 9,0x4(11); lwz 29,-21476(13); lha 3,0x1b0(9); lwz 9,0x1b4(9); lwz 30,0x0(29); add 3,11,3; mtspr 8,9; lha 0,0xb8(30); addi 30,30,184; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 3,3; beq 0f; bl _s80187B00_0; add 10,31,31; addi 9,28,2220; sthx 3,9,10; addi 8,28,2216; extsh 11,3; lhax 0,8,10; cmpw 11,0; bge 0f; sthx 3,8,10; 0:; add 0,31,31; addi 9,28,2220; lhax 3,9,0; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80187B00_0();

struct HUDTarget {
    void GetReputationValue();
};

void HUDTarget::GetReputationValue() {
}
