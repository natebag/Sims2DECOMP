// 0x803C2448 EStorable::New(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,4; bl _s803C2448_0; lis 9,-32697; mr 11,3; addi 9,9,-28472; stw 9,0x0(11); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803C2448_0();
extern "C" void f_803C2448() {}
