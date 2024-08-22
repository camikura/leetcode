/*
 * @lc app=leetcode id=13 lang=golang
 *
 * [13] Roman to Integer
 */

package leetcode

// @lc code=start
func romanToInt(s string) int {
	m := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	ans := 0

	for i := range len(s) {
		if i < len(s)-1 && m[s[i]] < m[s[i+1]] {
			ans -= m[s[i]]
		} else {
			ans += m[s[i]]
		}
	}

	return ans
}

// @lc code=end
