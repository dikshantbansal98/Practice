class Solution:
    def singleNonDuplicate(self, arr: List[int]) -> int:
        n = len(arr)
    
        low = 0
        high = n-1

        while low <= high:
            mid = (low+high)//2

            if mid > 0 and arr[mid - 1] == arr[mid]:
                mid -= 1

            if mid < n and (mid == n-1 or arr[mid + 1] != arr[mid]):
                return arr[mid]

            left_count = mid

            if left_count % 2 == 1:
                high = mid - 1
            else:
                low = mid + 2