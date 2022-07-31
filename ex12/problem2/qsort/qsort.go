package qsort

type quickSorter[T any] struct {
	slice []T
	less  func(a, b T) bool
	pivot func([]T) int
}

// pi := pivot index
// parition(a, l, r) :|-> pi
// {x ∈ [l, pi) | x < a[pi]}
// {y ∈ [pi, r) | a[pi] <= y}
func (qs *quickSorter[T]) partition(l, r int) int {
	pi := l + qs.pivot(qs.slice[l:r])

	// right group left end index
	li := l

	for i := l; i < r; i++ {
		if qs.less(qs.slice[i], qs.slice[pi]) {
			qs.slice[i], qs.slice[li] = qs.slice[li], qs.slice[i]
			li++
		}
	}
	qs.slice[pi], qs.slice[li] = qs.slice[li], qs.slice[pi]
	pi, li = li, pi
	return pi
}

func (qs *quickSorter[T]) recursive(l int, r int) {
	if r-l <= 1 {
		return
	}

	pi := qs.partition(l, r)
	qs.recursive(l, pi)
	qs.recursive(pi+1, r)
}

func newQuickSorter[T any](slice []T, less func(a, b T) bool, pivot func([]T) int) quickSorter[T] {
	return quickSorter[T]{slice: slice, less: less, pivot: pivot}
}


func Slice[T any](slice []T, less func(a, b T) bool, pivot func([]T) int) {
	qs := newQuickSorter(slice, less, pivot)
	qs.recursive(0, len(slice))
}
