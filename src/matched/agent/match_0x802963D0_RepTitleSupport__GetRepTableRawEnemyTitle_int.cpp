// 0x802963D0 RepTitleSupport::GetRepTableRawEnemyTitle(int) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_80296434" lines="cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 1:; li 0,0; mr 3,31; stw 0,0xc(31)"
extern "C" void f_80296434();
extern "C" void f_802963D0() {}
