// 0x800EAF44 (60B) cXObjectImpl::SimIndependent(void)

extern "C" short* helper_0x800E4040(void* obj, int idx);  // EdithVariableSet::operator[](int)

class cXObjectImpl {
public:
    int SimIndependent();
};

int cXObjectImpl::SimIndependent() {
    short* p = helper_0x800E4040((char*)this + 40, 60);
    if (*p != 0) return 1;
    return 0;
}
