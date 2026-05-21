// 0x80180308 UIScreenManager::PopQueue(int) (64B)
// ASMPROC_swap_operands: match="add 9,3,9" pos=1,2

class UIScreenManager {
public:
    void PopQueue(int id);
};

void UIScreenManager::PopQueue(int id) {
    if (id > 7) goto done;
    {
        int* slot = (int*)((char*)this + 512 + id * 4);
        do {
            if (id > 0) {
                slot[0] = slot[1];
            }
            id++;
            slot++;
        } while (id <= 7);
    }
done:
    *(int*)((char*)this + 0x220) = 0;
}
