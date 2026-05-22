// 0x80326DE0 EResourceManager::GetIds(unsigned (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4c(3); lwz 0,0x0(9); stw 0,0x0(5); lwz 9,0x4c(3); addi 9,9,4; stw 9,0x0(4)"
extern "C" void f_80326DE0() {}
