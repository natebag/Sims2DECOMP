class EString {
public:
    int GetLength() const;
};

class StringBuffer {
public:
    int Set(const EString *str);
};

class ObjectDataSlotDescList {
public:
    int m_pad;
    EString m_name;

    int GetResourceName(StringBuffer &buf) const;
};

int ObjectDataSlotDescList::GetResourceName(StringBuffer &buf) const {
    if (m_name.GetLength() == 0) {
        return 0;
    }
    buf.Set(&m_name);
    return 1;
}
