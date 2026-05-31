// FLAGS: -fno-schedule-insns
// 0x80312254 EResource::IsManaged(void) (24B)
// lwz r0,4(3); li r3,1; cmplwi r0,0; bnelr; li r3,0  -- m_manager != 0
struct EResource {
    char pad[4];
    void* m_manager;        // 0x4
    int IsManaged();
};

int EResource::IsManaged() {
    if (m_manager) return 1;
    return 0;
}
