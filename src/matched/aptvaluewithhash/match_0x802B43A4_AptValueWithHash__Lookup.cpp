struct EAStringC;

struct AptValue;

struct AptNativeHash {
    AptValue* Lookup(EAStringC* key) const;
};

struct AptValueWithHash {
    char _pad[0x0C];
    AptNativeHash m_hash;

    AptValue* Lookup(EAStringC* key) const;
};

AptValue* AptValueWithHash::Lookup(EAStringC* key) const
{
    return m_hash.Lookup(key);
}
