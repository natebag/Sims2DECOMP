/* Interaction::SetUniqueID(void) - 20 bytes */

static int s_nextUniqueID;

struct Interaction {
    char m_pad[0x38];
    int m_id;

    void SetUniqueID(void);
};

void Interaction::SetUniqueID(void) {
    s_nextUniqueID = s_nextUniqueID + 1;
    m_id = s_nextUniqueID;
}
