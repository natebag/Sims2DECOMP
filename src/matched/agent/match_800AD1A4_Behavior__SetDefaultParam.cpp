struct BehaviorNodeParam {
    int m_a;
    int m_b;
};

class Behavior {
public:
    static void SetDefaultParam(BehaviorNodeParam *param);
};

void Behavior::SetDefaultParam(BehaviorNodeParam *param) {
    param->m_a = -1;
    param->m_b = -1;
}
