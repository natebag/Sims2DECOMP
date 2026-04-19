// 0x8019314C (40B) CASTarget::GetLotNumberFromMode(int)

struct Singleton { char pad[36]; int m_lot; };
extern Singleton* g_castSingleton;

struct CASTarget {
    static int GetLotNumberFromMode(int mode);
};

int CASTarget::GetLotNumberFromMode(int mode) {
    if (mode > 5) goto fail;
    if (mode < 1) goto fail;
    return g_castSingleton->m_lot + 1;
fail:
    return 9;
}
