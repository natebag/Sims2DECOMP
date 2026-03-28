// 0x800EC084 (8 bytes)
class GlobalConstantsClient {
public:
    short GetID();
};

short GlobalConstantsClient::GetID() {
    return *(short*)((char*)this + 0x4);
}
