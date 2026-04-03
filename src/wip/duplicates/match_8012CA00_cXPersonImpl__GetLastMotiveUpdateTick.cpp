// 0x8012CA00 (8 bytes)
class cXPersonImpl {
public:
    int GetLastMotiveUpdateTick();
};

int cXPersonImpl::GetLastMotiveUpdateTick() {
    return *(int*)((char*)this + 0x538);
}
