# PAPI-VTUNES
- In order to collect events, set linux parameters:

        - sudo sh -c 'echo 0 >/proc/sys/kernel/perf_event_paranoid'
        - sudo sh -c 'echo 0 > /proc/sys/kernel/kptr_restrict'
        - sudo sh -c 'echo 0 > /proc/sys/kernel/yama/ptrace_scope'
        
- Directories:

	- cxx-sort    -> sort algorithms with PAPI and VTUNES example
	- cxx-matrix  -> matrix operation algorithms with PAPI and VTUNES example
	- lib -> C++ class PAPI 

