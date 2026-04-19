// 0x80298264 (2396B) AptDate::CleanNativeFunctions(void) - 37x AptRegistry Register

struct AptRegistryBase { char pad[8]; };

struct AptRegistry : public AptRegistryBase {
    virtual void f0() = 0;
    virtual void Register(const char* func, const char* file, int id) = 0;
};

extern AptRegistry* g_AptDate_Reg1;
extern AptRegistry* g_AptDate_Reg2;
extern AptRegistry* g_AptDate_Reg3;
extern AptRegistry* g_AptDate_Reg4;
extern AptRegistry* g_AptDate_Reg5;
extern AptRegistry* g_AptDate_Reg6;
extern AptRegistry* g_AptDate_Reg7;
extern AptRegistry* g_AptDate_Reg8;
extern AptRegistry* g_AptDate_Reg9;
extern AptRegistry* g_AptDate_Reg10;
extern AptRegistry* g_AptDate_Reg11;
extern AptRegistry* g_AptDate_Reg12;
extern AptRegistry* g_AptDate_Reg13;
extern AptRegistry* g_AptDate_Reg14;
extern AptRegistry* g_AptDate_Reg15;
extern AptRegistry* g_AptDate_Reg16;
extern AptRegistry* g_AptDate_Reg17;
extern AptRegistry* g_AptDate_Reg18;
extern AptRegistry* g_AptDate_Reg19;
extern AptRegistry* g_AptDate_Reg20;
extern AptRegistry* g_AptDate_Reg21;
extern AptRegistry* g_AptDate_Reg22;
extern AptRegistry* g_AptDate_Reg23;
extern AptRegistry* g_AptDate_Reg24;
extern AptRegistry* g_AptDate_Reg25;
extern AptRegistry* g_AptDate_Reg26;
extern AptRegistry* g_AptDate_Reg27;
extern AptRegistry* g_AptDate_Reg28;
extern AptRegistry* g_AptDate_Reg29;
extern AptRegistry* g_AptDate_Reg30;
extern AptRegistry* g_AptDate_Reg31;
extern AptRegistry* g_AptDate_Reg32;
extern AptRegistry* g_AptDate_Reg33;
extern AptRegistry* g_AptDate_Reg34;
extern AptRegistry* g_AptDate_Reg35;
extern AptRegistry* g_AptDate_Reg36;
extern AptRegistry* g_AptDate_Reg37;

extern char s_AptDate_func[];
extern char s_AptDate_file[];

