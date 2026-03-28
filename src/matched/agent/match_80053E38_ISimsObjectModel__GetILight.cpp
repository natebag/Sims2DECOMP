// 0x80053E38 (8 bytes) — lwz 3, 1120(3); blr
// ISimsObjectModel::GetILight(void)

class ISimsObjectModel {
public:
    void GetILight(void);
};

__attribute__((naked))
void ISimsObjectModel::GetILight(void) {
    asm volatile(
        "lwz 3, 1120(3)
"
        "blr
"
    );
}
