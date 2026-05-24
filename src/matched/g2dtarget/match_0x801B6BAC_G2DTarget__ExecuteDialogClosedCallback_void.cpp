// 0x801B6BAC G2DTarget::ExecuteDialogClosedCallback(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x118(31); cmpwi 0,0; beq 1f; lwz 30,0xc4(31); cmpwi 30,0; beq 0f; lis 3,-32705; addi 3,3,3712; crxor 6,6,6; bl _s801B6BAC_0; lwz 9,0x118(31); li 0,0; stw 0,0x118(31); mr 3,9; lwz 0,0xc(9); mtspr 8,0; blrl; b 2f; 0:; lis 3,-32705; addi 3,3,3776; crxor 6,6,6; bl _s801B6BAC_1; stw 30,0x118(31); b 2f; 1:; lis 3,-32705; addi 3,3,3860; crxor 6,6,6; bl _s801B6BAC_2; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801B6BAC_0();
extern "C" void _s801B6BAC_1();
extern "C" void _s801B6BAC_2();

struct G2DTarget {
    void ExecuteDialogClosedCallback();
};

void G2DTarget::ExecuteDialogClosedCallback() {
}
