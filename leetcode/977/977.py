def sortedSquares(nums):
  if (nums[0] >= 0): return squareArray(nums)
  if (nums[len(nums) - 1] <= 0):
    return squareArray((nums[i] for i in range(len(nums) - 1, -1, -1)))

  new_nums = [0 for i in range(len(nums))]
  pos = getIdxFirstPositive(nums)
  neg = pos - 1

  for idx in range(len(nums)):
    if (neg < 0 or (pos < len(nums) and nums[pos] < nums[neg] * -1)):
      new_nums[idx] = nums[pos]
      pos += 1
    else:
      new_nums[idx] = nums[neg] * -1
      neg -= 1
  return squareArray(new_nums)

def getIdxFirstPositive(nums):
  for idx in range(1, len(nums)):
    if (nums[idx] >= 0): return idx

def squareArray(nums):
  for idx in range(len(nums)):
    nums[idx] = nums[idx] ** 2
  return nums