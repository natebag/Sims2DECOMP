// 0x802FD3E8 ESubModelShader::UnRegisterMorphTarget(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,56; li 0,0; stwx 0,3,4"
extern "C" void f_802FD3E8() {}
