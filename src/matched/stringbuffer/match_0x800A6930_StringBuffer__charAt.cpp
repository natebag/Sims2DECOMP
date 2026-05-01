// 0x800A6930 StringBuffer::charAt(int) const (84B)

class StringBuffer {
public:
    int GetSize() const;
    char* GetData() const;
    char charAt(int idx) const;
};

char StringBuffer::charAt(int idx) const {
    if (idx >= 0 && idx < GetSize()) {
        return GetData()[idx];
    }
    return 0;
}
