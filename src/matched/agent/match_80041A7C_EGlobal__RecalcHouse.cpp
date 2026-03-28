/* EGlobal::RecalcHouse(void) at 0x80041A7C (68B) */

struct EIObjectMan {
    void PostLoad(void);
};

struct EHouse {
    int m_pad;
    EIObjectMan *m_objectMan;
    void ReCalcHouse(void);
};

struct EGlobal {
    char pad_00[0xC8];
    EHouse *m_house;

    void RecalcHouse(void);
};

void EGlobal::RecalcHouse(void) {
    if (m_house != 0) {
        m_house->ReCalcHouse();
        m_house->m_objectMan->PostLoad();
    }
}
