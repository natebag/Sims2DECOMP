/* Interaction::operator=(Interaction &) at 0x800C1068 (216B) */

struct BString2 {
    int m_ptr;
    void operator_assign(BString2 *rhs);
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

    Interaction &operator=(Interaction &rhs);
    void SetLocalVars(short *src, int count);
};

Interaction &Interaction::operator=(Interaction &rhs) {
    m_flags = rhs.m_flags;
    m_type = rhs.m_type;
    m_priority = rhs.m_priority;
    m_person = rhs.m_person;
    m_stackObject = rhs.m_stackObject;
    m_iconObject = rhs.m_iconObject;
    m_treeTabEntryIndex = rhs.m_treeTabEntryIndex;
    m_stackVars[0] = rhs.m_stackVars[0];
    m_stackVars[1] = rhs.m_stackVars[1];
    m_stackVars[2] = rhs.m_stackVars[2];
    m_stackVars[3] = rhs.m_stackVars[3];
    m_id = rhs.m_id;
    m_treeID = rhs.m_treeID;
    m_attenuation = rhs.m_attenuation;
    m_name.operator_assign(&rhs.m_name);
    m_link = 0;
    {
        int count = rhs.m_localVarsCount;
        if (count != 0) {
            SetLocalVars(rhs.m_localVars, count);
        } else {
            m_localVars = (short *)count;
            m_localVarsCount = count;
        }
    }
    return *this;
}
