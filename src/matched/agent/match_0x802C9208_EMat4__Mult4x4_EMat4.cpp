// 0x802C9208 EMat4::Mult4x4(EMat4 (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,3; mr 3,4; mr 4,5; mr 5,0; bl _s802C9208_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802C9208_0();
extern "C" void f_802C9208() {}
