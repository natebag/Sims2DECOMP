// 0x803233C8 (44B) EControllerManager::Init(void)

class EControllerManager {
public:
    int Init();
};

int EControllerManager::Init() {
    int* p = (int*)this;
    int i = 0;
    int n = 4;
    do {
        p[0] = i;
        p[4] = 1;
        i++;
        p++;
        n--;
    } while (n != 0);
    return 1;
}
