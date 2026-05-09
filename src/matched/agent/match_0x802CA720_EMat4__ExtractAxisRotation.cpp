// EMat4::ExtractAxisRotation(EVec3&) const @ 0x802CA720 (64B)
// Delegates to EQuat: quat.FromMat4(*this); quat.ExtractAxisRotation(out)

class EVec3;
class EMat4;

class EQuat {
public:
    float x, y, z, w;
    void FromMat4(EMat4& mat);
    void ExtractAxisRotation(EVec3& out) const;
};

class EMat4 {
public:
    void ExtractAxisRotation(EVec3& out) const;
};

void EMat4::ExtractAxisRotation(EVec3& out) const {
    EQuat quat;
    quat.FromMat4(const_cast<EMat4&>(*this));
    quat.ExtractAxisRotation(out);
}
