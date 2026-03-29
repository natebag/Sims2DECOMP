/* Interaction::Interaction(Interaction &) at 0x800C11D0 (92B) */

struct BString2 {
    int m_ptr;
    void Init(void);
};

struct InteractionBase {
    int m_link;
    int m_type;
    void *m_person;
    void *m_stackObject;
    void *m_iconObject;
    int m_treeTabEntryIndex;
    short m_stackVars[4];
    int m_localVarsCount;
    short *m_localVars;
    int m_priority;
    short m_treeID;
    char m_pad2E[2];
    float m_attenuation;
    BString2 m_name;
    int m_id;
    int m_flags;
};

struct Interaction : InteractionBase {
    virtual ~Interaction(void);

    Interaction(Interaction &other);
    Interaction &operator=(Interaction &other);
};

Interaction::Interaction(Interaction &other) {
    m_name.Init();
    m_localVarsCount = 0;
    m_localVars = (short *)m_localVarsCount;
    *this = other;
}
