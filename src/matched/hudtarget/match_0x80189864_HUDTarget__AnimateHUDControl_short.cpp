// 0x80189864 HUDTarget::AnimateHUDControl(short, (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 28,5; lis 30,-32705; mr 5,4; addi 3,1,8; addi 4,30,-19956; crxor 6,6,6; bl _s80189864_0; addi 29,1,24; addi 4,30,-19956; extsh 5,28; mr 3,29; crxor 6,6,6; bl _s80189864_1; lis 4,-32705; lwz 3,-25136(13); addi 4,4,-19428; mr 9,29; li 5,0; li 6,0; li 7,2; addi 8,1,8; crxor 6,6,6; bl _s80189864_2; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"

extern "C" void _s80189864_0();
extern "C" void _s80189864_1();
extern "C" void _s80189864_2();

struct HUDTarget {
    void AnimateHUDControl_short();
};

void HUDTarget::AnimateHUDControl_short() {
}
