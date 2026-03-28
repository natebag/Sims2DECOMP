struct EAStringC;
struct AptValue;

struct AptNativeHash {
    void Set(EAStringC* key, AptValue* val);
};

struct AptObject {
    char _pad[0x0C];
    AptNativeHash m_hash;

    void Set(EAStringC* key, AptValue* val);
};

void AptObject::Set(EAStringC* key, AptValue* val)
{
    m_hash.Set(key, val);
}
