// 0x8004E7DC ISimsObjectModel::GetAdjacentRoom(bool) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 4,0; beq 0f; li 0,0; stw 0,0x45c(31); 0:; lwz 3,0x328(31); lwz 9,0x4(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 2f; lwz 0,0x45c(31); cmpwi 0,0; bne 1f; mr 3,31; bl _s8004E7DC_0; lwz 0,0x45c(31); cmpwi 0,0; beq 2f; 1:; lwz 3,0x45c(31); bl _s8004E7DC_1; b 3f; 2:; li 3,-1; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8004E7DC_0();
extern "C" void _s8004E7DC_1();

struct ISimsObjectModel {
    void GetAdjacentRoom();
};

void ISimsObjectModel::GetAdjacentRoom() {
}
