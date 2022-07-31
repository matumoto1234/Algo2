package main

import (
	"fmt"
	"math/rand"
	"time"

	"github.com/matumoto1234/Algo2/ex12/problem2/qsort"
)

func less(a, b int) bool {
	return a < b
}

func deterministicPivotIndex(slice []int) int {
	return len(slice) - 1
}

func randomizedPivotIndex(slice []int) int {
	return rand.Intn(len(slice))
}

func measureSorting(slice []int, pivot func([]int) int) time.Duration {
	start := time.Now()

	qsort.Slice(slice, less, pivot)

	elapsed := time.Since(start)
	return elapsed
}

func makeRandomSlice(n int) []int {
	slice := make([]int, n)
	for i := range slice {
		slice[i] = rand.Int()
	}
	return slice
}

func compare(n int) {
	fmt.Println("n:", n, "started.")
	slice := makeRandomSlice(n)

	r := measureSorting(slice[:], randomizedPivotIndex)
	d := measureSorting(slice[:], deterministicPivotIndex)

	fmt.Println("randomized:", r)
	fmt.Println("deterministic:", d)
	fmt.Println("n:", n, "ended.")
}

func main() {
	compare(100)
	compare(1000)
	compare(10000)
	compare(100000)
	compare(1000000)
}
