// 0x802FF810 ESubModelShader::GetModifiableColor(unsigned (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x8(3); lwz 9,0x14(11); cmpwi 9,0; bne 0f; lwz 11,0x18(11); li 9,0; cmpwi 11,0; beq 0f; lwz 9,0x14(11); 0:; rlwinm 0,4,2,0,29; addi 9,9,64; lwzx 3,9,0"
extern "C" int f_802FF810() {}
