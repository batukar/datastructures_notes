array = [98, 17, 44, 35, 94]

def mergeSort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        mergeSort(left) # Solu bir elemana kadar bol
        mergeSort(right) # Sagi bir elemana kadar bol

        i = j = k = 0

        # Sol ve sagda bir eleman kalıncaya kadar kostur
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1

        # Sol tek eleman kalmissa
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        
        # Sag tek eleman kalmissa
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

    return arr

print("Dizi: ", array)

newArr = mergeSort(array)
print("Siralanmis Dizi: ",newArr)

def binarySearch(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

value = 44 # Aranacak deger
index = binarySearch(arr=newArr, target=value)

if index == -1:
    print("Eleman bulunamadi: ", value)
else:
    print("Eleman bulundu: ", value, "\nIndeksi:", index)