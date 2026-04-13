// 0x80132838 PropTable::DestroyInstance(PropTable*) (64B)

struct PropTable {
    virtual ~PropTable();
    static void DestroyInstance(PropTable* p);
};

void PropTable::DestroyInstance(PropTable* p) {
    if (p) {
        delete p;
    }
}
