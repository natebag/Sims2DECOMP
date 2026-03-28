struct AptValue;
struct EAStringC;

void AptNativeHash_Set(AptValue* obj, EAStringC* name, AptValue* val);

struct AptCIH {
    void objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val);
};

void AptCIH::objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val) {
    AptNativeHash_Set(obj, name, val);
}
