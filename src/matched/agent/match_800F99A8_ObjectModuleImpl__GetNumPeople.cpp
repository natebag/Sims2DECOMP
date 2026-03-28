/* ObjectModuleImpl::GetNumPeople(void) - 20 bytes */

class ObjectModuleImpl {
public:
    char pad[0x2058];
    char* m_peopleBegin;
    char* m_peopleEnd;

    int GetNumPeople(void);
};

int ObjectModuleImpl::GetNumPeople(void) {
    return ((int)m_peopleEnd - (int)m_peopleBegin) >> 2;
}
