package main

import (
	"fmt"
	"math/rand"
)

func pi(n int) float64 {
	inCircle := 0
	for i := 1; i <= n; i++ {
		x := rand.Float64()
		y := rand.Float64()
		d := (x-0.5)*(x-0.5) + (y-0.5)*(y-0.5)
		if d < 0.25 {
			inCircle = inCircle + 1
		}
	}
	return 4.0 * float64(inCircle) / float64(n)
}

func main() {
	ns := [6]int{1, 10, 100, 1000, 10000, 100000}
	for _, n := range ns {
		for i := 0; i < 10; i++ {
			fmt.Println("i:", i, "n:", n, "pi:", pi(n))
		}
	}
}
