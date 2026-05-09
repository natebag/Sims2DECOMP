// operator<<(EStream&, EBitArray const&) - 0x802E05C4 (172B)

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    int GetWordCount() const;
};

class EStreamBase { public: char data[24]; };
class EStream : public EStreamBase {
public:
    virtual void Filler1() = 0;
    virtual void Filler2() = 0;
    virtual void Filler3() = 0;
    virtual void Filler4() = 0;
    virtual void Filler5() = 0;
    virtual void Filler6() = 0;
    virtual void Write(void* data, int size) = 0;
};

inline EStream& operator<<(EStream& s, int val) {
    s.Write(&val, 4);
    return s;
}

EStream& operator<<(EStream& s, const EBitArray& arr) {
    s << arr.m_nSize;
    int wordCount = arr.GetWordCount();
    for (int i = 0; i < wordCount; i++) {
        s << arr.m_pBuffer[i];
    }
    return s;
}
