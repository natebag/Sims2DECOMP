// 0x802DF430 EBitArrayProxy::operator&=(bool) (108B)

class EBitArray {
public:
    bool Get(int idx);
    void Set(int idx, bool b);
};

class EBitArrayProxy {
public:
    EBitArray* m_arr;
    int m_idx;
    void operator&=(bool b);
};

void EBitArrayProxy::operator&=(bool b) {
    EBitArray* arr = m_arr;
    int idx = m_idx;
    bool cur = arr->Get(idx);
    arr->Set(idx, cur & b);
}
