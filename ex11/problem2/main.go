package main

import (
	"fmt"
	"sort"

	"github.com/matumoto1234/ex11/rand1"
	"github.com/matumoto1234/ex11/rand2"
	"github.com/matumoto1234/ex11/rand3"
)

func toHistogram(vals []int32) [10]int {
	if len(vals) == 0 {
		return [10]int{}
	}

	val64s := make([]int64, len(vals))

	for i := range vals {
		val64s[i] = int64(vals[i]) * int64(10)
	}

	sort.Slice(val64s, func(i, j int) bool {
		return val64s[i] < val64s[j]
	})

	lower := val64s[0]
	upper := val64s[len(val64s)-1]
	diff := (upper - lower) / 10

	var hist [10]int

	for _, val := range val64s {
		for i := int64(1); i <= 10; i++ {
			stair := diff*i + lower

			if val < stair {
				hist[i /*0-indexed=*/ -1]++
				break
			}
		}
	}

	return hist
}

func toDistribution(n int, hist [10]int) [10]float32 {
	var dist [10]float32

	for i := range dist {
		dist[i] = float32(hist[i]) * 100 / float32(n)
	}

	return dist
}

func main() {
	fmt.Println("please input n.")
	var n int
	fmt.Scan(&n)

	fmt.Println(toDistribution(n, toHistogram(rand1.Rand1(n))))
	fmt.Println(toDistribution(n, toHistogram(rand2.Rand2(n))))
	fmt.Println(toDistribution(n, toHistogram(rand3.Rand3(n))))
}
