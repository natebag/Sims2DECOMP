/* UIScreenManager::IsScreenManaged(UIScreenID) at 0x8017FC74 (60B) */

struct UIScreenManager_ISM {
    int FindRecordIndexByID(int id);
    int IsScreenManaged(int id);
};

int UIScreenManager_ISM::IsScreenManaged(int id) {
    int result = 0;
    int idx = FindRecordIndexByID(id);
    if (idx != -1) result = 1;
    return result;
}
