// 0x8017E318 UIReflow::SubmitTweenBlock(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; beq 0f; lis 4,-32706; addi 4,4,14504; bl _s8017E318_0; lwz 9,0x0(31); lis 4,-32706; lwz 3,-25136(13); lis 8,-32706; li 5,0; li 6,0; li 7,2; addi 4,4,14152; addi 8,8,14516; crxor 6,6,6; bl _s8017E318_1; bl _s8017E318_2; lwz 4,0x0(31); bl _s8017E318_3; li 0,0; stw 0,0x4(31); stw 0,0x0(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8017E318_0();
extern "C" void _s8017E318_1();
extern "C" void _s8017E318_2();
extern "C" void _s8017E318_3();

struct UIReflow {
    void SubmitTweenBlock();
};

void UIReflow::SubmitTweenBlock() {
}
