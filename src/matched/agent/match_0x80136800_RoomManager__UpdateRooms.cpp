// RoomManager::UpdateRooms(void) @ 0x80136800 (72B)

struct RoomMgr_VT14 {
    virtual void f0()  = 0;
    virtual void f1()  = 0;
    virtual void f2()  = 0;
    virtual void f3()  = 0;
    virtual void f4()  = 0;
    virtual void f5()  = 0;
    virtual void f6()  = 0;
    virtual void f7()  = 0;
    virtual void f8()  = 0;
    virtual void f9()  = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
};

extern RoomMgr_VT14* g_simMgrHouse;

struct RoomManager_UR {
    char _pad[32];
    int m_flag;
    void UpdateRooms();
    void ComputeRooms();
};

void RoomManager_UR::UpdateRooms() {
    if (m_flag == 0) return;
    ComputeRooms();
    g_simMgrHouse->f13();
}
