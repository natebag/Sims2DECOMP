// 0x8012CA18 (8 bytes)
class cXPersonImpl {
public:
    void SetIgnoringObject(int p);
};

void cXPersonImpl::SetIgnoringObject(int p) {
    *(int*)((char*)this + 0x53C) = p;
}
