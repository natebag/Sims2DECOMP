// 0x8017FEB8 UIScreenManager::FindRecordIndexByID(int) (64B)

class UIScreenManager {
public:
    int FindRecordIndexByID(int target_id);
};

int UIScreenManager::FindRecordIndexByID(int target_id) {
    int count = 24;
    int* p = (int*)((char*)this + 116);
    int result = -1;
    int match = 0;
    do {
        p = (int*)((char*)p + 16);
        int id = *p;
        result++;
        if (id == target_id) match = 1;
        if (match != 0) break;
        count--;
    } while (count != 0);
    if (match == 0) result = -1;
    return result;
}