namespace AptDate {
    void CleanNativeFunctions(void) {
        if (g_AptDate_Reg1) { g_AptDate_Reg1->Register(s_AptDate_func, s_AptDate_file, 888); g_AptDate_Reg1 = 0; }
        if (g_AptDate_Reg2) { g_AptDate_Reg2->Register(s_AptDate_func, s_AptDate_file, 889); g_AptDate_Reg2 = 0; }
        if (g_AptDate_Reg3) { g_AptDate_Reg3->Register(s_AptDate_func, s_AptDate_file, 890); g_AptDate_Reg3 = 0; }
        if (g_AptDate_Reg4) { g_AptDate_Reg4->Register(s_AptDate_func, s_AptDate_file, 891); g_AptDate_Reg4 = 0; }
        if (g_AptDate_Reg5) { g_AptDate_Reg5->Register(s_AptDate_func, s_AptDate_file, 892); g_AptDate_Reg5 = 0; }
        if (g_AptDate_Reg6) { g_AptDate_Reg6->Register(s_AptDate_func, s_AptDate_file, 893); g_AptDate_Reg6 = 0; }
        if (g_AptDate_Reg7) { g_AptDate_Reg7->Register(s_AptDate_func, s_AptDate_file, 894); g_AptDate_Reg7 = 0; }
        if (g_AptDate_Reg8) { g_AptDate_Reg8->Register(s_AptDate_func, s_AptDate_file, 895); g_AptDate_Reg8 = 0; }
        if (g_AptDate_Reg9) { g_AptDate_Reg9->Register(s_AptDate_func, s_AptDate_file, 896); g_AptDate_Reg9 = 0; }
        if (g_AptDate_Reg10) { g_AptDate_Reg10->Register(s_AptDate_func, s_AptDate_file, 897); g_AptDate_Reg10 = 0; }
        if (g_AptDate_Reg11) { g_AptDate_Reg11->Register(s_AptDate_func, s_AptDate_file, 898); g_AptDate_Reg11 = 0; }
        if (g_AptDate_Reg12) { g_AptDate_Reg12->Register(s_AptDate_func, s_AptDate_file, 899); g_AptDate_Reg12 = 0; }
        if (g_AptDate_Reg13) { g_AptDate_Reg13->Register(s_AptDate_func, s_AptDate_file, 900); g_AptDate_Reg13 = 0; }
        if (g_AptDate_Reg14) { g_AptDate_Reg14->Register(s_AptDate_func, s_AptDate_file, 901); g_AptDate_Reg14 = 0; }
        if (g_AptDate_Reg15) { g_AptDate_Reg15->Register(s_AptDate_func, s_AptDate_file, 902); g_AptDate_Reg15 = 0; }
        if (g_AptDate_Reg16) { g_AptDate_Reg16->Register(s_AptDate_func, s_AptDate_file, 903); g_AptDate_Reg16 = 0; }
        if (g_AptDate_Reg17) { g_AptDate_Reg17->Register(s_AptDate_func, s_AptDate_file, 904); g_AptDate_Reg17 = 0; }
        if (g_AptDate_Reg18) { g_AptDate_Reg18->Register(s_AptDate_func, s_AptDate_file, 905); g_AptDate_Reg18 = 0; }
        if (g_AptDate_Reg19) { g_AptDate_Reg19->Register(s_AptDate_func, s_AptDate_file, 906); g_AptDate_Reg19 = 0; }
        if (g_AptDate_Reg20) { g_AptDate_Reg20->Register(s_AptDate_func, s_AptDate_file, 907); g_AptDate_Reg20 = 0; }
        if (g_AptDate_Reg21) { g_AptDate_Reg21->Register(s_AptDate_func, s_AptDate_file, 908); g_AptDate_Reg21 = 0; }
        if (g_AptDate_Reg22) { g_AptDate_Reg22->Register(s_AptDate_func, s_AptDate_file, 909); g_AptDate_Reg22 = 0; }
        if (g_AptDate_Reg23) { g_AptDate_Reg23->Register(s_AptDate_func, s_AptDate_file, 910); g_AptDate_Reg23 = 0; }
        if (g_AptDate_Reg24) { g_AptDate_Reg24->Register(s_AptDate_func, s_AptDate_file, 911); g_AptDate_Reg24 = 0; }
        if (g_AptDate_Reg25) { g_AptDate_Reg25->Register(s_AptDate_func, s_AptDate_file, 912); g_AptDate_Reg25 = 0; }
        if (g_AptDate_Reg26) { g_AptDate_Reg26->Register(s_AptDate_func, s_AptDate_file, 913); g_AptDate_Reg26 = 0; }
        if (g_AptDate_Reg27) { g_AptDate_Reg27->Register(s_AptDate_func, s_AptDate_file, 914); g_AptDate_Reg27 = 0; }
        if (g_AptDate_Reg28) { g_AptDate_Reg28->Register(s_AptDate_func, s_AptDate_file, 915); g_AptDate_Reg28 = 0; }
        if (g_AptDate_Reg29) { g_AptDate_Reg29->Register(s_AptDate_func, s_AptDate_file, 916); g_AptDate_Reg29 = 0; }
        if (g_AptDate_Reg30) { g_AptDate_Reg30->Register(s_AptDate_func, s_AptDate_file, 917); g_AptDate_Reg30 = 0; }
        if (g_AptDate_Reg31) { g_AptDate_Reg31->Register(s_AptDate_func, s_AptDate_file, 918); g_AptDate_Reg31 = 0; }
        if (g_AptDate_Reg32) { g_AptDate_Reg32->Register(s_AptDate_func, s_AptDate_file, 919); g_AptDate_Reg32 = 0; }
        if (g_AptDate_Reg33) { g_AptDate_Reg33->Register(s_AptDate_func, s_AptDate_file, 920); g_AptDate_Reg33 = 0; }
        if (g_AptDate_Reg34) { g_AptDate_Reg34->Register(s_AptDate_func, s_AptDate_file, 921); g_AptDate_Reg34 = 0; }
        if (g_AptDate_Reg35) { g_AptDate_Reg35->Register(s_AptDate_func, s_AptDate_file, 922); g_AptDate_Reg35 = 0; }
        if (g_AptDate_Reg36) { g_AptDate_Reg36->Register(s_AptDate_func, s_AptDate_file, 923); g_AptDate_Reg36 = 0; }
        if (g_AptDate_Reg37) { g_AptDate_Reg37->Register(s_AptDate_func, s_AptDate_file, 924); g_AptDate_Reg37 = 0; }
    }
}
