
import random
class Solution:
    def solve(self, A):

        def qsort(A, left, right):
            ''' qsort defination '''

            if left >= right: return

            pivot = random.choice(xrange(left, right + 1))
            v = A[pivot]
            A[left], A[pivot] = A[pivot], A[left]
            i, j = left + 1, right

            while True:
                while i <= right and A[i] < v: i += 1
                while A[j] > v: j -= 1
                if i < j:
                    A[i], A[j] = A[j], A[i]
                    i += 1
                    j -= 1
                else: break

            A[left], A[j] = A[j], A[left]
            qsort(A, left, j-1)
            qsort(A, j+1, right)

        qsort(A, 0, len(A) - 1)


if __name__ == '__main__':
    ''' test block '''
    s = random.sample(xrange(100), 10)
    # s = [2, 4, 9, 10, 1, 6]
    r = s[:]
    print s
    Solution().solve(s)
    print s
    print sorted(r)