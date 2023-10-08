def max_area(height):
    max_area = 0
    n = len(height)
    
    left = 0
    right = n-1

    while left < right:
        area = (right - left) * min(height[left], height[right])
        if area > max_area:
            max_area = area
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
            
    return max_area
