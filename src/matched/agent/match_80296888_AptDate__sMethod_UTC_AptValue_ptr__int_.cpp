struct AptValue;
extern AptValue* gpAptUndefined;

struct AptDate {
    static AptValue* sMethod_UTC(AptValue* args, int nArgs);
};

AptValue* AptDate::sMethod_UTC(AptValue* args, int nArgs) {
    return gpAptUndefined;
}
