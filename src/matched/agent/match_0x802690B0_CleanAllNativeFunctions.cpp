// 0x802690B0 (76B) CleanAllNativeFunctions(void) — umbrella wrapper, 12 AptX CleanNative calls

namespace AptArray { void CleanNativeFunctions(void); }
namespace AptDate { void CleanNativeFunctions(void); }
namespace AptMathObj { void CleanNativeFunctions(void); }
namespace AptKey { void CleanNativeFunctions(void); }
namespace AptLoadVars { void CleanNativeFunctions(void); }
namespace AptSound { void CleanNativeFunctions(void); }
namespace AptScriptColour { void CleanNativeFunctions(void); }
namespace AptXml { void CleanNativeFunctions(void); }
namespace AptXmlNode { void CleanNativeFunctions(void); }
namespace AptCharacterInst { void CleanNativeFunctions(void); }
namespace AptString { void CleanNativeFunctions(void); }
namespace AptError { void CleanNativeFunctions(void); }

void CleanAllNativeFunctions(void) {
    AptArray::CleanNativeFunctions();
    AptDate::CleanNativeFunctions();
    AptMathObj::CleanNativeFunctions();
    AptKey::CleanNativeFunctions();
    AptLoadVars::CleanNativeFunctions();
    AptSound::CleanNativeFunctions();
    AptScriptColour::CleanNativeFunctions();
    AptXml::CleanNativeFunctions();
    AptXmlNode::CleanNativeFunctions();
    AptCharacterInst::CleanNativeFunctions();
    AptString::CleanNativeFunctions();
    AptError::CleanNativeFunctions();
}
