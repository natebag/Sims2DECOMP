extern void *g_AptScriptFunctionBase_currentFrame;

struct EAStringC;
struct AptValue;

struct AptNativeHash {
    void Set(EAStringC *, AptValue *);
};

struct AptScriptFunctionBase {
    void CreateFrameStack();
    void SetInLocalScope(EAStringC *, AptValue *);
};

void AptScriptFunctionBase::SetInLocalScope(EAStringC *name, AptValue *value) {
    if (g_AptScriptFunctionBase_currentFrame == 0) {
        CreateFrameStack();
    }
    ((AptNativeHash *)((char *)g_AptScriptFunctionBase_currentFrame + 12))->Set(name, value);
}
