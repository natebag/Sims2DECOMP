/* Interaction::Interaction(void) - 0x800C1140 - 144 bytes */

const float kDefaultAttenuation = 0.0f;

struct BString2 {
    int m_ptr;
};

void BString2__init(BString2 *b);

struct InteractionBase {
    void *m_link;
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

struct Interaction : public InteractionBase {
    virtual ~Interaction(void);
    Interaction(void);
};

Interaction::Interaction(void) {
    m_person = 0;
    m_stackObject = 0;
    m_iconObject = 0;
    m_priority = 0;
    m_treeID = 0;
    m_treeTabEntryIndex = -1;
    m_attenuation = kDefaultAttenuation;
    BString2__init(&m_name);
    m_id = 0;
    m_type = 0;
    m_stackVars[0] = 0;
    m_stackVars[1] = 0;
    m_stackVars[2] = 0;
    m_stackVars[3] = 0;
    m_flags = 0;
    m_localVarsCount = 0;
    m_localVars = 0;
}
