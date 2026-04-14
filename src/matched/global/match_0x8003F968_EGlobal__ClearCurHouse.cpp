/* EGlobal::ClearCurHouse(void) at 0x8003F968 (68B) */

struct EHouse {
    void Destroy(int);
};

struct EGlobal {
    char pad[0xC8];
    EHouse* m_curHouse;

    void ClearCurHouse(void);
};

void EGlobal::ClearCurHouse(void) {
    if (m_curHouse != 0) {
        m_curHouse->Destroy(3);
        m_curHouse = 0;
    }
}
