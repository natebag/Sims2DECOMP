struct AptValue;
extern AptValue* gpAptUndefined;

struct AptString {
    static AptValue* sMethod_lastIndexOf(AptValue* args, int nArgs);
};

AptValue* AptString::sMethod_lastIndexOf(AptValue* args, int nArgs) {
    return gpAptUndefined;
}
