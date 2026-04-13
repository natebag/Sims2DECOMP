// 0x801AD544 E2ETarget::SaveFrame (36B)
extern void EyeToyClient_SaveSessionToSlot(void*, int);

struct E2ETarget_SF {
    char pad[0xC0];
    void* m_session;
    void SaveFrame(char* name, char* path);
};

void E2ETarget_SF::SaveFrame(char* name, char* path) {
    EyeToyClient_SaveSessionToSlot(m_session, (int)name);
}
