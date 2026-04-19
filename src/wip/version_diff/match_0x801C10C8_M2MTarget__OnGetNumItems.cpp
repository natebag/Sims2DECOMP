/* M2MTarget::OnGetNumItems(M2MTarget::ResultStruct &) at 0x801C10C8 (64B) */

struct M2MRS {
    int field0;
    int field4;
    int field8;
};

struct M2MTarget_OGNI {
    int OnGetNumItems(M2MRS& rs);
};

int M2MTarget_OGNI::OnGetNumItems(M2MRS& rs) {
    if (rs.field0 != 0xff) goto c4;
    return 2;
c4:
    if (rs.field4 != 0xff) goto c8;
    return 8;
c8:
    if (rs.field8 == 0) return 0;
    return 4;
}
