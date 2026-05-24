// 0x8017E7A8 UIReflow::Tween_ColorOverride(unsigned (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 28,0x88(1); stw 0,0x9c(1); mr 29,4; mr 30,3; rlwinm 28,29,24,8,31; lis 4,-32706; addi 4,4,14352; rlwinm 29,29,0,24,31; bl _s8017E7A8_0; lis 4,-32706; mr 3,30; addi 4,4,14360; bl _s8017E7A8_1; lis 4,-32706; mr 5,28; addi 3,1,8; addi 4,4,14364; crxor 6,6,6; bl _s8017E7A8_2; addi 4,1,8; mr 3,30; bl _s8017E7A8_3; lis 4,-32706; mr 3,30; addi 4,4,14372; bl _s8017E7A8_4; mr 3,30; mr 4,29; bl _s8017E7A8_5; lwz 0,0x9c(1); mtspr 8,0; lmw 28,0x88(1); addi 1,1,152"

extern "C" void _s8017E7A8_0();
extern "C" void _s8017E7A8_1();
extern "C" void _s8017E7A8_2();
extern "C" void _s8017E7A8_3();
extern "C" void _s8017E7A8_4();
extern "C" void _s8017E7A8_5();

struct UIReflow {
    void Tween_ColorOverride();
};

void UIReflow::Tween_ColorOverride() {
}
