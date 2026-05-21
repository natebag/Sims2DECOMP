// 0x8015C1A4 ObjectDataObjDefinition::GetResourceName(StringBuffer*) const (68B)

class StringBuffer {
public:
    void copy(char* s);
};

class ObjectDataObjDefinition {
public:
    int m_0;
    char* m_4;
    char* m_8;
    bool GetResourceName(StringBuffer* sb) const;
};

bool ObjectDataObjDefinition::GetResourceName(StringBuffer* sb) const {
    if (m_8 == m_4) {
        return false;
    } else {
        sb->copy(m_4);
        return true;
    }
}
