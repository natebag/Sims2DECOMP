// 0x80053E00 (8 bytes) — addi 3, 3, 1040; blr
// ISimsObjectModel::GetDir(void)

class ISimsObjectModel {
public:
    void GetDir(void);
};

__attribute__((naked))
void ISimsObjectModel::GetDir(void) {
    asm volatile(
        "addi 3, 3, 1040\n"
        "blr\n"
    );
}
