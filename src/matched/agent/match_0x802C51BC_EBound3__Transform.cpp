// 0x802C51BC (84B) EBound3::Transform(EMat4 &, EBound3 &) const

struct EVec3 { int x, y, z; };  // 12B
class EMat4;

class EBound3 {
public:
    void Transform(EMat4& mat, EBound3& out) const;
};

extern "C" void func_802C4FE8(const EBound3* self, EVec3* temp);
extern "C" void func_802C55B4(EBound3* out, EVec3* temp, int count, EMat4& mat);

void EBound3::Transform(EMat4& mat, EBound3& out) const {
    EVec3 temp[8];
    int i;
    for (i = 0; i < 8; i++) ;
    func_802C4FE8(this, temp);
    func_802C55B4(&out, temp, 8, mat);
}
