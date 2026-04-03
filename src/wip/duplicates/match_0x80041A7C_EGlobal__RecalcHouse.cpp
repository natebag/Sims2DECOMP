/* EGlobal::RecalcHouse(void) at 0x80041A7C (68B) */

struct EIObjectMan {
    void PostLoad(void);
};

struct EHouse {
    char pad_00[0x04];
    EIObjectMan* m_objMan;

    void ReCalcHouse(void);
};

struct EGlobal {
    char pad_00[0xC8];
    EHouse* m_curHouse;

    void RecalcHouse(void);
};

void EGlobal::RecalcHouse(void) {
    if (m_curHouse != 0) {
        m_curHouse->ReCalcHouse();
        m_curHouse->m_objMan->PostLoad();
    }
}
