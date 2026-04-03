// 0x800fa1e8 (12 bytes) — VERIFIED MATCH
// cXObjectImpl::TryUIEffect(StackElem *, XPrimParam *)
// Stub: always returns success (0, 1). UI effects not implemented on GameCube.

struct StackElem;
struct XPrimParam;
struct TUI {
    long long TryUIEffect(StackElem *elem, XPrimParam *param);
};
long long TUI::TryUIEffect(StackElem *elem, XPrimParam *param) {
    return 1;
}
