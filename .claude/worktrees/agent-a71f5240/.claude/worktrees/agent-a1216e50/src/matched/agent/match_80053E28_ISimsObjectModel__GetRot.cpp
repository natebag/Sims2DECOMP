// 0x80053E28 (8 bytes) — lfs 1, 1008(3); blr
// ISimsObjectModel::GetRot(void)

class ISimsObjectModel {
public:
    void GetRot(void);
};

__attribute__((naked))
void ISimsObjectModel::GetRot(void) {
    asm volatile(
        "lfs 1, 1008(3)\n"
        "blr\n"
    );
}
