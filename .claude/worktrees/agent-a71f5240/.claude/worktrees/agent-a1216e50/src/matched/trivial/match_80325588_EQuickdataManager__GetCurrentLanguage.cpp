// 0x80325588 (8 bytes)
class EQuickdataManager {
public:
    int GetCurrentLanguage();
};

int EQuickdataManager::GetCurrentLanguage() {
    return *(int*)((char*)this + 0xD20);
}
