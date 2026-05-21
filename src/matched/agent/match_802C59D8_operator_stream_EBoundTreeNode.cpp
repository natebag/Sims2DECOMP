// 0x802C59D8 operator<<(EStream&, EBoundTreeNode*) (32B)

struct EStream { char dummy[0x48]; };
struct EStorable {};
struct EBoundTreeNode {};

extern EStream& operator<<(EStream& s, EStorable* p);

EStream& operator<<(EStream& s, EBoundTreeNode* n) {
    return operator<<(s, (EStorable*)n);
}
