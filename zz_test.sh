#!/bin/bash

# Generate all permutations of the numbers 1 through 5
numbers=(1 2 3 4 5)
permutations=$(echo ${numbers[@]} | tr ' ' '\n' | sort -u | awk 'BEGIN{perm=""}{perm=perm $0 "\n"}END{split(perm, a, "\n"); b=length(a); for (i=0; i<b; i++) for (j=0; j<b; j++) for (k=0; k<b; k++) for (l=0; l<b; l++) for (m=0; m<b; m++) if (i!=j && i!=k && i!=l && i!=m && j!=k && j!=l && j!=m && k!=l && k!=m && l!=m) print a[i],a[j],a[k],a[l],a[m]}')

# Execute push_swap with each permutation and count the number of lines in the output
while read -r permutation; do
    echo "Processing permutation: $permutation"
    ./push_swap "$permutation" | wc -l
done <<< "$permutations"