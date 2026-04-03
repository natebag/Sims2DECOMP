struct StackElem;
struct XPrimParam { short field0; short field2; };

struct cXObjectImpl_TTB {
    long long InterpValue(short, short, short **, float **, short *);
    long long TryTreeBreak(StackElem *elem, XPrimParam *param);
};

long long cXObjectImpl_TTB::TryTreeBreak(StackElem *elem, XPrimParam *param) {
    short result;
    if (InterpValue(param->field2, param->field0, 0, 0, &result) == -1) {
        return -1;
    }
    result = 0;
    return 1;
}
