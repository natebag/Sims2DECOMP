// 0x80159C54 (48B) ObjectDataBehaviorConstants::SetValueName(int, char *)

struct ObjectDataBehaviorConstants {
    char pad[16];
    char* m_valueNames;  // at offset 16
    void SetValueName(int index, char* name);
};

extern void WriteStringAt(char* ptr, char* name);  // 0x8009da6c

void ObjectDataBehaviorConstants::SetValueName(int index, char* name) {
    WriteStringAt((char*)m_valueNames + (index * 4), name);
}
