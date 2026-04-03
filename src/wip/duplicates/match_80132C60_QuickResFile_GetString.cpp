// QuickResFile::GetString - 0x80132C60 (188 bytes)
// TU: quickresfile
// Decompiled implementation - raw pointer math only

// StringBuffer::erase - external function
extern void StringBuffer_erase(void* self);

// StringBuffer::append - external function  
extern void StringBuffer_append(void* self, char* str, int len);

// FindRes function for string set lookup
extern void* FindRes_AStringSet(void* start, void* end, int index);

void QuickResFile_GetString(void* this_ptr, void* out, short strSetIndex, short strIndex) {
    // this_ptr layout (from QuickResFile.h):
    // offset 0x00: vtable
    // offset 0x08: m_fileName_008 (u32) - pointer to ERQuickdata
    // offset 0x18: pointer to string table area (at offset 16 from m_fileName_008)
    
    int* self = (int*)this_ptr;
    
    // Clear output buffer - call StringBuffer::erase
    StringBuffer_erase(out);
    
    // Get quickdata pointer from offset 8
    int quickdata = self[2];  // 0x08 / 4 = 2
    if (quickdata == 0) {
        return;
    }
    
    // Get string table pointer at offset 16 from quickdata
    int* quickdataPtr = (int*)quickdata;
    int strTablePtr = quickdataPtr[4];  // 0x10 / 4 = 4 (offset 16)
    
    // Calculate count from -4 offset (number of string sets)
    int count = 0;
    if (strTablePtr != 0) {
        int* countPtr = (int*)(strTablePtr - 4);
        count = *countPtr;
    }
    
    // Find the string set by index
    // Each entry is 12 bytes, so we multiply index by 3 for int offset
    void* strSet = FindRes_AStringSet(
        (void*)strTablePtr,
        (void*)(strTablePtr + count * 12),
        (int)strSetIndex
    );
    
    if (strSet == 0) {
        return;
    }
    
    // Validate string index
    if (strIndex <= 0) {
        return;
    }
    
    // Get the string array pointer from string set (at offset 0)
    int* strSetPtr = (int*)strSet;
    int strings = strSetPtr[0];
    
    // Get count of strings in this set (at offset -4)
    int strCount = 0;
    if (strings != 0) {
        int* strCountPtr = (int*)(strings - 4);
        strCount = *strCountPtr;
    }
    
    // Check if requested index is valid
    if (strIndex > strCount) {
        return;
    }
    
    // Get the string at index (1-based, so subtract 1)
    // Index into array: (strIndex - 1) * 4
    int* strArray = (int*)strings;
    int str = strArray[strIndex - 1];
    if (str == 0) {
        return;
    }
    
    // Append string to output buffer (-1 means full string)
    StringBuffer_append(out, (char*)str, -1);
}
