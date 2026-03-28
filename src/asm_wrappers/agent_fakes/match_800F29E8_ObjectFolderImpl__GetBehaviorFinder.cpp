// 0x800F29E8 (8 bytes) — addi 3, 3, 4; blr
// ObjectFolderImpl::GetBehaviorFinder(void)

class Behavior;

class ObjectFolderImpl {
public:
    void GetBehaviorFinder(void);
};

__attribute__((naked))
void ObjectFolderImpl::GetBehaviorFinder(void) {
    asm volatile(
        "addi 3, 3, 4\n"
        "blr\n"
    );
}
