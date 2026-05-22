// 0x80360450 ERTQuantize4D::AllocNode(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 10,3; lhz 3,0x1006(10); cmpwi 3,0; beq 0f; mulli 11,3,72; lwz 9,0x1008(10); lhzx 0,9,11; sth 0,0x1006(10); blr; 0:; li 3,0"
extern "C" void f_80360450() {}
