# PAPI-VTUNES
- In order to collect events, set linux parameters:
        - sudo sh -c 'echo 0 >/proc/sys/kernel/perf_event_paranoid'
        - sudo sh -c 'echo 0 > /proc/sys/kernel/kptr_restrict'
        - sudo sh -c 'echo 0 > /proc/sys/kernel/yama/ptrace_scope'
        
- Directories:
sorts -> sort algorithms used to PAPI and VTUNES
lib -> C++ class PAPI 

