how to use checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
segfaults!
ARG="4 67 3 87 100 10000"; ./push_swap $ARG | ./checker_Mac $ARG

Merging 2 runs to stack A
if A > B, push B to A, then rotate A
if A < B, rotate A
if A < B, rotate A until stack of A is at end, then append values from B until stack in B is at end or B is empty