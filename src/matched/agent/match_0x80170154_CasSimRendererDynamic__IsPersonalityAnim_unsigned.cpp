// 0x80170154 CasSimRendererDynamic::IsPersonalityAnim(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x224(3); li 3,0; lwz 0,0x68(9); cmpw 4,0; beq 0f; lwz 0,0x6c(9); cmpw 4,0; beq 0f; lwz 0,0x70(9); cmpw 4,0; beq 0f; lwz 0,0x74(9); cmpw 4,0; beq 0f; lwz 0,0x78(9); cmpw 4,0; beq 0f; lwz 0,0x7c(9); cmpw 4,0; beq 0f; lwz 0,0x80(9); cmpw 4,0; beq 0f; lwz 0,0x84(9); cmpw 4,0; beq 0f; lwz 0,0x88(9); cmpw 4,0; beq 0f; lwz 0,0x8c(9); cmpw 4,0; bnelr; 0:; li 3,1"
extern "C" int f_80170154() {}
