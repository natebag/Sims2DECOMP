// VERIFIED MATCH - 0x800A7CD4 (112 bytes)
// QuickStringSet::QueryInterface(unsigned int, void **)
// COM QueryInterface: match GUID, return this+delta on match with AddRef

class QuickStringSet {
public:
    void* vtable;
    
    int QueryInterface(unsigned int iid, void** ppv) {
        if (ppv == 0) {
            return 0;
        }
        
        // Check for IID_IUnknown (1) or specific GUID
        if (iid == 1 || iid == 0x6BA37FA5) {
            // Get AddRef thunk via vtable[5-6]
            void** vt = (void**)vtable;
            int offset = *(int*)((char*)vt + 16);
            void (*addref)(void*) = (void (*)(void*))*(void**)((char*)vt + 20);
            
            void* adjusted = (char*)this + offset;
            addref(adjusted);
            
            *ppv = this;
            return 1;  // S_OK
        }
        
        return 0;  // E_NOINTERFACE
    }
};
