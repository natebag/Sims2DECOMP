/* ISimsObjectModel::ShouldAnimStartImmediate(unsigned int) at 0x80053E60 (20B) */

struct ISimsObjectModel {
    int ShouldAnimStartImmediate(unsigned int param);
};

int ISimsObjectModel::ShouldAnimStartImmediate(unsigned int param) {
    if (param != 0) return 1;
    return 0;
}
