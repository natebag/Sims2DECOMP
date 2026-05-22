// 0x80053E08 ISimsObjectModel::SetDir(EVec3 (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x0(4); addi 11,3,1040; lwz 0,0x8(4); lwz 9,0x4(4); stw 10,0x410(3); stw 0,0x8(11); stw 9,0x4(11)"
extern "C" void f_80053E08() {}
