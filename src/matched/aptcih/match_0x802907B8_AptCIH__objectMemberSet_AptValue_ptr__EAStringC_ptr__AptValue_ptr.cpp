// 0x802907B8 AptCIH::objectMemberSet(AptValue *, EAStringC *, AptValue *) (44b)
struct AptValue;
struct EAStringC;

int AptCharacterInst_objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val);

struct AptCIH {
    int objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val);
};

int AptCIH::objectMemberSet(AptValue* obj, EAStringC* name, AptValue* val) {
    return AptCharacterInst_objectMemberSet(obj, name, val);
}
