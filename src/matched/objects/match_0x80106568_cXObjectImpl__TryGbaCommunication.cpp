// 0x80106568 (72 bytes) — VERIFIED MATCH
// cXObjectImpl::TryGbaCommunication(StackElem *, XPrimParam *)
// Checks if GBA link hardware is present. Returns (0,1) if yes, (0,0) if no.

struct StackElem;
struct XPrimParam;

struct GlobalBlock {
    char pad[23664];
    int gbaLinkValue;
};
extern GlobalBlock g_globals;

int EyeToyClient_IsPresent();

struct TGC {
    long long TryGbaCommunication(StackElem *elem, XPrimParam *param);
};

long long TGC::TryGbaCommunication(StackElem *elem, XPrimParam *param) {
    if (g_globals.gbaLinkValue == 0) {
        if (EyeToyClient_IsPresent()) {
            return 1;
        }
    }
    return 0;
}
