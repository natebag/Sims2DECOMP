struct EAStringC;
struct AptValue;

struct AptNativeHash {
    void SetIfNotExists(EAStringC* key, AptValue* val);
};

struct AptValueWithHash {
    char _pad[0x0C];
    AptNativeHash m_hash;

    void Set(EAStringC* key, AptValue* val);
};

void AptValueWithHash::Set(EAStringC* key, AptValue* val)
{
    m_hash.SetIfNotExists(key, val);
}
