// 0x80311CC8 (8 bytes)
class EResourceLoaderImpl {
public:
    int AreLoadsPaused();
};

int EResourceLoaderImpl::AreLoadsPaused() {
    return *(int*)((char*)this + 0x3E8);
}
