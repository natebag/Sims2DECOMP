// 0x80209354 InteractorModule::Interactor::OnCommandUpdate(InteractorCommand, float) (88B)

namespace InteractorModule {

class Interactor {
public:
    char pad[0x34];
    int m_p1x;       // 0x34
    int m_p1y;       // 0x38
    int m_p2x;       // 0x3c
    int m_p2y;       // 0x40

    void OnCommandUpdate(int cmd, float val);
};

void Interactor::OnCommandUpdate(int cmd, float val) {
    float local[2];
    if (cmd == 7) {
        float* p = &local[0];
        p[1] = val;
        local[0] = val;
        m_p1y = *(int*)&p[1];
        m_p1x = *(int*)&local[0];
    } else if (cmd == 8) {
        float* p = &local[0];
        p[1] = val;
        local[0] = val;
        m_p2y = *(int*)&p[1];
        m_p2x = *(int*)&local[0];
    }
}

}
