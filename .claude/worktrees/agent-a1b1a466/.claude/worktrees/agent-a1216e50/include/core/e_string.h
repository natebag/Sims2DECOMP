#ifndef E_STRING_H
#define E_STRING_H

#include "types.h"

// Forward declarations
class EStream;
struct __sFILE;

struct TArrayDefaultAllocator {};

// TArray primary template - EA's dynamic array
template <class T, class Alloc>
class TArray {
public:
    T*   m_data;      // 0x00
    int  m_size;      // 0x04
    int  m_capacity;  // 0x08

    void Init(void);
    void Add(T& item);
    void SetSize(int newSize, int newCap);
    void Insert(T* src, int pos, int count);
    void Destruct(T* ptr, int count);
    void Construct(T* ptr, int count);
    void Copy(T* dst, T* src, int count);
    void CopyReverse(T* dst, T* src, int count);
};

// EString - EA's string class wrapping a char* buffer
// Layout: single pointer member m_buffer at offset 0
class EString {
public:
    char* m_buffer; // 0x00 - pointer to null-terminated char buffer

    static char m_null; // null character used as empty string

    // Constructors
    EString();
    EString(char c);
    EString(char* start, char* end);

    // Buffer management
    void SetToNull(void);
    char* AllocBuffer(int size);
    void Deallocate(char* buf);
    void FreeBuffer(char* buf);
    void MakeCopy(char* src);
    int Allocate(int size);

    // Assignment
    EString& operator=(char* str);

    // Query
    int GetLength(void) const;

    // Modification
    void MakeUpper(void);
    void MakeLower(void);
    void Empty(void);

    // Concatenation
    EString operator+(char c) const;
    EString& operator+=(char* str);
    EString& operator+=(char c);

    // Comparison
    int Compare(char* str) const;
    int CompareNoCase(char* str) const;
    int CompareSymbol(char* str) const;

    // Substrings
    EString Mid(int start, int count) const;
    EString Left(int count) const;
    EString Right(int count) const;

    // Search
    int Find(char c, int start) const;
    int FindNoCase(char c) const;
    int Find(char* str, int start) const;
    int FindNoCase(char* str) const;
    int FindReverse(char c) const;

    // Replace
    int Replace(char* from, char* to);
    void Replace(char oldChar, char newChar);
    void Remove(char c);

    // Conversion
    void Convert(float val);
    void Convert(int val);
    void Convert(double val);

    // Format
    void Format(char* fmt, ...);

    // Insert
    void Insert(int pos, char c);
    void Insert(int pos, char* str);

    // Buffer access
    char* GetBuffer(int minLen);
    void ReleaseBuffer(void);

    // Path operations
    void FixTrailingSlash(void);
    void RemoveTrailingSlash(void);
    void RemoveDriveLetter(void);
    EString ExtractFilename(void) const;
    EString ExtractRoot(void) const;
    EString ExtractDirectory(void) const;
    EString ExtractExtension(void) const;
    void MakeLegalFilename(void);
    void MakeLegalSymbolName(void);
    void RemoveRelationalDirectories(void);

    // Trimming
    void TrimRight(char c);
    void TrimLeft(char c);
    void Trim(char c);
    void TrimRight(char* chars);
    void TrimLeft(char* chars);
    void Trim(char* chars);

    // Slash conversion
    void ConvertToBackslashes(void);
    void ConvertToForwardslashes(void);
    static void ConvertToBackslashes(char* str);
    static void ConvertToForwardslashes(char* str);

    // Tokenize
    void Tokenize(char* delimiters, TArray<EString, TArrayDefaultAllocator>& tokens);
    void GetLine(__sFILE* file);

    // Comparison helpers
    static int CharsEqualNoCase(char a, char b);

    // Cast operator
    operator char*(void) const;
};

// Free operators
EString operator+(char c, EString& str);
EStream& operator<<(EStream& stream, EString& str);
EStream& operator>>(EStream& stream, EString& str);

// EString2 - Wide string class (unsigned short / wchar_t)
class EString2 {
public:
    unsigned short* m_buffer; // 0x00 - pointer to null-terminated wchar buffer

    // Constructors
    EString2(wchar_t c);
    EString2(char c);
    EString2(unsigned short* start, unsigned short* end);

    // Static helpers
    static int StrLenC16(unsigned short* str);

    // Buffer management
    void SetToNull(void);
    void SetToError(void);
    void MakeCopy(unsigned short* src);
    void MakeCopyFromChars(char* src);
    void Deallocate(unsigned short* buf);
    int Allocate(int size, bool flag);

    // Assignment
    EString2& operator=(unsigned short* str);
    EString2& operator=(char* str);
    EString2& operator=(wchar_t c);
    EString2& operator=(char c);

    // Query
    int GetLength(void) const;

    // Modification
    void MakeUpper(void);
    void MakeLower(void);
    void Empty(void);

    // Comparison
    int Compare(unsigned short* str) const;
    int Compare(char* str) const;
    int CompareNoCase(unsigned short* str) const;
    EString GetEString(void) const;

    // Substrings
    EString2 Mid(int start, int count) const;
    EString2 Left(int count) const;
    EString2 Right(int count) const;

