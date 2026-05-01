// 0x800A7080 StringBuffer2::charAt(int) const (84B)

class StringBuffer2 {
public:
    int GetSize() const;
    unsigned short* GetData() const;
    unsigned short charAt(int idx) const;
};

unsigned short StringBuffer2::charAt(int idx) const {
    if (idx >= 0 && idx < GetSize()) {
        return GetData()[idx];
    }
    return 0;
}
