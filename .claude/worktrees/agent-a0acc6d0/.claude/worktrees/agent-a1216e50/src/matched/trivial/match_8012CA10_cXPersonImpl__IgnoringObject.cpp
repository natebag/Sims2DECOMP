// 0x8012CA10 (8 bytes)
class cXPersonImpl {
public:
    int IgnoringObject();
};

int cXPersonImpl::IgnoringObject() {
    return *(int*)((char*)this + 0x53C);
}
