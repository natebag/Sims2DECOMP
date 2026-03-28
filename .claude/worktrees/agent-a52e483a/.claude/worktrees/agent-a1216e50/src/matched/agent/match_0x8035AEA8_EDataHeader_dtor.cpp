/* EDataHeader::~EDataHeader(void) - 0x8035AEA8 (64 bytes) */

struct EDataHeader {
    void Cleanup();
    ~EDataHeader();
};

EDataHeader::~EDataHeader()
{
    Cleanup();
}
