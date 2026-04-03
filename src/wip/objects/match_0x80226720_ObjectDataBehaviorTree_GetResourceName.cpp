// ObjectDataBehaviorTree::GetResourceName (0x80226720, 84 bytes)
// Simple getter that returns 1 if StringBuffer has content, 0 if empty

class StringBuffer {
public:
    int length() const;
    void copy(StringBuffer &);
};

class ObjectDataBehaviorTree {
    StringBuffer m_resourceName;  // at offset 12 (0x0C)

public:
    int GetResourceName(StringBuffer &out) const {
        if (m_resourceName.length() == 0) {
            return 0;
        }
        out.copy(m_resourceName);
        return 1;
    }
};
