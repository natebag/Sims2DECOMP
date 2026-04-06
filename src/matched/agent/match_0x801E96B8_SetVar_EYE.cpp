extern void* gEyeState;
extern "C" int parseValue(void*);
struct EyeState { char pad[0x8C]; int slotCurrSel; };
void SetVar_EYE_slotCurrSel_Handler(void* self, void* val) {
    int result = parseValue(val);
    ((EyeState*)gEyeState)->slotCurrSel = result;
}
