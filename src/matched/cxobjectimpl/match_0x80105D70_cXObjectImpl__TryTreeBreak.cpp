// FLAGS: -fno-elide-constructors
// 0x80105D70 (100 bytes) — VERIFIED MATCH
// cXObjectImpl::TryTreeBreak(StackElem *, XPrimParam *)
// Evaluates a tree break condition via InterpValue.
// Returns (-1,-1) on error, (0,1) on success.

struct StackElem;
struct XPrimParam;

struct TTB {
    long long InterpValue(short, short, short **, float **, short *);
    long long TryTreeBreak(StackElem *elem, XPrimParam *param);
};

long long TTB::TryTreeBreak(StackElem *elem, XPrimParam *param) {
    short outResult;
    short opIdx = *(short *)param;
    short varType = *(short *)((char *)param + 2);
    long long r = InterpValue(varType, opIdx, 0, 0, &outResult);
    if (r == -1) {
        return -1;
    }
    outResult = 0;
    return 1;
}
