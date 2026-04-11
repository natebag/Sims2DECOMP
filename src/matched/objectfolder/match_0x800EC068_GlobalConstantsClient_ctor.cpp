// 0x800EC068 GlobalConstantsClient::GlobalConstantsClient (20b)
// FLAGS: -fno-schedule-insns

extern int GlobalConstantsClient_vtable[];

struct GlobalConstantsClient {
    int* m_vt;       // 0x00
    short m_field_4; // 0x04
    GlobalConstantsClient(short);
};

GlobalConstantsClient::GlobalConstantsClient(short p2) {
    m_field_4 = p2;
    *(int**)this = GlobalConstantsClient_vtable;
}
