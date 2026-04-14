// 0x80148BB4 (48 bytes)
// StackElem::NextFrame(void) const
// stmw r30; mr r30,r3; bl GetSize; add r30,r30,r3; lmw r30; blr
// Returns: (char*)this + GetSize()

class StackElem {
public:
    int GetSize() const;
    StackElem* NextFrame() const;
};

StackElem* StackElem::NextFrame() const {
    return (StackElem*)((char*)this + GetSize());
}
