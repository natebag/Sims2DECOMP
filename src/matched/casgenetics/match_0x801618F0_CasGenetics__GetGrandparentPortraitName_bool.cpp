// 0x801618F0 CasGenetics::GetGrandparentPortraitName(bool, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,3; mr 30,4; addi 3,1,8; mr 31,5; mr 28,3; bl _s801618F0_0; cmpwi 30,0; beq 0f; lis 9,-32706; addi 5,9,-4120; b 1f; 0:; lis 9,-32706; addi 5,9,-4116; 1:; lis 4,-32706; addi 3,1,8; mr 6,31; addi 4,4,-4140; crxor 6,6,6; bl _s801618F0_1; mr 3,28; bl _s801618F0_2; mr 4,3; mr 3,29; bl _s801618F0_3; lwz 4,0x8(1); mr 3,28; bl _s801618F0_4; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s801618F0_0();
extern "C" void _s801618F0_1();
extern "C" void _s801618F0_2();
extern "C" void _s801618F0_3();
extern "C" void _s801618F0_4();

struct CasGenetics {
    void GetGrandparentPortraitName();
};

void CasGenetics::GetGrandparentPortraitName() {
}
