// 0x8024F4AC TArray<EVec3, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8024F4C8" lines="mr 30,3; stw 0,0xb0(1); addi 0,1,8; li 31,1; stw 0,0xb4(1); stw 29,0x0(30)"
extern "C" void f_8024F4C8();
extern "C" void f_8024F4AC() {}
