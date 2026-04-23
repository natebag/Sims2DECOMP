import json
with open("tools/all_64_128b_targets.json") as f:
    data = json.load(f)
for t in data["groups"]["SAnimator2"]:
    if not t.get("matched", False):
        print(f"{t['addr']}  {t['symbol']}")
