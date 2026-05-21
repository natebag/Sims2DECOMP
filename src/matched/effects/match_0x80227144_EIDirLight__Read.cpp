// 0x80227144 EIDirLight::Read(EStream&) (76B)

struct EVec3 { float x, y, z; };
struct EStream {};
EStream& operator>>(EStream& s, EVec3& v);

struct EITypeInfo {
    char _pad[0x16];
    unsigned short m_readVersion;
};

class EILight {
    char _pad[0xac];
public:
    void Read(EStream& s);
};

class EIDirLight : public EILight {
    EVec3 m_direction;
public:
    static EITypeInfo m_typeInfo;
    void Read(EStream& s);
};

void EIDirLight::Read(EStream& s) {
    EILight::Read(s);
    if (m_typeInfo.m_readVersion) return;
    s >> m_direction;
}
