struct AptValue;
extern AptValue* gpAptUndefined;

struct AptStage {
    static AptValue* sMethod_removeListener(AptValue* args, int nArgs);
};

AptValue* AptStage::sMethod_removeListener(AptValue* args, int nArgs) {
    return gpAptUndefined;
}
