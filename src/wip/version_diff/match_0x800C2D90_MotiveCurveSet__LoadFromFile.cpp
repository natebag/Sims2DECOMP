struct PiecewiseFn {
    void Reset(void);
    void AddPointsFromText(char *);
};

struct StringSet {
    virtual void _v0();
    virtual void _v1();
    virtual void _v2();
    virtual void _v3();
    virtual void _v4();
    virtual void _v5();
    virtual void _v6();
    virtual void _v7();
    virtual void _v8();
    virtual void _v9();
    virtual void _v10();
    virtual void _v11();
    virtual void _v12();
    virtual int Count(char lang);
    virtual void _v14();
    virtual char *GetString(int index, char lang);
    virtual void _v16();
    virtual void _v17();
    virtual void _v18();
    virtual void _v19();
    virtual void _v20();
    virtual void _v21();
    virtual void _v22();
    virtual void _v23();
    virtual void _v24();
    virtual void _v25();
    virtual void _v26();
    virtual void _v27();
    virtual void LoadRes(unsigned int groupID, short instanceID);

    static StringSet *CreateInstance(void);
    static void DestroyInstance(StringSet *);
};

struct StringSetRef {
    StringSet *ptr;
    StringSetRef() { ptr = 0; StringSet::DestroyInstance(ptr); ptr = 0; }
    ~StringSetRef() { StringSet::DestroyInstance(ptr); ptr = 0; }
    void create() { ptr = StringSet::CreateInstance(); }
    StringSet *operator->() { return ptr; }
};

struct MotiveCurveSet {
    char *m_data;
    int m_count;
    void LoadFromFile(unsigned int, short);
};

void MotiveCurveSet::LoadFromFile(unsigned int groupID, short instanceID) {
    StringSetRef ss;
    ss.create();
    ss->LoadRes(groupID, instanceID);
    ss->Count(-1);
    int i = 1;
    if (i <= m_count) {
        int offset = 0;
        do {
            PiecewiseFn *entry = (PiecewiseFn *)(m_data + offset);
            entry->Reset();
            char *str = ss->GetString(i, -1);
            if (str != 0) {
                entry->AddPointsFromText(str);
            }
            i++;
            offset += 20;
        } while (i <= m_count);
    }
}
