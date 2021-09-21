/*
    소수 찾기
    https://www.acmicpc.net/problem/1978
*/
package main

import (
	"bufio"
	"fmt"
	"os"
)

func is_prime(n uint32) bool {
	var j uint32

	for j = 2; j*j <= n; j++ {
		if n%j == 0 {
			return false
		}
	}

	return n != 1
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	var n, ans uint32
	fmt.Fscanf(stdin, "%d\n", &n)

	for ; n != 0; n-- {
		var x uint32

		fmt.Fscanf(stdin, "%d ", &x)

		if is_prime(x) {
			ans++
		}
	}

	fmt.Fprintf(stdout, "%d", ans)
}
