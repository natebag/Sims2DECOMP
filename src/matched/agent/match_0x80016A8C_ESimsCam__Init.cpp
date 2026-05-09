// ESimsCam::Init(void) at 0x80016A8C (44B)
// FLAGS: -fno-schedule-insns
// DOL uses r0 for val and r9 for zero literal; compiled swaps them.
// Single region_gpr_relabel over entire body fixes the swap.
// ASMPROC_region_gpr_relabel: start_anchor="lwz 9" start_mode=at end_anchor="blr" end_mode=before rename="9:0,0:9" unsafe_clobber=true
// ASMPROC_replace_insn: match="li 9, 9" replacement="li 9,0"

extern int g_scamInitVal;

struct ESimsCam_I {
    char pad[0x3cc];   // 972 bytes
    int m_field_3cc;   // offset 972
    int m_field_3d0;   // offset 976
    int m_field_3d4;   // offset 980
    char pad3[0xa0];   // 0x3d8 to 0x477 (160 bytes)
    int m_field_478;   // offset 1144
    char pad4[0xd0];   // 0x478+4=0x47c to 0x54c = 0x54c-0x47c = 0xd0
    int m_field_54c;   // offset 1356
    char pad5[4];
    int m_field_554;   // offset 1364
    int m_field_558;   // offset 1368
    int m_field_55c;   // offset 1372
    void Init();
};

void ESimsCam_I::Init() {
    int val = g_scamInitVal;
    m_field_55c = 0;
    m_field_3d0 = val;
    m_field_54c = 0;
    m_field_3d4 = 0;
    m_field_478 = 0;
    m_field_554 = 0;
    m_field_558 = 0;
    m_field_3cc = val;
}
