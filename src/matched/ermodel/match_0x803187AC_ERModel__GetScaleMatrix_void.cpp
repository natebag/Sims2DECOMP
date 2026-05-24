// 0x803187AC ERModel::GetScaleMatrix(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; lwz 0,0x174(31); cmpwi 0,0; bne 1f; lis 3,-32692; li 4,64; addi 3,3,-27556; li 5,16; bl _s803187AC_0; lis 9,-32702; lfs f13,0x88(31); lfs f0,0x8a0(9); stw 3,0x174(31); fcmpu 0,f13,f0; beq 0f; stfs f13,0x8(1); addi 4,1,8; stfs f13,0x10(1); stfs f13,0xc(1); bl _s803187AC_1; b 1f; 0:; bl _s803187AC_2; 1:; lwz 3,0x174(31); lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"

extern "C" void _s803187AC_0();
extern "C" void _s803187AC_1();
extern "C" void _s803187AC_2();

struct ERModel {
    void GetScaleMatrix();
};

void ERModel::GetScaleMatrix() {
}
