// FLAGS: -fno-schedule-insns
// 0x801F65A4 INVTarget::GetOnMsgInvExists (36B)

extern char g_onMsgInvExists[16];

struct OnMsgInvExists {
    int field0;
    short field4;
    char field6;
};

struct INVTarget {
    void GetOnMsgInvExists(char* out);
};

void INVTarget::GetOnMsgInvExists(char* out) {
    OnMsgInvExists* src = (OnMsgInvExists*)g_onMsgInvExists;
    int w = src->field0;
    short h = src->field4;
    char b = src->field6;
    OnMsgInvExists* dst = (OnMsgInvExists*)out;
    dst->field0 = w;
    dst->field4 = h;
    dst->field6 = b;
}