    // Concatenation
    EString2& operator+=(unsigned short* str);
    EString2 operator+(wchar_t c);
    EString2& operator+=(wchar_t c);
    EString2 operator+(char* str) const;
    EString2 operator+(EString& str) const;
    EString2 operator+(char c) const;
    EString2& operator+=(EString& str);
    EString2& operator+=(char* str);
    EString2& operator+=(char c);

    // Search
    int Find(wchar_t c) const;
    int Find(unsigned short* str) const;
    int FindReverse(wchar_t c) const;

    // Replace
    void Replace(unsigned short* from, unsigned short* to);
    void Replace(wchar_t oldChar, wchar_t newChar);
    void Remove(wchar_t c);
    void RemoveTrailing(wchar_t c);

    // Conversion
    void Convert(float val);
    void Convert(int val);
    void Convert(double val);

    // Tokenize
    void Tokenize(wchar_t delim, TArray<EString2, TArrayDefaultAllocator>& tokens);
    EString2 GetNextToken(int& pos, int len, wchar_t delim);
    void GetLine(__sFILE* file);

    // Path operations
    void FixTrailingSlash(void);
    void RemoveTrailingSlash(void);
    EString2 ExtractFilename(void) const;
    EString2 ExtractRoot(void) const;
    EString2 ExtractDirectory(void) const;
    EString2 ExtractExtension(void) const;
    void MakeLegalFilename(void);

    // Slash conversion
    void ConvertToBackslashes(void);
    void ConvertToForwardslashes(void);

    // Cast operator
    operator unsigned short*(void) const;
};

// Free operators
EString2 operator+(wchar_t c, EString2& str);
EStream& operator<<(EStream& stream, EString2& str);
EStream& operator>>(EStream& stream, EString2& str);

// TArray specializations used by string obj files
template <>
class TArray<EString, TArrayDefaultAllocator> {
public:
    EString* m_data;   // 0x00
    int m_size;        // 0x04
    int m_capacity;    // 0x08

    void Construct(EString* dst, int count);
    void Copy(EString* dst, EString* src, int count);
    void SetSize(int newSize, int growBy);
    void CopyReverse(EString* dst, EString* src, int count);
    void Insert(EString* item, int index, int count);
    void Add(EString& item);
};

template <>
class TArray<EString2, TArrayDefaultAllocator> {
public:
    EString2* m_data;  // 0x00
    int m_size;        // 0x04
    int m_capacity;    // 0x08

    void Destruct(EString2* ptr, int count);
    void Init(void);
    void Construct(EString2* dst, int count);
    void Copy(EString2* dst, EString2* src, int count);
    void SetSize(int newSize, int growBy);
    void CopyReverse(EString2* dst, EString2* src, int count);
    void Insert(EString2* item, int index, int count);
    void Add(EString2& item);
};

// EFixedString - Fixed-size string that doesn't allocate
// Layout: char* m_buffer at 0x00, int m_maxLen at 0x04
class EFixedString {
public:
    char* m_buffer; // 0x00
    int m_maxLen;   // 0x04

    void Init(void* buf, int maxLen);

    // Concatenation
    void Concatonate(char* a, char* b);
    void Concatonate(char* a, char b);
    void Concatonate(char a, char* b);

    // Copy
    void MakeCopy(char* src);
    void MakeCopy(char c);

    // Query
    int GetLength(void) const;

    // Modification
    void MakeUpper(void);
    void MakeLower(void);

    // Comparison
    int Compare(char* str) const;
    int CompareNoCase(char* str) const;
    int CompareSymbol(char* str) const;

    // Substrings
    void Mid(EFixedString& out, int start, int count) const;
    void Left(EFixedString& out, int count) const;
    void Right(EFixedString& out, int count) const;

    // Concatenation operators
    EFixedString& operator+=(char* str);
    EFixedString& operator+=(char c);

    // Search
    int Find(char c) const;
    int FindNoCase(char c) const;
    int Find(char* str) const;
    int FindNoCase(char* str) const;
    int FindReverse(char c) const;

    // Replace
    void Replace(EFixedString& out, char* from, char* to);
    void Replace(char oldChar, char newChar);
    void Remove(EFixedString& out, char c);

    // Conversion
    void Convert(float val);
    void Convert(int val);
    void Convert(double val);

    // Path operations
    void FixTrailingSlash(void);
    void RemoveTrailingSlash(void);
    void RemoveDriveLetter(void);
    void ExtractFilename(EFixedString& out) const;
    void ExtractRoot(EFixedString& out) const;
    void ExtractDirectory(EFixedString& out) const;
    void ExtractExtension(EFixedString& out) const;
    void MakeLegalFilename(void);

    // Trimming
    void TrimRight(char c);
    void TrimLeft(char c);
    void Trim(char c);
    void TrimRight(char* chars);
    void TrimLeft(char* chars);
    void Trim(char* chars);

    // Buffer access
    char* GetBuffer(int minLen);
    void ReleaseBuffer(void);

    // Comparison helpers
    static int CharsEqualNoCase(char a, char b);
};

// Free operators
EStream& operator<<(EStream& stream, EFixedString& str);
EStream& operator>>(EStream& stream, EFixedString& str);

#endif // E_STRING_H
