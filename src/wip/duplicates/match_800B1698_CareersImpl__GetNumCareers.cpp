// 0x800B1698 (8 bytes)
class CareersImpl {
public:
    int GetNumCareers();
};

int CareersImpl::GetNumCareers() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0xC);
}
