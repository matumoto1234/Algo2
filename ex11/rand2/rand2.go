package rand2

import "math/big"

func Rand2(n int) []*big.Int {
	x := big.NewInt(1)
	a := big.NewInt(48271)
	m := big.NewInt(2147483647)

	q := big.NewInt(0)
	q.Div(m, a)

	r := big.NewInt(0)
	r.Mod(m, a)

	rand_seq := make([]*big.Int, 0)
	for i := 1; i <= n; i++ {
		// x = a*(x%q) - r*(x/q)
		lhs := big.NewInt(0)
		lhs.Mod(x, q)
		lhs.Mul(lhs, a)

		rhs := big.NewInt(0)
		rhs.Div(x, q)
		rhs.Mul(rhs, r)

		x.Sub(lhs, rhs)

		// x < 0
		if x.Cmp(big.NewInt(0)) == -1 {
			x.Add(x, m)
		}
		rand_seq = append(rand_seq, big.NewInt(0).Set(x))
	}
	return rand_seq
}
