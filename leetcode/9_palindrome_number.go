/*
 * @lc app=leetcode id=9 lang=golang
 *
 * [9] Palindrome Number
 */

package leetcode

// @lc code=start
func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	t := x
	b := 0

	for x > 0 {
		b = b*10 + x%10
		x /= 10
	}

	return t == b
}

// @lc code=end
