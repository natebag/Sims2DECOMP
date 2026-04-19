// 0x802280A4 (32B) EILight::CreateCopy(void) const
// Thunk to EStorable::CreateCopy(void) const

class EStorable {
public:
    static void CreateCopy(void);
};

class EILight {
public:
    void CreateCopy(void) const;
};

void EILight::CreateCopy(void) const {
    EStorable::CreateCopy();
}
