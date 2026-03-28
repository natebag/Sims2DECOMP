#ifndef EFIXEDSTRING_H
#define EFIXEDSTRING_H

#include "types.h"

// EFixedString - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (0 named), 98 methods

class EFixedString {
public:
    // Constructors / Destructors
    EFixedString(void *, int, char *)  // 0x8074C19C
    EFixedString(void *, int)  // 0x8074C248
    ~EFixedString(void);  // 0x8074C894

    // Methods
    void ExtractExtension(EFixedString &);  // 0x8074E820 (176B)
    void Init(void *, int);  // 0x8074C6BC (472B)
    void MakeCopy(char *);  // 0x8074CC48 (292B)
    void ValidateBuffer(void);  // 0x8074C904 (208B)
    void Concatonate(char *, char *);  // 0x8074C9D4 (408B)
    void Concatonate(char *, char);  // 0x8074CB6C (112B)
    void Concatonate(char, char *);  // 0x8074CBDC (108B)
    void MakeCopy(char);  // 0x8074CD6C (80B)
    /* ? */ GetLength(void);  // 0x8074CDBC (68B)
    void MakeUpper(void);  // 0x8074CE00 (152B)
    void MakeLower(void);  // 0x8074CE98 (152B)
    void Compare(char *);  // 0x8074CF30 (216B)
    void CompareNoCase(char *);  // 0x8074D008 (320B)
    void CompareSymbol(char *);  // 0x8074D148 (672B)
    void Mid(EFixedString &, int, int);  // 0x8074D3E8 (384B)
    void Left(EFixedString &, int);  // 0x8074D568 (396B)
    void Right(EFixedString &, int);  // 0x8074D6F4 (232B)
    void operator+=(char *);  // 0x8074D7DC (300B)
    void operator+=(char);  // 0x8074D908 (100B)
    void Find(char);  // 0x8074D96C (160B)
    void FindNoCase(char);  // 0x8074DA0C (192B)
    void CharsEqualNoCase(char, char);  // 0x8074EED4 (312B)
    void Find(char *);  // 0x8074DACC (292B)
    void FindNoCase(char *);  // 0x8074DBF0 (308B)
    void Replace(EFixedString &, char *, char *);  // 0x8074DD24 (308B)
    void operator=(EFixedString &);  // 0x8074F080 (72B)
    void FindReverse(char);  // 0x8074DE58 (200B)
    void Convert(float);  // 0x8074DF20 (124B)
    void Convert(int);  // 0x8074DF9C (116B)
    void Replace(char, char);  // 0x8074E010 (136B)
    void Remove(EFixedString &, char);  // 0x8074E098 (360B)
    void FixTrailingSlash(void);  // 0x8074E308 (128B)
    void operator[](int);  // 0x8074F0C8 (176B)
    void RemoveTrailingSlash(void);  // 0x8074E388 (300B)
    void RemoveDriveLetter(void);  // 0x8074E4B4 (208B)
    void ExtractFilename(EFixedString &);  // 0x8074E584 (208B)
    void ExtractRoot(EFixedString &);  // 0x8074E654 (256B)
    void ExtractDirectory(EFixedString &);  // 0x8074E754 (204B)
    void operator=(char *);  // 0x8074F038 (72B)
    void Empty(void);  // 0x8074F178 (44B)
    void MakeLegalFilename(void);  // 0x8074E8D0 (228B)
    void TrimRight(char);  // 0x8074E9B4 (248B)
    void TrimLeft(char);  // 0x8074EAAC (176B)
    void Trim(char);  // 0x8074EB5C (116B)
    void TrimRight(char *);  // 0x8074EBD0 (256B)
    void TrimLeft(char *);  // 0x8074ECD0 (184B)
    void Trim(char *);  // 0x8074ED88 (92B)
    /* ? */ GetBuffer(int);  // 0x8074EDE4 (84B)
    void ReleaseBuffer(void);  // 0x8074EE38 (64B)
    void Convert(double);  // 0x8074EE78 (92B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R] (Compare, CompareNoCase, CompareSymbol, ...)
    u8 _pad_001[3];  // 0x001
    u32 m_field_004;  // 0x004 [R] (Concatonate, Convert, MakeCopy, ...)
};

#endif // EFIXEDSTRING_H
