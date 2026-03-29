// 0x802AFFF8 (8 bytes)
class AptTextFormat {
public:
    void* operator new[](unsigned int size);
};

void* AptTextFormat::operator new[](unsigned int size) {
    return 0;
}
