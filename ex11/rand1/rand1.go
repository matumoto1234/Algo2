package rand1

import "math/big"

func Rand1(n int) []*big.Int {
	x := big.NewInt(53402397)
	rand_seq := make([]*big.Int, 0)
	for i := 1; i <= n; i++ {
		x.Mul(x, big.NewInt(65539)).Add(x, big.NewInt(125654))

		// x < 0
		if x.Cmp(big.NewInt(0)) == -1 {
			x.Add(x, big.NewInt(2147483647))
			x.Add(x, big.NewInt(1))
		}
		rand_seq = append(rand_seq, big.NewInt(0).Set(x))
	}
	return rand_seq
}
