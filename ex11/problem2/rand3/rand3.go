package rand3

import (
	"github.com/matumoto1234/ex11/rand2"
)

func Rand3(n int) []int32 {
	x := int32(1)
	next := int32(0)
	A := rand2.Rand2(55)
	rand_seq := make([]int32, 0, n)

	for i := 1; i <= n; i++ {
		j := (next + 31) % 55
		x = A[j] - A[next]
		if x < 0 {
			x += 2147483647
			x += 1
		}
		A[next] = x
		next = (next + 1) % 55
		rand_seq = append(rand_seq, x)
	}
    return rand_seq
}
