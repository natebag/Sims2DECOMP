// 0x800C9A9C Neighbor::GetFamily(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 9,-21476(13); mr 28,3; li 30,0; lwz 11,0x0(9); lha 3,0x110(11); lwz 0,0x114(11); add 3,9,3; mtspr 8,0; blrl; mr 29,3; cmpw 30,29; bge 2f; 0:; lwz 11,-21476(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x11c(9); lha 3,0x118(9); mtspr 8,0; add 3,11,3; blrl; mr 31,3; lwz 4,0x8(28); lwz 9,0x0(31); lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; mr 3,31; b 3f; 1:; addi 30,30,1; cmpw 30,29; blt 0b; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

struct Neighbor {
    void GetFamily();
};

void Neighbor::GetFamily() {
}
