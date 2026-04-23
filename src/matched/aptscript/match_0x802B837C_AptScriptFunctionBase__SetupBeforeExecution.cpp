// FLAGS: -msdata=eabi -G 8
// 0x802B837C (20B) AptScriptFunctionBase::SetupBeforeExecution(_AptScriptFunctionState*, AptValue*)

extern int g_scriptFunctionState;

struct AptValue;
struct AptScriptFunctionBase {
    void SetupBeforeExecution(void* state, AptValue* val);
};

void AptScriptFunctionBase::SetupBeforeExecution(void* state, AptValue* val) {
    *(int*)state = g_scriptFunctionState;
    g_scriptFunctionState = 0;
}
