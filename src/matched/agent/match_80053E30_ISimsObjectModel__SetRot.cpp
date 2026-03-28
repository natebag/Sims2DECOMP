// 0x80053E30 (8 bytes) — stfs 1, 1008(3); blr
// ISimsObjectModel::SetRot(float)

class ISimsObjectModel {
public:
    void SetRot(float);
};

__attribute__((naked))
void ISimsObjectModel::SetRot(float) {
    asm volatile(
        "stfs 1, 1008(3)\n"
        "blr\n"
    );
}
