// 0x80159C18 (44B) ObjectDataBehaviorConstants::GetValueName(int)
// Simple field-access + offset-indexed call wrapper.

struct ObjectDataBehaviorConstants {
    char pad[16];
    char* m_valueNames;  // at offset 16
    char* GetValueName(int index);
};

extern char* ReadStringAt(char* ptr);  // 0x8009ecf8

char* ObjectDataBehaviorConstants::GetValueName(int index) {
    return ReadStringAt((char*)m_valueNames + (index * 4));
}
