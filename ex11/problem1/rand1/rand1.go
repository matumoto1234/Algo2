package rand1

func Rand1(n int) []int32 {
	x := int32(53402397)
	rand_seq := make([]int32, 0, n)
	for i := 1; i <= n; i++ {
		x = 65539*x + 125654

		if x < 0 {
			x += 2147483647
			x += 1
		}
		rand_seq = append(rand_seq, x)
	}
	return rand_seq
}
