struct AptValue;
struct EAStringC;

int AptNativeHash_Lookup(AptValue* obj, EAStringC* name);

struct AptCIH {
    int objectMemberLookup(AptValue* obj, EAStringC* name) const;
};

int AptCIH::objectMemberLookup(AptValue* obj, EAStringC* name) const {
    return AptNativeHash_Lookup(obj, name);
}
