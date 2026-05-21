// 0x80324510 (36B) EControllerManager::BitToIndex(unsigned int)

class EControllerManager {
public:
    static int BitToIndex(unsigned int bit);
};

int EControllerManager::BitToIndex(unsigned int bit) {
    int idx = 0;
    if ((bit >> 1) == 0) return 0;
    do {
        idx++;
    } while ((bit >> (idx + 1)) != 0);
    return idx;
}
