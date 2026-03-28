// 0x80053D9C (8 bytes) — lwz 3, 1100(3); blr
// ISimsObjectModel::GetShadow(void)

class ISimsObjectModel {
public:
    void GetShadow(void);
};

__attribute__((naked))
void ISimsObjectModel::GetShadow(void) {
    asm volatile(
        "lwz 3, 1100(3)\n"
        "blr\n"
    );
}
