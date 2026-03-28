class EString {
public:
    int GetLength() const;
};

class StringBuffer {
public:
    int Set(const EString *str);
};

class IFFBehaviorConstants {
public:
    char m_pad[0x18];
    EString m_name;

    int GetResourceName(StringBuffer &buf) const;
};

int IFFBehaviorConstants::GetResourceName(StringBuffer &buf) const {
    if (m_name.GetLength() == 0) {
        return 0;
    }
    buf.Set(&m_name);
    return 1;
}
