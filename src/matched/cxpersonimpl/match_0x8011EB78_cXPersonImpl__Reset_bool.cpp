// 0x8011EB78 cXPersonImpl::Reset(bool) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 30,3; mr 24,4; li 5,160; lha 26,0x4c(30); lha 25,0x48(30); li 4,0; lha 27,0x4e(30); addi 3,30,8; lha 29,0x7c(30); lha 28,0x8a(30); bl _s8011EB78_0; sth 26,0x4c(30); sth 25,0x48(30); sth 27,0x4e(30); sth 29,0x7c(30); sth 28,0x8a(30); lwz 11,-21476(13); lwz 4,0x4(30); lwz 9,0x0(11); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x3f4(30); lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,0x0(30); mr 4,24; bl _s8011EB78_1; lwz 11,0x3f4(30); lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; li 9,-32768; stw 0,0x54c(30); sth 9,0x540(30); stw 0,0x544(30); stw 0,0x548(30); lwz 11,0x4(30); lwz 9,0x4(11); lha 3,0x328(9); lwz 0,0x32c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; bl _s8011EB78_2; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s8011EB78_0();
extern "C" void _s8011EB78_1();
extern "C" void _s8011EB78_2();

struct cXPersonImpl {
    void Reset();
};

void cXPersonImpl::Reset() {
}
