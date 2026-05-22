// 0x80240744 SNDVDEmuInit(int) (32 B)
// FLAGS: -fno-schedule-insns
// GCC order: lis9,stw3(val),li0,lis11,stw0 — DOL batches: lis9,lis11,li0,stw3,stw0
// 4-directive cascade: hoist lis11, then swap li0 before stw3
// ASMPROC_replace_insn: match="stw 3,SN_emu_dvd_a460@l(9)" replacement="lis 11,SN_emu_dvd_a1ac@ha"
// ASMPROC_replace_insn: match="lis 11,SN_emu_dvd_a1ac@ha" replacement="stw 3,SN_emu_dvd_a460@l(9)" occurrence=1
// ASMPROC_replace_insn: match="stw 3,SN_emu_dvd_a460@l(9)" replacement="li 0,0"
// ASMPROC_replace_insn: match="li 0,0" replacement="stw 3,SN_emu_dvd_a460@l(9)" occurrence=1
extern volatile int SN_emu_dvd_a460[];
extern volatile int SN_emu_dvd_a1ac[];

void SNDVDEmuInit(int val) {
    if (val != -32768) return;
    SN_emu_dvd_a460[0] = val;
    SN_emu_dvd_a1ac[0] = 0;
}
