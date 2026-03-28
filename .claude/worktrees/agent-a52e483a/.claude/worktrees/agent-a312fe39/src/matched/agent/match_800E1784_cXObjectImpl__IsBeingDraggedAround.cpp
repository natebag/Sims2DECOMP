// 0x800E1784 (8 bytes) — li 3, 0; blr
// cXObjectImpl::IsBeingDraggedAround(void)

class cXObject;

class cXObjectImpl {
public:
    void IsBeingDraggedAround(void);
};

__attribute__((naked))
void cXObjectImpl::IsBeingDraggedAround(void) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
