// 0x802DA3EC EA::Allocator::GeneralAllocator::GetDataPreview(const void*, unsigned int, char*, wchar_t*, unsigned int) const (304 B)
// Format a memory block as a hex + ASCII preview string. Builds a local
// hex-digit table, space-fills the caller's buffer and NUL-terminates it, then
// writes "XX " hex pairs followed by a tab-separated ASCII column in which
// non-printable characters and quote marks are rendered as '.'. The number of
// bytes shown is min(nDataSize, (nBufferLength-2)/4). The fourth parameter is
// unused. Always returns 0.
namespace EA { namespace Allocator {

extern "C" void* memset(void* pDest, int c, unsigned int n);

struct GeneralAllocator {
    unsigned int GetDataPreview(const void* pData, unsigned int nDataSize,
                                char* pBuffer, wchar_t* pUnused,
                                unsigned int nBufferLength) const;
};

unsigned int GeneralAllocator::GetDataPreview(const void* pData, unsigned int nDataSize,
                                              char* pBuffer, wchar_t* /*pUnused*/,
                                              unsigned int nBufferLength) const
{
    char hexChars[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };

    unsigned int nWritable = (nBufferLength - 2) >> 2;
    if (nDataSize < nWritable)
        nWritable = nDataSize;

    memset(pBuffer, ' ', nBufferLength);
    pBuffer[nBufferLength - 1] = 0;

    if (nBufferLength <= 4) {
        pBuffer[0] = 0;
        return 0;
    }

    char* pAscii = (char*)(nWritable * 3 + (unsigned int)pBuffer);
    pAscii[-1] = '\t';

    unsigned int i = 0;
    if (i < nWritable) {
        do {
            pBuffer[i * 3]     = hexChars[((const unsigned char*)pData)[i] >> 4];
            pBuffer[i * 3 + 1] = hexChars[((const unsigned char*)pData)[i] & 0x0f];

            unsigned char c = ((const unsigned char*)pData)[i];
            if ((unsigned int)(c - 0x20) > 0x5e || (signed char)c == '"' || (signed char)c == '\'')
                *pAscii = '.';
            else
                *pAscii = c;

            pAscii++;
            i++;
        } while (i < nWritable);
    }

    return 0;
}

}}
