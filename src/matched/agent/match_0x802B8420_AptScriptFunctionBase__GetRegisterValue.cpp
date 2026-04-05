/* AptScriptFunctionBase::GetRegisterValue(int) at 0x802B8420 (16B) */

extern int* g_registerValues;

struct AptScriptFunctionBase {
    static int GetRegisterValue(int index);
};

int AptScriptFunctionBase::GetRegisterValue(int index) {
    return g_registerValues[index];
}
