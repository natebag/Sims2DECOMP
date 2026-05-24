// 0x803440AC ENgcRenderer::ModelMatrixIndex(int, (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; cmpwi 5,255; bgt 0f; cmpwi 5,254; blt 0f; mulli 29,4,48; addi 30,29,17780; add 30,31,30; mr 3,30; bl _s803440AC_0; lwz 4,0x4d8(31); addi 29,29,1952; mr 3,30; add 4,4,29; b 1f; 0:; mulli 9,4,48; rlwinm 11,5,6,0,25; add 11,11,31; lfsu f0,0x770(11); mr 3,9; addi 10,11,16; add 9,9,31; addi 8,11,32; stfsu f0,0x4574(9); addi 7,11,48; addi 0,3,1952; lfs f13,0x10(11); addi 3,3,17780; add 3,31,3; stfs f13,0x4(9); lfs f0,0x20(11); stfs f0,0x8(9); lfs f13,0x30(11); stfs f13,0xc(9); lfs f0,0x4(11); stfs f0,0x10(9); lfs f13,0x4(10); stfs f13,0x14(9); lfs f0,0x4(8); stfs f0,0x18(9); lfs f13,0x4(7); stfs f13,0x1c(9); lfs f0,0x8(11); stfs f0,0x20(9); lfs f13,0x8(10); stfs f13,0x24(9); lfs f0,0x8(8); stfs f0,0x28(9); lfs f13,0x8(7); stfs f13,0x2c(9); lwz 4,0x4d8(31); add 4,4,0; 1:; bl _s803440AC_1; lwz 9,0x4d8(31); lwz 0,0x6cc(9); oris 0,0,32768; ori 0,0,2; stw 0,0x6cc(9); li 0,1; stw 0,0x510(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s803440AC_0();
extern "C" void _s803440AC_1();

struct ENgcRenderer {
    void ModelMatrixIndex();
};

void ENgcRenderer::ModelMatrixIndex() {
}
