// 0x80311C88 (8 bytes)
class EResourceLoaderImpl {
public:
    void EnableReloads(int p);
};

void EResourceLoaderImpl::EnableReloads(int p) {
    *(int*)((char*)this + 0x3E0) = p;
}
