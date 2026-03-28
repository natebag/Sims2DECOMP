struct AptValue;
extern AptValue* gpAptUndefined;

struct AptSound {
    static AptValue* sMethod_stop(AptValue* args, int nArgs);
};

AptValue* AptSound::sMethod_stop(AptValue* args, int nArgs) {
    return gpAptUndefined;
}
