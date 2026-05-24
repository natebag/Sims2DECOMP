// 0x8004E55C ISimsObjectModel::RemoveSubModelsFromHouse(ERLevel (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 30,0x450(3); mr 29,4; cmpwi 30,0; beq 4f; 0:; lwz 31,0x0(30); mr 3,29; mr 4,31; bl _s8004E55C_0; lwz 9,0x0(31); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; lwz 9,0x0(31); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,31,3; mtspr 8,0; blrl; mr 4,3; mr 3,29; bl _s8004E55C_1; 1:; lwz 4,0x3bc(31); cmpwi 4,0; beq 2f; mr 3,29; bl _s8004E55C_2; 2:; lwz 4,0x3c0(31); cmpwi 4,0; beq 3f; mr 3,29; bl _s8004E55C_3; 3:; lwz 30,0x8(30); cmpwi 30,0; bne 0b; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8004E55C_0();
extern "C" void _s8004E55C_1();
extern "C" void _s8004E55C_2();
extern "C" void _s8004E55C_3();

struct ISimsObjectModel {
    void RemoveSubModelsFromHouse_ERLevel();
};

void ISimsObjectModel::RemoveSubModelsFromHouse_ERLevel() {
}
