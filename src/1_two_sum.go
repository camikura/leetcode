/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

package leetcode

// @lc code=start
func twoSum(nums []int, target int) []int {
	m := make(map[int]int)

	for i, num := range nums {
		diff := target - num
		if index, ok := m[diff]; ok {
			return []int{index, i}
		}
		m[num] = i
	}

	return nil
}

// @lc code=end
