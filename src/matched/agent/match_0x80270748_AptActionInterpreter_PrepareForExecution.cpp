// 0x80270748 (32B) AptActionInterpreter::PrepareForExecution(char *)
// Thunk to AptScriptFunctionBase::PushStaticData(void)

class AptScriptFunctionBase {
public:
    static void PushStaticData(void);
};

class AptActionInterpreter {
public:
    void PrepareForExecution(char *);
};

void AptActionInterpreter::PrepareForExecution(char *) {
    AptScriptFunctionBase::PushStaticData();
}
