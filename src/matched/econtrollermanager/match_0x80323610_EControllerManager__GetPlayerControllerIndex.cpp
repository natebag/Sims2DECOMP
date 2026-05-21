// 0x80323610 (28B) EControllerManager::GetPlayerControllerIndex(unsigned int)

class EControllerManager {
public:
    int GetPlayerControllerIndex(unsigned int idx);
};

int EControllerManager::GetPlayerControllerIndex(unsigned int idx) {
    int result = -1;
    if (idx <= 3) {
        result = ((int*)this)[idx];
    }
    return result;
}
