// 0x80312284 (8 bytes)
class EResource {
public:
    short GetNumRefs();
};

short EResource::GetNumRefs() {
    return *(short*)((char*)this + 0xC);
}
