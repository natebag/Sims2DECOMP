/* Interaction::SetLocalVars(short *, int) at 0x800C17A4 (136B) */

extern void free_mem(void *);
extern void *alloc_mem(int);

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
    int m_name;
    int m_id;
    int m_flags;
};

struct Interaction : InteractionBase {
    virtual ~Interaction(void);

    void SetLocalVars(short *src, int count);
};

void Interaction::SetLocalVars(short *src, int count) {
    if (m_localVars != 0) {
        free_mem(m_localVars);
    }
    m_localVarsCount = count;
    m_localVars = (short *)alloc_mem(((count + 3) << 1) & ~7);
    int i;
    for (i = 0; i < m_localVarsCount; i++) {
        m_localVars[i] = src[i];
    }
}
