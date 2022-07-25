package rand2

func Rand2(n int) []int32 {
	x := int32(1)
	A := int32(48271)
	M := int32(2147483647)
	Q := M / A
	R := M % A
	rand_seq := make([]int32, 0, n)

	for i := 1; i <= n; i++ {
		x = A*(x%Q) - R*(x/Q)

		if x < 0 {
			x += M
		}
		rand_seq = append(rand_seq, x)
	}
    return rand_seq
}
