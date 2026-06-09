/* Behavior::SetDefaultParam(BehaviorNodeParam *) at 0x800AD1A4 (16B) */

struct BehaviorNodeParam;

struct Behavior {
    int m_field0;
    int m_field4;

    void SetDefaultParam(BehaviorNodeParam* param);
};

void Behavior::SetDefaultParam(BehaviorNodeParam* param) {
    m_field0 = -1;
    m_field4 = -1;
}
