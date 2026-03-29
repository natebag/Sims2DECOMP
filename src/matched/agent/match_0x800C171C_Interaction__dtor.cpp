/* Interaction::~Interaction(void) at 0x800C171C (100B) */

struct BString2 {
    int m_ptr;
    void Destroy(int);
};

extern void operator_delete(void *);

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

extern void free_mem(void *);

struct Interaction : InteractionBase {
    virtual ~Interaction(void);
};

Interaction::~Interaction(void) {
    if (m_localVars != 0) {
        free_mem(m_localVars);
    }
    m_name.Destroy(2);
}
