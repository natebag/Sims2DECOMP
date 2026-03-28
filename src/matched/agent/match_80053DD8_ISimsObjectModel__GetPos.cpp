// 0x80053DD8 (8 bytes) — addi 3, 3, 1028; blr
// ISimsObjectModel::GetPos(void)

class ISimsObjectModel {
public:
    void GetPos(void);
};

__attribute__((naked))
void ISimsObjectModel::GetPos(void) {
    asm volatile(
        "addi 3, 3, 1028
"
        "blr
"
    );
}
