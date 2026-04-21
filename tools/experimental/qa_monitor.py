import time, subprocess, sys, json, os
from datetime import datetime

milestone = 8700
reported = False
log_path = "qa_monitor.log"

def log(msg):
    with open(log_path, "a", encoding="utf-8") as f:
        f.write(f"[{datetime.now().isoformat()}] {msg}\n")
    print(msg)

log("QA monitor started. Milestone: 8700")

while True:
    try:
        result = subprocess.run([sys.executable, "tools/count_matched.py"], capture_output=True, text=True, timeout=60)
        output = result.stdout + result.stderr
        # Parse unique addresses
        unique = None
        dupes = None
        for line in output.splitlines():
            if line.strip().startswith("Unique addresses:"):
                unique = int(line.split(":")[1].strip())
            if line.strip().startswith("Duplicates:"):
                dupes = int(line.split(":")[1].strip())
        if unique is not None:
            log(f"Count: {unique} unique, {dupes} duplicates")
            if unique >= milestone and not reported:
                log(f"*** MILESTONE REACHED: {unique} unique addresses (52%) ***")
                reported = True
                # Keep running but don't report again
        else:
            log(f"Could not parse count. Output:\n{output}")
    except Exception as e:
        log(f"Error: {e}")
    
    time.sleep(900)  # 15 minutes
