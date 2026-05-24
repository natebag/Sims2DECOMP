// 0x8004D598 ISimsObjectModel::UpdateParticle(ObjAnimDef (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); mr 29,3; mr 27,4; lwz 3,0x328(29); li 4,34; lwz 9,0x4(3); lha 0,0x260(9); lwz 9,0x264(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 5f; addi 11,29,1056; lwz 9,0x4(27); lwz 0,0x4(11); cmpw 0,9; beq 5f; stw 9,0x4(11); addi 30,29,1088; lwz 9,0x4(30); mr 28,30; b 2f; 0:; lwz 0,0x8(30); lwz 3,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 1f; cmpwi 3,0; beq 1f; li 4,3; bl _s8004D598_0; 1:; mr 9,31; 2:; li 0,1; cmpwi 9,0; bne 3f; li 0,0; 3:; cmpwi 0,0; bne 0b; mr 3,30; bl _s8004D598_1; li 3,16; bl _s8004D598_2; bl _s8004D598_3; lwz 9,0x0(29); mr 31,3; addi 4,1,8; lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,29,3; blrl; lis 9,-32707; mr 5,27; lfs f1,0x31b8(9); mr 3,31; addi 4,1,8; bl _s8004D598_4; cmpwi 3,0; beq 4f; mr 3,28; mr 4,31; bl _s8004D598_5; b 5f; 4:; cmpwi 31,0; beq 5f; mr 3,31; li 4,3; bl _s8004D598_6; 5:; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"

extern "C" void _s8004D598_0();
extern "C" void _s8004D598_1();
extern "C" void _s8004D598_2();
extern "C" void _s8004D598_3();
extern "C" void _s8004D598_4();
extern "C" void _s8004D598_5();
extern "C" void _s8004D598_6();

struct ISimsObjectModel {
    void UpdateParticle_ObjAnimDef();
};

void ISimsObjectModel::UpdateParticle_ObjAnimDef() {
}
