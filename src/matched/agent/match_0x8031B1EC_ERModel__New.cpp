/* ERModel::New(void) at 0x8031B1EC (40B) */

struct ERModel_New {
    char m_pad[384];
    static void* operator new(unsigned int size);
    ERModel_New();
    static ERModel_New* New();
};

ERModel_New* ERModel_New::New() {
    return new ERModel_New();
}
