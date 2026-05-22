// 0x802F3438 O2TTarget::QuitGame(char (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfd f24,0xe8(1); lfd f25,0xf0(1); lfd f26,0xf8(1); lfd f27,0x100(1); lfd f28,0x108(1); lfd f29,0x110(1); lfd f30,0x118(1); lfd f31,0x120(1); addi 1,1,296"
extern "C" float f_802F3438() {}
