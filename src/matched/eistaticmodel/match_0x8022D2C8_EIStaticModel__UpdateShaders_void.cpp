// 0x8022D2C8 EIStaticModel::UpdateShaders(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; lwz 9,0x120(28); cmpwi 9,0; beq 3f; lwz 0,0x40(9); li 8,0; lwz 31,0x118(28); cmpw 8,0; bge 3f; 0:; lwz 11,0x120(28); mulli 10,8,24; li 30,0; lwz 9,0x3c(11); addi 27,8,1; add 29,9,10; lwz 0,0x4(29); cmpw 30,0; bge 2f; lis 26,-32704; 1:; lwz 11,0x4(31); li 4,0; lfs f1,-4560(26); li 5,0; lwz 9,0x0(11); li 6,0; addi 30,30,1; addi 31,31,16; lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(29); cmpw 30,0; blt 1b; 2:; lwz 9,0x120(28); mr 8,27; lwz 0,0x40(9); cmpw 8,0; blt 0b; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

struct EIStaticModel {
    void UpdateShaders();
};

void EIStaticModel::UpdateShaders() {
}
