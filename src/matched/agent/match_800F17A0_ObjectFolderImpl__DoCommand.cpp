// 0x800F17A0 (8 bytes) — li 3, 1; blr
// ObjectFolderImpl::DoCommand(short, int)

class ObjectFolderImpl {
public:
    void DoCommand(short, int);
};

__attribute__((naked))
void ObjectFolderImpl::DoCommand(short, int) {
    asm volatile(
        "li 3, 1\n"
        "blr\n"
    );
}
