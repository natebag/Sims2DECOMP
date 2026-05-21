// 0x80091054 (68B) LoadingScreenWaitingForLoadState::IsReadyToLoad(void)

extern "C" unsigned int helper_0x80090BB8(void* p);

class LoadingScreenWaitingForLoadState {
public:
    float IsReadyToLoad();
};

float LoadingScreenWaitingForLoadState::IsReadyToLoad() {
    void* sub = *(void**)((char*)this + 8);
    unsigned int v = helper_0x80090BB8(sub);
    return (float)v;
}
