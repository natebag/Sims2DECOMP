// 0x8022F384 EIStaticSubModel::OrderTableCallback(ELevelDrawData (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 11,0x24(4); mr 31,3; lwz 30,0x20(4); lwz 9,0x0(11); lwz 28,0x18(4); lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; lwz 29,0x98(31); add 3,11,3; blrl; lwz 0,0xa8(31); mr 5,3; cmpw 0,30; beq 2f; stw 30,0xa8(31); lwz 4,0x98(31); lwz 3,0x14(30); cmpwi 3,0; beq 0f; mr 11,3; b 1f; 0:; lwz 9,0x18(30); li 11,0; cmpwi 9,0; beq 1f; lwz 11,0x14(9); 1:; lwz 9,0xf0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 9,0x70(29); mr 4,28; lha 3,0xb8(9); lwz 0,0xbc(9); add 3,29,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

struct EIStaticSubModel {
    void OrderTableCallback_ELevelDrawData();
};

void EIStaticSubModel::OrderTableCallback_ELevelDrawData() {
}
