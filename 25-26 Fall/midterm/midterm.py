
suspicious_ips = [992, 15, 4021, 77, 15, 2500, 903, 4]
previous_suspicious_ip = 15

def mergeSort(arr): # -> O(nlogn)
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        mergeSort(left)
        mergeSort(right)

        i = j = k = 0

        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1
    return arr

newArr = mergeSort(suspicious_ips)
print(newArr)

def binarySearch(arr, target): # -> O(logn)
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

result = binarySearch(newArr, previous_suspicious_ip)

if result != -1:
    print("IP: ", {previous_suspicious_ip}, "bugun supheli listesinde mevcut.")

    count = newArr.count(previous_suspicious_ip)
    print("IP: ", {previous_suspicious_ip}, "bugun, " f"{count} kez kaydedilmistir.")
    if count > 2:
        print(f"Supheli IP tekrar tespit edildi: BANLANDI")
else:
    print("Bu IP bugun supheli listesinde mevcut degil.")