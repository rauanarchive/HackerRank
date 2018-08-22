def mergeSort(alist):
    # print("Splitting ",alist)
    if len(alist)>1:
        # integer division
        mid = len(alist)//2
        # slicing from left to mid
        lefthalf = alist[:mid]
        # slicing from mid to right
        righthalf = alist[mid:]
        mergeSort(lefthalf)
        mergeSort(righthalf)

        i=0
        j=0
        k=0
        # this while loop works for one-element array
        # ideally we expect len(lefthalf) and len(righthalf)
        # to be one
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1
        # when going up the recursion tree, we merge bigger subarrays
        # in the two while loops
        while i < len(lefthalf):
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf):
            alist[k]=righthalf[j]
            j=j+1
            k=k+1
    # print("Merging ",alist)

alist = [54,26,93,17,77,31,44,55,20]
mergeSort(alist)
print(alist)
