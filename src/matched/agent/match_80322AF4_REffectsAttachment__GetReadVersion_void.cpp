struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_REffectsAttachment_tid = { 1, 2, 3, 4 };
class REffectsAttachment { public: unsigned short GetReadVersion(); };
unsigned short REffectsAttachment::GetReadVersion() { return s_REffectsAttachment_tid.readVer; }
