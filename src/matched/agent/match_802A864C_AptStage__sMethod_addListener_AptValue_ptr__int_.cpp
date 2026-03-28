struct AptValue;
extern AptValue* gpAptUndefined;

struct AptStage {
    static AptValue* sMethod_addListener(AptValue* args, int nArgs);
};

AptValue* AptStage::sMethod_addListener(AptValue* args, int nArgs) {
    return gpAptUndefined;
}
