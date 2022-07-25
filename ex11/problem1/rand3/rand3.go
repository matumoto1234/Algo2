package rand3

import (
	"math/big"
	"github.com/matumoto1234/ex11/rand2"
)

func Rand3(n int) []*big.Int {
	x := big.NewInt(1)
	next := big.NewInt(0)
	a := rand2.Rand2(55)
	rand_seq := make([]*big.Int, 0)
	for i := 1; i <= n; i++ {
		// j := (next + 31) % 55
		j := big.NewInt(0)
		j.Add(next, big.NewInt(31))
		j.Mod(j, big.NewInt(55))

		x.Sub(a[j.Int64()], a[next.Int64()])

		// x < 0
		if x.Cmp(big.NewInt(0)) == -1 {
			x.Add(x, big.NewInt(2147483647))
			x.Add(x, big.NewInt(1))
		}
		a[next.Int64()] = x
		next.Add(next, big.NewInt(1))
		next.Mod(next, big.NewInt(55))
		rand_seq = append(rand_seq, big.NewInt(0).Set(x))
	}
	return rand_seq
}
