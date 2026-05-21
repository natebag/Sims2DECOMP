// 0x80227108 EIDirLight::Write(EStream&) (60B)

struct EVec3 { float x, y, z; };
struct EStream {};
EStream& operator<<(EStream& s, EVec3& v);

class EILight {
    char _pad[0xac];
public:
    void Write(EStream& s);
};

class EIDirLight : public EILight {
    EVec3 m_direction;
public:
    void Write(EStream& s);
};

void EIDirLight::Write(EStream& s) {
    EILight::Write(s);
    s << m_direction;
}
