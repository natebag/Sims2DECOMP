// 0x80288CBC (1756B) AptCharacterInst::CleanNativeFunctions(void) - 27x AptRegistry Register

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptCharacterInst_Reg1;
extern AptRegistry* g_AptCharacterInst_Reg2;
extern AptRegistry* g_AptCharacterInst_Reg3;
extern AptRegistry* g_AptCharacterInst_Reg4;
extern AptRegistry* g_AptCharacterInst_Reg5;
extern AptRegistry* g_AptCharacterInst_Reg6;
extern AptRegistry* g_AptCharacterInst_Reg7;
extern AptRegistry* g_AptCharacterInst_Reg8;
extern AptRegistry* g_AptCharacterInst_Reg9;
extern AptRegistry* g_AptCharacterInst_Reg10;
extern AptRegistry* g_AptCharacterInst_Reg11;
extern AptRegistry* g_AptCharacterInst_Reg12;
extern AptRegistry* g_AptCharacterInst_Reg13;
extern AptRegistry* g_AptCharacterInst_Reg14;
extern AptRegistry* g_AptCharacterInst_Reg15;
extern AptRegistry* g_AptCharacterInst_Reg16;
extern AptRegistry* g_AptCharacterInst_Reg17;
extern AptRegistry* g_AptCharacterInst_Reg18;
extern AptRegistry* g_AptCharacterInst_Reg19;
extern AptRegistry* g_AptCharacterInst_Reg20;
extern AptRegistry* g_AptCharacterInst_Reg21;
extern AptRegistry* g_AptCharacterInst_Reg22;
extern AptRegistry* g_AptCharacterInst_Reg23;
extern AptRegistry* g_AptCharacterInst_Reg24;
extern AptRegistry* g_AptCharacterInst_Reg25;
extern AptRegistry* g_AptCharacterInst_Reg26;
extern AptRegistry* g_AptCharacterInst_Reg27;

extern char s_AptCharacterInst_func[];
extern char s_AptCharacterInst_file[];

namespace AptCharacterInst {
    void CleanNativeFunctions(void) {
        if (g_AptCharacterInst_Reg1) { g_AptCharacterInst_Reg1->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 544); g_AptCharacterInst_Reg1 = 0; }
        if (g_AptCharacterInst_Reg2) { g_AptCharacterInst_Reg2->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 545); g_AptCharacterInst_Reg2 = 0; }
        if (g_AptCharacterInst_Reg3) { g_AptCharacterInst_Reg3->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 546); g_AptCharacterInst_Reg3 = 0; }
        if (g_AptCharacterInst_Reg4) { g_AptCharacterInst_Reg4->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 547); g_AptCharacterInst_Reg4 = 0; }
        if (g_AptCharacterInst_Reg5) { g_AptCharacterInst_Reg5->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 548); g_AptCharacterInst_Reg5 = 0; }
        if (g_AptCharacterInst_Reg6) { g_AptCharacterInst_Reg6->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 549); g_AptCharacterInst_Reg6 = 0; }
        if (g_AptCharacterInst_Reg7) { g_AptCharacterInst_Reg7->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 550); g_AptCharacterInst_Reg7 = 0; }
        if (g_AptCharacterInst_Reg8) { g_AptCharacterInst_Reg8->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 551); g_AptCharacterInst_Reg8 = 0; }
        if (g_AptCharacterInst_Reg9) { g_AptCharacterInst_Reg9->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 552); g_AptCharacterInst_Reg9 = 0; }
        if (g_AptCharacterInst_Reg10) { g_AptCharacterInst_Reg10->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 553); g_AptCharacterInst_Reg10 = 0; }
        if (g_AptCharacterInst_Reg11) { g_AptCharacterInst_Reg11->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 554); g_AptCharacterInst_Reg11 = 0; }
        if (g_AptCharacterInst_Reg12) { g_AptCharacterInst_Reg12->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 555); g_AptCharacterInst_Reg12 = 0; }
        if (g_AptCharacterInst_Reg13) { g_AptCharacterInst_Reg13->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 556); g_AptCharacterInst_Reg13 = 0; }
        if (g_AptCharacterInst_Reg14) { g_AptCharacterInst_Reg14->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 557); g_AptCharacterInst_Reg14 = 0; }
        if (g_AptCharacterInst_Reg15) { g_AptCharacterInst_Reg15->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 558); g_AptCharacterInst_Reg15 = 0; }
        if (g_AptCharacterInst_Reg16) { g_AptCharacterInst_Reg16->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 559); g_AptCharacterInst_Reg16 = 0; }
        if (g_AptCharacterInst_Reg17) { g_AptCharacterInst_Reg17->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 560); g_AptCharacterInst_Reg17 = 0; }
        if (g_AptCharacterInst_Reg18) { g_AptCharacterInst_Reg18->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 561); g_AptCharacterInst_Reg18 = 0; }
        if (g_AptCharacterInst_Reg19) { g_AptCharacterInst_Reg19->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 562); g_AptCharacterInst_Reg19 = 0; }
        if (g_AptCharacterInst_Reg20) { g_AptCharacterInst_Reg20->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 563); g_AptCharacterInst_Reg20 = 0; }
        if (g_AptCharacterInst_Reg21) { g_AptCharacterInst_Reg21->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 564); g_AptCharacterInst_Reg21 = 0; }
        if (g_AptCharacterInst_Reg22) { g_AptCharacterInst_Reg22->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 565); g_AptCharacterInst_Reg22 = 0; }
        if (g_AptCharacterInst_Reg23) { g_AptCharacterInst_Reg23->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 566); g_AptCharacterInst_Reg23 = 0; }
        if (g_AptCharacterInst_Reg24) { g_AptCharacterInst_Reg24->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 567); g_AptCharacterInst_Reg24 = 0; }
        if (g_AptCharacterInst_Reg25) { g_AptCharacterInst_Reg25->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 568); g_AptCharacterInst_Reg25 = 0; }
        if (g_AptCharacterInst_Reg26) { g_AptCharacterInst_Reg26->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 569); g_AptCharacterInst_Reg26 = 0; }
        if (g_AptCharacterInst_Reg27) { g_AptCharacterInst_Reg27->Register(s_AptCharacterInst_func, s_AptCharacterInst_file, 570); g_AptCharacterInst_Reg27 = 0; }
    }
}
