import os, re, sys

candidates = [
    ("80299264", "AptPseudoDisplayList::Remove"),
    ("8029af8c", "AptDisplayList::AptDisplayList"),
    ("802ab148", "AptSeedRand"),
    ("802b42a0", "AptValue::DeleteThis"),
    ("802b5e14", "AptObject::objectMemberLookup"),
    ("802854f8", "AptActionQueueC::GetDequeSize"),
    ("802998fc", "AptDisplayListState::remove"),
    ("802843d8", "AptAnimationPoolData::addInput"),
    ("802860ac", "AptArray::get"),
    ("802b4d04", "AptValueVector::PushValue"),
]

matched = set()
for root, dirs, files in os.walk("src/matched"):
    for f in files:
        if f.endswith(".cpp"):
            m = re.search(r"([0-9a-fA-F]{8})", f)
            if m:
                matched.add(m.group(1).lower())

for addr, name in candidates:
    found = addr.lower() in matched
    print(f"{addr} {'MATCHED' if found else 'UNMATCHED'} {name}")
