// 0x8005B460 PlumbBobModel::DrawShadow(ERC (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); mr 31,3; mr 29,4; lwz 0,0x2c(31); cmpwi 0,0; beq 0f; addi 3,1,8; mr 30,3; bl _s8005B460_0; lfs f0,0xc(31); addi 11,31,12; lis 9,-32707; addi 10,1,56; stfs f0,0x38(1); mr 3,30; lfs f12,0x4318(9); lfs f13,0x4(11); lwz 9,0x2c(31); stfs f13,0x4(10); lfs f0,0x8(11); stfs f0,0x8(10); stfs f12,0x40(1); lfs f1,0x88(9); bl _s8005B460_1; lwz 9,0x70(29); mr 4,30; li 5,1; lha 3,0xe8(9); lwz 0,0xec(9); add 3,29,3; mtspr 8,0; blrl; lwz 3,0x2c(31); mr 4,29; bl _s8005B460_2; 0:; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"

extern "C" void _s8005B460_0();
extern "C" void _s8005B460_1();
extern "C" void _s8005B460_2();

struct PlumbBobModel {
    void DrawShadow();
};

void PlumbBobModel::DrawShadow() {
}
