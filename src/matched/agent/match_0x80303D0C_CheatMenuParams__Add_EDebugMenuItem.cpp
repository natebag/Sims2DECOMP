// 0x80303D0C CheatMenuParams::Add(EDebugMenuItem (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); stw 0,0x0(4); lwz 9,0x4(3); cmpwi 9,0; beq 0f; stw 4,0x4(9); b 1f; 0:; stw 4,0x0(3); 1:; li 0,0; stw 0,0x4(4); stw 4,0x4(3); lwz 9,0x8(3); addi 9,9,1; stw 9,0x8(3)"
extern "C" void f_80303D0C() {}
