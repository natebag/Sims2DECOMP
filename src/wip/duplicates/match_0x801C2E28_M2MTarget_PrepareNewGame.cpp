/* M2MTarget::PrepareNewGame - 0x801C2E28 - 80 bytes */

extern void SetGameSpeed(const char *, int);
extern const char kGameSpeedStr[];

struct M2MTarget {
    char pad0[0x11C];
    int m_field11C;
    char pad1[0x168 - 0x120];
    int m_field168;
    char pad2[0x180 - 0x16C];
    int m_field180;
    void PrepareNewGame(void);
};

void M2MTarget::PrepareNewGame(void)
{
    m_field180 = 1;
    m_field11C = 5;
    SetGameSpeed(kGameSpeedStr, 7);
    m_field168 = 3;
}
