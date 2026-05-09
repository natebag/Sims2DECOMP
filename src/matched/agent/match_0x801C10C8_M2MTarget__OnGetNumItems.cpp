// 0x801C10C8 M2MTarget::OnGetNumItems(M2MTarget::ResultStruct&) (64B)

struct M2MRS {
    int field0;
    int field4;
    int field8;
};

struct M2MTarget {
    int OnGetNumItems(M2MRS& rs);
};

int M2MTarget::OnGetNumItems(M2MRS& rs) {
    int result = 0;
    if (rs.field0 == 0xff) return 2;
    if (rs.field4 == 0xff) return 8;
    if (rs.field8 == 0) result = 4;
    return result;
}
