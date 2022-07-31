package qsort

import (
	"fmt"
	"math/rand"
	"sort"
	"testing"
)

func isSameSlice(a, b []int) bool {
	isSame := true
	for i := range a {
		if a[i] != b[i] {
			isSame = false
			break
		}
	}
	return isSame
}

func TestHand1(t *testing.T) {
	var nums []int = []int{3, 1, 4, 1, 5}

	Slice(nums, func(a, b int) bool {
		return a < b
	}, func(a []int) int {
		return len(a) - 1
	})

	var ans []int = []int{1, 1, 3, 4, 5}

	if !isSameSlice(nums, ans) {
		t.Error(`miss in hand1`, nums, ans)
	}
}

func TestHand2(t *testing.T) {
	var nums []int = []int{1, 1, 1, 1, 1}
	Slice(nums, func(a, b int) bool {
		return a < b
	}, func(a []int) int {
		return len(a) - 1
	})

	var ans []int = []int{1, 1, 1, 1, 1}

	if !isSameSlice(nums, ans) {
		t.Error(`miss in hand2`)
	}
}

func TestBig1(t *testing.T) {
	n := rand.Intn(200000)
	nums := make([]int, n)
	for i := range nums {
		nums[i] = rand.Int()
	}

	fmt.Println("big1 nums generated", "n:", n)

	ans := nums[:]
	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	Slice(nums, func(a, b int) bool {
		return a < b
	}, func(a []int) int {
		return len(a) - 1
	})

	if !isSameSlice(nums, ans) {
		t.Error(`miss in big1`)
	}
}

func TestBig2(t *testing.T) {
	n := rand.Intn(200000)
	nums := make([]int, n)
	for i := range nums {
		nums[i] = rand.Int()
	}

	fmt.Println("big2 nums generated", "n:", n)

	ans := nums[:]
	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	Slice(nums, func(a, b int) bool {
		return a < b
	}, func(a []int) int {
		return 0
	})

	if !isSameSlice(nums, ans) {
		t.Error(`miss in big1`)
	}
}

func TestBig3(t *testing.T) {
	n := rand.Intn(200000)
	nums := make([]int, n)
	for i := range nums {
		nums[i] = rand.Int()
	}

	fmt.Println("big3 nums generated", "n:", n)

	ans := nums[:]
	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	Slice(nums, func(a, b int) bool {
		return a < b
	}, func(a []int) int {
		return rand.Intn(len(a))
	})

	if !isSameSlice(nums, ans) {
		t.Error(`miss in big1`)
	}
}