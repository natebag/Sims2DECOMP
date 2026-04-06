// EyeToyClient::DoesRepSlotHaveEyetoyImage(int)
// Address: 0x80039178 | Size: 36 bytes
// Pattern: global array access with bit extraction using XOR 1 trick
// DOL: mulli, lis/addi/addi for 0x80423DC8, lwzx, xori 1, subfic/addc for bool normalize

static unsigned int gEyeToyRepSlotArray[256];  // Global array at 0x80423DC0

extern "C" int EyeToyClient_DoesRepSlotHaveEyetoyImage(void* this_, int slot) {
    // Load from array at 0x80423DC8 (gEyeToyRepSlotArray + 8)
    // The XOR 1 + subfic/addc pattern normalizes (val ^ 1) to 0 or 1
    unsigned int* array = (unsigned int*)((char*)gEyeToyRepSlotArray + 8);
    unsigned int val = array[slot * 3];  // 12 bytes = 3 ints per element
    // Return (val ^ 1) ? 1 : 0 - normalized boolean
    return ((val ^ 1) == 0) ? 0 : 1;
}
