typedef int UIScreenID;

class UIScreenManager {
public:
    int FindRecordIndexByID(UIScreenID id);
    int IsUIScreenUnloaded(UIScreenID id);
};

int UIScreenManager::IsUIScreenUnloaded(UIScreenID id) {
    return FindRecordIndexByID(id) == -1;
}
