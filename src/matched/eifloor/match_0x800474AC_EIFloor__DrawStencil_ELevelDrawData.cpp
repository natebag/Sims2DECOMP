// 0x800474AC EIFloor::DrawStencil(ELevelDrawData (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; li 0,0; lwz 31,0x98(29); mr 30,3; stw 0,0xb4(29); stw 0,0xac(29); lwz 9,0x70(31); lwz 0,0xf4(9); lha 3,0xf0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,0; li 5,0; lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,2; li 5,0; li 6,0; lha 3,0x1d8(9); lwz 0,0x1dc(9); add 3,31,3; mtspr 8,0; blrl; lwz 30,0x104(30); cmpwi 30,0; beq 1f; 0:; lwz 9,0x70(31); lwz 4,0x4(30); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,31,3; mtspr 8,0; blrl; lwz 30,0x0(30); cmpwi 30,0; bne 0b; 1:; lwz 9,0x70(31); li 4,0; li 5,0; li 6,0; lwz 0,0x1dc(9); lha 3,0x1d8(9); mtspr 8,0; add 3,31,3; blrl; li 0,0; stw 0,0xa8(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct EIFloor {
    void DrawStencil_ELevelDrawData();
};

void EIFloor::DrawStencil_ELevelDrawData() {
}
