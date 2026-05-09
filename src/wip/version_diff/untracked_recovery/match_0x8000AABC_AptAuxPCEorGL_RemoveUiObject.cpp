// Match attempt: AptAuxPCEorGL_RemoveUiObject
// Address: 0x8000AABC | Size: 140 bytes

struct UIObjectBase {};

extern UIObjectBase* g_uiObjectArray[10] __attribute__((section(".data")));

int AptAuxPCEorGL_RemoveUiObject(UIObjectBase* obj) {
    int found = 0;
    int i = 0;
    
    if (obj == g_uiObjectArray[0]) {
        found = 1;
    } else {
        do {
            i++;
            if (i > 9) {
                return found;
            }
        } while (obj != g_uiObjectArray[i]);
        found = 1;
    }
    
    while (i < 9) {
        g_uiObjectArray[i] = g_uiObjectArray[i + 1];
        i++;
    }
    g_uiObjectArray[9] = 0;
    
    return found;
}
