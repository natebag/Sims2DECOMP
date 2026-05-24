// 0x8031B0C0 ERModel::TransformModelUV(EVec2 (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 31,3; mr 23,4; lwz 0,0x17c(31); mr 24,5; mr 25,6; mr 26,7; mr 27,8; cmpwi 0,0; bne 1f; li 0,1; addi 9,31,60; stw 0,0x17c(31); li 30,0; mr 28,9; lwz 0,0x4(9); cmpw 30,0; bge 1f; li 29,0; 0:; lwz 3,0x3c(31); mr 4,23; lwz 9,0x20(31); mr 5,24; add 3,3,29; mr 6,25; mr 7,26; mr 8,27; bl _s8031B0C0_0; addi 30,30,1; lwz 0,0x4(28); addi 29,29,24; cmpw 30,0; blt 0b; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"

extern "C" void _s8031B0C0_0();

struct ERModel {
    void TransformModelUV_EVec2();
};

void ERModel::TransformModelUV_EVec2() {
}
