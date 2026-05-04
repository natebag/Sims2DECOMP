// ASMPROC_force_reg_at_pos: match="li 0,0" pos=0 from_reg=0 to_reg=9
// ASMPROC_force_reg_at_pos: match="lwz 11,g_AptScriptFunctionBase_staticTop@sda21(0)" pos=0 from_reg=11 to_reg=3
// ASMPROC_force_reg_at_pos: match="slwi 9,9,2" pos=0 from_reg=9 to_reg=0
// ASMPROC_force_reg_at_pos: match="slwi 0,9,2" pos=1 from_reg=9 to_reg=0
// ASMPROC_force_reg_at_pos: match="stw 0,g_AptScriptFunctionBase_staticDepth@sda21(0)" pos=0 from_reg=0 to_reg=9
// ASMPROC_force_reg_at_pos: match="add 9,11,9" pos=0 from_reg=9 to_reg=0
// ASMPROC_force_reg_at_pos: match="add 0,11,9" pos=1 from_reg=11 to_reg=3
// ASMPROC_force_reg_at_pos: match="add 0,3,9" pos=2 from_reg=9 to_reg=0
// ASMPROC_force_reg_at_pos: match="stw 9,g_AptScriptFunctionBase_staticTop@sda21(0)" pos=0 from_reg=9 to_reg=0

extern int g_AptScriptFunctionBase_staticDepth;
extern char *g_AptScriptFunctionBase_staticTop;

struct AptScriptFunctionBase {
    void PushStaticData();
};

void AptScriptFunctionBase::PushStaticData() {
    int depth = g_AptScriptFunctionBase_staticDepth;
    char *top = g_AptScriptFunctionBase_staticTop;
    depth = (int)(top + depth * 4);
    g_AptScriptFunctionBase_staticDepth = 0;
    g_AptScriptFunctionBase_staticTop = (char *)depth;
}
