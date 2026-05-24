// 0x801CF0EC O2TTarget::RestoreOptions(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 30,-32697; lbz 0,-29740(13); addi 30,30,24012; lwz 9,0x148(30); stb 0,0x1c(9); lbz 4,-29740(13); lwz 3,-21492(13); extsb 4,4; bl _s801CF0EC_0; lwz 9,0x148(30); lbz 0,-29739(13); stb 0,0x1d(9); lbz 4,-29739(13); lwz 3,-21492(13); extsb 4,4; bl _s801CF0EC_1; lwz 9,0x148(30); lbz 0,-29738(13); stb 0,0x29(9); lbz 4,-29738(13); lwz 3,-21492(13); extsb 4,4; bl _s801CF0EC_2; lwz 9,0x148(30); lbz 0,-29737(13); stb 0,0x28(9); lbz 4,-29737(13); lwz 3,-21492(13); extsb 4,4; bl _s801CF0EC_3; lwz 11,0x148(30); mr 3,30; lbz 0,-29736(13); stb 0,0x1f(11); lwz 9,0x148(30); lbz 0,-29735(13); stb 0,0x20(9); bl _s801CF0EC_4; lwz 9,0x148(30); lwz 0,-29732(13); lwz 10,-29724(13); stw 0,0x4(9); lwz 8,-29728(13); lwz 11,0x148(30); lwz 0,-29720(13); stw 10,0x18(11); lwz 9,0x148(30); stw 8,0x24(9); lwz 11,0x148(30); stw 0,0x0(11); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801CF0EC_0();
extern "C" void _s801CF0EC_1();
extern "C" void _s801CF0EC_2();
extern "C" void _s801CF0EC_3();
extern "C" void _s801CF0EC_4();

struct O2TTarget {
    void RestoreOptions();
};

void O2TTarget::RestoreOptions() {
}
