// 0x801E64BC WXFTarget::OnRightKeyPressed(char (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-272(1); mfspr 0,8; stmw 30,0x108(1); stw 0,0x114(1); mr 30,3; lis 4,-32705; lwz 5,0x8c(30); addi 4,4,-8800; addi 3,1,8; subfic 0,5,0; adde 5,0,5; crxor 6,6,6; bl _s801E64BC_0; lwz 9,0x80(30); addi 5,1,8; lwz 4,-28724(13); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x114(1); mtspr 8,0; lmw 30,0x108(1); addi 1,1,272"

extern "C" void _s801E64BC_0();

struct WXFTarget {
    void OnRightKeyPressed();
};

void WXFTarget::OnRightKeyPressed() {
}
