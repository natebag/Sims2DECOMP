/* Behavior::IsDefaultParam(BehaviorNodeParam *) - 0x800AD17C (40B) */

struct BehaviorNodeParam {
    int m_field_0;
    int m_field_4;
};

int IsDefaultParam(BehaviorNodeParam* p);
int IsDefaultParam(BehaviorNodeParam* p) {
    int r = 0;
    if (p->m_field_0 == -1) {
        r = (p->m_field_4 == -1) ? 1 : 0;
    }
    return r;
}
